from pathlib import Path
import hashlib, importlib.util, json, sys
ROOT = Path(__file__).resolve().parents[5]
RUN = Path(__file__).resolve().parent
sys.path[:0] = [str(ROOT/'scripts/research'), str(ROOT/'local/tools/python-unicorn')]
import capstone
import v2_source_dependencies as dep
from v2_shared_manifests import ManifestReader
spec = importlib.util.spec_from_file_location('native', ROOT/'scripts/research/verify-v2-native-batch.py')
native = importlib.util.module_from_spec(spec); spec.loader.exec_module(native)
raw = (ROOT/'local/game/Porsche.exe').read_bytes()
assert hashlib.sha256(raw).hexdigest() == 'ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
base = RUN.parent/'560-audio-stream-routing-integration'
build = json.loads((base/'build-001.json').read_bytes())
cfg = json.loads((base/'build-config.json').read_bytes())
_, effective = ManifestReader(ROOT).resolve(build, 'source', 'crlf-to-lf', 'crlf-to-lf')
dep.EXTRA_INCLUDE_DIRS = tuple(ROOT/p for p in cfg['source_include_dirs'])
closure = dep.source_hashes(build['compiled_source_roots'])
index = ROOT/'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d'
functions = {x['entry_va']:x for x in map(json.loads,(index/'functions.jsonl').read_text().splitlines())}
registry = json.loads((ROOT/'iterations/v2/001-original-recovery/source/recovered/functions.json').read_bytes())['functions']
targets = [(0x4ad8b0,152),(0x4ad950,101)]
md = capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
bodies=[]
for va,size in targets:
    b=native.pe_at(raw,va,size)
    ins=[dict(va=f'{i.address:08x}',raw=i.bytes.hex(),asm=f'{i.mnemonic} {i.op_str}'.strip()) for i in md.disasm(b,va)]
    assert sum(len(bytes.fromhex(i['raw'])) for i in ins)==size
    bodies.append(dict(va=f'{va:08x}',bytes=size,sha256=hashlib.sha256(b).hexdigest(),raw_hex=b.hex(),instructions=ins,index=functions[f'{va:08x}']))
hits=[]
for name in closure:
    if Path(name).suffix.lower() not in ('.cpp','.hpp','.h','.inc'): continue
    for num,line in enumerate((ROOT/name).read_text(encoding='utf-8').splitlines(),1):
        if any(f'{v:08x}' in line.lower() for v,_ in targets): hits.append(dict(file=name,line=num,text=line.strip()))
overlaps=[]
for row in registry:
    if row.get('module')!='Porsche.exe' or 'entry_va' not in row: continue
    ranges=functions.get(row['entry_va'],{}).get('ranges',[[row['entry_va'],row['entry_va']]])
    if any(int(a,16)<v+s and int(b,16)>=v for a,b in ranges for v,s in targets): overlaps.append(row)
result=dict(module_sha256=hashlib.sha256(raw).hexdigest(), baseline=str(base.relative_to(ROOT)),effective_source_pins=len(effective),compiled_roots=len(build['compiled_source_roots']),source_header_closure=len(closure),closure_hashes=closure,bodies=bodies,ownership_hits=hits,registry_overlaps=overlaps)
(RUN/'scope-evidence.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8',newline='\n')
for body in bodies:
    print(body['va'],body['sha256'])
    for i in body['instructions']: print(i['va'],i['asm'])
print('pins/roots/closure',len(effective),len(build['compiled_source_roots']),len(closure),'hits',hits,'overlaps',overlaps)
