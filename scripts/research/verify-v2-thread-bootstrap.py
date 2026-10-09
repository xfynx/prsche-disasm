from v2_source_dependencies import source_hashes
"""Compare original x86 and native C++ thread/lock/page bootstrap jointly."""
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

POOL,TABLE,POOL2=0x3600000,0x3700000,0x3800000
STACK,EXIT=0x200f000,0x2200000
FUNCTIONS=[0x55f320,0x55f3b0,0x5321f0,0x532250,0x56e5f0]
IAT={0x5b21b0:(0x2200100,'system_info',1),0x5b2144:(0x2200200,'virtual_alloc',4),
     0x5b207c:(0x2200300,'initialize',1),0x5b2074:(0x2200400,'thread_id',0),
     0x5b2094:(0x2200500,'process',0),0x5b2170:(0x2200600,'thread',0),
     0x5b20a0:(0x2200700,'duplicate',7)}
ENDPOINTS={target:(name,n,True) for target,name,n in IAT.values()}
ENDPOINTS.update({0x53c290:('fill',3,False),0x557380:('exit_register',1,False)})
GLOBAL_ADDRS=[0x6a57d0,0x6a57d4,0x6a57d8,0x6a57dc,0x6a57e0,0x6a57e4,
              0x6a57e8,0x6a57ec,0x5df6a0,0x69cb04,0x5de000,0x6a6418]

def cases():
    result=[]
    for count in (0,1,100):
        for initialized,fail,prepool,pretable,registered,repeats in (
            (0,0,0,0,0,1),(0,0,0,0,0,2),(0,0,1,0,0,1),
            (0,0,0,1,0,1),(0,0,0,0,1,1),(1,0,0,0,0,1),
            (0,1,0,0,0,1),(0,2,0,0,0,1),(0,3,0,0,0,1)):
            result.append((count,initialized,fail,prepool,pretable,registered,repeats))
    return result

def original(case,module,data,functions):
    count,initialized,fail_mask,prepool,pretable,registered,repeats=case
    uc=Uc(UC_ARCH_X86,UC_MODE_32);base=int(module['image_base'],16)
    uc.mem_map(base,0x300000)
    for s in module['sections']:uc.mem_write(base+s['rva'],data[s['raw_offset']:s['raw_offset']+s['raw_size']])
    for addr in (POOL,TABLE,POOL2):uc.mem_map(addr,0x10000);uc.mem_write(addr,b'\xcc'*0x10000)
    uc.mem_map(0x2000000,0x10000);uc.mem_map(EXIT,0x1000)
    def word(p):return struct.unpack('<I',uc.mem_read(p,4))[0]
    def put(p,v):uc.mem_write(p,struct.pack('<I',v&0xffffffff))
    for address,(target,_,_) in IAT.items():put(address,target)
    initial=[0,0,0,initialized,registered,TABLE if pretable else 0,0,0,1,POOL+0x200 if prepool else 0,32,0]
    for address,value in zip(GLOBAL_ADDRS,initial):put(address,value)
    if prepool:put(POOL+0x218,0);put(POOL+0x21c,0x46524545)
    calls=[];states=[];hits=set();allocation_number=0
    ranges=[(int(x,16),int(y,16)) for va in FUNCTIONS for x,y in functions[f'{va:08x}']['ranges']]
    def hook(machine,p,size,user):
        nonlocal allocation_number
        if p==EXIT:machine.emu_stop();return
        if p in FUNCTIONS:hits.add(f'{p:08x}')
        endpoint=ENDPOINTS.get(p)
        if endpoint is None:
            if not any(start<=p<=end for start,end in ranges):raise RuntimeError(f'Unexpected original code {p:08x}')
            return
        name,n,stdcall=endpoint;sp=machine.reg_read(UC_X86_REG_ESP)
        values=struct.unpack('<'+'I'*(n+1),machine.mem_read(sp,4*(n+1)))
        ret,args=values[0],values[1:];value=0
        states.append([word(address) for address in GLOBAL_ADDRS])
        if name=='system_info':
            calls.append([name]);machine.mem_write(args[0],b'\0'*36);put(args[0]+4,4096)
        elif name=='virtual_alloc':
            index=allocation_number;allocation_number+=1
            value=0 if fail_mask&(1<<index) else ((TABLE if index==0 else POOL2) if prepool else (POOL if index==0 else TABLE if index==1 else POOL2))
            calls.append([name,*args,value])
            if value and args[1]<=0x10000:machine.mem_write(value,b'\0'*args[1])
        elif name=='initialize':calls.append([name,args[0]])
        elif name=='thread_id':calls.append([name]);value=0x1234
        elif name=='process':calls.append([name]);value=0x4001000
        elif name=='thread':calls.append([name]);value=0x4002000
        elif name=='duplicate':
            calls.append([name,*args]);put(args[3],0x4003000);value=1
        elif name=='fill':calls.append([name,*args]);machine.mem_write(args[0],bytes([args[1]&255])*args[2])
        elif name=='exit_register':calls.append([name,args[0]])
        machine.reg_write(UC_X86_REG_EAX,value)
        machine.reg_write(UC_X86_REG_ESP,sp+4*(n+1) if stdcall else sp+4)
        machine.reg_write(UC_X86_REG_EIP,ret)
    uc.hook_add(UC_HOOK_CODE,hook)
    for _ in range(repeats):
        put(STACK,EXIT);put(STACK+4,count);uc.reg_write(UC_X86_REG_ESP,STACK)
        uc.emu_start(0x55f320,EXIT+1,count=300000)
        if uc.reg_read(UC_X86_REG_EIP)!=EXIT or uc.reg_read(UC_X86_REG_ESP)!=STACK+4:raise RuntimeError('original ABI/return failure')
    return {'globals':[word(p) for p in GLOBAL_ADDRS],
            'arena':''.join(bytes(uc.mem_read(p,0x1100)).hex() for p in (POOL,TABLE,POOL2)),
            'calls':calls,'states':states},hits

