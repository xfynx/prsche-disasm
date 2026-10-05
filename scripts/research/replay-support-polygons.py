"""Execute original support polygon constructors, containment and leaf selection.

The spatial leaf is supplied by the harness; spatial traversal/resource loading
are excluded. No original instruction is patched and no virtual call is stubbed.
"""
import argparse
import importlib.util
import json
from pathlib import Path
import struct

spec = importlib.util.spec_from_file_location('response', Path(__file__).with_name('replay-contact-response.py'))
response = importlib.util.module_from_spec(spec)
spec.loader.exec_module(response)
from unicorn.x86_const import (UC_X86_REG_EAX, UC_X86_REG_EBX, UC_X86_REG_ECX,
                               UC_X86_REG_EDI, UC_X86_REG_ESI, UC_X86_REG_ESP, UC_X86_REG_EIP)
from unicorn import UC_HOOK_CODE

OBJ, VERT, PTRS, COLORS = response.CAR, response.CAR + 0x100, response.CAR + 0x200, response.CAR + 0x240
OWNER, NODE, VECTOR, RECORDS = response.CAR + 0x1000, response.CAR + 0x1100, response.CAR + 0x1140, response.CAR + 0x1200


def floats(uc, address, values):
    uc.mem_write(address, struct.pack('<' + 'f' * len(values), *values))


def words(uc, address, values):
    uc.mem_write(address, struct.pack('<' + 'I' * len(values), *values))


def execute(uc, entry, args, owner):
    words(uc, response.STACK, [response.EXIT, *args])
    uc.reg_write(UC_X86_REG_ECX, owner)
    uc.reg_write(UC_X86_REG_ESP, response.STACK)
    uc.emu_start(entry, response.EXIT, count=10000)
    if uc.reg_read(UC_X86_REG_EIP) != response.EXIT:
        raise RuntimeError('instruction budget exhausted')
    return uc.reg_read(UC_X86_REG_EAX)


def make(module, data, points, flags=1, extra_ranges=()):
    ranges = ((0x4853c0, 0x48556c), (0x4855c0, 0x485630),
              (0x485780, 0x4859e5), (0x485c50, 0x485dd0),
              (0x485e40, 0x485ea0), (0x486090, 0x486262), (0x47329f, 0x47332d))
    uc = response.machine(module, data, ranges + extra_ranges)
    for i, point in enumerate(points):
        floats(uc, VERT + i*16, [*point, 0.])
    words(uc, PTRS, [VERT+i*16 for i in range(len(points))])
    execute(uc, 0x485c50 if len(points)==3 else 0x4853c0, [PTRS, COLORS, flags], OBJ)
    return uc


def cross(a, b, p):
    value = (a[0]-b[0])*(p[2]-b[2]) - (p[0]-b[0])*(a[2]-b[2])
    rounded = response.f32(value)
    return struct.unpack('<i', struct.pack('<f', rounded))[0]


