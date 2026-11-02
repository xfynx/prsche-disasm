"""Read-only acceptance for config-driven original/native subsystem batches."""
import argparse
import collections
import functools
import hashlib
import importlib.util
import json
from pathlib import Path
import re
import struct
import subprocess
import sys
from v2_shared_manifests import ManifestReader

ROOT = Path(__file__).resolve().parents[2]


@functools.lru_cache(maxsize=1)
def legacy_native_runner():
    # Frozen tool input before optional SDK libraries; never substitute source inputs.
    return subprocess.check_output(
        ['git', 'cat-file', 'blob', '0733c15bb343c2043d6e3f642e82bc40b26dccde'], cwd=ROOT)


def module(name, path):
    spec = importlib.util.spec_from_file_location(name, path)
    value = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(value)
    return value


def audit_import_thunk(data, symbol, imported):
    """Prove a platform adapter is only JMP [the original Win32 import]."""
    machine, sections, _, table, count, optional, _ = struct.unpack_from('<HHIIIHH', data)
    assert machine == 0x14c and optional == 0
    strings = table + count * 18

    def name(index):
        offset = table + index * 18
        raw = data[offset:offset + 8]
        if raw[:4] == b'\0' * 4:
            start = strings + struct.unpack_from('<I', raw, 4)[0]
            return data[start:data.index(b'\0', start)].decode('ascii')
        return raw.rstrip(b'\0').decode('ascii')

    entries = []
    index = 0
    while index < count:
        offset = table + index * 18
        if name(index) == symbol:
            entries.append(struct.unpack_from('<Ih', data, offset + 8))
        index += 1 + data[offset + 17]
    assert len(entries) == 1
    value, section = entries[0]
    assert 1 <= section <= sections
    offset = 20 + (section - 1) * 40
    size, raw, relocations = struct.unpack_from('<III', data, offset + 16)
    relocation_count = struct.unpack_from('<H', data, offset + 32)[0]
    code = data[raw + value:raw + size]
    assert code == b'\xff\x25\0\0\0\0' and relocation_count == 1
    address, target, kind = struct.unpack_from('<IIH', data, relocations)
    assert address == value + 2 and kind == 6 and name(target) == imported
    return code.hex()


def audit_native(cfg, cache, sha):
    load = cache.document
    native_cfg = load(ROOT / cfg['native_config'])
    native = load(ROOT / cfg['native_receipt'])
    assert native['status'] == 'PASS'
    assert native['config'] == cfg['native_config']
    assert native['original_sha256'] == native_cfg['original_sha256']
    for group in ('inputs_sha256', 'outputs_sha256'):
        assert native[group], group
        for name, expected in native[group].items():
            actual = sha(ROOT / name)
            if (group == 'inputs_sha256' and actual != expected
                    and name == 'scripts/research/verify-v2-native-batch.py'
                    and expected == '9c53c1110f9094449e59c72a2d08f076f796a553a3500a43d978267c72169e98'):
                actual = hashlib.sha256(legacy_native_runner()).hexdigest()
            assert actual == expected, f'{group}: {name}'
    pe = cache.data(ROOT / native_cfg['original_pe'])
    assert hashlib.sha256(pe).hexdigest() == native_cfg['original_sha256']
    utility = module('native_batch_pe', ROOT / 'scripts/research/verify-v2-native-batch.py')
    assert native['original_bodies'] == native_cfg['original_bodies']
    for body in native['original_bodies']:
        data = utility.pe_at(pe, int(body['va'], 16), body['bytes'])
        assert hashlib.sha256(data).hexdigest() == body['sha256']
    assert set(native['variants']) == {'od', 'o2'}
    mutations = {item['name']: item for item in native_cfg['mutations']}
    assert {item['name'] for item in native['mutation_controls']} == set(mutations)
    for item in native['mutation_controls']:
        assert item['detected'] and item['exit_code'] == mutations[item['name']].get('expected_exit', 10)
    for name, receipt in native['receipts'].items():
        expected = next((item.get('expected_exit', 10) for key, item in mutations.items()
                         if name == f'mutation-{key}-native'), 0)
        assert receipt['exit_code'] == expected, name
        assert sha(ROOT / receipt['log']) == receipt['log_sha256'], name
    total_cases = 0
    for variant, result in native['variants'].items():
        receipt = native['receipts'][f'{variant}-native']
        output = cache.data(ROOT / receipt['log']).decode('utf8')
        assert native_cfg['pass_marker'] in output
        case_marker = re.search(r'\bcases=(\d+)\b', output)
        assert case_marker, 'native result must report its measured case count'
        total_cases += int(case_marker.group(1))
        assert result['output_sha256'] == receipt['log_sha256']
    assert total_cases == cfg['native_cases']
    dependencies = module('native_batch_dependencies', ROOT / 'scripts/research/audio_recovery_provenance.py')
    paths = dependencies.dependency_paths(ROOT / native['attempt_dir'])
    pinned = {(ROOT / name).resolve() for name in native['inputs_sha256']}
    assert paths <= pinned, 'compiler dependency closure not pinned'

    result = dict(cases=cfg['native_cases'], mutations=len(mutations),
                  receipt_sha256=sha(ROOT / cfg['native_receipt']))
    reused = []
    for proof in cfg.get('reused_chains', []):
        path = ROOT / proof['auditor']
        assert sha(path) == proof['auditor_sha256']
        verifier = module('native_batch_reused_chain', path)
        work = ROOT / proof['work']
        assert sha(work / 'receipt.json') == proof['receipt_sha256']
        receipt = verifier.audit_receipt(work)
        verifier.cache.check_stable()
        assert receipt['native_cases_passed'] == proof['cases']
        for body in proof['original_bodies']:
            assert utility.pe_at(pe, int(body['va'], 16), body['bytes']) == cache.data(work / body['file'])
        reused.append(dict(cases=proof['cases'], receipt_sha256=proof['receipt_sha256'], rerun=False))
    if reused:
        result['reused_chains'] = reused
    return result


