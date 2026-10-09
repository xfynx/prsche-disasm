"""Compare the first accepted MAD header slice of 004dc850 with original x86."""
import argparse
import hashlib
import json
import struct
import subprocess
import sys
from pathlib import Path

from v2_source_dependencies import source_hashes

ROOT = Path(__file__).resolve().parents[2]
SHA = 'ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
START, DRAW = 0x4dc850, 0x4dc180
STACK, EXIT = 0x220f000, 0x2210000
STREAM, BUFFER, HEADER = 0x3001000, 0x3100000, 0x3200000
SCREEN_W, SCREEN_H = 0x5deac8, 0x5deacc
STATE_ADDRS = (0x65e268, 0x65e280, 0x65e3e8, 0x65e28c, 0x65e3e4, 0x65ba5c)
SERVICES = {
    0x531ca0: BUFFER,
    0x56aff0: STREAM,
    0x56b5b0: 0x3300000,
    0x56b230: 0,
    0x56b690: 0x3400000,
    0x56c540: HEADER,
}
TAGS = (0x6d44414d, 0x6544414d, 0x6b44414d)


def u32(value):
    return value & 0xffffffff


def signed16(value):
    value &= 0xffff
    return value - 0x10000 if value & 0x8000 else value


def cases():
    out = []
    for tag_i, tag in enumerate(TAGS):
        for mode in (0, 1, 3):
            for width, height, sw, sh in (
                (640, 480, 640, 480), (319, 201, 640, 480),
                (-1, -3, 640, 480), (0x7fff, -0x8000, 1, -1),
                (-0x8000, 0x7fff, -3, 3),
                (0x7fff, -0x8000, -0x80000000, 0x7fffffff),
            ):
                out.append({
                    'tag': tag, 'period': u32(0xfedc0000 + tag_i * 0x101 + len(out)),
                    'width': width, 'height': height, 'mode': mode,
                    'screen_width': sw, 'screen_height': sh,
                    'arg3': u32(0x10203040 + tag_i), 'arg4': mode,
                    'arg5': u32(0xfedcba00 + tag_i),
                })
    return out


def read_va(image, module, va, size):
    rva = va - int(module['image_base'], 16)
    sec = next(s for s in module['sections']
               if s['rva'] <= rva < s['rva'] + s['raw_size'])
    off = sec['raw_offset'] + rva - sec['rva']
    return image[off:off + size]


def original(module, image, case):
    sys.path.insert(0, str(ROOT / 'local/tools/python-unicorn'))
    from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE
    from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_EIP, UC_X86_REG_ESP

    uc = Uc(UC_ARCH_X86, UC_MODE_32)
    base = int(module['image_base'], 16)
    uc.mem_map(base, 0x300000)
    for section in module['sections']:
        if section['raw_size']:
            uc.mem_write(base + section['rva'], image[section['raw_offset']:section['raw_offset'] + section['raw_size']])
    for addr in (0x2200000, 0x3000000, 0x3100000, 0x3200000, 0x3300000, 0x3400000):
        uc.mem_map(addr, 0x10000)

    def put(address, value):
        uc.mem_write(address, struct.pack('<I', u32(value)))

    def word(address):
        return struct.unpack('<I', uc.mem_read(address, 4))[0]

    header = bytearray(0x20)
    struct.pack_into('<I', header, 0, case['tag'])
    struct.pack_into('<I', header, 0x0c, case['period'])
    struct.pack_into('<h', header, 0x10, case['width'])
    struct.pack_into('<h', header, 0x12, case['height'])
    uc.mem_write(HEADER, bytes(header))
    put(SCREEN_W, case['screen_width'])
    put(SCREEN_H, case['screen_height'])
    initial = (0xaaaa0001, 0xbbbb0002, 0xcccc0003, 0xffffffff, 0xdddd0005, 0xeeee0006)
    for address, value in zip(STATE_ADDRS, initial):
        put(address, value)
    put(STREAM + 0x100, 0)
    put(STACK, EXIT)
    args = (STREAM, STREAM + 0x100, case['arg3'], case['arg4'], case['arg5'])
    for i, value in enumerate(args):
        put(STACK + 4 + 4 * i, value)
    uc.reg_write(UC_X86_REG_ESP, STACK)
    draw_args = None
    trace = []

    def hook(machine, address, _size, _user):
        nonlocal draw_args
        trace.append(address)
        if address == DRAW:
            sp = machine.reg_read(UC_X86_REG_ESP)
            draw_args = [word(sp + 4 + 4 * i) for i in range(8)]
            machine.emu_stop()
            return
        if address in SERVICES:
            sp = machine.reg_read(UC_X86_REG_ESP)
            ret = word(sp)
            machine.reg_write(UC_X86_REG_EAX, SERVICES[address])
            machine.reg_write(UC_X86_REG_ESP, sp + 4)
            machine.reg_write(UC_X86_REG_EIP, ret)
            return
        if START <= address < 0x4dc9de:
            return
        trace_text = ','.join(format(x, '08x') for x in trace[-20:])
        raise RuntimeError(f'unexpected original boundary {address:08x}; trace={trace_text}')

    uc.hook_add(UC_HOOK_CODE, hook)
    try:
        uc.emu_start(START, DRAW + 1, count=10000)
    except Exception as error:
        trace_text = ','.join(format(x, '08x') for x in trace[-20:])
        raise RuntimeError(f'original emulation failed for {case}; eip={uc.reg_read(UC_X86_REG_EIP):08x}; trace={trace_text}') from error
    if draw_args is None or uc.reg_read(UC_X86_REG_EIP) != DRAW:
        raise AssertionError(f'original did not reach renderer boundary: {case}, eip={uc.reg_read(UC_X86_REG_EIP):08x}')
    state = [word(address) for address in STATE_ADDRS]
    return {
        'accepted': 1, 'period': state[0], 'width': struct.unpack('<i', struct.pack('<I', state[1]))[0],
        'height': struct.unpack('<i', struct.pack('<I', state[2]))[0],
        'counter': state[3], 'decoded': state[4], 'delta': state[5],
        'draw': [struct.unpack('<i', struct.pack('<I', x))[0] if i < 4 or i == 6 else x
                 for i, x in enumerate(draw_args)],
    }


