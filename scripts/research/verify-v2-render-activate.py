"""Compare the recovered 0x467fc0 display-mode consumer to Porsche.exe x86."""
import argparse
import hashlib
import json
import struct
import subprocess
import sys
from pathlib import Path

from v2_source_dependencies import source_hashes

ROOT=Path(__file__).resolve().parents[2]
ITER=ROOT/'iterations/v2/001-original-recovery'
RUN=ITER/'runs/049-render-activate'
SHA='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ECX,UC_X86_REG_EIP,UC_X86_REG_ESP

STACK,OBJ,EXIT=0x3101000,0x3103000,0x3200000
VIDEO,APPLY=0x5376c0,0x468030

def put(u,a,v): u.mem_write(a,struct.pack('<I',v&0xffffffff))
def word(u,a): return struct.unpack('<I',u.mem_read(a,4))[0]

def cases():
    return [
      (640,480,2,640,480,2,2,0,0x12345678), # unchanged tuple, no side effects
      (640,480,2,800,600,2,2,0,0x12345678),
      (640,480,2,640,480,3,2,0,0x87654321),
      (640,480,2,800,600,3,0,0,0xffffffff),
      (640,480,2,0,0,2,2,0,0x10203040),
      (640,480,2,0,720,9,0x55,0,0xabcdef01),
      (640,480,2,800,600,3,2,1,0x76543210),
      (0,0,0,800,600,7,0xffffffff,1,0x11111111),
      (1920,1080,0x11,1280,720,0x12,0x100,0,0x80000000),
    ]

def original(module,data,c):
    aw,ah,am,w,h,m,transition,fullscreen,result=c
    u=Uc(UC_ARCH_X86,UC_MODE_32);u.mem_map(0x400000,0x300000)
    for sec in module['sections']:
        if sec['raw_size']:
            u.mem_write(0x400000+sec['rva'],data[sec['raw_offset']:sec['raw_offset']+sec['raw_size']])
    u.mem_map(0x3100000,0x10000);u.mem_map(EXIT,0x1000)
    u.mem_write(EXIT,b'\xc3'*0x1000)
    put(u,0x619784,aw);put(u,0x619788,ah);put(u,0x61978c,am)
    u.mem_write(OBJ,b'\0'*0x80);u.mem_write(OBJ+0x60,bytes([fullscreen&255]))
    trace={'video':0,'apply':0,'args':[0]*5,'field':0}
    def hook(mu,address,_size,_):
        if address not in (VIDEO,APPLY): return
        sp=mu.reg_read(UC_X86_REG_ESP);ret=word(mu,sp);cleanup=0;eax=0
        if address==VIDEO:
            trace['video']+=1
            trace['args'][:]=[word(mu,sp+4+i*4) for i in range(5)]
            eax=result;cleanup=4
        else:
            trace['apply']+=1
            value=word(mu,sp+4);trace['field']=value
            mu.mem_write(mu.reg_read(UC_X86_REG_ECX)+0x68,struct.pack('<I',value))
            cleanup=8
        mu.reg_write(UC_X86_REG_EAX,eax)
        mu.reg_write(UC_X86_REG_ESP,sp+cleanup)
        mu.reg_write(UC_X86_REG_EIP,ret)
    u.hook_add(UC_HOOK_CODE,hook)
    for i,v in enumerate((EXIT,w,h,m,transition)):put(u,STACK+i*4,v)
    u.reg_write(UC_X86_REG_ESP,STACK);u.reg_write(UC_X86_REG_ECX,OBJ)
    u.emu_start(0x467fc0,EXIT,count=1000)
    return (trace['video'],trace['apply'],*trace['args'],word(u,OBJ+0x68),
            u.reg_read(UC_X86_REG_ESP)-STACK)

def main():
    p=argparse.ArgumentParser();p.add_argument('--probe',type=Path,default=ROOT/'local/builds/v2/render-activate-049/bin/Release/render_activate_probe.exe');p.add_argument('--report',type=Path,default=RUN/'verification.json');a=p.parse_args()
    module=next(json.loads(x) for x in (ROOT/'research/binary-index/static/binaries.jsonl').read_text(encoding='utf8').splitlines() if json.loads(x)['file']=='Porsche.exe')
    data=(ROOT/'local/game'/module['path']).read_bytes();assert hashlib.sha256(data).hexdigest()==SHA
    inputs=cases();proc=subprocess.run([str(a.probe)],input=''.join(' '.join(map(str,x))+'\n' for x in inputs),text=True,capture_output=True,check=True)
    lines=proc.stdout.splitlines();assert len(lines)==len(inputs),(len(lines),len(inputs),proc.stderr)
    fixtures=[]
    for c,line in zip(inputs,lines):
        actual=tuple(int(x,0) for x in line.split());expected=original(module,data,c)
        assert expected[-1]==20, f'x86 RET 0x10 stack delta mismatch: {expected[-1]}'
        if actual!=expected[:-1]: raise RuntimeError(f'{c}: x86={expected[:-1]} C++={actual}')
        fixtures.append({'input':c,'output':actual,'x86_stack_delta':expected[-1]})
    deps=[
      ITER/'source/include/porsche/render_activate.hpp',
      ITER/'source/include/porsche/render_display.hpp',
      ITER/'source/include/porsche/render_objects.hpp',
      ITER/'source/include/porsche/render_startup.hpp',
      ITER/'source/recovered/Porsche.exe/render_activate.cpp',
      ITER/'source/recovered/render_activate_probe.cpp',
      RUN/'CMakeLists.txt',RUN/'README.md',Path(__file__).resolve()]
    hashes={x.relative_to(ROOT).as_posix():hashlib.sha256(x.read_bytes().replace(b'\r\n',b'\n')).hexdigest() for x in deps}
    report={'schema':1,'binary':'Porsche.exe','sha256':SHA,'entry_va':'00467fc0','coverage':'full 00467fc0..0046802f, RET 0x10; caller evidence 004b6c99..004b6cbe is recorded but not included as recovered main behavior','full_function_vas':['00467fc0'],'partial_function_vas':[],'cases':len(inputs),'native_cpp_equal_original_x86':True,'binary_matched':False,'game_launch_verified':False,'boundaries':'005376c0 video-mode call and 00468030 result consumer. The verifier models the five video-mode arguments and only the observed first 00468030 write to display+0x68; subsequent helper/window/cursor effects are outside coverage.','source_sha256':hashes,'probe_sha256':hashlib.sha256(a.probe.read_bytes()).hexdigest(),'fixtures':fixtures}
    report['source_sha256']=source_hashes(report['source_sha256'].keys(),compiled_sources=['iterations/v2/001-original-recovery/source/recovered/Porsche.exe/render_activate.cpp', 'iterations/v2/001-original-recovery/source/recovered/render_activate_probe.cpp'])
    a.report.parent.mkdir(parents=True,exist_ok=True);a.report.write_text(json.dumps(report,indent=2)+'\n',encoding='utf8')
    print(json.dumps({'cases':len(inputs),'full_function_vas':report['full_function_vas'],'native_cpp_equal_original_x86':True,'caller':'004b6cb9 passes width,height,mode,transition=2 from canonical globals'}))

if __name__=='__main__': main()
