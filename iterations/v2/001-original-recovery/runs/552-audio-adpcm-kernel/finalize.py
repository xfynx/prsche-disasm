"""Use the unchanged shared read-only audit and freeze the independent Run552 packet."""
import argparse
import hashlib
import importlib.util
import json
import re
import subprocess
import sys
from pathlib import Path

ROOT=Path(__file__).resolve().parents[5]
RUN=Path(__file__).resolve().parent
sys.path.insert(0,str(ROOT/'scripts/research'))
from v2_proof_cache import ProofCache


def module(name,path):
    spec=importlib.util.spec_from_file_location(name,path)
    value=importlib.util.module_from_spec(spec)
    spec.loader.exec_module(value)
    return value


parser=argparse.ArgumentParser()
parser.add_argument('--attempt',type=int,required=True)
args=parser.parse_args()
rel=lambda p:p.relative_to(ROOT).as_posix()
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
receipt_path=ROOT/'local/experiments/v2-audio-adpcm-kernel-552'/f'{args.attempt:03d}'/'receipt.json'
receipt=json.loads(receipt_path.read_bytes())
cfg=json.loads((RUN/'native-config.json').read_bytes())
cases=events=0
for variant in ('od','o2'):
    text=(ROOT/receipt['attempt_dir']/f'{variant}-native.log').read_text()
    cases+=int(re.search(r'cases=(\d+)',text)[1])
    events+=int(re.search(r'events=(\d+)',text)[1])
batch=dict(native_config=receipt['config'],native_receipt=rel(receipt_path),native_cases=cases,native_receipt_sha256=sha(receipt_path))
audit=module('audit552',ROOT/'scripts/research/audit-v2-native-game-batch.py')
cache=ProofCache()
proof=audit.audit_native(batch,cache,sha)
cache.check_stable()
subprocess.run([sys.executable,str(RUN/'audit-static.py'),'--attempt',f'{args.attempt:03d}'],check=True,cwd=ROOT)
static_path=ROOT/'local/reports'/f'552-fp-static-audit-{args.attempt:03d}.json'
static=json.loads(static_path.read_bytes())
assert static['PASS']
coff=module('coff552',ROOT/'scripts/research/build-v2-compile-corpus.py')
views={str(i):dict(source=source,variants={v:coff.coff_symbols(ROOT/receipt['attempt_dir']/f'{v}-{i}.obj') for v in ('od','o2')}) for i,source in enumerate(cfg['sources'])}
sizes={'0059a910':706,'0059abe0':397,'0059ad80':58,'0059adc0':61,'0059ae00':1914,'0059b580':176}
arity={'0059a910':2,'0059abe0':4,'0059ad80':2,'0059adc0':1,'0059ae00':3,'0059b580':2}
translation=json.loads((RUN/'translation-evidence.json').read_bytes())
dependencies={b['va']:list(dict.fromkeys(re.search(r'_([0-9a-f]{8})$',i['source'])[1]
              for i in b['instructions'] if i['source'].startswith('call '))) for b in translation['bodies']}
ready=dict(status='READY-PASS-FROZEN',**batch,native_events=events,original_functions=6,original_bytes=sum(sizes.values()),
           new_writable_bytes=0,new_readonly_bytes=1144,mutations=len(receipt['mutation_controls']),
           pinned_inputs=len(receipt['inputs_sha256']),pinned_outputs=len(receipt['outputs_sha256']),
           sources_to_add=[cfg['sources'][0]],reused_native_sources=cfg['sources'][1:],
           new_originals=[dict(entry_va=va,original_bytes=size,abi=f'cdecl{arity[va]}/void,RET0',recovered_dependencies=dependencies[va],unrecovered_dependencies=[]) for va,size in sizes.items()],
           expected_new_frontier=[],static_audit=rel(static_path),static_audit_sha256=sha(static_path),
           fp_configurations=216,boundaries=[
               'Six static MSVC x86 instruction translations; no runtime production original byte blob. 3312 original bytes and 1144 exact new readonly bytes; canonical504readbits and519copy reused.',
               'PC0/2/3 by RC0..3 by incoming depth0..5 by sticky0/25/453f: full CW/SW/16-bit tag/live80-bit values and MXCSR, stack/nonvolatile/DF ABI, state/output exact. FIP/FDP host addresses excluded; empty slots undefined.',
               'Original 037 frame regression seed1f4ec7c7 now exact. Mode-zero gain is pinned qword005b2778=0.5; absence of FLDCW never establishes a process precision contract.',
               'Raw canonical1144B asserted against independent PE bytes before execution; actual COFF instructions/data+call relocations/control flow checked at both optimization levels. No added clamps/guards or invented opaque locals.',
               'Actual550caller composition, real music streams, truncated/malformed/corrupt inputs, arbitrary caller-stack/external aliases, unmasked exceptions, more incoming live slots/invalid stack, concurrency/liveaudio/startup/gameplay remain open.',
               'Independent packet only. Game integration/registry/pin counts belong to root later554; blocked547 and537005 never retried.'])
for name,value in [('coff.json',dict(native_receipt=rel(receipt_path),native_receipt_sha256=sha(receipt_path),sources=views)),
                   ('ready.json',ready),('verification-summary.json',dict(proof,native_events=events,receipt_sha256=sha(receipt_path),static_audit_sha256=sha(static_path),all_inputs_outputs_logs_and_compiler_dependencies_verified=True))]:
    (RUN/name).write_text(json.dumps(value,indent=2)+'\n',encoding='utf-8',newline='\n')
print('frozen552',cases,'comparisons',events,'events',len(receipt['mutation_controls']),'mutations')
print('primaryCOFF',views['0']['variants']['o2'])
