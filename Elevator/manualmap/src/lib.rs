#[macro_use]
extern crate litcrypt;
use_litcrypt!();

use std::cell::UnsafeCell;
use std::collections::HashMap;
use std::fs;
use std::mem::size_of;
use std::ffi::c_void;

use windows::Win32::System::SystemServices::{IMAGE_BASE_RELOCATION, IMAGE_IMPORT_DESCRIPTOR};
use windows::Win32::System::Threading::GetCurrentProcess;
use windows::Win32::System::WindowsProgramming::{IMAGE_THUNK_DATA32, IMAGE_THUNK_DATA64};
use windows::Win32::System::Diagnostics::Debug::{IMAGE_OPTIONAL_HEADER32, IMAGE_SECTION_HEADER};

use data::{IMAGE_FILE_HEADER, IMAGE_OPTIONAL_HEADER64, MEM_COMMIT, MEM_RESERVE, 
    PAGE_EXECUTE, PAGE_EXECUTE_READ, PAGE_EXECUTE_READWRITE, PAGE_READONLY, PAGE_READWRITE, PVOID, PeMetadata, SECTION_MEM_EXECUTE, 
    SECTION_MEM_READ, SECTION_MEM_WRITE};

use litcrypt::lc;


/// Manually maps a PE from disk to the memory of the current process.
///
/// It will return either a pair (PeMetadata,isize) containing the mapped PE
/// metadata and its base address or a String with a descriptive error message.
///
/// # Examples
///
/// ```
/// let ntdll = manualmap::read_and_map_module("c:\\windows\\system32\\ntdll.dll");
///
/// match ntdll {
///     Ok(x) => if x.1 != 0 {println!("The base address of ntdll.dll is 0x{:X}.", x.1);},
///     Err(e) => println!("{}", e),      
/// }
/// ```
pub fn read_and_map_module (filepath: &str) -> Result<(PeMetadata,isize), String> 
{
    let file_content = fs::read(filepath).expect(&lc!("[x] Error opening the specified file."));
    let file_content_ptr = file_content.as_ptr();
    let result = manually_map_module(file_content_ptr)?;

    Ok(result)
}

