"""Read-only native proof audit and frozen546 integration handoff."""
from pathlib import Path
import hashlib,importlib.util,json,re,sys
ROOT=Path(__file__).resolve().parents[5];RUN=Path(__file__).resolve().parent
sys.path.insert(0,str(ROOT/'scripts/research'))
from v2_proof_cache import ProofCache
def module(name,path):
 spec=importlib.util.spec_from_file_location(name,path);m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m);return m
audit=module('audit546',ROOT/'scripts/research/audit-v2-native-game-batch.py')
coff=module('coff546',ROOT/'scripts/research/build-v2-compile-corpus.py')
rel=lambda p:p.relative_to(ROOT).as_posix()
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
receipt_path=ROOT/'local/experiments/v2-render-resource-allocation-546/003/receipt.json'
receipt=json.loads(receipt_path.read_bytes());cfg=json.loads((RUN/'native-config.json').read_bytes())
cases=events=0
for variant in ['od','o2']:
 text=(ROOT/receipt['attempt_dir']/f'{variant}-native.log').read_text(encoding='utf8');cases+=int(re.search(r'cases=(\d+)',text)[1]);events+=int(re.search(r'events=(\d+)',text)[1])
batch=dict(native_config=receipt['config'],native_receipt=rel(receipt_path),native_cases=cases,native_receipt_sha256=sha(receipt_path))
cache=ProofCache();proof=audit.audit_native(batch,cache,sha);cache.check_stable()
sources=cfg['sources'];views={str(i):dict(source=source,variants={v:coff.coff_symbols(ROOT/receipt['attempt_dir']/f'{v}-{i}.obj') for v in ['od','o2']}) for i,source in enumerate(sources)}
originals=[
 dict(entry_va='00553fc0',original_bytes=134,abi='cdecl1DWORD,RET0;int result',recovered_dependencies=['00555390','00569a70','005697f0'],unrecovered_dependencies=[],platform_imports=['KERNEL32.dll!VirtualAlloc'],binding_boundary='569a70 controlled typed external;accepted canonical static owner requires separately proved export'),
 dict(entry_va='00554b50',original_bytes=64,abi='cdecl0,RET0;int result',recovered_dependencies=['00553fc0'],unrecovered_dependencies=[]),
 dict(entry_va='00554b20',original_bytes=44,abi='cdecl2DWORD,RET0;pointer result',recovered_dependencies=['00554b50','00531ca0'],unrecovered_dependencies=[]),
 dict(entry_va='00554b90',original_bytes=59,abi='cdecl1DWORD,RET0;pointer result',recovered_dependencies=['00554b50','00531ca0','0053c290'],unrecovered_dependencies=[]),
 dict(entry_va='00554ad0',original_bytes=79,abi='cdecl5DWORD,RET0;ignored result',recovered_dependencies=['00556880'],unrecovered_dependencies=[]),
 dict(entry_va='00554bd0',original_bytes=228,abi='cdecl4DWORD,RET0;slot result;full-table tail noreturn',recovered_dependencies=['005a246e'],unrecovered_dependencies=['0055ec50']),
]
ready=dict(status='READY-PASS-FROZEN-INDEPENDENT',**batch,native_events=events,original_functions=6,original_bytes=608,new_writable_bytes=8,new_readonly_bytes=199,mutations=len(receipt['mutation_controls']),pinned_inputs=len(receipt['inputs_sha256']),pinned_outputs=len(receipt['outputs_sha256']),sources_to_add=[sources[0]],reused_native_sources=sources[1:],new_originals=originals,
 integration_blockers=['Canonical569a70 exists as static function in immutable application_heap_init.cpp;root547 export regression was Defender-blocked beforeexecution and remains unaccepted.546 controls this external endpoint and does not establish its game provider.',
 'Capacity diagnostic0055ec50 is a real unresolved dependency;no fixture diagnostic/process/API/heap provider may enter the game graph.'],
 boundaries=[
 'Six actual raw/C++ bodies608B plus actual543invalidate/reset/release and canonical521format;external heap/OS/diagnostic/process/heap-slot children controlled',
 'Raw preferred-capacity4B/format14sparseDWORD56B/DTEX5B/capacitymessage138B checked before fixture resets;sentinel4B initialloaderzero section evidence',
 'Last matching slot;normal32records;derived sentinel006a3a08 read before capacity or found return proved by matched inaccessible-page read faults;sentinel owns separate4B section,not a33rd slot or C++array overrun',
 'Admitted formatA0..13;wrapping products/negative signed truncation;flags lowbyte0/1/2/255 and upper32bit distinctions;negative width skip behavior',
 'VirtualAlloc0/1,exact ABI/flags,late arena/capacity/id after controlled callbacks,ignored heap-init result,signedlazy threshold/decrements,unconditional nodeNULL fill endpoint',
 'Full-slot diagnostic channel/message/exit-1 call order transported through controlled nonreturn exception,not actual logging/process termination;nodeNULL fill uses controlled exception,not canonical fill fault acceptance',
 'BothOd/O2 stack/nonvolatile registers and x87CW/status/tag/values,callback FPUchanges,unaligned admitted node/header bytes and complete intermediate/final snapshots',
 '001fixturelinkfailure and002surviving signeddivision control preserved;003coverage-repaired negative products passes all30controls',
 'No outer554960/selector54820/comparator554310;arbitrary format/index,corrupt chain,external aliases/faults/concurrency/live heap/API/device/startup/gameplay and current game integration remain open',
 'No retry/rename/exclusion/bypass of blocked547 or537005 artifacts'])
for name,value in [('coff.json',dict(native_receipt=rel(receipt_path),native_receipt_sha256=sha(receipt_path),sources=views)),('ready.json',ready),('verification-summary.json',dict(proof,native_events=events,all_inputs_outputs_logs_and_compiler_dependencies_verified=True,receipt_sha256=sha(receipt_path)))]:
 (RUN/name).write_text(json.dumps(value,indent=2)+'\n',encoding='utf8',newline='\n')
print('frozen546',cases,'comparisons',events,'events',len(receipt['mutation_controls']),'mutations')
print('production undefined',views['0']['variants']['o2']['undefined'])
