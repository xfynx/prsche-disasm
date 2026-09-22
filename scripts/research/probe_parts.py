"""Read-only CRP part metadata for assembly investigations."""
from pathlib import Path
import struct
import sys
from inspect_crp import dec, entry, u32

root = Path(__file__).resolve().parents[1] / 'game/GameData/CarModel'
for car in sys.argv[1:]:
    d = dec((root / (car + '.crp')).read_bytes())
    records = [entry(d, u32(d, 12)*16 + i*16) for i in range(u32(d, 4) >> 5)]
    levels = {}
    for a in records:
        parts = a.get('entries', [])
        name = next((d[e['target']:e['target']+e['length']].split(b'\0')[0].decode() for e in parts if e['tag']=='Name'), '?')
        base = next((e for e in parts if e['tag']=='Base'), None)
        if not base: continue
        b = d[base['target']:base['target']+base['length']]
        lods = [struct.unpack_from('<I4H', b, 100+i*12) for i in range(u32(b, 12))]
        if b[69] != 0 or b[78]&128: continue
        levels.setdefault(tuple(x[3] for x in lods), []).append(name)
        for p in parts:
            if p['tag'] != 'pr' or p['index'] >> 12 != lods[0][3]: continue
            raw = d[p['target']:p['target']+p['length']]
            ni, nd = struct.unpack_from('<II', raw, 40)
            infos = [struct.unpack_from('<II4H', raw, 48+i*16) for i in range(ni)]
            rows = [struct.unpack_from('<HHI', raw, 48+ni*16+i*8) for i in range(nd)]
            if nd and (not any(r[1]==0x4976 for r in rows) or not any(r[1]==0x4975 for r in rows)):
                print(car, name, hex(p['offset']), 'pr',hex(p['index']), 'count',p['count'],'infos',infos,'rows',rows)
    print(car, 'LEVEL GROUPS', levels)
