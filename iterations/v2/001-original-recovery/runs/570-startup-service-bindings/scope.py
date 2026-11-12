from pathlib import Path
import hashlib, importlib.util, json, re, struct, sys
root=Path(__file__).resolve().parents[5]; run=Path(__file__).resolve().parent
sys.path[:0]=[str(root/'scripts/research'),str(root/'local/tools/python-unicorn')]
import capstone
import v2_source_dependencies as dep
from v2_shared_manifests import ManifestReader
spec=importlib.util.spec_from_file_location('native',root/'scripts/research/verify-v2-native-batch.py')
n=importlib.util.module_from_spec(spec);spec.loader.exec_module(n)
raw=(root/'local/game/Porsche.exe').read_bytes(); sha=lambda b:hashlib.sha256(b).hexdigest()
assert sha(raw)=='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
base=root/'iterations/v2/001-original-recovery/runs/567-audio-codec-control-integration'
build=json.loads((base/'build-001.json').read_bytes()); cfg=json.loads((base/'build-config.json').read_bytes())
_,pins=ManifestReader(root).resolve(build,'source','crlf-to-lf','crlf-to-lf')
dep.EXTRA_INCLUDE_DIRS=tuple(root/p for p in cfg['source_include_dirs'])
closure=dep.source_hashes(build['compiled_source_roots'])
index=root/'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d'
functions={x['entry_va']:x for x in map(json.loads,(index/'functions.jsonl').read_text().splitlines())}
registry=json.loads((root/'iterations/v2/001-original-recovery/source/recovered/functions.json').read_bytes())['functions']
targets=[(0x536080,27),(0x534540,12)]
md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32); bodies=[]
for va,size in targets:
    blob=n.pe_at(raw,va,size); ins=[{'va':f'{i.address:08x}','raw':i.bytes.hex(),'asm':f'{i.mnemonic} {i.op_str}'.strip()} for i in md.disasm(blob,va)]
    assert sum(len(bytes.fromhex(x['raw'])) for x in ins)==size
    bodies.append({'va':f'{va:08x}','bytes':size,'sha256':sha(blob),'raw_hex':blob.hex(),'instructions':ins,'index':functions.get(f'{va:08x}')})
hits=[]
for name in closure:
    if Path(name).suffix.lower() not in ('.cpp','.hpp','.h','.inc'): continue
    for line,text in enumerate((root/name).read_text(encoding='utf-8').splitlines(),1):
        if any(f'{v:08x}' in text.lower() for v,_ in targets): hits.append({'file':name,'line':line,'text':text.strip()})
overlaps=[]
for row in registry:
    if row.get('module')!='Porsche.exe' or 'entry_va' not in row: continue
    ranges=functions.get(row['entry_va'],{}).get('ranges',[[row['entry_va'],row['entry_va']]])
    if any(int(a,16)<v+s and int(b,16)>=v for a,b in ranges for v,s in targets): overlaps.append(row)
result={'module_sha256':sha(raw),'baseline':'Run567 attempt 001','pins':len(pins),'roots':len(build['compiled_source_roots']),'closure':len(closure),'closure_hashes':closure,'hits':hits,'overlaps':overlaps,'bodies':bodies}
near=[]
for name in closure:
    if Path(name).suffix.lower() not in ('.cpp','.hpp','.h','.inc'):continue
    for line,text in enumerate((root/name).read_text(encoding='utf-8').splitlines(),1):
        if any(0x69dd10<=int(x,16)<0x69dd30 or 0x5de650<=int(x,16)<0x5de6c0 for x in re.findall(r'(?<![0-9a-fA-F])[0-9a-fA-F]{8}(?![0-9a-fA-F])',text)):
            near.append({'file':name,'line':line,'text':text.strip()})
pe=struct.unpack_from('<I',raw,0x3c)[0];count=struct.unpack_from('<H',raw,pe+6)[0];opt=struct.unpack_from('<H',raw,pe+20)[0];base=struct.unpack_from('<I',raw,pe+52)[0]
for i in range(count):
    at=pe+24+opt+i*40;name=raw[at:at+8].rstrip(b'\0').decode();vs,rva,rs,ro=struct.unpack_from('<IIII',raw,at+8);offset=0x69dd1e-base-rva
    if 0<=offset<vs:
        assert offset>=rs
        result['new_byte']={'va':'0069dd1e','section':name,'offset':offset,'virtual_size':vs,'raw_size':rs,'initial':0,'proof':'PE virtual tail beyond file-backed bytes'}
assert 'new_byte' in result
result['nearby_owner_candidates']=near
result['actual_callers']=[]
for va,size in [(0x4b67b0,13),(0x4dd648,16)]:
    blob=n.pe_at(raw,va,size);result['actual_callers'].append({'va':f'{va:08x}','bytes':size,'sha256':sha(blob),'raw_hex':blob.hex(),'instructions':[{'va':f'{x.address:08x}','asm':f'{x.mnemonic} {x.op_str}'.strip()} for x in md.disasm(blob,va)]})
(run/'scope-evidence.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8',newline='\n')
print('pins/roots/closure',len(pins),len(build['compiled_source_roots']),len(closure),'hits',len(hits),'overlaps',len(overlaps))
for x in bodies: print(x['va'],x['bytes'],x['sha256'], 'indexed',x['index'] is not None)
