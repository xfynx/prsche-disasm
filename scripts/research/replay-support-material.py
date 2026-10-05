"""Replay original mt pointer resolution/assignment and support flag consumption.

The resource parser census is read-only. Each x86 replay supplies allocation
results, but executes original pointer resolution, assignment, constructors and
the material consumer without patching instructions or substituting calls.
"""
import argparse
from collections import Counter
import importlib.util
import json
from pathlib import Path
import struct

spec = importlib.util.spec_from_file_location('support', Path(__file__).with_name('replay-support-polygons.py'))
support = importlib.util.module_from_spec(spec)
spec.loader.exec_module(support)
response = support.response
spec = importlib.util.spec_from_file_location('crp', Path(__file__).with_name('inspect_crp.py'))
crp = importlib.util.module_from_spec(spec)
spec.loader.exec_module(crp)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_EBX, UC_X86_REG_ECX, UC_X86_REG_EDX, UC_X86_REG_EBP, UC_X86_REG_ESI, UC_X86_REG_EDI, UC_X86_REG_ESP, UC_X86_REG_EIP

OWNER, BUNDLE = response.CAR+0x1000, response.CAR+0x1100
MATERIALS, TABLE, MATERIAL = response.CAR+0x1200, response.CAR+0x1300, response.CAR+0x1800
ENTRY, PAYLOAD, PRIMITIVE = response.CAR+0x1900, response.CAR+0x1a00, response.CAR+0x1b80
RANGES = ((0x44ab07,0x44ab31),(0x44abe1,0x44abfb),(0x489160,0x4891a6),
          (0x474ac0,0x474ad2),(0x474b90,0x474bae),(0x539f30,0x539f34),
          (0x475398,0x47542d))


def until(uc, entry, stops):
    def stop(machine,address,_size,_data):
        if address in stops:
            machine.emu_stop()
    hook=uc.hook_add(UC_HOOK_CODE,stop)
    uc.emu_start(entry,response.EXIT,count=10000)
    uc.hook_del(hook)
    result=uc.reg_read(UC_X86_REG_EIP)
    if result not in stops:
        raise RuntimeError('original path did not reach expected stop')
    return result


def census():
    tracks=[]
    all_words=set()
    for path in sorted((response.ROOT/'local/game/GameData/Track').glob('*.crp')):
        source=path.read_bytes()
        decoded=crp.dec(source)
        if decoded[:4]!=b'karT':
            raise RuntimeError(f'unexpected track magic: {path}')
        articles,misc,base=crp.u32(decoded,4)>>5,crp.u32(decoded,8),crp.u32(decoded,12)*16
        materials=[]
        table={}
        for i in range(misc):
            record=crp.entry(decoded,base+(articles+i)*16)
            if record['tag']=='mt':
                if not crp.u32(decoded,record['offset']+4)&1:
                    raise RuntimeError('census expects indexed original mt entries')
                if record['length']<4:
                    raise RuntimeError('short mt payload')
                word=crp.u32(decoded,record['target'])
                materials.append({'index':record['index'],'flags':word})
                table[record['index']]=word
                all_words.add(word)
        histogram=Counter(m['flags'] for m in materials)
        tracks.append({'path':path.relative_to(response.ROOT/'local/game').as_posix(),
                       'sha256':response.hashlib.sha256(source).hexdigest(),
                       'decoded_sha256':response.hashlib.sha256(decoded).hexdigest(),
                       'material_count':len(materials),
                       'table_size':max(table,default=0)+1,
                       'table_occupied':len(table),
                       'effective_flags_histogram':{f'0x{k:08x}':v for k,v in sorted(Counter(table.values()).items())},
                       'low_nibble_eligible':sum(bool(m['flags']&15) for m in materials),
                       'flags_histogram':{f'0x{k:08x}':v for k,v in sorted(histogram.items())}})
    if len(tracks)!=15:
        raise RuntimeError(f'expected current 15-track corpus, got {len(tracks)}')
    return tracks,all_words


