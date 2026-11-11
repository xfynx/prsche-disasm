"""Read-only raw stateful stream creator/lifecycle and ownership census."""
from pathlib import Path
import hashlib,importlib.util,json,re,struct,sys
ROOT=Path(__file__).resolve().parents[5];RUN=Path(__file__).resolve().parent
sys.path[:0]=[str(ROOT/'scripts/research'),str(ROOT/'local/tools/python-unicorn')]
import capstone
import v2_source_dependencies as dep
from v2_shared_manifests import ManifestReader
spec=importlib.util.spec_from_file_location('n561scope',ROOT/'scripts/research/verify-v2-native-batch.py');n=importlib.util.module_from_spec(spec);spec.loader.exec_module(n)
raw=(ROOT/'local/game/Porsche.exe').read_bytes();sha=lambda b:hashlib.sha256(b).hexdigest();assert sha(raw)=='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
baseline=RUN.parent/'557-audio-lifecycle-integration/build-001.json';build=json.loads(baseline.read_bytes());cfg=json.loads(baseline.with_name('build-config.json').read_bytes());_,effective=ManifestReader(ROOT).resolve(build,'source','crlf-to-lf','crlf-to-lf')
roots=list(build['compiled_source_roots']);ready559=json.loads((RUN.parent/'559-audio-stream-service/ready.json').read_bytes());roots+=ready559['sources_to_add'];dep.EXTRA_INCLUDE_DIRS=tuple([ROOT/p for p in cfg['source_include_dirs']]+[RUN.parent/'559-audio-stream-service']);closure=dep.source_hashes(roots)
idx=ROOT/'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d';funcs={r['entry_va']:r for r in map(json.loads,(idx/'functions.jsonl').read_text().splitlines())}
selected={0x5673d0:384,0x567690:135,0x567740:202,0x566d60:24,0x5673b0:25,0x566d40:22,0x58ff50:31,0x58ff70:86}
sizes={**selected,0x566e10:36,0x566e40:95,0x567270:314,0x56aff0:564,0x56c840:80,0x5912e0:58,0x56c420:280,0x56b3b0:175,0x561200:135,0x5617d0:27}
for va in [0x561200,0x5617d0]:sizes[va]=funcs[f'{va:08x}']['body_bytes']
md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32);bodies=[]
for va,size in sizes.items():
 b=n.pe_at(raw,va,size);instructions=[dict(va=f'{i.address:08x}',raw=i.bytes.hex(),asm=f'{i.mnemonic} {i.op_str}'.strip()) for i in md.disasm(b,va)];assert sum(len(bytes.fromhex(i['raw'])) for i in instructions)==size
 bodies.append(dict(va=f'{va:08x}',bytes=size,sha256=sha(b),raw_hex=b.hex(),instructions=instructions,index=funcs.get(f'{va:08x}')))
registry_path=ROOT/'iterations/v2/001-original-recovery/source/recovered/functions.json';registry=json.loads(registry_path.read_bytes());collisions=[]
for row in registry['functions']:
 if row.get('module')!='Porsche.exe' or 'entry_va' not in row:continue
 ranges=funcs.get(row['entry_va'],{}).get('ranges',[[row['entry_va'],row['entry_va']]])
 if any(int(a,16)<v+selected[v] and int(b,16)>=v for a,b in ranges for v in selected):collisions.append(row)
targets={f'{v:06x}' for v in sizes}|{'6b7740','6b7780','6b499c','6b49a1','6b49c8','6b49fc'};hits=[];neighbors=[]
for name in closure:
 if Path(name).suffix not in ['.cpp','.hpp','.h','.inc']:continue
 for number,line in enumerate((ROOT/name).read_text(encoding='utf-8-sig').splitlines(),1):
  if any(t in line.lower() for t in targets):hits.append(dict(file=name,line=number,text=line.strip()))
  if any(abs(int(m,16)-0x6b7740)<0x200 for m in re.findall(r'(?<![0-9a-fA-F])[0-9a-fA-F]{8}(?![0-9a-fA-F])',line)):neighbors.append(dict(file=name,line=number,text=line.strip()))
pe=struct.unpack_from('<I',raw,0x3c)[0];base=struct.unpack_from('<I',raw,pe+52)[0];sections=struct.unpack_from('<H',raw,pe+6)[0];optional=struct.unpack_from('<H',raw,pe+20)[0];data=None
for i in range(sections):
 at=pe+24+optional+i*40;virtual_size,rva,raw_size,raw_at=struct.unpack_from('<IIII',raw,at+8);start=0x6b7740-base-rva
 if 0<=start and start+80<=virtual_size:
  assert start>=raw_size;data=dict(va='006b7740',bytes=80,slot_bytes=64,map_va='006b7780',map_bytes=16,initial_hex='00'*80,section=raw[at:at+8].rstrip(b'\0').decode(),section_rva=f'{rva:08x}',virtual_bytes=virtual_size,raw_bytes=raw_size,offset=start,proof='Entire exact64Bslot+16Bmap extent lies in PE virtual loader-zero tail.')
assert data
result=dict(kind='scope-before-implementation',module_sha256=sha(raw),baseline=str(baseline.relative_to(ROOT)),baseline_effective_pins=len(effective),baseline_roots=len(build['compiled_source_roots']),current_with_frozen559_roots=len(roots),source_header_closure=len(closure),closure_sha256=closure,registry_sha256=sha(registry_path.read_bytes()),new_body_collisions=collisions,ownership_hits=hits,neighboring_literal_owners=neighbors,new_data=data,bodies=bodies,calls=[json.loads(l) for l in (idx/'calls.jsonl').read_text().splitlines() if any(f'00{t}' in l for t in targets)],state_boundaries=['Creator/count loop addresses006b7740..006b7780 prove16slots/64B;lookup explicitly accepts signed0..15 only','Canonical508 construct returns0..15 when successful;creator maps this index to selectedouter slot0..15 through16Bmap','6b499c=canonicaldevice+dc,6b49a1=+e1,6b49c8=+108,6b49fc=+13c;classsymbol requires16Bbacking prefix. No newregistration/device owner','Descriptorall28callerbytes copiedforward without zeroingopaque22/23;doesnotpromote556PARTIAL'])
(RUN/'scope-evidence.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8',newline='\n')
print(json.dumps({k:result[k] for k in ['baseline_effective_pins','baseline_roots','current_with_frozen559_roots','source_header_closure','new_body_collisions','new_data']}));print('ownership',len(hits),'neighbor-literals',len(neighbors));print(json.dumps(neighbors[:24],indent=2))
