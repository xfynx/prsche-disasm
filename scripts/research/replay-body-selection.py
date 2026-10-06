"""Execute original 0x495020 through first 0x494000 call or no-hit return.

Real original owner/tree/EDG callbacks are used, no selection stubs. The
synthetic car supplies explicit source state, not a gameplay adapter mapping.
"""
import importlib.util
import json
from pathlib import Path
import struct
import argparse

HERE = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('mixed', HERE / 'replay-mixed-support.py')
m = importlib.util.module_from_spec(spec)
spec.loader.exec_module(m)
t, s, r, o = m.t, m.s, m.r, m.o
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP, UC_X86_REG_ESI, UC_X86_REG_EIP

CAR = t.GEOMETRY + 0xe000


def run_case(module, data, ranges, name, position, velocity, width):
    poly = [[0., 0., -10.], [0., 0., 10.], [10., 0., 10.], [10., 0., -10.]]
    edges = [[[0., 0., -5.], [0., 0., 5.]], [[0., 10., -5.], [0., 10., 5.]]]
    uc, _ = t.machine(module, data, ranges, [poly], 0)
    t.execute(uc, 0x484ae0, [r.CAR], t.NODE)
    for i, endpoints in enumerate(edges):
        source = t.GEOMETRY + 0x1000 + i*0x40
        for j, point in enumerate(endpoints):
            s.floats(uc, source + j*16, [*point, 0.])
        t.execute(uc, 0x485100, [source, i+10], m.EDGE_BASE+i*0x80)
        t.execute(uc, 0x484ae0, [m.EDGE_BASE+i*0x80], t.NODE)
    s.words(uc, 0x628960, [t.SCENE])
    s.words(uc, t.SCENE+0x24, [t.HOLDER])
    s.words(uc, t.HOLDER, [t.NODE])
    uc.mem_write(CAR+8, bytes(48))
    for offset, values in ((0x330, position), (0x33c, velocity), (0x364, [1., 0., 0.]),
                           (0x370, [0., 1., 0.]), (0x37c, [0., 0., 1.]),
                           (0x3a8, [width, .75, 2.])):
        s.floats(uc, CAR+offset, values)
    observed = [None]
    last_segment = [None]
    def stop_before_response(machine, address, _size, _user):
        if address == 0x4740d0:
            pointer = t.words(machine, machine.reg_read(UC_X86_REG_ESP) + 4, 1)[0]
            last_segment[0] = [list(o.f32(machine, pointer, 3)), list(o.f32(machine, pointer + 12, 3))]
        if address == 0x4954ff:
            sp = machine.reg_read(UC_X86_REG_ESP)
            car, normal, point, displacement, angular = t.words(machine, sp, 5)
            if car != CAR or angular != 1:
                raise RuntimeError('unexpected original response arguments')
            # The caller local frame is initial stack -0x128. Eight points
            # start at local +0xc8. ESI is the current candidate pointer.
            candidate = (machine.reg_read(UC_X86_REG_ESI) - (r.STACK-0x128+0xc8)) // 12
            observed[0] = dict(candidate=candidate, point=list(o.f32(machine, point, 3)),
                               normal=list(o.f32(machine, normal, 3)),
                               displacement=list(o.f32(machine, displacement, 3)),
                               word=t.words(machine, 0x628c88, 1)[0], segment=last_segment[0])
            machine.emu_stop()
    uc.hook_add(UC_HOOK_CODE, stop_before_response)
    s.words(uc, r.STACK, [r.EXIT, CAR])
    uc.reg_write(UC_X86_REG_ESP, r.STACK)
    uc.emu_start(0x495020, r.EXIT, count=100000)
    if observed[0] is None and uc.reg_read(UC_X86_REG_EIP) != r.EXIT:
        raise RuntimeError('original selection instruction budget exhausted')
    return dict(name=name, position=position, velocity=velocity, width=width, polygons=[poly], edges=edges, original=observed[0])


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--run-dir', type=Path, default=r.ROOT / 'iterations/012-campaign-fidelity/runs/019-original-contact-runtime')
    args = parser.parse_args()
    module, = [v for v in map(json.loads, (r.ROOT/'research/binary-index/static/binaries.jsonl').read_text(encoding='utf8').splitlines()) if v['file']=='Porsche.exe']
    data = (r.ROOT/'local/game'/module['path']).read_bytes()
    assert r.hashlib.sha256(data).hexdigest() == r.SHA
    sources = list(map(json.loads, (args.run_dir/'mixed-query-source.jsonl').read_text(encoding='utf8').splitlines()))
    ranges = list(o.EXTRA+o.TREE_RANGES) + [(t.PLATFORM, t.PLATFORM+19),
        (0x485630, 0x485780), (0x485ea0, 0x486090), (0x485100, 0x485201),
        (0x4852b0, 0x4853c0), (0x489cc0, 0x489dec), (0x495020, 0x4955b1),
        (0x532300, 0x53235c), (0x56e660, 0x56e6d7), (0x489f10, 0x489f89), (0x508000, 0x508005)]
    ranges += [(int(a,16),int(b,16)+1) for row in sources if row.get('kind')=='function' for a,b in row['ranges']]
    rows = [run_case(module, data, ranges, f'y{y}_w{width}', [2., y, 1.], velocity, width)
            for y in (0., 4., 5., 9.) for width, velocity in ((4., [10., 0., 0.]), (1., [-5., 1., 2.]))]
    (args.run_dir/'body-selection-replay.json').write_text(json.dumps(dict(module='Porsche.exe',sha256=r.SHA,cases=rows,
        excluded=['live car field binding','response/repeated contacts','effects and large impact callbacks']),indent=2)+'\n', encoding='utf8', newline='\n')
    def vec(values): return ','.join(map(str, values))
    lines = ['name\tposition\tvelocity\twidth\tcandidate\tpoint\tnormal\tdisplacement\tword\tfrom']
    for row in rows:
        hit = row['original']
        values = [row['name'],vec(row['position']),vec(row['velocity']),str(row['width'])]
        values += ['-']*6 if hit is None else [str(hit['candidate']),vec(hit['point']),vec(hit['normal']),vec(hit['displacement']),str(hit['word']),vec(hit['segment'][0])]
        lines.append('\t'.join(values))
    (args.run_dir/'body-selection-fixtures.tsv').write_text('\n'.join(lines)+'\n', encoding='utf8', newline='\n')
    print(f'{len(rows)} original first-contact/no-hit body calls captured')


if __name__ == '__main__': main()
