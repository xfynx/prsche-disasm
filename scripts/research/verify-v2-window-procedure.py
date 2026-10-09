"""Original message comparator, binary search and WndProc versus native x86."""
import argparse
import hashlib
import json
from pathlib import Path
import struct
import subprocess
import sys

ROOT=Path(__file__).resolve().parents[2]
RUN=ROOT/'iterations/v2/001-original-recovery/runs/034-window-procedure'
SHA='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ESP,UC_X86_REG_EIP
STACK,EXIT,CALLBACK,DEFAULT,KEY,OTHER=0x3108000,0x3200000,0x3200100,0x3200200,0x3101000,0x3101010

def put(uc,address,value):uc.mem_write(address,struct.pack('<I',value&0xffffffff))
def word(uc,address):return struct.unpack('<I',uc.mem_read(address,4))[0]

def cases():
    result=[]
    for count in (0,1,2,3,4,8,15,16,127,128):
        for msg in sorted({0,1,4,7,max(0,count*3-2),count*3+2,0x80000000,0xffffffff}):
            for handled in (0,1,0x80000000):
                result.append((0,count,msg,handled,0xfedc0001,0x12345678))
            result.append((2,count,msg,0,0,0))
    for a in (0,1,0x7fffffff,0x80000000,0xffffffff):
        for b in (0,1,0x7fffffff,0x80000000,0xffffffff):result.append((1,0,a,0,b,0))
    return result

def original(module,data,case):
    kind,count,msg,handled,answer,fallback=case
    uc=Uc(UC_ARCH_X86,UC_MODE_32);uc.mem_map(0x400000,0x300000)
    for section in module['sections']:
        uc.mem_write(0x400000+section['rva'],data[section['raw_offset']:section['raw_offset']+section['raw_size']])
    uc.mem_map(0x3100000,0x10000);uc.mem_map(EXIT,0x1000);uc.mem_write(EXIT,b'\xc3'*0x1000)
    uc.mem_write(0x69e0e0,b'\xcc'*1024)
    for i in range(count):put(uc,0x69e0e0+i*8,i*3+1);put(uc,0x69e0e4+i*8,CALLBACK)
    before=bytes(uc.mem_read(0x69e0e0,1024));put(uc,0x69e570,count)
    put(uc,0x5b2318,DEFAULT);put(uc,KEY,msg);put(uc,OTHER,answer)
    calls=[0,0];ok=True
    def hook(machine,address,_size,_user):
        nonlocal ok
        if address not in (CALLBACK,DEFAULT):return
        sp=machine.reg_read(UC_X86_REG_ESP);ret=word(machine,sp)
        if address==CALLBACK:
            args=[word(machine,sp+4*i) for i in range(1,7)];calls[0]+=1
            ok=ok and args[:5]==[0x6b77a0,0x1234,msg,0x89abcdef,0xfedcba98] and word(machine,args[5])==0
            put(machine,args[5],answer);value=handled;argc=6
        else:
            args=[word(machine,sp+4*i) for i in range(1,5)];calls[1]+=1
            ok=ok and args==[0x1234,msg,0x89abcdef,0xfedcba98];value=fallback;argc=4
        machine.reg_write(UC_X86_REG_EAX,value);machine.reg_write(UC_X86_REG_ESP,sp+4+argc*4)
        machine.reg_write(UC_X86_REG_EIP,ret)
    uc.hook_add(UC_HOOK_CODE,hook)
    if kind==0:entry=0x53aba0;args=[0x1234,msg,0x89abcdef,0xfedcba98]
    elif kind==1:entry=0x53a7f0;args=[KEY,OTHER]
    else:entry=0x5a2f23;args=[KEY,0x69e0e0,count,8,0x53a7f0]
    for i,value in enumerate([EXIT]+args):put(uc,STACK+i*4,value)
    uc.reg_write(UC_X86_REG_ESP,STACK);uc.emu_start(entry,EXIT,count=10000)
    if uc.reg_read(UC_X86_REG_EIP)!=EXIT:raise RuntimeError('Original failed to return')
    result=uc.reg_read(UC_X86_REG_EAX)
    if kind==2 and result:result=(result-0x69e0e0)//8+1
    ok=ok and before==bytes(uc.mem_read(0x69e0e0,1024))
    return result,*calls,int(ok)

def main():
    parser=argparse.ArgumentParser()
    parser.add_argument('--probe',type=Path,default=ROOT/'local/builds/v2/window-procedure-034/bin/Release/window_procedure_probe.exe')
    parser.add_argument('--report-dir',type=Path,default=RUN)
    args=parser.parse_args()
    module=next(r for r in map(json.loads,(ROOT/'research/binary-index/static/binaries.jsonl').read_text(encoding='utf8').splitlines()) if r['file']=='Porsche.exe')
    data=(ROOT/'local/game'/module['path']).read_bytes()
    assert hashlib.sha256(data).hexdigest()==SHA
    inputs=cases();native=subprocess.run([str(args.probe)],input=''.join(' '.join(map(str,c))+'\n' for c in inputs),text=True,capture_output=True,check=True)
    outputs=[tuple(map(int,line.split())) for line in native.stdout.splitlines()]
    assert len(outputs)==len(inputs)
    fixtures=[]
    for case,actual in zip(inputs,outputs):
        expected=original(module,data,case)
        if actual!=expected:raise RuntimeError(f'{case}: expected {expected}, actual {actual}')
        fixtures.append({'input':case,'output':actual})
    deps=['source/include/porsche/window_state.hpp','source/include/porsche/window_procedure.hpp','source/recovered/Porsche.exe/window_procedure.cpp','source/recovered/window_procedure_probe.cpp']
    deps=['iterations/v2/001-original-recovery/'+p for p in deps]+['scripts/research/verify-v2-window-procedure.py']
    report={'schema':1,'sha256':SHA,'function_vas':['0053a7f0','0053aba0','005a2f23'],'cases':len(inputs),
        'native_cpp_equal_original_x86':True,'binary_matched':False,'game_launch_verified':False,
        'boundaries':'Callback bodies and DefWindowProcA are recorded; original binary search/comparator execute directly. Valid sorted 0..128-entry arrays.',
        'source_sha256':{p:hashlib.sha256((ROOT/p).read_bytes().replace(b'\r\n',b'\n')).hexdigest() for p in deps},
        'probe_sha256':hashlib.sha256(args.probe.read_bytes()).hexdigest(),'fixtures':fixtures}
    args.report_dir.mkdir(parents=True,exist_ok=True)
    (args.report_dir/'verification.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf8')
    print(json.dumps({'cases':len(inputs),'function_vas':report['function_vas'],'native_cpp_equal_original_x86':True}))

if __name__=='__main__':main()
