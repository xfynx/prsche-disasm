from v2_source_dependencies import source_hashes
"""Compare Porsche.exe startup resource path consumer with a native C++ probe."""
import argparse
import hashlib
import json
from pathlib import Path
import struct
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[2]
RUN = ROOT / 'iterations/v2/001-original-recovery/runs/023-resource-paths'
sys.path.insert(0, str(ROOT / 'local/tools/python-unicorn'))
from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_EIP, UC_X86_REG_ESP, UC_X86_REG_EDI

SOURCE_SHA = 'ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
BASE, MODULE, DRIVE, FORMAT, EXISTS, EXIT, STACK = (
    0x400000, 0x2101000, 0x2101010, 0x5a0fbf, 0x561b80, 0x2200000, 0x2301800)
ROOT_ADDR, FALLBACK_ADDR, ENABLED_ADDR = 0x6af168, 0x6af26c, 0x6af370
MODULE_PATHS = (b'C:\\NFS\\Porsche.exe', b'D:\\Porsche.exe', b'Z:\\Games\\NFS.EXE')


def cases():
    return [(path, drive, found, final) for path in range(3)
            for drive in (0, ord('d'), ord('m'), ord('z'))
            for found in (0, 1) for final in (0, 1)]


def original(module, data, case):
    path_kind, optical_letter, file_result, final_result = case
    uc = Uc(UC_ARCH_X86, UC_MODE_32)
    uc.mem_map(BASE, 0x300000)
    for section in module['sections']:
        off = section['raw_offset']
        uc.mem_write(BASE + section['rva'], data[off:off + section['raw_size']])
    uc.mem_map(0x2100000, 0x3000)
    uc.mem_map(EXIT, 0x1000)
    uc.mem_map(0x2300000, 0x2000)
    uc.mem_write(0x5b2064, struct.pack('<I', MODULE))
    uc.mem_write(0x5b2060, struct.pack('<I', DRIVE))
    uc.mem_write(ROOT_ADDR, b'\xa5' * 260)
    uc.mem_write(FALLBACK_ADDR, b'\xa5' * 260)
    uc.mem_write(ENABLED_ADDR, b'\xa5')
    uc.mem_write(STACK, struct.pack('<I', EXIT))
    uc.reg_write(UC_X86_REG_ESP, STACK)
    uc.reg_write(UC_X86_REG_EIP, 0x59d650)
    calls = []

    def cstring(inner, address):
        raw = bytes(inner.mem_read(address, 1024))
        return raw.split(b'\x00', 1)[0]

    def hook(inner, address, _size, _user):
        if address not in (MODULE, DRIVE, FORMAT, EXISTS):
            return
        sp = inner.reg_read(UC_X86_REG_ESP)
        ret = struct.unpack('<I', inner.mem_read(sp, 4))[0]
        if address == MODULE:
            handle, dest, capacity = struct.unpack('<III', inner.mem_read(sp + 4, 12))
            if handle != 0 or capacity != 0x104:
                raise RuntimeError('Unexpected GetModuleFileNameA arguments')
            name = MODULE_PATHS[path_kind]
            inner.mem_write(dest, name + b'\x00')
            calls.append(f'M{capacity}')
            eax, pop = len(name), 4
        elif address == DRIVE:
            dest = struct.unpack('<I', inner.mem_read(sp + 4, 4))[0]
            path = cstring(inner, dest)
            calls.append('D' + path.decode('ascii'))
            eax, pop = (5 if path[0] == optical_letter else 3), 2
        elif address == FORMAT:
            dest, fmt = struct.unpack('<II', inner.mem_read(sp + 4, 8))
            pattern = cstring(inner, fmt)
            if pattern == b'%c:\\':
                letter = struct.unpack('<I', inner.mem_read(sp + 12, 4))[0]
                result = bytes((letter & 0xff,)) + b':\\'
            elif pattern == b'%s%s':
                a, b = struct.unpack('<II', inner.mem_read(sp + 12, 8))
                result = cstring(inner, a) + cstring(inner, b)
            else:
                raise RuntimeError(f'Unexpected original format {pattern!r}')
            inner.mem_write(dest, result + b'\x00')
            calls.append('F' + result.decode('ascii'))
            eax, pop = len(result), 1  # cdecl formatter
        else:
            arg = struct.unpack('<I', inner.mem_read(sp + 4, 4))[0]
            path = cstring(inner, arg)
            calls.append('E' + path.decode('ascii'))
            eax, pop = (final_result if b'fe.txt' in path else file_result), 1
        inner.reg_write(UC_X86_REG_EAX, eax)
        inner.reg_write(UC_X86_REG_ESP, sp + 4 * pop)
        inner.reg_write(UC_X86_REG_EIP, ret)

    uc.hook_add(UC_HOOK_CODE, hook)
    uc.emu_start(0x59d650, EXIT, count=10000)
    if uc.reg_read(UC_X86_REG_EIP) != EXIT:
        raise RuntimeError('Original resource path function did not return')
    return (str(uc.reg_read(UC_X86_REG_EAX)), str(uc.mem_read(ENABLED_ADDR, 1)[0]),
            bytes(uc.mem_read(ROOT_ADDR, 260)).hex(),
            bytes(uc.mem_read(FALLBACK_ADDR, 260)).hex(), ','.join(calls))


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--probe', type=Path, default=ROOT / 'local/builds/v2/001-original-recovery/bin/Release/resource_paths_probe.exe')
    parser.add_argument('--report-dir',type=Path,default=RUN)
    args = parser.parse_args()
    report_dir=args.report_dir
    module = next(row for row in map(json.loads, (ROOT / 'research/binary-index/static/binaries.jsonl').read_text(encoding='utf8').splitlines()) if row['file'] == 'Porsche.exe')
    data = (ROOT / 'local/game' / module['path']).read_bytes()
    if module['sha256'] != SOURCE_SHA or hashlib.sha256(data).hexdigest() != SOURCE_SHA:
        raise RuntimeError('Porsche.exe SHA mismatch')
    inputs = cases()
    native = subprocess.run([str(args.probe)], input=''.join(' '.join(map(str, x)) + '\n' for x in inputs),
                            text=True, capture_output=True, check=True, timeout=120)
    rows = [tuple(line.split()) for line in native.stdout.splitlines()]
    if len(rows) != len(inputs):
        raise RuntimeError(f'Native rows {len(rows)} != cases {len(inputs)}')
    for i, (case, actual) in enumerate(zip(inputs, rows)):
        expected = original(module, data, case)
        if actual != expected:
            raise RuntimeError(f'Case {i} {case}: expected return/flag/log {expected[0],expected[1],expected[4]}, native {actual[0],actual[1],actual[4]}')
    deps = ['iterations/v2/001-original-recovery/source/include/porsche/resource_paths.hpp',
            'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/resource_paths.cpp',
            'iterations/v2/001-original-recovery/source/recovered/resource_paths_probe.cpp',
            'scripts/research/verify-v2-resource-paths.py',
            'iterations/v2/001-original-recovery/CMakeLists.txt',
            'iterations/v2/001-original-recovery/source/recovered/sources.cmake']
    report = {'schema': 1, 'sha256': SOURCE_SHA, 'cases': len(inputs),
              'full_function_vas': ['0059d650'], 'native_cpp_equal_original_x86': True,
              'binary_matched': False, 'game_launch_verified': False,
              'boundary': 'valid NUL-terminated GetModuleFileNameA paths containing a backslash; Win32/CRT/file_exists are typed recording endpoints',
              'probe_sha256': hashlib.sha256(args.probe.read_bytes()).hexdigest(),
              'source_sha256': {name: hashlib.sha256((ROOT / name).read_bytes().replace(b'\r\n', b'\n')).hexdigest() for name in deps}}
    report_dir.mkdir(parents=True, exist_ok=True)
    report['source_sha256']=source_hashes([*report['source_sha256'],Path(__file__)])
    (report_dir / 'verification.json').write_text(json.dumps(report, indent=2) + '\n', encoding='utf8')
    print(json.dumps({'cases': len(inputs), 'full_function_vas': report['full_function_vas']}))


if __name__ == '__main__':
    main()
