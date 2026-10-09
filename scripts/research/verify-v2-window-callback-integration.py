from v2_source_dependencies import source_hashes
"""Compare callback registration and representative WndProc traffic to Porsche.exe x86."""
import argparse,hashlib,json,re,struct,subprocess,sys
from pathlib import Path

ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
RUN=ROOT/'iterations/v2/001-original-recovery/runs/065-window-callback-integration'
SHA='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
ASM=ROOT/'research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm'
STACK=0x3108000;EXIT=0x3010000;IMAGE=0x400000
REGION_CASES=[(6,1,0),(5,0,(480<<16)|640),(0x100,0x70,(0x2a<<16)|2),
              (0x201,1,(22<<16)|13),(0xf,0,0),(0x10,0,0)]
VA_LINE=re.compile(r'^([0-9a-fA-F]{8})\s+\S+\s+(.*)$')
PUSH=re.compile(r'PUSH\s+(?:0x(?P<hex>[0-9a-fA-F]+)|(?P<dec>-?\d+))')

def registrations():
    rows=[];pending=[]
    for line in ASM.read_text(encoding='utf8').splitlines():
        m=VA_LINE.match(line)
        if not m:continue
        va=int(m[1],16);text=m[2]
        if not 0x53ad35<=va<0x53aecf:continue
        p=PUSH.search(text)
        if p:pending.append((int(p['hex'],16) if p['hex'] is not None else int(p['dec']))&0xffffffff)
        if 'CALL 0x0053a800' in text:
            rows.append((pending[-1],pending[-2]));pending.clear()
    if len(rows)!=27:raise RuntimeError(f'original registration block has {len(rows)} entries')
    return rows

