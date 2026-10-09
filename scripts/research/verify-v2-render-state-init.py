import argparse
from v2_source_dependencies import source_hashes
#!/usr/bin/env python3
import hashlib, json, struct, subprocess, sys
from pathlib import Path

ROOT=Path(__file__).resolve().parents[2]
ITER=ROOT/'iterations/v2/001-original-recovery'
RUN=ITER/'runs/071-render-state-init'
SHA='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_EIP,UC_X86_REG_ESP

STACK,EXIT=0x3101000,0x3200000
SETSTATE,CLOCK=0x3300000,0x3300010

def put(u,a,v):u.mem_write(a,struct.pack('<I',v&0xffffffff))
def get(u,a):return struct.unpack('<I',u.mem_read(a,4))[0]

def case(seed,setting80,setting60,setting68,a8,clock):
    return dict(seed=seed,setting80=setting80&0xffffffff,setting60=setting60&0xffffffff,
        setting68=setting68&0xffffffff,a8=a8&255,clock=clock&0xffffffff)

def cases():
    return [
        case(1,0,0,0,0,0x12345678),
        case(2,25,1,1,1,0),
        case(3,26,2,2,0,0xffffffff),
        case(4,100,0xffffffff,0xffffffff,1,0x87654321),
        case(5,0x7fffffff,1,0,1,0x01020304),
        case(6,0x80000000,0,1,0,0xaabbccdd),
        case(7,0xffffffff,2,0x7fffffff,1,42),
        case(0x5a,1,0x80000000,0x80000000,0,0xdeadbeef),
        case(0xa5,0x7fffff00,3,0xfffffffe,0x80,0x0badcafe),
        case(0x3c,50,0,0x7fffffff,1,0x76543210),
        case(0xc3,0x80000001,0,0,1,0x89abcdef),
        case(0xff,0xffffffff,1,1,0,0x13579bdf),
    ]

def module_data():
    entries=[json.loads(x) for x in (ROOT/'research/binary-index/static/binaries.jsonl').read_text(encoding='utf8').splitlines()]
    m=next(x for x in entries if x['file']=='Porsche.exe')
    data=(ROOT/'local/game'/m['path']).read_bytes()
    if hashlib.sha256(data).hexdigest()!=SHA:raise RuntimeError('original binary SHA mismatch')
    return m,data

def original(m,data,c):
    u=Uc(UC_ARCH_X86,UC_MODE_32);u.mem_map(0x400000,0x300000)
    for sec in m['sections']:
        if sec['raw_size']:u.mem_write(0x400000+sec['rva'],data[sec['raw_offset']:sec['raw_offset']+sec['raw_size']])
    u.mem_map(0x3100000,0x10000);u.mem_map(EXIT,0x1000);u.mem_map(0x3300000,0x1000)
    u.mem_write(EXIT,b'\xc3'*0x1000)
    put(u,0x6bd918,SETSTATE)
    # Clock is a direct-call boundary; route its entry through an explicit stub.
    u.mem_write(0x555bc0,b'\xe9'+struct.pack('<i',CLOCK-(0x555bc0+5)))
    put(u,0x657d80,c['setting80']);put(u,0x657d60,c['setting60']);put(u,0x657d68,c['setting68'])
    put(u,0x5ce908,c['seed']^0x11223344);put(u,0x5deb1c,c['seed']^0x55667788)
    put(u,0x69dd1d,c['seed'])
    u.mem_write(0x619790,bytes([c['seed']&255])*0x71)
    u.mem_write(0x6197a8,bytes([c['a8']]))
    events=[]
    def hook(mu,addr,_size,_):
        if addr not in (SETSTATE,CLOCK,0x535b40):return
        sp=mu.reg_read(UC_X86_REG_ESP);ret=get(mu,sp)
        if addr==SETSTATE:
            key,value=get(mu,sp+4),get(mu,sp+8)
            events.append(['setstate',key,value])
            mu.reg_write(UC_X86_REG_ESP,sp+12);mu.reg_write(UC_X86_REG_EIP,ret)
        elif addr==CLOCK:
            events.append(['clock',0,c['clock']])
            mu.reg_write(UC_X86_REG_EAX,c['clock'])
            mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
        else:
            events.append(['option',get(mu,sp+4),0])
    u.hook_add(UC_HOOK_CODE,hook)
    put(u,STACK,EXIT);u.reg_write(UC_X86_REG_ESP,STACK)
    try:u.emu_start(0x44f020,EXIT,count=100000)
    except Exception as exc:raise RuntimeError(f"original x86 failed for {c}: EIP={u.reg_read(UC_X86_REG_EIP):08x}; calls={events}") from exc
    return {'state':list(u.mem_read(0x619790,0x71)),
        'time':[get(u,0x5ce908),get(u,0x5deb1c)],'option':u.mem_read(0x69dd1d,1)[0],
        'calls':events,'stack_delta':u.reg_read(UC_X86_REG_ESP)-STACK}

