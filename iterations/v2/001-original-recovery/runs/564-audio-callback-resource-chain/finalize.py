"""Read-only native proof and COFF handoff, with no executable rerun."""
from pathlib import Path
import hashlib,importlib.util,json,sys
root=Path(__file__).resolve().parents[5];run=Path(__file__).resolve().parent
sys.path.insert(0,str(root/'scripts/research'))
from v2_proof_cache import ProofCache
def module(name,path):
    spec=importlib.util.spec_from_file_location(name,path);m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m);return m
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
audit=module('audit564',root/'scripts/research/audit-v2-native-game-batch.py')
coff=module('coff564',root/'scripts/research/build-v2-compile-corpus.py')
receipt=root/'local/experiments/v2-audio-callback-resource-chain-564/008/receipt.json'
config='iterations/v2/001-original-recovery/runs/564-audio-callback-resource-chain/native-config-008.json'
batch={'native_config':config,'native_receipt':receipt.relative_to(root).as_posix(),'native_cases':384,'native_receipt_sha256':sha(receipt)}
cache=ProofCache();proof=audit.audit_native(batch,cache,sha);cache.check_stable()
obj=root/'local/experiments/v2-audio-callback-resource-chain-564/008'
views={v:coff.coff_symbols(obj/f'{v}-0.obj') for v in ['od','o2']}
source='iterations/v2/001-original-recovery/runs/564-audio-callback-resource-chain/audio_callback_resource_564.cpp'
scope=json.loads((run/'scope-evidence.json').read_bytes()); data=json.loads((run/'string-evidence.json').read_bytes())
assert not scope['hits'] and not scope['overlaps'] and not data['exact_literal_hits'] and not data['nearby_candidates']
assert sum(x['bytes'] for x in data['witnesses'])==98
ready={'status':'BOUNDED-PARTIAL-REVIEW','native':batch,'native_audit':proof,'source':source,'source_sha256':sha(root/source),
 'originals':[{'va':b['va'],'bytes':b['bytes'],'status':'partial-native-differential-verified'} for b in scope['bodies']],
 'readonly_original_data':data['witnesses'],'scope_evidence_sha256':sha(run/'scope-evidence.json'),'string_evidence_sha256':sha(run/'string-evidence.json'),
 'boundaries':['Only indexed resource lookup; named comparison endpoint fails closed; name lookup is untested.',
  'Only output1 and null output2 at actual caller; direct alias/null/output2 and arbitrary memory overlap untested.',
  'Controlled fixture state transports canonical root, option and diagnostic handler symbols; original x86 reader vs actual compiled canonical 540 reader.',
  'Controlled diagnostic and stream endpoints; no callback root/stack mutations, live stream or device.',
  'ABI checks cdecl stack and EBX/ESI/EDI/EBP on composed parent; individual body ABIs not separately measured; incidental EAX not compared.',
  'One seeded x87 state: CW/SW/full16-bit tag/all live80/MXCSR compared; no PC/RC/sticky matrix or unmasked-FP proof.',
  'Malformed resource/faults, complete producers, arbitrary callbacks, startup and gameplay remain open.']}
for name,value in [('ready.json',ready),('coff.json',{'source':source,'variants':views})]:
    (run/name).write_text(json.dumps(value,indent=2)+'\n',encoding='utf-8',newline='\n')
print('audit',proof,'partial entries',len(scope['bodies']),'readonly bytes',98)
