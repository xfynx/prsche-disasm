"""Differentially execute Porsche.exe's complete 0x468030 consumer."""
import argparse, hashlib, json, struct, subprocess, sys
from pathlib import Path

from v2_source_dependencies import source_hashes

ROOT=Path(__file__).resolve().parents[2]
ITER=ROOT/'iterations/v2/001-original-recovery'
RUN=ITER/'runs/051-render-window'
SHA='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ECX,UC_X86_REG_EIP,UC_X86_REG_ESP

STACK,OBJ,DRIVER,VTABLE,EXIT=0x3101000,0x3103000,0x3104000,0x3105000,0x3200000
QUERY,SELECT,COMMIT,TIME,VIDEO,RESIZE,SHOW=0x44e720,0x3210010,0x44ebf0,0x44ed10,0x537600,0x53bd40,0x3210060

def put(u,a,v): u.mem_write(a,struct.pack('<I',v&0xffffffff))
def word(u,a): return struct.unpack('<I',u.mem_read(a,4))[0]
def cases():
    return [
      (7,7,0,0x100,1,-1,0,0,0),              # stored result: store then return
      (3,2,1,0x100,1,-1,0,0,0),              # fullscreen; one negative ShowCursor
      (4,2,1,0x100,3,0,-1,0,0),              # fullscreen; repeat until negative
      (5,1,0,0x900,1,-1,0,0,0),              # windowed mode record + renderer vslot
      (0xffffffff,0,0,0x76543210,3,1,0,-1,0),# unsigned result, multiple cursor calls
      (0x12,0x11,1,0x80000000,2,-2,0,0,0),   # fullscreen negative return
      (0x20,0x10,0,0x12345678,4,2,1,0,-1),   # loop through nonnegative results
    ]

def original(module,data,c):
    result,current,fullscreen,seed,count,*cursor=c
    u=Uc(UC_ARCH_X86,UC_MODE_32);u.mem_map(0x400000,0x300000)
    for sec in module['sections']:
        if sec['raw_size']:u.mem_write(0x400000+sec['rva'],data[sec['raw_offset']:sec['raw_offset']+sec['raw_size']])
    u.mem_map(0x3100000,0x10000);u.mem_map(EXIT,0x1000);u.mem_map(0x3210000,0x10000)
    u.mem_write(EXIT,b'\xc3'*0x1000)
    u.mem_write(OBJ,b'\0'*0x100);u.mem_write(DRIVER,b'\0'*0x100);u.mem_write(VTABLE,b'\0'*0x100)
    u.mem_write(OBJ+0x60,bytes([fullscreen&255]));put(u,OBJ+0x70,DRIVER);put(u,DRIVER,VTABLE);put(u,VTABLE+0x1c,SELECT)
    put(u,0x619780,current);put(u,0x628130,OBJ);put(u,0x5b2278,SHOW)
    events=[];cursor_i=0
    def hook(mu,address,_size,_):
        nonlocal cursor_i
        if address not in (QUERY,SELECT,COMMIT,TIME,VIDEO,RESIZE,SHOW):return
        sp=mu.reg_read(UC_X86_REG_ESP);ret=word(mu,sp);cleanup=4;eax=0
        if address==QUERY:
            index=word(mu,sp+4);dest=word(mu,sp+8)
            events.append([2,index,int(word(mu,0x628130)!=0)])
            for i in range(10):put(mu,dest+i*4,seed+i)
            cleanup=4
        elif address==SELECT:
            events.append([3,word(mu,sp+4),int(mu.reg_read(UC_X86_REG_ECX)==DRIVER)])
            cleanup=8 # driver virtual member is thiscall and consumes its word
        elif address==COMMIT:events.append([4,word(mu,sp+4)])
        elif address==TIME:events.append([5])
        elif address==VIDEO:events.append([6,*[word(mu,sp+4+i*4) for i in range(6)]])
        elif address==RESIZE:events.append([1,*[word(mu,sp+4+i*4) for i in range(4)]])
        else:
            show=struct.unpack('<i',struct.pack('<I',word(mu,sp+4)))[0]
            value=cursor[cursor_i] if cursor_i<len(cursor) else -1;cursor_i+=1
            events.append([7,show,value]);eax=value&0xffffffff;cleanup=8
        mu.reg_write(UC_X86_REG_EAX,eax);mu.reg_write(UC_X86_REG_ESP,sp+cleanup);mu.reg_write(UC_X86_REG_EIP,ret)
    u.hook_add(UC_HOOK_CODE,hook)
    put(u,STACK,EXIT);put(u,STACK+4,result);u.reg_write(UC_X86_REG_ESP,STACK);u.reg_write(UC_X86_REG_ECX,OBJ)
    try:u.emu_start(0x468030,EXIT,count=5000)
    except Exception as exc:
        raise RuntimeError(f'original x86 failed for case {c}, EIP=0x{u.reg_read(UC_X86_REG_EIP):08x}, ESP=0x{u.reg_read(UC_X86_REG_ESP):08x}, events={events}') from exc
    return {'field':word(u,OBJ+0x68),'events':events,'stack_delta':u.reg_read(UC_X86_REG_ESP)-STACK}

