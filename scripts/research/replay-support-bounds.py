"""Bounded original x86 replay: support center/bounds and node/object overlap."""
import argparse
import importlib.util
import json
from pathlib import Path
import random
import subprocess
import struct

spec = importlib.util.spec_from_file_location('support', Path(__file__).with_name('replay-support-polygons.py'))
support = importlib.util.module_from_spec(spec)
spec.loader.exec_module(support)
response = support.response

BOUNDS = response.CAR + 0x1a00
NODE = response.CAR + 0x1b00
RANGES = ((0x484320, 0x484450), (0x485630, 0x485780),
          (0x485ea0, 0x485f8a))


def vec(uc, address):
    return list(struct.unpack('<3f', uc.mem_read(address, 12)))


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--run-dir', type=Path, required=True)
    parser.add_argument('--source-output', type=Path)
    args = parser.parse_args()
    module, = [m for m in map(json.loads, (response.ROOT/'research/binary-index/static/binaries.jsonl').read_text(encoding='utf-8').splitlines()) if m['file'] == 'Porsche.exe']
    data = (response.ROOT/'local/game'/module['path']).read_bytes()
    if module['sha256'] != response.SHA or response.hashlib.sha256(data).hexdigest() != response.SHA:
        raise RuntimeError('original SHA mismatch')

    shapes = [
        [[-3., 2., -5.], [7., 3., -2.], [1., -4., 8.]],
        [[-3., 2., -5.], [7., 3., -2.], [8., -4., 8.], [-2., 9., 5.]],
        [[0., 0., 0.], [1., 0., 0.], [0., 0., 1.]],
        [[-1., 0., -1.], [1., 0., -1.], [1., 0., 1.], [-1., 0., 1.]],
        [[1., 0., 1.], [1., 2., 1.], [1., -3., 1.]],
        [[1., 0., 1.], [2., 2., 1.], [1., -3., 2.], [2., 4., 2.]],
    ]
    rng = random.Random(0x485630)
    for count in (3, 4):
        for _ in range(16):
            shapes.append([[float(rng.randint(-20, 20)) / 4 for _ in range(3)] for _ in range(count)])
    rows = []
    predicate = []
    for points in shapes:
        count = len(points)
        uc = support.make(module, data, points, extra_ranges=RANGES)
        table = struct.unpack('<I', uc.mem_read(support.OBJ, 4))[0]
        callbacks = struct.unpack('<2I', uc.mem_read(table+4, 8))
        assert callbacks == ((0x485e40, 0x485ea0) if count == 3 else (0x4855c0, 0x485630))
        support.floats(uc, BOUNDS, [101., 102., 103., 104., 105., 106., 107., 108., 109.])
        support.execute(uc, callbacks[0], [BOUNDS], support.OBJ)
        center = vec(uc, BOUNDS)
        support.execute(uc, callbacks[1], [BOUNDS+12, BOUNDS+24], support.OBJ)
        lower, upper = vec(uc, BOUNDS+12), vec(uc, BOUNDS+24)
        rows.append({'vertices': points, 'center': center, 'lower': lower, 'upper': upper})

        # The node word and global width table/extent are the exact inputs of 0x484320.
        # Vary both overlap and early center-accept branches; Y is a sentinel.
        for x, z, width, extent in ((0, 0, 1., 0.), (1, 1, 1., 0.),
                                    (0, 0, 8., 0.), (2, 2, 8., 0.),
                                    (10, 10, 1., 0.), (0, 0, 32., 0.),
                                    (1, 1, .3, .125), (3, 0, 5.25, 2.25)):
            support.words(uc, NODE, [(z << 14) | x])
            support.floats(uc, 0x628be8, [width])
            support.floats(uc, 0x628c30, [extent])
            actual = support.execute(uc, 0x484320, [support.OBJ], NODE) & 255
            predicate.append({'vertices': points, 'x': x, 'z': z,
                              'width': width, 'extent': extent, 'result': actual})

    args.run_dir.mkdir(parents=True, exist_ok=True)
    (args.run_dir/'bounds-replay.json').write_text(json.dumps({'module': 'Porsche.exe', 'sha256': response.SHA,
        'center_bounds_cases': len(rows), 'predicate_cases': len(predicate),
        'scope': 'original type-1 callbacks and 0x484320; object constructors original; no patched instructions'}, indent=2)+'\n', encoding='utf-8')
    (args.run_dir/'bounds-fixtures.json').write_text(json.dumps({'callbacks': rows, 'predicate': predicate}, indent=2)+'\n', encoding='utf-8')
    (args.run_dir/'bounds-callback-fixtures.tsv').write_text(
        'count\tvertices\tcenter\tlower\tupper\n' +
        ''.join(f"{len(row['vertices'])}\t{','.join(str(v) for p in row['vertices'] for v in p)}\t"
                f"{','.join(map(str,row['center']))}\t{','.join(map(str,row['lower']))}\t"
                f"{','.join(map(str,row['upper']))}\n" for row in rows), encoding='utf-8')
    (args.run_dir/'bounds-predicate-fixtures.tsv').write_text(
        'count\tvertices\twidth\textent\tx\tz\tresult\n' +
        ''.join(f"{len(row['vertices'])}\t{','.join(str(v) for p in row['vertices'] for v in p)}\t"
                f"{row['width']}\t{row['extent']}\t{row['x']}\t{row['z']}\t{row['result']}\n"
                for row in predicate), encoding='utf-8')
    if args.source_output:
        source = []
        for address, size in ((0x484320, 0x130), (0x4855c0, 0x70),
                              (0x485630, 0x148), (0x485e40, 0x60), (0x485ea0, 0xea),
                              (0x5b2468, 4), (0x5b2680, 4)):
            query = subprocess.run(['py', '-3', 'scripts/research/query-binary-index.py',
                                    '--binary', 'Porsche.exe', '--address', hex(address),
                                    '--disassemble', '--limit', '300'], cwd=response.ROOT,
                                   capture_output=True, text=True, check=True)
            raw = subprocess.run(['py', '-3', 'scripts/research/inspect-pe-range.py',
                                  '--binary', 'Porsche.exe', '--address', hex(address),
                                  '--size', hex(size)], cwd=response.ROOT,
                                 capture_output=True, text=True, check=True)
            source.append({'module': 'Porsche.exe', 'sha256': response.SHA,
                           'address': hex(address), 'index_query': query.stdout.splitlines(),
                           'raw_decode': raw.stdout.splitlines()})
        args.source_output.parent.mkdir(parents=True, exist_ok=True)
        args.source_output.write_text(''.join(json.dumps(row)+'\n' for row in source), encoding='utf-8')
    print(f'{len(rows)} center/bounds and {len(predicate)} node/object original-x86 cases')


if __name__ == '__main__':
    main()
