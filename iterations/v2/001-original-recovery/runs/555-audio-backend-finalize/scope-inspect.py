"""Read-only original/index/current ownership census for the pan-table packet."""
import hashlib
import importlib.util
import json
import struct
import sys
from pathlib import Path

ROOT=Path(__file__).resolve().parents[5]
RUN=Path(__file__).resolve().parent
sys.path[:0]=[str(ROOT/'scripts/research'),str(ROOT/'local/tools/python-unicorn')]
import capstone
import v2_source_dependencies as dep
from v2_shared_manifests import ManifestReader

spec=importlib.util.spec_from_file_location('native555',ROOT/'scripts/research/verify-v2-native-batch.py')
n=importlib.util.module_from_spec(spec)
spec.loader.exec_module(n)
raw=(ROOT/'local/game/Porsche.exe').read_bytes()
sha=lambda b:hashlib.sha256(b).hexdigest()
assert sha(raw)=='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
baseline=RUN.parent/'551-diagnostic-codec-integration/build-001.json'
build=json.loads(baseline.read_bytes())
cfg=json.loads(baseline.with_name('build-config.json').read_bytes())
_,effective=ManifestReader(ROOT).resolve(build,'source','crlf-to-lf','crlf-to-lf')
dep.EXTRA_INCLUDE_DIRS=tuple(ROOT/p for p in cfg['source_include_dirs'])
closure=dep.source_hashes(build['compiled_source_roots'])
roots=list(build['compiled_source_roots'])
for packet in ['552-audio-adpcm-kernel','553-audio-resampler-kernel']:
    ready=json.loads((RUN.parent/packet/'ready.json').read_bytes())
    roots+=ready['sources_to_add']
closure_current=dep.source_hashes(roots)
index=ROOT/'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d'
functions={f['entry_va']:f for f in map(json.loads,(index/'functions.jsonl').read_text().splitlines())}
sizes={0x58e0e0:424,0x58e0b0:36,0x58e290:51,0x565c70:90,0x590250:56,0x565cd0:137}
md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
bodies=[]
for va,size in sizes.items():
    b=n.pe_at(raw,va,size)
    instructions=[dict(va=f'{i.address:08x}',raw=i.bytes.hex(),asm=f'{i.mnemonic} {i.op_str}'.strip()) for i in md.disasm(b,va)]
    assert sum(len(bytes.fromhex(i['raw'])) for i in instructions)==size
    bodies.append(dict(va=f'{va:08x}',bytes=size,sha256=sha(b),raw_hex=b.hex(),instructions=instructions,index=functions.get(f'{va:08x}')))
registry=json.loads((ROOT/'iterations/v2/001-original-recovery/source/recovered/functions.json').read_bytes())
selected={0x58e0e0:424,0x58e0b0:36,0x58e290:51}
collisions=[]
for row in registry['functions']:
    if row.get('module')!='Porsche.exe' or 'entry_va' not in row:continue
    ranges=functions.get(row['entry_va'],{}).get('ranges',[[row['entry_va'],row['entry_va']]])
    for va,size in selected.items():
        if any(int(a,16)<va+size and int(b,16)>=va for a,b in ranges):collisions.append(row)
targets={f'{v:08x}' for v in sizes}|{'006b1820','006b181f','006b1821','006b48dc','006b48ec'}
hits=[]
for name in closure_current:
    if Path(name).suffix not in ['.cpp','.hpp','.h','.inc']:continue
    for number,line in enumerate((ROOT/name).read_text(encoding='utf-8-sig').splitlines(),1):
        if any(t[2:] in line.lower() for t in targets):hits.append(dict(file=name,line=number,text=line.strip()))
# Prove the table lies wholly in the original PE zero-fill tail, not invented data.
pe=struct.unpack_from('<I',raw,0x3c)[0]
base=struct.unpack_from('<I',raw,pe+52)[0]
count=struct.unpack_from('<H',raw,pe+6)[0]
optional=struct.unpack_from('<H',raw,pe+20)[0]
table=None
for i in range(count):
    off=pe+24+optional+i*40
    virtual_size,rva,raw_size,raw_pointer=struct.unpack_from('<IIII',raw,off+8)
    if rva<=0x6b181f-base and 0x6b1820-base+1024<=rva+virtual_size:
        assert 0x6b181f-base>=rva+raw_size
        table=dict(va='006b181f',bytes=1025,table_va='006b1820',table_bytes=1024,initial='PE-loader-zero',section=raw[off:off+8].rstrip(b'\0').decode(),section_rva=f'{rva:08x}',section_virtual_bytes=virtual_size,section_raw_bytes=raw_size)
assert table
e=dict(kind='scope-only-before-root-approval',query='0058e0e0 backend_finalize directcaller565720,leaf58e0b0,consumer58e290;separate565c70 control graph',
       module_sha256=sha(raw),baseline=str(baseline.relative_to(ROOT)),effective_source_pins=len(effective),compiled_roots=len(build['compiled_source_roots']),
       source_header_closure=len(closure),closure_sha256=closure,current_roots=len(roots),current_closure=len(closure_current),current_closure_sha256=closure_current,
       registry_sha256=sha((ROOT/'iterations/v2/001-original-recovery/source/recovered/functions.json').read_bytes()),new_body_collisions=collisions,ownership_hits=hits,
       bodies=bodies,new_table=table,calls=[json.loads(l) for l in (index/'calls.jsonl').read_text().splitlines() if any(t in l for t in targets)],
       references=[json.loads(l) for l in (index/'references.jsonl').read_text().splitlines() if any(t in l for t in targets)])
(RUN/'scope-evidence.json').write_text(json.dumps(e,indent=2)+'\n',encoding='utf-8',newline='\n')
print('551 baseline',len(effective),'pins',len(build['compiled_source_roots']),'roots',len(closure),'closure; +552/553',len(roots),len(closure_current),'collision',len(collisions))
print(json.dumps(hits,indent=2))
print(json.dumps(table))
