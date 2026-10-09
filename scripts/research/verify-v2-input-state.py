"""Differential mode-6 input state and DirectInput helper proof against Porsche.exe."""
import argparse
import hashlib
import json
from pathlib import Path
import random
import struct
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[2]
RUN = ROOT / 'iterations/v2/001-original-recovery/runs/013-input-state'
sys.path.insert(0, str(ROOT / 'local/tools/python-unicorn'))
from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_EIP, UC_X86_REG_ESP

VAS = (0x532e10, 0x56fd00, 0x56fd30, 0x56fce0)
BASE, COUNT, SLOT = 0x400000, 0x69cb0c, 0x6be040
DEVICE, VTABLE, POLL, ACQUIRE, GET, DIAG, EXIT, STACK = (
    0x2100200, 0x2100300, 0x2101000, 0x2101010, 0x2101020, 0x2101030,
    0x2200000, 0x2300800)
LOST = (0x8007000c, 0x8007001e)


def cases():
    out = []
    statuses = (0, 1, *LOST)
    # kind,index,count,present,type,poll0,poll1,acqp,get0,get1,acqg
    for kind in range(4):
        sizes = (1, 2, 3, 4, 5, 0x102) if kind == 0 else (0x10, 0x50, 0x100)
        for typ in sizes:
            for poll0 in statuses:
                for get0 in statuses:
                    for ap in (0, 1):
                        for ag in (0, 1):
                            out.append((kind, 0, 1, 1, typ, poll0, 7, ap, get0, 9, ag))
    out.extend((0, index, count, present, 1, 0, 7, 0, 0, 9, 0)
               for index, count, present in ((0, 0, 1), (0, 1, 0), (1, 1, 1),
                                               (1, 2, 1), (31, 32, 1), (32, 32, 1)))
    rng = random.Random(0x532e10)
    for _ in range(60):
        kind = rng.randrange(4)
        typ = rng.choice((1, 2, 3, 4)) if kind == 0 else rng.choice((16, 80, 256))
        out.append((kind, 0, 1, 1, typ, rng.choice(statuses), rng.getrandbits(32),
                    rng.randrange(2), rng.choice(statuses), rng.getrandbits(32), rng.randrange(2)))
    return out


