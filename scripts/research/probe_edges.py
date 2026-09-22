import struct
from pathlib import Path

for track in ["skidpad", "alps"]:
    path = Path(f"local/game/GameData/Track/{track}.edg")
    if not path.is_file(): continue
    data = path.read_bytes()[4:]
    n = len(data) // 28
    print(f"=== {track}: {n} edges ===")
    for i in range(min(12, n)):
        flags, x1, y1, z1, x2, y2, z2 = struct.unpack("<B3x3f3f", data[i*28:(i+1)*28])
        print(f"  {i:2d}: flags=0x{flags:02x} p1=({x1:8.2f}, {y1:6.2f}, {z1:8.2f}) -> p2=({x2:8.2f}, {y2:6.2f}, {z2:8.2f})")