/// Manually maps a PE into the current process.
///
/// It will return either a pair (PeMetadata,isize) containing the mapped PE
/// metadata and its base address or a String with a descriptive error message.
///
/// # Examples
///
/// ```
/// use std::fs;
///
/// let file_content = fs::read("c:\\windows\\system32\\ntdll.dll").expect("[x] Error opening the specified file.");
/// let file_content_ptr = file_content.as_ptr();
/// let result = manualmap::manually_map_module(file_content_ptr);
/// ```
pub fn manually_map_module (file_ptr: *const u8) -> Result<(PeMetadata,isize), String> 
{
    let pe_info = get_pe_metadata(file_ptr)?;
    if (pe_info.is_32_bit && (size_of::<usize>() == 8)) || (!pe_info.is_32_bit && (size_of::<usize>() == 4)) 
    {
        return Err(lc!("[x] The module architecture does not match the process architecture."));
    }

    let dwsize;
    if pe_info.is_32_bit 
    {
        dwsize = pe_info.opt_header_32.SizeOfImage as usize;
    }
    else 
    {
        dwsize = pe_info.opt_header_64.size_of_image as usize;
    }

    unsafe 
    {
        let handle = GetCurrentProcess();
        let a = usize::default();
        let base_address: *mut PVOID = std::mem::transmute(&a);
        let zero_bits = 0 as usize;
        let size: *mut usize = std::mem::transmute(&dwsize);
        let ret = dinvoke::nt_allocate_virtual_memory(handle, base_address, zero_bits, size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
        
        let _r = dinvoke::close_handle(handle);

        if ret != 0
        {
            return Err(lc!("[x] Error allocating memory."));
        }
        
        let image_ptr = *base_address;

        map_module_to_memory(file_ptr, image_ptr, &pe_info)?;
        
        relocate_module(&pe_info, image_ptr);

        rewrite_module_iat(&pe_info, image_ptr)?;

        clean_dos_header(image_ptr);

        set_module_section_permissions(&pe_info, image_ptr)?;

        add_runtime_table(&pe_info, image_ptr);

        Ok((pe_info,image_ptr as isize))

    }

}

/// Retrieves PE headers information from the module base address.
///
/// It will return either a data::PeMetada struct containing the PE
/// metadata or a String with a descriptive error message.
///
/// # Examples
///
/// ```
/// use std::fs;
///
/// let file_content = fs::read("c:\\windows\\system32\\ntdll.dll").expect("[x] Error opening the specified file.");
/// let file_content_ptr = file_content.as_ptr();
/// let result = manualmap::get_pe_metadata(file_content_ptr);
/// ```
pub fn get_pe_metadata (module_ptr: *const u8) -> Result<PeMetadata,String>
{
    let mut pe_metadata= PeMetadata::default();

    unsafe {

        let e_lfanew = *((module_ptr as usize + 0x3C) as *const u32);
        pe_metadata.pe = *((module_ptr as usize + e_lfanew as usize) as *const u32);

        if pe_metadata.pe != 0x4550 
        {
            return Err(lc!("[x] Invalid PE signature."));
        }

        pe_metadata.image_file_header = *((module_ptr as usize + e_lfanew as usize + 0x4) as *mut IMAGE_FILE_HEADER);

        let opt_header: *const u16 = (module_ptr as usize + e_lfanew as usize + 0x18) as *const u16; 
        let pe_arch = *(opt_header);

        if pe_arch == 0x010B
        {
            pe_metadata.is_32_bit = true;
            let opt_header_content: *const IMAGE_OPTIONAL_HEADER32 = std::mem::transmute(opt_header);
            pe_metadata.opt_header_32 = *opt_header_content;
        }
        else if pe_arch == 0x020B 
        {
            pe_metadata.is_32_bit = false;
            let opt_header_content: *const IMAGE_OPTIONAL_HEADER64 = std::mem::transmute(opt_header);
            pe_metadata.opt_header_64 = *opt_header_content;
        } 
        else 
        {
            return Err(lc!("[x] Invalid magic value."));
        }

        let mut sections: Vec<IMAGE_SECTION_HEADER> = vec![];

        for i in 0..pe_metadata.image_file_header.number_of_sections
        {
            let section_ptr = (opt_header as usize + pe_metadata.image_file_header.size_of_optional_header as usize + (i * 0x28) as usize) as *const u8;
            let section_ptr: *const IMAGE_SECTION_HEADER = std::mem::transmute(section_ptr);
            sections.push(*section_ptr);
        }

        pe_metadata.sections = sections;

        Ok(pe_metadata)
    }
}

/// Maps a module to a valid memory space in the current process.
///
/// The parameters required are a vector with the module content, the base address where the module should be
/// mapped and the module's metadata.
pub fn map_module_to_memory(module_ptr: *const u8, image_ptr: *mut c_void, pe_info: &PeMetadata) -> Result<(),String>
{
    if (pe_info.is_32_bit && (size_of::<usize>() == 8)) || (!pe_info.is_32_bit && (size_of::<usize>() == 4)) 
    {
        return Err(lc!("[x] The module architecture does not match the process architecture."));
    }

    let nsize;
    if pe_info.is_32_bit 
    {
        nsize = pe_info.opt_header_32.SizeOfHeaders as usize;
    }
    else 
    {
        nsize = pe_info.opt_header_64.size_of_headers as usize;
    }

    unsafe 
    {   

        let handle = GetCurrentProcess();
        let base_address: *mut c_void = std::mem::transmute(image_ptr);
        let buffer: *mut c_void = std::mem::transmute(module_ptr);
        let written: usize = 0;
        let bytes_written: *mut usize = std::mem::transmute(&written);
        let ret = dinvoke::nt_write_virtual_memory(handle, base_address, buffer, nsize, bytes_written);

        if ret != 0
        {
            let _r = dinvoke::close_handle(handle);
            return Err(lc!("[x] Error writing PE headers to the allocated memory."));
        }

        for section in &pe_info.sections
        {
            let section_base_ptr = (image_ptr as usize + section.VirtualAddress as usize) as *mut u8;
            let section_content_ptr = (module_ptr as usize + section.PointerToRawData as usize) as *mut u8;          

            let base_address: *mut c_void = std::mem::transmute(section_base_ptr);
            let buffer: *mut c_void = std::mem::transmute(section_content_ptr);
            let nsize = section.SizeOfRawData as usize;
            let bytes_written: *mut usize = std::mem::transmute(&written);
            let ret = dinvoke::nt_write_virtual_memory(handle, base_address, buffer, nsize, bytes_written);
            let _r = dinvoke::close_handle(handle);

            if ret != 0 || *bytes_written != nsize
            {
                return Err(lc!("[x] Failed to write PE sections to the allocated memory."))
            }
        }

        Ok(())
    }
}

/// Relocates a module in memory.
///
/// The parameters required are the module's metadata information and a
/// pointer to the base address where the module is mapped in memory.
pub fn relocate_module(pe_info: &PeMetadata, image_ptr: *mut c_void) 
{
    unsafe {

        let module_memory_base: *mut usize = std::mem::transmute(image_ptr);
        let image_data_directory;
        let image_delta: isize;
        if pe_info.is_32_bit 
        {
            image_data_directory = pe_info.opt_header_32.DataDirectory[5]; // BaseRelocationTable
            image_delta = module_memory_base as isize - pe_info.opt_header_32.ImageBase as isize;
        }
        else 
        {
            image_data_directory = pe_info.opt_header_64.datas_directory[5]; // BaseRelocationTable
            image_delta = module_memory_base as isize - pe_info.opt_header_64.image_base as isize;
        }

        let mut reloc_table_ptr = (module_memory_base as usize + image_data_directory.VirtualAddress as usize) as *mut i32;
        let mut next_reloc_table_block = -1;

        while next_reloc_table_block != 0 
        {
            let ibr: *mut IMAGE_BASE_RELOCATION = std::mem::transmute(reloc_table_ptr);
            let image_base_relocation = *ibr;
            let reloc_count: isize = (image_base_relocation.SizeOfBlock as isize - size_of::<IMAGE_BASE_RELOCATION>() as isize) / 2;

            for i in 0..reloc_count
            {
                let reloc_entry_ptr = (reloc_table_ptr as usize + size_of::<IMAGE_BASE_RELOCATION>() as usize + (i * 2) as usize) as *mut u16;
                let reloc_value = *reloc_entry_ptr;

                let reloc_type = reloc_value >> 12;
                let reloc_patch = reloc_value & 0xfff;

                if reloc_type != 0
                {
                    
                    if reloc_type == 0x3
                    {
                        let patch_ptr = (module_memory_base as usize + image_base_relocation.VirtualAddress as usize + reloc_patch as usize) as *mut i32;
                        let original_ptr = *patch_ptr;
                        let patch = original_ptr + image_delta as i32;
                        *patch_ptr = patch;
                    }
                    else 
                    {
                        let patch_ptr = (module_memory_base as usize + image_base_relocation.VirtualAddress as usize + reloc_patch as usize) as *mut isize;
                        let original_ptr = *patch_ptr;
                        let patch = original_ptr + image_delta as isize;
                        *patch_ptr = patch;
                    }
                }
            }

            reloc_table_ptr = (reloc_table_ptr as usize + image_base_relocation.SizeOfBlock as usize) as *mut i32;
            next_reloc_table_block = *reloc_table_ptr;

        }


    }
}

/// Rewrites the IAT of a manually mapped module.
///
/// The parameters required are the module's metadata information and a
/// pointer to the base address where the module is mapped in memory.
pub fn rewrite_module_iat(pe_info: &PeMetadata, image_ptr: *mut c_void) -> Result<(),String> 
{
    unsafe 
    {
        let module_memory_base: *mut usize = std::mem::transmute(image_ptr);
        let image_data_directory;
        if pe_info.is_32_bit 
        {
            image_data_directory = pe_info.opt_header_32.DataDirectory[1]; // ImportTable
        }
        else 
        {
            image_data_directory = pe_info.opt_header_64.datas_directory[1]; // ImportTable
        }

        if image_data_directory.VirtualAddress == 0 
        {
            return Ok(()); // No hay import table
        }

        let import_table_ptr = (module_memory_base as usize + image_data_directory.VirtualAddress as usize) as *mut usize;

        let info = os_info::get();
        let version = info.version().to_string();
        let mut api_set_dict: HashMap<String,String> = HashMap::new();
        if version >= "10".to_string()
        {
            api_set_dict = dinvoke::get_api_mapping();
        }

        let mut counter = 0;
        let mut image_import_descriptor_ptr = (import_table_ptr as usize + size_of::<IMAGE_IMPORT_DESCRIPTOR>() as usize * counter) as *mut IMAGE_IMPORT_DESCRIPTOR;
        let mut image_import_descriptor = *image_import_descriptor_ptr;

        while image_import_descriptor.Name != 0
        {
            let mut dll_name = "".to_string();
            let mut c: char = ' ';
            let mut ptr = (module_memory_base as usize + image_import_descriptor.Name as usize) as *mut u8;
            while c != '\0'
            {
                c = *ptr as char;
                if c != '\0'
                {
                    dll_name.push(c);
                    ptr = ptr.add(1);
                }
            }

            if dll_name == ""
            {
                return Ok(());
            }
            else 
            {
                let lookup_key =  format!("{}{}",&dll_name[..dll_name.len() - 6], ".dll");

                if (version >= 10.to_string() && (dll_name.starts_with("api-") || dll_name.starts_with("ext-"))) &&  api_set_dict.contains_key(&lookup_key)
                {
                    let key = match api_set_dict.get(&lookup_key) {
                        Some(x) => x.to_string(),
                        None => "".to_string(),
                    };

                    if key.len() > 0 
                    {
                        dll_name = key.to_string();
                    }
                }

                let mut module_handle = dinvoke::get_module_base_address(&dll_name) as usize;

                if module_handle == 0
                {

                    module_handle = dinvoke::load_library_a(&dll_name) as usize;

                    if module_handle == 0
                    {
                        return Err(lc!("[x] Unable to find the specified module: {}", dll_name)); 
                    }
                    /*let to_map = lc!("C:\\windows\\system32\\").to_string() + &dll_name;
                    let mapped = read_and_map_module(&to_map)?;
                    if mapped.1 == 0
                    {
                        module_handle = dinvoke::load_library_a(&dll_name) as usize;

                        if module_handle == 0
                        {
                            return Err(lc!("[x] Unable to find the specified module: {}", dll_name)); 
                        }
                    }
                    else 
                    {
                        module_handle = mapped.1 as usize;    
                    }*/
                }

                if pe_info.is_32_bit
                {
                    let mut i: isize = 0;

                    loop 
                    {
                        let image_thunk_data = (module_memory_base as usize + image_import_descriptor.Anonymous.OriginalFirstThunk as usize 
                            + i as usize * size_of::<u32>() as usize) as *mut IMAGE_THUNK_DATA32;
                        let image_thunk_data = *image_thunk_data;
                        let ft_itd = (module_memory_base as usize + image_import_descriptor.FirstThunk as usize +
                            i as usize * size_of::<u32>() as usize) as *mut i32;
                        if image_thunk_data.u1.AddressOfData == 0
                        {
                            break;
                        }

                        if image_thunk_data.u1.AddressOfData < 0x80000000
                        {
                            let mut imp_by_name_ptr = (module_memory_base as usize + image_thunk_data.u1.AddressOfData as usize + 
                                size_of::<u16>() as usize) as *mut u8;
                            let mut import_name: String = "".to_string();
                            let mut c: char = ' ';
                            while c != '\0'
                            {
                                c = *imp_by_name_ptr as char;
                                if c != '\0'
                                {
                                    import_name.push(c);
                                }

                                imp_by_name_ptr = imp_by_name_ptr.add(1);
                            }

                            let func_ptr = dinvoke::get_function_address(module_handle as isize, &import_name);
                            *ft_itd = func_ptr as i32;

                        }
                        else 
                        {
                            let f_ordinal = (image_thunk_data.u1.AddressOfData & 0xFFFF) as u32;
                            let func_ptr = dinvoke::get_function_address_by_ordinal(module_handle as isize, f_ordinal);
                            let func_ptr = func_ptr as *mut i32;
                            *ft_itd = func_ptr as i32;
                        }

                        i = i + 1;
                    }
                }
                else 
                {
                    let mut i: isize = 0;

                    loop 
                    {
                        let image_thunk_data = (module_memory_base as u64 + image_import_descriptor.Anonymous.OriginalFirstThunk as u64 
                            + i as u64 * size_of::<u64>() as u64) as *mut IMAGE_THUNK_DATA64;
                        let image_thunk_data = *image_thunk_data;
                        let ft_itd = (module_memory_base as u64 + image_import_descriptor.FirstThunk as u64 +
                            i as u64 * size_of::<u64>() as u64) as *mut isize;
                        

                        if image_thunk_data.u1.AddressOfData == 0
                        {
                            break;
                        }

                        if image_thunk_data.u1.AddressOfData < 0x8000000000000000
                        {
                            let mut imp_by_name_ptr = (module_memory_base as u64 + image_thunk_data.u1.AddressOfData as u64 + 
                                size_of::<u16>() as u64) as *mut u8;
                            let mut import_name: String = "".to_string();
                            let mut c: char = ' ';
                            while c != '\0'
                            {
                                c = *imp_by_name_ptr as char;
                                if c != '\0'
                                {
                                    import_name.push(c);
                                }

                                imp_by_name_ptr = imp_by_name_ptr.add(1);
                            }

                            let func_ptr = dinvoke::get_function_address(module_handle as isize, &import_name) as *mut isize;
                            *ft_itd = func_ptr as isize;
                        }
                        else 
                        {
     
                            let f_ordinal = (image_thunk_data.u1.AddressOfData & 0xFFFF) as u32;
                            let func_ptr = dinvoke::get_function_address_by_ordinal(module_handle as isize, f_ordinal);
                            *ft_itd = func_ptr as isize;
                        }

                        i = i + 1;
                    }
                }
  
            }

            counter = counter + 1;
            image_import_descriptor_ptr = (import_table_ptr as usize + size_of::<IMAGE_IMPORT_DESCRIPTOR>() as usize * counter) as *mut IMAGE_IMPORT_DESCRIPTOR;
            image_import_descriptor = *image_import_descriptor_ptr;

        }

        Ok(())
    }
}

// This method is reponsible of cleaning IOCs that may reveal the pressence of a 
// manually mapped PE in a private memory region. It will remove PE magic bytes,
// DOS header and DOS stub.
fn clean_dos_header (image_ptr: *mut c_void) 
{
    unsafe
    {
        let mut base_addr = image_ptr as *mut u8;
        let pe_header = image_ptr as isize + 0x3C;
        while (base_addr as isize) < pe_header
        {
            *base_addr = 0;
            base_addr = base_addr.add(1);            
        }
        base_addr = base_addr.add(4);

        let e_lfanew = *((image_ptr as usize + 0x3C) as *const u32);
        let pe = image_ptr as isize + e_lfanew as isize;

        while (base_addr as isize) < pe
        {
            *base_addr = 0;
            base_addr = base_addr.add(1);            
        }

        let pe = pe as *mut u16;
        *pe = 0;
    }
}

pub fn add_runtime_table(pe_info: &PeMetadata, image_ptr: *mut c_void) 
{
    unsafe 
    {
        for section in &pe_info.sections
        {   
            let s = std::str::from_utf8(&section.Name).unwrap();
            if s.contains(&lc!(".pdata"))
            {
                let base = image_ptr as isize;
                let mut i = 0i32;
                let r = base + section.VirtualAddress as isize;
                let mut runtime: *mut data::RUNTIME_FUNCTION = std::mem::transmute(r);
                while  (*runtime).begin_addr != 0 
                {
                    runtime = runtime.add(1);
                    i +=1 ;
                }

                let func: data::RtlAddFunctionTable;
                let _ret: Option<bool>;                
                let k32 = dinvoke::get_module_base_address(&lc!("kernel32.dll"));
                let function_table: usize = image_ptr as usize;
                dinvoke::dynamic_invoke!(k32,&lc!("RtlAddFunctionTable"),func,_ret,function_table,i,base as isize);
            }
        }
    }

}

/// Sets correct module section permissions for a manually mapped module.
///
/// The parameters required are the module's metadata information and a
/// pointer to the base address where the module is mapped in memory.
pub fn set_module_section_permissions(pe_info: &PeMetadata, image_ptr: *mut c_void) -> Result<(),String> 
{
    unsafe 
    {
        let base_of_code;

        if pe_info.is_32_bit
        {
            base_of_code = pe_info.opt_header_32.BaseOfCode as usize;
        }
        else 
        {
            base_of_code = pe_info.opt_header_64.base_of_code as usize;
        }

        let handle = GetCurrentProcess();
        let base_address: *mut PVOID = std::mem::transmute(&image_ptr);
        let s: UnsafeCell<isize> = isize::default().into();
        let size: *mut usize = std::mem::transmute(s.get());
        *size = base_of_code;
        let o = u32::default();
        let old_protection: *mut u32 = std::mem::transmute(&o);
        let _ret = dinvoke::nt_protect_virtual_memory(handle, base_address, size, PAGE_READONLY, old_protection);
       
        for section in &pe_info.sections
        {
            let is_read = (section.Characteristics.0 & SECTION_MEM_READ) != 0;
            let is_write = (section.Characteristics.0 & SECTION_MEM_WRITE) != 0;
            let is_execute = (section.Characteristics.0 & SECTION_MEM_EXECUTE) != 0;
            let new_protect: u32;

            if is_read & !is_write & !is_execute
            {
                new_protect = PAGE_READONLY;
            }
            else if is_read & is_write & !is_execute
            {
                new_protect = PAGE_READWRITE;
            } 
            else if is_read & is_write & is_execute
            {
                new_protect = PAGE_EXECUTE_READWRITE;
            }
            else if is_read & !is_write & is_execute
            {
                new_protect = PAGE_EXECUTE_READ;
            }
            else if !is_read & !is_write & is_execute
            {
                new_protect = PAGE_EXECUTE;
            }
            else
            {
                return Err(lc!("[x] Unknown section permission."));
            }

            let address: *mut c_void = (image_ptr as usize + section.VirtualAddress as usize) as *mut c_void;
            let base_address: *mut PVOID = std::mem::transmute(&address);
            *size = section.Misc.VirtualSize as usize;
            let o = u32::default();
            let old_protection: *mut u32 = std::mem::transmute(&o);
            let ret = dinvoke::nt_protect_virtual_memory(handle, base_address, size, new_protect, old_protection);
            
            let _r = dinvoke::close_handle(handle);

            if ret != 0
            {
                return Err(lc!("[x] Error changing section permission."));
            }

        }

        Ok(())
    } 
}