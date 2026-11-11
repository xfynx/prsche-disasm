"""Original periodic-control transport census and canonical owner boundaries."""
import hashlib
import importlib.util
import json
import sys
from pathlib import Path

ROOT=Path(__file__).resolve().parents[5]
RUN=Path(__file__).resolve().parent
sys.path[:0]=[str(ROOT/'scripts/research'),str(ROOT/'local/tools/python-unicorn')]
import capstone
import v2_source_dependencies as dep
from v2_shared_manifests import ManifestReader
spec=importlib.util.spec_from_file_location('native558',ROOT/'scripts/research/verify-v2-native-batch.py')
n=importlib.util.module_from_spec(spec);spec.loader.exec_module(n)
raw=(ROOT/'local/game/Porsche.exe').read_bytes();sha=lambda b:hashlib.sha256(b).hexdigest()
assert sha(raw)=='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
baseline=RUN.parent/'554-audio-kernel-integration/build-001.json'
build=json.loads(baseline.read_bytes());cfg=json.loads(baseline.with_name('build-config.json').read_bytes())
_,effective=ManifestReader(ROOT).resolve(build,'source','crlf-to-lf','crlf-to-lf')
dep.EXTRA_INCLUDE_DIRS=tuple(ROOT/p for p in cfg['source_include_dirs'])
roots=list(build['compiled_source_roots'])
for packet in ('555-audio-backend-finalize','556-application-audio-lifecycle'):
    ready=json.loads((RUN.parent/packet/'ready.json').read_bytes());roots+=ready['sources_to_add']
closure=dep.source_hashes(roots)
idx=ROOT/'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d'
functions={f['entry_va']:f for f in map(json.loads,(idx/'functions.jsonl').read_text().splitlines())}
sizes={0x565c70:90,0x565cd0:137,0x590250:56,0x590290:3,
       0x5901b0:153,0x5902a0:157,0x4ab470:63,0x565890:135}
md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32);bodies=[]
for va,size in sizes.items():
    b=n.pe_at(raw,va,size);ins=[dict(va=f'{i.address:08x}',raw=i.bytes.hex(),asm=f'{i.mnemonic} {i.op_str}'.strip()) for i in md.disasm(b,va)]
    assert sum(len(bytes.fromhex(i['raw'])) for i in ins)==size
    bodies.append(dict(va=f'{va:08x}',bytes=size,sha256=sha(b),raw_hex=b.hex(),instructions=ins,index=functions.get(f'{va:08x}')))
target={f'{v:08x}' for v in sizes}|{'006b4a08','006b4a0c','006b4a0d','006b4886','006b4898','006b499c','006b49a4','006b4a00','006b4a3c','006b4a40','006b4aa0','006b4ae0','006b4b20'}
hits=[]
for name in closure:
    if Path(name).suffix not in ('.cpp','.hpp','.h','.inc'):continue
    for line_no,line in enumerate((ROOT/name).read_text(encoding='utf-8-sig').splitlines(),1):
        if any(t[2:] in line.lower() for t in target):hits.append(dict(file=name,line=line_no,text=line.strip()))
registry=json.loads((ROOT/'iterations/v2/001-original-recovery/source/recovered/functions.json').read_bytes())
selected={v:sizes[v] for v in (0x565c70,0x565cd0,0x590250,0x590290)};collisions=[]
for row in registry['functions']:
    if row.get('module')!='Porsche.exe' or 'entry_va' not in row:continue
    ranges=functions.get(row['entry_va'],{}).get('ranges',[[row['entry_va'],row['entry_va']]])
    if any(any(int(a,16)<va+size and int(b,16)>=va for a,b in ranges) for va,size in selected.items()):collisions.append(row)
e=dict(kind='approved-sparse-period-transport-three-partial-address-domains',query='postsetup4ab470 and frame565cd0 callers;565c70/565cd0/590250/590290 transport;5901b0/5902a0 callback boundaries',module_sha256=sha(raw),
       baseline=baseline.relative_to(ROOT).as_posix(),effective_source_pins=len(effective),baseline_roots=len(build['compiled_source_roots']),current_roots=len(roots),source_header_closure=len(closure),closure_sha256=closure,
       bodies=bodies,new_body_collisions=collisions,ownership_hits=hits,
       state_contract=dict(new_bytes=193,admitted_group=list(range(32)),flags=list(range(256)),
       canonical_device_original_span=['006b48b0','006b4a3b'],group0_words=['006b4a08','006b4a10','006b4a14'],group0_bytes=['006b4a0c','006b4a0d'],
       notify_kind_owner='Run462 audio_ds_notify_kind_006b4886',callback_owner='Run455 audio_device_callback_006b4898',channel_count_pointer='canonical434 device views',
       excluded='All32 low5-bit groups use exact sparse host views; upper24 argument bits remain unproved. No original32-slot array inferred. Slot3 aliases460callbacks; later groups alias palette/new touched sparse cells. Research395 unsized network views are not canonical owners.'),
       calls=[json.loads(l) for l in (idx/'calls.jsonl').read_text().splitlines() if any(t in l for t in target)],
       references=[json.loads(l) for l in (idx/'references.jsonl').read_text().splitlines() if any(t in l for t in target)])
(RUN/'scope-evidence.json').write_text(json.dumps(e,indent=2)+'\n',encoding='utf-8',newline='\n')
print('558',len(effective),'baselinepins',len(roots),'current roots',len(closure),'closure','collisions',len(collisions))
print('owner hits',len(hits),'newdata193 all32 low-byte groups; upper address domain partial')
