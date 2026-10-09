"""Differentially compare Porsche.exe 0053b8d0 with the recovered C++ worker."""
import argparse, hashlib, json, struct, subprocess, sys
from pathlib import Path

ROOT=Path(__file__).resolve().parents[2]
RUN=ROOT/'iterations/v2/001-original-recovery/runs/035-window-worker'
sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ESP,UC_X86_REG_EIP

STACK,EXIT=0x3108000,0x3000100
SHA='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
CASES=[(0,1,0,0,0,3,4,643,484,40,50,1,0),
       (0,1,1,35,45,0,0,640,480,0,0,0,0),
       (1,1,0,0,0,0,0,800,600,0,0,1,1),
       (1,1,1,35,45,0,0,800,600,0,0,0,1),
       (0,1,0,0,0,3,4,643,484,40,50,1,1),
       (0,1,0,0,0,3,4,643,484,40,50,0xffffffff,0)]

def original(module,data,case):
    fs,create,override,ox,oy,left,top,right,bottom,sx,sy,msg,fs_after=case
    uc=Uc(UC_ARCH_X86,UC_MODE_32);base=int(module['image_base'],16);uc.mem_map(base,0x300000)
    for sec in module['sections']:
        uc.mem_write(base+sec['rva'],data[sec['raw_offset']:sec['raw_offset']+sec['raw_size']])
    uc.mem_map(0x3000000,0x10000);uc.mem_map(0x3100000,0x10000);uc.mem_map(0x3200000,0x10000)
    def put(a,v):uc.mem_write(a,struct.pack('<I',v&0xffffffff))
    def word(a):return struct.unpack('<I',uc.mem_read(a,4))[0]
    def signed(a):return struct.unpack('<i',uc.mem_read(a,4))[0]
    def write_rect(p,vals):uc.mem_write(p,struct.pack('<4i',*vals))
    cfg=0x6b77a0;uc.mem_write(cfg,b'\0'*0x480);uc.mem_write(cfg+0x461,bytes([fs]))
    put(cfg+0x14,right);put(cfg+0x18,bottom);put(cfg+0x458,1)
    put(0x69e5a8,0x3200800);uc.mem_write(0x3200800,b'Class\0');put(0x6b7794,0x1234000)
    put(0x5dea88,0x10000000);uc.mem_write(0x5dead4,b'\x09')
    put(0x69e5b0,override);put(0x6bda00,ox);put(0x6bda04,oy)
    put(0x69e5a0,1);put(0x5de024,0);put(0x69e59c,0x2220000);put(0x69e5a4,0x3000200)
    uc.mem_write(0x6b7c01,bytes([fs]));put(0x6b7bf8,0);put(0x6b7c14,0);put(0x69e574,0);put(0x69e578,0)
    put(0x69e598,0);put(0x6bda00,ox);put(0x6bda04,oy);put(0x69e57c,0);put(0x69e580,0)
    put(0x69e5b0,override);put(0x69e5a4,0x3000200);put(0x69e578,0);put(0x69e574,0)
    put(0x6bda00,ox);put(0x6bda04,oy);put(0x69e5b0,override)
    # Distinct executable stubs make IAT and unresolved direct calls observable.
    addresses={0x5b22c4:0x3000000,0x5b22bc:0x3000010,0x5b22c0:0x3000020,
      0x5b2324:0x3000030,0x5b2278:0x3000040,0x5b22f0:0x3000050,
      0x5b231c:0x3000060,0x5b2300:0x3000070,0x5b22d0:0x3000080,
      0x5b22d4:0x3000090,0x5b22d8:0x30000a0,0x5b22dc:0x30000b0,
      0x5b22e0:0x30000c0,0x5b22e4:0x30000d0}
    for a,t in addresses.items():
        if a<0x3000000:put(a,t)
    calls=[]
    # name, stack argument count, stdcall cleanup
    spec={0x3000000:('metrics',1,True),0x3000010:('adjust',4,True),0x3000020:('create',12,True),
      0x3000030:('cursor',1,True),0x3000040:('showcursor',1,True),0x3000050:('clientrect',2,True),
      0x3000060:('clienttoscreen',2,True),0x3000070:('foreground',1,True),0x3000080:('active',1,True),
      0x3000090:('destroy',1,True),0x30000a0:('getmessage',4,True),0x30000b0:('translate',1,True),
      0x30000c0:('dispatch',1,True),0x30000d0:('iconic',1,True),
      0x55fb20:('tick',0,False),0x55fb90:('event_wait',1,False),0x55fc10:('event_set',1,False),
      0x5322b0:('pump',1,False),0x5322c0:('dispatch_game',1,False),0x565560:('activation',0,False),
      0x573980:('focus',0,False),0x558350:('prepare',1,False),0x3000200:('callback',0,False),
      0x53b530:('accelerator',2,False)}
    def hook(m,p,size,user):
        if p==EXIT:m.emu_stop();return
        if p not in spec:return
        name,n,stdcall=spec[p];sp=m.reg_read(UC_X86_REG_ESP);raw=struct.unpack('<'+'I'*(n+1),m.mem_read(sp,4*(n+1)));ret,args=raw[0],list(raw[1:]);result=0
        if name=='metrics':result=640 if args[0]==0 else 480
        elif name=='adjust':result=1
        elif name=='create':calls.append(['CreateWindowExA']);result=0x1230000 if create else 0
        elif name=='cursor':calls.append(['SetCursor'])
        elif name=='showcursor':calls.append(['ShowCursor'])
        elif name=='clientrect':calls.append(['GetClientRect']);write_rect(args[1],(left,top,right,bottom));result=1
        elif name=='clienttoscreen':calls.append(['ClientToScreen']);write_rect(args[1],(sx,sy,0,0));result=1
        elif name=='foreground':calls.append(['SetForegroundWindow'])
        elif name=='active':calls.append(['SetActiveWindow'])
        elif name=='destroy':calls.append(['DestroyWindow']);result=1
        elif name=='getmessage':
            calls.append(['GetMessageA']);result=msg
            if msg:m.mem_write(args[0],struct.pack('<7I',0x1230000,0x100,65,0,100,0,0))
        elif name=='translate':calls.append(['TranslateMessage']);result=1
        elif name=='dispatch':calls.append(['DispatchMessageA']);put(0x69e578,1)
        elif name=='iconic':calls.append(['IsIconic'])
        elif name=='accelerator':calls.append(['0053b530',*args]);result=0
        elif name=='tick':calls.append(['0055fb20']);result=77
        elif name=='event_wait':calls.append(['0055fb90',args[0]]);m.mem_write(0x6b7c01,bytes([fs_after]))
        elif name=='event_set':calls.append(['0055fc10',args[0]])
        elif name=='pump':calls.append(['005322b0',args[0]])
        elif name=='dispatch_game':calls.append(['005322c0',args[0]])
        elif name=='activation':result=0
        elif name=='focus':result=0
        elif name=='prepare':calls.append(['00558350'])
        elif name=='callback':calls.append(['callback']);put(0x69e578,1)
        m.reg_write(UC_X86_REG_EAX,result);m.reg_write(UC_X86_REG_ESP,sp+4*(n+1) if stdcall else sp+4);m.reg_write(UC_X86_REG_EIP,ret)
    uc.hook_add(UC_HOOK_CODE,hook);put(STACK,EXIT);put(STACK+4,0)
    uc.reg_write(UC_X86_REG_ESP,STACK)
    try:uc.emu_start(0x53b8d0,EXIT,count=3000)
    except Exception as e:raise RuntimeError(f'x86 worker fault at {uc.reg_read(UC_X86_REG_EIP):08x}, calls={calls}') from e
    if uc.reg_read(UC_X86_REG_EIP)!=EXIT:raise RuntimeError('original worker did not return')
    return {'result':uc.reg_read(UC_X86_REG_EAX),'hwnd':word(0x6b7bf8),
      'pos':[signed(0x6b7c08),signed(0x6b7c0c)],'calls':calls}

