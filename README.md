# Description

Elevator allows to bypass the UAC and spawn an elevated process with full administrator privileges. This is done by abusing the behaviour of the RPC server that implements the UAC feature, as demonstrated by James Forshaw in his article [Calling Local Windows RPC Servers from .NET](https://googleprojectzero.blogspot.com/2019/12/calling-local-windows-rpc-servers-from.html). The tool does not require to drop an extra DLL or write to the Windows Registry (as is often the case with other UAC bypass techniques), and it has been successfully tested on Windows Server 2016, Windows Server 2019, Windows 10 and Windows 11 (it probably works on other versions of Windows).

The tool is composed of a C++ stub that connects the tool itself with the RPC server exposed by the service APPINFO, and the Rust project that contains the main logic that allows to abuse the bug and bypass the UAC. The C++ stub has been obtained from compiling the IDL file that RPC View created from the RPC interface with ID 201ef99a-7fa0-444c-9399-19ba84f12a1a.

The C++ RPC stub has been compiled to a dll and its binary content has been encrypted and hardcoded into the Rust crate (check out the function get_rpc_stub() in the crate rpcclient). Then, the dll is manually mapped in runtime using [DInvoke_rs](https://github.com/Kudaes/DInvoke_rs). If you want to go through this process by yourself (which is not needed in order to use the tool), just open the project RPC_Stub on Visual Studio 2019+ and compile the dll. After that, use the script.py (Python 2.7) included in the repo to obtain a hex string from the binary content of the dll, that should be placed in the function rppclient::get_rpc_stub().

Valid only for x64 systems.

# Compilation 

Since we are using [LITCRYPT](https://github.com/anvie/litcrypt.rs) plugin to obfuscate string literals, it is required to set up the environment variable LITCRYPT_ENCRYPT_KEY before compiling the code:

	C:\Users\User\Desktop\Elevator> set LITCRYPT_ENCRYPT_KEY="yoursupersecretkey"

After that, move into the Elevator folder and simply compile the code:

	C:\Users\User\Desktop\Elevator\Elevator> cargo build --release
	C:\Users\User\Desktop\Elevator\Elevator\target\release> elevator.exe -h

# Usage

	USAGE:
    elevator.exe <COMMAND> [OPTIONS]

	ARGS:
	    <COMMAND>                   Command line to run.

	OPTIONS:
	    -h, --help                  Print help information.
	    -n, --new-console           Set CREATE_NEW_CONSOLE flag for the new process.

# Examples

	C:\Temp> elevator.exe c:\windows\system32\cmd.exe --new-console
	C:\Temp> elevator.exe "c:\windows\system32\cmd.exe /C whoami /groups > file.txt" --new-console

# Credits
* [James Forshaw](https://twitter.com/tiraniddo).
* [Clément Labro (itm4n)](https://twitter.com/itm4n) for his great posts about RPC.
