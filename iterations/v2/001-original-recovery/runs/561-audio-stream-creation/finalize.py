"""Audit the frozen native receipt and publish a conservative integration handoff."""
from pathlib import Path
import hashlib, importlib.util, json, sys

ROOT=Path(__file__).resolve().parents[5]
RUN=Path(__file__).resolve().parent
sys.path.insert(0,str(ROOT/'scripts/research'))
from v2_proof_cache import ProofCache

def module(name,path):
    spec=importlib.util.spec_from_file_location(name,path)
    result=importlib.util.module_from_spec(spec);spec.loader.exec_module(result)
    return result
def sha(path):return hashlib.sha256(Path(path).read_bytes()).hexdigest()
def rel(path):return path.relative_to(ROOT).as_posix()

receipt_path=ROOT/'local/experiments/v2-audio-stream-creation-561/003/receipt.json'
receipt=json.loads(receipt_path.read_bytes())
config=json.loads((RUN/'native-config.json').read_bytes())
batch=dict(native_config=receipt['config'],native_receipt=rel(receipt_path),
           native_cases=3562,native_receipt_sha256=sha(receipt_path))
audit=module('audit561',ROOT/'scripts/research/audit-v2-native-game-batch.py')
cache=ProofCache();proof=audit.audit_native(batch,cache,sha);cache.check_stable()
coff=module('coff561',ROOT/'scripts/research/build-v2-compile-corpus.py')
views={v:coff.coff_symbols(ROOT/receipt['attempt_dir']/f'{v}-0.obj') for v in ('od','o2')}
source=config['sources'][0]
scope=json.loads((RUN/'scope-evidence.json').read_bytes())
sizes={x['va']:x['bytes'] for x in scope['bodies']}
entries=['005673d0','00567690','00567740','00566d60','005673b0','00566d40','0058ff50','0058ff70']
ready=dict(status='READY-BOUNDED-PASS',**batch,native_events=2168,
    sources_to_add=[source],source_headers=[rel(RUN/'audio_stream_creation_561.hpp')],
    source_sha256=sha(ROOT/source),header_sha256=sha(RUN/'audio_stream_creation_561.hpp'),
    original_bytes=909,new_writable_bytes=80,new_readonly_bytes=0,
    original_functions=8,full_original_functions=1,partial_original_functions=7,
    mutations=len(receipt['mutation_controls']),fp_configurations=144,
    new_originals=[dict(entry_va=va,source=source,original_bytes=sizes[va],
         status='native-differential-verified' if va=='00566d60' else 'partial') for va in entries],
    undefined_o2=views['o2']['undefined'],boundaries=[
      'Creator numeric and memory domains bounded by fixture; signed slot scan address domain asserted.',
      'Count uses signed pointer scan; registration/removal index a signed callback count, with out-of-domain physical aliases unproved.',
      'Shutdown exercises populated 16-slot setup; stop scene does not establish a true two-live-slot case.',
      'Descriptor bytes 22/23 remain physically copied, not proved padding; 556 stays partial.',
      'Actual codec and callback bodies, arbitrary aliases/faults, concurrency, live audio and game startup remain open.',
      'Scope census predates 560 intake; integration must check its current complete source closure and canonical ownership.' ])
for name,value in [('ready.json',ready),('coff.json',dict(native_receipt=rel(receipt_path),variants=views)),
                   ('verification-summary.json',dict(proof=proof,native_events=2168,receipt_sha256=sha(receipt_path)))]:
    (RUN/name).write_text(json.dumps(value,indent=2)+'\n',encoding='utf-8',newline='\n')
print('561 shared native audit PASS: 3562 cases, 16 controls; 1 full / 7 partial')
