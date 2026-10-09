from v2_source_dependencies import source_hashes
"""Differentially execute the original window activation/key paths and C++ probe."""
import argparse, hashlib, json, struct, subprocess, sys
from pathlib import Path

ROOT=Path(__file__).resolve().parents[2]
SHA='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
RUN=ROOT/'iterations/v2/001-original-recovery/runs/059-window-keys'
sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ESP,UC_X86_REG_EIP

BASE=0x400000; STACK=0x3108000; EXIT=0x3010000
API={0x5b2318:0x3000000,0x5b22cc:0x3000010,0x5b2304:0x3000020,
     0x5b2278:0x3000030,0x5b22f8:0x3000040,0x5b22c8:0x3000050}
DIRECT={0x53a9e0:0x3000060,0x3000070:0x3000070}
ADDR={v:k for k,v in API.items()}

def cases():
    out=[]
    # The original accelerator has a 91-byte class table covering every key 21..7b.
    for msg in (0x100,0x104):
        out.extend((0,msg,key) for key in range(0x21,0x7c))
        out.extend((0,msg,key) for key in (0,0x20,0x7c,0xffffffff))
    for msg in (0x100,0x104,0x102,0x101):
      for wp in (0x20,0x21,0x2d,0x2e,0x60,0x69,0x70,0x7b,0x7c):
       for accel in (0,1):
        out.append((1,1,1,msg,wp,0x01020003,4,1,accel))
    out += [(1,0,1,0x100,0x21,0x01010002,8,0,0),
            (1,1,0,0x100,0x21,0x01010002,8,0,0),
            (0,1,1,0x100,0x21,0x01010002,8,0,0),
            (1,1,1,0x100,0x21,0x00000000,8,1,0)]
    # Activation branches cover state, hook handle/enable, minimized/high word,
    # Win32 return value, and invalid callback identities.
    for cfg in (0,1):
     for match in (0,1):
      for active in (0,1):
       for enabled in (0,1):
        for hook in (0,1):
         out.append((2,cfg,match,active,enabled,hook,1,1,0xffff1234,0))
    out += [(2,1,1,0,1,1,1,0,0x00010000,0),
            (2,1,1,1,1,0,0,1,0x12340001,-9),
            (2,1,1,0,0,1,0,1,0x00000000,7)]
    # Hook callback: code/running gates, filter context rules, Ctrl state,
    # recognized key set, optional callback result and CallNext boundary.
    for code in (0,1,-1):
     for running in (0,1):
      out.append((3,code,0x1b,0x20000000,running,0,0,1,0,-23,1))
    for filter in (0,1):
     for context in (0,1):
      for key in (9,0x1b,0x20,0x5b,0x5c,0x5d,0x2c,0x41):
       for ctrl in (0,0x8000):
        for cb in (0,1):
         for cbret in (0,1):
          out.append((3,0,key,0x20000000 if context else 0,1,filter,ctrl,cb,cbret,-23,1))
    return out

def native_line(c):
    if c[0]==0:return f"0 {c[1]} {c[2]}"
    if c[0]==1:return "1 " + " ".join(map(str,c[1:]))
    if c[0]==2:
        _,cfg,match,active,enabled,hook,hret,defresult,wp,lpres=c
        return f"2 {cfg} {match} {wp} {active} {enabled} {hook} {hret} {defresult}"
    _,code,key,lp,running,filter,asyncv,cb,cbret,nextv,hook=c
    return f"3 {code} {key} {lp} {running} {filter} {asyncv} {cb} {cbret} {nextv} {hook}"

def parse_native(line):
    v=list(map(int,line.split())); result,output,key,active,hook,enabled,running,capacity,mapvalue,n=v[:10]
    p=10;events=[]
    for _ in range(n):events.append(v[p:p+5]);p+=5
    return {'result':result,'output':output,'key':key,'active':active,'hook':hook,'enabled':enabled,
      'running':running,'capacity':capacity,'events':events,'keys':v[p:p+256]}

