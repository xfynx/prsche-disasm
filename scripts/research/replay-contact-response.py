"""Differential probe of an original contact-response slice, not a game solver.

Install unicorn==2.1.3 into local/tools/python-unicorn. Runs original x86 bytes
from 0x4940ae after geometry preparation, with the angular callback disabled.
No original instruction is patched or replaced. See original-collision/response.md.
"""
import argparse
import hashlib
import json
import math
from pathlib import Path
import random
import struct
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'local/tools/python-unicorn'))
from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EBX, UC_X86_REG_EDI, UC_X86_REG_ESP, UC_X86_REG_EIP

SHA = 'ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
CAR, NORMAL, STACK, EXIT, RESULT = 0x2000000, 0x2002000, 0x2108000, 0x2200000, 0x2200100
WHEELS = (0x7f8, 0x8bc, 0x980, 0xa44)


def f32(value):
    return struct.unpack('<f', struct.pack('<f', value))[0]


def approximate_speed(v):
    return f32(max(abs(v[0]), abs(v[2])) + .25 * min(abs(v[0]), abs(v[2])))


def machine(module, data):
    uc = Uc(UC_ARCH_X86, UC_MODE_32)
    base = int(module['image_base'], 16)
    end = max(s['rva'] + max(s['vsize'], s['raw_size']) for s in module['sections'])
    uc.mem_map(base, (end + 4095) & ~4095)
    for section in module['sections']:
        start = section['raw_offset']
        uc.mem_write(base + section['rva'], data[start:start + section['raw_size']])
    uc.mem_map(CAR, 0x4000)
    uc.mem_map(0x2100000, 0x10000)
    uc.mem_map(EXIT, 0x1000)
    # Harness only: store the returned x87 float. Original bytes stay intact.
    uc.mem_write(EXIT, b'\xd9\x1d' + struct.pack('<I', RESULT))
    allowed = ((0x4940ae, 0x4943a0), (0x493dd0, 0x493f01),
               (0x532360, 0x532397), (0x532910, 0x532923),
               (0x56e8d1, 0x56e8f5), (0x516950, 0x516951), (EXIT, EXIT + 6))

    def guard(_uc, address, _size, _user):
        if not any(lo <= address < hi for lo, hi in allowed):
            raise RuntimeError(f'unexpected original path: {address:08x}')
    uc.hook_add(UC_HOOK_CODE, guard)
    return uc


