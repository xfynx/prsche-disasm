"""Audit frozen 575 native receipt and emit conservative shared-build handoff."""
from pathlib import Path
import hashlib,importlib.util,json,re,sys
ROOT=Path(__file__).resolve().parents[5];RUN=Path(__file__).resolve().parent
sys.path.insert(0,str(ROOT/'scripts/research'))
from v2_proof_cache import ProofCache
def module(name,path):
 spec=importlib.util.spec_from_file_location(name,path);m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m);return m
def sha(path):return hashlib.sha256(Path(path).read_bytes()).hexdigest()
def rel(path):return path.relative_to(ROOT).as_posix()
path=ROOT/'local/experiments/v2-render-texture-scheduler-575/001/receipt.json';receipt=json.loads(path.read_bytes());cfg=json.loads((RUN/'native-config.json').read_bytes());cases=events=0
for variant in ('od','o2'):
 log=(ROOT/receipt['attempt_dir']/f'{variant}-native.log').read_text();cases+=int(re.search(r'cases=(\d+)',log)[1]);events+=int(re.search(r'events=(\d+)',log)[1])
batch=dict(native_config=receipt['config'],native_receipt=rel(path),native_cases=cases,native_receipt_sha256=sha(path))
audit=module('audit575',ROOT/'scripts/research/audit-v2-native-game-batch.py');cache=ProofCache();proof=audit.audit_native(batch,cache,sha);cache.check_stable()
coff=module('coff575',ROOT/'scripts/research/build-v2-compile-corpus.py');views={str(i):{v:coff.coff_symbols(ROOT/receipt['attempt_dir']/f'{v}-{i}.obj') for v in ('od','o2')} for i in (0,1)}
owner=json.loads((RUN/'message-ownership.json').read_bytes());assert owner['source_hits']==[] and owner['callback_source_hits']==[] and owner['bytes']==120 and owner['callback_initial']=='00000000'
sources=cfg['sources'][:2];headers=[rel(RUN/'render_texture_scheduler_575.hpp'),rel(RUN/'texture_process_575.hpp')]
entries=[('005550e0',434,sources[0],'Integer core and void facade compared for mapped count<=32; caller return, arbitrary count/alias and live driver remain bounded.'),('005552a0',40,sources[0],'Mapped node/slot and signed score-level cases; arbitrary indices/faults remain open.'),('00554f60',212,sources[0],'Mapped node/slot and actual notify child with controlled stdcall driver callbacks; broader aliases and live driver remain open.'),('00555040',150,sources[1],'Descriptor bytes/nullness and ordered callback effects compared; stack-descriptor pointer identity and stack aliasing remain open.'),('005554b0',275,sources[1],'Mapped node/tail/list states and callback/driver reloads compared; broader lifetime/alias and live driver remain open.')]
ready=dict(status='READY-BOUNDED-PASS',**batch,native_events=events,adapter_comparisons=1032,original_functions=5,full_original_functions=0,partial_original_functions=5,original_bytes=1111,new_writable_bytes=4,new_readonly_bytes=120,mutations=len(receipt['mutation_controls']),sources_to_add=sources,source_headers=headers,source_sha256={s:sha(ROOT/s) for s in sources},header_sha256={h:sha(ROOT/h) for h in headers},message_ownership=rel(RUN/'message-ownership.json'),message_ownership_sha256=sha(RUN/'message-ownership.json'),
 new_originals=[dict(entry_va=va,original_bytes=size,status='partial',source=source,reason=reason) for va,size,source,reason in entries],undefined_o2={k:v['o2']['undefined'] for k,v in views.items()},boundaries=[
  'The original 32-entry stack-array/count behavior is retained without a clamp; comparisons cover mapped initial and callback-adjusted counts within 0..32, not out-of-range stack corruption.',
  'Original scheduler integer core and existing void linker facade are compared separately; four indexed direct callers do not consume the scheduler EAX, but indirect callers remain unproved.',
  'Exact 120 contiguous PE bytes and 4-byte loader-zero callback slot have full574 source-closure witnesses. Existing 537/543/540/357 owners are reused; fixture uses controlled 537/540 state views and driver/diagnostic endpoints.',
  'Raw 00555440 -> raw 005554b0 and raw 005550e0 -> 00554f60 -> 00555040 paths are composed against the corresponding compiled functions; descriptor nullness and all 16 written bytes are observed while stack pointer identities are normalized.',
  'One seeded full x87 and MXCSR state is observed; no broad FP matrix, arbitrary stack descriptor aliases, faults, concurrency, live driver or startup/gameplay acceptance.',
  'Existing partial parents and partial semantic dependencies do not become fully recovered by binding these symbols.',
  '574 source ownership census must be refreshed if the actual integration base changes.'])
for name,value in [('ready.json',ready),('coff.json',dict(native_receipt=rel(path),sources=views)),('verification-summary.json',dict(proof=proof,native_events=events,adapter_comparisons=1032,receipt_sha256=sha(path)))]:
 (RUN/name).write_text(json.dumps(value,indent=2)+'\n',encoding='utf-8',newline='\n')
print(f'575 shared audit PASS: {cases} scenes, {events} events, {len(receipt["mutation_controls"])} controls; 5 partial')
