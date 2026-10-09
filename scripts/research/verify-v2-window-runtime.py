"""Compare the bounded Porsche.exe 0x5366e0 callback consumer with x86."""
import argparse
import hashlib
import json
from pathlib import Path
import struct
import subprocess
import sys

ROOT=Path(__file__).resolve().parents[2]
RUN=ROOT/'iterations/v2/001-original-recovery/runs/027-window-runtime'
sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ESP,UC_X86_REG_EIP

BASE=0x400000
CALLBACKS=(0x3000000,0x3000010)
EXIT=0x3000100
STACK=0x3108000

def cases():
    out=[]
    for last,tick in ((0,0),(0,5),(4,5),(0x7ffffffe,0x80000000)):
        for first in (0,1):
            for second in (0,1):
                for active in (0,1):
                    out.append((last,tick,3,7,first,active,4,9,second,0,0x1234,0))
    out.extend([(0,10,5,7,1,0,11,9,1,0,0x45,20),
                (0,10,5,7,1,0,11,9,1,0,0x45,2),
                (0,0xffffffff,0xfffffffe,4,1,0,0,1,1,0,0x67,0)])
    return out

def original(module,data,case):
    uc=Uc(UC_ARCH_X86,UC_MODE_32)
    base=int(module['image_base'],16)
    uc.mem_map(base,0x300000)
    for s in module['sections']:
        uc.mem_write(base+s['rva'],data[s['raw_offset']:s['raw_offset']+s['raw_size']])
    uc.mem_map(0x3000000,0x1000)
    uc.mem_map(0x3100000,0x10000)
    def put(addr,value):uc.mem_write(addr,struct.pack('<I',value&0xffffffff))
    def word(addr):return struct.unpack('<I',uc.mem_read(addr,4))[0]
    last,tick,next0,period0,enabled0,active0,next1,period1,enabled1,active1,arg,change_tick=case
    uc.mem_write(0x69dd20,b'\0'*256)
    put(0x69de24,last);put(0x6b7c40,tick)
    for i,(n,period,enabled,active) in enumerate(((next0,period0,enabled0,active0),(next1,period1,enabled1,active1))):
        slot=0x69dd20+i*16
        put(slot,CALLBACKS[i] if enabled else 0)
        put(slot+4,period);put(slot+8,n);put(slot+12,active)
    calls=[]
    def hook(machine,p,size,user):
        if p not in CALLBACKS:return
        sp=machine.reg_read(UC_X86_REG_ESP)
        ret,a,elapsed=struct.unpack('<III',machine.mem_read(sp,12))
        i=CALLBACKS.index(p);calls.append([i,a,elapsed])
        if i==0 and change_tick:put(0x6b7c40,change_tick)
        machine.reg_write(UC_X86_REG_EAX,i+1)
        machine.reg_write(UC_X86_REG_ESP,sp+4)
        machine.reg_write(UC_X86_REG_EIP,ret)
    uc.hook_add(UC_HOOK_CODE,hook)
    put(STACK,EXIT);put(STACK+4,arg)
    uc.reg_write(UC_X86_REG_ESP,STACK)
    uc.emu_start(0x5366e0,EXIT,count=500)
    if uc.reg_read(UC_X86_REG_EIP)!=EXIT:raise RuntimeError('callback consumer did not return')
    return {'result':uc.reg_read(UC_X86_REG_EAX),'last':word(0x69de24),
            'tick':word(0x6b7c40),'slots':[word(0x69dd28),word(0x69dd2c),word(0x69dd38),word(0x69dd3c)],
            'calls':calls,'noop':0}

def window_cases():
    return [(full,pos,flag,override,channels,success,0x10000000,x,y,640,480,800,600,delta,7)
            for full in (0,1) for pos in (0,1) for flag in (0,1)
            for override in (0,1) for channels in (0,1) for success in (0,1)
            for x,y,delta in ((20,30,5),)]

