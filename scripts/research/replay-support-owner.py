"""Capture original type-1 owner polygon cache, normal and plane point.

Runs unchanged Porsche.exe instructions, including tree insertion and query,
polygon callbacks, cross/normalization and owner wrapper. Only imported Win32
critical-section services use the existing single-thread platform model.
"""
import argparse
import importlib.util
import json
from pathlib import Path
import struct

HERE = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('tree', HERE / 'replay-support-tree.py')
t = importlib.util.module_from_spec(spec)
spec.loader.exec_module(t)
s, r = t.s, t.r
from unicorn.x86_const import (UC_X86_REG_EAX, UC_X86_REG_EBX, UC_X86_REG_EBP,
                              UC_X86_REG_ECX, UC_X86_REG_ESI, UC_X86_REG_ESP)

EXTRA = ((0x474060, 0x4740cb), (0x474320, 0x474420),
         (0x474420, 0x47442d), (0x4745f0, 0x47460c),
         (0x485b10, 0x485b2a), (0x486030, 0x48604f),
         (0x485b50, 0x485c41), (0x485f90, 0x48602c),
         (0x532880, 0x532898), (0x5328d0, 0x532902),
         (0x532b20, 0x532b45), (0x499c40, 0x499c7f),
         (0x56e8f5, 0x56e93a))

# Reuse Run 017's exact indexed function ranges for the original insertion,
# allocator and cached tree query rather than widening execution to all .text.
TREE_SOURCE = r.ROOT / 'iterations/012-campaign-fidelity/research/original-collision/support-tree-source.jsonl'
TREE_RANGES = tuple((int(a, 16), int(b, 16) + 1)
                    for row in map(json.loads, TREE_SOURCE.read_text(encoding='utf8').splitlines())
                    if row.get('kind') == 'function' for a, b in row['ranges'])


def f32(uc, address, count):
    return struct.unpack('<' + 'f' * count, uc.mem_read(address, count * 4))


def selected(pointer, length):
    if pointer == 0:
        return '-'
    index, rem = divmod(pointer - r.CAR, 0x80)
    if rem or not 0 <= index < length:
        raise RuntimeError('invalid original selected polygon pointer')
    return index


def original_plane_height(uc, query, normal, base_ptr):
    """Execute 0x499c40..0x499c7b, stopping before unrelated 0x499730."""
    p = r.STACK - 0x100
    s.floats(uc, r.NORMAL, query)
    s.floats(uc, p + 0x1c, normal)
    uc.reg_write(UC_X86_REG_EAX, base_ptr)
    uc.reg_write(UC_X86_REG_EBX, r.NORMAL)
    uc.reg_write(UC_X86_REG_EBP, 0)
    uc.reg_write(UC_X86_REG_ECX, 0)
    uc.reg_write(UC_X86_REG_ESI, 0)
    uc.reg_write(UC_X86_REG_ESP, p)
    uc.emu_start(0x499c40, 0x499c7f, count=100)
    return f32(uc, p + 0x64, 1)[0]


