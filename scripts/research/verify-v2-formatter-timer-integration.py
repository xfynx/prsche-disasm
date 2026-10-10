"""Run 121: compose timer signaling, auxiliary event signaling, and formatter helpers."""
import argparse
import hashlib
import json
import subprocess
import sys
from pathlib import Path

from v2_source_dependencies import source_hashes

ROOT = Path(__file__).resolve().parents[2]
PACKET = ROOT / 'iterations/v2/001-original-recovery'
RUN = PACKET / 'runs/121-formatter-timer-integration'
SHA = 'ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'


def verify_component(script, probe, report_dir):
    subprocess.run([sys.executable, str(ROOT / 'scripts/research' / script),
                    '--probe', str(probe), '--report-dir', str(report_dir)],
                   cwd=ROOT, capture_output=True, text=True, check=True, timeout=180)
    return json.loads((report_dir / 'verification.json').read_text(encoding='utf8'))


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--probe', type=Path, required=True)
    parser.add_argument('--timer-probe', type=Path, required=True)
    parser.add_argument('--formatter-probe', type=Path, required=True)
    parser.add_argument('--auxiliary-probe', type=Path, required=True)
    parser.add_argument('--report-dir', type=Path, required=True)
    args = parser.parse_args()
    args.report_dir.mkdir(parents=True, exist_ok=True)

    component_specs = [
        ('verify-v2-timer-setup.py', args.timer_probe, 'timer-setup'),
        ('verify-v2-formatter-original.py', args.formatter_probe, 'formatter-original'),
        ('verify-v2-auxiliary-wait.py', args.auxiliary_probe, 'auxiliary-wait'),
    ]
    proofs = {}
    for script, probe, label in component_specs:
        report = verify_component(script, probe, args.report_dir / label)
        if report.get('native_cpp_equal_original_x86') is not True:
            raise RuntimeError(f'{label} component did not pass its original-x86 differential')
        proofs[label] = report
    expected_counts = {'timer-setup': 9, 'formatter-original': 11,
                       'auxiliary-wait': 3}
    for label, expected in expected_counts.items():
        if proofs[label].get('cases') != expected:
            raise RuntimeError(f'{label} report has unexpected case count')

    requests = ''.join([
        '1 11111111 22222222 0\n',
        '1 00000000 33333333 0\n',
        '1 11111111 00000000 1\n',
    ])
    rows = subprocess.run([str(args.probe)], input=requests, text=True,
                          capture_output=True, check=True, timeout=30).stdout.splitlines()
    actual = [json.loads(line) for line in rows]
    expected = [
        {'case': 'timer_tail', 'worker_event': '0x11111111',
         'auxiliary_event': '0x22222222', 'saved_clock': 0,
         'clock': 4097, 'fraction': 2,
         'signals': ['0x11111111', '0x22222222']},
        {'case': 'timer_tail', 'worker_event': '0x00000000',
         'auxiliary_event': '0x33333333', 'saved_clock': 0,
         'clock': 4097, 'fraction': 2,
         'signals': ['0x33333333']},
        {'case': 'timer_tail', 'worker_event': '0x11111111',
         'auxiliary_event': '0x00000000', 'saved_clock': 1,
         'clock': 4097, 'fraction': 2, 'signals': []},
        {'case': 'formatter_span', 'bytes': '4100ff', 'remaining': 5,
         'emitted': 3, 'tail': 'a0a1a2a3a4a5a6a7a8a9aaabacadaeaf'},
    ]
    if actual != expected:
        raise AssertionError(f'integrated native state/order mismatch: expected={expected}, actual={actual}')

    function_vas = sorted({va for proof in proofs.values()
                           for va in proof.get('full_function_vas', [])})
    expected_vas = sorted(['00564eb0', '00564fa0', '00565030',
                           '005a4ab2', '005a4ae7', '005a4b18',
                           '005a4b50', '005a4b5d', '005a4b6d',
                           '0053c270'])
    if function_vas != expected_vas:
        raise RuntimeError(f'component function set mismatch: {function_vas}')

    compiled = [
        'iterations/v2/001-original-recovery/source/recovered/startup_timing_integration_probe.cpp',
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/timer_setup.cpp',
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/clock_worker.cpp',
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/file_events.cpp',
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/auxiliary_wait.cpp',
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/formatter_original.cpp',
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/shared_runtime_globals.cpp',
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/window_runtime.cpp',
        'iterations/v2/001-original-recovery/source/platform/startup_timer_links.cpp',
    ]
    deps = [
        'iterations/v2/001-original-recovery/CMakeLists.txt',
        'iterations/v2/001-original-recovery/source/recovered/sources.cmake',
        'iterations/v2/001-original-recovery/runs/121-formatter-timer-integration/README.md',
        'iterations/v2/001-original-recovery/runs/121-formatter-timer-integration/CMakeLists.txt',
        'scripts/research/verify-v2-formatter-timer-integration.py',
        'scripts/research/verify-v2-timer-setup.py',
        'scripts/research/verify-v2-formatter-original.py',
        'scripts/research/verify-v2-auxiliary-wait.py',
    ]
    report = {
        'schema': 1, 'module': 'Porsche.exe', 'sha256': SHA,
        'function_vas': expected_vas, 'full_function_vas': expected_vas,
        'partial_function_vas': [], 'cases': len(actual),
        'native_cpp_equal_original_x86': True, 'binary_matched': False,
        'game_launch_verified': False,
        'comparison': 'Three component verifiers execute the accepted timer cluster, six formatter helpers, and auxiliary signal against original x86. The composed probe calls the real timer-producer tail, which signals the canonical worker event and then the canonical auxiliary event through recovered 0055fb30; it separately checks formatter span bytes and opaque descriptor tail. No call edge between timer diagnostics and formatter is claimed.',
        'boundaries': {
            'WinMM': 'Common production bridge maps the recovered timer boundary signatures directly to timeGetDevCaps/timeBeginPeriod/timeSetEvent/timeKillEvent/timeEndPeriod and links winmm. Component oracle fixtures control API outcomes; composed producer-tail cases do not schedule host timers.',
            'diagnostic_handler_005debf0': 'Unknown diagnostic callback remains explicit; the composed probe does not invoke timer setup diagnostic paths and supplies only the existing timer_diagnostic_boundary fixture required to link timer_setup.cpp.',
            'formatter_core_005a4371': 'Parser is not recovered or called; no fake-success parser is included.',
            'formatter_cleanup_005a4259': 'The helper cleanup edge remains a separate typed recording boundary, not an adapter to Run108 cleanup. Composed formatter case stays within output capacity.',
            'live_thread_and_WM_CLOSE': 'No live timer thread or end-to-end WM_CLOSE producer is claimed; those routes remain open.',
        },
        'source_sha256': source_hashes(deps, compiled_sources=compiled),
        'probe_sha256': hashlib.sha256(args.probe.read_bytes()).hexdigest(),
        'component_reports': {label: (args.report_dir / label / 'verification.json').resolve().relative_to(ROOT).as_posix()
                              for _, _, label in component_specs},
        'fixtures': actual,
    }
    (args.report_dir / 'verification.json').write_text(json.dumps(report, indent=2) + '\n', encoding='utf8')
    print(json.dumps({'cases': len(actual), 'full_function_vas': expected_vas,
                      'native_cpp_equal_original_x86': True}))


if __name__ == '__main__':
    main()