def run_case(module, data, fixture):
    uc = machine(module, data)

    def put(address, *values):
        uc.mem_write(address, struct.pack('<' + 'f' * len(values), *values))

    def get(address, count=1):
        return list(struct.unpack('<' + 'f' * count, uc.mem_read(address, count * 4)))

    velocity, normal, correction = (fixture[k] for k in ('velocity', 'normal', 'correction'))
    position = [10., 20., 30.]
    put(CAR + 0x330, *position)
    put(CAR + 0x33c, *velocity)
    speed = approximate_speed(velocity)
    put(CAR + 0x35c, speed)
    for offset, basis in ((0x364, (1, 0, 0)), (0x370, (0, 1, 0)),
                          (0x37c, (0, 0, 1)), (0x490, (0, 0, -1)), (0x4a8, (1, 0, 0))):
        put(CAR + offset, *basis)
    put(CAR + 0xd58, 11., 12., 13.)
    for offset in WHEELS:
        put(CAR + offset, 40., 50., 60.)
        put(CAR + offset + 0x78, 9.)
    put(CAR + 0xdb8, 7.)
    put(CAR + 0xdc0, 8.)
    uc.mem_write(CAR + 0x52c, bytes([fixture['alternate'] * 4]))
    uc.mem_write(0x628c88, struct.pack('<I', fixture['surface']))
    put(NORMAL, *normal)
    put(STACK + 0xc, *correction)
    uc.mem_write(STACK + 0x54, struct.pack('<I', EXIT))
    # At 0x4940ae, four arguments to the preceding scale call remain on stack.
    uc.reg_write(UC_X86_REG_ESP, STACK - 16)
    uc.reg_write(UC_X86_REG_EBX, CAR)
    uc.reg_write(UC_X86_REG_EDI, NORMAL)
    uc.emu_start(0x4940ae, EXIT + 6, count=10000)
    if uc.reg_read(UC_X86_REG_EIP) != EXIT + 6:
        raise RuntimeError('instruction budget exhausted')

    actual = {'velocity': get(CAR + 0x33c, 3), 'position': get(CAR + 0x330, 3),
              'local_velocity': get(CAR + 0xd58, 3), 'speed': get(CAR + 0x35c),
              'return': get(RESULT), 'wheels': [x for off in WHEELS for x in get(CAR + off, 3)],
              'resets': [get(CAR + off + 0x78)[0] for off in WHEELS] + get(CAR + 0xdb8) + get(CAR + 0xdc0)}
    strength = f32(-sum(a * b for a, b in zip(velocity, normal)))
    expected = {'velocity': velocity, 'position': position, 'local_velocity': [11., 12., 13.],
                'speed': [speed], 'return': [0.], 'wheels': [40., 50., 60.] * 4,
                'resets': [9.] * 4 + [7., 8.]}
    if strength > 0:
        scale = f32(strength * f32(1.1))
        v = [f32(f32(a + f32(n * scale)) * f32(.998)) for a, n in zip(velocity, normal)]
        reported = f32(speed * f32(1 / 12)) if speed * .125 > strength else strength
        expected.update(velocity=v, position=[f32(a + b) for a, b in zip(position, correction)],
                        local_velocity=[-v[2], v[1], v[0]] if fixture['alternate'] else v,
                        speed=[approximate_speed(v)], return_value=[abs(f32(reported * 3))],
                        wheels=[f32(40 + correction[0]), 50., f32(60 + correction[2])] * 4)
        expected['return'] = expected.pop('return_value')
        if fixture['alternate']:
            expected['resets'] = [0.] * 6
    for key, values in expected.items():
        for want, got in zip(values, actual[key], strict=True):
            if not math.isclose(want, got, rel_tol=2e-6, abs_tol=2e-6):
                raise AssertionError(f"{fixture['name']} {key}: expected {want}, original {got}")
    return {'input': fixture, 'original': actual}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    modules = [json.loads(line) for line in (ROOT / 'research/binary-index/static/binaries.jsonl').read_text(encoding='utf-8').splitlines()]
    module, = [m for m in modules if m['file'] == 'Porsche.exe']
    data = (ROOT / 'local/game' / module['path']).read_bytes()
    if module['sha256'] != SHA or hashlib.sha256(data).hexdigest() != SHA:
        raise RuntimeError('original SHA256 mismatch')
    rng = random.Random(494000)
    vectors = [('head_on', [-10., 0., 0.], [1., 0., 0.]),
               ('departing', [10., 1., 4.], [1., 0., 0.]),
               ('stationary', [0., 0., 0.], [1., 0., 0.]),
               ('tangent', [0., 2., 40.], [1., 0., 0.]),
               ('glancing', [-.1, 2., 40.], [1., 0., 0.])]
    for index in range(27):
        angle = rng.uniform(-math.pi, math.pi)
        vectors.append((f'oblique_{index}', [rng.uniform(-80, 80) for _ in range(3)],
                        [math.cos(angle), 0., math.sin(angle)]))
    results = []
    for name, velocity, normal in vectors:
        for alternate in (False, True):
            fixture = {'name': name + ('_alternate' if alternate else ''),
                       'velocity': list(map(f32, velocity)), 'normal': list(map(f32, normal)),
                       'correction': list(map(f32, [.125, -.25, .5])),
                       'alternate': alternate, 'surface': rng.choice([0, 0x10, 0x20, 0x60, 0xff])}
            results.append(run_case(module, data, fixture))
    output = {'module': 'Porsche.exe', 'sha256': SHA, 'entry': '0x4940ae',
              'scope': 'prepared geometry; angular callback disabled; original x86 scalar path in Unicorn 2.1.3',
              'cases_passed': len(results), 'results': results}
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(output, indent=2) + '\n', encoding='utf-8')
    print(f'{len(results)} original-x86 differential cases passed; {args.output}')


if __name__ == '__main__':
    main()
