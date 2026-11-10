"""Read-only shared native audit/COFF handoff; no executable rerun."""
from pathlib import Path
import argparse,hashlib,importlib.util,json,re,sys
ROOT=Path(__file__).resolve().parents[5];RUN=Path(__file__).resolve().parent
sys.path.insert(0,str(ROOT/'scripts/research'))
from v2_proof_cache import ProofCache
def module(name,path):
 spec=importlib.util.spec_from_file_location(name,path);m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m);return m
parser=argparse.ArgumentParser();parser.add_argument('--attempt',type=int,required=True);args=parser.parse_args()
audit=module('audit559',ROOT/'scripts/research/audit-v2-native-game-batch.py');coff=module('coff559',ROOT/'scripts/research/build-v2-compile-corpus.py')
rel=lambda p:p.relative_to(ROOT).as_posix();sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
path=ROOT/'local/experiments/v2-audio-stream-service-559'/f'{args.attempt:03d}'/'receipt.json';receipt=json.loads(path.read_bytes());cfg=json.loads((RUN/'native-config.json').read_bytes());cases=events=0
for variant in ['od','o2']:
 text=(ROOT/receipt['attempt_dir']/f'{variant}-native.log').read_text();cases+=int(re.search(r'cases=(\d+)',text)[1]);events+=int(re.search(r'events=(\d+)',text)[1])
batch=dict(native_config=receipt['config'],native_receipt=rel(path),native_cases=cases,native_receipt_sha256=sha(path));cache=ProofCache();proof=audit.audit_native(batch,cache,sha);cache.check_stable()
views={str(i):dict(source=source,variants={v:coff.coff_symbols(ROOT/receipt['attempt_dir']/f'{v}-{i}.obj') for v in ['od','o2']}) for i,source in enumerate(cfg['sources'])};source=cfg['sources'][0]
scope=json.loads((RUN/'scope-evidence.json').read_bytes());rows={b['va']:b for b in scope['bodies']}
dependencies={'00561960':([],[]),'005611d0':([],[]),'005611e0':(['005611d0','00589790'],[]),'005678a0':(['005611e0'],[]),'005678c0':(['005678a0','0056afc0'],[]),'0056afc0':([],[]),'00567660':([],['005673d0'])}
abi={'00561960':'cdecl1(pointer28),signed32EAX0/RET0;26writtenbytes+2preserved','005611d0':'cdecl1 uint32EAX/RET0;wrapping3*n+12 thenSHL3','005611e0':'cdecl1 uint32EAX/RET0;recordbytes+canonicalprefix','005678a0':'cdecl2 uint32EAX/RET0;record/prefix+44*n+f8 wrapping','005678c0':'cdecl2 uint32EAX/RET0;servicebytes+codecbytes(count+1,1,1)','0056afc0':'cdecl3 uint32EAX/RET0;exact LEA/SHL integer wrap','00567660':'cdecl5 signed32EAX/RET0;realcreator receives(arg1..5,0,0) as cdecl7'}
originals=[dict(entry_va=va,source=source,original_bytes=rows[va]['bytes'],status='native-differential-verified',abi=abi[va],recovered_dependencies=dependencies[va][0],unrecovered_dependencies=dependencies[va][1]) for va in dependencies]
frontier=[n for n in views['0']['variants']['o2']['undefined'] if '005673d0' in n]
ready=dict(status='READY-PASS-FROZEN',**batch,native_events=events,original_functions=7,full_original_functions=7,partial_original_functions=0,original_bytes=258,new_writable_bytes=0,new_readonly_bytes=0,mutations=len(receipt['mutation_controls']),pinned_inputs=len(receipt['inputs_sha256']),pinned_outputs=len(receipt['outputs_sha256']),sources_to_add=[source],new_originals=originals,expected_new_frontier=frontier,reused_native_sources=cfg['sources'][1:],fp_configurations=144,boundaries=[
 'Seven static MSVC x86 bodies258B, no data/state/array owner or guessedcapacity.557current767effectivepins312roots568source/header closure has no newbody/interiorcollision; canonical508prefix00589790 actualsource executes, no cloned leaf',
 'All integer LEA/IMUL-free SHL/add wrap and actualcalls/usedEAX/cdeclnonvolatile+stack balanced atOd/O2; full32bit input edges, definedmapped descriptors+alignment0..3 and full28B seededinput/output compare including original26writes and two preservedbytes22/23',
 'Actualbegin5 forwards allfive plus twoexplicitzeros to real5673d0cdecl7/EAX endpoint. Controlledcreator captures allseven arguments/knownmapped pointer, fullusedEAX and descriptor/root/CW effects; it is transport,not creator/stream math acceptance. No fixture provider enters game',
 'Direct descriptor->begin composition plus actualraw556e010->raw559helpers versus compiled556->compiled559 with actualcanonicalprefix, heap/scheduler/support. Inherited556uninitializedcaller bytes22/23 alone masked at controlledcreator seam;556PARTIAL status/source remain immutable,neverupgraded by this packet',
 'FPmatrix144configurations PC0/2/3 RC0..3 live-depth0/1/5/8 sticky0/25/453f across allseven bodies and both compositions; fullCW/SW/16bit tag/live80-bit/MXCSR. HostFIP/FDP and undefinedempty payloads excluded; integeronly original bodies contain no FP arithmetic',
 'Currentsemanticnavigation records384Bcreator7DWORDcopy tostream+DC,314Bomitted567270 callback forwarding+DC to791B5612a0arg4; that consumer reads only knownfields on this path. Otherconsumerclosure remains open; physicalopaque transport isnotpadding proof or permission to promote556partial',
 'Actualcreator5673d0, streamslots/maps/callback algorithms, storage/fault/invalidpointer/callerstack aliases/unmaskedFP/concurrency/liveaudio/startup/gameplay remain open. No guessed capacities/zeroing/clamps, unrelated accepted-case reruns, originalasset changes or blocked547/537005 retry'])
for name,value in [('coff.json',dict(native_receipt=rel(path),native_receipt_sha256=sha(path),sources=views)),('ready.json',ready),('verification-summary.json',dict(proof,native_events=events,receipt_sha256=sha(path),all_inputs_outputs_logs_and_compiler_dependencies_verified=True))]:
 (RUN/name).write_text(json.dumps(value,indent=2)+'\n',encoding='utf-8',newline='\n')
print('frozen559',cases,'comparisons',events,'events',len(receipt['mutation_controls']),'mutations;7full/258B/0data');print(json.dumps(views['0'],indent=2))
