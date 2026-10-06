"""Execute bounded Porsche.exe wheel branch and material-height state consumers.

The original bytes at 0x494480 and 0x499730 run unchanged in Unicorn. The
polygon callbacks also run unchanged; only supplied car/polygon inputs are
synthetic. This is not the full four-wheel force loop at 0x499a70.
"""
import argparse
import importlib.util
import json
from pathlib import Path
import struct

HERE = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('support', HERE / 'replay-support-polygons.py')
s = importlib.util.module_from_spec(spec)
spec.loader.exec_module(s)
r = s.response
from unicorn.x86_const import UC_X86_REG_ESP, UC_X86_REG_EIP

OWNER = s.OWNER
QUERY = r.NORMAL
EXTRA = ((0x494480, 0x4944f7), (0x474420, 0x47442d),
         (0x474320, 0x474420), (0x4745f0, 0x47460c),
         (0x485b10, 0x485b2a), (0x485b50, 0x485c41),
         (0x485f90, 0x48602c), (0x486030, 0x48604f),
         (0x532880, 0x532898), (0x5328d0, 0x532902),
         (0x532b20, 0x532b45), (0x56e8f5, 0x56e93a))


def getf(uc, address):
    return struct.unpack('<f', uc.mem_read(address, 4))[0]


def branch_case(module, data, name, flags, reference, point):
    poly = [[0., 2., 0.], [0., 2., 10.], [10., 2., 0.]]
    uc = s.make(module, data, poly, flags or 1, EXTRA)
    s.words(uc, OWNER + 0x28, [s.OBJ])
    s.words(uc, OWNER + 0x24, [flags])
    s.floats(uc, r.CAR + 0x334, [reference])
    s.floats(uc, QUERY, point)
    result = s.execute(uc, 0x494480, [r.CAR, OWNER, QUERY], r.CAR)
    return {'name': name, 'flags': flags, 'reference': reference,
            'point': point, 'result': result}


def noise_case(module, data, name, speed, material, phase, previous, current, seed, gate=1., multiplier=0x10001):
    uc = r.machine(module, data, ((0x499730, 0x49988b),))
    wheel = r.CAR + 0x824
    s.floats(uc, r.CAR + 0x3a0, [gate])
    s.floats(uc, r.CAR + 0x35c, [speed])
    s.words(uc, wheel + 0x20, [material])  # car+0x844
    s.floats(uc, wheel + 0x10, [phase])    # car+0x834
    s.floats(uc, wheel + 0x0c, [current])  # car+0x830
    s.floats(uc, wheel + 0x08, [previous]) # car+0x82c
    s.words(uc, 0x5d1028, [seed])
    s.words(uc, 0x5d102c, [multiplier])
    s.words(uc, 0x655a0c, [999])
    s.words(uc, r.STACK, [r.EXIT, r.CAR, 0])
    uc.reg_write(UC_X86_REG_ESP, r.STACK)
    uc.emu_start(0x499730, r.EXIT + 6, count=10000)
    if uc.reg_read(UC_X86_REG_EIP) != r.EXIT + 6:
        raise RuntimeError(f'{name}: original 0x499730 did not return')
    return {'name': name, 'speed': speed, 'material': material, 'phase': phase,
            'previous': previous, 'current': current, 'seed': seed,
            'height': getf(uc, r.RESULT), 'next_phase': getf(uc, wheel + 0x10),
            'next_previous': getf(uc, wheel + 0x08),
            'next_current': getf(uc, wheel + 0x0c),
            'next_seed': struct.unpack('<I', uc.mem_read(0x5d1028, 4))[0],
            'gate': gate, 'multiplier': multiplier,
            'next_product': struct.unpack('<I', uc.mem_read(0x655a0c, 4))[0]}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--run-dir', type=Path, default=r.ROOT / 'iterations/012-campaign-fidelity/runs/019-original-contact-runtime')
    args = parser.parse_args()
    modules = [m for m in map(json.loads, (r.ROOT / 'research/binary-index/static/binaries.jsonl').read_text(encoding='utf8').splitlines()) if m['file'] == 'Porsche.exe']
    module, = modules
    data = (r.ROOT / 'local/game' / module['path']).read_bytes()
    if r.hashlib.sha256(data).hexdigest() != r.SHA or module['sha256'] != r.SHA:
        raise RuntimeError('original Porsche.exe SHA mismatch')
    branches = [branch_case(module, data, *case) for case in (
        ('flat', 0, 100., [2., 30., 2.]),
        ('contact', 1, 0., [2., 30., 2.]),
        ('far', 1, 10., [2., 30., 2.]),
        ('boundary', 1, 6., [2., 30., 2.]),
        ('other_material', 10, 0., [2., 30., 2.]),
    )]
    noise = [noise_case(module, data, *case) for case in (
        ('below_period', 0., 3, .1, .2, .4, 123),
        ('wrap_rough', 30., 3, .49, .2, .4, 123),
        ('rough_reset', 30., 3, 2.49, .2, .4, 123),
        ('wrap_smooth', 30., 1, .49, .2, .4, 123),
        ('negative_reset', 0., 2, -.1, .2, .4, 123),
        ('material_2', 0., 2, .1, .2, .4, 123),
        ('material_4', 0., 4, .1, .2, .4, 123),
    )]
    noise += [noise_case(module, data, f'material_{material}_rng', 30., material, 2.49,
                        .2, .4, 123, multiplier=16807) for material in range(16)]
    noise += [noise_case(module, data, f'period_{phase}', 0., 3, phase, .2, .4, 123,
                        multiplier=16807) for phase in (2.5, r.f32(2.5-2**-22), r.f32(2.5+2**-22))]
    noise += [noise_case(module, data, f'gate_{gate}', 30., 3, 2.49, .2, .4, 123,
                        gate=gate, multiplier=16807) for gate in (0., r.f32(.86), r.f32(.86-2**-24))]
    args.run_dir.mkdir(parents=True, exist_ok=True)
    (args.run_dir / 'wheel-state-replay.json').write_text(json.dumps({
        'module': 'Porsche.exe', 'sha256': r.SHA,
        'branch_cases': branches, 'material_cases': noise,
        'scope': '0x494480 and 0x499730; full 0x499a70 wheel force loop excluded',
    }, indent=2) + '\n', encoding='utf8')
    rows = ['name\tflags\treference\tpoint\tresult']
    rows.extend(f"{c['name']}\t{c['flags']}\t{c['reference']}\t{','.join(map(str,c['point']))}\t{c['result']}" for c in branches)
    (args.run_dir / 'wheel-branch-fixtures.tsv').write_text('\n'.join(rows)+'\n', encoding='utf8')
    rows = ['name\tspeed\tmaterial\tphase\tprevious\tcurrent\tseed\theight\tnext_phase\tnext_previous\tnext_current\tnext_seed\tgate\tmultiplier\tnext_product']
    rows.extend('\t'.join(str(c[key]) for key in ('name','speed','material','phase','previous','current','seed','height','next_phase','next_previous','next_current','next_seed','gate','multiplier','next_product')) for c in noise)
    (args.run_dir / 'wheel-material-fixtures.tsv').write_text('\n'.join(rows)+'\n', encoding='utf8')
    print(f'{len(branches)} branch and {len(noise)} material x86 cases captured')


if __name__ == '__main__':
    main()
