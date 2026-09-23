import csv
from pathlib import Path
import struct

# Load festrings.csv
strings = {}
with open("local/game/FEData/Locale/festrings.csv", "r", encoding="latin-1") as f:
    for line in f:
        line = line.strip()
        if not line or line.startswith('#'): continue
        parts = line.split(',', 1)
        if len(parts) == 2 and parts[0].isdigit():
            strings[int(parts[0])] = parts[1].strip('"')

print(f"Loaded {len(strings)} strings from festrings.csv")

trn_data = Path("local/game/FEData/Data/nfs5.trn").read_bytes()

for i in range(35):
    chunk = trn_data[i * 3392 : (i + 1) * 3392]
    # First 32 bytes contain IDs or text
    # In nfs-formats career.rs, let's see how we parsed TournamentRecord:
    # name_id is at offset 32: u32
    name_id = struct.unpack('<I', chunk[32:36])[0]
    desc_id = struct.unpack('<I', chunk[36:40])[0]
    name_str = strings.get(name_id, f"ID_{name_id}")
    desc_str = strings.get(desc_id, f"ID_{desc_id}")
    
    # Let's inspect where actual num_stages, fee, prize, etc. are:
    # In chunk[48..] or chunk[64..]
    ints = struct.unpack('<32I', chunk[:128])
    print(f"[{i:02d}] Name ({name_id}): {name_str!r}")
    print(f"     Desc ({desc_id}): {desc_str[:60]!r}...")
