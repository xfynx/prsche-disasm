"""Freeze the passed three-body pan packet with the unchanged shared read-only audit."""
import argparse
import hashlib
import importlib.util
import json
import re
import sys
from pathlib import Path

ROOT=Path(__file__).resolve().parents[5]
RUN=Path(__file__).resolve().parent
sys.path.insert(0,str(ROOT/'scripts/research'))
from v2_proof_cache import ProofCache

def module(name,path):
    spec=importlib.util.spec_from_file_location(name,path)
    m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m);return m

parser=argparse.ArgumentParser();parser.add_argument('--attempt',type=int,required=True);args=parser.parse_args()
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
rel=lambda p:p.relative_to(ROOT).as_posix()
receipt_path=ROOT/'local/experiments/v2-audio-backend-finalize-555'/f'{args.attempt:03d}'/'receipt.json'
receipt=json.loads(receipt_path.read_bytes());cfg=json.loads((RUN/'native-config.json').read_bytes())
cases=events=0
for variant in ('od','o2'):
    log=(ROOT/receipt['attempt_dir']/f'{variant}-native.log').read_text()
    cases+=int(re.search(r'cases=(\d+)',log)[1]);events+=int(re.search(r'events=(\d+)',log)[1])
batch=dict(native_config=receipt['config'],native_receipt=rel(receipt_path),native_receipt_sha256=sha(receipt_path),native_cases=cases)
audit=module('audit555',ROOT/'scripts/research/audit-v2-native-game-batch.py')
cache=ProofCache();proof=audit.audit_native(batch,cache,sha);cache.check_stable()
coff=module('coff555',ROOT/'scripts/research/build-v2-compile-corpus.py')
views={str(i):dict(source=source,variants={v:coff.coff_symbols(ROOT/receipt['attempt_dir']/f'{v}-{i}.obj') for v in ('od','o2')}) for i,source in enumerate(cfg['sources'])}
scope=json.loads((RUN/'scope-evidence.json').read_bytes())
span=ROOT/'local/reports/555-pan-data-span-review.json'
assert span.is_file()
originals=[dict(entry_va='0058e0e0',original_bytes=424,abi='cdecl0/void,RET0;256 rows; original signed IDIV and callback-free leaf calls',recovered_dependencies=['0058e0b0'],unrecovered_dependencies=[]),
           dict(entry_va='0058e0b0',original_bytes=36,abi='cdecl1/signed32 EAX,RET0;exact wrapping integer polynomial and signed magic division',recovered_dependencies=[],unrecovered_dependencies=[]),
           dict(entry_va='0058e290',original_bytes=51,abi='cdecl2/void,RET0;arithmetic phase>>8; captured low-byte count; original forward copy',recovered_dependencies=[],unrecovered_dependencies=[])]
ready=dict(status='READY-PASS-FROZEN',**batch,native_events=events,original_functions=3,original_bytes=511,new_writable_bytes=1025,new_readonly_bytes=0,
           mutations=len(receipt['mutation_controls']),pinned_inputs=len(receipt['inputs_sha256']),pinned_outputs=len(receipt['outputs_sha256']),
           sources_to_add=[cfg['sources'][0]],reused_native_sources=cfg['sources'][1:],new_originals=originals,expected_new_frontier=[],
           data_span_review=rel(span),data_span_review_sha256=sha(span),fp_configurations=324,
           boundaries=[
               'Pan/weight table builder, polynomial and copy consumer; not device cleanup. Original511B static instructions and1025B exact touched loader-zero span006b181f..006b1c1f (one preceding byte plus1024B table). No invented padding/guards or raw runtime production blob.',
               'Canonical application_audio_device_state_006b48c0 remains sole device owner; full551754pins/307roots/557closure plus552553 gives310roots/564closure, no body/exact data owner collision. Root bounded span census independently finds no recognized declaration overlap.',
               'Builder count0..4, tested distinct nonzero-divisor circular thresholds and high count-word prefixes; count0 original negative last-column offset writes the separately proved preceding byte. Bounds come from admitted physical extents, not a global producer clamp claim.',
               'Polynomial full32-bit edge/random inputs, usedEAX and exact multiply/sign correction; actual raw builder->raw polynomial->raw copy versus compiled three-body compositions with all256 intermediate rows; all original forward copy/order/state and specified table/device-output overlaps+align0..3.',
               'PC0/2/3 byRC0..3 by incoming depth0..8 bysticky0/25/453f: full CW/SW/16bit tag/live80bit values/MXCSR and cdecl nonvolatile/stack/DF ABI. No FP arithmetic occurs in these bodies. FIP/FDP host addresses and undefined empty values excluded.',
               'Constructor/create_device and broader audio consumer are not composed here. Only the three new real bodies execute; dead dependencies of unchanged canonical state-owner TU fail-closed in fixture and never enter game.',
               'Divide-by-zero/signed quotient overflow, count beyond4, arbitrary invalid/external/caller-stack output/phase aliases, unmasked FP/faults/concurrency/live audio/startup/gameplay remain open. Independent packet until later root shared integration; period565c70 deferred; no blocked547/537005 retry.'])
for name,value in [('coff.json',dict(native_receipt=rel(receipt_path),native_receipt_sha256=sha(receipt_path),sources=views)),('ready.json',ready),
                   ('verification-summary.json',dict(proof,native_events=events,receipt_sha256=sha(receipt_path),all_inputs_outputs_logs_and_compiler_dependencies_verified=True,data_span_review_sha256=sha(span)))]:
    (RUN/name).write_text(json.dumps(value,indent=2)+'\n',encoding='utf-8',newline='\n')
print('frozen555',cases,'cases',events,'events',len(receipt['mutation_controls']),'mutations',len(receipt['inputs_sha256']),'inputs',len(receipt['outputs_sha256']),'outputs')
print('primaryCOFF',views['0']['variants']['o2'])
