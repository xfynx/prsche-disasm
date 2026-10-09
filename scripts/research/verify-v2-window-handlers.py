"""Original 53a800 handler table and eight callbacks versus native x86 C++."""
import argparse, hashlib, json, struct, subprocess, sys
from pathlib import Path

ROOT=Path(__file__).resolve().parents[2]
RUN=ROOT/'iterations/v2/001-original-recovery/runs/038-window-handlers'
SHA='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ESP,UC_X86_REG_EIP
STACK,EXIT,LOCK,PUMP,DISPATCH,SPI,QUIT=0x3108000,0x3200000,0x3210000,0x3210010,0x3210020,0x3210030,0x3210040
LOCK_CREATE=0x5321f0
CONFIG,OUT=0x3101000,0x3102000
HANDLERS=[0x53b040,0x53b230,0x53b260,0x53b290,0x53b2a0,0x53b2e0,0x53b870,0x53b8b0]

def put(u,a,v):u.mem_write(a,struct.pack('<I',v&0xffffffff))
def word(u,a):return struct.unpack('<I',u.mem_read(a,4))[0]

def cases():
    c=[]
    # key found replacement, found removal, insertion in-order, append at capacity,
    # out-of-capacity insertion, first-use lock and already-created lock.
    c += [(0,5,30,0x12345678,1,0,0),(0,5,30,0,1,0,0),
          (0,5,25,0x12345678,1,0,0),(0,128,0x1234abcd,0x12345678,1,0,0),
          (0,128,0x1234abcd,0,1,0,0),(0,0,0x1234abcd,0x12345678,0,0,0),
          (0,3,20,0,1,0,0)]
    for mode in range(1,9):
        for hascfg in ((1,) if mode==5 else (0,1)):
            for hwndmatch in (0,1):
                for flag in (0,1):
                    for wp in ((0xf060,0xf020,0xf030,0xf120,0x1234) if mode==5 else (0x13579bdf,)):
                        c.append((mode,hascfg,hwndmatch,flag,wp,0x1234,3))
    c += [(6,1,1,1,0,0x1234,0),(6,1,1,1,0,0x1234,1),(6,1,1,1,0,0x1234,2),(6,1,1,1,0,0x1234,3)]
    return c

def original(module,data,case):
    u=Uc(UC_ARCH_X86,UC_MODE_32);u.mem_map(0x400000,0x300000)
    for sec in module['sections']:
        u.mem_write(0x400000+sec['rva'],data[sec['raw_offset']:sec['raw_offset']+sec['raw_size']])
    u.mem_map(0x3100000,0x10000);u.mem_map(EXIT,0x1000);u.mem_map(LOCK,0x1000);u.mem_write(EXIT,b'\xc3'*0x1000)
    calls={'lock':0,'pump':0,'dispatch':0,'quit':0,'spi':0}
    if case[0]==0:
        _,count,key,value,lock_present,_,_=case
        u.mem_write(0x69e0e0,b'\xcc'*1024);put(u,0x69e570,count)
        for i in range(count):put(u,0x69e0e0+i*8,10+10*i);put(u,0x69e0e4+i*8,0x1000+i)
        put(u,0x69e59c,0x22220000 if lock_present else 0);put(u,0x5b2078,PUMP);put(u,0x5b206c,DISPATCH)
        put(u,STACK,EXIT);put(u,STACK+4,key);put(u,STACK+8,value)
        entry=0x53a800
    else:
        mode,hascfg,match,flag,wp,configured,spi_values=case
        conf=bytearray(0x474);conf[0x461]=flag;struct.pack_into('<I',conf,0x458,configured)
        u.mem_write(CONFIG,bytes(conf));put(u,0x6b7bf8,0x1234);put(u,0x69e578,0);put(u,0x6b7c14,wp)
        put(u,0x69e57c,0);put(u,0x69e580,0);put(u,OUT,0x76543210)
        put(u,0x5b22f4,QUIT);put(u,0x5b2314,SPI)
        for addr,value in ((QUIT,1),(SPI,2),(LOCK,0),(PUMP,0),(DISPATCH,0)):
            pass
        args=[CONFIG if hascfg else 0,0x1234 if match else 0x5678,0,wp,0,OUT]
        for i,v in enumerate([EXIT]+args):put(u,STACK+i*4,v)
        entry=HANDLERS[mode-1]

    trace=[]
    def hook(m,address,_size,_user):
        trace.append(address)
        if len(trace)>30:trace.pop(0)
        if address not in (LOCK_CREATE,PUMP,DISPATCH,SPI,QUIT):return
        sp=m.reg_read(UC_X86_REG_ESP);ret=word(m,sp)
        if address==LOCK_CREATE:
            calls['lock']+=1;m.reg_write(UC_X86_REG_EAX,0x22220000);cleanup=0
        elif address==PUMP:
            calls['pump']+=1;cleanup=4
        elif address==DISPATCH:
            calls['dispatch']+=1;cleanup=4
        elif address==QUIT:
            calls['quit']+=1;cleanup=4
        else:
            calls['spi']+=1;action=word(m,sp+4);out=word(m,sp+12)
            values=case[6]
            if action in (0x10,0x54):put(m,out,1 if (values&(1 if action==0x10 else 2)) else 0)
            cleanup=16
        m.reg_write(UC_X86_REG_ESP,sp+4+cleanup);m.reg_write(UC_X86_REG_EIP,ret)
    u.hook_add(UC_HOOK_CODE,hook)
    u.reg_write(UC_X86_REG_ESP,STACK)
    try:u.emu_start(entry,EXIT,count=250000)
    except Exception as exc:raise RuntimeError(f'{case}: {exc}, eip={u.reg_read(UC_X86_REG_EIP):08x}, trace={[hex(x) for x in trace]}') from exc
    if u.reg_read(UC_X86_REG_EIP)!=EXIT:raise RuntimeError(f'Original did not return at {entry:08x}')
    if case[0]==0:
        rows=[(word(u,0x69e0e0+i*8),word(u,0x69e0e4+i*8)) for i in range(word(u,0x69e570))]
        return (u.reg_read(UC_X86_REG_EAX),word(u,0x69e570),int(bool(word(u,0x69e59c))),
                calls['pump'],calls['dispatch'],*rows)
    return (u.reg_read(UC_X86_REG_EAX),word(u,OUT),word(u,0x6b7c14),word(u,0x69e578),
            calls['quit'],calls['spi'],word(u,0x69e57c),word(u,0x69e580),calls['pump'],calls['dispatch'])

