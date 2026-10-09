from v2_source_dependencies import source_hashes
"""Compare three recovered FE callbacks with original Porsche.exe x86."""
import argparse
import hashlib
import json
from pathlib import Path
import random
import struct
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[2]
RUN = ROOT / 'iterations/v2/001-original-recovery/runs/012-fe-callbacks'
sys.path.insert(0, str(ROOT / 'local/tools/python-unicorn'))
from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ESP, UC_X86_REG_EIP

VAS = (0x4119e0, 0x411a80, 0x411b40)
LIST, MASKS, CALLEE, EXIT = 0x5e8e60, 0x5e9380, 0x532e10, 0x2000000


def cases():
    rng = random.Random(0x4119e0)
    out = []
    indices = (0, 1, 7, 31, 32, 127, 128, 255, 256, 32767, 32768, 65535)
    layouts = [bytes([255] * 32), bytes([0] * 32), bytes(range(32)),
               bytes([i + 1 for i in range(31)] + [255]), bytes([i for i in range(32)])]
    for kind in range(3):
        for index in indices:
            for bit in (0, 1, 31):
                packed = ((index << (20 if kind == 2 else 16)) | bit) & 0xffffffff
                for present in (0, 1):
                    for layout in layouts:
                        masks = bytes(rng.getrandbits(8) for _ in range(128))
                        out.append((kind, packed, present, layout, masks))
        for _ in range(80):
            out.append((kind, rng.getrandbits(32), rng.randrange(2),
                        bytes(rng.getrandbits(8) for _ in range(32)),
                        bytes(rng.getrandbits(8) for _ in range(128))))
    return out


def original(module, data, case):
    kind, packed, present, devices, masks = case
    uc = Uc(UC_ARCH_X86, UC_MODE_32)
    base = int(module['image_base'], 16)
    uc.mem_map(base, 0x300000)
    for section in module['sections']:
        offset = section['raw_offset']
        uc.mem_write(base + section['rva'], data[offset:offset + section['raw_size']])
    uc.mem_map(EXIT, 0x1000)
    uc.mem_map(0x2100000, 0x1000)
    uc.mem_write(LIST, devices)
    uc.mem_write(MASKS, masks)
    esp = 0x2100800
    uc.mem_write(esp, struct.pack('<II', EXIT, packed))
    uc.reg_write(UC_X86_REG_ESP, esp)
    uc.reg_write(UC_X86_REG_EIP, VAS[kind])
    calls = []

    def hook(inner, address, _size, _user):
        if address != CALLEE:
            return
        sp = inner.reg_read(UC_X86_REG_ESP)
        ret, index, mode = struct.unpack('<III', inner.mem_read(sp, 12))
        calls.append((index, mode))
        inner.reg_write(UC_X86_REG_EAX, 0x12340000 if present else 0)
        inner.reg_write(UC_X86_REG_ESP, sp + 4)
        inner.reg_write(UC_X86_REG_EIP, ret)

    uc.hook_add(UC_HOOK_CODE, hook)
    uc.emu_start(VAS[kind], EXIT, count=1000)
    if uc.reg_read(UC_X86_REG_EIP) != EXIT:
        raise RuntimeError('Original callback did not return')
    return (bytes(uc.mem_read(LIST, 32)).hex(), bytes(uc.mem_read(MASKS, 128)).hex(),
            len(calls), calls[0][0] if calls else 0, calls[0][1] if calls else 0,
            uc.reg_read(UC_X86_REG_EAX))


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--probe', type=Path, default=ROOT / 'local/builds/v2/001-original-recovery/bin/Release/fe_callbacks_probe.exe')
    parser.add_argument('--limit', type=int, default=0)
    parser.add_argument('--report-dir', type=Path, default=RUN)
    args = parser.parse_args()
    binaries = ROOT / 'research/binary-index/static/binaries.jsonl'
    module = next(row for row in map(json.loads, binaries.read_text(encoding='utf8').splitlines())
                  if row['file'] == 'Porsche.exe')
    expected_sha = 'ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
    if module['sha256'] != expected_sha:
        raise RuntimeError('Unexpected source binary in index')
    data = (ROOT / 'local/game' / module['path']).read_bytes()
    if hashlib.sha256(data).hexdigest() != expected_sha:
        raise RuntimeError('Original Porsche.exe SHA mismatch')
    inputs = cases()[:args.limit or None]
    wire = '\n'.join(f'{kind} {packed} {present} {devices.hex()} {masks.hex()}'
                     for kind, packed, present, devices, masks in inputs) + '\n'
    native = subprocess.run([str(args.probe)], input=wire, capture_output=True, text=True,
                            check=True, timeout=120)
    rows = [line.split() for line in native.stdout.splitlines()]
    if len(rows) != len(inputs):
        raise RuntimeError(f'Native returned {len(rows)} lines for {len(inputs)} cases')
    for number, (case, row) in enumerate(zip(inputs, rows)):
        expected = original(module, data, case)
        actual = (row[0], row[1], *map(int, row[2:]))
        if actual != expected:
            raise RuntimeError(f'Case {number}: input={case[:3]}, original={expected}, native={actual}')
    report = {'schema': 1, 'sha256': expected_sha, 'function_vas': [f'{va:08x}' for va in VAS],
              'cases': len(inputs), 'native_cpp_equal_original_x86': True,
              'native_return_equal_original_eax': True,
              'binary_matched': False, 'game_launch_verified': False,
              'boundary': '0x00532e10 mode 6 returns controlled null/non-null pointer; callee side effects unrecovered',
              'probe_sha256': hashlib.sha256(args.probe.read_bytes()).hexdigest()}
    dependencies = [
        'iterations/v2/001-original-recovery/source/include/porsche/fe_callbacks.hpp',
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/fe_callbacks.cpp',
        'iterations/v2/001-original-recovery/source/recovered/fe_callbacks_probe.cpp',
        'iterations/v2/001-original-recovery/source/include/porsche/fe_stream.hpp',
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/fe_stream.cpp',
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/fe_tables.inc',
        'scripts/research/verify-v2-fe-callbacks.py',
        'iterations/v2/001-original-recovery/CMakeLists.txt',
        'iterations/v2/001-original-recovery/source/recovered/sources.cmake',
    ]
    report['source_sha256'] = {name: hashlib.sha256((ROOT / name).read_bytes().replace(b'\r\n', b'\n')).hexdigest()
                               for name in dependencies}
    if not args.limit:
        args.report_dir.mkdir(parents=True, exist_ok=True)
        report['source_sha256']=source_hashes([*report['source_sha256'],Path(__file__)])
        (args.report_dir / 'verification.json').write_text(json.dumps(report, indent=2) + '\n', encoding='utf8')
    print(json.dumps({'cases': len(inputs), 'native_cpp_equal_original_x86': True,
                      'function_vas': report['function_vas']}))


if __name__ == '__main__':
    main()
