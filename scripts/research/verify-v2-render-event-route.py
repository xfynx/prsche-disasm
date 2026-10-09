"""Differentially execute the cursor/event route at 0x5728b0 and 0x53a970."""
import argparse,hashlib,json,struct,subprocess,sys
from pathlib import Path

from v2_source_dependencies import source_hashes

ROOT=Path(__file__).resolve().parents[2]
ITER=ROOT/'iterations/v2/001-original-recovery'
RUN=ITER/'runs/060-render-event-route'
SHA='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_EIP,UC_X86_REG_ESP

STACK,EXIT=0x3101000,0x3200000
ENTER_IAT,LEAVE_IAT,CTS_IAT,SETPOS_IAT,SETCURSOR_IAT=0x5b2078,0x5b206c,0x5b231c,0x5b2320,0x5b2324
ENTER_FN,LEAVE_FN,CTS_FN,SETPOS_FN,SETCURSOR_FN,CALLBACK_FN=0x3300000,0x3300010,0x3300020,0x3300030,0x3300040,0x3300050
HWND=0x87654321

def put(u,a,v):u.mem_write(a,struct.pack('<I',v&0xffffffff))
def get(u,a):return struct.unpack('<I',u.mem_read(a,4))[0]
def cases():
    common=[-10,-20,100,200]
    return [
      (0,0,0x1234,0,40,50,3,1,common,[40,50],1,300,-100,[0]*6),
      (0,1,0,0,40,50,3,1,common,[40,50],1,300,-100,[0]*6),
      (0,1,0x1234,0,40,50,3,0,common,[40,50],1,300,-100,[0]*6),
      (0,1,0x1234,0,40,50,3,0,common,[1,2],1,300,-100,[0]*6),
      (0,1,0x1234,CALLBACK_FN, -100,250,5,1,common,[40,50],1,-3,17,[0]*6),
      (0,1,0x1234,CALLBACK_FN,50,80,6,1,common,[50,80],0,-3,17,[0]*6),
      (0,1,0x1234,0x005367b0,100,200,9,1,common,[50,80],1,5,6,[0]*6),
      # The 537600 route installs new bounds and redispatches the old cursor
      # coordinates and old flag with down=0, as seen at 0057272c.
      (1,1,0x1234,0x005367b0,0,0,0,0,common,[1,250],1,2,3,[10,20,0x44,100,200,0x66]),
      (1,1,0x1234,CALLBACK_FN,0,0,0,0,[100,100,200,200],[120,180],0,0,0,[100,100,0x80000001,200,250,0]),
    ]

def original(module,data,c):
    route,gate,lock,callback,x,y,flags,down,bounds,last,client,dx,dy,driver=c
    u=Uc(UC_ARCH_X86,UC_MODE_32);u.mem_map(0x400000,0x300000)
    for sec in module['sections']:
        if sec['raw_size']:u.mem_write(0x400000+sec['rva'],data[sec['raw_offset']:sec['raw_offset']+sec['raw_size']])
    u.mem_map(0x3100000,0x10000);u.mem_map(EXIT,0x1000);u.mem_map(0x3300000,0x1000)
    u.mem_write(EXIT,b'\xc3'*0x1000)
    for slot,target in ((ENTER_IAT,ENTER_FN),(LEAVE_IAT,LEAVE_FN),(CTS_IAT,CTS_FN),(SETPOS_IAT,SETPOS_FN),(SETCURSOR_IAT,SETCURSOR_FN)):
        put(u,slot,target)
    put(u,0x5deaac,gate);put(u,0x69e59c,lock);put(u,0x5debec,callback)
    put(u,0x6b77a0+0x458,HWND)
    put(u,0x6a643c,bounds[0]);put(u,0x6a6438,bounds[1]);put(u,0x6a6430,bounds[2]);put(u,0x6a6434,bounds[3])
    put(u,0x6a6448,last[0]);put(u,0x6a6444,last[1]);put(u,0x6a6440,0xdeadbeef)
    events=[]
    def hook(mu,address,_size,_):
        if address not in (ENTER_FN,LEAVE_FN,CTS_FN,SETPOS_FN,SETCURSOR_FN,CALLBACK_FN):return
        sp=mu.reg_read(UC_X86_REG_ESP);ret=get(mu,sp)
        if address in (ENTER_FN,LEAVE_FN):
            events.append([1 if address==ENTER_FN else 5,get(mu,sp+4),0,0,0]);n=1;cleanup=True;eax=0
        elif address==CTS_FN:
            hwnd,p=get(mu,sp+4),get(mu,sp+8);px,py=get(mu,p),get(mu,p+4)
            if client:
                put(mu,p,px+dx);put(mu,p+4,py+dy)
            events.append([2,hwnd,px,py,client]);n=2;cleanup=True;eax=client
        elif address==SETPOS_FN:
            events.append([3,get(mu,sp+4),get(mu,sp+8),0,0]);n=2;cleanup=True;eax=1
        elif address==SETCURSOR_FN:
            events.append([4,get(mu,sp+4),0,0,0]);n=1;cleanup=True;eax=0
        else:
            events.append([6,callback,get(mu,sp+4),0,0]);n=1;cleanup=False;eax=0
        mu.reg_write(UC_X86_REG_EAX,eax);mu.reg_write(UC_X86_REG_ESP,sp+4+(n*4 if cleanup else 0));mu.reg_write(UC_X86_REG_EIP,ret)
    u.hook_add(UC_HOOK_CODE,hook)
    put(u,STACK,EXIT)
    if route:
        args=driver;entry=0x537600
    else:
        args=[x,y,flags,down];entry=0x5728b0
    for i,v in enumerate(args):put(u,STACK+4+i*4,v)
    u.reg_write(UC_X86_REG_ESP,STACK)
    try:u.emu_start(entry,EXIT,count=10000)
    except Exception as exc:raise RuntimeError(f'x86 {c}: EIP={u.reg_read(UC_X86_REG_EIP):08x} events={events}') from exc
    state=[get(u,0x6a6440),get(u,0x6a6448),get(u,0x6a6444)]
    return {'events':events,'state':state,'stack_delta':u.reg_read(UC_X86_REG_ESP)-STACK}

