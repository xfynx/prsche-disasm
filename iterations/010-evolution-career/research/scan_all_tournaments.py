import struct
from pathlib import Path

trn_path = Path("local/game/GameData/nfs5.trn")
data = trn_path.read_bytes()
print(f"nfs5.trn size: {len(data)}, tournaments: {len(data) // 3392}")

tournaments = []
for i in range(len(data) // 3392):
    chunk = data[i * 3392 : (i + 1) * 3392]
    # Name is 32 bytes ASCII
    name = chunk[:32].split(b'\x00')[0].decode('ascii', errors='ignore')
    # Let's inspect fields
    # num_stages is at offset 0x24 (36) or around there
    # Let's unpack first 64 bytes as ints
    ints = struct.unpack('<16I', chunk[:64])
    # Let's find num_stages and other properties
    stages_count = chunk[32] # or let's inspect
    print(f"[{i:02d}] Name: {name!r}, ints[:8]: {ints[:8]}")