def main():
    ap=argparse.ArgumentParser();ap.add_argument('--probe',type=Path,default=ROOT/'local/builds/v2/001-original-recovery/run035-window-worker/bin/Release/window_worker_probe.exe');ap.add_argument('--limit',type=int,default=0);ap.add_argument('--report',type=Path,default=RUN/'verification.json');a=ap.parse_args()
    module=next(json.loads(x) for x in (ROOT/'research/binary-index/static/binaries.jsonl').read_text(encoding='utf8').splitlines() if json.loads(x)['file']=='Porsche.exe')
    data=(ROOT/'local/game'/module['path']).read_bytes()
    if hashlib.sha256(data).hexdigest()!=SHA or module['sha256']!=SHA:raise RuntimeError('original SHA mismatch')
    selected=CASES[:a.limit or None]
    native=subprocess.run([str(a.probe)],input='\n'.join(' '.join(map(str,c)) for c in selected)+'\n',text=True,capture_output=True,check=True,timeout=30)
    rows=[json.loads(x) for x in native.stdout.splitlines()]
    for i,(case,actual) in enumerate(zip(selected,rows)):
        expected=original(module,data,case)
        if actual!=expected:raise RuntimeError(f'case {i} {case}: expected={expected}, native={actual}')
    print(json.dumps({'range':'0053b8d0..0053bad8','cases':len(selected),'native_cpp_equal_original_x86':True}))
    if a.limit:return
    files=['iterations/v2/001-original-recovery/source/include/porsche/window_worker.hpp','iterations/v2/001-original-recovery/source/include/porsche/window_state.hpp','iterations/v2/001-original-recovery/source/recovered/Porsche.exe/window_worker.cpp','iterations/v2/001-original-recovery/source/recovered/Porsche.exe/window_state.cpp','iterations/v2/001-original-recovery/source/recovered/window_worker_probe.cpp','iterations/v2/001-original-recovery/runs/035-window-worker/CMakeLists.txt','scripts/research/verify-v2-window-worker.py']
    # Pin every compiled translation unit and its owned transitive headers.
    import re
    owned=ROOT/'iterations/v2/001-original-recovery/source'
    pending=[owned/'recovered/Porsche.exe'/x for x in ['window_worker.cpp', 'window_runtime.cpp']]
    seen=set()
    while pending:
        path=pending.pop()
        if path in seen:continue
        seen.add(path)
        for inc in re.findall(r'#include "(porsche/[^"]+)"',path.read_text(encoding='utf8')):
            pending.append(owned/'include'/inc)
    files=sorted(set(files)|{p.relative_to(ROOT).as_posix() for p in seen})
    report={'schema':1,'sha256':SHA,'range':'0053b8d0..0053bad8','function_vas':['0053b8d0'],'full_function_vas':['0053b8d0'],'partial_function_vas':[],'cases':len(selected),'native_cpp_equal_original_x86':True,'binary_matched':False,'game_launch_verified':False,'source_sha256':{p:hashlib.sha256((ROOT/p).read_bytes().replace(b'\r\n',b'\n')).hexdigest() for p in files},'probe_sha256':hashlib.sha256(a.probe.read_bytes()).hexdigest()}
    a.report.parent.mkdir(parents=True,exist_ok=True);a.report.write_text(json.dumps(report,indent=2)+'\n',encoding='utf8')
if __name__=='__main__':main()