def main():
    p=argparse.ArgumentParser();p.add_argument('--probe',type=Path,default=ROOT/'local/builds/v2/render-event-route-060/bin/Release/render_event_route_probe.exe');p.add_argument('--report',type=Path,default=RUN/'verification.json');a=p.parse_args()
    module=next(json.loads(x) for x in (ROOT/'research/binary-index/static/binaries.jsonl').read_text(encoding='utf8').splitlines() if json.loads(x)['file']=='Porsche.exe')
    data=(ROOT/'local/game'/module['path']).read_bytes();assert hashlib.sha256(data).hexdigest()==SHA
    inputs=cases()
    feed=''.join(' '.join(map(str,[route,gate,lock,callback,x,y,flags,down,*bounds,*last,client,dx,dy,*driver]))+'\n' for route,gate,lock,callback,x,y,flags,down,bounds,last,client,dx,dy,driver in inputs)
    proc=subprocess.run([str(a.probe)],input=feed,text=True,capture_output=True,check=True)
    lines=proc.stdout.splitlines();assert len(lines)==len(inputs),(len(lines),len(inputs),proc.stderr)
    fixtures=[]
    for c,line in zip(inputs,lines):
        route,*_=c;native=json.loads(line);expected=original(module,data,c)
        want_delta=4
        if expected['stack_delta']!=want_delta:raise RuntimeError(f'{c}: unexpected original stack delta {expected}')
        if native['events']!=expected['events'] or native['state']!=expected['state']:
            raise RuntimeError(f'{c}: x86={expected} native={native}')
        fixtures.append({'input':c,'output':{'events':native['events'],'state':native['state'],'stack_delta':expected['stack_delta']}})
    rel=lambda x:x.relative_to(ROOT).as_posix()
    deps=[ITER/'source/include/porsche/render_event_route.hpp',ITER/'source/include/porsche/render_driver_calls.hpp',ITER/'source/include/porsche/render_display.hpp',ITER/'source/include/porsche/render_loader.hpp',ITER/'source/include/porsche/heap.hpp',ITER/'source/include/porsche/heap_locks.hpp',ITER/'source/include/porsche/window_position.hpp',ITER/'source/include/porsche/window_create.hpp',ITER/'source/include/porsche/window_state.hpp',ITER/'source/include/porsche/window_messages.hpp',ITER/'source/recovered/Porsche.exe/render_event_route.cpp',ITER/'source/recovered/Porsche.exe/render_driver_calls.cpp',ITER/'source/recovered/Porsche.exe/heap_locks.cpp',ITER/'source/recovered/Porsche.exe/window_create.cpp',ITER/'source/recovered/Porsche.exe/window_state.cpp',ITER/'source/recovered/Porsche.exe/window_position.cpp',ITER/'source/recovered/render_event_route_probe.cpp',ROOT/'research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm',ROOT/'research/v2/binaries/Porsche.exe-ddd748fdbe6d/decompiled.c',RUN/'CMakeLists.txt',RUN/'README.md',Path(__file__).resolve()]
    report={'schema':1,'binary':'Porsche.exe','sha256':SHA,'entry_va':'005728b0','coverage':'full 005728b0..0057298a plus cursor helper 0053a970..0053a9d2 and default callback 005367b0..005367b3','full_function_vas':['005728b0','0053a970','005367b0'],'partial_function_vas':[],'cases':len(inputs),'native_cpp_equal_original_x86':True,'binary_matched':False,'game_launch_verified':False,'boundaries':'Heap lock APIs 005322b0/005322c0 use the recovered heap lock implementation; USER32 ClientToScreen, SetCursorPos, SetCursor are typed platform edges. Unknown replacement callback targets in PTR_FUN_005debec remain a typed bridge; the original PE initializer points to recovered no-op 005367b0. The window-message name and render-driver call bridge both dispatch to this single consumer; no state globals are duplicated.','source_sha256':{rel(x):hashlib.sha256(x.read_bytes().replace(b'\r\n',b'\n')).hexdigest() for x in deps},'probe_sha256':hashlib.sha256(a.probe.read_bytes()).hexdigest(),'fixtures':fixtures}
    report['source_sha256']=source_hashes(report['source_sha256'].keys(),compiled_sources=['iterations/v2/001-original-recovery/source/recovered/Porsche.exe/render_driver_calls.cpp', 'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/render_event_route.cpp', 'iterations/v2/001-original-recovery/source/recovered/render_event_route_probe.cpp'])
    a.report.parent.mkdir(parents=True,exist_ok=True);a.report.write_text(json.dumps(report,indent=2)+'\n',encoding='utf8')
    print(json.dumps({'cases':len(inputs),'full_function_vas':report['full_function_vas'],'native_cpp_equal_original_x86':True,'shared_route':'window_message_mouse_event_005728b0 / render_driver_apply_005728b0'}))
if __name__=='__main__':main()
