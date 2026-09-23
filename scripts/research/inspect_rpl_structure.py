import struct
import binascii

with open('local/game/savedata/replay.rpl', 'rb') as f:
    d = f.read()

print(f"Total size: {len(d)} (0x{len(d):x})")

print("--- Header dwords/floats ---")
for i in range(0, 160, 4):
    u = struct.unpack_from('<I', d, i)[0]
    flt = struct.unpack_from('<f', d, i)[0]
    asc = ''.join(chr(b) if 32 <= b < 127 else '.' for b in d[i:i+4])
    print(f"0x{i:04x} (+{i:3}): hex=0x{u:08x} int={u:10} | f32={flt:14.4f} | str='{asc}'")
