"""Read-only original application audio lifecycle and accepted ownership census."""
from pathlib import Path
import hashlib,importlib.util,json,re,struct,sys
ROOT=Path(__file__).resolve().parents[5];RUN=Path(__file__).resolve().parent
sys.path[:0]=[str(ROOT/'scripts/research'),str(ROOT/'local/tools/python-unicorn')]
import capstone
import v2_source_dependencies as dep
from v2_shared_manifests import ManifestReader
spec=importlib.util.spec_from_file_location('n556scope',ROOT/'scripts/research/verify-v2-native-batch.py');n=importlib.util.module_from_spec(spec);spec.loader.exec_module(n)
raw=(ROOT/'local/game/Porsche.exe').read_bytes();sha=lambda b:hashlib.sha256(b).hexdigest()
assert sha(raw)=='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
baseline=RUN.parent/'554-audio-kernel-integration/build-001.json';build=json.loads(baseline.read_bytes());cfg=json.loads(baseline.with_name('build-config.json').read_bytes())
_,effective=ManifestReader(ROOT).resolve(build,'source','crlf-to-lf','crlf-to-lf');dep.EXTRA_INCLUDE_DIRS=tuple(ROOT/p for p in cfg['source_include_dirs']);closure=dep.source_hashes(build['compiled_source_roots'])
idx=ROOT/'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d';functions={r['entry_va']:r for r in map(json.loads,(idx/'functions.jsonl').read_text().splitlines())}
registry=json.loads((ROOT/'iterations/v2/001-original-recovery/source/recovered/functions.json').read_bytes())
sizes={0x4ae010:228,0x4ae2b0:88,0x4ae310:163,0x4a66b0:398,0x4a6840:279,0x4a6960:153,0x4ad9c0:1114,0x567690:135}
for va in [0x5678c0,0x561960,0x567660,0x5673d0,0x5365e0,0x5366a0]:sizes[va]=functions[f'{va:08x}']['body_bytes']
sizes[0x4a6960]=functions['004a6960']['body_bytes']
md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32);bodies=[]
for va,size in sizes.items():
 b=n.pe_at(raw,va,size);instructions=[dict(va=f'{i.address:08x}',raw=i.bytes.hex(),asm=f'{i.mnemonic} {i.op_str}'.strip()) for i in md.disasm(b,va)]
 assert sum(len(bytes.fromhex(i['raw'])) for i in instructions)==size
 bodies.append(dict(va=f'{va:08x}',bytes=size,sha256=sha(b),raw_hex=b.hex(),instructions=instructions,index=functions.get(f'{va:08x}')))
targets=['4ae010','4ae2b0','4ae310','4ad9c0','567690','567660','5678c0','561960','655d30','656ab4','5e8bfc']
hits=[];near=[]
for name in closure:
 if Path(name).suffix not in ['.cpp','.hpp','.h','.inc']:continue
 for number,line in enumerate((ROOT/name).read_text(encoding='utf-8').splitlines(),1):
  if any(t in line.lower() for t in targets):hits.append(dict(file=name,line=number,text=line.strip()))
  if any(abs(int(m,16)-0x655d30)<0x80 or abs(int(m,16)-0x656ab4)<0x80 for m in re.findall(r'(?<![0-9a-fA-F])[0-9a-fA-F]{8}(?![0-9a-fA-F])',line)):near.append(dict(file=name,line=number,text=line.strip()))
collisions=[]
for row in registry['functions']:
 if row.get('module')!='Porsche.exe' or 'entry_va' not in row:continue
 ranges=functions.get(row['entry_va'],{}).get('ranges',[[row['entry_va'],row['entry_va']]])
 if any(int(a,16)<v+sizes[v] and int(b,16)>=v for a,b in ranges for v in [0x4ae010,0x4ae2b0,0x4ae310]):collisions.append(row)
result=dict(kind='scoping-only-no-production-implementation',module_sha256=sha(raw),baseline=str(baseline.relative_to(ROOT)),effective_source_pins=len(effective),compiled_roots=len(build['compiled_source_roots']),source_header_closure=len(closure),closure_sha256=closure,new_body_collisions=collisions,ownership_hits=hits,neighboring_owner_candidates=near,bodies=bodies,calls=[json.loads(l) for l in (idx/'calls.jsonl').read_text().splitlines() if any(f'00{t}' in l for t in targets[:8])])
pe=struct.unpack_from('<I',raw,0x3c)[0];num=struct.unpack_from('<H',raw,pe+6)[0];optional=struct.unpack_from('<H',raw,pe+20)[0];base=struct.unpack_from('<I',raw,pe+24+28)[0]
for section in range(num):
 at=pe+24+optional+section*40;name=raw[at:at+8].rstrip(b'\0').decode();virtual_size,rva,raw_size,raw_at=struct.unpack_from('<IIII',raw,at+8);offset=0x655d30-base-rva
 if 0<=offset and offset+4<=virtual_size:
  assert offset>=raw_size
  result['new_data']=dict(va='00655d30',bytes=4,initial_hex='00000000',section=name,section_rva=f'{rva:08x}',virtual_size=virtual_size,raw_size=raw_size,offset=offset,proof='Complete cell lies in PE virtual section beyond file-backed prefix; Windows loader zero-fills. No exact owner; nearest literal declared spans exclude it.')
assert 'new_data' in result
result['partial_entry_004ae010']=dict(opaque_descriptor_offsets=['0x16','0x17'],initializer='00561960 writes words+0c/+0e/+10/+12/+14 and+18/+1a, leaving+16/+17 unwritten',consumer='00567660 forwards descriptor to005673d0;005674f5..00567504 copies7DWORDs tostream+dc including both opaque bytes',boundary='Controlled endpoint proof masks only these original unwritten two bytes. Physical downstream read exists; no padding claim or real child/unwritten semantic acceptance. Entry remains PARTIAL.')
(RUN/'scope-evidence.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8',newline='\n')
print(json.dumps({k:result[k] for k in ['effective_source_pins','compiled_roots','source_header_closure','new_body_collisions']}));print(json.dumps(hits,indent=2));print('neighboring candidates',len(near))
callback=next(b for b in bodies if b['va']=='004ad9c0')
supplement=dict(kind='raw-callback-identity-index-supplement-not-algorithm-acceptance',module_sha256=sha(raw),body=callback,returns=[r['va'] for r in callback['instructions'] if r['asm']=='ret'],next_entry='004ade20',padding_hex=n.pe_at(raw,0x4ade1a,6).hex(),contract='Address is passed as canonical TimedCallback(cdecl2U/U) to register/remove. Complete original callback returnsEAX0 on both exits; actual algorithm remains unresolved, never executed by556.')
(RUN/'callback-index-supplement.json').write_text(json.dumps(supplement,indent=2)+'\n',encoding='utf-8',newline='\n')
