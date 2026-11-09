"""Read-only audits/COFF inventory for the two553 proofs; never executes a PE."""
from pathlib import Path
import argparse,hashlib,importlib.util,json,re,sys
ROOT=Path(__file__).resolve().parents[5];RUN=Path(__file__).resolve().parent
sys.path.insert(0,str(ROOT/'scripts/research'))
from v2_proof_cache import ProofCache
def module(name,path):
 spec=importlib.util.spec_from_file_location(name,path);m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m);return m
args=argparse.ArgumentParser();args.add_argument('--kernel-attempt',type=int,required=True);args.add_argument('--random-attempt',type=int,default=1);options=args.parse_args()
audit=module('audit553',ROOT/'scripts/research/audit-v2-native-game-batch.py');coff=module('coff553',ROOT/'scripts/research/build-v2-compile-corpus.py')
rel=lambda p:p.relative_to(ROOT).as_posix();sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
base=ROOT/'local/experiments/v2-audio-resampler-kernel-553'
batches=[];views={};proofs=[];events=mutations=0;cache=ProofCache();sources=[]
for kind,path in [('kernel',base/f'{options.kernel_attempt:03d}'/'receipt.json'),('random',base/'random'/f'{options.random_attempt:03d}'/'receipt.json')]:
 receipt=json.loads(path.read_bytes());cfg=json.loads((ROOT/receipt['config']).read_bytes());cases=count=0
 for variant in ['od','o2']:
  text=(ROOT/receipt['attempt_dir']/f'{variant}-native.log').read_text();cases+=int(re.search(r'cases=(\d+)',text)[1]);count+=int(re.search(r'events=(\d+)',text)[1])
 batch=dict(native_config=receipt['config'],native_receipt=rel(path),native_receipt_sha256=sha(path),native_cases=cases)
 proof=audit.audit_native(batch,cache,sha);batches.append(batch);proofs.append(dict(kind=kind,**proof,native_events=count))
 events+=count;mutations+=len(receipt['mutation_controls']);source=cfg['sources'][0];sources.append(source)
 views[kind]=dict(source=source,variants={v:coff.coff_symbols(ROOT/receipt['attempt_dir']/f'{v}-0.obj') for v in ['od','o2']},native_receipt=rel(path),native_receipt_sha256=sha(path))
cache.check_stable()
kernel_source,random_source=sources
originals=[dict(entry_va='00597810',source=kernel_source,original_bytes=678,abi='cdecl3 void(input,output,state),RET0;exact x87 CW/status/stack/order/qword spills',recovered_dependencies=['005a17c9','005a0f98'],unrecovered_dependencies=[]),dict(entry_va='005a17c9',source=random_source,original_bytes=34,abi='cdecl0 signed32/EAX,RET0;wrap32 state+14 and15-bit result',recovered_dependencies=['005a545c'],unrecovered_dependencies=[]),dict(entry_va='005a17bc',source=random_source,original_bytes=13,abi='cdecl1 void(seed),RET0;canonical thread state+14',recovered_dependencies=['005a545c'],unrecovered_dependencies=[])]
ready=dict(status='READY-PASS-FROZEN',native_batches=batches,native_cases=sum(b['native_cases'] for b in batches),native_events=events,mutations=mutations,original_functions=3,original_bytes=725,new_writable_bytes=0,new_readonly_bytes=76,sources_to_add=sources,new_originals=originals,expected_new_frontier=[],boundaries=[
 'Kernel678B original LPC/noise-pulse10-stage lattice/160 float outputs;exact x87 assembly maintains arithmetic,spills,aliasing,clipping,countdown,history and end-state order independent of SSE2/compiler FP flags',
 'Two separately frozen shared-runner proofs form one planned553 packet: kernel with controlled random returns/effects; actual47B rand/seed with controlled canonicalgetptd returned thread records. Existing canonical522ftol executes for kernel; originalftol raw oracle executes opposite side',
 'Original76Breadonlydata independently checked against rawPE bytes before scenes.754 effectivepins307roots557source+header closure has no exact newbody/interior/data owner collision;0newTLSorstate owner',
 'Specified direct packet/state/output aliases and align0..3,masked PC0/2/3 RC0..3 and seeded live x87 stack depths;all160 sample outputs and persistent frame states plus controlled-rand before/after intermediate state/order compare atOd/O2',
 'Actual550 callback processes partial block and cached carry across17/160/143 sample requests with actualcanonical504 constructor zeroing200B,505ack and existing state owners; canonical producer proofs reused',
 'Random proof checks wrap32 LCG with8 seed edges,alternating returned records,late seed mutation and callback CW effects;full thread record/state/usedEAX/nonvolatile ABI/FPU observation atOd/O2',
 'FXSAVE observesCW/SW/abridged physical tag and everylive80bit payload;empty-register payloads and instruction/data addresses are not compared. No arbitrary FLDENV tag fabrication or MMX state domain is claimed',
 'Canonicalgetptd full TLS/lifecycle proof reused,not rerun or replaced in game. Faults/unmaskedFP/corrupt arbitrary producer states/aliases/concurrency/fullproducer/liveaudio/startup/gameplay remain open; no guard/clamp invented',
 'Native proofs independent until root later common game build/COFF/registry audit;accepted551/blocked547/537005 remain untouched'])
for name,value in [('coff.json',dict(sources=views,native_batches=batches)),('ready.json',ready),('verification-summary.json',dict(native_batches=proofs,native_cases=ready['native_cases'],native_events=events,mutations=mutations,all_inputs_outputs_logs_and_compiler_dependencies_verified=True))]:
 (RUN/name).write_text(json.dumps(value,indent=2)+'\n',encoding='utf-8',newline='\n')
print('frozen553',ready['native_cases'],'comparisons',events,'events',mutations,'mutations');print(json.dumps(views,indent=2))
