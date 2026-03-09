import os.path
import warnings

Import('env')

NULINK_CLI_EXE_8051T = '"%PROGRAMFILES(X86)%\\Nuvoton Tools\\NuLink Command Tool\\NuLink_8051OT.exe"'
NULINK_NOT_FOUND_MSG = '''
Please install %s from:
    https://www.nuvoton.com/tool-and-software/software-development-tool/programmer
'''

def on_build(source, target, env):
    firmware_path = os.path.abspath(str(source[0]))  
    bin_path = os.path.splitext(firmware_path)[0] + ".bin"
    ih = IntelHex(firmware_path)
    ih.tobinfile(bin_path)

    print(f"Generated BIN file: {bin_path}")

def on_upload(source, target, env):
    firmware_path = os.path.abspath(str(source[0])) 
    print("\033[93;41m Upload use CLI \033[0m")
    try:
        env.Execute(f'{NULINK_CLI_EXE_8051T} -e aprom')
        env.Execute(f'{NULINK_CLI_EXE_8051T} -w aprom {firmware_path}')
    except:
        warnings.warn(NULINK_NOT_FOUND_MSG % 'NuLinkCLI')
        exit(2)
    __import__('time').sleep(0.1)



env.Replace(UPLOADCMD=on_upload)