def original_window(module,data,case):
    uc=Uc(UC_ARCH_X86,UC_MODE_32)
    base=int(module['image_base'],16)
    uc.mem_map(base,0x300000)
    for s in module['sections']:
        uc.mem_write(base+s['rva'],data[s['raw_offset']:s['raw_offset']+s['raw_size']])
    uc.mem_map(0x3000000,0x1000)
    uc.mem_map(0x3100000,0x10000)
    uc.mem_map(0x3200000,0x10000)
    OBJ,CLASS=0x3201000,0x3202000
    def put(addr,value):uc.mem_write(addr,struct.pack('<I',value&0xffffffff))
    def word(addr):return struct.unpack('<I',uc.mem_read(addr,4))[0]
    def signed(value):return struct.unpack('<i',struct.pack('<I',value))[0]
    fullscreen,positioned,flag,override,channels,success,style,x,y,w,h,mw,mh,delta,state=case
    uc.mem_write(OBJ,b'\0'*0x480);uc.mem_write(CLASS,b'Class\0')
    for off,val in ((0x14,w),(0x18,h),(0x458,positioned),(0x468,x),(0x46c,y)):put(OBJ+off,val)
    uc.mem_write(OBJ+0x461,bytes([fullscreen]))
    for addr,val in ((0x5dea88,style),(0x69e5b0,override),(0x6bda00,35),(0x6bda04,45),
                     (0x69e5a8,CLASS),(0x6b7794,0x1234000),(0x5de024,state),(0x69e5a0,channels)):put(addr,val)
    uc.mem_write(0x5dead4,bytes([0x20 if flag else 0]))
    endpoints={0x5b22c4:(0x3000000,'metrics',1,True),0x5b22bc:(0x3000010,'adjust',4,True),
               0x5b22c0:(0x3000020,'create',12,True),0x5b2324:(0x3000030,'set_cursor',1,True),
               0x5b2278:(0x3000040,'show_cursor',1,True)}
    for address,(target,_,_,_) in endpoints.items():put(address,target)
    endpoints_by_target={target:(name,argc,stdcall) for target,name,argc,stdcall in endpoints.values()}
    endpoints_by_target[0x5739b0]=('channel',2,False)
    calls=[]
    def hook(machine,p,size,user):
        if p not in endpoints_by_target:return
        name,argc,stdcall=endpoints_by_target[p]
        sp=machine.reg_read(UC_X86_REG_ESP)
        ret,*args=struct.unpack('<'+'I'*(argc+1),machine.mem_read(sp,4*(argc+1)))
        result=0
        if name=='metrics':
            calls.append([name,args[0]]);result=mw if args[0]==0 else mh
        elif name=='adjust':
            rect=list(struct.unpack('<iiii',machine.mem_read(args[0],16)))
            calls.append([name,*rect,args[1],signed(args[2]),args[3]])
            l,t,r,b=rect
            machine.mem_write(args[0],struct.pack('<iiii',l-delta,t-delta,r+delta,b+delta))
            result=1
        elif name=='create':
            def cstr(addr):return bytes(machine.mem_read(addr,6)).split(b'\0')[0].decode()
            calls.append([name,args[0],cstr(args[1]),cstr(args[2]),args[3],
                          *map(signed,args[4:8]),*args[8:]])
            result=0x1230000 if success else 0
        elif name in ('set_cursor','show_cursor'):
            calls.append([name,signed(args[0])])
        elif name=='channel':calls.append([name,*args])
        machine.reg_write(UC_X86_REG_EAX,result)
        machine.reg_write(UC_X86_REG_ESP,sp+4*(argc+1) if stdcall else sp+4)
        machine.reg_write(UC_X86_REG_EIP,ret)
    uc.hook_add(UC_HOOK_CODE,hook)
    put(STACK,EXIT);put(STACK+4,OBJ)
    uc.reg_write(UC_X86_REG_ESP,STACK)
    uc.emu_start(0x53bb00,EXIT,count=1500)
    if uc.reg_read(UC_X86_REG_EIP)!=EXIT:raise RuntimeError('window create did not return')
    return {'result':uc.reg_read(UC_X86_REG_EAX),'x':signed(word(OBJ+0x468)),
            'y':signed(word(OBJ+0x46c)),'state':word(0x5de024),'calls':calls}

def main():
    parser=argparse.ArgumentParser()
    parser.add_argument('--probe',type=Path,default=ROOT/'local/builds/v2/001-original-recovery/bin/Release/window_runtime_probe.exe')
    parser.add_argument('--limit',type=int,default=0)
    args=parser.parse_args()
    module=next(x for x in map(json.loads,(ROOT/'research/binary-index/static/binaries.jsonl').read_text(encoding='utf8').splitlines()) if x['file']=='Porsche.exe')
    data=(ROOT/'local/game'/module['path']).read_bytes()
    sha='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
    if hashlib.sha256(data).hexdigest()!=sha or module['sha256']!=sha:raise RuntimeError('original SHA mismatch')
    defaults=json.loads(subprocess.run([str(args.probe),'--defaults'],text=True,capture_output=True,check=True).stdout)
    if defaults!=[0x10000000,9]:raise RuntimeError(f'file-backed default mismatch: {defaults}')
    selected=cases()[:args.limit or None]
    native=subprocess.run([str(args.probe)],input='\n'.join(' '.join(map(str,c)) for c in selected)+'\n',text=True,capture_output=True,check=True,timeout=30)
    rows=list(map(json.loads,native.stdout.splitlines()))
    if len(rows)!=len(selected):raise RuntimeError('native row count mismatch')
    for i,(case,actual) in enumerate(zip(selected,rows)):
        expected=original(module,data,case)
        if expected!=actual:raise RuntimeError(f'case {i} differs: {case}; original={expected}; native={actual}')
    windows=window_cases()[:args.limit or None]
    native_windows=subprocess.run([str(args.probe),'--window'],
        input='\n'.join(' '.join(map(str,c)) for c in windows)+'\n',text=True,capture_output=True,check=True,timeout=30)
    window_rows=list(map(json.loads,native_windows.stdout.splitlines()))
    if len(window_rows)!=len(windows):raise RuntimeError('native window row count mismatch')
    for i,(case,actual) in enumerate(zip(windows,window_rows)):
        expected=original_window(module,data,case)
        if expected!=actual:raise RuntimeError(f'window case {i} differs: {case}; original={expected}; native={actual}')
    print(json.dumps({'scheduler_cases':len(selected),'window_cases':len(windows),
                      'function_vas':['005366e0','005367b0','0053bb00'],'native_cpp_equal_original_x86':True}))
    if args.limit:return
    paths=['iterations/v2/001-original-recovery/source/include/porsche/window_runtime.hpp',
           'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/window_runtime.cpp',
           'iterations/v2/001-original-recovery/source/recovered/window_runtime_probe.cpp',
           'scripts/research/verify-v2-window-runtime.py']
    report={'schema':1,'sha256':sha,'function_vas':['005366e0','005367b0','0053bb00'],
            'scheduler_cases':len(selected),'window_cases':len(windows),
            'native_cpp_equal_original_x86':True,'binary_matched':False,'game_launch_verified':False,
            'source_sha256':{p:hashlib.sha256((ROOT/p).read_bytes().replace(b'\r\n',b'\n')).hexdigest() for p in paths},
            'probe_sha256':hashlib.sha256(args.probe.read_bytes()).hexdigest()}
    RUN.mkdir(parents=True,exist_ok=True)
    (RUN/'verification.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf8')

if __name__=='__main__':main()
