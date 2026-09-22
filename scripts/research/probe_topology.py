import glob
import struct

for path in sorted(glob.glob("local/game/GameData/Track/*.edg")):
    name = path.split("\\")[-1]
    with open(path, "rb") as f:
        data = f.read()
    u32_0, u32_1 = struct.unpack("<II", data[:8])
    u16_all = struct.unpack("<4H", data[:8])
    print(f"{name:15s}: len={len(data):7d} | u32=[{u32_0}, {u32_1}] | u16={u16_all}")



