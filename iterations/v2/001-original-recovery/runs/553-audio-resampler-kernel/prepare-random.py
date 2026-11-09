"""Independent rand/seed proof within the already planned553 kernel packet."""
from pathlib import Path
import hashlib,importlib.util,json,sys
ROOT=Path(__file__).resolve().parents[5];RUN=Path(__file__).resolve().parent
sys.path[:0]=[str(ROOT/'scripts/research')]
spec=importlib.util.spec_from_file_location('n553random',ROOT/'scripts/research/verify-v2-native-batch.py');n=importlib.util.module_from_spec(spec);spec.loader.exec_module(n)
raw=(ROOT/'local/game/Porsche.exe').read_bytes();sha=lambda b:hashlib.sha256(b).hexdigest()
assert sha(raw)=='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
scope=json.loads((RUN/'scope-evidence.json').read_text())
hits=[]
for name in scope['closure_sha256']:
 if Path(name).suffix not in ['.cpp','.hpp','.h','.inc']:continue
 for number,line in enumerate((ROOT/name).read_text(encoding='utf-8').splitlines(),1):
  if any(term in line.lower() for term in ['5a17bc','5a17c9','5a545c','p+0x14,1']):hits.append(dict(file=name,line=number,text=line.strip()))
idx=ROOT/'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d';funcs={r['entry_va']:r for r in map(json.loads,(idx/'functions.jsonl').read_text().splitlines())}
records=[]
for va,size,token in [(0x5a17c9,34,'@RANDOM553@'),(0x5a17bc,13,'@SEED553@')]:
 b=n.pe_at(raw,va,size);records.append(dict(va=f'{va:08x}',bytes=size,sha256=sha(b),token=token,raw_hex=b.hex(),index=funcs.get(f'{va:08x}')))
e=dict(module_sha256=sha(raw),baseline=scope['baseline'],effective_source_pins=754,compiled_roots=307,source_header_closure=557,ownership_hits=hits,bodies=records,canonical_child='source/recovered/Porsche.exe/formatter_crt_runtime.cpp:formatter_crt_thread_005a545c',canonical_seed_producer='formatter_crt_initialize_thread_005a5449 writes+14=1',calls=[json.loads(l) for l in (idx/'calls.jsonl').read_text().splitlines() if any(t in l for t in ['005a17bc','005a17c9','005a545c'])],boundary='Original LCG/seed body acceptance with controlled returned thread record and effects. Existing canonical TLS/getptd proof reused; no new TLS state or claimed live thread lifecycle.')
(RUN/'random-scope-evidence.json').write_text(json.dumps(e,indent=2)+'\n',encoding='utf-8',newline='\n')
src=(RUN/'audio_random_553.cpp').relative_to(ROOT).as_posix()
mutations=[('lcg-multiply','state*0x343fdu','state*0x343feu'),('lcg-add','+0x269ec3u','+0x269ec2u'),('state-store','std::memcpy(thread+0x14,&state,4);','std::memcpy(thread+0x18,&state,4);'),('result-shift','(state>>16)','(state>>15)'),('result-mask','&0x7fffu','&0xffffu'),('seed-store','std::memcpy(thread+0x14,&seed,4);','std::memcpy(thread+0x18,&seed,4);')]
text=(ROOT/src).read_text()
for name,old,new in mutations:assert text.count(old)==1
cfg=dict(run=553,experiment='local/experiments/v2-audio-resampler-kernel-553/random',original_pe='local/game/Porsche.exe',original_sha256=sha(raw),sources=[src],fixture=(RUN/'native-random-fixture.cpp.in').relative_to(ROOT).as_posix(),include_dirs=[RUN.relative_to(ROOT).as_posix(),'iterations/v2/001-original-recovery/source/include'],headers=[(RUN/f).relative_to(ROOT).as_posix() for f in ['random-scope-evidence.json','prepare-random.py']],original_bodies=[{k:r[k] for k in ['va','bytes','sha256','token']} for r in records],pass_marker='audio_random_original_x86_vs_cpp=PASS',timeout_seconds=120,mutations=[dict(name=name,source=src,old=old,new=new,expected_exit=1,failure_marker='divergence') for name,old,new in mutations])
(RUN/'native-random-config.json').write_text(json.dumps(cfg,indent=2)+'\n',encoding='utf-8',newline='\n')
print('prepared553 random47B,canonicalgetptd child,6 mutations')
