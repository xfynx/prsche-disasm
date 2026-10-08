"""Compare original operation wait control flow and native C++ with recording services."""
import hashlib
import json
from pathlib import Path
import struct
import subprocess
import sys
ROOT=Path(__file__).resolve().parents[2]
RUN=ROOT/'iterations/v2/001-original-recovery/runs/008-file-scheduler'
sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ESP,UC_X86_REG_EIP
BASE,STACK,EXIT=0x3500000,0x200f000,0x2200000
FUNCTIONS=[0x567f70,0x580ea0,0x580ec0]
ENDPOINTS={0x5322b0:1,0x5322c0:1,0x567b80:3,0x567af0:1,0x55f780:1,0x5366e0:1,0x55f740:1,0x55fc60:1,0x55fc40:1}
def cases():
    result=[]
    for slot in [0,1,17,31]:
        for initialized in [0,1]:
            for thread in [0,1,0xffffffff]:
                for steps in [0,1,3]:
                    result.append([0x12340020+slot,initialized,steps,1,1,thread,0xfffffffe,0,0x2001000])
    result.extend([[0,1,0,1,1,0,7,0,0]])
    for pending in [0,1,2,3,0xffffffff]:
        for found in [0,1]:result.append([0x81234571,1,2,pending,found,0,0xfffffffd,0,0])
    for mutation in [1,2]:
        for thread in [0,1]:result.append([0x1234003f,1,2,1,1,thread,0x7fffffff,mutation,0x2001000])
    return ['|'.join(map(str,r)) for r in result]
def original(wire,module,data,functions):
    ident,initialized,steps,pending,found,thread,status,mutation,lock=map(int,wire.split('|'))
    uc=Uc(UC_ARCH_X86,UC_MODE_32);uc.mem_map(0x400000,0x300000)
    for s in module['sections']:uc.mem_write(0x400000+s['rva'],data[s['raw_offset']:s['raw_offset']+s['raw_size']])
    uc.mem_map(BASE,0x10000);uc.mem_write(BASE,b'\xcc'*0x10000);uc.mem_map(0x2000000,0x10000);uc.mem_map(EXIT,0x1000)
    def put(p,*v):uc.mem_write(p,struct.pack('<'+'I'*len(v),*[x&0xffffffff for x in v]))
    def words(p,n):return struct.unpack('<'+'I'*n,uc.mem_read(p,n*4))
    put(0x6a5c7c,BASE)
    for i in range(32):put(BASE+i*112,initialized);put(BASE+i*112+0x3c,lock);put(BASE+i*112+0x64,0x4003000+i*16);put(BASE+0x1000+i*112+0x64,0x4004000+i*16)
    ranges=[(int(a,16),int(b,16)) for v in FUNCTIONS for a,b in functions[f'{v:08x}']['ranges']]
    iteration=0;calls=[];coverage=set()
    def hook(machine,p,size,user):
        nonlocal iteration
        if p==EXIT:machine.emu_stop();return
        if p in FUNCTIONS:coverage.add(f'{p:08x}')
        argc=ENDPOINTS.get(p)
        if argc is None:
            if not any(a<=p<=b for a,b in ranges):raise RuntimeError(f'Unexpected code {p:08x}')
            return
        sp=uc.reg_read(UC_X86_REG_ESP);ret,*args=words(sp,argc+1);value=0
        if p in [0x5322b0,0x5322c0]:calls.append(['enter' if p==0x5322b0 else 'leave',*args])
        elif p==0x567b80:
            calls.append(['find',*args[:2]]);put(args[2],pending if iteration<steps else 0);iteration+=1;value=BASE+0x3000 if found else 0
            if mutation==1:put(args[0],0)
        elif p==0x567af0:calls.append(['status',*args]);value=status
        elif p==0x55f780:
            calls.append(['thread',*args]);value=thread
            if mutation==2:put(0x6a5c7c,BASE+0x1000)
        elif p==0x5366e0:calls.append(['pump',*args]);value=0xfedcba98
        elif p==0x55f740:calls.append(['sleep',*args])
        elif p==0x55fc60:calls.append(['wait_event',*args])
        elif p==0x55fc40:calls.append(['reset_event',*args])
        uc.reg_write(UC_X86_REG_EAX,value);uc.reg_write(UC_X86_REG_ESP,sp+4);uc.reg_write(UC_X86_REG_EIP,ret)
    uc.hook_add(UC_HOOK_CODE,hook);put(STACK,EXIT,ident);uc.reg_write(UC_X86_REG_ESP,STACK);uc.emu_start(0x567f70,EXIT+1,count=1000000)
    assert uc.reg_read(UC_X86_REG_EIP)==EXIT and uc.reg_read(UC_X86_REG_ESP)==STACK+4,'ABI/budget failure'
    value=uc.reg_read(UC_X86_REG_EAX)
    return {'result':value if value<0x80000000 else value-0x100000000,'devices':words(0x6a5c7c,1)[0],'arena':bytes(uc.mem_read(BASE,0x3000)).hex(),'calls':calls},coverage
