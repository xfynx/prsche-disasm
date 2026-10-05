"""Execute original spatial bounds, point traversal, and support-cache resolution.

Synthetic node arenas and empty record vectors are supplied. The x86 functions
and global width-initialization slice run unchanged, with no substituted calls.
This does not test original resource loading, insertion, or a live race.
"""
import argparse
import importlib.util
import json
from pathlib import Path
import struct
import subprocess

spec = importlib.util.spec_from_file_location('support', Path(__file__).with_name('replay-support-polygons.py'))
support = importlib.util.module_from_spec(spec)
spec.loader.exec_module(support)
response = support.response
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESI, UC_X86_REG_ESP, UC_X86_REG_EIP

NODES = response.CAR + 0x1000
VECTOR = response.CAR + 0x1800
SCENE = response.CAR + 0x1900
TREE = response.CAR + 0x1940
OWNER = response.CAR + 0x1980
RANGES = ((0x48384a, 0x483882), (0x484450, 0x4844f3),
          (0x484500, 0x484628), (0x473240, 0x47332f))


def grid(module, data, half_extent, depth=16):
    uc = response.machine(module, data, RANGES)
    support.floats(uc, response.STACK + 0x18, [half_extent])
    support.words(uc, response.STACK + 0x1c, [depth])
    uc.reg_write(UC_X86_REG_ESP, response.STACK)
    uc.reg_write(UC_X86_REG_ESI, NODES)

    def stop(machine, address, _size, _user):
        if address == 0x483881:
            machine.emu_stop()
    hook = uc.hook_add(UC_HOOK_CODE, stop)
    uc.emu_start(0x48384a, response.EXIT, count=10000)
    uc.hook_del(hook)
    if uc.reg_read(UC_X86_REG_EIP) != 0x483881:
        raise RuntimeError('width initialization did not reach stop')
    widths = list(struct.unpack('<16f', uc.mem_read(0x628be8, 64)))
    expected = [0.] * 16
    expected[0] = response.f32(half_extent * 2.)
    for i in range(1, depth):
        expected[i] = response.f32(expected[i-1] * .5)
    assert widths == expected
    return uc, widths


def packed(level, x, z):
    return (level << 28) | (z << 14) | x


def contains(code, widths, half_extent, point):
    width = widths[code >> 28]
    low_x = (code & 0x3fff) * width - half_extent
    low_z = response.f32(((code >> 14) & 0x3fff) * width - half_extent)
    return low_x <= point[0] <= low_x+width and low_z <= point[2] <= low_z+width


def expected_leaf(nodes, widths, half_extent, point):
    root = 0
    if all(child is None for child in nodes[root]['children']):
        return root
    code = nodes[root]['packed']
    width = widths[code >> 28]
    cx = ((code & 0x3fff)+.5)*width-half_extent
    cz = (((code >> 14) & 0x3fff)+.5)*width-half_extent
    node = root
    while True:
        if nodes[node]['records_present']:
            return node
        left, below = point[0] < cx, point[2] < cz
        slot = (2 if below else 0) if left else (3 if below else 1)
        cx += -width*.25 if left else width*.25
        cz += -width*.25 if below else width*.25
        width *= .5
        child = nodes[node]['children'][slot]
        if child is None:
            return root
        node = child


def put_nodes(uc, nodes):
    support.words(uc, VECTOR, [VECTOR+0x10, VECTOR+0x10, VECTOR+0x10])
    for i, node in enumerate(nodes):
        pointers = [0 if c is None else NODES+c*0x20 for c in node['children']]
        support.words(uc, NODES+i*0x20, [node['packed'], *pointers,
                                      VECTOR if node['records_present'] else 0])


