import struct
import capstone

with open('local/game/nfs5.exe', 'rb') as f:
    exe_data = f.read()

md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)

def find_calls(target_va, name=""):
    print(f"Finding calls to {name} (0x{target_va:08x}):")
    for off in range(0, 0x1b0000 - 5):
        if exe_data[off] == 0xe8: # relative call
            rel = struct.unpack_from('<i', exe_data, off+1)[0]
            call_target = (0x400000 + off + 5) + rel
            if call_target == target_va:
                caller_va = 0x400000 + off
                print(f"  Call from 0x{caller_va:08x}")
                # print few instructions before
                code = exe_data[off-30:off+5]
                for ins in md.disasm(code, caller_va-30):
                    print(f"    0x{ins.address:08x}: {ins.mnemonic:<8} {ins.op_str}")

find_calls(0x00414060, "RecordFrame")
find_calls(0x004141a0, "PlaybackFrame")
