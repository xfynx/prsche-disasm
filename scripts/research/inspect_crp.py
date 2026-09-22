from pathlib import Path
import struct, json, hashlib

ROOT=Path(r'C:\Program Files (x86)\by Decepticon\Need for Speed - Porsche Unleashed\GameData\CarModel')
OUT=Path(__file__).parent
def u32(d,o=0): return struct.unpack_from('<I',d,o)[0]
def dec(d):
    if d[:2]!=b'\x10\xfb': return d
    size=int.from_bytes(d[2:5],'big'); out=bytearray(); p=5
    while True:
        c=d[p];p+=1
        if c<0x80:
            a=d[p];p+=1;lit=c&3;n=((c>>2)&7)+3;dist=((c>>5)<<8)+a+1
        elif c<0xc0:
            a,b=d[p:p+2];p+=2;lit=a>>6;n=(c&63)+4;dist=((a&63)<<8)+b+1
        elif c<0xe0:
            a,b,e=d[p:p+3];p+=3;lit=c&3;n=((c>>2)&3)*256+e+5;dist=((c&16)<<12)+(a<<8)+b+1
        else:
            lit=((c&31)*4+4) if c<0xfc else c&3;n=0;dist=0
        assert p+lit<=len(d)
        out.extend(d[p:p+lit]);p+=lit
        if n:
            assert 0<dist<=len(out)
            for _ in range(n):out.append(out[-dist])
        assert len(out)<=size
        if c>=0xfc:break
    assert len(out)==size,(len(out),size)
    return bytes(out)
def entry(d,o):
    ident,lf,count,offs=struct.unpack_from('<4I',d,o);length=lf>>8;flag=lf&255
    idx=ident&65535 if flag&1 else 0;ident=ident>>16 if flag&1 else ident
    tag=ident.to_bytes(2 if flag&1 else 4,'big').decode('ascii',errors='replace')
    target=o+(offs if length else offs*16)
    assert target+(length if length else count*16)<=len(d)
    e=dict(tag=tag,index=idx,length=length,count=count,offset=o,target=target)
    if not length:e['entries']=[entry(d,target+i*16) for i in range(count)]
    return e
def analyze(car):
    source=(ROOT/f'{car}.crp').read_bytes();d=dec(source);(OUT/f'{car}.crp').write_bytes(d)
    articles=u32(d,4)>>5;misc=u32(d,8);base=u32(d,12)*16
    es=[entry(d,base+i*16) for i in range(articles+misc)]
    for e in es:
        if 'entries' in e:
            for s in e['entries']:
                b=d[s['target']:s['target']+s['length']]
                if s['tag']=='Name':e['name']=b.split(b'\0')[0].decode(errors='replace')
                if s['tag']=='Base':
                    e['base_info']=list(b[68:84]);e['levels']=[struct.unpack_from('<I4H',b,100+i*12) for i in range(u32(b,12))]
                if s['tag']=='pr':s['material']=struct.unpack_from('<H',b,4)[0];s['transparency']=struct.unpack_from('<H',b,2)[0]
        if e['tag']=='mt':
            b=d[e['target']:e['target']+e['length']];e['render']=b[16:32].split(b'\0')[0].decode();e['tpg']=u32(b,40);e['raw']=b.hex()
        if e['tag']=='sf':
            b=d[e['target']:e['target']+e['length']];(OUT/f'{car}-sf-{e["index"]}.fsh').write_bytes(b)
            e['magic']=b[:4].decode(errors='replace');e['textures']=[]
            if b[:4]==b'SHPI':
                for i in range(u32(b,8)):
                    name=b[16+i*8:20+i*8].decode(errors='replace');t=u32(b,20+i*8)
                    e['textures'].append(dict(name=name,offset=t,header=struct.unpack_from('<I6H',b,t)))
    info=dict(car=car,sha256=hashlib.sha256(source).hexdigest(),compressed_size=len(source),decoded_size=len(d),decoded_sha256=hashlib.sha256(d).hexdigest(),articles=articles,misc=misc,entries=es)
    (OUT/f'{car}.json').write_text(json.dumps(info,indent=2),encoding='utf8')
    print(car,len(source),len(d),articles,misc)
    for e in es:
        if e['tag']=='Arti':print('part',e.get('name'),e.get('base_info'),[x[3] for x in e.get('levels',[])])
        else:print(e['tag'],e['index'],e['length'],e.get('tpg',''),e.get('render',''),e.get('textures',''))
    for ext in ['tpg','clr']:
        b=(ROOT/f'{car}.{ext}').read_bytes();print(ext,len(b),b[:200].hex(),b[:200])
if __name__=='__main__':
    analyze('356a');analyze('356b')
