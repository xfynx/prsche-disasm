"""Original dynamic type-1 tree insertion, splitting, allocation and query.

Game/allocator instructions are unmodified. A valid preinitialized heap is
supplied; only imported Win32 critical-section services are modeled for one
thread. No game callee, geometric callback or allocator callback is stubbed.
"""
import argparse
import importlib.util
import json
from pathlib import Path
import random
import struct
import subprocess

HERE = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('support', HERE/'replay-support-polygons.py')
s = importlib.util.module_from_spec(spec)
spec.loader.exec_module(s)
r = s.response
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP, UC_X86_REG_ECX, UC_X86_REG_EIP, UC_X86_REG_EAX

HEAP, SIZE, NODE, PLATFORM = 0x2300000, 0x400000, r.CAR+0x2e00, 0x2800000
GEOMETRY = 0x2700000
VERT, PTRS, COLORS = r.CAR+0x3000, r.CAR+0x3100, r.CAR+0x3200
SCENE, HOLDER, OWNER, CRITICAL = r.CAR+0x3400, r.CAR+0x3480, r.CAR+0x3500, r.CAR+0x3800
ADDRESSES = (0x483df0, 0x484320, 0x484ae0, 0x483bd0, 0x4211d0, 0x4237d0,
             0x4282c0, 0x481cf0, 0x505810, 0x59ecb0, 0x59ecd0, 0x59ef90,
             0x59f050, 0x59eeb0, 0x5322b0, 0x5322c0, 0x531f70, 0x531f90,
             0x531ca0, 0x531c60, 0x5320b0, 0x484500, 0x484450, 0x473240)


def words(uc, address, count):
    return list(struct.unpack('<'+'I'*count, uc.mem_read(address, 4*count)))


def execute(uc, address, args, owner):
    s.words(uc, r.STACK, [r.EXIT, *args])
    uc.reg_write(UC_X86_REG_ECX, owner)
    uc.reg_write(UC_X86_REG_ESP, r.STACK)
    uc.emu_start(address, r.EXIT, count=2000000)
    if uc.reg_read(UC_X86_REG_EIP) != r.EXIT:
        raise RuntimeError('original instruction budget exhausted')
    return uc.reg_read(UC_X86_REG_EAX)


def machine(module, data, ranges, polygons, root):
    uc = s.make(module, data, polygons[0], extra_ranges=tuple(ranges))
    uc.mem_map(HEAP, SIZE)
    uc.mem_map(GEOMETRY, 0x10000)
    uc.mem_map(PLATFORM, 4096)
    # Imported services, resolved as the Windows loader would resolve IAT slots.
    # RET4 is only a harness endpoint; the hook models the single-thread state.
    for address in (PLATFORM, PLATFORM+16):
        uc.mem_write(address, b'\xc2\x04\x00')
    s.words(uc, 0x5b2078, [PLATFORM])  # EnterCriticalSection
    s.words(uc, 0x5b206c, [PLATFORM+16])  # LeaveCriticalSection
    s.words(uc, CRITICAL, [0, 0xffffffff, 0, 0, 0, 0])
    service_counts = [0, 0]
    def imported_services(machine, address, _size, _user):
        if address not in (PLATFORM, PLATFORM+16):
            return
        sp = machine.reg_read(UC_X86_REG_ESP)
        return_address, critical = words(machine, sp, 2)
        if critical != CRITICAL:
            raise RuntimeError('unexpected Win32 critical section')
        state = words(machine, critical, 6)
        if address == PLATFORM:
            state[1] = (state[1]+1) & 0xffffffff
            state[2] += 1
            state[3] = 1
            service_counts[0] += 1
        else:
            if state[2] == 0 or state[3] != 1:
                raise RuntimeError('unbalanced Win32 lock')
            state[1] = (state[1]-1) & 0xffffffff
            state[2] -= 1
            state[3] = 1 if state[2] else 0
            service_counts[1] += 1
        s.words(machine, critical, state)
        machine.reg_write(UC_X86_REG_ESP, sp+8)
        machine.reg_write(UC_X86_REG_EIP, return_address)
    uc.hook_add(UC_HOOK_CODE, imported_services)
    # Supplied valid allocator state, following 5697f0/5320b0 layout. All
    # allocation, pool refill, vector growth and free operations run original code.
    s.words(uc, 0x5e4fe8, [0x5e4700])
    s.words(uc, 0x6af3f8, [4096])
    s.words(uc, 0x5e4728, [CRITICAL])
    owner = HEAP+16
    sentinel, free, end = owner+16, HEAP+128, HEAP+SIZE-16
    s.words(uc, 0x6b4f20, [owner])
    s.words(uc, HEAP, [0x8000424d, 64, free, 0])
    s.words(uc, end, [0x8010424d, 0, HEAP, free])
    s.words(uc, free, [0x40004246, SIZE-160, end, HEAP, sentinel, sentinel])
    s.words(uc, sentinel, [0x4253, 0x7fffffff, 0, 0, free, free])
    s.words(uc, owner+0x28, [8, 0, 0, 0, 0, 0])
    s.words(uc, NODE, [root, 0, 0, 0, 0, 0])
    s.floats(uc, 0x628be8, [16384/(2**i) if i < 15 else 0 for i in range(16)])
    s.floats(uc, 0x628c30, [8192.])
    for index, points in enumerate(polygons):
        # Constructors retain pointers into vt, so each polygon needs a stable
        # vertex buffer. Reusing constructor scratch would mutate all objects.
        vertices = GEOMETRY + index*0x40
        for i, point in enumerate(points):
            s.floats(uc, vertices+i*16, [*point, 0.])
        s.words(uc, PTRS, [vertices+16*i for i in range(len(points))])
        execute(uc, 0x485c50 if len(points)==3 else 0x4853c0, [PTRS, COLORS, 1], r.CAR+index*0x80)
    return uc, service_counts


