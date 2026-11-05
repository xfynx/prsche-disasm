"""Batch538 bounded original evidence and ownership; no original writes."""
from pathlib import Path
import sys,json,hashlib,importlib.util,re
ROOT=Path(__file__).resolve().parents[5]
RUN=Path(__file__).resolve().parent
sys.path=[p for p in sys.path if Path(p or '.').resolve()!=RUN]
sys.path.insert(0,str(ROOT/'scripts/research'))
import capstone,v2_source_dependencies as dep
s=importlib.util.spec_from_file_location('native538',ROOT/'scripts/research/verify-v2-native-batch.py');n=importlib.util.module_from_spec(s);s.loader.exec_module(n)
raw=(ROOT/'local/game/Porsche.exe').read_bytes();sha=hashlib.sha256(raw).hexdigest();assert sha=='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
idx=ROOT/'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d'
indexed={r['entry_va']:r for r in map(json.loads,(idx/'functions.jsonl').read_text().splitlines())}
registry=json.loads((ROOT/'iterations/v2/001-original-recovery/source/recovered/functions.json').read_text())
build=RUN.parent/'535-resource-processor-integration/build-003.json';cfg=json.loads(build.with_name('build-config.json').read_text())
dep.EXTRA_INCLUDE_DIRS=tuple(ROOT/p for p in cfg['source_include_dirs'])
closure=dep.source_hashes(json.loads(build.read_text())['compiled_source_roots'])
overlaps=[]
for row in registry['functions']:
 if row.get('module')=='Porsche.exe' and 'entry_va' in row:
  ranges=indexed.get(row['entry_va'],{}).get('ranges',[[row['entry_va'],row['entry_va']]])
  if any(int(a,16)<0x59c889 and int(b,16)>=0x59c690 for a,b in ranges):overlaps.append(row)
assert not overlaps,overlaps
md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
bodies=[]
for va,size in [(0x59c690,505),(0x59c890,344),(0x59c9f0,91),(0x59a5a0,185),(0x59a660,200)]:
 data=n.pe_at(raw,va,size);ins=[dict(va=f'{i.address:08x}',raw=i.bytes.hex(),asm=f'{i.mnemonic} {i.op_str}'.strip()) for i in md.disasm(data,va)]
 bodies.append(dict(va=f'{va:08x}',bytes=size,sha256=hashlib.sha256(data).hexdigest(),index=indexed.get(f'{va:08x}'),instructions=ins))
refs=[]
for line in (idx/'references.jsonl').read_text().splitlines():
 if '0059c690' in line or '0059c890' in line:refs.append(json.loads(line))
hits=[]
for p in closure:
 if Path(p).suffix in ['.cpp','.hpp','.h','.inc']:
  for lineno,line in enumerate((ROOT/p).read_text(encoding='utf-8').splitlines(),1):
   if re.search('59c690|59c890|59a5a0|59a660|59c9f0',line,re.I):hits.append(dict(file=p,line=lineno,text=line.strip()))
out=dict(original_sha256=sha,query='0059c690 continuation; caller0059c890; ctor0059c9f0; slot38 decoder children',bodies=bodies,references=refs,ownership=dict(registry_sha256=hashlib.sha256((ROOT/'iterations/v2/001-original-recovery/source/recovered/functions.json').read_bytes()).hexdigest(),source_roots=len(json.loads(build.read_text())['compiled_source_roots']),closure_sha256=closure,overlaps=overlaps,hits=hits))
(RUN/'scope-evidence.json').write_text(json.dumps(out,indent=2)+'\n',encoding='utf-8',newline='\n')
print('roots',out['ownership']['source_roots'],'closure',len(closure),'overlaps',len(overlaps),'references',refs)
for f in bodies[:1]:
 print('BODY',f['va'],f['bytes'],f['sha256'])
 for i in f['instructions']:print(i['va'],i['asm'])
