"""Run original 0x499a70 through its first four-wheel loop, stopping at 0x499f16.

The original support tree, callbacks, material RNG, 0x493bc0 part consumer,
compression clamps and CRT asin execute unchanged. Synthetic car/parts/scene
are explicit inputs; later force accumulation and gameplay cadence are excluded.
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
from unicorn.x86_const import UC_X86_REG_ESP, UC_X86_REG_EIP, UC_X86_REG_EDI

CAR, PARTS = t.GEOMETRY + 0xe000, t.GEOMETRY + 0x4000
RUN = r.ROOT / 'iterations/012-campaign-fidelity/runs/020-original-wheel-loop'
ADDRESSES = (0x499a70, 0x494480, 0x499730, 0x493bc0, 0x532330,
             0x56e6aa, 0x532910, 0x56e8d1, 0x5a2a10, 0x5a2a2d,
             0x5a4f68, 0x5a4ef5, 0x5a4f7e, 0x5a4f8b, 0x5a4e97)


def exported_sources():
    rows = [dict(module='Porsche.exe', sha256=r.SHA)]
    ranges = list(o.EXTRA + o.TREE_RANGES) + [(t.PLATFORM, t.PLATFORM + 19)]
    for address in ADDRESSES:
        result = subprocess.check_output(['py', '-3', str(HERE / 'query-binary-index.py'),
            '--binary', 'Porsche.exe', '--address', hex(address), '--disassemble', '--limit', '2200'],
            encoding='utf-8', cwd=r.ROOT)
        for row in map(json.loads, result.splitlines()):
            if row.get('kind') == 'function':
                ranges.extend((int(a, 16), int(b, 16) + 1) for a, b in row['ranges'])
            if row.get('kind') in ('function', 'disassembly'):
                rows.append(row)
    return rows, ranges


def run_case(module, data, ranges, case):
    # First source vertex/base and winding are preserved by actual constructor.
    slope, y = case['slope'], case['deck']
    poly = [[x, y + slope*x, z] for x,z in ((-10.,-10.), (-10.,10.), (10.,10.), (10.,-10.))]
    uc, _ = t.machine(module, data, ranges, [poly], 0)
    uc.mem_write(r.CAR + 0xa, struct.pack('<H', case['material']))
    t.execute(uc, 0x484ae0, [r.CAR], t.NODE)
    s.words(uc, 0x628960, [t.SCENE])
    s.words(uc, t.SCENE + 0x24, [t.HOLDER])
    s.words(uc, t.HOLDER, [t.NODE])
    s.words(uc, 0x606ac4, [case['quality']])
    s.words(uc, 0x657408, [case['global_skip']])
    s.words(uc, 0x6573f8, [case['material_remap']])
    s.words(uc, CAR + 0xdac, [case['car_skip']])
    s.floats(uc, CAR + 0x334, [case['reference']])
    s.floats(uc, CAR + 0x370, case['up'])
    s.floats(uc, CAR + 0x3a0, [case['gate']])
    s.floats(uc, CAR + 0x35c, [case['speed']])
    s.floats(uc, CAR + 0x3e8, case['fallback_normal'])
    s.floats(uc, CAR + 0x400, case['fallback_base'])
    s.words(uc, CAR + 0x760, [PARTS])
    s.floats(uc, PARTS + 0x120, [case['ride'], case['limit']])
    s.floats(uc, CAR + 0x4e4, case['modifiers'])
    parts = []
    for i in range(20):
        ptr = PARTS + 0x200 + i*0x180
        part = case['parts'][i] if i < len(case['parts']) else [0, 0., 0, 0.]
        kind, weight, mask, bias = part
        uc.mem_write(ptr + 0x26, struct.pack('<H', kind))
        uc.mem_write(ptr + 0x48, bytes(int(bool(mask & (1 << bit))) for bit in range(10)))
        s.floats(uc, ptr + 0x60, [weight])
        s.floats(uc, ptr + 0x164, [bias])
        parts.append(ptr)
    s.words(uc, CAR + 0x768, parts)
    for i, point in enumerate(case['points']):
        s.floats(uc, CAR + 0x1dc + i*12, point)
        owner = CAR + 0x7bc + i*0xc4
        uc.mem_write(owner, bytes(0xc4))
        s.floats(uc, owner + 0x64, [case['old_compression']])
        s.words(uc, owner + 0x80, [case['wheel_flag']])
        s.floats(uc, owner + 0x84, [case['phase_offset']])
        s.floats(uc, owner + 0x78, [case['noise_phase']])
        s.floats(uc, owner + 0x74, [case['noise_current']])
        s.floats(uc, owner + 0x70, [case['noise_previous']])
    s.words(uc, 0x5d1028, [123])
    s.words(uc, 0x5d102c, [16807])
    s.words(uc, 0x655a0c, [999])
    observed = []
    def watch(machine, address, _size, _user):
        if address == 0x499d15:
            owner = machine.reg_read(UC_X86_REG_EDI)
            observed.append(dict(query=list(o.f32(machine, owner+0x30, 3)),
                point=list(o.f32(machine, owner+0x3c, 3)), normal=list(o.f32(machine, owner+0x48, 3)),
                material=t.words(machine, owner+0x88, 1)[0],
                noise=list(o.f32(machine, owner+0x70, 3)),
                selected=t.words(machine, owner+0x28, 1)[0] != 0))
        if address == 0x499f16:
            machine.emu_stop()
    uc.hook_add(UC_HOOK_CODE, watch)
    s.words(uc, r.STACK, [r.EXIT, CAR])
    uc.reg_write(UC_X86_REG_ESP, r.STACK)
    uc.emu_start(0x499a70, r.EXIT, count=1000000)
    if uc.reg_read(UC_X86_REG_EIP) != 0x499f16 or len(observed) != 4:
        raise RuntimeError('original wheel loop did not reach four-wheel boundary')
    for i, result in enumerate(observed):
        owner = CAR + 0x7bc + i*0xc4
        result['compression'] = o.f32(uc, owner + 0x64, 1)[0]
        result['angle'] = o.f32(uc, owner + 0x6c, 1)[0]
    sp = uc.reg_read(UC_X86_REG_ESP)
    return dict(input=case, polygon=poly, wheels=observed,
                multipliers=list(o.f32(uc, sp+0x9c, 4)),
                sum=list(o.f32(uc, sp+0x3c, 3)),
                rng=t.words(uc, 0x5d1028, 1)[0], product=t.words(uc, 0x655a0c, 1)[0])


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--run-dir', type=Path, default=RUN)
    args = parser.parse_args()
    module, = [m for m in map(json.loads, (r.ROOT/'research/binary-index/static/binaries.jsonl').read_text(encoding='utf-8').splitlines()) if m['file']=='Porsche.exe']
    data = (r.ROOT/'local/game'/module['path']).read_bytes()
    if module['sha256'] != r.SHA or r.hashlib.sha256(data).hexdigest() != r.SHA:
        raise RuntimeError('original SHA mismatch')
    rows, ranges = exported_sources()
    base = dict(name='flat', slope=0., deck=0., material=1, quality=2,
                global_skip=0, car_skip=0, material_remap=0, reference=0.,
                up=[0.,1.,0.], gate=1., speed=12., fallback_normal=[.2,1.,.3],
                fallback_base=[1.,3.,2.], ride=.4, limit=1.2,
                modifiers=[.1*i for i in range(10)], parts=[],
                points=[[-1.,.3,1.],[1.,.3,1.],[-1.,.3,-1.],[1.,.3,-1.]],
                old_compression=.25, wheel_flag=0, phase_offset=.125,
                noise_phase=.1, noise_current=.4, noise_previous=.2)
    changes = [('flat',{}), ('slope',dict(slope=.2)), ('far',dict(deck=8.)),
        ('no_material',dict(material=0)), ('outside',dict(points=[[20.,1.,20.]]*4)),
        ('fallback_up_gate',dict(material=0,fallback_normal=[.2,.1,.3])),
        ('fallback_just_above',dict(material=0,fallback_normal=[.2,r.f32(.1+2**-27),.3])),
        ('quality_skip',dict(quality=1)), ('global_car_skip',dict(global_skip=1,car_skip=1)),
        ('global_without_car_skip',dict(global_skip=1)), ('car_without_global_skip',dict(car_skip=1)),
        ('remap_material_1',dict(material_remap=1)), ('remap_material_10',dict(material=10,material_remap=1)),
        ('inverted',dict(up=[0.,-1.,0.])), ('up_gate_exact',dict(up=[0.,r.f32(.3),0.])),
        ('up_gate_below',dict(up=[0.,r.f32(.3-2**-25),0.])),
        ('negative',dict(points=[[x,-1.,z] for x,z in ((-1,1),(1,1),(-1,-1),(1,-1))])),
        ('negative_flag',dict(wheel_flag=1,points=[[x,-1.,z] for x,z in ((-1,1),(1,1),(-1,-1),(1,-1))])),
        ('positive_limit',dict(points=[[x,3.,z] for x,z in ((-1,1),(1,1),(-1,-1),(1,-1))])),
        ('damage_one',dict(parts=[[4,30.,1,.02]])),
        ('damage_average',dict(parts=[[4,30.,3,.02],[5,60.,0,.05],[8,100.,1023,-.1],[9,10.,1,99.]])),
        ('damage_phase',dict(parts=[[8,70.,12,.04]],phase_offset=.3)),
        ('material_gate',dict(material=3,gate=.5)),
        ('positive_multiplier',dict(points=[[x,-4.,z] for x,z in ((-1,1),(1,1),(-1,-1),(1,-1))])),
        ('negative_floor_flag',dict(wheel_flag=1,points=[[x,3.,z] for x,z in ((-1,1),(1,1),(-1,-1),(1,-1))])),
        ('zero_projection',dict(points=[[x,0.,z] for x,z in ((-1,1),(1,1),(-1,-1),(1,-1))])),
        ('height_gate_exact',dict(reference=4.)),
        ('height_gate_above',dict(reference=r.f32(4.+2**-21))),
        ('height_gate_below',dict(reference=-r.f32(4.+2**-21))),
        ('fallback_negative_y',dict(material=0,fallback_normal=[.2,-1.,.3])),
        ('material_high_word',dict(material=0x101,material_remap=1)),
    ]
    changes += [(f'material_{mat}',dict(material=mat,noise_phase=2.49)) for mat in range(16)]
    results = [run_case(module,data,ranges,dict(base,**dict(change,name=name))) for name,change in changes]
    args.run_dir.mkdir(parents=True, exist_ok=True)
    for name, value in [('wheel-loop-replay.json',dict(module='Porsche.exe',sha256=r.SHA,cases=results,
            boundary='0x499f16 before later forces',original_bytes_unchanged=True))]:
        (args.run_dir/name).write_text(json.dumps(value,indent=2)+'\n',encoding='utf-8',newline='\n')
    (args.run_dir/'wheel-loop-source.jsonl').write_text('\n'.join(map(json.dumps,rows))+'\n',encoding='utf-8',newline='\n')
    def encoded(values):
        return ','.join(map(str, values))
    lines = ['name\tscalars\tup\tfallback_normal\tfallback_base\tmodifiers\tparts\tpoints\twheels\tmultipliers\tsum\trng\tproduct']
    scalar_keys = ('slope','deck','material','quality','global_skip','car_skip','material_remap',
                   'reference','gate','speed','ride','limit','old_compression','wheel_flag',
                   'phase_offset','noise_phase','noise_current','noise_previous')
    for result in results:
        case = result['input']
        wheels = []
        for w in result['wheels']:
            wheels.append(encoded([*w['query'],*w['point'],*w['normal'],w['material'],int(w['selected']),
                                   *w['noise'],w['compression'],w['angle']]))
        lines.append('\t'.join([case['name'],encoded(case[k] for k in scalar_keys),encoded(case['up']),
            encoded(case['fallback_normal']),encoded(case['fallback_base']),encoded(case['modifiers']),
            '/'.join(encoded(p) for p in case['parts']) or '-', '/'.join(encoded(p) for p in case['points']),
            '/'.join(wheels), encoded(result['multipliers']),encoded(result['sum']),str(result['rng']),str(result['product'])]))
    (args.run_dir/'wheel-loop-fixtures.tsv').write_text('\n'.join(lines)+'\n',encoding='utf-8',newline='\n')
    print(f'{len(results)} complete first four-wheel loops captured ({len(results)*4} wheel states)')


if __name__ == '__main__':
    main()