def original_machine(module,binary):
    from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
    from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ESP,UC_X86_REG_EIP
    uc=Uc(UC_ARCH_X86,UC_MODE_32);uc.mem_map(IMAGE,0x300000)
    for sec in module['sections']:
        uc.mem_write(IMAGE+sec['rva'],binary[sec['raw_offset']:sec['raw_offset']+sec['raw_size']])
    for a,n in ((0x3000000,0x10000),(0x3100000,0x10000),(0x3200000,0x10000)):uc.mem_map(a,n)
    iat={0x5b2318:0x3000000,0x5b22cc:0x3000010,0x5b2304:0x3000020,
      0x5b2278:0x3000030,0x5b22f4:0x3000040,0x5b22f0:0x3000050,
      0x5b231c:0x3000060,0x5b2300:0x3000070,0x5b22e8:0x3000080,0x5b22ec:0x3000090}
    for p,v in iat.items():uc.mem_write(p,struct.pack('<I',v))
    def word(addr):return struct.unpack('<I',uc.mem_read(addr,4))[0]
    def set32(addr,value):uc.mem_write(addr,struct.pack('<I',value&0xffffffff))
    def signed(addr):return struct.unpack('<i',uc.mem_read(addr,4))[0]
    def read_entries(base,n):return [struct.unpack('<II',uc.mem_read(base+i*8,8)) for i in range(n)]
    events=[];api_result=-77
    specs={0x3000000:('def',4,True),0x3000010:('sethook',4,True),
      0x3000020:('unhook',1,True),0x3000030:('show',1,True),0x3000040:('quit',1,True),
      0x3000050:('getrect',2,True),0x3000060:('toscreen',2,True),
      0x3000070:('foreground',1,True),0x3000080:('beginpaint',2,True),0x3000090:('endpaint',2,True),
      0x5322b0:('pump',1,False),0x5322c0:('dispatch',1,False),0x5a112b:('sort',4,False),
      0x53a9e0:('enqueue',3,False),0x5728b0:('mouse',4,False),0x30000a0:('resizecheck',0,False)}
    def api_hook(m,ip,size,user):
        nonlocal events
        if ip==EXIT:m.emu_stop();return
        if ip not in specs:return
        name,n,std=specs[ip];sp=m.reg_read(UC_X86_REG_ESP)
        raw=struct.unpack('<'+'I'*(n+1),m.mem_read(sp,(n+1)*4));ret,args=raw[0],list(raw[1:]);result=0
        if name=='def':events.append([5,*args]);result=api_result
        elif name=='sethook':events.append([6,args[0],args[1],args[2],args[3]]);result=0x5555
        elif name=='unhook':events.append([7,args[0],0,0,0]);result=1
        elif name=='show':events.append([8,args[0],0,0,0]);result=0
        elif name=='quit':events.append([4,args[0],0,0,0])
        elif name=='getrect':
            events.append([9,args[0],0,0,0]);m.mem_write(args[1],struct.pack('<4i',0,0,640,480));result=1
        elif name=='toscreen':
            events.append([10,args[0],0,0,0]);m.mem_write(args[1],struct.pack('<2i',10,20));result=1
        elif name=='foreground':events.append([17,args[0],0,0,0]);result=args[0]
        elif name=='beginpaint':events.append([15,args[0],0,0,0]);result=1
        elif name=='endpaint':events.append([16,args[0],0,0,0]);result=1
        elif name=='pump':events.append([1,args[0],0,0,0])
        elif name=='dispatch':events.append([3,args[0],0,0,0])
        elif name=='sort':
            base,count,width,compare=args;events.append([2,count,width,0,0])
            if width!=8:raise RuntimeError(f'unexpected qsort element width {width}')
            entries=read_entries(base,count);entries.sort(key=lambda x:x[0])
            for i,e in enumerate(entries):m.mem_write(base+i*8,struct.pack('<II',*e))
        elif name=='enqueue':events.append([13,*args,0])
        elif name=='mouse':events.append([14,*args])
        elif name=='resizecheck':events.append([11,0,0,0,0]);result=0
        m.reg_write(UC_X86_REG_EAX,result&0xffffffff)
        m.reg_write(UC_X86_REG_ESP,sp+4*(n+1) if std else sp+4)
        m.reg_write(UC_X86_REG_EIP,ret)
    uc.hook_add(UC_HOOK_CODE,api_hook)
    def call(start,args):
        words=[EXIT]+[x&0xffffffff for x in args]
        uc.mem_write(STACK,struct.pack('<'+'I'*len(words),*words))
        uc.reg_write(UC_X86_REG_ESP,STACK);uc.reg_write(UC_X86_REG_EIP,start)
        try:uc.emu_start(start,EXIT,count=80000)
        except Exception as e:raise RuntimeError(f'x86 fault {uc.reg_read(UC_X86_REG_EIP):08x}, fn={start:08x}, args={args}, events={events[-8:]}') from e
        if uc.reg_read(UC_X86_REG_EIP)!=EXIT:raise RuntimeError(f'x86 function did not return {start:08x}')
        return uc.reg_read(UC_X86_REG_EAX)
    # Initialize original shared window fixture, then execute the exact original
    # handler registrar for every PUSH pair from 0053ac20.
    uc.mem_write(0x6b77a0,b'\0'*0x478);set32(0x6b7bf8,0x1234)
    set32(0x6b7c14,1);uc.mem_write(0x6b7c01,b'\0')
    set32(0x69e59c,0x7777);set32(0x69e0e0,0);set32(0x69e570,0)
    set32(0x69e560,8);set32(0x69e5a0,0);set32(0x6bd9dc,0)
    set32(0x69e588,1);set32(0x69e584,0);set32(0x69e5ac,0);set32(0x69e58c,0)
    set32(0x69e590,0);set32(0x69e578,0);set32(0x6a57d8,0x8888)
    uc.mem_write(0x5de028,b'\0'*256);set32(0x5df9b8,0x30000a0)
    rows=registrations();events=[]
    for msg,va in rows:call(0x53a800,[msg,va])
    registration_events=events[:]
    table=[[m,va] for m,va in read_entries(0x69e0e0,word(0x69e570))]
    dispatches=[]
    for msg,wp,lp in REGION_CASES:
        events=[];result=call(0x53aba0,[0x1234,msg,wp,lp])
        state=[word(0x6b7c14),word(0x69e578),signed(0x6b7c08),signed(0x6b7c0c),
          word(0x69e5ac),word(0x69e584)]+list(uc.mem_read(0x5de028,256))
        dispatches.append({'message':msg,'result':result if result<0x80000000 else result-0x100000000,'events':events,'state':state})
    return {'registrations':table,'registration_events':registration_events,'dispatches':dispatches}

