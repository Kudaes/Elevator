use std::{ffi::c_void, ptr};
use bindings::Windows::Win32::{Foundation::{BOOL, HANDLE, HINSTANCE, PSTR, PWSTR}, Security::SECURITY_ATTRIBUTES, System::{Diagnostics::Debug::{IMAGE_DATA_DIRECTORY, IMAGE_OPTIONAL_HEADER32, IMAGE_SECTION_HEADER, EXCEPTION_RECORD}, SystemServices::{OVERLAPPED}, Kernel::UNICODE_STRING, WindowsProgramming::{OBJECT_ATTRIBUTES, IO_STATUS_BLOCK}, Rpc::{MIDL_STUBLESS_PROXY_INFO, CLIENT_CALL_RETURN}, Threading::PROCESS_INFORMATION}};
use winapi::shared::ntdef::LARGE_INTEGER;

pub type PVOID = *mut c_void;
pub type DWORD = u32;
pub type EntryPoint =  extern "system" fn (HINSTANCE, u32, *mut c_void) -> BOOL;
pub type LoadLibraryA = unsafe extern "system" fn (PSTR) -> HINSTANCE;
pub type OpenProcess = unsafe extern "system" fn (u32, i32, u32) -> HANDLE;
pub type CreateFileA = unsafe extern "system" fn (*mut u8, u32, u32, *const SECURITY_ATTRIBUTES, u32, u32, HANDLE) -> HANDLE;
pub type ReadFile = unsafe extern "system" fn (HANDLE, PVOID, u32, *mut u32, *mut OVERLAPPED) -> i32; 
pub type CreateProcessW = unsafe extern "system" fn (*const u16, *mut u16, *const SECURITY_ATTRIBUTES, *const SECURITY_ATTRIBUTES, BOOL, u32, *const c_void,
    *const u16, *const STARTUPINFOEXW, *mut PROCESS_INFORMATION) -> BOOL;
pub type GetLastError = unsafe extern "system" fn () -> u32;
pub type CloseHandle = unsafe extern "system" fn (HANDLE) -> i32;
pub type LptopLevelExceptionFilter = usize;
pub type InitializeProcThreadAttributeList = unsafe extern "system" fn (PVOID, u32, u32, *mut usize) -> BOOL;
pub type UpdateProcThreadAttribute = unsafe extern "system" fn (PVOID, u32, usize, *const c_void, usize, PVOID, *const usize) -> BOOL;
pub type SetUnhandledExceptionFilter = unsafe extern "system" fn (filter: LptopLevelExceptionFilter) -> LptopLevelExceptionFilter;
pub type LdrGetProcedureAddress = unsafe extern "system" fn (PVOID, *mut String, u32, *mut PVOID) -> i32;
pub type NtWriteVirtualMemory = unsafe extern "system" fn (HANDLE, PVOID, PVOID, usize, *mut usize) -> i32;
pub type NtProtectVirtualMemory = unsafe extern "system" fn (HANDLE, *mut PVOID, *mut usize, u32, *mut u32) -> i32;
pub type NtAllocateVirtualMemory = unsafe extern "system" fn (HANDLE, *mut PVOID, usize, *mut usize, u32, u32) -> i32;
pub type NtQueryInformationProcess = unsafe extern "system" fn (HANDLE, u32, PVOID, u32, *mut u32) -> i32;
pub type NtQuerySystemInformation = unsafe extern "system" fn (u32, PVOID, u32, *mut u32) -> i32;
pub type NtDuplicateObject = unsafe extern "system" fn (HANDLE, HANDLE, HANDLE, *mut HANDLE, u32, u32, u32) -> i32;
pub type NtQueryObject = unsafe extern "system" fn (HANDLE, u32, PVOID, u32, *mut u32) -> i32;
pub type NtOpenFile = unsafe extern "system" fn (*mut HANDLE, u32, *mut OBJECT_ATTRIBUTES, *mut IO_STATUS_BLOCK, u32, u32) -> i32;
pub type NtOpenProcess = unsafe extern "system" fn (*mut HANDLE, u32, *mut OBJECT_ATTRIBUTES, *mut CLIENT_ID) -> i32;
pub type NtCreateThreadEx = unsafe extern "system" fn (*mut HANDLE, u32, *mut OBJECT_ATTRIBUTES, HANDLE, PVOID, PVOID, u32, usize, usize, usize, *mut PS_ATTRIBUTE_LIST) -> i32;
pub type NtRemoveProcessDebug = unsafe extern "system" fn (HANDLE, HANDLE) -> i32;
pub type NtWaitForDebugEvent = unsafe extern "system" fn (HANDLE, u8, *mut LARGE_INTEGER, PVOID) -> i32;
pub type NtTerminateProcess = unsafe extern "system" fn (HANDLE, i32) -> i32;
pub type RtlAdjustPrivilege = unsafe extern "system" fn (u32, u8, u8, *mut u8) -> i32;
pub type RtlInitUnicodeString = unsafe extern "system" fn (*mut UNICODE_STRING, *const u16) -> () ;
pub type RtlZeroMemory = unsafe extern "system" fn (PVOID, usize) -> ();
pub type NdrClientCall3 = unsafe extern "C" fn (*mut MIDL_STUBLESS_PROXY_INFO, u32, *mut c_void, ...) -> CLIENT_CALL_RETURN;
pub type RpcStringBindingCompose = unsafe extern "system" fn (*const u16, *const u16, *const u16, *const u16, *const u16, *mut *mut u16) -> i32;
pub type RpcBindingFromStringBinding = unsafe extern "system" fn (*const u16, *mut *mut c_void) -> i32;
pub type RpcStringFree = unsafe extern "system" fn (*mut *mut u16) -> i32; 
pub type RAiLaunchAdminProcess = unsafe extern "system" fn (*mut *mut c_void, *mut u16, *mut u16, i32, i32, *mut u16, *mut u16, *mut APP_STARTUP_INFO, isize, i32, *mut APP_PROCESS_INFORMATION, *mut i32) -> i32;

