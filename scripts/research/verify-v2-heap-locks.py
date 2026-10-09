from v2_source_dependencies import source_hashes
"""Compare bounded lock pool/Win32 consumers with Porsche.exe x86."""
import argparse
import hashlib
import json
from pathlib import Path
import re
import struct
import subprocess
import sys

ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ESP,UC_X86_REG_EIP

FUNCTIONS=[0x5321f0,0x532250,0x5322b0,0x5322c0,0x5322d0]
ARENA,STACK,EXIT=0x3600000,0x200f000,0x2200000
ENDPOINTS={0x55f320:('thread_init',1,False),0x56e5f0:('allocate',1,False),
           0x53c290:('fill',3,False),0x2200100:('initialize',1,True),
           0x2200200:('enter',1,True),0x2200300:('leave',1,True),
           0x2200400:('delete',1,True)}
IAT={0x5b207c:0x2200100,0x5b2078:0x2200200,0x5b206c:0x2200300,0x5b2068:0x2200400}

def cases():
    return [(mode,initialized,failed,count)
            for mode in range(8)
            for initialized in ((0,1) if mode in (0,1,7) else (1,))
            for failed in ((0,1) if mode in (0,5,6) else (0,))
            for count in ((0,1,32) if mode in (0,5,6) else (32,))]

def original(case,module,data,functions):
    mode,initialized,failed,count=case
    uc=Uc(UC_ARCH_X86,UC_MODE_32);base=int(module['image_base'],16)
    uc.mem_map(base,0x300000)
    for section in module['sections']:
        uc.mem_write(base+section['rva'],data[section['raw_offset']:section['raw_offset']+section['raw_size']])
    uc.mem_map(ARENA,0x10000);uc.mem_write(ARENA,b'\xcc'*0x10000)
    uc.mem_map(0x2000000,0x10000);uc.mem_map(EXIT,0x1000)
    def word(p):return struct.unpack('<I',uc.mem_read(p,4))[0]
    def put(p,v):uc.mem_write(p,struct.pack('<I',v&0xffffffff))
    for address,target in IAT.items():put(address,target)
    put(0x6a57dc,initialized);put(0x69cb04,ARENA+0x200 if mode in (1,3,6,7) else 0)
    put(0x5de000,count)
    if mode in (1,3,6,7):put(ARENA+0x218,ARENA+0x300 if mode==7 else 0);put(ARENA+0x21c,0x46524545)
    calls=[];coverage=set();ranges=[(int(x,16),int(y,16)) for va in FUNCTIONS for x,y in functions[f'{va:08x}']['ranges']]
    def hook(machine,p,size,user):
        if p==EXIT:machine.emu_stop();return
        if p in FUNCTIONS:coverage.add(f'{p:08x}')
        endpoint=ENDPOINTS.get(p)
        if endpoint is None:
            if not any(start<=p<=end for start,end in ranges):raise RuntimeError(f'unexpected x86 target {p:08x}')
            return
        name,n,stdcall=endpoint;sp=machine.reg_read(UC_X86_REG_ESP)
        values=struct.unpack('<'+'I'*(n+1),machine.mem_read(sp,4*(n+1)))
        ret,args=values[0],values[1:];value=0
        if name=='thread_init':calls.append([name,args[0]]);put(0x6a57dc,1)
        elif name=='allocate':
            requested=word(args[0]);rounded=(requested+4095)&~4095;put(args[0],rounded)
            value=0 if failed else ARENA+0x100;calls.append([name,requested,rounded,value])
        elif name=='fill':calls.append([name,*args]);machine.mem_write(args[0],bytes([args[1]&255])*args[2])
        else:calls.append([name,args[0]])
        machine.reg_write(UC_X86_REG_EAX,value)
        machine.reg_write(UC_X86_REG_ESP,sp+4*(n+1) if stdcall else sp+4)
        machine.reg_write(UC_X86_REG_EIP,ret)
    uc.hook_add(UC_HOOK_CODE,hook)
    va={0:0x5321f0,1:0x5321f0,2:0x5322b0,3:0x5322d0,4:0x5322d0,5:0x532250,6:0x532250,7:0x5321f0}[mode]
    put(STACK,EXIT);put(STACK+4,0 if mode==4 else ARENA+0x200)
    machine=uc
    machine.reg_write(UC_X86_REG_ESP,STACK)
    machine.emu_start(va,EXIT+1,count=100000)
    if mode==2:
        machine.reg_write(UC_X86_REG_ESP,STACK);put(STACK,EXIT)
        machine.emu_start(0x5322c0,EXIT+1,count=100000)
    if machine.reg_read(UC_X86_REG_EIP)!=EXIT:raise RuntimeError(f'ABI/return failure {va:08x}')
    result=machine.reg_read(UC_X86_REG_EAX) if mode in (0,1,7) else 0
    return {'return':result,'head':word(0x69cb04),'count':word(0x5de000),
            'initialized':word(0x6a57dc),'arena':bytes(machine.mem_read(ARENA,0x1100)).hex(),'calls':calls},coverage

