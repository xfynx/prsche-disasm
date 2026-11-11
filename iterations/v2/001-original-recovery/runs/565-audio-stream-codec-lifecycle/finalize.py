"""Audit frozen native receipt and record conservative readiness; no native rerun."""
from pathlib import Path
import hashlib,importlib.util,json,sys
ROOT=Path(__file__).resolve().parents[5];RUN=Path(__file__).resolve().parent
sys.path.insert(0,str(ROOT/'scripts/research'))
from v2_proof_cache import ProofCache
def module(name,path):
 spec=importlib.util.spec_from_file_location(name,path);m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m);return m
def sha(path):return hashlib.sha256(Path(path).read_bytes()).hexdigest()
def rel(path):return path.relative_to(ROOT).as_posix()
path=ROOT/'local/experiments/v2-audio-codec-access-565/002/receipt.json';receipt=json.loads(path.read_bytes());cfg=json.loads((RUN/'native-config.json').read_bytes())
batch=dict(native_config=receipt['config'],native_receipt=rel(path),native_cases=7392,native_receipt_sha256=sha(path))
audit=module('audit565',ROOT/'scripts/research/audit-v2-native-game-batch.py');cache=ProofCache();proof=audit.audit_native(batch,cache,sha);cache.check_stable()
coff=module('coff565',ROOT/'scripts/research/build-v2-compile-corpus.py');views={v:coff.coff_symbols(ROOT/receipt['attempt_dir']/f'{v}-0.obj') for v in ('od','o2')}
source=cfg['sources'][0];entries=[('0056b380',45,'native-differential-verified'),('0056b4c0',122,'partial'),('0056c840',80,'partial'),('005912e0',58,'partial')]
ready=dict(status='READY-BOUNDED-PASS',**batch,native_events=3332,original_functions=4,full_original_functions=1,partial_original_functions=3,original_bytes=305,new_writable_bytes=0,new_readonly_bytes=90,
 mutations=len(receipt['mutation_controls']),fp_configurations=144,sources_to_add=[source],source_headers=[rel(RUN/'audio_codec_access_565.hpp')],source_sha256=sha(ROOT/source),header_sha256=sha(RUN/'audio_codec_access_565.hpp'),
 new_originals=[dict(entry_va=va,original_bytes=size,status=status,source=source) for va,size,status in entries],undefined_o2=views['o2']['undefined'],
 boundaries=['The native fixture exercises mapped handles, invalid magic/null, unaligned aliases, signed thresholds, wrapper index edges and seeded x87 state; arbitrary pointer faults and concurrency remain outside the proof.',
 '0056b4c0 calls controlled 0056b540; actual transition remains a real frontier and dependent parent is partial.',
 '0056c840 frame subtraction has narrow value coverage; raw input bits and return are compared but broader arithmetic boundaries remain to be exercised.',
 '005912e0 accepts unchanged 32-bit outer-slot index bits; actual 005673d0 -> 005912e0 composition and real codec-result producer remain unproved. Run561 creator stays partial.',
 'Diagnostic handler is a controlled IAT seam; exact two message bytes plus original source-file bytes are independently read and checked before relocation. Two production local message arrays account for 90 bytes; source-file VA stays raw metadata.',
 'Ownership census uses 563 baseline; recheck the actual intake closure if it changes. Full create/destroy/reset and callbacks remain outside this packet.',
 'REA attempt001 failed before analysis with spawn EPERM; attempt002 permission request was interrupted before launch. Raw PE/index and pre-existing Ghidra pseudocode informed the candidate; no REA audit is claimed.'])
for name,value in [('ready.json',ready),('coff.json',dict(native_receipt=rel(path),variants=views)),('verification-summary.json',dict(proof=proof,native_events=3332,receipt_sha256=sha(path)))]:
 (RUN/name).write_text(json.dumps(value,indent=2)+'\n',encoding='utf-8',newline='\n')
print('565 audit PASS: 7392 cases, 8 controls; 1 full / 3 partial')
