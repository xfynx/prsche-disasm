import struct
from pathlib import Path

# Load festrings.csv
strings = {}
with open("local/game/FEData/Locale/festrings.csv", "r", encoding="latin-1") as f:
    for line in f:
        line = line.strip()
        if not line or line.startswith('#'): continue
        parts = line.split(',', 1)
        if len(parts) == 2 and parts[0].isdigit():
            # Get English string (first entry in CSV line)
            eng = parts[1].split(',')[0].strip('"')
            strings[int(parts[0])] = eng

prt_data = Path("local/game/FEData/Data/nfs5.prt").read_bytes()
count = len(prt_data) // 360
print(f"Total parts: {count}")

categories = set()
cars = set()
sample_parts = []

for i in range(count):
    chunk = prt_data[i * 360 : (i + 1) * 360]
    part_id = struct.unpack('<I', chunk[0:4])[0]
    name_id = struct.unpack('<I', chunk[4:8])[0]
    car_name = chunk[8:40].split(b'\x00')[0].decode('ascii', errors='ignore')
    cat_name = chunk[40:72].split(b'\x00')[0].decode('ascii', errors='ignore')
    price = struct.unpack('<I', chunk[92:96])[0]
    
    # Let's inspect floats around offset 96..140
    floats = struct.unpack('<8f', chunk[96:128])
    
    part_title = strings.get(name_id, f"ID_{name_id}")
    categories.add(cat_name)
    cars.add(car_name)
    if i < 30:
        sample_parts.append((part_id, car_name, cat_name, part_title, price, floats[:4]))

print("Discovered Categories:", sorted(list(categories)))
print(f"Cars with parts ({len(cars)}):", sorted(list(cars))[:10])
print("\nSample 356 Parts:")
for p in sample_parts[:15]:
    print(f"ID={p[0]:<4} Car={p[1]:<10} Cat={p[2]:<12} Price={p[4]:<6} CR  Title={p[3]!r}  Floats={p[5]}")