def run_case(module, data, name, polygons, steps):
    uc, services = t.machine(module, data,
                             EXTRA + TREE_RANGES + ((0x485630, 0x485780),
                                                    (0x485ea0, 0x486090)),
                             polygons, 0)
    for index in range(len(polygons)):
        t.execute(uc, 0x484ae0, [r.CAR + index * 0x80], t.NODE)
    s.words(uc, 0x628960, [t.SCENE])
    s.words(uc, t.SCENE + 0x24, [t.HOLDER])
    s.words(uc, t.HOLDER, [t.NODE])
    s.words(uc, t.OWNER, [0] * 16)
    rows = []
    for point, reuse in steps:
        s.floats(uc, r.NORMAL, point)
        t.execute(uc, 0x474060, [r.NORMAL, int(reuse)], t.OWNER)
        pointer = t.words(uc, t.OWNER + 0x28, 1)[0]
        index = selected(pointer, len(polygons))
        normal = None
        base = None
        if index != '-':
            normal_ptr = t.execute(uc, 0x474420, [], t.OWNER)
            base_ptr = t.execute(uc, 0x4745f0, [0], t.OWNER)
            normal = f32(uc, normal_ptr, 3)
            base = f32(uc, base_ptr, 3)
        height = None if normal is None else original_plane_height(uc, point, normal, base_ptr)
        node = t.words(uc, t.OWNER + 0x2c, 1)[0]
        node_code = t.words(uc, node, 1)[0] if node else '-'
        rows.append({'case': name, 'vertices': polygons, 'point': point,
                     'reuse': int(reuse), 'polygon': index, 'node': node_code,
                     'normal': normal, 'base': base,
                     'height': height,
                     'word': t.words(uc, t.OWNER + 0x24, 1)[0] & 0xffff,
                     'changed': uc.mem_read(t.OWNER + 9, 1)[0]})
    if t.words(uc, t.CRITICAL, 6)[1:4] != [0xffffffff, 0, 0] or services[0] != services[1]:
        raise RuntimeError('unbalanced platform critical-section state')
    return rows


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        '--run-dir', type=Path,
        default=r.ROOT / 'iterations/012-campaign-fidelity/runs/018-original-support-runtime')
    args = parser.parse_args()
    module, = [m for m in map(json.loads, (r.ROOT / 'research/binary-index/static/binaries.jsonl').read_text(encoding='utf8').splitlines()) if m['file'] == 'Porsche.exe']
    data = (r.ROOT / 'local/game' / module['path']).read_bytes()
    if r.hashlib.sha256(data).hexdigest() != r.SHA or module['sha256'] != r.SHA:
        raise RuntimeError('original SHA mismatch')
    tri = [[0., 0., 0.], [0., 0., 10.], [10., 0., 0.]]
    tri_high = [[x, 10., z] for x, _, z in tri]
    slope = [[0., 0., 0.], [0., 2., 10.], [10., 4., 0.]]
    quad = [[0., 0., 0.], [0., 2., 10.], [10., 4., 10.], [10., 1., 0.]]
    cases = [
        ('stacked', [tri, tri_high], [([1., 1., 1.], 1), ([1., 9., 1.], 1),
                                     ([1., 9., 1.], 0), ([20., 0., 20.], 1)]),
        ('triangle_slope', [slope], [([2., 3., 2.], 1), ([2., 8., 2.], 0)]),
        ('triangle_reverse', [list(reversed(slope))], [([2., 3., 2.], 1)]),
        ('quad_twist', [quad], [([2., 3., 2.], 1), ([5., 0., 5.], 1)]),
        ('quad_reverse', [list(reversed(quad))], [([2., 3., 2.], 1)]),
    ]
    rows = [row for name, polygons, steps in cases
            for row in run_case(module, data, name, polygons, steps)]
    args.run_dir.mkdir(parents=True, exist_ok=True)
    with (args.run_dir / 'owner-fixtures.tsv').open('w', encoding='utf8', newline='\n') as out:
        out.write('case\tvertices\tpoint\treuse\tpolygon\tnode\tnormal\tbase\theight\n')
        for row in rows:
            vertices = '/'.join(','.join(str(value) for point in poly for value in point)
                                for poly in row['vertices'])
            normal, base, point = row['normal'], row['base'], row['point']
            height = '-' if row['height'] is None else str(row['height'])
            cells = [row['case'], vertices, ','.join(map(str, point)), row['reuse'],
                     row['polygon'], row['node'],
                     '-' if normal is None else ','.join(map(str, normal)),
                     '-' if base is None else ','.join(map(str, base)), height]
            out.write('\t'.join(map(str, cells)) + '\n')
    (args.run_dir / 'owner-replay.json').write_text(
        json.dumps({'module': 'Porsche.exe', 'sha256': r.SHA, 'rows': rows,
                    'excluded': ['full wheel force law', 'mixed type scene',
                                 'concurrent Win32 locks', 'resource loader']}, indent=2) + '\n',
        encoding='utf8', newline='\n')
    print(f'{len(rows)} original owner selection/normal/point cases captured')


if __name__ == '__main__':
    main()
