"""Original resampler/LPC kernel census against the accepted551 full closure."""
from pathlib import Path
import hashlib, importlib.util, json, re, struct, sys
ROOT=Path(__file__).resolve().parents[5]; RUN=Path(__file__).resolve().parent
sys.path[:0]=[str(ROOT/'scripts/research'),str(ROOT/'local/tools/python-unicorn')]
import capstone
import v2_source_dependencies as dep
from v2_shared_manifests import ManifestReader
spec=importlib.util.spec_from_file_location('native553',ROOT/'scripts/research/verify-v2-native-batch.py')
n=importlib.util.module_from_spec(spec);spec.loader.exec_module(n)
raw=(ROOT/'local/game/Porsche.exe').read_bytes();sha=lambda b:hashlib.sha256(b).hexdigest()
assert sha(raw)=='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
baseline=RUN.parent/'551-diagnostic-codec-integration/build-001.json'
build=json.loads(baseline.read_text());cfg=json.loads(baseline.with_name('build-config.json').read_text())
_,effective=ManifestReader(ROOT).resolve(build,'source','crlf-to-lf','crlf-to-lf')
dep.EXTRA_INCLUDE_DIRS=tuple(ROOT/p for p in cfg['source_include_dirs'])
closure=dep.source_hashes(build['compiled_source_roots'])
idx=ROOT/'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d'
funcs={f['entry_va']:f for f in map(json.loads,(idx/'functions.jsonl').read_text().splitlines())}
registry=json.loads((ROOT/'iterations/v2/001-original-recovery/source/recovered/functions.json').read_text())
data={0x5c17d0:8,0x5b4ba8:8,0x5b24c0:8,0x5b27b8:8,0x5c17c8:8,0x5c17c0:8,0x5c17b8:8,0x5b2750:8,0x5b4690:8,0x5c1698:4}
sizes={0x597810:678,0x5a17c9:34,0x5a0f98:39,0x59b690:404,0x59b830:100}
md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
bodies=[]
for va,size in sizes.items():
 b=n.pe_at(raw,va,size);ins=[dict(va=f'{i.address:08x}',raw=i.bytes.hex(),asm=f'{i.mnemonic} {i.op_str}'.strip()) for i in md.disasm(b,va)]
 assert sum(len(bytes.fromhex(i['raw'])) for i in ins)==size
 bodies.append(dict(va=f'{va:08x}',bytes=size,sha256=sha(b),raw_hex=b.hex(),instructions=ins,index=funcs.get(f'{va:08x}')))
targets={f'{v:08x}' for v in sizes}|{f'{v:08x}' for v in data}
hits=[]
for name in closure:
 if Path(name).suffix not in ['.cpp','.hpp','.h','.inc']:continue
 for number,line in enumerate((ROOT/name).read_text(encoding='utf-8').splitlines(),1):
  if any(t[2:] in line.lower() for t in targets):hits.append(dict(file=name,line=number,text=line.strip()))
collisions=[]
for row in registry['functions']:
 if row.get('module')!='Porsche.exe' or 'entry_va' not in row:continue
 ranges=funcs.get(row['entry_va'],{}).get('ranges',[[row['entry_va'],row['entry_va']]])
 if any(int(a,16)<0x597810+678 and int(b,16)>=0x597810 for a,b in ranges):collisions.append(row)
result=dict(kind='original-census-not-semantic-acceptance',module_sha256=sha(raw),baseline=str(baseline.relative_to(ROOT)),effective_source_pins=len(effective),compiled_roots=len(build['compiled_source_roots']),source_header_closure=len(closure),closure_sha256=closure,new_body_collisions=collisions,ownership_hits=hits,bodies=bodies,data=[dict(va=f'{v:08x}',bytes=s,raw_hex=n.pe_at(raw,v,s).hex(),value=struct.unpack('<d' if s==8 else '<f',n.pe_at(raw,v,s))[0]) for v,s in data.items()],calls=[json.loads(l) for l in (idx/'calls.jsonl').read_text().splitlines() if any(t in l for t in ['00597810','0059b690','0059b830','005a17c9','005a0f98'])])
(RUN/'scope-evidence.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8',newline='\n')
print(json.dumps({k:result[k] for k in ['effective_source_pins','compiled_roots','source_header_closure','new_body_collisions']}));print(json.dumps(result['data'],indent=2));print(json.dumps(hits,indent=2))
