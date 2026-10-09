from v2_source_dependencies import source_hashes
"""Compare Porsche.exe 0x53ac20 registration prefix with native x86 C++."""
import argparse
import hashlib
import json
from pathlib import Path
import struct
import subprocess
import sys

ROOT=Path(__file__).resolve().parents[2]
RUN=ROOT/'iterations/v2/001-original-recovery/runs/029-window-create'
sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ESP,UC_X86_REG_EIP

STACK,EXIT=0x3108000,0x3000100
ENDPOINTS={0x5321f0:(0x3000000,'lock',0,False),
           0x5b2138:(0x3000010,'module',1,True),
           0x5b2308:(0x3000020,'icon',2,True),
           0x5b230c:(0x3000030,'cursor',2,True),
           0x5b2040:(0x3000040,'stock',1,True),
           0x5b2310:(0x3000050,'register',1,True),
           0x5b213c:(0x3000060,'last_error',0,True),
           0x5debf0:(0x3000070,'diagnostic',2,False)}

def cases():return [(previous,lock,name,success) for previous in (0,1,3)
                    for lock in (0,1) for name in (0,1,2) for success in (0,1)]

def original(module,data,case,full=False):
    previous,lock,name,success=case[:4]
    uc=Uc(UC_ARCH_X86,UC_MODE_32);base=int(module['image_base'],16)
    uc.mem_map(base,0x300000)
    for section in module['sections']:
        uc.mem_write(base+section['rva'],data[section['raw_offset']:section['raw_offset']+section['raw_size']])
    uc.mem_map(0x3000000,0x1000);uc.mem_map(0x3100000,0x10000)
    uc.mem_map(0x3200000,0x10000)
    def put(addr,value):uc.mem_write(addr,struct.pack('<I',value&0xffffffff))
    def word(addr):return struct.unpack('<I',uc.mem_read(addr,4))[0]
    def cstr(addr):
        if not addr:return ''
        return bytes(uc.mem_read(addr,100)).split(b'\0')[0].decode('latin1')
    uc.mem_write(0x3200010,b'Porsche\0');uc.mem_write(0x3200020,b'Override\0')
    put(0x3200030,0x3200020)
    put(0x69e59c,0x2220000 if lock else 0)
    put(0x69e594,previous)
    put(0x69e5a8,0x3200010 if name==1 else 0)
    put(0x6afcc0,0x3200030 if name==2 else 0)
    for addr in (0x6b7794,0x5deb74,0x5deb78):put(addr,0)
    if full:
        handlers_registered,prior_hwnd,thread_success,fullscreen,width,height=case[4:]
        for addr,value in ((0x69e598,handlers_registered),(0x69e564,0),(0x69e560,0),
                           (0x69e0d8,0),(0x69e568,0),(0x6b7c14,0),
                           (0x6b77b4,0),(0x6b77b8,0),(0x69e574,0),
                           (0x6b7bf8,0x1230000 if prior_hwnd else 0),
                           (0x69e57c,0),(0x69e580,0)):put(addr,value)
        uc.mem_write(0x6b7c01,b'\0');uc.mem_write(0x6bd9e0,b'\0'*28)
    for address,(target,_,_,_) in ENDPOINTS.items():
        if address!=0x5321f0:put(address,target)
    handlers={target:(label,argc,stdcall) for target,label,argc,stdcall in ENDPOINTS.values()}
    handlers[0x5321f0]=('lock',0,False)
    if full:
        direct={0x53a800:('handler',2),0x53bec0:('resize',2),0x55f420:('thread_start',5),
                0x5366e0:('tick',1),0x55f740:('idle',1),0x53bcb0:('prepare',0),
                0x55fb30:('wait',1)}
        handlers.update({address:(label,argc,address==0x53a800) for address,(label,argc) in direct.items()})
        for iat,target,label,argc in ((0x5b2300,0x3000080,'foreground',1),
                                       (0x5b2314,0x3000090,'spi',4)):
            put(iat,target);handlers[target]=(label,argc,True)
    calls=[]
    def hook(machine,p,size,user):
        if p==EXIT:machine.emu_stop();return
        if p not in handlers:return
        label,argc,stdcall=handlers[p]
        sp=machine.reg_read(UC_X86_REG_ESP)
        ret,*args=struct.unpack('<'+'I'*(argc+1),machine.mem_read(sp,4*(argc+1)))
        result=0
        if label=='lock':calls.append(['lock']);result=0x2220000
        elif label=='module':calls.append(['module']);result=0x1234000
        elif label=='icon':calls.append(['icon',*args]);result=0x1235000
        elif label=='cursor':calls.append(['cursor',*args]);result=0x1236000
        elif label=='stock':calls.append(['stock',*args]);result=0x1237000
        elif label=='register':
            fields=struct.unpack('<10I',machine.mem_read(args[0],40))
            if fields[1]!=0x53aba0:raise RuntimeError(f'Unexpected WndProc {fields[1]:08x}')
            calls.append(['register',fields[0],'wndproc',*fields[2:8],cstr(fields[8]),cstr(fields[9])])
            result=1 if success else 0
        elif label=='last_error':calls.append(['last_error']);result=0xdead
        elif label=='diagnostic':calls.append(['diagnostic',cstr(args[0]),args[1]])
        elif label=='handler':calls.append(['handler',*args])
        elif label=='resize':calls.append(['resize',*args])
        elif label=='thread_start':
            if args[:4]!=[0x53b8d0,0,1,0xffffffff]:raise RuntimeError(f'Unexpected worker launch {args}')
            calls.append(['thread_start','worker',*args[1:4]])
            if thread_success:
                for i in range(7):put(args[4]+4*i,0x100+i)
                put(0x69e574,0x1238000);put(0x6b7bf8,0x1230000)
                result=1
        elif label=='tick':calls.append(['tick',*args])
        elif label=='idle':calls.append(['idle',*args])
        elif label=='prepare':calls.append(['prepare'])
        elif label=='wait':calls.append(['wait',*args]);put(0x69e574,0)
        elif label=='foreground':calls.append(['foreground',*args]);result=args[0]
        elif label=='spi':
            calls.append(['spi',args[0],args[1],int(args[2]!=0),args[3]])
            if args[2]:put(args[2],1 if args[0]==0x10 else 0)
            result=1
        machine.reg_write(UC_X86_REG_EAX,result)
        machine.reg_write(UC_X86_REG_ESP,sp+4*(argc+1) if stdcall else sp+4)
        machine.reg_write(UC_X86_REG_EIP,ret)
    uc.hook_add(UC_HOOK_CODE,hook)
    put(STACK,EXIT)
    if full:
        put(STACK+4,width);put(STACK+8,height);put(STACK+12,fullscreen)
    uc.reg_write(UC_X86_REG_ESP,STACK)
    try:uc.emu_start(0x53ac20,EXIT if full else 0x53ad23,count=1500 if full else 500)
    except Exception as exc:raise RuntimeError(f'registration x86 fault at {uc.reg_read(UC_X86_REG_EIP):08x} sp {uc.reg_read(UC_X86_REG_ESP):08x} calls={calls[-5:]}') from exc
    at=uc.reg_read(UC_X86_REG_EIP)
    if at not in ((EXIT,) if full else (0x53ad23,EXIT)):raise RuntimeError(f'registration ended {at:08x}')
    output={'result':uc.reg_read(UC_X86_REG_EAX) if full else (1 if at==0x53ad23 else 0),
            'refcount':word(0x69e594),
            'lock':word(0x69e59c),'instance':word(0x6b7794),'name':cstr(word(0x69e5a8)),
            'error_file':word(0x5deb74),'error_line':word(0x5deb78),'calls':calls}
    if full:
        output.update({'handlers':word(0x69e598),'input_lock':word(0x69e564),
            'input_capacity':word(0x69e560),'running':word(0x6b7c14),
            'width':word(0x6b77b4),'height':word(0x6b77b8),
            'fullscreen':bytes(uc.mem_read(0x6b7c01,1))[0],
            'thread':word(0x69e574),'hwnd':word(0x6b7bf8),
            'saved':[word(0x69e57c),word(0x69e580)],
            'worker_state':[word(0x6bd9e0+4*i) for i in range(7)]})
    return output

