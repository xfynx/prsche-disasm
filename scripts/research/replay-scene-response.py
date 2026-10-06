"""Replay complete 0x494000 support-dependent preparation and response.

The tree/owner and all game callees execute unchanged original instructions.
Synthetic finite car/scene inputs are explicit; no gameplay field binding is
inferred. Imported critical sections use the existing single-thread model.
"""
import argparse
import importlib.util
import json
from pathlib import Path
import struct

HERE = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('owner', HERE / 'replay-support-owner.py')
o = importlib.util.module_from_spec(spec)
spec.loader.exec_module(o)
t, s, r = o.t, o.s, o.r
from unicorn.x86_const import UC_X86_REG_ESP, UC_X86_REG_EIP

CAR = t.GEOMETRY + 0xe000
POINT, DISPLACEMENT = r.NORMAL + 0x80, r.NORMAL + 0xc0
CAPTURE = r.EXIT + 0x200


def get(uc, address, count=1):
    return list(struct.unpack('<' + 'f' * count, uc.mem_read(address, count * 4)))


def run_case(module, data, name, polygons, cached, point, displacement, velocity, angular, alternate):
    ranges = o.EXTRA + o.TREE_RANGES + (
        (0x485630, 0x485780), (0x485ea0, 0x486090),
        (0x494000, 0x4943a0), (0x532300, 0x53235c),
        (0x56e660, 0x56e6d7), (CAPTURE, CAPTURE + 6))
    uc, _ = t.machine(module, data, ranges, polygons, 0)
    for index in range(len(polygons)):
        t.execute(uc, 0x484ae0, [r.CAR + index * 0x80], t.NODE)
    s.words(uc, 0x628960, [t.SCENE])
    s.words(uc, t.SCENE + 0x24, [t.HOLDER])
    s.words(uc, t.HOLDER, [t.NODE])
    s.words(uc, t.OWNER, [0] * 16)
    if cached is not None:
        s.floats(uc, POINT, cached)
        t.execute(uc, 0x474060, [POINT, 1], t.OWNER)
    # 0x494000 takes a private copy of car+8. It must not mutate the car owner.
    original_owner = bytes(uc.mem_read(t.OWNER, 48))
    uc.mem_write(CAR + 8, original_owner)
    s.floats(uc, CAR + 0x330, [2., 3., 2.])
    s.floats(uc, CAR + 0x33c, velocity)
    s.floats(uc, CAR + 0x35c, [r.approximate_speed(velocity)])
    for offset, value in ((0x364, [1., 0., 0.]), (0x370, [0., 1., 0.]),
                          (0x37c, [0., 0., 1.]), (0x490, [0., 0., -1.]),
                          (0x4a8, [1., 0., 0.]), (0xd58, [11., 12., 25.])):
        s.floats(uc, CAR + offset, value)
    for offset in r.WHEELS:
        s.floats(uc, CAR + offset, [4., 5., 6.])
        s.floats(uc, CAR + offset + 0x78, [9.])
    s.floats(uc, CAR + 0x38c, [.375])
    s.floats(uc, CAR + 0x434, [1234.])
    s.floats(uc, CAR + 0xdb8, [7.])
    s.floats(uc, CAR + 0xdc0, [8.])
    uc.mem_write(CAR + 0x52c, bytes([4 if alternate else 0]))
    normal = [1., 0., 0.]
    s.floats(uc, r.NORMAL, normal)
    s.floats(uc, POINT, point)
    s.floats(uc, DISPLACEMENT, displacement)
    uc.mem_write(CAPTURE, b'\xd9\x1d' + struct.pack('<I', r.RESULT))
    s.words(uc, r.STACK, [CAPTURE, CAR, r.NORMAL, POINT, DISPLACEMENT, int(angular)])
    uc.reg_write(UC_X86_REG_ESP, r.STACK)
    uc.emu_start(0x494000, 0x4940ae, count=100000)
    if uc.reg_read(UC_X86_REG_EIP) != 0x4940ae:
        raise RuntimeError('preparation did not reach response')
    prepared = get(uc, r.STACK - 0x48, 3)
    selected_pointer = t.words(uc, r.STACK - 0x30 + 0x28, 1)[0]
    selected = None if selected_pointer == 0 else o.selected(selected_pointer, len(polygons))
    uc.emu_start(0x4940ae, CAPTURE + 6, count=100000)
    if uc.reg_read(UC_X86_REG_EIP) != CAPTURE + 6:
        raise RuntimeError(f'response stopped at {uc.reg_read(UC_X86_REG_EIP):08x}, esp={uc.reg_read(UC_X86_REG_ESP):08x}')
    if bytes(uc.mem_read(CAR + 8, 48)) != original_owner:
        raise AssertionError('source response changed the persistent owner')
    return dict(name=name, polygons=polygons, cached=cached, point=point,
                displacement=displacement, velocity=velocity, angular=angular,
                alternate=alternate, selected=selected, prepared=prepared,
                original=dict(position=get(uc, CAR + 0x330, 3),
                              velocity=get(uc, CAR + 0x33c, 3),
                              speed=get(uc, CAR + 0x35c),
                              local=get(uc, CAR + 0xd58, 3),
                              angular=get(uc, CAR + 0x38c),
                              field434=get(uc, CAR + 0x434),
                              wheels=[get(uc, CAR + off, 3) for off in r.WHEELS],
                              wheel_fields=[get(uc, CAR + off + 0x78)[0] for off in r.WHEELS],
                              db8=get(uc, CAR + 0xdb8), dc0=get(uc, CAR + 0xdc0),
                              magnitude=get(uc, r.RESULT)))


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--run-dir', type=Path,
                        default=r.ROOT / 'iterations/012-campaign-fidelity/runs/019-original-contact-runtime')
    args = parser.parse_args()
    module, = [m for m in map(json.loads, (r.ROOT / 'research/binary-index/static/binaries.jsonl').read_text(encoding='utf8').splitlines()) if m['file'] == 'Porsche.exe']
    data = (r.ROOT / 'local/game' / module['path']).read_bytes()
    if r.hashlib.sha256(data).hexdigest() != r.SHA or module['sha256'] != r.SHA:
        raise RuntimeError('original SHA mismatch')
    tri = [[0., 0., 0.], [0., 0., 10.], [10., 0., 0.]]
    high = [[x, 10., z] for x, _, z in tri]
    rows = []
    for label, point, displacement, cached in (
        ('inside', [2., 1., 2.], [.125, -.25, .5], None),
        ('outside', [20., 1., 20.], [.125, -.25, .5], [2., 1., 2.]),
        ('cross_out', [2., 1., 2.], [20., 0., 20.], [2., 1., 2.]),
        ('cross_in', [20., 1., 20.], [-18., 0., -18.], None),
        ('fresh_high', [2., 9., 2.], [.125, 0., .5], [2., 1., 2.])):
        for velocity in ([-10., 2., 3.], [10., 2., 3.], [-.1, 2., 40.]):
            for angular, alternate in ((False, False), (True, False), (True, True)):
                name = f'{label}_{velocity[0]}_{int(angular)}_{int(alternate)}'
                rows.append(run_case(module, data, name, [tri, high], cached,
                                     point, displacement, velocity, angular, alternate))
    args.run_dir.mkdir(parents=True, exist_ok=True)
    (args.run_dir / 'scene-response-replay.json').write_text(json.dumps(
        dict(module='Porsche.exe', sha256=r.SHA, entry='0x494000', cases=rows,
             excluded=['live car producer binding', 'mixed scene objects', 'surface effect code outputs']),
        indent=2) + '\n', encoding='utf8', newline='\n')
    header = ['name', 'cached', 'point', 'displacement', 'velocity', 'angular',
              'alternate', 'selected', 'prepared', 'position', 'next_velocity',
              'speed', 'local', 'next_angular', 'field434', 'wheels',
              'wheel_fields', 'db8', 'dc0', 'magnitude']
    def cell(value):
        if value is None:
            return '-'
        if isinstance(value, bool):
            return str(int(value))
        if isinstance(value, list):
            return ','.join(cell(x) for x in value)
        return str(value)
    lines = ['\t'.join(header)]
    for row in rows:
        original = row['original']
        values = [row[k] for k in header[:9]] + [original[k] for k in
                  ('position', 'velocity', 'speed', 'local', 'angular',
                   'field434', 'wheels', 'wheel_fields', 'db8', 'dc0', 'magnitude')]
        lines.append('\t'.join(map(cell, values)))
    (args.run_dir / 'scene-response-fixtures.tsv').write_text('\n'.join(lines) + '\n',
                                                            encoding='utf8', newline='\n')
    print(f'{len(rows)} complete original scene-dependent responses captured')


if __name__ == '__main__':
    main()