def original(module, data, case):
    kind, index, count, present, typ, poll0, poll1, ap, get0, get1, ag = case
    uc = Uc(UC_ARCH_X86, UC_MODE_32)
    uc.mem_map(BASE, 0x300000)
    for section in module['sections']:
        off = section['raw_offset']
        uc.mem_write(BASE + section['rva'], data[off:off + section['raw_size']])
    uc.mem_map(0x2100000, 0x3000)
    uc.mem_map(EXIT, 0x1000)
    uc.mem_map(0x2300000, 0x1000)
    uc.mem_write(COUNT, struct.pack('<i', count))
    uc.mem_write(SLOT, bytes(0x2180))
    uc.mem_write(SLOT, struct.pack('<III', DEVICE if present else 0, 0x87654321, typ))
    uc.mem_write(SLOT + 12, bytes([0xa5]) * 256)
    uc.mem_write(DEVICE, struct.pack('<I', VTABLE))
    for offset, target in ((0x1c, ACQUIRE), (0x24, GET), (0x64, POLL)):
        uc.mem_write(VTABLE + offset, struct.pack('<I', target))
    uc.mem_write(0x5debf0, struct.pack('<I', DIAG))
    args = ((index, 6), (DEVICE,), (DEVICE, typ, SLOT + 12), (DEVICE, SLOT + 12, typ))[kind]
    uc.mem_write(STACK, struct.pack('<' + 'I' * (len(args) + 1), EXIT, *args))
    uc.reg_write(UC_X86_REG_ESP, STACK)
    uc.reg_write(UC_X86_REG_EIP, VAS[kind])
    calls = []
    phase = None
    poll_calls = get_calls = 0

    def hook(inner, address, _size, _user):
        nonlocal phase, poll_calls, get_calls
        if address not in (POLL, ACQUIRE, GET, DIAG):
            return
        sp = inner.reg_read(UC_X86_REG_ESP)
        ret = struct.unpack('<I', inner.mem_read(sp, 4))[0]
        if address == POLL:
            phase = 'P'; calls.append('P')
            result = poll0 if poll_calls == 0 else poll1
            poll_calls += 1; argc = 1
        elif address == ACQUIRE:
            calls.append('A'); result = ap if phase == 'P' else ag; argc = 1
        elif address == GET:
            phase = 'G'; get_calls += 1
            _self, size, dest = struct.unpack('<III', inner.mem_read(sp + 4, 12))
            calls.append(f'G{size}' + ('s' if dest == SLOT + 12 else 'x'))
            inner.mem_write(dest, bytes([0x40 + get_calls]) * size)
            result = get0 if get_calls == 1 else get1; argc = 3
        else:
            calls.append('D'); result = 0; argc = 0  # cdecl diagnostic: caller pops its argument
        inner.reg_write(UC_X86_REG_EAX, result)
        inner.reg_write(UC_X86_REG_ESP, sp + 4 * (argc + 1))
        inner.reg_write(UC_X86_REG_EIP, ret)

    uc.hook_add(UC_HOOK_CODE, hook)
    uc.emu_start(VAS[kind], EXIT, count=300)
    if uc.reg_read(UC_X86_REG_EIP) != EXIT:
        raise RuntimeError('Original input function did not return')
    eax = uc.reg_read(UC_X86_REG_EAX)
    returned = int(eax == SLOT + 8) if kind == 0 else eax
    if kind == 0 and eax not in (0, SLOT + 8):
        raise RuntimeError(f'Unexpected original mode-6 return {eax:#x}')
    arena = bytes(uc.mem_read(SLOT, 0x2180))
    normalized = b''.join(arena[i * 0x10c + 4:(i + 1) * 0x10c] for i in range(32))
    return str(returned), normalized.hex(), ','.join(calls) or '-'


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--probe', type=Path, default=ROOT / 'local/builds/v2/001-original-recovery/bin/Release/input_probe.exe')
    parser.add_argument('--limit', type=int, default=0)
    args = parser.parse_args()
    module = next(row for row in map(json.loads, (ROOT / 'research/binary-index/static/binaries.jsonl').read_text(encoding='utf8').splitlines()) if row['file'] == 'Porsche.exe')
    expected_sha = 'ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
    data = (ROOT / 'local/game' / module['path']).read_bytes()
    if module['sha256'] != expected_sha or hashlib.sha256(data).hexdigest() != expected_sha:
        raise RuntimeError('Porsche.exe SHA mismatch')
    inputs = cases()[:args.limit or None]
    wire = '\n'.join(' '.join(map(str, case)) for case in inputs) + '\n'
    native = subprocess.run([str(args.probe)], input=wire, text=True, capture_output=True, check=True, timeout=120)
    rows = [tuple(line.split()) for line in native.stdout.splitlines()]
    if len(rows) != len(inputs):
        raise RuntimeError(f'Native rows {len(rows)} != input cases {len(inputs)}')
    for i, (case, actual) in enumerate(zip(inputs, rows)):
        expected = original(module, data, case)
        if actual != expected:
            raise RuntimeError(f'Case {i} {case}: expected ret={expected[0]},log={expected[2]},arena={hashlib.sha256(bytes.fromhex(expected[1])).hexdigest()} native ret={actual[0]},log={actual[2]},arena={hashlib.sha256(bytes.fromhex(actual[1])).hexdigest()}')
    report = {'schema': 2, 'sha256': expected_sha,
              'partial_function_vas': ['00532e10'],
              'full_function_vas': ['0056fd00', '0056fd30', '0056fce0'],
              'cases': len(inputs),
              'native_cpp_equal_original_x86': True, 'binary_matched': False,
              'game_launch_verified': False,
              'boundary': 'DirectInput vtable methods recorded with controlled HRESULT and data; 0x532e10 modes 1/2/8 and negative indexes not accepted',
              'probe_sha256': hashlib.sha256(args.probe.read_bytes()).hexdigest()}
    deps = ['iterations/v2/001-original-recovery/source/include/porsche/input_state.hpp',
            'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/input_state.cpp',
            'iterations/v2/001-original-recovery/source/recovered/input_probe.cpp',
            'scripts/research/verify-v2-input-state.py',
            'iterations/v2/001-original-recovery/CMakeLists.txt',
            'iterations/v2/001-original-recovery/source/recovered/sources.cmake']
    report['source_sha256'] = {name: hashlib.sha256((ROOT / name).read_bytes().replace(b'\r\n', b'\n')).hexdigest() for name in deps}
    if not args.limit:
        RUN.mkdir(parents=True, exist_ok=True)
        (RUN / 'verification.json').write_text(json.dumps(report, indent=2) + '\n', encoding='utf8')
    print(json.dumps({'cases': len(inputs), 'native_cpp_equal_original_x86': True,
                      'partial_function_vas': report['partial_function_vas'],
                      'full_function_vas': report['full_function_vas']}))


if __name__ == '__main__':
    main()
