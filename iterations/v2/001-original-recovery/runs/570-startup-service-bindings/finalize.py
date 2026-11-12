"""Read-only audit and COFF handoff; never executes a proof binary."""
from pathlib import Path
import hashlib,importlib.util,json,sys
root=Path(__file__).resolve().parents[5];run=Path(__file__).resolve().parent
sys.path.insert(0,str(root/'scripts/research'))
from v2_proof_cache import ProofCache
def module(name,path):
 spec=importlib.util.spec_from_file_location(name,path);m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m);return m
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
audit=module('audit570',root/'scripts/research/audit-v2-native-game-batch.py');coff=module('coff570',root/'scripts/research/build-v2-compile-corpus.py')
receipt=root/'local/experiments/v2-startup-service-bindings-570/001/receipt.json'
batch={'native_config':'iterations/v2/001-original-recovery/runs/570-startup-service-bindings/native-config.json','native_receipt':receipt.relative_to(root).as_posix(),'native_cases':360,'native_receipt_sha256':sha(receipt)}
cache=ProofCache();proof=audit.audit_native(batch,cache,sha);cache.check_stable()
obj=receipt.parent;views={v:coff.coff_symbols(obj/f'{v}-0.obj') for v in ['od','o2']}
scope=json.loads((run/'scope-evidence.json').read_bytes());assert not scope['overlaps'] and scope['new_byte']['initial']==0
ready={'status':'BOUNDED-PARTIAL-REVIEW','native':batch,'native_audit':proof,'source':'iterations/v2/001-original-recovery/runs/570-startup-service-bindings/startup_service_570.cpp',
 'originals':[{'va':'00536080','bytes':27,'status':'partial-native-differential-verified','calling_convention':'original ECX receiver, RET0; fastcall and cdecl transport adapters','recovered_dependencies':['00555330']}],
 'new_data':[scope['new_byte']], 'scope_evidence_sha256':sha(run/'scope-evidence.json'),
 'expected_frontier':['?startup_sequence_service_00536080@porsche@@YIXPAX0@Z','?game_setup_movie_service_begin_00536080@porsche@@YAXPAX@Z'],
 'boundaries':['Receiver is a mapped independent buffer; arbitrary aliases/faults and incidental EAX are not accepted.',
  'Actual canonical Run543 child executes; its render platform callback and fixture storage are controlled, not live driver.',
  'A single seeded x87 state compares abridged tag/live80/control/status; MXCSR/full tag and FP matrix not claimed.',
  'Original descriptor 005de680 overlaps existing 005de6ac; 00534540 remains deferred, with no duplicate state or provider.']}
for name,value in [('ready.json',ready),('coff.json',{'variants':views})]:
 (run/name).write_text(json.dumps(value,indent=2)+'\n',encoding='utf-8',newline='\n')
print('audit',proof,'one partial entry, two ABI bindings, one original byte')
