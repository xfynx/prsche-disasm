"""Audit every local executable against its input SHA and v2 export results.

Listing, automatic pseudo-C, recovered source and binary matches are distinct.
No source module is excluded merely because it is a driver/installer/16-bit NE.
"""
import argparse
import hashlib
import json
from pathlib import Path
import re
import struct
import sys

ROOT = Path(__file__).resolve().parents[2]
ITERATION = ROOT / 'iterations/v2/001-original-recovery'
sys.path.insert(0, str(Path(__file__).resolve().parent))
from v2_manual_index import records as manual_records


def load(path):
    return json.loads(path.read_text(encoding='utf-8-sig')) if path.exists() else None


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--require-listing', action='store_true')
    parser.add_argument('--require-decompile-attempts', action='store_true')
    parser.add_argument('--write-verification', action='store_true')
    parser.add_argument('--verification-output', type=Path,
                        default=ITERATION/'runs/012-fe-callbacks/corpus-verification.json',
                        help='Current checkpoint report; historical run hashes are preserved')
    args = parser.parse_args()
    verification_output = args.verification_output if args.verification_output.is_absolute() else ROOT / args.verification_output
    original = ROOT / 'local/game'
    old = load(ROOT / 'research/binary-index/coverage.json')
    known = {entry['sha256']: entry for entry in old['binaries']}
    binaries = {}
    for path in sorted(original.rglob('*')):
        if not path.is_file() or path.suffix.lower() not in ('.exe','.dll','.asi','.ocx'):
            continue
        data = path.read_bytes()
        sha = hashlib.sha256(data).hexdigest()
        relative = path.relative_to(original).as_posix()
        if sha in binaries:
            binaries[sha]['paths'].append(relative)
            continue
        offset = struct.unpack_from('<I',data,0x3c)[0] if data[:2] == b'MZ' and len(data)>=64 else None
        signature = data[offset:offset+4] if offset is not None else b''
        kind = 'PE' if signature == b'PE\0\0' else 'NE' if signature[:2] == b'NE' else 'unknown'
        entry = {'sha256':sha,'paths':[relative],'bytes':len(data),'format':kind,
                 'role':'unclassified','recovered_functions':0,'matched_functions':0,'matched_binary':False}
        if kind == 'PE':
            entry.update(machine=hex(struct.unpack_from('<H',data,offset+4)[0]),
                         coff_timestamp=hex(struct.unpack_from('<I',data,offset+8)[0]),
                         linker_version=f'{data[offset+26]}.{data[offset+27]}',
                         compiler='unconfirmed; linker version alone is insufficient')
        expected = known.get(sha)
        if not expected:
            raise RuntimeError(f'{relative}: SHA is absent from the original inventory; investigate before reuse')
        export = ROOT/'research/v2/binaries'/f'{path.name}-{sha[:12]}'
        listing, decompile = load(export/'listing.json'), load(export/'decompilation.json')
        for record in (listing,decompile):
            if record and record['sha256'] != sha:
                raise RuntimeError(f'{relative}: stale export SHA')
        if listing:
            for name in ('disassembly.asm','functions.jsonl','defined-data.jsonl','unclassified-executable.jsonl'):
                if not (export/name).is_file():
                    raise RuntimeError(f'{relative}: completed listing is missing {name}')
            if sum(1 for _ in (export/'functions.jsonl').open(encoding='utf-8')) != listing['functions']:
                raise RuntimeError(f'{relative}: listing function count mismatch')
        if decompile:
            statuses = [json.loads(line) for line in (export/'decompile-status.jsonl').read_text(encoding='utf-8').splitlines()]
            if len(statuses) != decompile['functions'] or not (export/'decompiled.c').is_file():
                raise RuntimeError(f'{relative}: incomplete decompile output despite completion marker')
            failed = [s for s in statuses if s['status'] in ('failed','timeout')]
            if len(failed) != decompile['failed']:
                raise RuntimeError(f'{relative}: decompile failure count mismatch')
            text = (export/'decompiled.c').read_text(encoding='utf-8')
            bodies = re.split(r'/\* VA [^*]+\*/', text)[1:]
            decompile['warning_functions'] = sum(bool(re.search(r'/\* WARNING:|// WARNING:',body)) for body in bodies)
            decompile['diagnostic_functions'] = sum(bool(s.get('message')) for s in statuses)
            entry['decompile_failures'] = failed
        entry['export_directory'] = export.relative_to(ROOT).as_posix()
        entry['original_analysis'] = expected.get('ghidra',{})
        entry['listing'] = listing or {'status':'not-exported'}
        entry['automatic_decompilation'] = decompile or {'status':'not-exported'}
        binaries[sha] = entry
    manual = manual_records()
    manual_addresses = {}
    for record in manual:
        manual_addresses.setdefault(record['sha256'], set()).add(record['entry_va'].lower())
    recovered = load(ITERATION/'source/recovered/functions.json') or {'functions': []}
    seen = set()
    for function in recovered['functions']:
        key = (function['sha256'], function['entry_va'])
        if key in seen or key[0] not in binaries:
            raise RuntimeError(f'Duplicate or unknown recovered function: {key}')
        seen.add(key)
        source = ROOT/function['source']
        if not source.is_file():
            raise RuntimeError(f'Recovered source is missing: {source}')
        entry = binaries[key[0]]
        indexed = {json.loads(line)['entry_va'].lower() for line in
                   (ROOT/entry['export_directory']/'functions.jsonl').read_text(encoding='utf8').splitlines()}
        indexed.update(manual_addresses.get(key[0], set()))
        if key[1].lower() not in indexed:
            raise RuntimeError(f'Recovered function is absent from corpus: {key}')
        if function['status'] == 'native-differential-verified':
            verification = load(ROOT/function['verification_report'])
            source_sha = hashlib.sha256(source.read_bytes().replace(b'\r\n', b'\n')).hexdigest()
            verified_vas = verification.get('function_vas', [verification.get('function_va')]) if verification else []
            if not verification or verification['sha256'] != key[0] or key[1] not in verified_vas or not verification['native_cpp_equal_original_x86'] or verification['source_sha256'].get(function['source']) != source_sha:
                raise RuntimeError(f'Missing/stale native verification: {key}')
            for relative, expected_sha in verification['source_sha256'].items():
                dependency = ROOT/relative
                if not dependency.is_file() or hashlib.sha256(dependency.read_bytes().replace(b'\r\n', b'\n')).hexdigest() != expected_sha:
                    raise RuntimeError(f'Stale verified source dependency: {relative}')
            entry['recovered_functions'] += 1
        if function.get('binary_matched'):
            raise RuntimeError('Binary-match evidence validation has not been implemented; do not count unchecked claims')
    automatic_addresses = {}
    for sha, entry in binaries.items():
        export_functions = ROOT / entry['export_directory'] / 'functions.jsonl'
        automatic_addresses[sha] = {json.loads(line)['entry_va'].lower() for line in
                                    export_functions.read_text(encoding='utf-8').splitlines()}
        entry['supplementary_functions'] = []
    for record in manual:
        sha = record['sha256']
        if sha not in binaries:
            raise RuntimeError(f'Manual function references unknown binary SHA: {sha}')
        address = record['entry_va'].lower()
        if address in automatic_addresses[sha]:
            raise RuntimeError(f'Manual function overlaps automatic catalog: {(sha, address)}')
        binaries[sha]['supplementary_functions'].append({
            'entry_va': record['entry_va'], 'name': record['name'],
            'status': record['status'], 'reason': record['reason'],
            'body_bytes': record['body_bytes'], 'ranges': record['ranges'],
        })
    for entry in binaries.values():
        entry['supplementary_function_count'] = len(entry['supplementary_functions'])
    entries = list(binaries.values())
    listing_done = sum(bool(e['listing'].get('complete_listing_of_analyzed_instructions')) for e in entries)
    decompile_done = sum(bool(e['automatic_decompilation'].get('attempted_all_functions')) for e in entries)
    counts = {'input_paths':sum(len(e['paths']) for e in entries),'unique_modules':len(entries),
              'listing_modules':listing_done,'decompile_attempted_modules':decompile_done,
              'instructions':sum(e['listing'].get('instructions',0) for e in entries),
              'analyzed_functions':sum(e['listing'].get('functions',0) for e in entries),
              'unclassified_executable_bytes':sum(e['listing'].get('unclassified_executable_bytes',0) for e in entries),
              'automatic_pseudo_c_functions':sum(e['automatic_decompilation'].get('pseudo_c_functions',0) for e in entries),
              'supplementary_manual_functions':sum(e['supplementary_function_count'] for e in entries),
              'indexed_functions':sum(e['listing'].get('functions',0) for e in entries) + sum(e['supplementary_function_count'] for e in entries),
              'decompile_failures':sum(e['automatic_decompilation'].get('failed',0) for e in entries),
              'pseudo_c_warning_functions':sum(e['automatic_decompilation'].get('warning_functions',0) for e in entries),
              'recovered_functions':sum(e['recovered_functions'] for e in entries),
              'matched_functions':0,'matched_modules':0}
    output = {'schema':1,'snapshot_date':'2026-10-09','generation':'v2',
              'v1_checkpoint':'dc6b9d8','original_data':'local/game (read-only)',
              'reference_method':'matching source recovery; native Windows/x86 baseline before portable adaptation',
              'counts':counts,'binaries':entries,
              'boundary':'Exported instructions and automatic pseudo-C are not complete code discovery or compilable recovered source.'}
    target = ITERATION/'reference/binaries.json'
    target.parent.mkdir(parents=True,exist_ok=True)
    target.write_text(json.dumps(output,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps(counts))
    if args.require_listing and listing_done != len(entries):
        raise SystemExit('Missing full listings; inspect reference/binaries.json')
    if args.require_decompile_attempts and decompile_done != len(entries):
        raise SystemExit('Missing decompilation attempts; inspect reference/binaries.json')
    if args.write_verification:
        if listing_done != len(entries) or decompile_done != len(entries):
            raise SystemExit('Cannot record complete export verification before every module is attempted')
        hashes = {}
        paths = list((ROOT/'research/v2/binaries').rglob('*')) + [target]
        paths += [ROOT/p for p in ('scripts/research/export-v2.ps1',
                  'scripts/research/inventory-v2.py','scripts/research/ghidra/ExportRecoveryCorpus.java',
                  'scripts/build-v2.ps1','scripts/research/structure-v2.py',
                  'scripts/research/trace-v2-startup.py','scripts/research/verify-v2-startup.py',
                  'scripts/research/export-v2-fe-tables.py','scripts/research/verify-v2-fe-stream.py',
                  'scripts/research/verify-v2-heap.py')]
        paths += [ROOT/'scripts/research/v2_manual_index.py', ROOT/'scripts/research/verify-v2-files.py', ROOT/'scripts/research/verify-v2-file-device.py', ROOT/'research/binary-index/manual-functions.jsonl']
        run005 = ITERATION/'runs/005-original-files'
        if run005.exists():
            paths += [path for path in run005.rglob('*') if path.resolve() != verification_output.resolve()]
        paths += [path for path in (ITERATION/'runs/006-file-device').rglob('*') if path.resolve() != verification_output.resolve()]
        paths += [ROOT/'scripts/research/index-v2-worker.py', ROOT/'scripts/research/verify-v2-file-worker.py']
        paths += [path for path in (ITERATION/'runs/007-file-worker').rglob('*') if path.resolve() != verification_output.resolve()]
        paths += [ROOT/'scripts/research/verify-v2-file-wait.py']
        paths += [path for path in (ITERATION/'runs/008-file-scheduler').rglob('*') if path.resolve() != verification_output.resolve()]
        paths += [ROOT/'scripts/research/verify-v2-file-events.py', ROOT/'scripts/research/index-binaries.py', ROOT/'scripts/research/test_index_binaries.py', ROOT/'research/binary-index/static/imports.jsonl']
        paths += [path for path in (ITERATION/'runs/009-file-events').rglob('*') if path.resolve() != verification_output.resolve()]
        paths += [ROOT/'scripts/research/index-v2-threads.py', ROOT/'scripts/research/verify-v2-file-threads.py']
        paths += [path for path in (ITERATION/'runs/010-file-threads').rglob('*') if path.resolve() != verification_output.resolve()]
        paths += [ROOT/'scripts/research/verify-v2-file-disk.py', ROOT/'scripts/research/verify-v2-fe-callbacks.py']
        for run_name in ('011-file-disk','012-fe-callbacks'):
            paths += [path for path in (ITERATION/'runs'/run_name).rglob('*') if path.resolve() != verification_output.resolve()]
        # Pending parallel work is excluded until its dependency hashes are accepted.
        paths += list((ITERATION/'source/catalog').rglob('*'))
        paths += [ITERATION/'source/recovered/functions.json', ITERATION/'source/recovered/sources.cmake']
        for report_path in sorted({f['verification_report'] for f in recovered['functions']}):
            paths += [ROOT/p for p in load(ROOT/report_path)['source_sha256']]
        paths += [ITERATION/'CMakeLists.txt', ITERATION/'reference/startup.json']
        paths += [ROOT/p for p in sorted({f['verification_report'] for f in recovered['functions']})]
        paths += [ITERATION/'runs/003-fe-stream'/name for name in
                  ('tables.json', 'resource-inventory.json', 'source-functions.jsonl', 'source-calls.jsonl')]
        paths += [ITERATION/'runs/004-original-heap'/name for name in
                  ('source-functions.jsonl', 'source-calls.jsonl', 'heap-table-references.jsonl', 'toolchain.json', 'globals.json')]
        for path in sorted(paths):
            if path.is_file():
                data = path.read_bytes()
                source_script = path.relative_to(ROOT).as_posix().startswith('scripts/')
                if source_script:
                    data = data.replace(b'\r\n', b'\n')
                hashes[path.relative_to(ROOT).as_posix()] = {
                    'bytes':len(data),'sha256':hashlib.sha256(data).hexdigest(),
                    'hash_text_normalization':'CRLF to LF' if source_script else 'none; corpus stored as LF'}
        verification = {'schema':1,'date':'2026-10-09','counts':counts,
            'original_input_hashes_verified':True,'all_listing_files_present':True,
            'all_function_status_counts_verified':True,'ghidra':'12.1.3',
            'pe_export':'cached analyzed project, noanalysis/readOnly',
            'ne_export':'separate NeLoader project, subsequent readOnly decompile',
            'exporter_compilation_check':'drvmgt.dll full listing succeeded after SHA/resume guards',
            'new_v2_game_executable':False,'recovered_compilable_source':counts['recovered_functions'] > 0,
            'original_native_behavior_acceptance':False,'files':hashes,
            'limitations':['Automatic pseudo-C is not recovered compilable source.',
                'Four functions failed/timed out; details remain in the manifest.',
                'Warnings and unclassified executable bytes remain unresolved.',
                'Exact original compiler/CRT/flags/layout are not confirmed.']}
        verification_output.parent.mkdir(parents=True,exist_ok=True)
        verification_output.write_text(json.dumps(verification,indent=2)+'\n',encoding='utf-8',newline='\n')


if __name__ == '__main__':
    main()