def main():
    module=next(r for r in map(json.loads,(ROOT/'research/binary-index/static/binaries.jsonl').read_text().splitlines()) if r['file']=='Porsche.exe')
    data=(ROOT/'local/game'/module['path']).read_bytes();assert hashlib.sha256(data).hexdigest()==module['sha256']
    functions={r['entry_va']:r for r in map(json.loads,(ROOT/'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/functions.jsonl').read_text().splitlines())}
    inputs=cases();probe=ROOT/'local/builds/v2/001-original-recovery/bin/Release/wait_probe.exe'
    native=subprocess.run([str(probe)],input='\n'.join(inputs)+'\n',text=True,capture_output=True,check=True,timeout=30)
    outputs=list(map(json.loads,native.stdout.splitlines()));assert len(outputs)==len(inputs)
    fixtures=[];coverage=set()
    for i,(wire,actual) in enumerate(zip(inputs,outputs)):
        expected,hit=original(wire,module,data,functions);coverage|=hit
        if expected!=actual:
            p=ROOT/'local/reports/v2-wait-mismatch.json';p.write_text(json.dumps({'case':i,'input':wire,'expected':expected,'actual':actual},indent=2)+'\n');raise RuntimeError(f'Mismatch {i}: {p}')
        fixtures.append({'input':wire,'output_sha256':hashlib.sha256(json.dumps(expected,sort_keys=True).encode()).hexdigest()})
    paths=['source/recovered/Porsche.exe/file_wait.cpp','source/recovered/Porsche.exe/io_lists.cpp','source/recovered/wait_probe.cpp','source/include/porsche/file_wait.hpp','source/include/porsche/file_worker.hpp','source/include/porsche/file_device.hpp','source/include/porsche/files.hpp','source/include/porsche/heap.hpp']
    paths=['iterations/v2/001-original-recovery/'+p for p in paths]
    report={'schema':1,'sha256':module['sha256'],'function_vas':sorted(coverage),'cases':len(inputs),'native_cpp_equal_original_x86':True,'binary_matched':False,'game_launch_verified':False,'comparison':'Device arenas, retained/reloaded device identities, results and ordered find/status/thread/pump/sleep/event/lock calls. Pending/find/status are controlled fixtures; real consumers are exercised in joint files-regression.','source_sha256':{p:hashlib.sha256((ROOT/p).read_bytes().replace(b'\r\n',b'\n')).hexdigest() for p in paths},'probe_sha256':hashlib.sha256(probe.read_bytes()).hexdigest(),'fixtures':fixtures}
    RUN.mkdir(parents=True,exist_ok=True);(RUN/'verification.json').write_text(json.dumps(report,indent=2)+'\n',newline='\n');(RUN/'source-functions.jsonl').write_text(''.join(json.dumps({'sha256':module['sha256'],**functions[v]})+'\n' for v in sorted(coverage)),newline='\n')
    print(json.dumps({'cases':len(inputs),'functions':sorted(coverage),'native_equal_original':True}))
if __name__=='__main__':main()
