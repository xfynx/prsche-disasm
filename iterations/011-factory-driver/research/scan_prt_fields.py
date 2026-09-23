import struct
from pathlib import Path

prt_data = Path("local/game/FEData/Data/nfs5.prt").read_bytes()
count = len(prt_data) // 360

for i in range(25):
    chunk = prt_data[i * 360 : (i + 1) * 360]
    part_id = struct.unpack('<I', chunk[0:4])[0]
    car_name = chunk[8:40].split(b'\x00')[0].decode('ascii', errors='ignore')
    cat_name = chunk[40:72].split(b'\x00')[0].decode('ascii', errors='ignore')
    price = struct.unpack('<I', chunk[92:96])[0]
    
    # Let's inspect non-zero bytes after offset 72
    non_zeros = []
    for off in range(72, 360, 4):
        val = struct.unpack('<I', chunk[off:off+4])[0]
        fval = struct.unpack('<f', chunk[off:off+4])[0]
        if val != 0:
            non_zeros.append((off, hex(off), val, fval))
    print(f"ID={part_id:<3} {car_name:<6} {cat_name:<10} price={price:<5} non_zeros={non_zeros}")

