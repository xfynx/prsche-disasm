"""Verify the original import edges and actual disposable-child OS termination."""
import argparse
import hashlib
import json
from pathlib import Path
import subprocess

from v2_source_dependencies import source_hashes

ROOT = Path(__file__).resolve().parents[2]
SHA = 'ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
EDGES = [('005a24a5', '005b2094', 'GetCurrentProcess'),
         ('005a24ac', '005b216c', 'TerminateProcess'),
         ('005a252d', '005b21a8', 'ExitProcess')]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--probe', type=Path, required=True)
    parser.add_argument('--report-dir', type=Path, required=True)
    args = parser.parse_args()
    output = args.report_dir.resolve()/'verification.json'
    tracked = subprocess.check_output(['git', 'ls-files'], cwd=ROOT, text=True).splitlines()
    if output.relative_to(ROOT).as_posix() in tracked:
        raise RuntimeError('Use a fresh report directory; committed proof is immutable')
    original = (ROOT/'local/game/Porsche.exe').read_bytes()
    assert hashlib.sha256(original).hexdigest() == SHA
    module_path = ROOT/'research/binary-index/static/binaries.jsonl'
    import_path = ROOT/'research/binary-index/static/imports.jsonl'
    module = next(v for v in map(json.loads, module_path.read_text().splitlines())
                  if v['path'] == 'Porsche.exe')
    imports = [v for v in map(json.loads, import_path.read_text().splitlines())
               if v['path'] == 'Porsche.exe']
    image_base = int(module['image_base'], 0)
    evidence = []
    for call, iat, symbol in EDGES:
        matches = [v for v in imports if v['symbol'] == symbol]
        assert len(matches) == 1 and matches[0]['dll'].upper() == 'KERNEL32.DLL'
        assert image_base+int(matches[0]['iat_rva'], 0) == int(iat, 16)
        rva = int(call, 16)-image_base
        section = next(s for s in module['sections'] if s['rva'] <= rva < s['rva']+s['raw_size'])
        offset = section['raw_offset']+rva-section['rva']
        encoded = b'\xff\x15'+int(iat, 16).to_bytes(4, 'little')
        assert original[offset:offset+6] == encoded
        evidence.append(dict(call_va=call, iat_va=iat, import_name=symbol, bytes=encoded.hex()))
    cases = []
    for mode in ('exit', 'terminate-self'):
        for code in (0, 0x12345678, 0x87654321):
            result = subprocess.run([str(args.probe.resolve()), mode, hex(code)],
                                    capture_output=True, text=True, timeout=10,
                                    creationflags=subprocess.CREATE_NO_WINDOW)
            actual = result.returncode & 0xffffffff
            assert actual == code, (mode, code, actual, result.stderr)
            expected = 'exit' if mode == 'exit' else 'handle:4294967295'
            assert result.stdout.strip() == expected, result.stdout
            cases.append(dict(mode=mode, requested_code=code, observed_code=actual,
                              output=result.stdout.strip(), terminal_call_verified=True))
    packet = ROOT/'iterations/v2/001-original-recovery/runs/125-native-shutdown'
    tu = ROOT/'iterations/v2/001-original-recovery/source/platform/win32_shutdown.cpp'
    dependencies = [Path(__file__), packet/'README.md', packet/'CMakeLists.txt']
    report = dict(schema=1, kind='native OS binding acceptance; not original-function recovery',
                  module='Porsche.exe', sha256=SHA, function_vas=[], full_function_vas=[],
                  native_cpp_equal_original_x86=False, original_import_edges_verified=True,
                  native_fixture_passed=True, cases=len(cases), fixtures=cases, evidence=evidence,
                  source_sha256=source_hashes(dependencies, compiled_sources=[tu, packet/'native_shutdown_probe.cpp']),
                  original_index_sha256={p.relative_to(ROOT).as_posix(): hashlib.sha256(p.read_bytes()).hexdigest()
                                         for p in (module_path, import_path)},
                  probe_sha256=hashlib.sha256(args.probe.read_bytes()).hexdigest(),
                  game_launch_verified=False, full_crt_shutdown_verified=False,
                  limitations=['CRT callbacks and locks remain outside this OS fixture.',
                               'WM_CLOSE and original game startup are still open.'])
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_bytes((json.dumps(report, indent=2)+'\n').encode())
    print(json.dumps(dict(native_fixture_passed=True, cases=len(cases), original_import_edges_verified=True)))


if __name__ == '__main__':
    main()
