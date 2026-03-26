from typing import TYPE_CHECKING, Any

if TYPE_CHECKING:
    def Import(name: str) -> Any: ...
    env: Any
Import("env")
def objcopy_to_hex(source, target, env):
    print("--------------------------------------------------")
    print("Đang tạo file HEX chuẩn...")
    elf_file = str(target[0])
    hex_file = elf_file.replace(".elf", ".hex")
    env.Execute(f"$OBJCOPY -O ihex {elf_file} {hex_file}")
    print(f"Hoàn tất! File hex tại: {hex_file}")
    print("--------------------------------------------------")

env.AddPostAction("$BUILD_DIR/${PROGNAME}.elf", objcopy_to_hex)