def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--probe',type=Path,default=ROOT/'local/builds/v2/001-original-recovery/bin/Release/lock_probe.exe')
    parser.add_argument('--report-dir',type=Path,default=ROOT/'iterations/v2/001-original-recovery/runs/014-heap-locks')
    args=parser.parse_args()
    module=next(x for x in map(json.loads,(ROOT/'research/binary-index/static/binaries.jsonl').read_text().splitlines()) if x['file']=='Porsche.exe')
    data=(ROOT/'local/game'/module['path']).read_bytes()
    if hashlib.sha256(data).hexdigest()!='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39':raise RuntimeError('original SHA mismatch')
    functions={r['entry_va']:r for r in map(json.loads,(ROOT/'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/functions.jsonl').read_text().splitlines())}
    inputs=cases();native=subprocess.run([str(args.probe)],input=''.join(' '.join(map(str,c))+'\n' for c in inputs),text=True,capture_output=True,check=True,timeout=60)
    actual=list(map(json.loads,native.stdout.splitlines()))
    if len(actual)!=len(inputs):raise RuntimeError('native output count mismatch')
    hits=set();fixture=[]
    for i,(case,row) in enumerate(zip(inputs,actual)):
        expected,covered=original(case,module,data,functions);hits|=covered
        if expected!=row:
            p=ROOT/'local/reports/v2-locks-mismatch.json';p.parent.mkdir(parents=True,exist_ok=True)
            p.write_text(json.dumps({'case':case,'expected':expected,'actual':row},indent=2)+'\n')
            raise RuntimeError(f'case {i} differs: {[k for k in expected if expected[k]!=row.get(k)]}; {p}')
        fixture.append({'input':case,'output_sha256':hashlib.sha256(json.dumps(expected,sort_keys=True).encode()).hexdigest()})
    if hits!={f'{v:08x}' for v in FUNCTIONS}:raise RuntimeError('function coverage incomplete')
    source_root=ROOT/'iterations/v2/001-original-recovery/source'
    queue=[source_root/'recovered/Porsche.exe/heap_locks.cpp',source_root/'recovered/lock_probe.cpp']
    deps=set()
    while queue:
        path=queue.pop()
        if path in deps:continue
        deps.add(path)
        for include in re.findall(rb'^\s*#include\s+"([^"]+)"',path.read_bytes(),re.M):
            child=source_root/'include'/include.decode('ascii')
            if child.exists():queue.append(child)
    paths=sorted(str(path.relative_to(ROOT)).replace('\\','/') for path in deps)
    report={'schema':1,'sha256':module['sha256'],'module':'Porsche.exe','function_vas':sorted(hits),
            'cases':len(inputs),'native_cpp_equal_original_x86':True,'binary_matched':False,
            'comparison':'Pool arena and globals, return, ordered allocation/fill/thread/Win32 calls.',
            'boundaries':'Allocation, thread initialization and Win32 critical section calls are typed recording endpoints.',
            'source_sha256':{p:hashlib.sha256((ROOT/p).read_bytes().replace(b'\r\n',b'\n')).hexdigest() for p in paths},
            'probe_sha256':hashlib.sha256(args.probe.read_bytes()).hexdigest(),'fixtures':fixture}
    args.report_dir.mkdir(parents=True,exist_ok=True)
    report['source_sha256']=source_hashes([*report['source_sha256'],Path(__file__)])
    (args.report_dir/'verification.json').write_text(json.dumps(report,indent=2)+'\n',newline='\n')
    print(json.dumps({'cases':len(inputs),'functions':sorted(hits),'native_cpp_equal_original_x86':True}))

if __name__=='__main__':main()