def main():
    parser=argparse.ArgumentParser()
    parser.add_argument('--probe',type=Path,default=ROOT/'local/builds/v2/001-original-recovery/bin/Release/render_state_init_probe.exe')
    parser.add_argument('--report',type=Path,default=RUN/'verification.json')
    args=parser.parse_args();probe=args.probe
    m,data=module_data();inputs=cases()
    feed=''.join(' '.join(str(c[k]) for k in ('seed','setting80','setting60','setting68','a8','clock'))+'\n' for c in inputs)
    proc=subprocess.run([str(probe)],input=feed,text=True,capture_output=True,check=True)
    rows=proc.stdout.splitlines()
    if len(rows)!=len(inputs):raise RuntimeError(f'probe rows {len(rows)} != cases {len(inputs)}; stderr={proc.stderr}')
    fixtures=[]
    for c,line in zip(inputs,rows):
        native=json.loads(line);expect=original(m,data,c)
        if expect['stack_delta']!=4:raise RuntimeError(f"original cdecl stack delta {c}: {expect['stack_delta']}")
        if native!={k:v for k,v in expect.items() if k!='stack_delta'}:
            raise RuntimeError(f'case {c}: original={expect}; native={native}')
        fixtures.append({'input':c,'output':native,'original_stack_delta':expect['stack_delta']})
    rel=lambda x:x.relative_to(ROOT).as_posix()
    deps=[ITER/'source/include/porsche/render_state_init.hpp',ITER/'source/include/porsche/render_mode.hpp',
      ITER/'source/include/porsche/render_display.hpp',ITER/'source/recovered/Porsche.exe/render_state_init.cpp',
      ITER/'source/recovered/render_state_init_probe.cpp',RUN/'CMakeLists.txt',RUN/'README.md',
      ROOT/'research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm',
      ROOT/'research/v2/binaries/Porsche.exe-ddd748fdbe6d/decompiled.c',Path(__file__).resolve()]
    report={'schema':1,'binary':'Porsche.exe','sha256':SHA,'entry_va':'0044f020',
      'coverage':'complete caller-visible state effects of 0x44f020; original EAX is ignored by caller',
      'full_function_vas':['0044f020'],'partial_function_vas':[],'cases':len(inputs),
      'native_cpp_equal_original_x86':True,'game_launch_verified':False,
      'boundaries':'IAT 0x6bd918 is a two-DWORD stdcall state setter; direct 0x555bc0 is a cdecl/no-argument clock; 0x535b40 is executed from original x86 and verified in Run063 as a low-byte store. Canonical state/settings/time globals reuse Run063 owners; probe definitions are isolated stand-ins.',
      'source_sha256':{rel(p):hashlib.sha256(p.read_bytes().replace(b'\r\n',b'\n')).hexdigest() for p in deps},
      'probe_sha256':hashlib.sha256(probe.read_bytes()).hexdigest(),'fixtures':fixtures}
    report['source_sha256']=source_hashes(deps,compiled_sources=[ITER/'source/recovered/Porsche.exe/render_state_init.cpp',ITER/'source/recovered/render_state_init_probe.cpp',ITER/'source/recovered/Porsche.exe/application_state.cpp',ITER/'source/recovered/Porsche.exe/application_globals.cpp'])
    out=args.report;out.parent.mkdir(parents=True,exist_ok=True)
    out.write_text(json.dumps(report,indent=2)+'\n',encoding='utf8')
    print(f'verified {len(inputs)} full-state/call-order renderer alternate-init cases; report {rel(out)}')
if __name__=='__main__':main()
