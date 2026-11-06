"""Read-only shared proof audit and concrete integration handoff."""
from pathlib import Path
import hashlib,importlib.util,json,re,sys
ROOT=Path(__file__).resolve().parents[5];RUN=Path(__file__).resolve().parent
sys.path.insert(0,str(ROOT/'scripts/research'))
from v2_proof_cache import ProofCache
def module(name,path):
    spec=importlib.util.spec_from_file_location(name,path);m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m);return m
audit=module('audit543',ROOT/'scripts/research/audit-v2-native-game-batch.py')
coff=module('coff543',ROOT/'scripts/research/build-v2-compile-corpus.py')
rel=lambda p:p.relative_to(ROOT).as_posix()
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
receipt_path=ROOT/'local/experiments/v2-render-slot-reset-543/002/receipt.json';receipt=json.loads(receipt_path.read_text(encoding='utf8'))
cases=events=0
for variant in ['od','o2']:
    text=(ROOT/receipt['attempt_dir']/f'{variant}-native.log').read_text(encoding='utf8');cases+=int(re.search(r'cases=(\d+)',text)[1]);events+=int(re.search(r'events=(\d+)',text)[1])
batch=dict(native_config=receipt['config'],native_receipt=rel(receipt_path),native_cases=cases,native_receipt_sha256=sha(receipt_path))
cache=ProofCache();proof=audit.audit_native(batch,cache,sha);cache.check_stable()
source=json.loads((RUN/'native-config.json').read_text(encoding='utf8'))['sources'][0]
views={variant:coff.coff_symbols(ROOT/receipt['attempt_dir']/f'{variant}-0.obj') for variant in ['od','o2']}
coff_document=dict(native_receipt=rel(receipt_path),native_receipt_sha256=sha(receipt_path),sources={'0':dict(source=source,variants=views)})
ready=dict(status='READY-PASS-FROZEN',**batch,native_events=events,original_functions=3,original_bytes=245,new_writable_bytes=24,new_readonly_bytes=0,mutations=len(receipt['mutation_controls']),pinned_inputs=len(receipt['inputs_sha256']),pinned_outputs=len(receipt['outputs_sha256']),sources_to_add=[source],new_originals=[
dict(entry_va='00555330',original_bytes=81,abi='cdecl0,RET0;ignored result',recovered_dependencies=[],unrecovered_dependencies=[],indirect_boundary='canonical render_thrash_exports_006bd910[30],_THRASH_treset@0 stdcall0 ignored result'),
dict(entry_va='00555390',original_bytes=100,abi='cdecl0,RET0;ignored result',recovered_dependencies=['00555330','0053c290','00555400'],unrecovered_dependencies=[]),
dict(entry_va='00555400',original_bytes=64,abi='cdecl0,RET0;ignored result',recovered_dependencies=['005699f0'],unrecovered_dependencies=[],platform_imports=['KERNEL32.dll!VirtualFree'])],boundaries=[
'Normal signed slotcounts0..32,negative signed skip;finite nodes and specified slot/node aliases,no corrupt count/cycle guards',
'Actual555330/555390/555400 raw/C++ chain;controlled stdcall0 Thrash reset,cdecl fill/heap and stdcall3 VirtualFree endpoints',
'Late tReset count and per-fill count reload,epoch wrap,dirty early exit,sparse initialzeros and complete observed slot/node/global state',
'Initialarena guard,late null/alternate arena after heap callback,heap-id zero before API,API0 finalzero and bounded nested release',
'Canonical537slot1536B/540total reused by production;fixture views do not add game storage/provider ownership',
'Existing canonical heap/fill/OS implementations reused,not reaccepted as live algorithms by controlled endpoint proof',
'Broader producer554bd0/allocator554960,corrupt indices/cycles,arbitrary external aliases/faults,live heap/device/concurrency/startup/gameplay remain open',
'Antivirus-blocked537005 remains separate and unaccepted;no retry/rename/exclusion/bypass'])
for name,value in [('coff.json',coff_document),('ready.json',ready),('verification-summary.json',dict(proof,native_events=events,all_inputs_outputs_logs_and_compiler_dependencies_verified=True,receipt_sha256=sha(receipt_path)))]:
    (RUN/name).write_text(json.dumps(value,indent=2)+'\n',encoding='utf8',newline='\n')
print('frozen543',cases,'comparisons',events,'events',len(receipt['mutation_controls']),'mutations')
print('new production undefined',views['o2']['undefined'])