def original_machine(module,data):
    uc=Uc(UC_ARCH_X86,UC_MODE_32);uc.mem_map(BASE,0x300000)
    for s in module['sections']:
        uc.mem_write(BASE+s['rva'],data[s['raw_offset']:s['raw_offset']+s['raw_size']])
    for a,n in ((0x3000000,0x10000),(0x3100000,0x10000),(0x3200000,0x10000)):
        uc.mem_map(a,n)
    for slot,target in API.items():uc.mem_write(slot,struct.pack('<I',target))
    uc.mem_write(0x5de028,bytes(i^0x55 for i in range(256)))
    uc.mem_write(0x3200000,bytes((i*3+7)&255 for i in range(128)))
    events=[];current={}
    def u32(a):return struct.unpack('<I',uc.mem_read(a,4))[0]
    def set32(a,v):uc.mem_write(a,struct.pack('<I',v&0xffffffff))
    def hook(m,ip,size,user):
        if ip==EXIT:m.emu_stop();return
        sp=m.reg_read(UC_X86_REG_ESP)
        specs={0x3000000:('def',4,True),0x3000010:('sethook',4,True),
          0x3000020:('unhook',1,True),0x3000030:('show',1,True),
          0x3000040:('async',1,True),0x3000050:('next',4,True),
          0x53a9e0:('enqueue',3,False),0x3000070:('hotkey',2,False)}
        if ip not in specs:return
        name,n,std=specs[ip];raw=struct.unpack('<'+'I'*(n+1),m.mem_read(sp,4*(n+1)));ret,args=raw[0],list(raw[1:]);result=0
        if name=='def':events.append([4,*args]);result=current['def']
        elif name=='sethook':events.append([1,*args]);result=current['sethook']
        elif name=='unhook':events.append([2,args[0],0,0,0]);result=1
        elif name=='show':events.append([3,args[0],0,0,0]);result=0
        elif name=='async':events.append([5,args[0],0,0,0]);result=current['async']&0xffff
        elif name=='next':events.append([6,*args]);result=current['next']
        elif name=='enqueue':events.append([8,*args,0])
        elif name=='hotkey':events.append([7,*args,0,0]);result=current['cbret']
        m.reg_write(UC_X86_REG_EAX,result&0xffffffff)
        m.reg_write(UC_X86_REG_ESP,sp+4*(n+1) if std else sp+4)
        m.reg_write(UC_X86_REG_EIP,ret)
    uc.hook_add(UC_HOOK_CODE,hook)
    def run(c):
        nonlocal events
        events=[];mode=c[0];uc.mem_write(0x5de028,bytes(i^0x55 for i in range(256)))
        set32(0x6b7bf8,0x1234);set32(0x6b7c14,0);set32(0x69e560,32)
        set32(0x69e5a0,0);set32(0x6bd9dc,0);set32(0x69e584,0);set32(0x69e588,0)
        set32(0x69e58c,0);set32(0x69e590,0x3000070);set32(0x69e5ac,0)
        set32(0x6bd9fc,0xdeadbeef);current.clear();current.update({'def':-17,'sethook':0x55667788,
            'async':0,'next':-23,'cbret':1})
        set32(0x3201100,0xabcdef01)
        args=[];start=0x53b530
        if mode==0:args=[c[1],c[2]]
        elif mode==1:
            _,cfg,match,msg,wp,lp,capacity,mapen,accel=c
            set32(0x69e560,capacity);set32(0x69e5a0,0x3200000 if mapen else 0);set32(0x6bd9dc,accel)
            args=[0x3201000 if cfg else 0,0x1234 if match else 0x9999,msg,wp,lp,0x3201100];start=0x53b450
        elif mode==2:
            _,cfg,match,active,enabled,has_hook,hret,defresult,wp,lpres=c
            set32(0x69e5ac,active);set32(0x69e588,enabled);set32(0x69e584,0x44445555 if has_hook else 0)
            current['sethook']=0x55667788 if hret else 0;current['def']=defresult
            args=[0x3201000 if cfg else 0,0x1234 if match else 0x9999,6,wp,0x12345678,0x3201100];start=0x53b050
        else:
            _,code,key,lp,running,filterv,asyncv,cb,cbret,nextv,has_hook=c
            set32(0x6b7c14,running);set32(0x69e58c,filterv);set32(0x69e590,0x3000070 if cb else 0)
            set32(0x69e584,0x44445555 if has_hook else 0)
            current['async']=asyncv;current['cbret']=cbret;current['next']=nextv
            args=[code,key,lp];start=0x53b150
        words=[EXIT]+[v&0xffffffff for v in args]
        uc.mem_write(STACK,struct.pack('<'+'I'*len(words),*words))
        uc.reg_write(UC_X86_REG_ESP,STACK);uc.reg_write(UC_X86_REG_EIP,start)
        try:uc.emu_start(start,EXIT,count=10000)
        except Exception as e:raise RuntimeError(f'x86 fault at {uc.reg_read(UC_X86_REG_EIP):08x} case={c} events={events}') from e
        if uc.reg_read(UC_X86_REG_EIP)!=EXIT:raise RuntimeError(f'x86 did not return case={c}')
        ret=uc.reg_read(UC_X86_REG_EAX)
        return {'result':ret,'output':u32(0x3201100),'key':u32(0x6bd9fc),'active':u32(0x69e5ac),
          'hook':u32(0x69e584),'enabled':u32(0x69e588),'running':u32(0x6b7c14),
          'capacity':u32(0x69e560),'events':events,'keys':list(uc.mem_read(0x5de028,256))}
    return run