pub const DLL_PROCESS_DETACH: u32 = 0;
pub const DLL_PROCESS_ATTACH: u32 = 1;
pub const DLL_THREAD_ATTACH: u32 = 2;
pub const DLL_THREAD_DETACH: u32 = 3;

pub const PAGE_READONLY: u32 = 0x2;
pub const PAGE_READWRITE: u32 = 0x4;
pub const PAGE_EXECUTE_READWRITE: u32 = 0x40;
pub const PAGE_EXECUTE_READ: u32 = 0x20;
pub const PAGE_EXECUTE: u32 = 0x10;

pub const MEM_COMMIT: u32 = 0x1000;
pub const MEM_RESERVE: u32 = 0x2000;

pub const SECTION_MEM_READ: u32 = 0x40000000;
pub const SECTION_MEM_WRITE: u32 = 0x80000000;
pub const SECTION_MEM_EXECUTE: u32 = 0x20000000;

// Access mask
pub const GENERIC_READ: u32 = 0x80000000;
pub const GENERIC_WRITE: u32 = 0x40000000;
pub const GENERIC_EXECUTE: u32 = 0x20000000;
pub const GENERIC_ALL: u32 = 0x10000000;
pub const SECTION_ALL_ACCESS: u32 = 0x10000000;
pub const PROCESS_QUERY_LIMITED_INFORMATION: u32 = 0x1000;
pub const THREAD_ALL_ACCESS: u32 =  0x000F0000 |  0x00100000 | 0xFFFF;

//File share flags
pub const FILE_SHARE_NONE: u32 = 0x0;
pub const FILE_SHARE_READ: u32 = 0x1;
pub const FILE_SHARE_WRITE: u32 = 0x2;
pub const FILE_SHARE_DELETE: u32 = 0x4;

//File access flags
pub const DELETE: u32 = 0x10000;
pub const FILE_READ_DATA: u32 = 0x1;
pub const FILE_READ_ATTRIBUTES: u32 = 0x80;
pub const FILE_READ_EA: u32 = 0x8;
pub const READ_CONTROL: u32 = 0x20000;
pub const FILE_WRITE_DATA: u32 = 0x2;
pub const FILE_WRITE_ATTRIBUTES: u32 = 0x100;
pub const FILE_WRITE_EA: u32 = 0x10;
pub const FILE_APPEND_DATA: u32 = 0x4;
pub const WRITE_DAC: u32 = 0x40000;
pub const WRITE_OWNER: u32 = 0x80000;
pub const SYNCHRONIZE: u32 = 0x100000;
pub const FILE_EXECUTE: u32 = 0x20;

// File open flags
pub const FILE_SYNCHRONOUS_IO_NONALERT: u32 = 0x20;
pub const FILE_NON_DIRECTORY_FILE: u32 = 0x40;

