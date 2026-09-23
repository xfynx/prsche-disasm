import capstone

with open('local/game/nfs5.exe', 'rb') as f:
    exe_data = f.read()

md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)

def disasm_range(start_va, length):
    raw_off = start_va - 0x400000
    code = exe_data[raw_off:raw_off+length]
    print(f"=== Disassembly from 0x{start_va:08x} ({length} bytes) ===")
    for ins in md.disasm(code, start_va):
        print(f"0x{ins.address:08x}:  {ins.mnemonic:<8} {ins.op_str}")

disasm_range(0x004143f0, 160)
print("\n" + "="*50 + "\n")
disasm_range(0x00413870, 160)
