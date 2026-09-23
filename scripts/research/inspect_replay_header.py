import struct

with open('local/game/savedata/replay.rpl', 'rb') as f:
    d = f.read()

hdr = d[:0x3e24]

# Let's search strings inside the header
strings = []
cur = bytearray()
start = 0
for i, b in enumerate(hdr):
    if 32 <= b < 127:
        if not cur:
            start = i
        cur.append(b)
    else:
        if len(cur) >= 3:
            strings.append((start, cur.decode('latin1')))
        cur = bytearray()

print(f"Strings found in replay header ({len(strings)}):")
for off, s in strings:
    print(f"  0x{off:04x}: {s}")

# Let's inspect specific offsets
print("\n--- Header Structure Field Probing ---")
# 0x00: track or car?
print(f"0x0000..0x0030: {struct.unpack_from('<12I', hdr, 0)}")