pub const SEC_IMAGE: u32 = 0x1000000;

pub const PROCESS_DEBUG_OBJECT_HANDLE: u32 = 30;

// Attributes for ProcThreadAttributeList
pub const PROC_THREAD_ATTRIBUTE_PARENT_PROCESS: u32 = 0x00020000;

// Process creation flags
pub const EXTENDED_STARTUPINFO_PRESENT: u32 = 0x00080000;
pub const CREATE_UNICODE_ENVIRONMENT: u32 = 0x00000400;
pub const DEBUG_PROCESS: u32 = 0x00000001;
pub const CREATE_NEW_CONSOLE: u32 = 0x00000010;

#[repr(C)]
pub struct DBGUI_WAIT_STATE_CHANGE {
    pub new_state: u32,
    pub app_clientid: CLIENT_ID,
    pub state_info: [u8;160],
}

impl Default for DBGUI_WAIT_STATE_CHANGE
{
    fn default() -> DBGUI_WAIT_STATE_CHANGE {
        DBGUI_WAIT_STATE_CHANGE {
            new_state: 0,
            app_clientid: CLIENT_ID { unique_process: HANDLE::default(), unique_thread: HANDLE::default() },
            state_info: [0u8;160],
        }
    }
}

#[repr(C)]
#[allow(non_snake_case)]
pub struct STARTUPINFOEXW {
    pub StartupInfo: STARTUPINFOW,
    pub lpAttributeList: PVOID,
}

#[repr(C)]
#[allow(non_snake_case)]
pub struct STARTUPINFOW {

    pub cb: u32,
    pub lpReserved: PWSTR,
    pub lpDesktop: PWSTR,
    pub lpTitle: PWSTR,
    pub dwX: u32,
    pub dwY: u32,
    pub dwXSize: u32,
    pub dwYSize: u32,
    pub dwXCountChars: u32,
    pub dwYCountChars: u32,
    pub dwFillAttribute: u32,
    pub dwFlags: u32,
    pub wShowWindow: u16,
    pub cbReserved2: u16,
    pub lpReserved2: *mut u8,
    pub hStdInput: HANDLE,
    pub hStdOutput: HANDLE,
    pub hStdError: HANDLE,
}

#[derive(Clone)]
#[repr(C)]
pub struct PeMetadata {
    pub pe: u32,
    pub is_32_bit: bool,
    pub image_file_header: IMAGE_FILE_HEADER,
    pub opt_header_32: IMAGE_OPTIONAL_HEADER32,
    pub opt_header_64: IMAGE_OPTIONAL_HEADER64,
    pub sections: Vec<IMAGE_SECTION_HEADER> 
}

impl Default for PeMetadata {
    fn default() -> PeMetadata {
        PeMetadata {
            pe: u32::default(),
            is_32_bit: false,
            image_file_header: IMAGE_FILE_HEADER::default(),
            opt_header_32: IMAGE_OPTIONAL_HEADER32::default(),
            opt_header_64: IMAGE_OPTIONAL_HEADER64::default(),
            sections: Vec::default(),  
        }
    }
}

#[repr(C)]
pub struct PeManualMap {
    pub decoy_module: String,
    pub base_address: i64,
    pub pe_info: PeMetadata,
}

#[repr(C)]
#[derive(Copy, Clone, Default, PartialEq, Debug, Eq)]
pub struct ApiSetNamespace {
    pub unused: [u8;12],
    pub count: i32, // offset 0x0C
    pub entry_offset: i32, // offset 0x10
}

#[repr(C)]
#[derive(Copy, Clone, Default, PartialEq, Debug, Eq)]
pub struct ApiSetNamespaceEntry {
    pub unused1: [u8;4],
    pub name_offset: i32, // offset 0x04
    pub name_length: i32, // offset 0x08
    pub unused2: [u8;4],
    pub value_offset: i32, // offset 0x10
    pub value_length: i32, // offset 0x14
}

#[repr(C)]
#[derive(Copy, Clone, Default, PartialEq, Debug, Eq)]
pub struct ApiSetValueEntry {
    pub flags: i32, // offset 0x00
    pub name_offset: i32, // offset 0x04
    pub name_count: i32, // offset 0x08
    pub value_offset: i32, // offset 0x0C
    pub value_count: i32, // offset 0x10
}