def run(module, data):
    shapes = [([[0., 0., 0.], [10., 2., 0.], [0., 4., 10.]]),
              ([[0., 0., 0.], [10., 2., 0.], [10., 4., 10.], [0., 2., 10.]])]
    results = []
    for shape in shapes:
        for points in (shape, list(reversed(shape))):
            for point in ([2., 0., 2.], [2., 90., 2.], [20., 0., 20.],
                          [0., 0., 0.], [10., 0., 0.], [5., 0., 0.],
                          [-0.00001, 0., 2.], [0.00001, 0., 2.], [5., 0., 5.]):
                uc = make(module, data, points)
                actual_winding = uc.mem_read(OBJ + 8, 1)[0]
                factor = response.f32(1/3) if len(points)==3 else .25
                center = [response.f32(sum(p[axis] for p in points)*factor) for axis in range(3)]
                winding = int(all(cross(points[i], points[(i+1)%len(points)], center) <= 0 for i in range(len(points))))
                assert winding == actual_winding
                floats(uc, response.NORMAL, point)
                actual = execute(uc, 0x486090 if len(points)==3 else 0x485780, [response.NORMAL], OBJ) & 255
                expected = all(cross(points[i], points[(i+1)%len(points)], point)<=0 for i in range(len(points))) if winding else all(cross(points[i], points[(i+1)%len(points)], point)>=0 for i in range(len(points)))
                if actual != expected:
                    raise AssertionError(f'{points} {point}: original {actual}, expected {expected}')
                results.append({'vertices': points, 'point': point, 'winding': winding, 'center': center, 'original_contains': bool(actual)})

    selection = []
    leaf_cases=[([0.,10.],[2.,6.,2.],[1,1],[1,1]),
                ([10.,0.],[2.,5.,2.],[1,1],[1,1]),
                ([0.,10.],[2.,5.,2.],[1,1],[1,1]),
                ([0.,10.],[20.,0.,20.],[1,1],[1,1])]
    leaf_cases += [([0.,10.],[2.,6.,2.],flags,types)
                   for flags,types in (([1,0x10],[1,1]),([0,1],[1,1]),
                                       ([0x10,0x10],[1,1]),([1,1],[1,2]),
                                       ([1,1],[2,1]),([1,1],[2,2]))]
    for heights, point, flags, types in leaf_cases:
        uc = make(module, data, shapes[0])
        objects = []
        centers = []
        for index, height in enumerate(heights):
            obj, vert, ptrs = OBJ+index*0x400, VERT+index*0x400, PTRS+index*0x400
            points = [[p[0], height, p[2]] for p in shapes[0]]
            for i, p in enumerate(points):
                floats(uc, vert+i*16, [*p, 0.])
            words(uc, ptrs, [vert+i*16 for i in range(3)])
            execute(uc, 0x485c50, [ptrs, COLORS, flags[index]], obj)
            objects.append(obj)
            centers.append(height)
            words(uc, RECORDS + index*8, [types[index], obj])
        floats(uc, response.NORMAL, point)
        words(uc, OWNER+0x2c, [NODE])
        words(uc, NODE+0x14, [VECTOR])
        words(uc, VECTOR, [RECORDS, RECORDS+16])
        uc.mem_write(response.STACK+0x10, struct.pack('<I', 0x7e967699))
        words(uc, response.STACK+0x14, [0])
        words(uc, response.STACK+0x24, [response.EXIT])
        uc.reg_write(UC_X86_REG_ESI, OWNER)
        uc.reg_write(UC_X86_REG_EBX, response.NORMAL)
        uc.reg_write(UC_X86_REG_EDI, 0)
        uc.reg_write(UC_X86_REG_ESP, response.STACK)
        uc.emu_start(0x47329f, response.EXIT, count=10000)
        if uc.reg_read(UC_X86_REG_EIP)!=response.EXIT:
            raise RuntimeError('selection instruction budget exhausted')
        pointer=uc.reg_read(UC_X86_REG_EAX)
        actual=objects.index(pointer) if pointer else None
        eligible=[i for i in range(len(centers)) if flags[i]&0xf and types[i]==1 and point[0]<=10 and point[2]<=10]
        expected=min(eligible,key=lambda i:abs(centers[i]-point[1])) if eligible else None
        if actual!=expected:
            raise AssertionError(f'leaf selection {heights} {point}: original {actual}, expected {expected}')
        selection.append({'heights':heights,'point':point,'flags':flags,'types':types,'original_selected':actual})
    splits=[]
    for gap in (0., .039, .04, .041, .2):
        for flags in (0,1):
            gap=response.f32(gap)
            points=[[0.,0.,0.],[10.,0.,0.],[10.,0.,10.],[0.,gap,10.]]
            ranges=((0x47562d,0x475654),(0x47572f,0x475730),
                    (0x48a0a0,0x48a148),(0x489f90,0x48a060),
                    (0x532880,0x5328d0),(0x532b20,0x532b45),(0x56e8f5,0x56e951))
            uc=make(module,data,points,flags,ranges)
            words(uc,response.STACK+0x54,[VERT+i*16 for i in range(4)])
            uc.reg_write(UC_X86_REG_ESP,response.STACK)
            uc.reg_write(UC_X86_REG_EDI,flags)

            def stop(machine,address,_size,_data):
                if address in (0x475653,0x47572f):
                    machine.emu_stop()
            uc.hook_add(UC_HOOK_CODE,stop)
            uc.emu_start(0x47562d,response.EXIT,count=10000)
            address=uc.reg_read(UC_X86_REG_EIP)
            if address not in (0x475653,0x47572f):
                raise RuntimeError('split instruction budget exhausted')
            actual=address==0x475653
            expected=bool(flags and gap>response.f32(.04))
            if actual!=expected:
                raise AssertionError(f'quad split flags={flags}, gap={gap}: original{actual}, expected{expected}')
            splits.append({'vertices':points,'flags':flags,'original_split':actual})
    return {'module':'Porsche.exe','sha256':response.SHA,
            'scope':'original constructors/predicates and supplied-leaf selection; resource loader/spatial traversal excluded',
            'polygon_cases_passed':len(results),'selection_cases_passed':len(selection),'quad_split_cases_passed':len(splits),
            'polygons':results,'selections':selection,'quad_splits':splits}


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output',type=Path,required=True)
    parser.add_argument('--fixture-tsv',type=Path)
    parser.add_argument('--selection-tsv',type=Path)
    args=parser.parse_args()
    inventory=response.ROOT/'research/binary-index/static/binaries.jsonl'
    module,=[m for m in map(json.loads,inventory.read_text(encoding='utf-8').splitlines()) if m['file']=='Porsche.exe']
    data=(response.ROOT/'local/game'/module['path']).read_bytes()
    if response.hashlib.sha256(data).hexdigest()!=response.SHA or module['sha256']!=response.SHA:
        raise RuntimeError('original SHA256 mismatch')
    result=run(module,data)
    args.output.parent.mkdir(parents=True,exist_ok=True)
    args.output.write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    if args.fixture_tsv:
        header=['count']+[f'v{i}_{axis}' for i in range(4) for axis in 'xyz']+['px','py','pz','winding','contains','cx','cy','cz']
        rows=['\t'.join(header)]
        for fixture in result['polygons']:
            vertices=fixture['vertices']+[[0.,0.,0.]]*(4-len(fixture['vertices']))
            row=[len(fixture['vertices']),*[x for p in vertices for x in p],*fixture['point'],fixture['winding'],int(fixture['original_contains']),*fixture['center']]
            rows.append('\t'.join(map(str,row)))
        args.fixture_tsv.parent.mkdir(parents=True,exist_ok=True)
        args.fixture_tsv.write_text('\n'.join(rows)+'\n',encoding='utf-8')
    if args.selection_tsv:
        rows=['h0\th1\tflags0\tflags1\ttype0\ttype1\tpx\tpy\tpz\tselected']
        for fixture in result['selections']:
            row=[*fixture['heights'],*fixture['flags'],*fixture['types'],*fixture['point'],
                 -1 if fixture['original_selected'] is None else fixture['original_selected']]
            rows.append('\t'.join(map(str,row)))
        args.selection_tsv.parent.mkdir(parents=True,exist_ok=True)
        args.selection_tsv.write_text('\n'.join(rows)+'\n',encoding='utf-8')
    print(f"{result['polygon_cases_passed']} polygon / {result['selection_cases_passed']} leaf-selection / {result['quad_split_cases_passed']} quad-split original-x86 cases passed")


if __name__=='__main__':
    main()
