"""Read-only codec-frontier/body ownership census; no implementation or execution."""
from pathlib import Path
import hashlib,importlib.util,json,re,sys
ROOT=Path(__file__).resolve().parents[5];RUN=Path(__file__).resolve().parent
sys.path[:0]=[str(ROOT/'scripts/research'),str(ROOT/'local/tools/python-unicorn')]
import capstone
import v2_source_dependencies as dep
from v2_shared_manifests import ManifestReader
spec=importlib.util.spec_from_file_location('native550',ROOT/'scripts/research/verify-v2-native-batch.py')
native=importlib.util.module_from_spec(spec);spec.loader.exec_module(native)
raw=(ROOT/'local/game/Porsche.exe').read_bytes()
sha=lambda data:hashlib.sha256(data).hexdigest()
assert sha(raw)=='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
idx=ROOT/'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d'
indexed=list(map(json.loads,(idx/'functions.jsonl').read_text().splitlines()))
functions={f['entry_va']:f for f in indexed}
registry_path=ROOT/'iterations/v2/001-original-recovery/source/recovered/functions.json'
registry=json.loads(registry_path.read_text())
baseline=RUN.parent/'545-audio-nibble-3dnow-integration/build-001.json'
build=json.loads(baseline.read_text());cfg=json.loads(baseline.with_name('build-config.json').read_text())
_,effective=ManifestReader(ROOT).resolve(build,'source','crlf-to-lf','crlf-to-lf')
dep.EXTRA_INCLUDE_DIRS=tuple(ROOT/p for p in cfg['source_include_dirs'])
closure=dep.source_hashes(build['compiled_source_roots'])
md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
sizes={0x597e30:232,0x59c1e0:378,0x59b690:404}
for address in [0x59a910,0x597810,0x59abe0,0x59adc0,0x59ae00,0x58fef0]:
    sizes[address]=functions[f'{address:08x}']['body_bytes']
bodies=[]
for va,size in sizes.items():
    data=native.pe_at(raw,va,size)
    ins=[dict(va=f'{i.address:08x}',raw=i.bytes.hex(),asm=f'{i.mnemonic} {i.op_str}'.strip()) for i in md.disasm(data,va)]
    assert sum(len(bytes.fromhex(i['raw'])) for i in ins)==size
    bodies.append(dict(va=f'{va:08x}',bytes=size,sha256=sha(data),raw_hex=data.hex(),index=functions.get(f'{va:08x}'),instructions=ins))
targets={f'{v:08x}' for v in sizes}
refs=[json.loads(line) for line in (idx/'references.jsonl').read_text().splitlines() if any(t in line for t in targets)]
calls=[json.loads(line) for line in (idx/'calls.jsonl').read_text().splitlines() if any(t in line for t in targets)]
overlaps=[]
for row in registry['functions']:
    if row.get('module')!='Porsche.exe' or 'entry_va' not in row:continue
    ranges=functions.get(row['entry_va'],{}).get('ranges',[[row['entry_va'],row['entry_va']]])
    if any(int(a,16)<v+sizes[v] and int(b,16)>=v for a,b in ranges for v in sizes):overlaps.append(row)
hits=[]
for name in closure:
    if Path(name).suffix not in ['.cpp','.h','.hpp','.inc']:continue
    for number,line in enumerate((ROOT/name).read_text(encoding='utf-8').splitlines(),1):
        if any(t[2:] in line.lower() for t in targets):hits.append(dict(file=name,line=number,text=line.strip()))
result=dict(kind='research-only-no-implementation',query='coded ADPCM/resampler process frontiers, actual constructors/callers/kernel children, complete545compiler closure',
            original_sha256=sha(raw),baseline=str(baseline.relative_to(ROOT)),effective_source_pins=len(effective),compiled_roots=len(build['compiled_source_roots']),
            source_header_closure=len(closure),closure_sha256=closure,registry_sha256=sha(registry_path.read_bytes()),
            body_collisions=overlaps,ownership_hits=hits,bodies=bodies,calls=calls,references=refs)
(RUN/'scope-evidence.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8',newline='\n')
stream=next(row for row in bodies if row['va']=='0059c1e0')
supplement=dict(kind='raw-code-index-coverage-supplement-not-behavior-proof',module='Porsche.exe',module_sha256=sha(raw),
                entry_va=stream['va'],bytes=stream['bytes'],sha256=stream['sha256'],raw_hex=stream['raw_hex'],
                existing_index_entry=stream['index'],existing_symbol_kind='Label',
                returns=[row['va'] for row in stream['instructions'] if row['asm']=='ret'],
                direct_calls=[row for row in stream['instructions'] if row['asm'].startswith('call ')],
                next_entry='0059c360',padding_hex=native.pe_at(raw,0x59c35a,6).hex(),
                abi='cdecl5 int;arg1 object,arg2 count,arg4 output;explicit EAX result;RET0',
                index_sha256={name:sha((idx/name).read_bytes()) for name in ['functions.jsonl','symbols.jsonl','calls.jsonl','references.jsonl']},
                boundary='Original constructor504 stores this callback;raw full CFG ends at bothRET before padding. Semantics require later original comparisons.')
(RUN/'original-index-supplement.json').write_text(json.dumps(supplement,indent=2)+'\n',encoding='utf-8',newline='\n')
print(json.dumps({k:result[k] for k in ['effective_source_pins','compiled_roots','source_header_closure']}))
print('bodies',[(r['va'],r['bytes']) for r in bodies]);print('collisions',[(r.get('entry_va'),r.get('source')) for r in overlaps])