def main():
    p=argparse.ArgumentParser();p.add_argument('--probe',type=Path,default=ROOT/'local/builds/v2/window-handlers-038/bin/Release/window_handlers_probe.exe');p.add_argument('--report',type=Path,default=RUN/'verification.json');args=p.parse_args()
    module=next(json.loads(x) for x in (ROOT/'research/binary-index/static/binaries.jsonl').read_text(encoding='utf8').splitlines() if json.loads(x)['file']=='Porsche.exe')
    data=(ROOT/'local/game'/module['path']).read_bytes();assert hashlib.sha256(data).hexdigest()==SHA
    inputs=cases();native=subprocess.run([str(args.probe)],input=''.join(' '.join(map(str,x))+'\n' for x in inputs),text=True,capture_output=True,check=True)
    lines=native.stdout.splitlines();assert len(lines)==len(inputs),(len(lines),len(inputs))
    outputs=[]
    for case,line in zip(inputs,lines):
        vals=[]
        for word_ in line.split():
            vals.append(tuple(int(x,0) for x in word_.split(':')) if ':' in word_ else int(word_,0))
        actual=tuple(vals);expected=original(module,data,case)
        if actual!=expected:raise RuntimeError(f'{case}: expected {expected}, actual {actual}')
        outputs.append({'input':case,'output':actual})
    deps=['iterations/v2/001-original-recovery/'+x for x in (
          'source/include/porsche/window_handlers.hpp','source/recovered/Porsche.exe/window_handlers.cpp',
          'source/recovered/window_handlers_probe.cpp','source/recovered/Porsche.exe/window_procedure.cpp',
          'source/include/porsche/window_state.hpp','source/recovered/Porsche.exe/window_state.cpp',
          'runs/038-window-handlers/CMakeLists.txt','runs/038-window-handlers/README.md')]
    deps+=['scripts/research/verify-v2-window-handlers.py']
    # Pin every compiled translation unit and its owned transitive headers.
    import re
    owned=ROOT/'iterations/v2/001-original-recovery/source'
    pending=[owned/'recovered/Porsche.exe'/x for x in ['window_handlers.cpp', 'window_procedure.cpp']]
    seen=set()
    while pending:
        path=pending.pop()
        if path in seen:continue
        seen.add(path)
        for inc in re.findall(r'#include "(porsche/[^"]+)"',path.read_text(encoding='utf8')):
            pending.append(owned/'include'/inc)
    deps=sorted(set(deps)|{p.relative_to(ROOT).as_posix() for p in seen})
    report={'schema':1,'sha256':SHA,'function_vas':['0053a800',*[f'{x:08x}' for x in HANDLERS],
        '005a2f23','0053a7f0'],'full_function_vas':['0053a800','0053b040','0053b230','0053b260',
        '0053b290','0053b2a0','0053b2e0','0053b870','0053b8b0'],'partial_function_vas':[],
        'cases':len(inputs),'native_cpp_equal_original_x86':True,'binary_matched':False,'game_launch_verified':False,
        'boundaries':'Native 005a112b is fixture CRT qsort for unique bounded keys; original qsort executes in the oracle. Its algorithm/call ordering is not recovered. 005322b0/005322c0 lock wrappers and Win32 PostQuitMessage/SystemParametersInfoA are fixtures; original search, comparator, qsort, and callbacks execute from x86 image.',
        'source_sha256':{x:hashlib.sha256((ROOT/x).read_bytes().replace(b'\r\n',b'\n')).hexdigest() for x in deps},
        'probe_sha256':hashlib.sha256(args.probe.read_bytes()).hexdigest(),'fixtures':outputs}
    args.report.parent.mkdir(parents=True,exist_ok=True);args.report.write_text(json.dumps(report,indent=2)+'\n',encoding='utf8')
    print(json.dumps({'cases':len(inputs),'function_vas':report['function_vas'],'native_cpp_equal_original_x86':True}))
if __name__=='__main__':main()
