"""Differentially execute the original CRT callback registry and native recovery."""
import argparse
import hashlib
import json
from pathlib import Path
import struct
import subprocess
import sys

from v2_source_dependencies import source_hashes

ROOT=Path(__file__).resolve().parents[2]
RUN=ROOT/'iterations/v2/001-original-recovery/runs/052-exit-registry'
sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_EIP,UC_X86_REG_ESP

ARENA,ARENA_BYTES,STACK,EXIT=0x03600000,0x10000,0x0200f000,0x02200000
BASE,NEXT=0x006c1534,0x006c1530
CASES=[(1,0,0,-1),(1,0,1,-1),(1,0,32,-1),(1,0,33,-1),
       (1,0,37,-1),(1,1,33,-1),(1,0,3,2),(0,0,4,-1)]

def original(case,module,binary,rows):
    init_ok,realloc_fail,count,null_index=case
    uc=Uc(UC_ARCH_X86,UC_MODE_32);image=int(module['image_base'],16);uc.mem_map(image,0x300000)
    for section in module['sections']:
        uc.mem_write(image+section['rva'],binary[section['raw_offset']:section['raw_offset']+section['raw_size']])
    uc.mem_map(ARENA,ARENA_BYTES);uc.mem_write(ARENA,b'\xcc'*ARENA_BYTES)
    uc.mem_map(0x02000000,0x10000);uc.mem_map(EXIT,0x2000)
    def put(addr,*values):uc.mem_write(addr,struct.pack('<'+'I'*len(values),*(v&0xffffffff for v in values)))
    def word(addr):return struct.unpack('<I',uc.mem_read(addr,4))[0]
    put(BASE,0);put(NEXT,0)
    allocations={};growth=0;calls=[];results=[];coverage=set();terminal=False
    funcs=[]
    for va in ('005a2382','005a2400','005a2535','005a253e'):
        row=rows.get(va)
        if row:funcs.extend((int(a,16),int(b,16)) for a,b in row['ranges'])
    funcs.append((0x5a2412,0x5a2440))
    endpoints={0x5a3be5:('malloc',1),0x5a2e22:('fatal',1),
        0x5a8161:('size',1),0x5a8029:('realloc',2),
        0x5a4ba4:('lock',1),0x5a4c05:('unlock',1)}
    def hook(machine,address,_size,_user):
        nonlocal growth,terminal
        if address==EXIT:machine.emu_stop();return
        if address in (0x5a2412,0x5a2382,0x5a2400,0x5a2535,0x5a253e):coverage.add(f'{address:08x}')
        endpoint=endpoints.get(address)
        if endpoint is None:
            if not any(lo<=address<=hi for lo,hi in funcs):raise RuntimeError(f'unexpected x86 address {address:08x}, calls={calls[-6:]}')
            return
        label,n=endpoint;sp=machine.reg_read(UC_X86_REG_ESP)
        ret,*args=struct.unpack('<'+'I'*(n+1),machine.mem_read(sp,4*(n+1)))
        coverage.add(f'{address:08x}');value=0
        if label=='malloc':
            size=args[0];calls.append(['malloc_005a3be5',size])
            if init_ok:value=ARENA+0x4000;allocations[value]=size
        elif label=='fatal':
            calls.append(['amsg_exit_005a2e22',args[0]]);terminal=True;machine.emu_stop();return
        elif label=='size':
            ptr=args[0];value=allocations.get(ptr,0);calls.append(['allocation_size_005a8161',ptr,value])
        elif label=='realloc':
            ptr,size=args;calls.append(['reallocate_005a8029',ptr,size])
            if not realloc_fail and ptr in allocations:
                value=ARENA+0x5000+growth*0x1000;growth+=1
                old_size=allocations[ptr];machine.mem_write(value,bytes(machine.mem_read(ptr,old_size)));allocations[value]=size
        elif label=='lock':calls.append(['lock_005a4ba4',args[0]])
        elif label=='unlock':calls.append(['unlock_005a4c05',args[0]])
        machine.reg_write(UC_X86_REG_EAX,value);machine.reg_write(UC_X86_REG_ESP,sp+4);machine.reg_write(UC_X86_REG_EIP,ret)
    uc.hook_add(UC_HOOK_CODE,hook)
    def run(va,args=()):
        put(STACK,EXIT,*args);uc.reg_write(UC_X86_REG_ESP,STACK)
        uc.emu_start(va,EXIT+1,count=300000)
        if uc.reg_read(UC_X86_REG_EIP)!=EXIT or uc.reg_read(UC_X86_REG_ESP)!=STACK+4:raise RuntimeError(f'ABI mismatch at {va:08x}')
        return uc.reg_read(UC_X86_REG_EAX)
    # The CRT initializer uses malloc(0x80); the failure path terminates in __amsg_exit.
    uc.reg_write(UC_X86_REG_ESP,STACK);put(STACK,EXIT);uc.emu_start(0x5a2412,EXIT+1,count=30000)
    if not terminal and (uc.reg_read(UC_X86_REG_EIP)!=EXIT or uc.reg_read(UC_X86_REG_ESP)!=STACK+4):raise RuntimeError('initializer ABI mismatch')
    if not terminal:
        for i in range(count):
            callback=0 if i+1==null_index else 0x03500000+(i+1)*0x100
            raw_result=run(0x5a2400,(callback,));results.append(raw_result if raw_result<0x80000000 else raw_result-0x100000000)
    out={'terminal':terminal,'base':word(BASE),'next':word(NEXT),'results':results,
         'arena':bytes(uc.mem_read(ARENA,ARENA_BYTES)).hex(),'calls':calls}
    return out,coverage

