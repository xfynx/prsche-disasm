"""Probe original candidate construction and selected-edge geometry, no scene query.

Same dependency/setup as replay-contact-response.py. Hash-checked original x86
instructions execute without patches, with explicit entry/stop boundaries.
"""
import argparse
import importlib.util
import json
import math
from pathlib import Path
import struct

spec = importlib.util.spec_from_file_location('response', Path(__file__).with_name('replay-contact-response.py'))
response = importlib.util.module_from_spec(spec)
spec.loader.exec_module(response)
from unicorn.x86_const import UC_X86_REG_ESP, UC_X86_REG_EIP, UC_X86_REG_ESI

f32 = response.f32


def put(uc, address, *values):
    uc.mem_write(address, struct.pack('<' + 'f' * len(values), *values))


def get(uc, address, count):
    return list(struct.unpack('<' + 'f' * count, uc.mem_read(address, count * 4)))


def check(expected, actual):
    for want, got in zip(expected, actual, strict=True):
        if not math.isclose(want, got, abs_tol=2e-6, rel_tol=2e-6):
            raise AssertionError(f'expected {want}, original {got}')


def run(module, data):
    helpers = ((0x532300, 0x53235c), (0x56e660, 0x56e6d7),
               (0x5328d0, 0x532902), (0x532b20, 0x532b45), (0x489f10, 0x489f89))
    candidates = []
    for angle in (0., .4, -1.2):
        uc = response.machine(module, data, helpers + ((0x495020, 0x495263),))
        position, extent = [10., 20., 30.], [1., .75, 2.]
        right = list(map(f32, [math.cos(angle), 0., -math.sin(angle)]))
        forward = list(map(f32, [math.sin(angle), 0., math.cos(angle)]))
        for offset, value in ((0x330, position), (0x33c, [12., 3., -8.]),
                              (0x364, right), (0x370, [0., 1., 0.]),
                              (0x37c, forward), (0x3a8, extent)):
            put(uc, response.CAR + offset, *value)
        uc.mem_write(response.STACK + 4, struct.pack('<I', response.CAR))
        uc.reg_write(UC_X86_REG_ESP, response.STACK)
        uc.emu_start(0x495020, 0x495263, count=10000)
        if uc.reg_read(UC_X86_REG_EIP) != 0x495263:
            raise RuntimeError('candidate instruction budget exhausted')
        base = uc.reg_read(UC_X86_REG_ESP)
        actual = get(uc, base + 0xc8, 24)
        expected = []
        for height, length in ((-.75, 2.), (.75, 1.)):
            for end in (1., -1.):
                for side in (-1., 1.):
                    center = [10., 20. + height, 30.]
                    expected.extend(f32(f32(p + end*f32(f*length)) + side*r)
                                    for p, f, r in zip(center, forward, right))
        check(expected, actual)
        candidates.append({'angle': angle, 'right': right, 'forward': forward,
                           'position': position, 'extents': extent, 'original_points': actual})
    edges = []
    for a, b in (([0., 2., 0.], [10., 3., 0.]), ([0., 0., 0.], [0., 0., 10.]),
                 ([2., 10., -3.], [8., -4., 5.])):
        for start, end in ((a, b), (b, a)):
            for point in ([4., 7., 3.], [-20., -3., 30.]):
                uc = response.machine(module, data, helpers + ((0x49542d, 0x4954ff),))
                put(uc, response.STACK + 0xb0, *start, *end)
                put(uc, response.NORMAL, *point)
                uc.reg_write(UC_X86_REG_ESI, response.NORMAL)
                uc.reg_write(UC_X86_REG_ESP, response.STACK)
                uc.emu_start(0x49542d, 0x4954f1, count=10000)
                if uc.reg_read(UC_X86_REG_EIP) != 0x4954f1:
                    raise RuntimeError('edge instruction budget exhausted')
                dx, dz = end[0]-start[0], end[2]-start[2]
                length = math.hypot(dx, dz)
                t = f32(((point[0]-start[0])*dx + (point[2]-start[2])*dz)/(dx*dx+dz*dz))
                projected = [f32(start[0]+dx*t), 0., f32(start[2]+dz*t)]
                normal = list(map(f32, [-dz/length, 0., dx/length]))
                displacement = [f32(f32(projected[0]-point[0])*f32(1.01)), 0.,
                                f32(f32(projected[2]-point[2])*f32(1.01))]
                actual_n = get(uc, response.STACK + 0x24, 3)
                actual_d = get(uc, response.STACK + 0x34, 3)
                check(normal, actual_n)
                check(displacement, actual_d)
                edges.append({'a': start, 'b': end, 'point': point,
                              'original_normal': actual_n, 'original_displacement': actual_d})
    return {'module': 'Porsche.exe', 'sha256': response.SHA,
            'scope': 'candidate generation and selected-edge preparation; scene selection excluded',
            'candidate_cases_passed': len(candidates), 'edge_cases_passed': len(edges),
            'candidates': candidates, 'edges': edges}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    inventory = response.ROOT / 'research/binary-index/static/binaries.jsonl'
    module, = [m for m in map(json.loads, inventory.read_text(encoding='utf-8').splitlines()) if m['file'] == 'Porsche.exe']
    data = (response.ROOT / 'local/game' / module['path']).read_bytes()
    if response.hashlib.sha256(data).hexdigest() != response.SHA or module['sha256'] != response.SHA:
        raise RuntimeError('original SHA256 mismatch')
    result = run(module, data)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(result, indent=2) + '\n', encoding='utf-8')
    print(f"{result['candidate_cases_passed']} candidate / {result['edge_cases_passed']} selected-edge original-x86 cases passed")


if __name__ == '__main__':
    main()