#[derive(Copy, Clone, Default, PartialEq, Debug, Eq)]
#[repr(C)]
pub struct IMAGE_FILE_HEADER {
    pub machine: u16,
    pub number_of_sections: u16,
    pub time_data_stamp: u32,
    pub pointer_to_symbol_table: u32,
    pub number_of_symbols: u32,
    pub size_of_optional_header: u16,
    pub characteristics: u16,
}

#[derive(Copy, Clone,Default)]
#[repr(C)] // required to keep fields order, otherwise Rust may change that order randomly
pub struct IMAGE_OPTIONAL_HEADER64 {
        pub magic: u16, 
        pub major_linker_version: u8, 
        pub minor_linker_version: u8, 
        pub size_of_code: u32, 
        pub size_of_initialized_data: u32, 
        pub size_of_unitialized_data: u32, 
        pub address_of_entry_point: u32, 
        pub base_of_code: u32, 
        pub image_base: u64, 
        pub section_alignment: u32, 
        pub file_alignment: u32, 
        pub major_operating_system_version: u16, 
        pub minor_operating_system_version: u16, 
        pub major_image_version: u16,
        pub minor_image_version: u16, 
        pub major_subsystem_version: u16,
        pub minor_subsystem_version: u16, 
        pub win32_version_value: u32, 
        pub size_of_image: u32, 
        pub size_of_headers: u32, 
        pub checksum: u32, 
        pub subsystem: u16, 
        pub dll_characteristics: u16, 
        pub size_of_stack_reserve: u64, 
        pub size_of_stack_commit: u64, 
        pub size_of_heap_reserve: u64, 
        pub size_of_heap_commit: u64, 
        pub loader_flags: u32, 
        pub number_of_rva_and_sizes: u32, 
        pub datas_directory: [IMAGE_DATA_DIRECTORY; 16], 
}

#[derive(Copy, Clone, Default, PartialEq, Debug, Eq)]
#[repr(C)]
pub struct GUID
{
    pub data1: u32,
    pub data2: u16,
    pub data3: u16,
    pub data4: [u8; 8],
}

#[derive(Default)]
#[repr(C)]
pub struct APP_PROCESS_INFORMATION
{
    pub process_handle: usize,
	pub thread_handle: usize,
	pub process_id: i32,
	pub thread_id: i32
}

#[derive(Default)]
#[repr(C)]
pub struct MONITOR_POINT
{
    pub left: i32, 
    pub right: i32
}

#[repr(C)]
#[allow(non_snake_case)]
pub struct APP_STARTUP_INFO
{
    pub title: *mut u16,
    pub dwX: i32,
    pub dwY: i32,
    pub dwXSize: i32,
    pub dwYSize: i32,
    pub dwXCountChars: i32,
    pub dwYCountChars: i32,
    pub dwFillAttribute: i32,
    pub dwFlags: i32,
    pub show: i16,
    pub monitor: MONITOR_POINT
}

impl Default for APP_STARTUP_INFO
{
    fn default() -> APP_STARTUP_INFO {
        APP_STARTUP_INFO {
            title: ptr::null_mut(),
            dwX: 0,
            dwY: 0,
            dwXSize: 0,
            dwYSize: 0,
            dwXCountChars: 0,
            dwYCountChars: 0,
            dwFillAttribute: 0,
            dwFlags: 0,
            show: 0,
            monitor: MONITOR_POINT::default()
        }
    }
}

#[repr(C)]
pub struct SYSTEM_HANDLE_INFORMATION {
    pub number_of_handles: u32,
    pub handles: Vec<SYSTEM_HANDLE_TABLE_ENTRY_INFO>,
}

#[repr(C)]
pub struct SYSTEM_HANDLE_TABLE_ENTRY_INFO {
    pub process_id: u16,
    pub creator_back_trace_index: u16,
    pub object_type_index: u8,
    pub handle_attributes: u8,
    pub handle_value: u16,
    pub object: PVOID,
    pub granted_access: u32,
}

#[repr(C)]
pub struct CLIENT_ID {
    pub unique_process: HANDLE,
    pub unique_thread: HANDLE,
}

pub struct DbguiCreateProcess
{
    pub process_handle: HANDLE,
    pub thread_handle: HANDLE,
}

pub struct NtAllocateVirtualMemoryArgs
{
    pub handle: HANDLE, 
    pub base_address: *mut PVOID
}

pub struct NtOpenProcessArgs
{
   pub handle: *mut HANDLE, 
   pub access: u32, 
   pub attributes: *mut OBJECT_ATTRIBUTES, 
   pub client_id: *mut CLIENT_ID
}