def snapshot(uc, object_count):
    nodes = []
    known = set()
    def visit(pointer):
        if pointer in known:
            raise RuntimeError('tree cycle or shared child')
        known.add(pointer)
        code, *fields = words(uc, pointer, 6)
        children, vector = fields[:4], fields[4]
        records = None
        if vector:
            begin, end, capacity = words(uc, vector, 3)
            if not begin <= end <= capacity or (end-begin)%8:
                raise RuntimeError('invalid original record vector')
            records = []
            for address in range(begin, end, 8):
                kind, obj = words(uc, address, 2)
                index = (obj-r.CAR)//0x80
                if kind & 255 != 1 or obj != r.CAR+index*0x80 or not 0 <= index < object_count:
                    raise RuntimeError('invalid original support record')
                records.append(index)
        mask = sum((1<<i) for i, child in enumerate(children) if child)
        nodes.append((code, mask, records))
        for child in children:
            if child:
                visit(child)
    visit(NODE)
    encoded = ';'.join(f'{code}:{mask}:'+('-' if records is None else ','.join(map(str,records)) or '_')
                       for code, mask, records in nodes)
    return encoded, len(nodes)


def triangle(x, z, scale=10):
    return [[x, 0., z], [x+scale, 1., z], [x, 2., z+scale]]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--run-dir', type=Path, required=True)
    parser.add_argument('--source-output', type=Path, required=True)
    args = parser.parse_args()
    module, = [m for m in map(json.loads, (r.ROOT/'research/binary-index/static/binaries.jsonl').read_text(encoding='utf8').splitlines()) if m['file']=='Porsche.exe']
    data = (r.ROOT/'local/game'/module['path']).read_bytes()
    if r.hashlib.sha256(data).hexdigest() != r.SHA or module['sha256'] != r.SHA:
        raise RuntimeError('original SHA mismatch')
    sources = [{'module':'Porsche.exe', 'sha256':r.SHA}]
    ranges = [(PLATFORM, PLATFORM+19), (0x485630,0x485780), (0x485ea0,0x486090)]
    for address in (*ADDRESSES, 0x5697f0, 0x59e9d0):
        output = subprocess.check_output(['py','-3',str(HERE/'query-binary-index.py'),'--binary','Porsche.exe',
                                          '--address',hex(address),'--disassemble','--limit','2000'],
                                         text=True,encoding='utf-8',cwd=r.ROOT)
        for row in map(json.loads, output.splitlines()):
            if row.get('kind')=='function':
                ranges.extend((int(a,16),int(b,16)+1) for a,b in row['ranges'])
            if row.get('kind') in ('function','disassembly'):
                sources.append(row)
    rng = random.Random(0x484ae0)
    mixed = [triangle(x,z) for x,z in [(-100,-100),(-100,100),(100,100),(100,-100),(0,0),(-10,-10)]]
    mixed += [[[-8., 1., -8.],[8., 2., -8.],[8., 3., 8.],[-8.,4.,8.]],
              triangle(8192,8192),triangle(8193,0),triangle(-8193,-1)]
    randoms = [triangle(rng.randrange(-8100,8100),rng.randrange(-8100,8100),rng.randrange(1,30)) for _ in range(24)]
    cases = [('leaf',0,[triangle(0,0)], [0]*48),
             ('deep_split',0,[triangle(0,0)], [0]*50),
             ('terminal_growth',0xc2000800,[triangle(0,0,1)], [0]*60),
             ('mixed_forward',0,mixed,[i%len(mixed) for i in range(90)]),
             ('mixed_reverse',0,mixed,list(reversed([i%len(mixed) for i in range(90)]))),
             ('random_forward',0,randoms,[i%len(randoms) for i in range(80)]),
             ('random_reverse',0,randoms,list(reversed([i%len(randoms) for i in range(80)]))),
             ('edge_touch',0,[triangle(-1,-1,1),triangle(0,-1,1),triangle(-1,0,1),triangle(0,0,1)], [i%4 for i in range(65)])]
    rows, queries, summaries = [], [], []
    for name, root, polygons, order in cases:
        uc, services = machine(module,data,ranges,polygons,root)
        all_points = '/'.join(','.join(str(v) for point in points for v in point) for points in polygons)
        for count, index in enumerate(order, 1):
            execute(uc,0x484ae0,[r.CAR+index*0x80],NODE)
            if count in (1,48,49,50,len(order)):
                encoded, node_count = snapshot(uc,len(polygons))
                rows.append([name,root,all_points,','.join(map(str,order[:count])),encoded])
        encoded, node_count = snapshot(uc,len(polygons))
        s.words(uc,0x628960,[SCENE])
        s.words(uc,SCENE+0x24,[HOLDER])
        s.words(uc,HOLDER,[NODE])
        s.words(uc,OWNER+0x2c,[0])
        points = [[0.,0.,0.],[.25,0.,.25],[-.25,0.,-.25],[5.,99.,5.],[100.,0.,100.],
                  [-100.,0.,-100.],[8192.,0.,8192.],[8200.,0.,0.],[0.,0.,0.]]
        for point in points:
            s.floats(uc,r.NORMAL,point)
            cached_pointer = words(uc,OWNER+0x2c,1)[0]
            pointer = execute(uc,0x473240,[r.NORMAL],OWNER)
            index = '-' if not pointer else (pointer-r.CAR)//0x80
            if pointer and pointer != r.CAR+int(index)*0x80:
                raise RuntimeError('invalid original query object')
            leaf_pointer = words(uc,OWNER+0x2c,1)[0]
            queries.append([name,','.join(map(str,point)),index,words(uc,leaf_pointer,1)[0],
                            '-' if not cached_pointer else words(uc,cached_pointer,1)[0]])
        if words(uc,CRITICAL,6)[1:4] != [0xffffffff,0,0] or services[0] != services[1]:
            raise RuntimeError('unbalanced platform critical-section state')
        summaries.append({'case':name,'insertions':len(order),'nodes':node_count,'lock_calls':services})
    args.run_dir.mkdir(parents=True,exist_ok=True)
    def write(name, header, rows):
        (args.run_dir/name).write_text(header+'\n'+''.join('\t'.join(map(str,row))+'\n' for row in rows),encoding='utf-8',newline='\n')
    write('tree-fixtures.tsv','name\troot\tpolygons\torder\ttree',rows)
    write('tree-query-fixtures.tsv','name\tpoint\tselected\tleaf\tprevious_cache',queries)
    report = {'module':'Porsche.exe','sha256':r.SHA,'tree_snapshots':len(rows),'query_cases':len(queries),
              'cases':summaries,'platform_services':['single-thread EnterCriticalSection','single-thread LeaveCriticalSection'],
              'excluded':['multithreading','heap initialization/startup','non-type-1 objects','resource assembly','live vehicle state']}
    (args.run_dir/'tree-replay.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8',newline='\n')
    args.source_output.parent.mkdir(parents=True,exist_ok=True)
    args.source_output.write_text(''.join(json.dumps(row)+'\n' for row in sources),encoding='utf-8',newline='\n')
    constants = []
    for address, size in ((0x5e4700,40),(0x5e4fe8,8)):
        constants.append(subprocess.check_output(['py','-3',str(HERE/'inspect-pe-range.py'),'--binary','Porsche.exe',
                                                  '--address',hex(address),'--size',str(size),'--words'],
                                                 text=True,encoding='utf-8',cwd=r.ROOT))
    args.source_output.with_name('support-tree-allocator-constants.txt').write_text('\n'.join(constants),encoding='utf-8',newline='\n')
    print(f'{len(rows)} original dynamic tree snapshots and {len(queries)} full cached support queries captured')


if __name__=='__main__':
    main()