def main():
    p=argparse.ArgumentParser();p.add_argument('--probe',type=Path,default=ROOT/'local/builds/v2/render-window-051/bin/Release/render_window_probe.exe');p.add_argument('--report',type=Path,default=RUN/'verification.json');a=p.parse_args()
    module=next(json.loads(x) for x in (ROOT/'research/binary-index/static/binaries.jsonl').read_text(encoding='utf8').splitlines() if json.loads(x)['file']=='Porsche.exe')
    data=(ROOT/'local/game'/module['path']).read_bytes();assert hashlib.sha256(data).hexdigest()==SHA
    inputs=cases()
    proc=subprocess.run([str(a.probe)],input=''.join(' '.join(map(str,x))+'\n' for x in inputs),text=True,capture_output=True,check=True)
    lines=proc.stdout.splitlines();assert len(lines)==len(inputs),(len(lines),len(inputs),proc.stderr)
    fixtures=[]
    for c,line in zip(inputs,lines):
        native=json.loads(line);expected=original(module,data,c)
        assert expected['stack_delta']==8, f'x86 RET 4 stack delta mismatch: {expected["stack_delta"]}'
        if native!={'field':expected['field'],'events':expected['events']}:raise RuntimeError(f'{c}: x86={expected} C++={native}')
        fixtures.append({'input':c,'output':native})
    rel=lambda path:path.relative_to(ROOT).as_posix()
    deps=[ITER/'source/include/porsche/render_window.hpp',ITER/'source/include/porsche/render_activate.hpp',ITER/'source/include/porsche/render_display.hpp',ITER/'source/include/porsche/render_startup.hpp',ITER/'source/include/porsche/window_position.hpp',ITER/'source/include/porsche/window_worker.hpp',ITER/'source/recovered/Porsche.exe/render_window.cpp',ITER/'source/recovered/render_window_probe.cpp',ITER/'source/recovered/Porsche.exe/render_activate.cpp',RUN/'CMakeLists.txt',RUN/'README.md',Path(__file__).resolve()]
    report={'schema':1,'binary':'Porsche.exe','sha256':SHA,'entry_va':'00468030','coverage':'full 00468030..004680c5, RET 4','full_function_vas':['00468030'],'partial_function_vas':[],'cases':len(inputs),'native_cpp_equal_original_x86':True,'binary_matched':False,'game_launch_verified':False,'boundaries':'0044e720 mode-info provider, driver vtable+0x1c, 0044ebf0/0044ed10, 00537600, and USER32 ShowCursor are typed call contracts. 0053bd40 is dispatched through the shared window_position_resize_0053bd40 API and is hooked only for this isolated consumer proof; its implementation is owned by Run048. Run049 owns canonical mode-index 00619780 and actual-mode globals 00619784/88/8c; startup owns display pointer 00628130.','source_sha256':{rel(x):hashlib.sha256(x.read_bytes().replace(b'\r\n',b'\n')).hexdigest() for x in deps},'probe_sha256':hashlib.sha256(a.probe.read_bytes()).hexdigest(),'fixtures':fixtures}
    report['source_sha256']=source_hashes(report['source_sha256'].keys(),compiled_sources=['iterations/v2/001-original-recovery/source/recovered/Porsche.exe/render_window.cpp', 'iterations/v2/001-original-recovery/source/recovered/render_window_probe.cpp'])
    a.report.parent.mkdir(parents=True,exist_ok=True);a.report.write_text(json.dumps(report,indent=2)+'\n',encoding='utf8')
    print(json.dumps({'cases':len(inputs),'full_function_vas':report['full_function_vas'],'native_cpp_equal_original_x86':True,'window_resize':'shared 0053bd40 adapter called only on fullscreen branch'}))

if __name__=='__main__':main()
