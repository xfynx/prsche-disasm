"""Original mixed polygon/EDG tree and complete 0x4740d0 edge selection.

Constructors, insertion, splitting, leaf traversal, geometric predicates and
allocator run unchanged Porsche.exe bytes. The scene is synthetic and does
not stand in for 0x488090 resource assembly or live vehicle state.
"""
import argparse
import importlib.util
import json
from pathlib import Path
import struct
import subprocess

HERE = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('owner', HERE / 'replay-support-owner.py')
o = importlib.util.module_from_spec(spec)
spec.loader.exec_module(o)
t, s, r = o.t, o.s, o.r
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EBP

EDGE_BASE = r.CAR + 0x600
SEGMENT, OUTPUT, WORD = r.NORMAL + 0x100, r.NORMAL + 0x140, r.NORMAL + 0x180


def snapshot(uc, pointers):
    rows = []
    def visit(pointer):
        code, *fields = t.words(uc, pointer, 6)
        children, vector = fields[:4], fields[4]
        records = '-'
        if vector:
            begin, end, _ = t.words(uc, vector, 3)
            entries = []
            for address in range(begin, end, 8):
                kind, obj = t.words(uc, address, 2)
                label, expected_kind = pointers[obj]
                if kind & 255 != expected_kind:
                    raise RuntimeError('wrong typed record')
                entries.append(label)
            records = ','.join(entries) or '_'
        mask = sum(1 << slot for slot, child in enumerate(children) if child)
        rows.append(f'{code}:{mask}:{records}')
        for child in children:
            if child:
                visit(child)
    visit(t.NODE)
    return ';'.join(rows)