def tree_shapes():
    def node(code=0, children=None, records=True):
        return {'packed': code, 'children': children or [None]*4, 'records_present': records}
    leaf = [node()]
    shallow = [node(0, [1, 2, 3, 4], False)]
    # Original pointer slot order: (-X,+Z), (+X,+Z), (-X,-Z), (+X,-Z).
    shallow += [node(packed(1, x, z)) for x, z in ((0,1),(1,1),(0,0),(1,0))]
    sparse = [dict(n, children=list(n['children'])) for n in shallow]
    sparse[0]['children'][3] = None
    empty_child = [dict(n, children=list(n['children'])) for n in shallow]
    empty_child[3]['records_present'] = False
    internal_records = [dict(n, children=list(n['children'])) for n in shallow]
    internal_records[0]['records_present'] = True
    deep = [dict(n, children=list(n['children'])) for n in shallow]
    deep[3] = node(packed(1,0,0), [5,6,7,8], False)
    deep += [node(packed(2,x,z)) for x,z in ((0,1),(1,1),(0,0),(1,0))]
    shifted = [dict(n, children=list(n['children'])) for n in shallow]
    shifted[0]['packed'] = packed(3, 5, 2)
    return [('leaf', leaf), ('shallow', shallow), ('sparse', sparse),
            ('empty_child', empty_child), ('internal_records', internal_records),
            ('deep', deep), ('shifted_root', shifted)]


def run(module, data):
    inits, bounds, queries, cache = [], [], [], []
    for extent in (32., 0.1, 123.45, 8192.):
        extent = response.f32(extent)
        for depth in (1, 4, 16):
            _, widths = grid(module, data, extent, depth)
            inits.append({'half_extent':extent, 'depth':depth, 'original_widths':widths})
        uc, widths = grid(module, data, extent)
        for code in (packed(0,0,0), packed(1,0,1), packed(3,5,2), packed(15,1234,4567)):
            w = widths[code >> 28]
            x = (code & 0x3fff)*w-extent
            z = ((code >> 14)&0x3fff)*w-extent
            points = ((x,z),(x+w,z+w),(x+w*.5,z+w*.5),(x-w*.01,z+w*.5),
                      (x+w*1.01,z+w*.5),(x+w*.5,z-w*.01),(x+w*.5,z+w*1.01))
            support.words(uc, NODES, [code])
            for px,pz in points:
                point = [response.f32(px), 999., response.f32(pz)]
                support.floats(uc, response.NORMAL, point)
                actual = bool(support.execute(uc,0x484450,[response.NORMAL],NODES)&255)
                assert actual == contains(code,widths,extent,point), (code,point,actual)
                bounds.append({'half_extent':extent,'packed':code,'point':point,'original_contains':actual})
    for name,nodes in tree_shapes():
        points = [(-16.,16.),(16.,16.),(-16.,-16.),(16.,-16.),(0.,0.),
                  (-.00001,0.),(0.,-.00001),(-32.,-32.),(32.,32.),(90.,90.),
                  (-24.,-24.),(-8.,-24.),(-24.,-8.),(-8.,-8.),(-16.,-16.),(10.,-10.)]
        for px,pz in points:
            uc,widths = grid(module,data,32.)
            put_nodes(uc,nodes)
            point = [response.f32(px), -999., response.f32(pz)]
            support.floats(uc,response.NORMAL,point)
            pointer = support.execute(uc,0x484500,[response.NORMAL],NODES)
            actual = (pointer-NODES)//0x20
            assert pointer == NODES+actual*0x20 and 0<=actual<len(nodes)
            expected = expected_leaf(nodes,widths,32.,point)
            assert actual == expected, (name,point,actual,expected)
            queries.append({'tree':name,'nodes':nodes,'point':point,'original_leaf':actual})
            # Full 0x473240 resolves the leaf and iterates empty vectors. Its
            # cache can accept shared boundaries differently from fresh lookup.
            for cached in (None, 0, min(3,len(nodes)-1)):
                support.words(uc,0x628960,[SCENE])
                support.words(uc,SCENE+0x24,[TREE])
                support.words(uc,TREE,[NODES])
                support.words(uc,OWNER+0x2c,[0 if cached is None else NODES+cached*0x20])
                support.words(uc,0x6289f0,[0])
                result = support.execute(uc,0x473240,[response.NORMAL],OWNER)
                assert result == 0  # vectors empty; no polygon is supplied
                actual_pointer, = struct.unpack('<I',uc.mem_read(OWNER+0x2c,4))
                actual_cache = (actual_pointer-NODES)//0x20
                hits, = struct.unpack('<I',uc.mem_read(0x6289f0,4))
                hit = cached is not None and nodes[cached]['records_present'] and contains(nodes[cached]['packed'],widths,32.,point)
                expected_cache = cached if hit else expected
                assert actual_cache == expected_cache and hits == int(hit), (name,point,cached,actual_cache,expected_cache)
                cache.append({'tree':name,'nodes':nodes,'point':point,'cached':cached,
                              'original_leaf':actual_cache,'original_cache_hit':bool(hits)})
    return {'module':'Porsche.exe','sha256':response.SHA,
            'scope':'original grid initialization slice, bounds/traversal and full support selector with empty record vectors; synthetic arenas',
            'initialization_cases':inits,'bounds_cases':bounds,'query_cases':queries,'cache_cases':cache}