def dependencies():
    root=ROOT/'iterations/v2/001-original-recovery/source'
    queue=[root/'recovered/bootstrap_probe.cpp']+[root/'recovered/Porsche.exe'/name for name in
        ('file_threads.cpp','file_pages.cpp','heap_locks.cpp')]
    seen=set()
    while queue:
        path=queue.pop()
        if path in seen:continue
        seen.add(path)
        for inc in re.findall(rb'^\s*#include\s+"([^"]+)"',path.read_bytes(),re.M):
            child=root/'include'/inc.decode('ascii')
            if child.exists():queue.append(child)
    return sorted(str(p.relative_to(ROOT)).replace('\\','/') for p in seen)

def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--probe',type=Path,default=ROOT/'local/builds/v2/001-original-recovery/bin/Release/bootstrap_probe.exe')
    parser.add_argument('--report-dir',type=Path,default=ROOT/'iterations/v2/001-original-recovery/runs/020-thread-bootstrap')
    args=parser.parse_args()
    module=next(x for x in map(json.loads,(ROOT/'research/binary-index/static/binaries.jsonl').read_text().splitlines()) if x['file']=='Porsche.exe')
    data=(ROOT/'local/game'/module['path']).read_bytes()
    if hashlib.sha256(data).hexdigest()!='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39':raise RuntimeError('original SHA mismatch')
    functions={r['entry_va']:r for r in map(json.loads,(ROOT/'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/functions.jsonl').read_text().splitlines())}
    inputs=cases()
    process=subprocess.run([str(args.probe)],input=''.join(' '.join(map(str,c))+'\n' for c in inputs),text=True,capture_output=True,check=True,timeout=60)
    native=list(map(json.loads,process.stdout.splitlines()))
    if len(native)!=len(inputs):raise RuntimeError('native output count mismatch')
    hits=set();fixtures=[]
    for index,(case,actual) in enumerate(zip(inputs,native)):
        expected,seen=original(case,module,data,functions);hits|=seen
        if actual!=expected:
            path=ROOT/'local/reports/v2-bootstrap-mismatch.json';path.parent.mkdir(parents=True,exist_ok=True)
            path.write_text(json.dumps({'case':case,'expected':expected,'actual':actual},indent=2)+'\n')
            raise RuntimeError(f'case {index} differs: {[k for k in expected if expected[k]!=actual.get(k)]}; {path}')
        fixtures.append({'input':case,'output_sha256':hashlib.sha256(json.dumps(expected,sort_keys=True).encode()).hexdigest()})
    if hits!={f'{va:08x}' for va in FUNCTIONS}:raise RuntimeError('original coverage incomplete')
    paths=dependencies()
    report={'schema':1,'module':'Porsche.exe','sha256':module['sha256'],'function_vas':sorted(hits),
            'cases':len(inputs),'native_cpp_equal_original_x86':True,'binary_matched':False,
            'comparison':'Intermediate and final BSS globals, three full pool/table arenas, ordered typed OS/fill/exit calls after linked C++ execution of the real recovered graph.',
            'boundaries':'Win32 APIs, fill, and exit registration are deterministic recording endpoints; OS scheduling and contention are not verified.',
            'source_sha256':{p:hashlib.sha256((ROOT/p).read_bytes().replace(b'\r\n',b'\n')).hexdigest() for p in paths},
            'probe_sha256':hashlib.sha256(args.probe.read_bytes()).hexdigest(),'fixtures':fixtures}
    args.report_dir.mkdir(parents=True,exist_ok=True)
    report['source_sha256']=source_hashes([*report['source_sha256'],Path(__file__)])
    (args.report_dir/'verification.json').write_text(json.dumps(report,indent=2)+'\n',newline='\n')
    print(json.dumps({'cases':len(inputs),'function_vas':sorted(hits),'native_cpp_equal_original_x86':True}))

if __name__=='__main__':main()
