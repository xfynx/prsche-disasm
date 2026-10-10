import argparse, hashlib, json, struct, subprocess, sys
from pathlib import Path

ROOT=Path(__file__).resolve().parents[2]
RUN=ROOT/'iterations/v2/001-original-recovery/runs/129-application-context'
sys.path.insert(0,str(ROOT/'scripts/research'))
from v2_source_dependencies import source_hashes
sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ECX,UC_X86_REG_EIP,UC_X86_REG_ESP

IMAGE,IMAGE_BYTES=0x400000,0x300000
ARENA,ARENA_BYTES,STACK,EXIT=0x03600000,0x10000,0x0200f000,0x02200000
SHA='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
MOD='research/v2/binaries/Porsche.exe-ddd748fdbe6d'
CASES=[(0,b''),(1,b'A\0'),(2,b'0123456789abcdef\0'),(3,b'0123456789abcdef\0')]

def original(mode,source,module,binary):
    uc=Uc(UC_ARCH_X86,UC_MODE_32);uc.mem_map(IMAGE,IMAGE_BYTES)
    for sec in module['sections']:
        if sec['raw_size']:
            uc.mem_write(IMAGE+sec['rva'],binary[sec['raw_offset']:sec['raw_offset']+sec['raw_size']])
    uc.mem_map(ARENA,ARENA_BYTES);uc.mem_write(ARENA,b'\0'*ARENA_BYTES)
    uc.mem_map(0x02000000,0x10000);uc.mem_map(EXIT,0x1000)
    context=ARENA+0x1000
    pattern=bytes((i*37+0x53)&255 for i in range(0x180))
    uc.mem_write(context,pattern)
    uc.mem_write(0x005e8e50,source+b'\0'*(32-len(source)))
    calls=[]
    def put(addr,value):uc.mem_write(addr,struct.pack('<I',value&0xffffffff))
    def hook(machine,addr,size,_):
        if addr==EXIT:machine.emu_stop();return
        if 0x004d1a90<=addr<0x004d1b3c or 0x004d1ba0<=addr<0x004d1bce:return
        if addr in (0x00525e20,0x005294c0,0x005295b0,0x00525ec0):
            calls.append({0x00525e20:'00525e20',0x005294c0:'005294c0',
                0x005295b0:'005295b0',0x00525ec0:'00525ec0'}[addr])
            sp=machine.reg_read(UC_X86_REG_ESP);ret=struct.unpack('<I',machine.mem_read(sp,4))[0]
            if addr==0x00525ec0:machine.reg_write(UC_X86_REG_EAX,0xb16b00b5)
            machine.reg_write(UC_X86_REG_ESP,sp+4);machine.reg_write(UC_X86_REG_EIP,ret);return
        if addr in (0x0059ef90,0x0059f050):
            sp=machine.reg_read(UC_X86_REG_ESP);ret=struct.unpack('<I',machine.mem_read(sp,4))[0]
            if addr==0x0059ef90:
                calls.append('0059ef90')
                requested=struct.unpack('<I',machine.mem_read(sp+4,4))[0]
                if requested!=0x2c:raise AssertionError(f'allocator size {requested:#x}')
                machine.reg_write(UC_X86_REG_EAX,ARENA+0x5000 if mode in (1,2) else 0)
            else:
                released=struct.unpack('<I',machine.mem_read(sp+4,4))[0]
                calls.append('0059f050:member' if released==ARENA+0x5000 else '0059f050:other')
                if released != ARENA+0x5000:
                    raise AssertionError('dtor released wrong member')
                machine.reg_write(UC_X86_REG_EAX,1)
            machine.reg_write(UC_X86_REG_ESP,sp+4);machine.reg_write(UC_X86_REG_EIP,ret);return
        raise RuntimeError(f'unexpected x86 PC {addr:08x}, calls={calls}')
    uc.hook_add(UC_HOOK_CODE,hook)
    uc.mem_write(STACK,struct.pack('<I',EXIT));uc.reg_write(UC_X86_REG_ESP,STACK)
    uc.reg_write(UC_X86_REG_ECX,context)
    try:uc.emu_start(0x004d1a90,EXIT+1,count=50000)
    except Exception as exc:raise RuntimeError(f'ctor x86 failed pc={uc.reg_read(UC_X86_REG_EIP):08x} sp={uc.reg_read(UC_X86_REG_ESP):08x} calls={calls}') from exc
    ctor_result=uc.reg_read(UC_X86_REG_EAX)
    ctor=bytes(uc.mem_read(context,0x180))
    uc.reg_write(UC_X86_REG_ECX,context);uc.reg_write(UC_X86_REG_ESP,STACK)
    try:uc.emu_start(0x004d1ba0,EXIT+1,count=50000)
    except Exception as exc:raise RuntimeError(f'dtor x86 failed pc={uc.reg_read(UC_X86_REG_EIP):08x} sp={uc.reg_read(UC_X86_REG_ESP):08x} calls={calls}') from exc
    dtor_result=uc.reg_read(UC_X86_REG_EAX)
    dtor=bytes(uc.mem_read(context,0x180))
    return {'after_ctor':ctor,'after_dtor':dtor,'calls':calls,
        'ctor_result_ok':ctor_result==context,'dtor_eax_forwarded':dtor_result==0xb16b00b5}

