"""Bounded differential proof for Porsche.exe 0x56fff0 and 0x56fdb0 failure."""
import argparse
import hashlib
import json
from pathlib import Path
import struct
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[2]
RUN = ROOT / 'iterations/v2/001-original-recovery/runs/019-input-buffer'
sys.path.insert(0, str(ROOT / 'local/tools/python-unicorn'))
from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_EIP, UC_X86_REG_ESP

SOURCE_SHA = 'ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
BASE, DEVICE, VTABLE, PROP, CAPS = 0x400000, 0x2100200, 0x2100300, 0x2101000, 0x2101010
OUTPUT, EXIT, STACK = 0x2200000, 0x2210000, 0x2300800


def inputs():
    statuses = (0, 1, 0x8007000c, 0x8007001e, 0xffffffff)
    return [(0, status, value) for status in statuses for value in (0, 1, 2, 3, 0xffffffff)] + [
        (1, status, value) for status in statuses[1:] for value in (0, 1, 0xffffffff)]


def original(module, data, case):
    kind, status, value = case
    uc = Uc(UC_ARCH_X86, UC_MODE_32)
    uc.mem_map(BASE, 0x300000)
    for section in module['sections']:
        off = section['raw_offset']
        uc.mem_write(BASE + section['rva'], data[off:off + section['raw_size']])
    uc.mem_map(0x2100000, 0x3000)
    uc.mem_map(OUTPUT, 0x1000)
    uc.mem_map(EXIT, 0x1000)
    uc.mem_map(0x2300000, 0x1000)
    uc.mem_write(DEVICE, struct.pack('<I', VTABLE))
    uc.mem_write(VTABLE + 0x14, struct.pack('<I', PROP))
    uc.mem_write(VTABLE + 0x3c, struct.pack('<I', CAPS))
    uc.mem_write(OUTPUT, b'\xa5' * 0x21c)
    args = (DEVICE,) if kind == 0 else (DEVICE, OUTPUT)
    uc.mem_write(STACK, struct.pack('<' + 'I' * (len(args) + 1), EXIT, *args))
    uc.reg_write(UC_X86_REG_ESP, STACK)
    entry = 0x56fff0 if kind == 0 else 0x56fdb0
    uc.reg_write(UC_X86_REG_EIP, entry)
    calls = []

    def hook(inner, address, _size, _user):
        if address not in (PROP, CAPS, 0x53c290):
            return
        sp = inner.reg_read(UC_X86_REG_ESP)
        ret = struct.unpack('<I', inner.mem_read(sp, 4))[0]
        if address == PROP:
            dev, prop_id, dest = struct.unpack('<III', inner.mem_read(sp + 4, 12))
            initial = struct.unpack('<IIII', inner.mem_read(dest, 16))
            calls.append('P' if (dev, prop_id, initial) ==
                         (DEVICE, 2, (0x14, 0x10, 0, 0)) else 'E')
            inner.mem_write(dest + 16, struct.pack('<I', value))
            eax, pop = status, 4
        elif address == CAPS:
            dev, dest = struct.unpack('<II', inner.mem_read(sp + 4, 8))
            initial = struct.unpack('<I', inner.mem_read(dest, 4))[0]
            calls.append('C' if (dev, initial) == (DEVICE, 0x244) else 'E')
            eax, pop = status, 3
        else:
            dest, fill, length = struct.unpack('<III', inner.mem_read(sp + 4, 12))
            if (dest, fill, length) != (OUTPUT, 0, 0x21c):
                raise RuntimeError('Unexpected original memset args')
            inner.mem_write(dest, bytes(length))
            eax, pop = dest, 1  # cdecl; caller removes the three arguments
        inner.reg_write(UC_X86_REG_EAX, eax)
        inner.reg_write(UC_X86_REG_ESP, sp + 4 * pop)
        inner.reg_write(UC_X86_REG_EIP, ret)

    uc.hook_add(UC_HOOK_CODE, hook)
    uc.emu_start(entry, EXIT, count=500)
    if uc.reg_read(UC_X86_REG_EIP) != EXIT:
        raise RuntimeError('Original input buffer function did not return')
    return (str(uc.reg_read(UC_X86_REG_EAX)), ','.join(calls) or '-',
            bytes(uc.mem_read(OUTPUT, 0x21c)).hex())


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--probe', type=Path, default=ROOT / 'local/builds/v2/001-original-recovery/bin/Release/input_buffer_probe.exe')
    parser.add_argument('--report-dir', type=Path, default=RUN)
    args = parser.parse_args()
    report_dir = args.report_dir
    module = next(row for row in map(json.loads, (ROOT / 'research/binary-index/static/binaries.jsonl').read_text(encoding='utf8').splitlines()) if row['file'] == 'Porsche.exe')
    data = (ROOT / 'local/game' / module['path']).read_bytes()
    if module['sha256'] != SOURCE_SHA or hashlib.sha256(data).hexdigest() != SOURCE_SHA:
        raise RuntimeError('Porsche.exe SHA mismatch')
    cases = inputs()
    wire = ''.join(' '.join(map(str, case)) + '\n' for case in cases)
    native = subprocess.run([str(args.probe)], input=wire, text=True, capture_output=True, check=True, timeout=120)
    rows = [tuple(line.split()) for line in native.stdout.splitlines()]
    if len(rows) != len(cases):
        raise RuntimeError(f'Native rows {len(rows)} != cases {len(cases)}')
    for i, (case, actual) in enumerate(zip(cases, rows)):
        expected = original(module, data, case)
        if actual != expected:
            raise RuntimeError(f'Case {i} {case}: expected {expected[:2]} out={hashlib.sha256(bytes.fromhex(expected[2])).hexdigest()} actual {actual[:2]} out={hashlib.sha256(bytes.fromhex(actual[2])).hexdigest()}')
    deps = ['iterations/v2/001-original-recovery/source/include/porsche/input_buffer.hpp',
            'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/input_buffer.cpp',
            'iterations/v2/001-original-recovery/source/recovered/input_buffer_probe.cpp',
            'scripts/research/verify-v2-input-buffer.py',
            'iterations/v2/001-original-recovery/CMakeLists.txt',
            'iterations/v2/001-original-recovery/source/recovered/sources.cmake']
    report = {'schema': 1, 'sha256': SOURCE_SHA, 'cases': len(cases),
              'full_function_vas': ['0056fff0'], 'partial_function_vas': ['0056fdb0'],
              'covered_0056fdb0': 'capabilities failure exit only',
              'native_cpp_equal_original_x86': True, 'binary_matched': False,
              'game_launch_verified': False,
              'probe_sha256': hashlib.sha256(args.probe.read_bytes()).hexdigest(),
              'source_sha256': {name: hashlib.sha256((ROOT / name).read_bytes().replace(b'\r\n', b'\n')).hexdigest() for name in deps}}
    report_dir.mkdir(parents=True, exist_ok=True)
    (report_dir / 'verification.json').write_text(json.dumps(report, indent=2) + '\n', encoding='utf8')
    print(json.dumps({'cases': len(cases), 'full_function_vas': report['full_function_vas'],
                      'partial_function_vas': report['partial_function_vas']}))


if __name__ == '__main__':
    main()
