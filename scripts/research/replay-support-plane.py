"""Execute unmodified Porsche.exe plane-normal and quad-gap helpers in Unicorn.

Only supplied four-vertex float geometry is tested; resource loading is excluded.
"""
import argparse
import importlib.util
import json
import math
from pathlib import Path
import struct
import subprocess

HERE = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('support', HERE / 'replay-support-polygons.py')
support = importlib.util.module_from_spec(spec)
spec.loader.exec_module(support)
response = support.response
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ESP, UC_X86_REG_EIP

RANGES = ((0x489f90, 0x48a060), (0x48a0a0, 0x48a148),
          (0x532880, 0x532898), (0x532b20, 0x532b45), (0x56e8f5, 0x56e93a))
VERT = response.CAR + 0x100
PTRS = response.CAR + 0x200
OUTPUT = response.CAR + 0x300
PACKED = response.CAR + 0x400


def run_case(module, data, name, vertices):
    uc = response.machine(module, data, RANGES)
    for i, point in enumerate(vertices):
        support.floats(uc, VERT + 16*i, [*point, 0.])
    support.words(uc, PTRS, [VERT + 16*i for i in range(4)])
    support.floats(uc, PACKED, [value for point in vertices[:3] for value in point])
    support.floats(uc, OUTPUT, [71., 72., 73.])
    support.words(uc, response.STACK, [response.EXIT, OUTPUT, PACKED])
    uc.reg_write(UC_X86_REG_ESP, response.STACK)
    uc.emu_start(0x489f90, response.EXIT, count=10000)
    if uc.reg_read(UC_X86_REG_EIP) != response.EXIT:
        raise RuntimeError(f'{name}: plane budget exhausted')
    returned = uc.reg_read(UC_X86_REG_EAX)
    if returned != OUTPUT:
        raise AssertionError(f'{name}: plane returned {returned:08x}, wanted output')
    normal = list(struct.unpack('<3f', uc.mem_read(OUTPUT, 12)))

    gap_machine = response.machine(module, data, RANGES)
    for i, point in enumerate(vertices):
        support.floats(gap_machine, VERT + 16*i, [*point, 0.])
    support.words(gap_machine, PTRS, [VERT + 16*i for i in range(4)])
    support.words(gap_machine, response.STACK, [response.EXIT, PTRS])
    gap_machine.reg_write(UC_X86_REG_ESP, response.STACK)
    gap_machine.emu_start(0x48a0a0, response.EXIT + 6, count=10000)
    if gap_machine.reg_read(UC_X86_REG_EIP) != response.EXIT + 6:
        raise RuntimeError(f'{name}: gap budget exhausted at {gap_machine.reg_read(UC_X86_REG_EIP):08x}')
    gap_bits, = struct.unpack('<I', gap_machine.mem_read(response.RESULT, 4))
    gap = struct.unpack('<f', struct.pack('<I', gap_bits))[0]
    return {'name': name, 'vertices': vertices, 'normal': normal,
            'normal_bits': [struct.unpack('<I', struct.pack('<f', x))[0] for x in normal],
            'gap_bits': gap_bits, 'gap': gap if math.isfinite(gap) else None}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--fixture-tsv', type=Path, required=True)
    parser.add_argument('--source-output', type=Path)
    parser.add_argument('--split-fixture-tsv', type=Path)
    args = parser.parse_args()
    binaries = response.ROOT / 'research/binary-index/static/binaries.jsonl'
    module, = [m for m in map(json.loads, binaries.read_text(encoding='utf-8').splitlines())
               if m['file'] == 'Porsche.exe']
    data = (response.ROOT / 'local/game' / module['path']).read_bytes()
    if response.hashlib.sha256(data).hexdigest() != response.SHA or module['sha256'] != response.SHA:
        raise RuntimeError('original SHA256 mismatch')
    cases = [
        ('flat_up', [[0,0,0],[10,0,0],[10,0,10],[0,.2,10]]),
        ('flat_down', [[10,0,10],[10,0,0],[0,0,0],[0,.2,10]]),
        ('sloped', [[0,0,0],[10,1,0],[10,2,10],[0,3,10]]),
        ('vertical', [[0,0,0],[0,1,0],[0,2,10],[0,3,10]]),
        ('degenerate', [[0,0,0],[0,0,0],[0,0,0],[0,1,10]]),
        ('tiny', [[0,0,0],[.01,0,0],[.01,0,.01],[0,1,.01]]),
        ('near_threshold', [[0,0,0],[1,0,0],[1,0,.01],[0,.1,.01]]),
        ('above_threshold', [[0,0,0],[1,0,0],[1,0,.011],[0,.1,.011]]),
        ('negative_height', [[0,0,0],[10,0,0],[10,0,10],[0,-.2,10]]),
        ('shifted', [[2,3,4],[5,3.2,4],[5,3.5,8],[2,3.8,8]]),
    ]
    results = [run_case(module, data, name, [[response.f32(v) for v in p] for p in points])
               for name, points in cases]
    output = {'module': 'Porsche.exe', 'sha256': response.SHA,
              'entry_plane': '0x489f90', 'entry_gap': '0x48a0a0', 'cases': results}
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(output, indent=2, allow_nan=False) + '\n', encoding='utf-8')
    rows = ['name\tvertices\tnx_bits\tny_bits\tnz_bits\tgap_bits']
    for row in results:
        points = ','.join(str(value) for point in row['vertices'] for value in point)
        rows.append('\t'.join(map(str, [row['name'], points, *row['normal_bits'], row['gap_bits']])))
    args.fixture_tsv.write_text('\n'.join(rows) + '\n', encoding='utf-8')
    if args.split_fixture_tsv:
        prior = response.ROOT / 'iterations/012-campaign-fidelity/runs/013-original-support-query/support-replay.json'
        replay = json.loads(prior.read_text(encoding='utf-8'))
        if replay['sha256'] != response.SHA or replay['quad_split_cases_passed'] != 10:
            raise RuntimeError('Run 013 original split fixture mismatch')
        split_rows = ['flags\tvertices\tsplit']
        for row in replay['quad_splits']:
            points = ','.join(str(value) for point in row['vertices'] for value in point)
            split_rows.append(f"{row['flags']}\t{points}\t{int(row['original_split'])}")
        args.split_fixture_tsv.write_text('\n'.join(split_rows) + '\n', encoding='utf-8')
    if args.source_output:
        sources = [{'module': 'Porsche.exe', 'sha256': response.SHA}]
        for address in (0x489f90, 0x48a0a0, 0x532880, 0x532b20, 0x56e8f5):
            command = ['py', '-3', str(HERE / 'query-binary-index.py'), '--binary',
                       'Porsche.exe', '--address', hex(address), '--disassemble', '--limit', '300']
            records = [json.loads(line) for line in subprocess.check_output(
                command, cwd=response.ROOT, text=True, encoding='utf-8').splitlines()]
            sources.extend(record for record in records if record.get('kind') == 'disassembly')
        args.source_output.parent.mkdir(parents=True, exist_ok=True)
        args.source_output.write_text(''.join(json.dumps(record) + '\n' for record in sources), encoding='utf-8')
    print(f'{len(results)} original-x86 plane/gap cases passed; {args.output}')


if __name__ == '__main__':
    main()
