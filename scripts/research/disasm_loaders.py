import capstone

with open('local/game/nfs5.exe', 'rb') as f:
    exe_data = f.read()

# PE offsets: in .text section, VA = 0x400000 + file_offset
# EDG function around 0x488090 (file offset 0x88090)
# JNC function around 0x487880 (file offset 0x87880)

md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)

def disasm_range(start_va, length):
    file_off = start_va - 0x400000
    code = exe_data[file_off : file_off + length]
    print(f"=== Disassembly from VA 0x{start_va:08x} ({length} bytes) ===")
    for instr in md.disasm(code, start_va):
        print(f"0x{instr.address:08x}:  {instr.mnemonic:<7} {instr.op_str}")

print("DISASSEMBLING EDG LOADER:")
disasm_range(0x488090, 300)

print("\nDISASSEMBLING JNC LOADER:")
disasm_range(0x487880, 200)
