"""Read-only ADPCM kernel-family/data/ownership census against551."""
from pathlib import Path
import hashlib,importlib.util,json,re,sys,struct
ROOT=Path(__file__).resolve().parents[5];RUN=Path(__file__).resolve().parent
sys.path[:0]=[str(ROOT/'scripts/research'),str(ROOT/'local/tools/python-unicorn')]
import capstone
import v2_source_dependencies as dep
from v2_shared_manifests import ManifestReader
spec=importlib.util.spec_from_file_location('native552scope',ROOT/'scripts/research/verify-v2-native-batch.py')
n=importlib.util.module_from_spec(spec);spec.loader.exec_module(n)
raw=(ROOT/'local/game/Porsche.exe').read_bytes();sha=lambda b:hashlib.sha256(b).hexdigest()
assert sha(raw)=='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
idx=ROOT/'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d'
functions={r['entry_va']:r for r in map(json.loads,(idx/'functions.jsonl').read_text().splitlines())}
registry_path=ROOT/'iterations/v2/001-original-recovery/source/recovered/functions.json';registry=json.loads(registry_path.read_bytes())
baseline=RUN.parent/'551-diagnostic-codec-integration/build-001.json';build=json.loads(baseline.read_bytes());cfg=json.loads(baseline.with_name('build-config.json').read_bytes())
_,effective=ManifestReader(ROOT).resolve(build,'source','crlf-to-lf','crlf-to-lf')
dep.EXTRA_INCLUDE_DIRS=tuple(ROOT/p for p in cfg['source_include_dirs']);closure=dep.source_hashes(build['compiled_source_roots'])
md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32);bodies=[]
targets=['0059a910','0059abe0','0059ad80','0059adc0','0059ae00','0059b580']
for target in targets:
    f=functions[target];va=int(target,16);data=n.pe_at(raw,va,f['body_bytes'])
    ins=[dict(va=f'{i.address:08x}',raw=i.bytes.hex(),asm=f'{i.mnemonic} {i.op_str}'.strip()) for i in md.disasm(data,va)]
    assert sum(len(bytes.fromhex(i['raw'])) for i in ins)==len(data)
    bodies.append(dict(va=target,bytes=len(data),sha256=sha(data),raw_hex=data.hex(),index=f,instructions=ins))
spans=[('quantized',0x5e34c4,256),('codebook',0x5e35c4,512),('symbols',0x5e37c4,348),('quarter',0x5b2468,4),('half_double',0x5b2778,8),('blend_fir',0x5c1808,16),('switch_targets',0x59ad70,16)]
data=[]
for name,va,size in spans:
    value=n.pe_at(raw,va,size);data.append(dict(name=name,va=f'{va:08x}',bytes=size,sha256=sha(value),raw_hex=value.hex()))
assert max(n.pe_at(raw,0x5e35c4,512))==28
calls=[json.loads(line) for line in (idx/'calls.jsonl').read_text().splitlines() if any(t in line for t in targets)]
refs=[]
for line in (idx/'references.jsonl').read_text().splitlines():
    row=json.loads(line);address=int(row['to_va'],16) if re.fullmatch('[0-9a-fA-F]{8}',row.get('to_va','')) else -1
    if row.get('to_va') in targets or any(va<=address<va+size for _,va,size in spans):refs.append(row)
collisions=[]
for row in registry['functions']:
    if row.get('module')!='Porsche.exe' or 'entry_va' not in row:continue
    ranges=functions.get(row['entry_va'],{}).get('ranges',[[row['entry_va'],row['entry_va']]])
    if any(int(a,16)<int(t,16)+functions[t]['body_bytes'] and int(b,16)>=int(t,16) for a,b in ranges for t in targets):collisions.append(row)
queries=[t[2:] for t in targets]+[f'{va:08x}'[2:] for _,va,_ in spans]+['5e3504','5e37c8','5e37cc','5e37d0','5c180c','5c1810','5c1814']
hits=[]
for name in closure:
    if Path(name).suffix not in ['.cpp','.h','.hpp','.inc']:continue
    for number,line in enumerate((ROOT/name).read_text(encoding='utf-8').splitlines(),1):
        if any(q in line.lower() for q in queries):hits.append(dict(file=name,line=number,text=line.strip()))
result=dict(kind='research-only-no-implementation',query='ADPCM59a910 full kernel/transitive six-body family;actual550caller+504bitstate;original tables/scalars/full551ownership',
            original_sha256=sha(raw),baseline=str(baseline.relative_to(ROOT)),effective_source_pins=len(effective),compiled_roots=len(build['compiled_source_roots']),
            source_header_closure=len(closure),closure_sha256=closure,registry_sha256=sha(registry_path.read_bytes()),body_collisions=collisions,
            bodies=bodies,data=data,calls=calls,references=refs,ownership_hits=hits,
            index_sha256={name:sha((idx/name).read_bytes()) for name in ['functions.jsonl','calls.jsonl','references.jsonl']})
(RUN/'scope-evidence.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8',newline='\n')
print(json.dumps(dict(pins=len(effective),roots=len(build['compiled_source_roots']),closure=len(closure),bytes=sum(r['bytes'] for r in bodies),collisions=len(collisions))))
print('OWNERSHIP');print('\n'.join(str(h) for h in hits));print('rawdata',[(r['name'],r['bytes']) for r in data])