def run_case(module, data, ranges, name, polygons, edges, order, queries):
    uc, _ = t.machine(module, data, ranges, polygons, 0)
    pointers = {r.CAR + i * 0x80: (f'p{i}', 1) for i in range(len(polygons))}
    constructed = []
    for i, endpoints in enumerate(edges):
        source = t.GEOMETRY + 0x1000 + i * 0x40
        for j, point in enumerate(endpoints):
            s.floats(uc, source + j * 16, [*point, 0.])
        address = EDGE_BASE + i * 0x80
        t.execute(uc, 0x485100, [source, 10 + i], address)
        actual = [list(o.f32(uc, address + 0xc, 3)), list(o.f32(uc, address + 0x1c, 3))]
        constructed.append(actual)
        pointers[address] = (f'e{i}', 2)
    for label in order:
        index = int(label[1:])
        address = r.CAR + index * 0x80 if label[0] == 'p' else EDGE_BASE + index * 0x80
        t.execute(uc, 0x484ae0, [address], t.NODE)
    canonical = snapshot(uc, pointers)
    s.words(uc, 0x628960, [t.SCENE])
    s.words(uc, t.SCENE + 0x24, [t.HOLDER])
    s.words(uc, t.HOLDER, [t.NODE])
    s.words(uc, t.OWNER, [0] * 16)
    selected = [None]
    def observe(machine, address, _size, _user):
        if address == 0x4741fd:
            selected[0] = pointers[machine.reg_read(UC_X86_REG_EBP)][0]
    uc.hook_add(UC_HOOK_CODE, observe)
    outputs = []
    for segment, has_support in queries:
        # The polygon owner gate is part of original 0x4740d0; nonnull valid
        # pointer supplied explicitly, not a fake geometric callee.
        s.words(uc, t.OWNER + 0x28, [r.CAR if has_support else 0])
        s.floats(uc, SEGMENT, [v for point in segment for v in point])
        s.words(uc, WORD, [0x12345678])
        selected[0] = None
        result = t.execute(uc, 0x4740d0, [SEGMENT, OUTPUT, WORD], t.OWNER) & 255
        outputs.append(dict(segment=segment, has_support=has_support, hit=bool(result),
                            selected=selected[0], endpoints=None if not result else
                            [list(o.f32(uc, OUTPUT, 3)), list(o.f32(uc, OUTPUT + 12, 3))],
                            word=None if not result else t.words(uc, WORD, 1)[0] & 0xffff))
    return dict(name=name, polygons=polygons, edges=edges, constructed=constructed,
                order=order, tree=canonical, queries=outputs)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--run-dir', type=Path, default=r.ROOT / 'iterations/012-campaign-fidelity/runs/019-original-contact-runtime')
    args = parser.parse_args()
    module, = [m for m in map(json.loads, (r.ROOT / 'research/binary-index/static/binaries.jsonl').read_text(encoding='utf8').splitlines()) if m['file'] == 'Porsche.exe']
    data = (r.ROOT / 'local/game' / module['path']).read_bytes()
    if r.hashlib.sha256(data).hexdigest() != r.SHA:
        raise RuntimeError('original SHA mismatch')
    sources = [dict(module='Porsche.exe', sha256=r.SHA)]
    ranges = list(o.EXTRA + o.TREE_RANGES) + [(t.PLATFORM, t.PLATFORM + 19), (0x485630, 0x485780), (0x485ea0, 0x486090),
        (0x485100, 0x485201), (0x4852b0, 0x4853c0), (0x489cc0, 0x489dec)]
    for address in (0x4740d0, 0x484630, 0x42bcb0):
        output = subprocess.check_output(['py', '-3', str(HERE / 'query-binary-index.py'),
            '--binary', 'Porsche.exe', '--address', hex(address), '--disassemble', '--limit', '1000'],
            text=True, encoding='utf8', cwd=r.ROOT)
        for row in map(json.loads, output.splitlines()):
            if row.get('kind') == 'function':
                ranges.extend((int(a, 16), int(b, 16) + 1) for a, b in row['ranges'])
            if row.get('kind') in ('function', 'disassembly'):
                sources.append(row)
    polygons = [[[0., 0., 0.], [0., 0., 10.], [10., 0., 0.]]]
    edges = [[[-4., 0., 0.], [4., 0., 0.]], [[-4., 10., 0.], [4., 10., 0.]],
             [[4., 0., 0.], [-4., 0., 0.]], [[-200., 2., 0.], [0., 3., 0.]],
             [[0., 0., -4.], [0., 0., 4.]]]
    queries = [([[0., y, -2.], [0., y, 2.]], gate) for y in (0., 5., 9.) for gate in (True, False)]
    queries += [([[0., 0., 0.], [0., 0., 2.]], True),
                ([[20., 0., 20.], [30., 0., 30.]], True),
                ([[-2., 0., 0.], [2., 0., 0.]], True)]
    rows = []
    for name, order in [('leaf', ['p0'] + [f'e{i}' for i in range(5)]),
                        ('split', ['p0'] * 48 + [f'e{i}' for i in range(5)]),
                        ('reverse', [f'e{i}' for i in reversed(range(5))] + ['p0'] * 48)]:
        rows.append(run_case(module, data, ranges, name, polygons, edges, order, queries))
    args.run_dir.mkdir(parents=True, exist_ok=True)
    (args.run_dir / 'mixed-support-replay.json').write_text(json.dumps(
        dict(module='Porsche.exe', sha256=r.SHA, cases=rows, excluded=['resource scene assembly', 'special objects']),
        indent=2) + '\n', encoding='utf8', newline='\n')
    def encoded(points):
        return ','.join(str(v) for point in points for v in point)
    trees = ['name\tpolygons\tedges\tconstructed\torder\ttree']
    calls = ['name\tsegment\tgate\tselected\tendpoints\tword']
    for row in rows:
        trees.append('\t'.join([row['name'], '/'.join(map(encoded, row['polygons'])),
            '/'.join(map(encoded, row['edges'])), '/'.join(map(encoded, row['constructed'])),
            ','.join(row['order']), row['tree']]))
        for call in row['queries']:
            calls.append('\t'.join([row['name'], encoded(call['segment']), str(int(call['has_support'])),
                call['selected'] or '-', '-' if call['endpoints'] is None else encoded(call['endpoints']),
                '-' if call['word'] is None else str(call['word'])]))
    for filename, lines in [('mixed-tree-fixtures.tsv', trees), ('mixed-edge-fixtures.tsv', calls)]:
        (args.run_dir / filename).write_text('\n'.join(lines) + '\n', encoding='utf8', newline='\n')
    (args.run_dir / 'mixed-query-source.jsonl').write_text('\n'.join(json.dumps(row) for row in sources) + '\n', encoding='utf8', newline='\n')
    print(f'{len(rows)} original mixed trees and {sum(len(row["queries"]) for row in rows)} edge queries captured')


if __name__ == '__main__':
    main()