def main():
    parser=argparse.ArgumentParser()
    parser.add_argument('--probe',type=Path,default=ROOT/'local/builds/v2/001-original-recovery/bin/Release/window_create_probe.exe')
    parser.add_argument('--report',type=Path,default=RUN/'verification.json')
    parser.add_argument('--limit',type=int,default=0)
    args=parser.parse_args()
    module=next(x for x in map(json.loads,(ROOT/'research/binary-index/static/binaries.jsonl').read_text(encoding='utf8').splitlines()) if x['file']=='Porsche.exe')
    data=(ROOT/'local/game'/module['path']).read_bytes()
    sha='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
    if hashlib.sha256(data).hexdigest()!=sha or module['sha256']!=sha:raise RuntimeError('Original SHA mismatch')
    selected=cases()[:args.limit or None]
    native=subprocess.run([str(args.probe)],input='\n'.join(' '.join(map(str,c)) for c in selected)+'\n',text=True,capture_output=True,check=True,timeout=30)
    rows=list(map(json.loads,native.stdout.splitlines()))
    if len(rows)!=len(selected):raise RuntimeError('Native row count mismatch')
    for i,(case,actual) in enumerate(zip(selected,rows)):
        expected=original(module,data,case)
        if actual!=expected:raise RuntimeError(f'Case {i} differs: {case}; original={expected}; native={actual}')
    full_cases=[(0,0,1,1,0,0,1,0,640,480),(0,0,1,1,0,0,1,1,640,480),
                (0,0,1,0,0,0,1,0,640,480),(1,1,1,1,1,0,1,1,800,600),
                (1,1,1,1,1,1,1,1,800,600),(0,0,1,1,0,0,0,0,640,480)]
    full_cases=full_cases[:args.limit or None]
    native_full=subprocess.run([str(args.probe),'--full'],
        input='\n'.join(' '.join(map(str,c)) for c in full_cases)+'\n',
        text=True,capture_output=True,check=True,timeout=30)
    full_rows=list(map(json.loads,native_full.stdout.splitlines()))
    if len(full_rows)!=len(full_cases):raise RuntimeError('Full row count mismatch')
    for i,(case,actual) in enumerate(zip(full_cases,full_rows)):
        expected=original(module,data,case,True)
        if actual!=expected:raise RuntimeError(f'Full case {i} differs: {case}; original={expected}; native={actual}')
    print(json.dumps({'prefix_cases':len(selected),'full_cases':len(full_cases),
                      'range':'0053ac20..0053b03f','native_cpp_equal_original_x86':True}))
    if args.limit:return
    paths=['iterations/v2/001-original-recovery/source/include/porsche/window_create.hpp',
           'iterations/v2/001-original-recovery/source/include/porsche/window_state.hpp',
           'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/window_create.cpp',
           'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/window_state.cpp',
           'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/window_init.cpp',
           'iterations/v2/001-original-recovery/source/recovered/window_create_probe.cpp',
           'scripts/research/verify-v2-window-create.py']
    # Pin every compiled translation unit and its owned transitive headers.
    import re
    owned=ROOT/'iterations/v2/001-original-recovery/source'
    pending=[owned/'recovered/Porsche.exe'/x for x in ['window_create.cpp', 'window_init.cpp']]
    seen=set()
    while pending:
        path=pending.pop()
        if path in seen:continue
        seen.add(path)
        for inc in re.findall(r'#include "(porsche/[^"]+)"',path.read_text(encoding='utf8')):
            pending.append(owned/'include'/inc)
    paths=sorted(set(paths)|{p.relative_to(ROOT).as_posix() for p in seen})
    report={'schema':1,'sha256':sha,'range':'0053ac20..0053b03f',
            'scope':'full 0053ac20 with typed worker, window and input boundaries',
            'function_vas':['0053ac20'],'prefix_cases':len(selected),'full_cases':len(full_cases),'native_cpp_equal_original_x86':True,
            'binary_matched':False,'game_launch_verified':False,
            'source_sha256':{p:hashlib.sha256((ROOT/p).read_bytes().replace(b'\r\n',b'\n')).hexdigest() for p in paths},
            'probe_sha256':hashlib.sha256(args.probe.read_bytes()).hexdigest()}
    report['function_vas']=['0053ac20']
    report['source_sha256']=source_hashes(report['source_sha256'].keys(),compiled_sources=['iterations/v2/001-original-recovery/source/recovered/Porsche.exe/window_create.cpp', 'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/window_init.cpp', 'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/window_callback_bindings.cpp', 'iterations/v2/001-original-recovery/source/recovered/window_create_probe.cpp'])
    args.report.parent.mkdir(parents=True,exist_ok=True)
    args.report.write_text(json.dumps(report,indent=2)+'\n',encoding='utf8')

if __name__=='__main__':main()
