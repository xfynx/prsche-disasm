import struct

with open('local/game/nfs5.exe', 'rb') as f:
    exe_data = f.read()

def find_refs(target_va, name=""):
    pat = struct.pack('<I', target_va)
    pos = 0
    refs = []
    while True:
        idx = exe_data.find(pat, pos)
        if idx == -1:
            break
        refs.append(0x400000 + idx)
        pos = idx + 1
    print(f"References to {name} (0x{target_va:08x}): {[hex(r) for r in refs]}")
    return refs

find_refs(0x005e9a20, "ReplayBuffer")
find_refs(0x005ed844, "ReplayTickCount")
find_refs(0x00606a80, "GlobalTick")
find_refs(0x00606ac4, "GlobalTick2")
find_refs(0x005e99f4, "ReplayState")
find_refs(0x005e99f8, "ReplayPtr")
