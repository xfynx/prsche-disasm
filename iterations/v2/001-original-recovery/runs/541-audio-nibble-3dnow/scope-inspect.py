"""Read-only541 scope/ABI/data ownership against the current542 closure."""
from pathlib import Path
import sys,json,hashlib,importlib.util,re
ROOT=Path(__file__).resolve().parents[5];RUN=Path(__file__).resolve().parent
sys.path[:0]=[str(ROOT/'scripts/research'),str(ROOT/'local/tools/python-unicorn')]
import capstone
import v2_source_dependencies as dep
s=importlib.util.spec_from_file_location('native541',ROOT/'scripts/research/verify-v2-native-batch.py');n=importlib.util.module_from_spec(s);s.loader.exec_module(n)
raw=(ROOT/'local/game/Porsche.exe').read_bytes();sha=hashlib.sha256(raw).hexdigest();assert sha=='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
idx=ROOT/'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d'
indexed={r['entry_va']:r for r in map(json.loads,(idx/'functions.jsonl').read_text().splitlines())}
registry_path=ROOT/'iterations/v2/001-original-recovery/source/recovered/functions.json';registry=json.loads(registry_path.read_text())
build=RUN.parent/'542-texture-cleanup-integration/build-001.json';cfg=json.loads(build.with_name('build-config.json').read_text())
dep.EXTRA_INCLUDE_DIRS=tuple(ROOT/p for p in cfg['source_include_dirs'])
roots=json.loads(build.read_text())['compiled_source_roots'];closure=dep.source_hashes(roots)
overlaps=[]
for row in registry['functions']:
 if row.get('module')=='Porsche.exe' and 'entry_va' in row:
  ranges=indexed.get(row['entry_va'],{}).get('ranges',[[row['entry_va'],row['entry_va']]])
  if any(int(a,16)<0x59a7f9 and int(b,16)>=0x59a730 for a,b in ranges):overlaps.append(row)
assert not overlaps,overlaps
md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32);bodies=[]
for va,size in [(0x59a730,201),(0x597dc0,93),(0x59c610,118),(0x59c9f0,91),(0x59c690,505)]:
 data=n.pe_at(raw,va,size);ins=[dict(va=f'{i.address:08x}',raw=i.bytes.hex(),asm=f'{i.mnemonic} {i.op_str}'.strip()) for i in md.disasm(data,va)]
 bodies.append(dict(va=f'{va:08x}',bytes=size,sha256=hashlib.sha256(data).hexdigest(),index=indexed.get(f'{va:08x}'),instructions=ins))
refs=[]
for line in (idx/'references.jsonl').read_text().splitlines():
 if '0059a730' in line or any(f'"to_va":"{p}"' in line for p in ['005e3b28','005e3b38','006b04c0']):refs.append(json.loads(line))
hits=[]
for p in closure:
 if Path(p).suffix in ['.cpp','.hpp','.h','.inc']:
  for lineno,line in enumerate((ROOT/p).read_text(encoding='utf-8').splitlines(),1):
   if re.search('59a730|5e3b28|5e3b38|6b04c0|6b0800',line,re.I):hits.append(dict(file=p,line=lineno,text=line.strip()))
out=dict(original_sha256=sha,query='0059a730 nibble3DNow fullbody; 597dc0/59c610/59c9f0 selectors; 59c690scratch; 5e3b28/5e3b38/6b04c0 ownership',bodies=bodies,references=refs,ownership=dict(registry_sha256=hashlib.sha256(registry_path.read_bytes()).hexdigest(),source_roots=len(roots),closure_sha256=closure,overlaps=overlaps,hits=hits))
(RUN/'scope-evidence.json').write_text(json.dumps(out,indent=2)+'\n',encoding='utf-8',newline='\n')
print('roots',len(roots),'closure',len(closure),'overlaps',len(overlaps),'references',len(refs))
for f in bodies[:1]:
 print('BODY',f['va'],f['bytes'],f['sha256'])
 for i in f['instructions']:print(i['va'],i['asm'])
print('OWNERSHIP')
for hit in hits:print(hit['file'],hit['line'],hit['text'])