def run_case(module,data,flags,index,relative,caller_flag):
    vertices=[[0.,0.,0.],[10.,0.,0.],[0.,0.,10.]]
    uc=support.make(module,data,vertices,1,RANGES)
    # Supply an mt record, synthetic payload, and an already allocated table
    # entry. This bounds out material allocation and renderer method lookup.
    support.words(uc,ENTRY,[0x6d740000|index,(0x138<<8)|1|(2 if relative else 0),1,
                            PAYLOAD-ENTRY if relative else PAYLOAD])
    payload=struct.pack('<I',flags)+b'\0'*8+struct.pack('<I',0xa5a55a5a)+b'\0'*296
    uc.mem_write(PAYLOAD,payload)
    support.words(uc,response.STACK+0x28,[MATERIALS])
    support.words(uc,MATERIALS,[TABLE])
    support.words(uc,TABLE+index*4,[MATERIAL])
    uc.reg_write(UC_X86_REG_ESP,response.STACK)
    uc.reg_write(UC_X86_REG_EAX,ENTRY)
    uc.reg_write(UC_X86_REG_EDX,(0x138<<8)|1|(2 if relative else 0))
    until(uc,0x44ab07,{0x44ab30})
    pointer,=struct.unpack('<I',uc.mem_read(response.STACK+0x14,4))
    assert pointer==PAYLOAD
    # Run the actual material table-entry field writes after allocation.
    uc.reg_write(UC_X86_REG_ECX,MATERIALS)
    uc.reg_write(UC_X86_REG_EBX,index)
    uc.reg_write(UC_X86_REG_ESI,response.CAR+0x1c00)
    until(uc,0x44abe1,{0x44abfa})
    pointer,=struct.unpack('<I',uc.mem_read(MATERIAL+0x18,4))
    assert pointer==PAYLOAD
    # Original owner constructor stores its second argument at owner+0x2c.
    support.execute(uc,0x489160,[0x41727469,MATERIALS],OWNER)
    support.execute(uc,0x474b90,[OWNER],BUNDLE)
    support.words(uc,response.STACK+0x24,[BUNDLE])
    support.words(uc,PRIMITIVE+4,[0xbeef0000|index])
    uc.mem_write(response.STACK+0x190,bytes([caller_flag]))
    uc.reg_write(UC_X86_REG_ESP,response.STACK)
    uc.reg_write(UC_X86_REG_EBP,PRIMITIVE)
    uc.reg_write(UC_X86_REG_EAX,3)
    stop=until(uc,0x475398,{0x4753d2,0x47542c})
    actual=uc.reg_read(UC_X86_REG_EDI)
    alternate=stop==0x4753d2
    assert actual==flags
    assert alternate==bool(caller_flag and flags&0xffffff0f==0)
    support.execute(uc,0x485c50,[support.PTRS,support.COLORS,actual],support.OBJ)
    polygon_word,=struct.unpack('<H',uc.mem_read(support.OBJ+0xa,2))
    assert polygon_word==flags&0xffff
    return {'flags':flags,'index':index,'relative':relative,'caller_flag':caller_flag,
            'original_flags':actual,'original_polygon_word':polygon_word,
            'original_alternate_primitive':alternate}


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output',type=Path,required=True)
    parser.add_argument('--fixture-tsv',type=Path,required=True)
    parser.add_argument('--census-output',type=Path,required=True)
    args=parser.parse_args()
    inventory=response.ROOT/'research/binary-index/static/binaries.jsonl'
    module,=[m for m in map(json.loads,inventory.read_text(encoding='utf-8').splitlines()) if m['file']=='Porsche.exe']
    data=(response.ROOT/'local/game'/module['path']).read_bytes()
    if response.hashlib.sha256(data).hexdigest()!=response.SHA or module['sha256']!=response.SHA:
        raise RuntimeError('original SHA256 mismatch')
    tracks,corpus_words=census()
    words=sorted(corpus_words|{0,1,15,16,32,64,128,255,0x100,0x10000,0x80000000,0xffffffff})
    cases=[run_case(module,data,word,index,relative,caller)
           for word in words for index in (0,17) for relative in (False,True) for caller in (0,1)]
    result={'module':'Porsche.exe','sha256':response.SHA,
            'scope':'original bounded pointer resolution, material entry writes, owner/bundle constructors, material consumer and triangle constructor; synthetic allocated buffers',
            'case_count':len(cases),'corpus_flag_words':sorted(corpus_words),'cases':cases}
    args.output.parent.mkdir(parents=True,exist_ok=True)
    prefix={k:v for k,v in result.items() if k!='cases'}
    header=json.dumps(prefix,indent=2)[:-2]
    args.output.write_text(header+',\n  "cases": [\n'+',\n'.join('    '+json.dumps(c) for c in cases)+'\n  ]\n}\n',encoding='utf-8')
    rows=['flags\tindex\trelative\tcaller_flag\toriginal_flags\tpolygon_word\talternate']
    for c in cases:
        rows.append('\t'.join(map(str,[c['flags'],c['index'],int(c['relative']),c['caller_flag'],
                                      c['original_flags'],c['original_polygon_word'],int(c['original_alternate_primitive'])])))
    args.fixture_tsv.parent.mkdir(parents=True,exist_ok=True)
    args.fixture_tsv.write_text('\n'.join(rows)+'\n',encoding='utf-8')
    args.census_output.parent.mkdir(parents=True,exist_ok=True)
    args.census_output.write_text(json.dumps({'tracks':tracks,'total_materials':sum(t['material_count'] for t in tracks)},indent=2)+'\n',encoding='utf-8')
    rows=['path\tmaterial_count\ttable_size\toccupied\teffective_histogram']
    for track in tracks:
        histogram=','.join(f'{int(word,16)}:{count}' for word,count in track['effective_flags_histogram'].items())
        rows.append('\t'.join(map(str,[track['path'],track['material_count'],track['table_size'],track['table_occupied'],histogram])))
    args.census_output.with_suffix('.tsv').write_text('\n'.join(rows)+'\n',encoding='utf-8')
    print(f'{len(cases)} original-x86 material cases passed; {len(tracks)} tracks / {sum(t["material_count"] for t in tracks)} mt entries / {len(corpus_words)} flag values inventoried')


if __name__=='__main__':
    main()
