"""Read-only handoff for003 compiler artifacts; never opens or executes od.exe."""
import hashlib
import importlib.util
import json
from pathlib import Path

ROOT=Path(__file__).resolve().parents[5]
RUN=Path(__file__).resolve().parent
OUT=ROOT/'local/experiments/v2-audio-period-control-558/003'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
rel=lambda p:p.resolve().relative_to(ROOT).as_posix()
cfg=json.loads((RUN/'native-config.json').read_bytes())
spec=importlib.util.spec_from_file_location('coff558',ROOT/'scripts/research/build-v2-compile-corpus.py')
coff=importlib.util.module_from_spec(spec);spec.loader.exec_module(coff)
compiles=[];views={};input_paths={RUN/'native-config.json',RUN/'native-fixture.cpp.in'}
input_paths.update(ROOT/p for p in cfg['sources']+cfg['headers'])
for variant in ('od','o2'):
    for i,source in enumerate(cfg['sources']):
        receipt_path=OUT/f'{variant}-{i}-compile.execution.json';r=json.loads(receipt_path.read_bytes())
        assert r['exit_code']==0 and sha(ROOT/r['log'])==r['log_sha256']
        obj=OUT/f'{variant}-{i}.obj'
        compiles.append(dict(variant=variant,source=source,receipt=rel(receipt_path),receipt_sha256=sha(receipt_path),object=rel(obj),object_sha256=sha(obj),exit_code=0))
        dep=json.loads((OUT/'dependencies'/f'{variant}-{i}.json').read_bytes())['Data']
        for name in dep['Includes']:
            p=Path(name).resolve()
            if p.is_relative_to(ROOT):input_paths.add(p)
    views[variant]=coff.coff_symbols(OUT/f'{variant}-0.obj')
fixture=json.loads((OUT/'fixture-compile.execution.json').read_bytes());assert fixture['exit_code']==0
link_path=OUT/'od-link.execution.json';link=json.loads(link_path.read_bytes());assert link['exit_code']==0
assert not (OUT/'od-native.execution.json').exists()
assert not (OUT/'receipt.json').exists()
event=ROOT/'local/reports/558-defender-block-003.json'
assert 'VirTool:Win32/Obfuscator.UE' in event.read_text(encoding='utf-8-sig')
report=dict(status='COMPILED-RESEARCH-DEFENDER-BLOCKED',accepted=False,native_cases=0,detected_mutations=0,
 proposed_original_bodies=4,proposed_original_bytes=286,proposed_new_writable_bytes=193,proposed_readonly_bytes=0,
 partial_entries=['00565c70','00565cd0','00590250'],full_entry_candidate='00590290',
 compile_receipts=compiles,fixture_compiled=True,od_link_exit_code=0,od_link_receipt=rel(link_path),od_link_receipt_sha256=sha(link_path),
 source_coff=views,source_inputs_sha256={rel(p):sha(p) for p in sorted(input_paths)},
 block_evidence=rel(event),block_evidence_sha256=sha(event),
 blocked_before='shared runner digest(od.exe), prior to any native execution or mutation control',
 no_executable_hash_or_read_retry=True,no_antivirus_exclusion_rename_or_bypass=True,
 boundaries=['Od/O2 translation-unit compilation and Od link are not original behavior acceptance',
             'Three indexed entries remain partial for upper24 argument address bits; typed callback algorithms remain unresolved',
             'All native cases, FPU/ABI/cross-owner checks and13 mutations are pending, not passed',
             'Do not integrate or add registry entries until an authorized original-native proof can execute'])
(RUN/'compile-readiness.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8',newline='\n')
print('558 research-only',len(compiles),'successful TU compiles,fixture/Od link0;native cases0;Defender blocked; no executable opened')
