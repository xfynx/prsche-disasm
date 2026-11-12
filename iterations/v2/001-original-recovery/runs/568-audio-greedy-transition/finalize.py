"""Audit the frozen 568 native receipt and publish bounded integration evidence."""
from pathlib import Path
import hashlib,importlib.util,json,re,sys
ROOT=Path(__file__).resolve().parents[5];RUN=Path(__file__).resolve().parent
sys.path.insert(0,str(ROOT/'scripts/research'))
from v2_proof_cache import ProofCache
def module(name,path):
 spec=importlib.util.spec_from_file_location(name,path);m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m);return m
def sha(path):return hashlib.sha256(Path(path).read_bytes()).hexdigest()
def rel(path):return path.relative_to(ROOT).as_posix()
path=ROOT/'local/experiments/v2-audio-greedy-transition-568/002/receipt.json';receipt=json.loads(path.read_bytes());cfg=json.loads((RUN/'native-config.json').read_bytes());cases=events=0
for variant in ('od','o2'):
 log=(ROOT/receipt['attempt_dir']/f'{variant}-native.log').read_text();cases+=int(re.search(r'cases=(\d+)',log)[1]);events+=int(re.search(r'events=(\d+)',log)[1])
batch=dict(native_config=receipt['config'],native_receipt=rel(path),native_cases=cases,native_receipt_sha256=sha(path))
audit=module('audit568',ROOT/'scripts/research/audit-v2-native-game-batch.py');cache=ProofCache();proof=audit.audit_native(batch,cache,sha);cache.check_stable()
coff=module('coff568',ROOT/'scripts/research/build-v2-compile-corpus.py');views={v:coff.coff_symbols(ROOT/receipt['attempt_dir']/f'{v}-0.obj') for v in ('od','o2')}
owner=json.loads((RUN/'message-ownership.json').read_bytes());assert owner['source_hits']==[] and owner['bytes']==47
source=cfg['sources'][0];header=RUN/'audio_greedy_transition_568.hpp'
ready=dict(status='READY-BOUNDED-PASS',**batch,native_events=events,original_functions=2,full_original_functions=0,partial_original_functions=2,original_bytes=178,new_writable_bytes=0,new_readonly_bytes=47,
 mutations=len(receipt['mutation_controls']),sources_to_add=[source],source_headers=[rel(header)],source_sha256=sha(ROOT/source),header_sha256=sha(header),message_ownership=rel(RUN/'message-ownership.json'),message_ownership_sha256=sha(RUN/'message-ownership.json'),
 new_originals=[dict(entry_va='0056b540',original_bytes=110,status='partial',source=source,reason='Bounded mapped-handle domains and controlled diagnostic; raw file-label pointer consumer remains open.'),dict(entry_va='005681b0',original_bytes=68,status='partial',source=source,reason='Seeded actual list/queue states and controlled lock/event endpoints; arbitrary alias, lifetime and concurrency domains remain open.')],
 undefined_o2=views['o2']['undefined'],boundaries=['Original message bytes independently PE-checked and 567 source closure searched; 47-byte new message does not overlap 565 message.',
 'Actual 565 setter/wrapper -> 568 transition/child execute on both sides with actual canonical 561 lookup and canonical 00580c10/00568200 list/queue algorithms. Locks, event signaling and diagnostics are controlled fixture seams.',
 'Original wrapped computed-address zero test and group-byte write are preserved; seven mutation controls include a distinct expected access fault for an intentionally wrong zero test.',
 'One seeded full x87 control/status/tag/live80/MXCSR observation, not a broad FP matrix. Full producer and concurrent/fault behavior remain open.',
 'Actual creator 005673d0 -> wrapper and real codec-result production are not included; 561 creator and semantic dependencies stay partial.',
 'Diagnostic source-label 005bd978 remains raw metadata; the real 00565340 pointer-consuming path is not proved.',
 'Ownership census uses 567 baseline; recheck the actual intake closure if it changes.'])
for name,value in [('ready.json',ready),('coff.json',dict(native_receipt=rel(path),variants=views)),('verification-summary.json',dict(proof=proof,native_events=events,receipt_sha256=sha(path)))]:
 (RUN/name).write_text(json.dumps(value,indent=2)+'\n',encoding='utf-8',newline='\n')
print(f'568 shared audit PASS: {cases} cases, {events} events, {len(receipt["mutation_controls"])} controls; 2 partial')
