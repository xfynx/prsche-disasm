"""Run 117: prove the canonical install-path owner and startup/exit bridges."""
import argparse
import hashlib
import json
import subprocess
import sys
from pathlib import Path

from v2_source_dependencies import source_hashes

ROOT = Path(__file__).resolve().parents[2]
PACKET = ROOT / 'iterations/v2/001-original-recovery'
RUN = PACKET / 'runs/117-install-integration'
SHA = 'ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
INSTALL_SHA = '30e603756352a84c00d6d6b85a37e8dd19a375b544b318be88a1081a56bf1aae'
SLOTS = [35, 37, 48, 44, 25]
EXPECTED_PATHS = [b'.\\FeData\\movies\\', b'.\\FEData\\art\\',
                  b'.\\SaveData\\', b'.\\FEData\\trackart\\',
                  b'.\\drivers\\']


def invoke(verifier, probe, report_dir):
    subprocess.run([sys.executable, str(ROOT / 'scripts/research' / verifier),
                    '--probe', str(probe), '--report-dir', str(report_dir)],
                   check=True, cwd=ROOT, capture_output=True, text=True, timeout=180)
    return json.loads((report_dir / 'verification.json').read_text(encoding='utf8'))


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--probe', type=Path,
                        default=ROOT / 'local/builds/v2/001-original-recovery/bin/Release/install_paths_integration_probe.exe')
    parser.add_argument('--install-probe', type=Path)
    parser.add_argument('--exit-probe', type=Path)
    parser.add_argument('--report-dir', type=Path, required=True)
    args = parser.parse_args()
    args.report_dir.mkdir(parents=True, exist_ok=True)
    common_bin = args.probe.resolve().parent
    install_probe = args.install_probe or common_bin / 'install_paths_probe.exe'
    exit_probe = args.exit_probe or common_bin / 'process_exit_probe.exe'

    # Re-run the exact x86 differential packages as part of this composed proof.
    install_proof = invoke('verify-v2-install-paths.py', install_probe,
                           args.report_dir / 'install-paths-oracle')
    exit_proof = invoke('verify-v2-process-exit.py', exit_probe,
                        args.report_dir / 'process-exit-oracle')
    real = (ROOT / 'local/game/install.txt').read_bytes()
    raw_sha = hashlib.sha256(real).hexdigest()
    if raw_sha != INSTALL_SHA:
        raise RuntimeError('read-only local/game/install.txt raw SHA mismatch')
    if install_proof.get('native_cpp_equal_original_x86') is not True or \
       exit_proof.get('native_cpp_equal_original_x86') is not True:
        raise RuntimeError('underlying Run 115/116 x86 oracle proof did not pass')
    # The dependency tool hashes text files after CRLF normalization. Keep that
    # normalized-source pin distinct from the byte-exact original fixture SHA.
    normalized_sha = hashlib.sha256(real.decode('utf8').replace('\r\n', '\n').encode('utf8')).hexdigest()
    fixture_source_sha = install_proof['source_sha256'].get('local/game/install.txt')
    if fixture_source_sha != normalized_sha:
        raise RuntimeError('normalized install.txt source pin mismatch')

    request = 'ALIASES\nLOAD {} {}\nCLEAN 1\nCLEAN 0\n'.format(len(real), real.hex())
    request += 'EXIT 0 0\nEXIT 1 305419896\nEXIT 2 2271560481\n'
    lines = subprocess.run([str(args.probe)], input=request, text=True,
                           capture_output=True, check=True, timeout=30).stdout.splitlines()
    rows = [json.loads(line) for line in lines]
    if len(rows) != 7:
        raise RuntimeError(f'integration probe returned {len(rows)} rows, expected 7')
    alias, load, clean1, clean0, *exits = rows
    if alias['op'] != 'ALIASES' or alias['addresses'] != [alias['table_address'] + 4 * s for s in SLOTS]:
        raise AssertionError(f'alias cell addresses do not bind canonical table slots: {alias}')
    if alias['offsets'] != [4 * s for s in SLOTS] or alias['values'] != [0x101, 0x102, 0x103, 0x104, 0x105]:
        raise AssertionError(f'alias read/write does not share exact table cells: {alias}')

    # The integration probe prints null pointers as -1 offsets; the component
    # oracle prints JSON null. Normalize this representation before comparison.
    load['table_offsets'] = [None if offset == -1 else offset for offset in load['table_offsets']]
    table = install_proof['fixtures'][0]['output']
    if table['op'] != 'LOAD' or load['op'] != 'LOAD':
        raise AssertionError('composed startup call did not produce a load result')
    for key in ('blob_offset', 'table_offsets'):
        if load[key] != table[key]:
            raise AssertionError(f'composed loader differs from Run116 x86-verified result at {key}')
    if load['open_path'] != 'install.txt' or load['open_mode'] != 0:
        raise AssertionError(f'startup bridge changed exact open arguments: {load}')
    if sum(value is not None for value in load['table_offsets']) != 49:
        raise AssertionError('composed real install table does not contain 49 entries')
    alias_offsets = [load['table_offsets'][slot] for slot in SLOTS]
    if load['alias_offsets'] != alias_offsets:
        raise AssertionError('named aliases do not observe loaded canonical table values')
    for slot, expected in zip(SLOTS, EXPECTED_PATHS):
        offset = load['table_offsets'][slot]
        if offset is None:
            raise AssertionError(f'original table slot {slot} has an unexpected path')
        suffix = real[offset:]
        delimiter = min((index for index in (suffix.find(b'\r'), suffix.find(b'\n')) if index >= 0),
                        default=len(suffix))
        if suffix[:delimiter] != expected:
            raise AssertionError(f'original table slot {slot} has an unexpected path')

    if clean1 != {'op': 'CLEAN', 'result': 1, 'free_count': 1,
                  'free_offset': 0x1000, 'blob_offset': 0x1000}:
        raise AssertionError(f'non-null cleanup changed its observed behavior: {clean1}')
    if clean0 != {'op': 'CLEAN', 'result': 0, 'free_count': 0,
                  'free_offset': -1, 'blob_offset': -1}:
        raise AssertionError(f'null cleanup changed its observed behavior: {clean0}')
    exit_codes = [0, 305419896, 2271560481]
    for which, (got, code) in enumerate(zip(exits, exit_codes)):
        if got != {'op': 'EXIT', 'terminal': True, 'which': which,
                   'code': code, 'a': 0, 'b': 0}:
            raise AssertionError(f'exit alias {which} did not forward exact shutdown args: {got}')

    dependencies = [
        'iterations/v2/001-original-recovery/runs/117-install-integration/CMakeLists.txt',
        'iterations/v2/001-original-recovery/runs/117-install-integration/README.md',
        'scripts/research/verify-v2-install-integration.py',
        'iterations/v2/001-original-recovery/source/recovered/install_integration_probe.cpp',
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/install_paths.cpp',
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/install_paths_storage.cpp',
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/process_exit.cpp',
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/exit_shutdown.cpp',
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/exit_registry.cpp',
        'iterations/v2/001-original-recovery/source/platform/startup_install_exit_links.cpp',
        'iterations/v2/001-original-recovery/source/include/porsche/install_paths.hpp',
        'iterations/v2/001-original-recovery/source/include/porsche/process_exit.hpp',
        'local/game/install.txt',
    ]
    compiled = [
        'iterations/v2/001-original-recovery/source/recovered/install_integration_probe.cpp',
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/install_paths.cpp',
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/install_paths_storage.cpp',
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/process_exit.cpp',
        'iterations/v2/001-original-recovery/source/platform/startup_install_exit_links.cpp',
    ]
    report = {
        'schema': 1, 'module': 'Porsche.exe', 'sha256': SHA,
        'function_vas': ['004b6ff0', '004b7070', '00556640', '005a246e'],
        'full_function_vas': ['004b6ff0', '004b7070', '00556640', '005a246e'],
        'partial_function_vas': [], 'cases': len(rows),
        'native_cpp_equal_original_x86': True, 'binary_matched': False,
        'game_launch_verified': False,
        'comparison': 'Composes the original install-table owner, startup initializer, cleanup, size leaf, and all known terminal-exit aliases. Full parser and CRT-shutdown behavior are rechecked against their original x86 differential verifiers; this probe compares the exact shared table address relationships and loaded values.',
        'original_fixture': {'path': 'local/game/install.txt', 'raw_sha256': raw_sha,
                             'normalized_source_sha256': normalized_sha,
                             'bytes': len(real), 'entries': 49},
        'aliases': [{'slot': slot, 'original_va': f'{0x65b2a0 + 4 * slot:08x}',
                     'value': expected.decode('ascii')}
                    for slot, expected in zip(SLOTS, EXPECTED_PATHS)],
        'boundaries': {
            '0059d8e0': 'Controlled resource-open fixture returns original bytes and records exact path/mode.',
            '00531f90': 'Controlled free fixture records pointer and observed return value; allocator internals remain outside this packet.',
            'ExitProcess/CRT shutdown': 'Run115 x86 proof plus a terminal exception fixture; no host process is terminated.',
            'install.txt hashes': 'raw_sha256 pins exact local/game bytes; normalized_source_sha256 is the CRLF-normalized source dependency hash.',
        },
        'source_sha256': source_hashes(dependencies, compiled_sources=compiled),
        'probe_sha256': hashlib.sha256(args.probe.read_bytes()).hexdigest(),
        'component_reports': {
            'install_paths': str((args.report_dir / 'install-paths-oracle' / 'verification.json').relative_to(ROOT)),
            'process_exit': str((args.report_dir / 'process-exit-oracle' / 'verification.json').relative_to(ROOT)),
        },
        'fixtures': rows,
    }
    (args.report_dir / 'verification.json').write_text(json.dumps(report, indent=2) + '\n', encoding='utf8')
    print(json.dumps({'cases': len(rows), 'function_vas': report['full_function_vas'],
                      'native_cpp_equal_original_x86': True}))


if __name__ == '__main__':
    main()
