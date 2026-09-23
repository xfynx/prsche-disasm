import struct
import capstone

with open('local/game/nfs5.exe', 'rb') as f:
    data = f.read()

def va_to_raw(va):
    return va - 0x00401000 + 0x1000

def raw_to_va(raw):
    return 0x00401000 + (raw - 0x1000)

target_vas = [
    0x004be121, 0x004ddd11, 0x004e2c51, 0x004f7701,
    0x004fac91, 0x00501131, 0x00502741, 0x005177c1, 0x0051a711
]

md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
for va in target_vas:
    raw = va_to_raw(va - 16)
    code = data[raw:raw + 64]
    print(f"=== Section Registration around VA 0x{va:08x} ===")
    for i in md.disasm(code, va - 16):
        if i.mnemonic == 'mov' and '0x5' in i.op_str:
            parts = i.op_str.split(',')
            if len(parts) == 2:
                try:
                    imm = int(parts[1].strip(), 16)
                    if 0x005b0000 <= imm <= 0x006c0000:
                        imm_raw = 0x1cb000 + (imm - 0x005cb000) if imm >= 0x005cb000 else 0x1b2000 + (imm - 0x005b2000)
                        if 0 <= imm_raw < len(data):
                            s = data[imm_raw:imm_raw+32].split(b'\x00')[0]
                            if s and all(32 <= b <= 126 for b in s):
                                print(f"   -> Found section tag: '{s.decode()}' at VA 0x{imm:08x}")
                except Exception:
                    pass
        print(f"   0x{i.address:08x}: {i.mnemonic:10s} {i.op_str}")
