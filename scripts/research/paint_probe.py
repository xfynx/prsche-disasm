from pathlib import Path
from collections import Counter
import struct, sys
from inspect_crp import dec, entry, u32

root=Path(__file__).resolve().parents[1]/'game/GameData/CarModel'
for car in sys.argv[1:]:
    d=dec((root/(car+'.crp')).read_bytes())
    start=u32(d,12)*16; articles=u32(d,4)>>5
    for i in range(articles, articles+u32(d,8)):
        e=entry(d,start+i*16)
        if e['tag']!='sf' or e['index']>2: continue
        f=d[e['target']:e['target']+e['length']]
        for j in range(u32(f,8)):
            name=f[16+j*8:20+j*8].decode().strip('\0')
            off=u32(f,20+j*8); w,h=struct.unpack_from('<HH',f,off+4)
            if f[off]!=0x7d: continue
            pixels=f[off+16:off+16+w*h*4]
            a=Counter(pixels[3::4]); white=Counter(); dark=Counter()
            for k in range(0,len(pixels),4):
                b,g,r,alpha=pixels[k:k+4]
                if min(b,g,r)>220: white[alpha]+=1
                if max(b,g,r)<35: dark[alpha]+=1
            print(car,e['index'],name,'alpha',a.most_common(5),'white',white.most_common(3),'dark',dark.most_common(3))
