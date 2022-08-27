fn main() {
    windows::build!(
        Windows::Win32::System::Diagnostics::Debug::{GetThreadContext,SetThreadContext,IMAGE_FILE_HEADER,IMAGE_OPTIONAL_HEADER32,IMAGE_SECTION_HEADER,
            IMAGE_DATA_DIRECTORY,IMAGE_OPTIONAL_HEADER_MAGIC,IMAGE_SUBSYSTEM, DEBUG_EVENT},
        Windows::Win32::System::Memory::{VIRTUAL_ALLOCATION_TYPE,PAGE_PROTECTION_FLAGS},
        Windows::Win32::Foundation::{HANDLE,HINSTANCE,PSTR,BOOL},
        Windows::Win32::System::Threading::{GetCurrentProcess,GetCurrentThread,PROCESS_BASIC_INFORMATION,PROCESS_INFORMATION},
        Windows::Win32::System::SystemServices::{IMAGE_BASE_RELOCATION,IMAGE_IMPORT_DESCRIPTOR,IMAGE_THUNK_DATA32,IMAGE_THUNK_DATA64,OVERLAPPED},
        Windows::Win32::System::WindowsProgramming::{PUBLIC_OBJECT_TYPE_INFORMATION,OBJECT_ATTRIBUTES,IO_STATUS_BLOCK},
        Windows::Win32::Security::SECURITY_ATTRIBUTES,
        Windows::Win32::System::Kernel::UNICODE_STRING,
        Windows::Win32::System::Rpc::{MIDL_STUBLESS_PROXY_INFO,CLIENT_CALL_RETURN},
    );
}