def encoded_nodes(nodes):
    return ';'.join(f"{n['packed']}:{','.join(str(-1 if c is None else c) for c in n['children'])}:{int(n['records_present'])}" for n in nodes)


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output',type=Path,required=True)
    parser.add_argument('--fixtures-dir',type=Path,required=True)
    parser.add_argument('--source-output',type=Path)
    args=parser.parse_args()
    inventory=response.ROOT/'research/binary-index/static/binaries.jsonl'
    module,=[m for m in map(json.loads,inventory.read_text(encoding='utf-8').splitlines()) if m['file']=='Porsche.exe']
    data=(response.ROOT/'local/game'/module['path']).read_bytes()
    if response.hashlib.sha256(data).hexdigest()!=response.SHA or module['sha256']!=response.SHA:
        raise RuntimeError('original SHA256 mismatch')
    result=run(module,data)
    args.output.parent.mkdir(parents=True,exist_ok=True)
    # Store each supplied arena once; fixture rows below still carry the
    # complete arena so the Rust tests remain independently consumable.
    exported = {k:v for k,v in result.items() if not k.endswith('_cases')}
    exported['trees'] = dict(tree_shapes())
    for key in ('initialization_cases', 'bounds_cases', 'query_cases', 'cache_cases'):
        exported[key] = [{k:v for k,v in case.items() if k!='nodes'} for case in result[key]]
    # One JSON record per line keeps source review practical without losing
    # inputs or original outputs; the file remains a single valid JSON object.
    blocks=[]
    for key,value in exported.items():
        if key.endswith('_cases'):
            encoded='[\n'+',\n'.join('    '+json.dumps(case) for case in value)+'\n  ]'
        else:
            encoded=json.dumps(value)
        blocks.append('  '+json.dumps(key)+': '+encoded)
    args.output.write_text('{\n'+',\n'.join(blocks)+'\n}\n',encoding='utf-8')
    args.fixtures_dir.mkdir(parents=True,exist_ok=True)
    rows=['half_extent\tdepth\twidths']
    for f in result['initialization_cases']:
        rows.append(f"{f['half_extent']}\t{f['depth']}\t{','.join(map(str,f['original_widths']))}")
    (args.fixtures_dir/'grid-fixtures.tsv').write_text('\n'.join(rows)+'\n',encoding='utf-8')
    rows=['half_extent\tpacked\tpx\tpy\tpz\tcontains']
    for f in result['bounds_cases']:
        rows.append('\t'.join(map(str,[f['half_extent'],f['packed'],*f['point'],int(f['original_contains'])])))
    (args.fixtures_dir/'bounds-fixtures.tsv').write_text('\n'.join(rows)+'\n',encoding='utf-8')
    for kind in ('query','cache'):
        rows=['nodes\tpx\tpy\tpz\tcached\tleaf\tcache_hit']
        for f in result[f'{kind}_cases']:
            rows.append('\t'.join(map(str,[encoded_nodes(f['nodes']),*f['point'],
                                          -1 if f.get('cached') is None else f['cached'],
                                          f['original_leaf'],int(f.get('original_cache_hit',False))])))
        (args.fixtures_dir/f'{kind}-fixtures.tsv').write_text('\n'.join(rows)+'\n',encoding='utf-8')
    if args.source_output:
        output=[]
        for address in (0x483800,0x484450,0x484500,0x473240):
            command=['py','-3',str(response.ROOT/'scripts/research/query-binary-index.py'),
                     '--binary','Porsche.exe','--address',hex(address),'--disassemble','--limit','1000']
            output.append(subprocess.check_output(command,cwd=response.ROOT,text=True,encoding='utf-8').rstrip())
        args.source_output.parent.mkdir(parents=True,exist_ok=True)
        args.source_output.write_text('\n'.join(output)+'\n',encoding='utf-8')
    print(' / '.join(f'{len(result[k+"_cases"])} {k}' for k in ('initialization','bounds','query','cache'))+' original-x86 cases passed')


if __name__=='__main__':
    main()