def main():
    parser=argparse.ArgumentParser()
    parser.add_argument("--probe",type=Path,default=ROOT/"local/builds/v2/001-original-recovery/bin/Release/exit_registry_probe.exe")
    parser.add_argument("--report-dir",type=Path,default=RUN)
    args=parser.parse_args()
    args.report_dir.mkdir(parents=True,exist_ok=True)
    module=next(x for x in map(json.loads,(ROOT/'research/binary-index/static/binaries.jsonl').read_text().splitlines()) if x['file']=='Porsche.exe')
    binary=(ROOT/'local/game'/module['path']).read_bytes();sha='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
    if hashlib.sha256(binary).hexdigest()!=sha:raise RuntimeError('original SHA mismatch')
    rows={x['entry_va'].lower():x for x in map(json.loads,(ROOT/'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/functions.jsonl').read_text().splitlines())}
    probe=args.probe
    process=subprocess.run([str(probe)],input=''.join(' '.join(map(str,c))+'\n' for c in CASES),text=True,capture_output=True,check=True,timeout=30)
    actual=[json.loads(line) for line in process.stdout.splitlines()]
    if len(actual)!=len(CASES):raise RuntimeError('native output count differs')
    coverage=set();fixtures=[]
    for i,(case,got) in enumerate(zip(CASES,actual)):
        want,hit=original(case,module,binary,rows);coverage|=hit
        if got!=want:
            arena_diff=next((j for j,(a,b) in enumerate(zip(bytes.fromhex(want['arena']),bytes.fromhex(got['arena']))) if a!=b),None)
            keys=[k for k in want if want[k]!=got.get(k)]
            raise AssertionError(f'case {i} mismatch keys={keys}; expected globals/results/calls={want["base"],want["next"],want["results"],want["calls"]}; actual={got.get("base"),got.get("next"),got.get("results"),got.get("calls")}; first_arena_difference={arena_diff}')
        fixtures.append({'input':case,'output_sha256':hashlib.sha256(json.dumps(want,sort_keys=True).encode()).hexdigest()})
    full={'005a2412','005a2382','005a2400','005a2535','005a253e'}
    if not full<=coverage:raise RuntimeError(f'original code coverage missing {sorted(full-coverage)}')
    paths=['iterations/v2/001-original-recovery/source/include/porsche/exit_registry.hpp',
      'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/exit_registry.cpp',
      'iterations/v2/001-original-recovery/source/recovered/exit_registry_probe.cpp',
      'iterations/v2/001-original-recovery/runs/052-exit-registry/CMakeLists.txt',
      'scripts/research/verify-v2-exit-registry.py']
    report={'schema':1,'module':'Porsche.exe','sha256':sha,'range':'005a2382..005a2411 plus init 005a2412..005a2440',
      'function_vas':sorted(coverage),'full_function_vas':sorted(full),
      'partial_function_vas':sorted(coverage-full),'cases':len(CASES),'native_cpp_equal_original_x86':True,
      'binary_matched':False,'game_launch_verified':False,
      'comparison':'Full 64 KiB allocation arena, base/next globals, per-registration return values, allocator and lock call order across initialization, capacity growth, failed growth, null callback, and CRT initialization failure.',
      'boundaries':{'crt_allocator':'005a3be5 initial malloc and 005a8161 allocation-size / 005a8029 realloc are typed deterministic boundaries. The fixture relocates/copies the full old allocation on successful growth and can force allocation failure.',
        'lock':'005a2535/005a253e are recovered wrappers around lock enter/leave 0xD; underlying 005a4ba4/005a4c05 synchronization is a recording boundary.',
        'fatal':'Initial allocation failure calls __amsg_exit 005a2e22 with 0x18; comparison stops at this terminal boundary.',
        'integration':'The accepted 00557380 forwarding implementation and application-pool caller are not redefined. A void linker adapter calls the recovered result-returning 005a2400 and discards its result.'},
      'source_sha256':{p:hashlib.sha256((ROOT/p).read_bytes().replace(b'\r\n',b'\n')).hexdigest() for p in paths},
      'probe_sha256':hashlib.sha256(probe.read_bytes()).hexdigest(),'fixtures':fixtures}
    report['source_sha256']=source_hashes(report['source_sha256'].keys(),compiled_sources=['iterations/v2/001-original-recovery/source/recovered/Porsche.exe/exit_registry.cpp', 'iterations/v2/001-original-recovery/source/recovered/exit_registry_probe.cpp'])
    (args.report_dir/'verification.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf8',newline='\n')
    print(json.dumps({'functions':sorted(coverage),'cases':len(CASES),'native_cpp_equal_original_x86':True,'report':str(args.report_dir/'verification.json')}))
if __name__=='__main__':main()