def main():
    ap=argparse.ArgumentParser();ap.add_argument('--probe',type=Path,default=ROOT/'local/builds/v2/run065-window-callback-integration/bin/Release/window_callback_integration_probe.exe')
    ap.add_argument('--report',type=Path,default=RUN/'verification.json');args=ap.parse_args()
    binary=ROOT/'local/game/Porsche.exe'
    digest=hashlib.sha256(binary.read_bytes()).hexdigest()
    if digest!=SHA:raise SystemExit('immutable original SHA mismatch')
    module=next(json.loads(x) for x in (ROOT/'research/binary-index/static/binaries.jsonl').read_text(encoding='utf8').splitlines() if json.loads(x).get('sha256')==SHA)
    rows=registrations();data=[value for row in rows for value in row]
    inp=str(len(rows))+'\n'+'\n'.join(map(str,data))+'\n'+str(len(REGION_CASES))+'\n'+'\n'.join(
      f'{m} {w} {lp}' for m,w,lp in REGION_CASES)+'\n'
    native=subprocess.run([str(args.probe)],input=inp,text=True,capture_output=True,check=True)
    got=json.loads(native.stdout);want=original_machine(module,binary.read_bytes())
    unknown=subprocess.run([str(args.probe)],input='1\n1911 5505023\n0\n',text=True,capture_output=True,check=True)
    unknown_result=json.loads(unknown.stdout)
    if unknown_result!={'error':'unresolved callback','va':5505023}:
        raise SystemExit(f'unknown callback was not rejected explicitly: {unknown_result}')
    if got!=want:
        for key in ('registrations','registration_events','dispatches'):
            if got.get(key)!=want.get(key):
                if key=='registrations':
                    raise SystemExit(f'registration mismatch: native={got[key][:6]} original={want[key][:6]}')
                if key=='dispatches':
                    for i,(a,b) in enumerate(zip(got[key],want[key])):
                        if a!=b:
                            diffs={k:(a.get(k),b.get(k)) for k in a if a.get(k)!=b.get(k)}
                            raise SystemExit(f'differential mismatch {key}[{i}] message={a.get("message")}: {diffs}')
                raise SystemExit(f'differential mismatch in {key}')
        raise SystemExit('native/original differential mismatch')
    prod=ROOT/'iterations/v2/001-original-recovery/source/recovered/Porsche.exe'
    hashes={name:hashlib.sha256((prod/(name+'.cpp')).read_bytes()).hexdigest()
      for name in ('window_callback_bindings','window_handlers','window_procedure','window_messages','window_keys')}
    binding_report=ROOT/'iterations/v2/001-original-recovery/runs/064-window-callback-bindings/verification.json'
    bind=json.loads(binding_report.read_text(encoding='utf8'))
    full_vas=sorted(bind['full_function_abis'])
    if len(full_vas)!=16 or bind.get('unresolved_callback_vas'):
        raise SystemExit('Run064 does not prove all registered callback bodies and ABIs')
    dispatch_snapshots=[]
    for item in got['dispatches']:
        state=item['state']
        dispatch_snapshots.append({'message':f"0x{item['message']:04x}",
          'return':item['result'],'events':item['events'],
          'state':state[:6],
          'nonzero_virtual_keys':[[i,value] for i,value in enumerate(state[6:]) if value]})
    report={'source_binary':'local/game/Porsche.exe','sha256':SHA,
      'original_registration_consumer':'0053ac20 / 0053ad35..0053aecf',
      'registration_count':len(rows),'unique_callback_count':len({va for _,va in rows}),
      'function_vas':full_vas,'full_function_vas':full_vas,'partial_function_vas':[],
      'dispatch_messages':[f'0x{m:04x}' for m,_,_ in REGION_CASES],
      'production_sources_sha256':hashes,'registrations':len(got['registrations']),
      'registration_events':len(got['registration_events']),'dispatches':len(got['dispatches']),
      'registration_table':got['registrations'],'registration_boundary_events':got['registration_events'],
      'dispatch_results_and_traces':dispatch_snapshots,
      'run064_abi_evidence_sha256':hashlib.sha256(binding_report.read_bytes()).hexdigest(),
      'unknown_va':'0x0053ffff rejected before registration; no fallback callback',
      'boundary_policy':'Win32 and game services recorded as explicit typed boundaries; qsort replacement covers valid unique startup IDs only',
      'unresolved_callbacks':[],'result':'pass'}
    report['probe_sha256']=hashlib.sha256(args.probe.resolve().read_bytes()).hexdigest()
    report['schema']=1
    report['native_cpp_equal_original_x86']=True
    report['game_launch_verified']=False
    report['binary_matched']=False
    report['cases']=len(REGION_CASES)
    report['source_sha256']=source_hashes(['scripts/research/verify-v2-window-callback-integration.py', 'iterations/v2/001-original-recovery/runs/065-window-callback-integration/CMakeLists.txt', 'iterations/v2/001-original-recovery/runs/065-window-callback-integration/README.md', 'iterations/v2/001-original-recovery/runs/064-window-callback-bindings/verification.json'],compiled_sources=['iterations/v2/001-original-recovery/source/recovered/Porsche.exe/window_callback_bindings.cpp', 'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/window_handlers.cpp', 'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/window_procedure.cpp', 'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/window_messages.cpp', 'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/window_keys.cpp', 'iterations/v2/001-original-recovery/source/recovered/window_callbacks_integration_probe.cpp'])
    args.report.parent.mkdir(parents=True,exist_ok=True);args.report.write_text(json.dumps(report,indent=2)+'\n',encoding='utf8')
    print(json.dumps({'registrations':len(rows),'dispatches':len(REGION_CASES),'result':'pass'},indent=2))
if __name__=='__main__':main()