def main():
    parser=argparse.ArgumentParser()
    parser.add_argument('--probe',type=Path,default=ROOT/'local/builds/v2/application-context-129/bin/Release/application_context_probe.exe')
    parser.add_argument('--report-dir',type=Path,default=RUN)
    args=parser.parse_args()
    module=next(x for x in map(json.loads,(ROOT/'research/binary-index/static/binaries.jsonl').read_text().splitlines()) if x['file']=='Porsche.exe')
    binary=(ROOT/'local/game'/module['path']).read_bytes()
    if hashlib.sha256(binary).hexdigest()!=SHA:raise RuntimeError('original SHA mismatch')
    inp=''.join(f'{mode}\n' for mode,_ in CASES)
    got=[json.loads(x) for x in subprocess.run([str(args.probe)],input=inp,text=True,capture_output=True,check=True,timeout=30).stdout.splitlines()]
    if len(got)!=len(CASES):raise RuntimeError('probe case count mismatch')
    fixtures=[]
    for i,((mode,source),native) in enumerate(zip(CASES,got)):
        expected=original(mode,source,module,binary)
        for key in ('after_ctor','after_dtor'):
            actual=bytearray.fromhex(native[key]);want=bytearray(expected[key])
            # The only relocated field is the allocator-owned pointer at +d4.
            for image in (actual,want):
                value=struct.unpack_from('<I',image,0xd4)[0]
                struct.pack_into('<I',image,0xd4,1 if value else 0)
            if actual!=want:
                offset=next(j for j,(a,b) in enumerate(zip(actual,want)) if a!=b)
                raise AssertionError(f'case {i} {key} first mismatch at +{offset:#x}')
        if native['calls']!=expected['calls']:
            raise AssertionError(f'case {i} call order mismatch: {native["calls"]} != {expected["calls"]}')
        for key in ('ctor_result_ok','dtor_eax_forwarded'):
            if native[key] != expected[key]:raise AssertionError(f'case {i} {key} mismatch')
        fixtures.append({'input':mode,'sha256':hashlib.sha256(json.dumps({
            'after_ctor':native['after_ctor'],'after_dtor':native['after_dtor'],
            'calls':native['calls']},sort_keys=True).encode()).hexdigest()})
    full=['004d1a90','004d1ba0']
    compiled=['iterations/v2/001-original-recovery/source/recovered/Porsche.exe/application_context.cpp',
        'iterations/v2/001-original-recovery/source/recovered/application_context_probe.cpp']
    paths=compiled+['iterations/v2/001-original-recovery/source/include/porsche/application_context.hpp',
        'iterations/v2/001-original-recovery/source/include/porsche/application_alloc.hpp',
        'iterations/v2/001-original-recovery/source/include/porsche/application_heap_init.hpp',
        'iterations/v2/001-original-recovery/runs/129-application-context/CMakeLists.txt',
        'iterations/v2/001-original-recovery/runs/129-application-context/README.md',
        'scripts/research/verify-v2-application-context.py',
        'research/binary-index/static/binaries.jsonl',
        'research/v2/binaries/Porsche.exe-ddd748fdbe6d/functions.jsonl',
        'research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm',
        'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/calls.jsonl']
    hashes=source_hashes(paths,compiled_sources=compiled)
    args.report_dir.mkdir(parents=True,exist_ok=True)
    report={'schema':1,'module':'Porsche.exe','sha256':SHA,'range':'004d1a90..004d1bcd',
        'function_vas':full,'full_function_vas':full,'partial_function_vas':[],
        'cases':len(CASES),'native_cpp_equal_original_x86':True,
        'comparison':'Full 0x180-byte caller storage after constructor and destructor plus ordered typed external-boundary calls; allocator pointer at +0xd4 is compared as relocated null/non-null identity.',
        'unknown_boundaries':['00525e20','005294c0','005295b0','00525ec0'],
        'source_string':'Reads existing 005e8e50 owner to NUL; Run 081 unresolved alias/extent remains open.',
        'source_sha256':hashes,'probe_sha256':hashlib.sha256(args.probe.read_bytes()).hexdigest(),
        'fixtures':fixtures}
    (args.report_dir/'verification.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf8',newline='\n')
    print(json.dumps({'functions':full,'cases':len(CASES),'native_cpp_equal_original_x86':True,
        'report':str(args.report_dir/'verification.json')}))
if __name__=='__main__':main()
