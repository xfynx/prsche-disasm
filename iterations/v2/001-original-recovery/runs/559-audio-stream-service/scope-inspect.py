"""Original descriptor/size/service routing ownership census; no implementation."""
from pathlib import Path
import hashlib,importlib.util,json,struct,sys
ROOT=Path(__file__).resolve().parents[5];RUN=Path(__file__).resolve().parent
sys.path[:0]=[str(ROOT/'scripts/research'),str(ROOT/'local/tools/python-unicorn')]
import capstone
import v2_source_dependencies as dep
from v2_shared_manifests import ManifestReader
spec=importlib.util.spec_from_file_location('n559scope',ROOT/'scripts/research/verify-v2-native-batch.py');n=importlib.util.module_from_spec(spec);spec.loader.exec_module(n)
raw=(ROOT/'local/game/Porsche.exe').read_bytes();sha=lambda b:hashlib.sha256(b).hexdigest();assert sha(raw)=='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
baseline=RUN.parent/'557-audio-lifecycle-integration/build-001.json';build=json.loads(baseline.read_bytes());cfg=json.loads(baseline.with_name('build-config.json').read_bytes())
_,effective=ManifestReader(ROOT).resolve(build,'source','crlf-to-lf','crlf-to-lf');dep.EXTRA_INCLUDE_DIRS=tuple(ROOT/p for p in cfg['source_include_dirs']);closure=dep.source_hashes(build['compiled_source_roots'])
idx=ROOT/'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d';funcs={r['entry_va']:r for r in map(json.loads,(idx/'functions.jsonl').read_text().splitlines())}
sizes={0x561960:80,0x5611d0:12,0x5611e0:25,0x5678a0:31,0x5678c0:38,0x56afc0:34,0x567660:38,0x5673d0:384,0x567690:135,0x566d60:24,0x5673b0:25,0x567740:202,0x567270:314,0x5612a0:791,0x567170:125,0x5671f0:119}
md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32);bodies=[]
for va,size in sizes.items():
 b=n.pe_at(raw,va,size);instructions=[dict(va=f'{i.address:08x}',raw=i.bytes.hex(),asm=f'{i.mnemonic} {i.op_str}'.strip()) for i in md.disasm(b,va)]
 assert sum(len(bytes.fromhex(i['raw'])) for i in instructions)==size
 bodies.append(dict(va=f'{va:08x}',bytes=size,sha256=sha(b),raw_hex=b.hex(),instructions=instructions,index=funcs.get(f'{va:08x}')))
new=set(list(sizes)[:7]);registry_path=ROOT/'iterations/v2/001-original-recovery/source/recovered/functions.json';registry=json.loads(registry_path.read_bytes());collisions=[]
for row in registry['functions']:
 if row.get('module')!='Porsche.exe' or 'entry_va' not in row:continue
 ranges=funcs.get(row['entry_va'],{}).get('ranges',[[row['entry_va'],row['entry_va']]])
 if any(int(a,16)<v+sizes[v] and int(b,16)>=v for a,b in ranges for v in new):collisions.append(row)
targets={f'{v:06x}' for v in sizes}|{'589790','6b7740','6b7780','6b49fc'};hits=[]
for name in closure:
 if Path(name).suffix not in ['.cpp','.hpp','.h','.inc']:continue
 for number,line in enumerate((ROOT/name).read_text(encoding='utf-8').splitlines(),1):
  if any(t in line.lower() for t in targets):hits.append(dict(file=name,line=number,text=line.strip()))
# Navigation only: direct get-stream consumers and stream-service slab accesses
# to the copied descriptor's two known-opaque offsets(+f2/+f3 in the stream).
calls=list(map(json.loads,(idx/'calls.jsonl').read_text().splitlines()));consumers={int(r['from_function'],16) for r in calls if r.get('to_va')=='00566d60' and r.get('from_function')};field_reads=[]
for va in consumers:
 row=funcs[f'{va:08x}'];b=n.pe_at(raw,va,row['body_bytes'])
 for ins in md.disasm(b,va):
  if any(term in ins.op_str for term in ['0xdc','0xf2','0xf3','0xf0','0xf4','0xe0','0xe4','0xe8','0xec']):field_reads.append(dict(function=f'{va:08x}',va=f'{ins.address:08x}',asm=f'{ins.mnemonic} {ins.op_str}',raw=ins.bytes.hex()))
result=dict(kind='scope-only-before-production',module_sha256=sha(raw),baseline=str(baseline.relative_to(ROOT)),effective_source_pins=len(effective),compiled_roots=len(build['compiled_source_roots']),source_header_closure=len(closure),closure_sha256=closure,registry_sha256=sha(registry_path.read_bytes()),new_body_collisions=collisions,ownership_hits=hits,bodies=bodies,calls=[r for r in calls if any(f'00{t}' in json.dumps(r) for t in targets)],descriptor_defined_offsets=[i for i in range(28) if i not in [0x16,0x17]],descriptor_unwritten_offsets=['0x16','0x17'],descriptor_physical_copy='005674f5..00567504 copies7DWORDs tostream+DC; no e010 partial upgrade',direct_consumer_navigation=field_reads,semantic_boundary='Direct get-stream callers only. This navigation does not prove absence of further semantic reads or permit upgrading556e010.')
descriptor_consumer=next(b for b in bodies if b['va']=='005612a0')
result['descriptor_consumer_projection']=dict(path=['005673d0 copies descriptor tostream+DC','00567270+0x84 passesstream+DC as005612a0 arg4','005612a0 loadsarg4 intoEDI at00561382'],reads=[i for i in descriptor_consumer['instructions'] if int(i['va'],16)>=0x561382 and '[edi' in i['asm']],finding='This791Bconsumer reads known fields+07/+08/+09/+0a/+0b/+0c/+0e/+12/+14/+18; no direct read of opaque+16/+17 here. Other consumer closure remains open; no padding claim or556partial upgrade.')
(RUN/'scope-evidence.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8',newline='\n');print(json.dumps({k:result[k] for k in ['effective_source_pins','compiled_roots','source_header_closure','new_body_collisions']}));print(json.dumps(hits,indent=2));print(json.dumps(field_reads,indent=2))
