"""Read-only audit of frozen549 and concrete root integration handoff."""
from pathlib import Path
import hashlib,importlib.util,json,re,sys
ROOT=Path(__file__).resolve().parents[5];RUN=Path(__file__).resolve().parent
sys.path.insert(0,str(ROOT/'scripts/research'))
from v2_proof_cache import ProofCache
def module(name,path):
 spec=importlib.util.spec_from_file_location(name,path);m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m);return m
audit=module('audit549',ROOT/'scripts/research/audit-v2-native-game-batch.py');coff=module('coff549',ROOT/'scripts/research/build-v2-compile-corpus.py')
rel=lambda p:p.relative_to(ROOT).as_posix();sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
receipt_path=ROOT/'local/experiments/v2-render-diagnostic-549/001/receipt.json';receipt=json.loads(receipt_path.read_bytes());cfg=json.loads((RUN/'native-config.json').read_bytes())
cases=events=0
for variant in ['od','o2']:
 text=(ROOT/receipt['attempt_dir']/f'{variant}-native.log').read_text(encoding='utf8');cases+=int(re.search(r'cases=(\d+)',text)[1]);events+=int(re.search(r'events=(\d+)',text)[1])
batch=dict(native_config=receipt['config'],native_receipt=rel(receipt_path),native_cases=cases,native_receipt_sha256=sha(receipt_path))
cache=ProofCache();proof=audit.audit_native(batch,cache,sha);cache.check_stable()
views={str(i):dict(source=source,variants={v:coff.coff_symbols(ROOT/receipt['attempt_dir']/f'{v}-{i}.obj') for v in ['od','o2']}) for i,source in enumerate(cfg['sources'])}
ready=dict(status='READY-PASS-FROZEN',**batch,native_events=events,original_functions=1,original_bytes=116,new_writable_bytes=0,new_readonly_bytes=0,mutations=len(receipt['mutation_controls']),pinned_inputs=len(receipt['inputs_sha256']),pinned_outputs=len(receipt['outputs_sha256']),sources_to_add=[cfg['sources'][0]],reused_native_sources=cfg['sources'][1:],new_originals=[dict(entry_va='0055ec50',original_bytes=116,abi='cdecl(channelDWORD,constchar*format,...),RET0;void/ignored EAX;device callback cdecl(channel,text) ignored return',recovered_dependencies=['0055eba0','005a299e'],unrecovered_dependencies=[],indirect_boundary='eight canonical34512B records;device callback flag/pointer read after formatter/previous callbacks')],
 boundaries=[
 'One116B body,0newdata;545746pins/304roots/550source-header closure,registry832preflight and no body overlaps;canonical345channels/devices/started/startup and353vsprintf remain singleton owners',
 'Actual raw116B/C++ diagnostic with actual345startup and353vsprintf/formatter_entry;raw input varargs8words plus guardword;no new parser/formatter algorithm',
 'Controlled formatter-core/config/environment/device/process endpoints establish transport and state/order only;descriptor opaque tail untouched/uninspected and cleanup path not admitted',
 'Valid channel0,2,6,15,16,63;bit0flags/highbits,started0/1/highbit,enabled/null callbacks across8records;late channel/device flag/callback edits;no channel/start recheck after format/callbacks',
 'Bounded formatter output0/1/127/2047 terminated through accepted wrapper;callback buffer identity/written bytes and edits compare;never inspect uninitialized local tail or expired stackbuffer',
 'Buffer snapshots cache controlled written prefixes,device callbacks copy actual live prefixes includingNUL;no final dead-stack read;formatter return0/negative ignored',
 'Actual accepted546full32-slot capacity raw/C++ caller invokes549 then controlled noreturn exit-1;other546heap-slot/heap/API/reset/fill/header endpoints fail closed and never execute',
 'Od/O2 stack/nonvolatile and x87CW/status/tag/values compare with callback FPUchanges;all16mutations detected;shared read-only audit verifies all pins/logs/compiler dependencies',
 'Existing565340 numeric diagnostic/file-pointer prototype problem unchanged;no direct reuse or invented file-string resolution',
 'No full format/parser/overflow/arbitrarychannel/aliases/faults/reentry/concurrency/live device/OS/startup/gameplay acceptance;no blocked547/537005 retry/rename/exclusion/bypass'])
for name,value in [('coff.json',dict(native_receipt=rel(receipt_path),native_receipt_sha256=sha(receipt_path),sources=views)),('ready.json',ready),('verification-summary.json',dict(proof,native_events=events,all_inputs_outputs_logs_and_compiler_dependencies_verified=True,receipt_sha256=sha(receipt_path)))]:
 (RUN/name).write_text(json.dumps(value,indent=2)+'\n',encoding='utf8',newline='\n')
print('frozen549',cases,'comparisons',events,'events',len(receipt['mutation_controls']),'mutations')
print('new production defined',views['0']['variants']['o2']['defined']);print('production undefined',views['0']['variants']['o2']['undefined'])
