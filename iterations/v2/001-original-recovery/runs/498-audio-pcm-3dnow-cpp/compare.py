"""Run498 only: original/compiled C++ 3DNow on the same pinned Athlon emulator."""
import argparse
import hashlib
import importlib.util
import json
import os
from pathlib import Path
import struct
import subprocess
import sys
import time

ROOT = Path(__file__).resolve().parents[5]
RUN = Path(__file__).resolve().parent
sys.path[:0] = [str(ROOT/'scripts/research'), str(ROOT/'local/tools/python-unicorn')]
import capstone
import unicorn
from unicorn import Uc, UcError, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE, UC_HOOK_MEM_READ, UC_HOOK_MEM_WRITE
from unicorn import x86_const as x
from audio_recovery_provenance import dependency_paths


def load(name, path):
    spec = importlib.util.spec_from_file_location(name, path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


native = load('native498', ROOT/'scripts/research/verify-v2-native-batch.py')
coff = load('coff498', ROOT/'scripts/research/experiment-v2-thiscall-leaves-187.py')
digest = lambda data: hashlib.sha256(data).hexdigest()
sha = lambda path: digest(Path(path).read_bytes())
relative = lambda path: Path(path).resolve().relative_to(ROOT).as_posix() if Path(path).resolve().is_relative_to(ROOT) else str(Path(path).resolve())


def save(path, value):
    Path(path).write_text(json.dumps(value, indent=2)+'\n', encoding='utf-8', newline='\n')


def image_info(raw):
    pe = struct.unpack_from('<I', raw, 60)[0]
    assert raw[pe:pe+4] == b'PE\0\0'
    assert struct.unpack_from('<H', raw, pe+4)[0] == 0x14c
    optional = pe+24
    base = struct.unpack_from('<I', raw, optional+28)[0]
    size = struct.unpack_from('<I', raw, optional+56)[0]
    table = optional+struct.unpack_from('<H', raw, pe+20)[0]
    sections = [struct.unpack_from('<IIII', raw, table+40*i+8)
                for i in range(struct.unpack_from('<H', raw, pe+6)[0])]
    directories = [struct.unpack_from('<II', raw, optional+96+8*i) for i in range(16)]
    return dict(base=base, size=size, sections=sections, directories=directories)


def exports(raw, info):
    rva, _ = info['directories'][0]
    at = lambda va, n: native.pe_at(raw, va, n)
    row = struct.unpack('<IIHHIIIIIII', at(info['base']+rva, 40))
    _, _, _, _, _, ordinal_base, nfunc, nname, funcs, names, ords = row
    result = {}
    for i in range(nname):
        name_rva = struct.unpack('<I', at(info['base']+names+i*4, 4))[0]
        address = info['base']+name_rva
        name = bytearray()
        while (ch := at(address+len(name), 1)[0]):
            name.append(ch)
        ordinal = struct.unpack('<H', at(info['base']+ords+i*2, 2))[0]
        assert ordinal < nfunc
        result[name.decode('ascii')] = info['base']+struct.unpack('<I', at(info['base']+funcs+ordinal*4, 4))[0]
    return result


ARENA, ARENA_SIZE, STACK, SP, HARNESS, EXIT = 0x3000000, 0x80000, 0x2000000, 0x200e000, 0x2200000, 0x2200800
FPREGS = [getattr(x, 'UC_X86_REG_FP'+str(i)) for i in range(8)]
GPRS = {name:getattr(x, 'UC_X86_REG_'+name.upper()) for name in ['eax','ebx','ecx','edx','ebp','esi','edi','esp']}
GPR_SEED = dict(eax=0xa1a2a3a4,ebx=0xb1b2b3b4,ecx=0xc1c2c3c4,edx=0xd1d2d3d4,ebp=0x1718191a,esi=0xe1e2e3e4,edi=0xf1f2f3f4,esp=SP)


def fpstate(uc):
    return [uc.reg_read(reg) for reg in [x.UC_X86_REG_FPCW, x.UC_X86_REG_FPSW, x.UC_X86_REG_FPTAG, x.UC_X86_REG_MXCSR, *FPREGS]]


class Machine:
    def __init__(self, raw, entrypoints, model, bounds=None):
        self.uc = uc = Uc(UC_ARCH_X86, UC_MODE_32)
        uc.ctl_set_cpu_model(model)
        assert uc.ctl_get_cpu_model() == model == x.UC_CPU_X86_ATHLON
        info = image_info(raw)
        uc.mem_map(info['base'], (info['size']+4095)&~4095)
        for vsize, rva, rsize, offset in info['sections']:
            if rsize:
                uc.mem_write(info['base']+rva, raw[offset:offset+rsize])
        for address, size in [(ARENA,ARENA_SIZE),(STACK,0x10000),(HARNESS,0x1000)]:
            uc.mem_map(address,size)
        self.entrypoints = entrypoints
        self.allowed = bounds or [(info['base']+rva,info['base']+rva+vsize) for vsize,rva,_,_ in info['sections']]
        self.pf = {}
        md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
        if bounds:
            chunks = [(start,native.pe_at(raw,start,end-start)) for start,end in bounds]
        else:
            chunks = [(info['base']+rva,raw[offset:offset+rsize]) for _,rva,rsize,offset in info['sections'] if rsize]
        for address, body in chunks:
            for ins in md.disasm(body,address):
                if ins.mnemonic in ('pfmul','pfadd','pi2fd','femms'):
                    self.pf[ins.address] = ins.mnemonic
        self.active = False
        uc.hook_add(UC_HOOK_CODE, self.code)
        uc.hook_add(UC_HOOK_MEM_READ | UC_HOOK_MEM_WRITE, self.memory)

    def code(self, uc, address, size, user):
        if not self.active:
            return
        assert any(start <= address < end for start,end in self.allowed), ('unexpected code',hex(address))
        if address in self.pf:
            state = fpstate(uc)
            self.fp_events.update(json.dumps([self.pf[address],state],separators=(',',':')).encode()+b'\n')
            self.fp_count += 1

    def memory(self, uc, access, address, size, value, user):
        if not self.active or not ARENA <= address < ARENA+ARENA_SIZE:
            return
        assert ARENA <= address and address+size <= ARENA+self.scene_size, ('arena escape',hex(address),size)
        kind = 1 if access == unicorn.UC_MEM_WRITE else 0
        payload = (value & ((1<<(size*8))-1)).to_bytes(size,'little') if kind else bytes(uc.mem_read(address,size))
        self.events.update(struct.pack('<BII',kind,address-ARENA,size)+payload)
        self.event_count += 1

    def run(self, case):
        uc = self.uc
        arena, source, destination = arena_for(case)
        self.scene_size = len(arena)
        self.events, self.fp_events = hashlib.sha256(), hashlib.sha256()
        self.event_count = self.fp_count = 0
        self.active = False
        uc.mem_write(ARENA, arena)
        uc.mem_write(STACK, b'\xa5'*0x10000)
        # Explicitly reset every aliased x87/MMX payload before real x87 seeding.
        for i,reg in enumerate(FPREGS):
            uc.reg_write(reg,(0x8000000000000000 + (case.get('mmx',0)*0x123456789abcdef+i),0x3fff))
        cw, depth, sticky, mxcsr = case.get('cw',0x37f), case.get('depth',0), case.get('sticky',0), case.get('mxcsr',0x1f80)
        seed = b'\xdb\xe3'+b'\xd9\x2d'+struct.pack('<I',HARNESS+0x100)+b'\xd9\xe8'*depth
        uc.mem_write(HARNESS,seed)
        uc.mem_write(HARNESS+0x100,struct.pack('<H',cw))
        uc.emu_start(HARNESS,HARNESS+len(seed),count=32)
        uc.reg_write(x.UC_X86_REG_FPSW,uc.reg_read(x.UC_X86_REG_FPSW)|sticky)
        uc.reg_write(x.UC_X86_REG_MXCSR,mxcsr)
        seeded = fpstate(uc)
        assert seeded[0] == cw and seeded[1]>>11&7 == ((-depth)&7)
        args = [case['count']&0xffffffff]
        if case['kernel'] == 'accumulate':
            args.append(case.get('gain',0x3fa00000))
        args.extend([source,destination])
        stack = struct.pack('<'+'I'*(len(args)+1),EXIT,*args)
        uc.mem_write(SP,stack)
        for name,value in GPR_SEED.items():
            uc.reg_write(GPRS[name],value)
        uc.reg_write(x.UC_X86_REG_EFLAGS,0x202)
        self.active = True
        try:
            uc.emu_start(self.entrypoints[case['kernel']],EXIT,count=max(3000,abs(case['count'])*100+3000))
            assert uc.reg_read(x.UC_X86_REG_EIP) == EXIT, 'instruction budget/invalid return'
        finally:
            self.active = False
        state = fpstate(uc)
        regs = {name:uc.reg_read(GPRS[name]) for name in ['ebx','ebp','esi','edi','esp']}
        assert regs == {**{name:GPR_SEED[name] for name in ['ebx','ebp','esi','edi']},'esp':SP+4}, ('cdecl ABI',regs)
        # By-value argument copies are callee-owned; optimized C++ may reuse
        # them. All eight original consumers discard them with ADD ESP12/16.
        assert bytes(uc.mem_read(SP,4)) == stack[:4], 'return sentinel overwritten'
        assert bytes(uc.mem_read(SP+len(stack),32)) == b'\xa5'*32, 'caller stack canary overwritten'
        assert bytes(uc.mem_read(STACK,32)) == b'\xa5'*32, 'stack lower canary overwritten'
        return dict(memory=digest(bytes(uc.mem_read(ARENA,len(arena)))), input=digest(arena),
            events=self.events.hexdigest(),event_count=self.event_count,
            fp_events=self.fp_events.hexdigest(),fp_event_count=self.fp_count,
            initial_fp=seeded,final_fp=state,preserved=regs)


SPECIAL = [0,0x80000000,1,0x80000001,0x007fffff,0x807fffff,0x00800000,0x80800000,
           0x3f000000,0xbf000000,0x3f800000,0xbf800000,0x3faaaaab,0x7f7fffff,0xff7fffff,
           0x7f800000,0xff800000,0x7fc00001,0xffc01234,0x7f800001,0xff800001]


def arena_for(case):
    count = case['count']
    bulk = case.get('pattern') == 'all_s16'
    size = 0x70000 if bulk else 0x4000
    buf = bytearray((b'\x39\xa7\xd3\x65'*(size//4)))
    # Bulk source and destination are disjoint; small scenes allow padded negative
    # prefixes and byte alignments. Address-space arithmetic remains unsigned32.
    source = ARENA+0x400+case.get('sa',0)
    destination = source+case['overlap'] if 'overlap' in case else ARENA+(0x30000 if bulk else 0x2400)+case.get('da',0)
    n = max(96,count+16) if not bulk else 65536
    if bulk:
        struct.pack_into('<65536H',buf,source-ARENA,*range(65536))
    elif case['kernel'] == 'decode':
        values = [0,1,0x7fff,0x8000,0xffff,0x1234,0x8001,0xfffe,0xabcd]
        for i in range(-24,n):
            struct.pack_into('<H',buf,source-ARENA+i*2,values[i%len(values)])
    elif case.get('pattern') == 'fp_cartesian':
        for i in range(n):
            struct.pack_into('<I',buf,source-ARENA+i*4,SPECIAL[(i//len(SPECIAL))%len(SPECIAL)])
            struct.pack_into('<I',buf,destination-ARENA+i*4,SPECIAL[i%len(SPECIAL)])
    else:
        values = [0x3f800000,0xbf400000,0x40200000,0x3eaaaaab,0x41080000,0xc0a80000]
        for i in range(-24,n):
            struct.pack_into('<I',buf,source-ARENA+i*4,values[i%len(values)])
        if 'overlap' not in case:
            for i in range(-24,n):
                struct.pack_into('<I',buf,destination-ARENA+i*4,values[(i+3)%len(values)])
    return bytes(buf),source,destination


def cases():
    rows = []
    def add(kernel,group,**kw):
        rows.append(dict(name=f'{group}-{kernel}-{len(rows):04d}',kernel=kernel,group=group,**kw))
    for kernel in ['accumulate','decode']:
        for count in [0,1,7,8,9,16,17,*range(-1,-9,-1),*range(2,7),*range(10,16),*range(18,34),63,64,65]:
            add(kernel,'count',count=count)
        for sa in range(16):
            for da in range(16):
                add(kernel,'align',count=17,sa=sa,da=da)
        for offset in [-33,-17,-16,-8,-4,-2,-1,0,1,2,4,8,16,17,33]:
            for count in [0,1,7,8,9,16,17]:
                add(kernel,'alias',count=count,sa=(offset*3)&15,overlap=offset)
        for cw in [0x7f,0x27f,0x37f]:
            for rounding in range(4):
                for depth in [0,1,3,6]:
                    for sticky in [0,0x25]:
                        add(kernel,'fpstate',count=17,cw=cw|(rounding<<10),depth=depth,sticky=sticky,mmx=(rounding+depth)&1)
        for mxcsr in [0x1f80,0x3f80,0x5f80,0x7f80,0x9f80,0x1fc0,0x9fc0,0x1fbf]:
            add(kernel,'mxcsr',count=9,mxcsr=mxcsr,depth=3,mmx=1)
    for gain in SPECIAL:
        add('accumulate','fp_cartesian',count=len(SPECIAL)**2,gain=gain,pattern='fp_cartesian')
    add('decode','all_s16',count=65536,pattern='all_s16',mmx=1)
    return rows


def difference(expected, actual):
    return [name for name in expected if expected[name] != actual.get(name)]


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--attempt',type=int,required=True)
    args = parser.parse_args()
    cfg = json.loads((RUN/'config.json').read_text())
    out = ROOT/cfg['experiment']/f'{args.attempt:03d}'
    assert args.attempt > 0 and not out.exists(), 'immutable attempt exists'
    out.mkdir(parents=True)
    started = time.monotonic()
    pins = {}
    def pin(path):
        pins[relative(path)] = sha(path)
        return Path(path)
    def guard():
        for path,expected in pins.items():
            assert sha(ROOT/path if not Path(path).is_absolute() else path) == expected, ('input drift',path)
    vc = ROOT/'local/tools/BuildTools/VC/Tools/MSVC/14.44.35207'
    cl, link = vc/'bin/Hostx64/x86/cl.exe',vc/'bin/Hostx64/x86/link.exe'
    for path in [cl,link,cl.parent/'c1xx.dll',cl.parent/'c2.dll',__file__,RUN/'config.json',RUN/cfg['source'],RUN/cfg['header'],
                 ROOT/cfg['original_pe'],Path(unicorn.__file__),ROOT/'local/tools/python-unicorn/unicorn/lib/unicorn.dll',
                 ROOT/'scripts/research/verify-v2-native-batch.py',ROOT/'scripts/research/experiment-v2-thiscall-leaves-187.py',
                 ROOT/'scripts/research/experiment-v2-thiscall-186.py',ROOT/'scripts/research/audio_recovery_provenance.py']:
        pin(path)
    inputs = out/'inputs'
    inputs.mkdir()
    for filename in ['config.json',cfg['source'],cfg['header'],'compare.py']:
        (inputs/filename).write_bytes((RUN/filename).read_bytes())
    raw = (ROOT/cfg['original_pe']).read_bytes()
    assert digest(raw) == cfg['original_sha256']
    for row in cfg['original_bodies']:
        assert digest(native.pe_at(raw,int(row['va'],16),row['bytes'])) == row['sha256']
    md = capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
    original_evidence = dict(module_sha256=digest(raw),bodies=cfg['original_bodies'],
        gap=dict(va='0059bbc4',raw=native.pe_at(raw,0x59bbc4,3).hex(),reason='Skipped by original JE59bbc7 and JMP59bb9f;160 indexed body vs163 contiguous span'),
        callsites=[dict(va=f'{va:08x}',raw=native.pe_at(raw,va,65).hex(),
            instructions=[dict(va=f'{i.address:08x}',mnemonic=i.mnemonic,operands=i.op_str,raw=i.bytes.hex())
                          for i in md.disasm(native.pe_at(raw,va,65),va)])
            for va in [0x597b96,0x597bd4,0x5981a5,0x598837,0x598ac3,0x598c88,0x59cae1,0x59cbd9]],
        abi='cdecl4(count,gain_bits,source,destination) / cdecl3(count,S16 source,F32 destination); RET0; preserved EBX/EBP/ESI/EDI/ESP',
        consumer_state='Eight callsites clean16/12 bytes, ignore EAX/EDX/ECX and MMX payloads; ECX is reloaded or dead.5981bf uses x87 after the provider: FEMMS/FP environment matter. FP payloads and pre-PF intermediate states are compared as stronger bounded evidence, not a new ABI obligation.')
    save(out/'original-evidence.json',original_evidence)
    # Generate all mutations before a single compile invocation per optimization.
    variants = {'baseline':(RUN/cfg['source']).read_text()}
    for mutation in cfg['mutations']:
        text = variants['baseline']
        assert text.count(mutation['from']) == mutation['count'], mutation['name']
        variants[mutation['name']] = text.replace(mutation['from'],mutation['to'])
    sources = out/'sources'
    sources.mkdir()
    (sources/cfg['header']).write_bytes((RUN/cfg['header']).read_bytes())
    for name,text in variants.items():
        path = sources/(name+'.cpp')
        path.write_text(text,encoding='utf-8',newline='\n')
        pin(path)
    entry = sources/'image_entry.cpp'
    entry.write_text('extern "C" void __cdecl image_entry_498(){}\n',encoding='utf-8',newline='\n')
    pin(entry)
    executions = []
    def execute(name,command):
        guard()
        start = time.monotonic()
        proc = subprocess.run(list(map(str,command)),cwd=out,env={**os.environ,'VSLANG':'1033','CL':'','_CL_':'','INCLUDE':''},capture_output=True,timeout=120)
        log = out/(name+'.log')
        log.write_bytes((proc.stdout+proc.stderr).replace(b'\r\n',b'\n'))
        row = dict(name=name,command=list(map(str,command)),exit_code=proc.returncode,seconds=time.monotonic()-start,log_sha256=sha(log))
        executions.append(row)
        save(out/'executions.json',executions)
        assert proc.returncode == 0, (name,log.read_text(errors='replace')[-4000:])
    images = {}
    coffs = {}
    for optimization in ['Od','O2']:
        opt = out/optimization
        opt.mkdir()
        deps = opt/'dependencies'
        deps.mkdir()
        execute('compile-'+optimization,[cl,'/nologo','/c','/TP','/std:c++17','/'+optimization,'/Oi','/Gy','/GS-','/GR-','/Zl','/W4','/WX','/utf-8','/arch:IA32','/MP6','/I',vc/'include','/sourceDependencies',str(deps)+os.sep,'/Fo'+str(opt)+os.sep,*[sources/(name+'.cpp') for name in variants],entry])
        for path in dependency_paths(opt):
            pin(path)
        coffs[optimization] = {}
        images[optimization] = {}
        for name in variants:
            obj = opt/(name+'.obj')
            details = coff.coff_symbols(obj)
            assert not details['undefined_external_symbols'], details
            assert set(details['defined_external_symbols']) == set(cfg['exports'].values()),details
            coffs[optimization][name] = dict(**details,sha256=sha(obj))
            exe = opt/(name+'.exe')
            execute('link-'+optimization+'-'+name,[link,'/nologo','/MACHINE:X86','/SUBSYSTEM:CONSOLE','/ENTRY:image_entry_498','/NODEFAULTLIB','/FIXED','/DYNAMICBASE:NO','/BASE:0x10000000','/OUT:'+str(exe),*[f'/EXPORT:{export}={symbol}' for export,symbol in cfg['exports'].items()],obj,opt/'image_entry.obj'])
            image = exe.read_bytes()
            info = image_info(image)
            assert info['directories'][1] == (0,0), 'unexpected PE imports'
            assert info['directories'][5] == (0,0), 'unexpected PE relocations'
            images[optimization][name] = (image,exports(image,info))
        print(json.dumps(dict(stage='compiled',optimization=optimization,variants=len(variants))),flush=True)
    save(out/'coff.json',coffs)
    guard()
    scenes = cases()
    save(out/'cases.json',scenes)
    originals = {row['name']:int(row['va'],16) for row in cfg['original_bodies']}
    bounds = [(int(row['va'],16),int(row['va'],16)+row['bytes']) for row in cfg['original_bodies']]
    oracle = Machine(raw,originals,cfg['cpu_model'],bounds)
    candidates = {optimization:Machine(*images[optimization]['baseline'],cfg['cpu_model']) for optimization in images}
    records, expected_cache = [], {}
    counts = dict(cases=0,events=0,fp_events=0)
    for index,case in enumerate(scenes):
        expected = oracle.run(case)
        for optimization,machine in candidates.items():
            actual = machine.run(case)
            changed = difference(expected,actual)
            if changed:
                save(out/'failure.json',dict(case=case,optimization=optimization,differences=changed,expected=expected,actual=actual))
                raise AssertionError(('comparison mismatch',index,optimization,case['name'],changed))
        if case['group'] in ['count','alias']:
            expected_cache[case['name']] = expected
        records.append(dict(case=case['name'],**expected))
        counts['cases'] += 1
        counts['events'] += expected['event_count']
        counts['fp_events'] += expected['fp_event_count']
        if index%200 == 0:
            print(json.dumps(dict(stage='compare',completed=index+1,total=len(scenes))),flush=True)
    save(out/'comparisons.json',records)
    mutation_results = []
    mutation_cases = [case for case in scenes if case['group'] in ['count','alias']]
    for optimization in images:
        for mutation in cfg['mutations']:
            name = mutation['name']
            machine = Machine(*images[optimization][name],cfg['cpu_model'])
            detected = None
            for case in mutation_cases:
                try:
                    actual = machine.run(case)
                    changed = difference(expected_cache[case['name']],actual)
                except (UcError,AssertionError) as exc:
                    changed = [str(exc)]
                if changed:
                    detected = dict(optimization=optimization,mutation=name,case=case['name'],differences=changed)
                    break
            assert detected, ('undetected mutation',optimization,name)
            mutation_results.append(detected)
    save(out/'mutations.json',mutation_results)
    guard()
    outputs = {relative(path):sha(path) for path in out.rglob('*') if path.is_file()}
    receipt = dict(schema=1,status='PASS',kind='emulated-original-vs-emulated-compiled-cpp',
        original_sha256=cfg['original_sha256'],cpu_model=cfg['cpu_model'],unicorn_version=unicorn.__version__,
        unicorn_core_version=unicorn.uc_version(),case_counts_per_optimization=counts,optimizations=['Od','O2'],
        mutations_detected=len(mutation_results),variants_per_optimization=len(variants),
        original_body_bytes=319,contiguous_raw_span_bytes=322,new_state_bytes=0,
        input_sha256=pins,output_sha256=outputs,elapsed_seconds=time.monotonic()-started,
        boundaries=['Both sides share the pinned Unicorn Athlon11 implementation; no physical AMD/native-hardware acceptance',
                    'Padded mapped buffers, finite counts, masked exceptions only; no unmasked faults or extreme-count proof',
                    'No full producer/caller composition, concurrency/live audio/gameplay proof',
                    'No provider integration: coordinator audit extension remains required'])
    save(out/'receipt.json',receipt)
    (RUN/'validation.json').write_bytes((out/'receipt.json').read_bytes())
    (RUN/'original-evidence.json').write_bytes((out/'original-evidence.json').read_bytes())
    (RUN/'coff.json').write_bytes((out/'coff.json').read_bytes())
    print(json.dumps(dict(status='PASS',**counts,mutations=len(mutation_results),seconds=time.monotonic()-started)),flush=True)


if __name__ == '__main__':
    main()