def audit_source_changes(old_sources, sources, added_sources, replaced_sources=None,
                         native_sources=()):
    """Allow only declared additions and explicitly proved one-for-one replacements."""
    old_sources, sources = set(old_sources), set(sources)
    additions = set(added_sources)
    assert len(additions) == len(added_sources), 'duplicate added source'
    replacements = {} if replaced_sources is None else replaced_sources
    assert isinstance(replacements, dict), 'replaced_sources must map old paths to new paths'
    assert all(isinstance(old, str) and isinstance(new, str)
               for old, new in replacements.items()), 'invalid replacement path'
    assert old_sources - sources == set(replacements), 'unlisted or ineffective source removal'
    assert sources - old_sources == additions, 'unexpected added source'
    targets = set(replacements.values())
    assert len(targets) == len(replacements), 'replacement targets must be unique'
    assert targets <= additions, 'replacement target must be a new compiler input'
    assert targets <= set(native_sources), 'replacement target lacks a passed native packet'
    return replacements


def audit_game_source_names(sources, original_probe_sources=()):
    # Original game audio probes are legitimate recovered code. Exceptions must
    # name exact compiler inputs; fixture inputs remain forbidden unconditionally.
    allowed = set(original_probe_sources)
    assert len(allowed) == len(original_probe_sources), 'duplicate original probe source'
    assert allowed <= set(sources), 'original probe is not a compiler input'
    assert all('probe' in Path(p).name.lower() for p in allowed)
    assert not any('fixture' in p.lower() for p in sources)
    assert not any('probe' in Path(p).name.lower() and p not in allowed for p in sources)