def main():
    ap=argparse.ArgumentParser();ap.add_argument('--probe',type=Path,default=ROOT/'local/builds/v2/run059-window-keys/bin/Release/window_keys_probe.exe')
    ap.add_argument('--report',type=Path,default=RUN/'verification.json');a=ap.parse_args()
    bin_path=ROOT/'local/game/Porsche.exe';data=bin_path.read_bytes()
    if hashlib.sha256(data).hexdigest()!=SHA:raise SystemExit('immutable original SHA mismatch')
    module=next(json.loads(x) for x in (ROOT/'research/binary-index/static/binaries.jsonl').read_text(encoding='utf8').splitlines() if json.loads(x).get('sha256')==SHA)
    cs=cases();inp='\n'.join(native_line(c) for c in cs)+'\n'
    p=subprocess.run([str(a.probe)],input=inp,text=True,capture_output=True,check=True)
    got=[parse_native(x) for x in p.stdout.splitlines()]
    if len(got)!=len(cs):raise SystemExit(f'probe returned {len(got)} records for {len(cs)} cases')
    oracle=original_machine(module,data);failures=[]
    for i,c in enumerate(cs):
        want=oracle(c)
        # The native fixture uses a synthetic table address while the original
        # stores the actual VA. Compare all observed behavior except that address.
        if got[i]!=want:failures.append({'case':c,'native':got[i],'original':want})
    prod=ROOT/'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/window_keys.cpp'
    header=ROOT/'iterations/v2/001-original-recovery/source/include/porsche/window_keys.hpp'
    probe=a.probe.resolve()
    report={'source_binary':'local/game/Porsche.exe','sha256':SHA,
      'binary_index':'research/binary-index/static/binaries.jsonl',
      'production_source_sha256':hashlib.sha256(prod.read_bytes()).hexdigest(),
      'header_sha256':hashlib.sha256(header.read_bytes()).hexdigest(),
      'probe_sha256':hashlib.sha256(probe.read_bytes()).hexdigest(),
      'x86_abi':{'0053b050':'stdcall(6), RET 18','0053b150':'stdcall(3), RET C',
        '0053b450':'stdcall(6), RET 18','0053b530':'cdecl(2), RET'},
      'original_boundaries':['USER32 DefWindowProcA','USER32 SetWindowsHookExA',
        'USER32 UnhookWindowsHookEx','USER32 ShowCursor','USER32 GetAsyncKeyState',
        'USER32 CallNextHookEx','0069e590 optional cdecl dispatch',
        '0069e5a0 scan-code translation owner','0053a9e0 input queue insertion'],
      'caller_evidence':{'0053ac20':'registers 0053b050 and 0053b450 for the key messages',
        '0053b050':'installs callback 0053b150 through SetWindowsHookExA',
        '0053b450':'calls 0053b530 and/or queue insertion 0053a9e0',
        '0053b8d0':'calls 0053b530 before TranslateMessage'},
      'function_vas':['0053b050','0053b150','0053b450','0053b530'],
      'full_function_vas':['0053b050','0053b150','0053b450','0053b530'],'partial_function_vas':[],
      'cases':len(cs),'passed':len(cs)-len(failures),'failed':len(failures),
      'result':'pass' if not failures else 'fail','first_failures':failures[:5]}
    report['schema']=1
    report['native_cpp_equal_original_x86']=not failures
    report['binary_matched']=False
    report['game_launch_verified']=False
    report['source_sha256']=source_hashes(['scripts/research/verify-v2-window-keys.py','iterations/v2/001-original-recovery/runs/059-window-keys/CMakeLists.txt','iterations/v2/001-original-recovery/runs/059-window-keys/README.md'],compiled_sources=['iterations/v2/001-original-recovery/source/recovered/Porsche.exe/window_keys.cpp','iterations/v2/001-original-recovery/source/recovered/window_keys_probe.cpp'])
    a.report.parent.mkdir(parents=True,exist_ok=True);a.report.write_text(json.dumps(report,indent=2)+'\n',encoding='utf8')
    print(json.dumps({k:report[k] for k in ('cases','passed','failed','result')},indent=2))
    if failures:sys.exit(1)
if __name__=='__main__':main()
