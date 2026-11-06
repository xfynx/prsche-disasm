"""Read-only shared native audit and frozen550 handoff; never runs a PE."""
from pathlib import Path
import argparse,hashlib,importlib.util,json,re,sys
ROOT=Path(__file__).resolve().parents[5];RUN=Path(__file__).resolve().parent
sys.path.insert(0,str(ROOT/'scripts/research'))
from v2_proof_cache import ProofCache
def module(name,path):
    spec=importlib.util.spec_from_file_location(name,path);m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m);return m
args=argparse.ArgumentParser();args.add_argument('--attempt',type=int,required=True);options=args.parse_args()
audit=module('audit550',ROOT/'scripts/research/audit-v2-native-game-batch.py')
coff=module('coff550',ROOT/'scripts/research/build-v2-compile-corpus.py')
rel=lambda p:p.relative_to(ROOT).as_posix()
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
receipt_path=ROOT/'local/experiments/v2-audio-codec-frontier-550'/f'{options.attempt:03d}'/'receipt.json'
receipt=json.loads(receipt_path.read_bytes());cfg=json.loads((RUN/'native-config.json').read_bytes())
cases=events=0
for variant in ['od','o2']:
    text=(ROOT/receipt['attempt_dir']/f'{variant}-native.log').read_text(encoding='utf8')
    cases+=int(re.search(r'cases=(\d+)',text)[1]);events+=int(re.search(r'events=(\d+)',text)[1])
batch=dict(native_config=receipt['config'],native_receipt=rel(receipt_path),native_cases=cases,native_receipt_sha256=sha(receipt_path))
cache=ProofCache();proof=audit.audit_native(batch,cache,sha);cache.check_stable()
views={str(i):dict(source=source,variants={v:coff.coff_symbols(ROOT/receipt['attempt_dir']/f'{v}-{i}.obj') for v in ['od','o2']}) for i,source in enumerate(cfg['sources'])}
originals=[
    dict(entry_va='00597e30',original_bytes=232,abi='cdecl5/int,RET0;args1object/2requested/4output',recovered_dependencies=['00598a50'],unrecovered_dependencies=['0059a910']),
    dict(entry_va='0059c1e0',original_bytes=378,abi='cdecl5/int,RET0;both completeRET paths;args1object/2requested/4output',recovered_dependencies=['00561800','005618c0','0059a800','00598a50','0058fef0'],unrecovered_dependencies=['0059a910']),
    dict(entry_va='0059b690',original_bytes=404,abi='cdecl5/int,RET0;args1object/2requested/4output',recovered_dependencies=['00561800','005618c0'],unrecovered_dependencies=['00597810'])]
ready=dict(status='READY-PASS-FROZEN',**batch,native_events=events,original_functions=3,original_bytes=1014,new_writable_bytes=0,new_readonly_bytes=0,
           mutations=len(receipt['mutation_controls']),pinned_inputs=len(receipt['inputs_sha256']),pinned_outputs=len(receipt['outputs_sha256']),sources_to_add=[cfg['sources'][0]],new_originals=originals,
           expected_new_frontier=['?audio_adpcm_decode_0059a910@porsche@@YAXII@Z','?audio_resampler_decode_00597810@porsche@@YAXIII@Z'],
           reused_native_sources=cfg['sources'][1:],boundaries=[
               'Caller glue only;ADPCM59a910 cdecl2void(state,flag0) and resampler597810 cdecl3void(input,output,state) remain real unresolved kernels;deterministic opaque endpoints prove transport,not codec math',
               'Actual raw/canonical504init+readbits+original masks/scalars,505acquire/ack,519copy,434zero compose unchanged;no cloned state owner or accepted source edits',
               'Finite mapped plain requests0..433,stream signedskip-1/0 and positive1..433,carry0/1/7/432,16bitcursor/carry and packedmetadataalias reload/wrap,actual callbacks/terminal miss/marker0and1/all return paths',
               'Unsigned plain position precheck and wrapping position advance/signedoverrun;late counts/halfwords/processed totals;specified object-buffer/input/metadata aliases and align0..3;complete object/data/record snapshots and callback/kernel argument/order snapshots',
               'BothOd/O2 stack/nonvolatile ABI,returnedEAX and x87CW/status/tag/values;callback FPUchange and maskeddepth0/1/6/7. No native3DNow instruction executes or hardware claim changes',
               '001base variants passed but latehalfword mutation survived;002 changes only packedmetadataalias fixture sample to carry2/cursorFFFF;production algorithms unchanged',
               'Negative plain requests,huge wrapping copies/arbitrary external or caller-stack aliases,invalid/corrupt producer states,faults/unmaskedFP/concurrency/fullkernel/liveaudio/startup/gameplay remain open;no clamps/guards added to production',
               'Native proof independent until root sharedgame integration;blocked547 unchanged/no retry/bypass;541007/545001 remain immutable'])
for name,value in [('coff.json',dict(native_receipt=rel(receipt_path),native_receipt_sha256=sha(receipt_path),sources=views)),('ready.json',ready),('verification-summary.json',dict(proof,native_events=events,receipt_sha256=sha(receipt_path),all_inputs_outputs_logs_and_compiler_dependencies_verified=True))]:
    (RUN/name).write_text(json.dumps(value,indent=2)+'\n',encoding='utf8',newline='\n')
print('frozen550',cases,'comparisons',events,'events',len(receipt['mutation_controls']),'mutations')
print('primaryCOFF',views['0']['variants']['o2'])