def audit_emulated(item, cache, sha):
    """Admit an explicit original/compiled-C++ emulator proof, never as native."""
    load = cache.document
    cfg_path, receipt_path = ROOT / item['config'], ROOT / item['receipt']
    cfg, receipt = load(cfg_path), load(receipt_path)
    assert receipt['status'] == 'PASS'
    assert receipt['kind'] == 'emulated-original-vs-emulated-compiled-cpp'
    assert receipt['optimizations'] == ['Od', 'O2']
    assert receipt['cpu_model'] == cfg['cpu_model'] == 11
    for group in ('input_sha256', 'output_sha256'):
        assert receipt[group]
        for path, expected in receipt[group].items():
            assert sha(ROOT / path) == expected, path
    verifier_path = ROOT / item['verifier']
    assert receipt['input_sha256'][item['verifier']] == sha(verifier_path)
    assert receipt['input_sha256'][item['config']] == sha(cfg_path)
    verifier = module('emulated_batch_verifier', verifier_path)
    assert verifier.RUN == cfg_path.parent
    work = receipt_path.parent
    for filename in (cfg['source'], cfg['header'], 'config.json', 'compare.py'):
        assert cache.data(work / 'inputs' / filename) == cache.data(cfg_path.parent / filename)
    original = cache.data(ROOT / cfg['original_pe'])
    assert sha(ROOT / cfg['original_pe']) == receipt['original_sha256'] == cfg['original_sha256']
    for row in cfg['original_bodies']:
        assert hashlib.sha256(verifier.native.pe_at(original, int(row['va'], 16), row['bytes'])).hexdigest() == row['sha256']

    # The pilot pinned the engine DLL but not every Python binding/disassembler
    # module. Replay unchanged compiled outputs once under this complete semantic
    # dependency snapshot; no recompilation or native-hardware claim follows.
    package_roots = [Path(package.__file__).resolve().parent
                     for package in (verifier.unicorn, verifier.capstone)]
    dependencies = {Path(sys.executable).resolve(), Path(__file__).resolve()}
    for imported in tuple(sys.modules.values()):
        filename = getattr(imported, '__file__', None)
        if filename:
            path = Path(filename).resolve()
            if path.is_file() and any(path.is_relative_to(root) for root in package_roots):
                dependencies.add(path)
    for root in package_roots:
        dependencies.update(root.rglob('*.py'))
        dependencies.update(root.rglob('*.dll'))
        dependencies.update(root.rglob('*.so'))
    dependency_pins = {path: sha(path) for path in dependencies}
    assert verifier.unicorn.__version__ == receipt['unicorn_version']
    assert list(verifier.unicorn.uc_version()) == receipt['unicorn_core_version']
    executions = load(work / 'executions.json')
    for execution in executions:
        assert execution['exit_code'] == 0
        assert sha(work / (execution['name'] + '.log')) == execution['log_sha256']
    scenes, records = load(work / 'cases.json'), load(work / 'comparisons.json')
    assert scenes == verifier.cases() and len(scenes) == len(records)
    names = ['baseline'] + [entry['name'] for entry in cfg['mutations']]
    assert len(names) == len(set(names))
    assert receipt['variants_per_optimization'] == len(names)
    coffs = load(work / 'coff.json')
    images = {}
    pinned = {(ROOT / path).resolve() for group in ('input_sha256', 'output_sha256')
              for path in receipt[group]}
    for optimization in receipt['optimizations']:
        assert verifier.dependency_paths(work / optimization) <= pinned
        images[optimization] = {}
        for name in names:
            obj = work / optimization / (name + '.obj')
            symbols = verifier.coff.coff_symbols(obj)
            assert not symbols['undefined_external_symbols']
            assert set(symbols['defined_external_symbols']) == set(cfg['exports'].values())
            assert coffs[optimization][name] == dict(**symbols, sha256=sha(obj))
            raw = cache.data(work / optimization / (name + '.exe'))
            info = verifier.image_info(raw)
            assert info['directories'][1] == info['directories'][5] == (0, 0)
            exports = verifier.exports(raw, info)
            assert set(exports) == set(cfg['exports'])
            images[optimization][name] = (raw, exports)
    bounds = [(int(row['va'], 16), int(row['va'], 16) + row['bytes']) for row in cfg['original_bodies']]
    oracle = verifier.Machine(original, {row['name']: int(row['va'], 16) for row in cfg['original_bodies']}, cfg['cpu_model'], bounds)
    machines = {opt: verifier.Machine(*variants['baseline'], cfg['cpu_model']) for opt, variants in images.items()}
    expected_cache, counts = {}, dict(cases=0, events=0, fp_events=0)
    for case, record in zip(scenes, records):
        expected = oracle.run(case)
        assert record == json.loads(json.dumps(dict(case=case['name'], **expected))), case['name']
        for optimization, machine in machines.items():
            assert not verifier.difference(expected, machine.run(case)), (optimization, case['name'])
        if case['group'] in ('count', 'alias'):
            expected_cache[case['name']] = expected
        counts['cases'] += 1
        counts['events'] += expected['event_count']
        counts['fp_events'] += expected['fp_event_count']
    assert counts == receipt['case_counts_per_optimization']
    mutation_records = load(work / 'mutations.json')
    assert len(mutation_records) == receipt['mutations_detected'] == 2 * len(cfg['mutations'])
    expected_pairs = {(opt, name) for opt in images for name in names[1:]}
    assert {(row['optimization'], row['mutation']) for row in mutation_records} == expected_pairs
    for row in mutation_records:
        case = next(case for case in scenes if case['name'] == row['case'])
        machine = verifier.Machine(*images[row['optimization']][row['mutation']], cfg['cpu_model'])
        try:
            changed = verifier.difference(expected_cache[case['name']], machine.run(case))
        except (AssertionError, verifier.UcError) as error:
            changed = [str(error)]
        assert changed and row['differences'] == changed, row
    assert item['cases'] == counts['cases'] * 2
    for path, expected in dependency_pins.items():
        assert hashlib.sha256(path.read_bytes()).hexdigest() == expected, path
    return dict(kind=receipt['kind'], receipt_sha256=sha(receipt_path),
                cases=item['cases'], mutations=len(mutation_records), cpu_model=cfg['cpu_model'],
                events=counts['events'] * 2, fp_events=counts['fp_events'] * 2,
                semantic_dependencies_sha256={str(path): value for path, value in sorted(dependency_pins.items())},
                unchanged_compiled_outputs_replayed=True, native_hardware_verified=False)


