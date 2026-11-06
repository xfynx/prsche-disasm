"""Read-only admission of original/compiled emulator proofs with canonical support.

The single-object498 contract remains in its immutable original auditor.
"""
import collections
import hashlib
from pathlib import Path
import struct
import sys

ROOT=Path(__file__).resolve().parents[2]

def verify_original_data(original,row,pe_at):
    va,size=int(row['va'],16),row['bytes']
    assert type(size)==int and size>0
    if row['kind']=='file-backed':
        data=pe_at(original,va,size)
    else:
        assert row['kind']=='loader-zero'
        pe=struct.unpack_from('<I',original,0x3c)[0]
        optional=pe+24
        imagebase=struct.unpack_from('<I',original,optional+28)[0]
        count=struct.unpack_from('<H',original,pe+6)[0]
        table=optional+struct.unpack_from('<H',original,pe+20)[0]
        assert any(rva+raw<=va-imagebase and va-imagebase+size<=rva+virtual
                   for virtual,rva,raw in (struct.unpack_from('<III',original,table+40*i+8)
                                           for i in range(count)))
        data=bytes(size)
    assert hashlib.sha256(data).hexdigest()==row['sha256'],row['name']

def audit_supported_emulation(base,item,cache,sha):
    load=cache.document
    cfg_path,receipt_path=ROOT/item['config'],ROOT/item['receipt']
    cfg,receipt=load(cfg_path),load(receipt_path)
    assert receipt['status']=='PASS'
    assert receipt['kind']=='emulated-original-vs-emulated-compiled-cpp'
    assert receipt['optimizations']==['Od','O2'] and cfg['cpu_model']==receipt['cpu_model']==11
    for group in ['input_sha256','output_sha256']:
        assert receipt[group]
        for name,digest in receipt[group].items():assert sha(ROOT/name)==digest,name
    verifier_path=ROOT/item['verifier']
    assert receipt['input_sha256'][item['verifier']]==sha(verifier_path)
    assert receipt['input_sha256'][item['config']]==sha(cfg_path)
    verifier=base.module('supported_emulated_verifier',verifier_path)
    assert verifier.RUN==cfg_path.parent
    work=receipt_path.parent
    retention_path=Path(verifier.retention.__file__).resolve()
    assert retention_path.parent==cfg_path.parent
    assert receipt['input_sha256'][retention_path.relative_to(ROOT).as_posix()]==sha(retention_path)
    for filename in [cfg['source'],cfg['header'],'config.json','compare.py',retention_path.name]:
        assert cache.data(work/'inputs'/filename)==cache.data(cfg_path.parent/filename)
    supports=cfg['support_sources']
    assert supports and len({row['source'] for row in supports})==len(supports)
    assert len({row['object_stem'] for row in supports})==len(supports)
    for row in supports:
        source=ROOT/row['source']
        assert source.resolve().is_relative_to(ROOT) and source.suffix=='.cpp'
        assert not any(part in source.name.lower() for part in ['fixture','probe'])
        assert Path(row['object_stem']).name==row['object_stem']
        assert receipt['input_sha256'][row['source']]==sha(source)
        assert cache.data(work/'inputs/support'/row['source'])==cache.data(source)
    original=cache.data(ROOT/cfg['original_pe'])
    assert sha(ROOT/cfg['original_pe'])==receipt['original_sha256']==cfg['original_sha256']
    for row in cfg['original_bodies']:
        assert hashlib.sha256(verifier.native.pe_at(original,int(row['va'],16),row['bytes'])).hexdigest()==row['sha256']
    for row in cfg['original_data']:verify_original_data(original,row,verifier.native.pe_at)
    assert {row['name'] for row in cfg['original_data']}==set(cfg['data_exports'])
    assert set(cfg['candidate_exports'])<=set(cfg['exports'])
    assert all(cfg['exports'][key]==value for key,value in cfg['candidate_exports'].items())
    assert set(cfg['original_symbols'])==set(cfg['exports'])

    package_roots=[Path(package.__file__).resolve().parent for package in [verifier.unicorn,verifier.capstone]]
    dependencies={Path(sys.executable).resolve(),Path(base.__file__).resolve(),Path(__file__).resolve(),
                  ROOT/'scripts/research/audit-v2-supported-game-batch.py'}
    for imported in tuple(sys.modules.values()):
        filename=getattr(imported,'__file__',None)
        if filename:
            path=Path(filename).resolve()
            if path.is_file() and any(path.is_relative_to(root) for root in package_roots):dependencies.add(path)
    for root in package_roots:
        for suffix in ['*.py','*.dll','*.so']:dependencies.update(root.rglob(suffix))
    semantic_pins={path:sha(path) for path in dependencies}
    assert verifier.unicorn.__version__==receipt['unicorn_version']
    assert list(verifier.unicorn.uc_version())==receipt['unicorn_core_version']
    executions=load(work/'executions.json')
    for execution in executions:
        assert execution['exit_code']==0
        assert sha(work/(execution['name']+'.log'))==execution['log_sha256']
    scenes,records=load(work/'cases.json'),load(work/'comparisons.json')
    assert scenes==verifier.cases() and len(scenes)==len(records)
    names=['baseline']+[row['name'] for row in cfg['mutations']]
    assert len(names)==len(set(names)) and receipt['variants_per_optimization']==len(names)
    original_source=cache.data(cfg_path.parent/cfg['source']).decode('utf8')
    assert cache.data(work/'sources/baseline.cpp').decode('utf8')==original_source
    for mutation in cfg['mutations']:
        assert original_source.count(mutation['from'])==mutation['count']
        assert cache.data(work/'sources'/(mutation['name']+'.cpp')).decode('utf8')==original_source.replace(mutation['from'],mutation['to'])
    coffs=load(work/'coff.json')
    certificates=load(work/'retention.json')
    auxiliary=cfg.get('candidate_auxiliary_symbols',[])
    # Admit only this compiler's inert selectany metadata, never extra game state.
    assert auxiliary==['__Avx2WmemEnabledWeakValue']
    def verify_auxiliary(obj):
        parsed=verifier.retention.coff(obj)
        definitions=[s for s in parsed['symbols'].values()
                     if s['name']==auxiliary[0] and s['storage']==2 and s['section']>0]
        for symbol in definitions:
            section=parsed['sections'][symbol['section']-1]
            selections=[s['aux'][14] for s in parsed['symbols'].values()
                        if s['section']==section['number'] and s['storage']==3
                        and s['kind']==0 and len(s['aux'])==18]
            assert symbol['value']==0 and section['data']==bytes(4)
            assert section['flags']&0x1000 and not section['flags']&(0x20|0x20000000)
            assert not section['relocations'] and selections==[2]
        assert len(definitions)<=1
        return bool(definitions)
    pinned={(ROOT/name).resolve() for group in ['input_sha256','output_sha256'] for name in receipt[group]}
    images={}
    for optimization in receipt['optimizations']:
        compiles=[row for row in executions if row['name'].startswith('compile-') and row['name'].endswith('-'+optimization)]
        assert compiles
        for execution in compiles:
            options=[str(a).upper() for a in execution['command'] if str(a).upper().startswith('/O')]
            assert options.count('/'+optimization.upper())==1
            assert set(options)<={'/'+optimization.upper(),'/OI'},options
        assert verifier.dependency_paths(work/optimization)<=pinned
        opt=work/optimization
        provider_counts=collections.Counter()
        support_objects=[]
        for row in supports:
            obj=opt/('support-'+row['object_stem']+'.obj')
            assert obj.resolve() in pinned
            symbols=verifier.coff.coff_symbols(obj)
            verify_auxiliary(obj)
            assert coffs[optimization]['support_objects'][row['object_stem']]==dict(**symbols,sha256=sha(obj))
            provider_counts.update(symbols['defined_external_symbols'])
            support_objects.append(obj.resolve())
            snapshot=(work/'inputs/support'/row['source']).resolve()
            assert any(any(str(token).lower().endswith('.cpp') and Path(token).resolve() in [snapshot,(ROOT/row['source']).resolve()]
                           for token in execution['command']) for execution in executions),row['source']
        images[optimization]={}
        for name in names:
            obj=opt/(name+'.obj')
            symbols=verifier.coff.coff_symbols(obj)
            assert set(symbols['defined_external_symbols'])==set(cfg['candidate_exports'].values())|set(auxiliary)
            assert verify_auxiliary(obj)
            assert set(symbols['undefined_external_symbols'])==set(cfg['expected_candidate_undefined'])
            assert coffs[optimization][name]==dict(**symbols,sha256=sha(obj))
            all_providers=provider_counts+collections.Counter(symbols['defined_external_symbols'])
            assert all(all_providers[symbol]==1 for symbol in cfg['exports'].values())
            assert all(provider_counts[symbol]==1 for symbol in cfg['expected_candidate_undefined'])
            links=[row for row in executions if row['name']=='link-'+optimization+'-'+name]
            assert len(links)==1
            objects=[Path(token).resolve() for token in links[0]['command'] if str(token).lower().endswith('.obj')]
            expected=[obj.resolve(),*(support_objects),opt.resolve()/cfg.get('entry_object','image_entry.obj')]
            assert collections.Counter(objects)==collections.Counter(expected)
            assert all(path in pinned for path in expected)
            entry=opt/cfg.get('entry_object','image_entry.obj')
            object_sources={obj:work/'sources'/(name+'.cpp'),
                            **{path:ROOT/row['source'] for path,row in zip(support_objects,supports)},
                            entry:work/'sources/image_entry.cpp'}
            certificate=verifier.gate_image(opt/(name+'.exe'),opt/(name+'.map'),
                                           object_sources,executions,work,obj)
            assert certificate==certificates[optimization][name]
            assert certificate['strict_gate'] and certificate['explicit_incremental_no']
            assert {row['compile'] for row in certificate['object_compile_closure']}<=set(row['name'] for row in compiles)
            raw=cache.data(opt/(name+'.exe'));info=verifier.image_info(raw)
            assert info['directories'][1]==info['directories'][5]==(0,0)
            exports=verifier.exports(raw,info)
            assert set(exports)==set(cfg['exports'])
            images[optimization][name]=(raw,exports)

    bounds=[(int(row['va'],16),int(row['va'],16)+row['bytes']) for row in cfg['original_bodies']]
    oracle=verifier.Machine(original,{key:int(value,16) for key,value in cfg['original_symbols'].items()},cfg['cpu_model'],bounds)
    machines={opt:verifier.Machine(*variants['baseline'],cfg['cpu_model']) for opt,variants in images.items()}
    assert all(machine.initialization==oracle.initialization for machine in machines.values())
    assert load(work/'initialization.json')==oracle.initialization
    mutations=load(work/'mutations.json');witnesses={row['case'] for row in mutations}
    expected_cache={};counts=dict(cases=0,events=0,fp_events=0)
    for case,record in zip(scenes,records):
        expected=oracle.run(case)
        # JSON normalizes tuple/list transports, as in the existing498 auditor.
        import json
        assert record==json.loads(json.dumps(dict(case=case['name'],**expected))),case['name']
        for optimization,machine in machines.items():
            assert not verifier.difference(expected,machine.run(case)),(optimization,case['name'])
        if case['name'] in witnesses:expected_cache[case['name']]=expected
        counts['cases']+=1;counts['events']+=expected['event_count'];counts['fp_events']+=expected['fp_event_count']
    assert counts==receipt['case_counts_per_optimization']
    assert len(mutations)==receipt['mutations_detected']==2*len(cfg['mutations'])
    assert {(row['optimization'],row['mutation']) for row in mutations}=={(opt,name) for opt in images for name in names[1:]}
    for row in mutations:
        case=next(case for case in scenes if case['name']==row['case'])
        machine=verifier.Machine(*images[row['optimization']][row['mutation']],cfg['cpu_model'])
        try:changed=verifier.difference(expected_cache[case['name']],machine.run(case))
        except (AssertionError,verifier.UcError) as error:changed=[str(error)]
        assert changed and row['differences']==changed,row
    assert item['cases']==counts['cases']*2
    for path,digest in semantic_pins.items():assert hashlib.sha256(path.read_bytes()).hexdigest()==digest,path
    return dict(kind=receipt['kind'],receipt_sha256=sha(receipt_path),cases=item['cases'],mutations=len(mutations),
                cpu_model=cfg['cpu_model'],events=counts['events']*2,fp_events=counts['fp_events']*2,
                semantic_dependencies_sha256={str(path):digest for path,digest in sorted(semantic_pins.items())},
                support_sources=supports,canonical_data_exports=cfg['data_exports'],
                unchanged_compiled_outputs_replayed=True,native_hardware_verified=False)