pub struct NtProtectVirtualMemoryArgs
{
    pub handle: HANDLE, 
    pub base_address: *mut PVOID,
    pub size: *mut usize, 
    pub protection: u32
}

pub struct NtWriteVirtualMemoryArgs
{
    pub handle: HANDLE, 
    pub base_address: PVOID, 
    pub buffer: PVOID, 
    pub size: usize
}

pub struct NtCreateThreadExArgs
{
    pub thread: *mut HANDLE, 
    pub access: u32, 
    pub attributes: *mut OBJECT_ATTRIBUTES, 
    pub process: HANDLE
}

#[repr(C)]
#[allow(non_snake_case)]
pub struct CONTEXT {

    pub P1Home: u64,
    pub P2Home: u64,
    pub P3Home: u64,
    pub P4Home: u64,
    pub P5Home: u64,
    pub P6Home: u64,
    pub ContextFlags: u32,
    pub MxCsr: u32,
    pub SegCs: u16,
    pub SegDs: u16,
    pub SegEs: u16,
    pub SegFs: u16,
    pub SegGs: u16,
    pub SegSs: u16,
    pub EFlags: u32,
    pub Dr0: u64,
    pub Dr1: u64,
    pub Dr2: u64,
    pub Dr3: u64,
    pub Dr6: u64,
    pub Dr7: u64,
    pub Rax: u64,
    pub Rcx: u64,
    pub Rdx: u64,
    pub Rbx: u64,
    pub Rsp: u64,
    pub Rbp: u64,
    pub Rsi: u64,
    pub Rdi: u64,
    pub R8: u64,
    pub R9: u64,
    pub R10: u64,
    pub R11: u64,
    pub R12: u64,
    pub R13: u64,
    pub R14: u64,
    pub R15: u64,
    pub Rip: u64,
    pub Anonymous: [u8;4096],
    pub VectorRegister: [u8; 128*26],
    pub VectorControl: u64,
    pub DebugControl: u64,
    pub LastBranchToRip: u64,
    pub LastBranchFromRip: u64,
    pub LastExceptionToRip: u64,
    pub LastExceptionFromRip: u64,
}

impl Default for CONTEXT
{
    fn default() -> CONTEXT {
        CONTEXT {
            P1Home: 0, 
            P2Home: 0, 
            P3Home: 0, 
            P4Home: 0, 
            P5Home: 0, 
            P6Home: 0, 
            ContextFlags: 0, 
            MxCsr: 0, 
            SegCs: 0, 
            SegDs: 0, 
            SegEs: 0, 
            SegFs: 0, 
            SegGs: 0, 
            SegSs: 0, 
            EFlags: 0, 
            Dr0: 0, 
            Dr1: 0, 
            Dr2: 0, 
            Dr3: 0, 
            Dr6: 0, 
            Dr7: 0, 
            Rax: 0, 
            Rcx: 0, 
            Rdx: 0, 
            Rbx: 0, 
            Rsp: 0, 
            Rbp: 0, 
            Rsi: 0, 
            Rdi: 0, 
            R8: 0, 
            R9: 0, 
            R10: 0, 
            R11: 0, 
            R12: 0, 
            R13: 0, 
            R14: 0, 
            R15: 0, 
            Rip: 0, 
            Anonymous: [0;4096], 
            VectorRegister: [0; 128*26], 
            VectorControl: 0, 
            DebugControl: 0, 
            LastBranchToRip: 0, 
            LastBranchFromRip: 0, 
            LastExceptionToRip: 0, 
            LastExceptionFromRip: 0 
        }
    }
}

#[repr(C)]
pub struct EXCEPTION_POINTERS {
    pub exception_record: *mut EXCEPTION_RECORD,
    pub context_record: *mut CONTEXT,
}

#[repr(C)]
pub struct PS_ATTRIBUTE_LIST {
    pub size: u32,
    pub unk1: u32,
    pub unk2: u32,
    pub unk3: *mut u32,
    pub unk4: u32,
    pub unk5: u32,
    pub unk6: u32,
    pub unk7: *mut u32,
    pub unk8: u32,

}

pub enum ExceptionHandleFunction
{
    NtOpenProcess,
    NtAllocateVirtualMemory,
    NtWriteVirtualMemory,
    NtProtectVirtualMemory,
    NtCreateThreadEx
}