def native_input(case):
    return ' '.join(str(case[key]) for key in (
        'tag', 'period', 'width', 'height', 'mode', 'screen_width', 'screen_height',
        'arg3', 'arg4', 'arg5'))


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--probe', type=Path, default=ROOT / 'local/builds/v2/001-original-recovery/bin/Release/movie_header_probe.exe')
    parser.add_argument('--report-dir', type=Path, required=True)
    args = parser.parse_args()
    args.report_dir.mkdir(parents=True, exist_ok=True)
    module = next(x for x in map(json.loads, (ROOT / 'research/binary-index/static/binaries.jsonl').read_text().splitlines()) if x['file'] == 'Porsche.exe')
    image = (ROOT / 'local/game' / module['path']).read_bytes()
    assert hashlib.sha256(image).hexdigest() == SHA
    inputs = cases()
    run = subprocess.run([str(args.probe)], input=''.join(native_input(c) + '\n' for c in inputs),
                         text=True, capture_output=True, check=True)
    actuals = [json.loads(line) for line in run.stdout.splitlines()]
    if len(actuals) != len(inputs):
        raise AssertionError(f'native returned {len(actuals)} rows for {len(inputs)} cases')
    for i, (case, actual) in enumerate(zip(inputs, actuals)):
        expected = original(module, image, case)
        if actual != expected:
            raise AssertionError(f'case {i} {case}: original={expected} native={actual}')

    source_paths = [
        'iterations/v2/001-original-recovery/source/include/porsche/movie_header.hpp',
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/movie_header.cpp',
        'iterations/v2/001-original-recovery/source/recovered/movie_header_probe.cpp',
        'scripts/research/verify-v2-movie-header.py',
        'iterations/v2/001-original-recovery/runs/094-movie-header/CMakeLists.txt',
        'iterations/v2/001-original-recovery/runs/094-movie-header/README.md',
    ]
    result = {
        'schema': 1, 'module': 'Porsche.exe', 'sha256': SHA, 'module_sha256': SHA,
        'function_vas': ['004dc850'], 'full_function_vas': [], 'partial_function_vas': ['004dc850'],
        'cases': len(inputs), 'native_cpp_equal_original_x86': True,
        'comparison_boundary': '004dc850 accepted MAD-family header through entry of 004dc180; stream selection is explicitly fixture-controlled',
        'original_function': {'va': '004dc850', 'body_bytes': 3151,
                              'body_sha256': hashlib.sha256(read_va(image, module, START, 3151)).hexdigest()},
        'bounded_state': ['0065e268','0065e280','0065e3e8','0065e28c','0065e3e4','0065ba5c'],
        'source_sha256': source_hashes([ROOT / p for p in source_paths]),
        'probe_sha256': hashlib.sha256(args.probe.read_bytes()).hexdigest(),
    }
    (args.report_dir / 'verification.json').write_text(json.dumps(result, indent=2) + '\n', newline='\n')
    print(json.dumps({'cases': len(inputs), 'partial_function_vas': result['partial_function_vas'],
                      'native_cpp_equal_original_x86': True}))


if __name__ == '__main__':
    main()