def audit(config_path):
    reader = ManifestReader(ROOT)
    cache = reader.cache
    load = cache.document
    hashes = {}

    def sha(path):
        path = Path(path).resolve()
        if path not in hashes:
            hashes[path] = hashlib.sha256(cache.data(path)).hexdigest()
        return hashes[path]

    cfg = load(config_path)
    batches = cfg.get('native_batches', [cfg])
    native_proofs = [audit_native(item, cache, sha) for item in batches]
    assert sum(item['cases'] for item in native_proofs) == cfg['native_cases']
    emulated_proofs = [audit_emulated(item, cache, sha) for item in cfg.get('emulated_batches', [])]
    assert sum(item['cases'] for item in emulated_proofs) == cfg.get('emulated_cases', 0)

    rea_module = module('native_batch_rea', ROOT / 'scripts/research/audit-v2-rea-session.py')
    rea = [rea_module.audit(ROOT / item['config'], item['attempt'], cache, sha)
           for item in cfg['rea_sessions']]
    for name, expected in cfg['evidence_sha256'].items():
        assert sha(ROOT / name) == expected, name
    build_cfg = load(ROOT / cfg['build_config'])
    run, build = ROOT / build_cfg['run'], ROOT / build_cfg['build']
    current_path = run / f"build-{cfg['build_attempt']}.json"
    current, baseline = load(current_path), load(ROOT / cfg['baseline'])
    _, pins = reader.verify(current, 'source', expected_hash_mode='crlf-to-lf')
    assert current['input_unchanged'] and not current['compiler_errors'] and not current['other_linker_errors']
    old_sources, sources = set(baseline['compiled_source_roots']), set(current['compiled_source_roots'])
    replacements = cfg.get('replaced_sources', {})
    native_sources = set()
    if replacements:
        for item in batches:
            native_sources.update(load(ROOT / item['native_config'])['sources'])
    audit_source_changes(old_sources, sources, cfg['added_sources'], replacements, native_sources)
    assert current['source_count'] == len(sources)
    assert collections.Counter(Path(p).name for p in current['project_paths']) == collections.Counter(
        Path(p).name for p in baseline['project_paths'])
    audit_game_source_names(sources, cfg.get('original_probe_sources', ()))
    assert sha(ROOT / current['receipt']) == current['receipt_sha256']
    receipt = load(ROOT / current['receipt'])
    assert sha(ROOT / receipt['log']) == receipt['log_sha256']
    compiler_events = re.findall(r'(?m)^\s+([A-Za-z0-9_.-]+\.cpp)\s*$', cache.data(ROOT / receipt['log']).decode('utf8'))
    assert collections.Counter(compiler_events) == collections.Counter(Path(p).name for p in sources)
    before, after = ({item['symbol'] for item in report['frontier']} for report in (baseline, current))
    assert before - after == set(cfg['expected_closed_names'])
    assert after - before == set(cfg['expected_new_names'])
    assert current['unresolved_names'] == len(after)
    assert current['unresolved_references'] == sum(len(item['references']) for item in current['frontier'])
    assert current['exit_code'] == receipt['exit_code'] == (1 if after else 0)
    assert current['game_executed'] is False and bool(current['executable']) == (not after)
    coff = module('native_batch_coff', ROOT / 'scripts/research/build-v2-compile-corpus.py')
    definitions = collections.defaultdict(list)
    for path in build.glob('**/*.obj'):
        for symbol in coff.coff_symbols(path)['defined']:
            definitions[symbol].append(path.relative_to(build).as_posix())
    for symbol, owner in cfg['canonical_providers'].items():
        assert len(definitions[symbol]) == 1, symbol
        actual = definitions[symbol][0]
        # CMake disambiguates equal source basenames into different object paths.
        assert (actual == owner if '/' in owner else Path(actual).name == owner), symbol
    for symbol in cfg['expected_new_names']:
        assert not definitions[symbol], f'fabricated provider: {symbol}'
    platform = []
    for thunk in cfg.get('platform_import_thunks', []):
        candidates = list(build.glob('**/' + thunk['object']))
        assert len(candidates) == 1
        path = candidates[0]
        view = coff.coff_symbols(path)
        assert view['defined'] == [thunk['symbol']] and view['undefined'] == [thunk['import_symbol']]
        code = audit_import_thunk(cache.data(path), thunk['symbol'], thunk['import_symbol'])
        imports = [json.loads(line) for line in cache.data(ROOT / thunk['index']).decode('utf8').splitlines()]
        assert thunk['original_import'] in imports
        platform.append(dict(symbol=thunk['symbol'], import_symbol=thunk['import_symbol'],
                             code=code, object_sha256=sha(path), original_import=thunk['original_import']))
    graph = module('native_batch_graph', ROOT / 'scripts/research/v2_build_graph.py')
    entries = list(build.glob('**/porsche_original_game_link.vcxproj'))
    assert len(entries) == 1
    assert graph.compiled_sources(entries[0].parent, 'porsche_original_game_link') == current['compiled_source_roots']
    cache.check_stable()
    result = dict(schema=1, passed=True, native_cases=cfg['native_cases'],
                mutations=sum(item['mutations'] for item in native_proofs),
                rea=rea, source_pins=len(pins), game_sources=len(sources),
                build_sha256=sha(current_path), unresolved_names=len(after),
                unresolved_references=current['unresolved_references'],
                closed_names=sorted(before - after), new_names=sorted(after - before),
                canonical_providers=cfg['canonical_providers'], game_executed=False,
                executable=current['executable'])
    if 'native_batches' in cfg:
        result['native_proofs'] = native_proofs
    else:
        result['native_receipt_sha256'] = native_proofs[0]['receipt_sha256']
    if platform:
        result['platform_import_thunks'] = platform
    if cfg.get('original_probe_sources'):
        result['original_probe_sources'] = sorted(cfg['original_probe_sources'])
    if replacements:
        result['replaced_sources'] = replacements
    if emulated_proofs:
        result.update(emulated_proofs=emulated_proofs,
                      emulated_cases=sum(item['cases'] for item in emulated_proofs),
                      emulated_mutations=sum(item['mutations'] for item in emulated_proofs))
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--config', type=Path, required=True)
    args = parser.parse_args()
    result = audit(args.config.resolve())
    output = args.config.parent / 'validation.json'
    if output.exists():
        assert json.loads(output.read_bytes()) == result, 'completed audit changed'
    else:
        output.write_text(json.dumps(result, indent=2) + '\n', encoding='utf8', newline='\n')
    print(json.dumps({key: result[key] for key in ('passed', 'native_cases', 'mutations', 'game_sources',
                                                  'source_pins', 'unresolved_names', 'unresolved_references')}))


if __name__ == '__main__':
    main()
