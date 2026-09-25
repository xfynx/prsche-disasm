import struct
from pathlib import Path

prt_path = Path("local/game/FEData/Data/nfs5.prt")
prt_data = prt_path.read_bytes()
print(f"nfs5.prt size: {len(prt_data)}")

trn_path = Path("local/game/FEData/Data/nfs5.trn")
trn_data = trn_path.read_bytes()
print(f"nfs5.trn size: {len(trn_data)}, count: {len(trn_data) // 3392}")

# Let's inspect nfs5.prt structure
# Check if it has a header or fixed-size records
print("First 128 bytes of nfs5.prt:")
print(prt_data[:128].hex(' '))

# Let's find strings or record size in prt_data
import re
ascii_strings = [m.group(0).decode('ascii') for m in re.finditer(b'[A-Za-z0-9_ -]{4,}', prt_data[:2048])]
print("Sample strings in prt:", ascii_strings[:20])

# Inspect tournaments
for i in range(len(trn_data) // 3392):
    chunk = trn_data[i * 3392 : (i + 1) * 3392]
    name = chunk[:32].split(b'\x00')[0].decode('ascii', errors='ignore')
    num_stages = struct.unpack('<I', chunk[36:40])[0]
    entry_fee = struct.unpack('<I', chunk[40:44])[0]
    first_prize = struct.unpack('<I', chunk[44:48])[0]
    # Era or class? Let's check chunk[32:36]
    prop0 = struct.unpack('<I', chunk[32:36])[0]
    print(f"[{i:02d}] {name:<30} stages={num_stages} fee={entry_fee:<6} prize={first_prize:<7} prop0=0x{prop0:04x}")
