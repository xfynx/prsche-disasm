import argparse
from v2_source_dependencies import source_hashes
#!/usr/bin/env python3
import hashlib, json, struct, subprocess, sys
from pathlib import Path

ROOT=Path(__file__).resolve().parents[2]
ITER=ROOT/'iterations/v2/001-original-recovery'
RUN=ITER/'runs/073-render-state-integration'
SHA='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ECX,UC_X86_REG_EIP,UC_X86_REG_ESP

STACK,EXIT,DISPLAY,DRIVER,VTABLE,DEVICE,RECORDS,OUT=0x3101000,0x3200000,0x3104000,0x3105000,0x3108000,0x3107000,0x3106000,0x3109000
MODESET,DEVICE_API,GET,SET,CONFIG,CLOCK,VIRTUAL=0x3300000,0x3300010,0x3300020,0x3300030,0x3300040,0x3300050,0x3300060

def put(u,a,v):u.mem_write(a,struct.pack('<I',v&0xffffffff))
def get(u,a):return struct.unpack('<I',u.mem_read(a,4))[0]
def signed(v):return struct.unpack('<i',struct.pack('<I',v&0xffffffff))[0]

def make_case(seed,**kw):
    c=dict(index=seed%4,fullscreen=0,alternate=0,seed=seed,clock=0x12340000+seed,
      device_id=0x12345678,flags=0x20,min_a=640,min_b=800,field44=0x11223344,
      device_type=0,surface=0x600000,global_value=0,trident=0,voodoo=0,
      setting5c=0,setting60=seed%3,setting68=seed%4,setting6c=seed%4,
      setting70=seed%4,setting78=seed%2,setting80=seed*10)
    c.update(kw);c['gets']=[(seed*0x101+i*13)&0xffffffff for i in range(11)]
    c['sets']=[(seed+i*7)&1 for i in range(24)]
    return c

def cases():
    return [
      make_case(1,alternate=1,setting60=0,setting68=0,setting6c=3,setting70=0,setting78=1,setting80=0),
      make_case(2,fullscreen=1,index=2,device_type=9,alternate=0,trident=1,setting70=3,setting80=25),
      make_case(3,index=1,device_type=10,alternate=1,setting60=2,setting68=2,setting70=1,setting80=26,
                min_a=1280,min_b=1024,surface=0x900000),
      make_case(4,index=3,device_type=2,alternate=0,device_id=0x33444632,trident=1,voodoo=1,
                setting68=0,setting70=2,setting78=1,setting80=100),
      make_case(5,index=1,device_type=15,alternate=1,trident=1,voodoo=1,setting60=0,setting68=1,
                setting70=1,setting80=0x7fffffff,global_value=1),
      make_case(6,index=0,device_type=3,alternate=0,device_id=0x33444658,flags=0x40,
                setting5c=1,setting60=1,setting68=3,setting70=0,setting78=0,setting80=0x80000000),
      make_case(7,index=2,fullscreen=1,device_type=14,alternate=1,trident=1,voodoo=1,
                setting60=1,setting68=1,setting70=2,setting80=0xffffffff),
      make_case(8,index=3,device_type=1,alternate=0,flags=0x80,setting60=2,setting68=0,
                setting70=3,setting78=1,setting80=50,global_value=1),
      make_case(9,index=0,device_type=0,alternate=1,trident=1,voodoo=0,setting60=0,
                setting68=2,setting70=1,setting80=25,min_a=-5,min_b=10),
      make_case(10,index=2,device_type=9,alternate=0,setting60=1,setting68=2,
                setting70=2,setting78=1,setting80=0x7fffff00),
      make_case(11,index=1,device_type=3,alternate=1,device_id=0x33444632,setting60=2,
                setting68=3,setting70=0,setting80=1,global_value=0xffffffff),
      make_case(12,index=3,fullscreen=1,device_type=0,alternate=0,trident=1,voodoo=1,
                setting60=0,setting68=0,setting70=3,setting78=1,setting80=0x80000001),
    ]

def module_data():
    entries=[json.loads(x) for x in (ROOT/'research/binary-index/static/binaries.jsonl').read_text(encoding='utf8').splitlines()]
    m=next(x for x in entries if x['file']=='Porsche.exe')
    data=(ROOT/'local/game'/m['path']).read_bytes()
    if hashlib.sha256(data).hexdigest()!=SHA:raise RuntimeError('original binary SHA mismatch')
    return m,data

def native_input(c):
    head=[c[k] for k in ('index','fullscreen','alternate','seed','clock','device_id','flags','min_a','min_b',
      'field44','device_type','surface','global_value','trident','voodoo','setting5c','setting60','setting68',
      'setting6c','setting70','setting78','setting80')]
    for i in range(15,22):head[i]=signed(head[i])
    return ' '.join(map(str,head+c['gets']+c['sets']))

def original(m,data,c):
    u=Uc(UC_ARCH_X86,UC_MODE_32);u.mem_map(0x400000,0x300000)
    for sec in m['sections']:
        if sec['raw_size']:u.mem_write(0x400000+sec['rva'],data[sec['raw_offset']:sec['raw_offset']+sec['raw_size']])
    u.mem_map(0x3100000,0x10000);u.mem_map(EXIT,0x1000);u.mem_map(0x3300000,0x1000)
    u.mem_write(EXIT,b'\xc3'*0x1000)
    # Original external API slots and direct-call boundaries use typed recorders.
    for slot,target in ((0x6bd918,MODESET),(0x6bd934,DEVICE_API),(0x6bd984,GET),(0x6bd97c,SET)):
        put(u,slot,target)
    for target,entry in ((CONFIG,0x5a1e10),(CLOCK,0x555bc0)):
        u.mem_write(entry,b'\xe9'+struct.pack('<i',target-(entry+5)))
    # Driver vtable+0x24 is a thiscall/no-stack-argument boundary.
    put(u,DRIVER,VTABLE);put(u,DRIVER+8,RECORDS);put(u,VTABLE+0x24,VIRTUAL)
    display=bytearray(0x100);display[0x60]=c['fullscreen'];display[0x70:0x74]=struct.pack('<I',DRIVER)
    u.mem_write(DISPLAY,bytes(display));put(u,0x628130,DISPLAY)
    for r in range(4):
        words=[800+r*320,600+r*120,[16,15,32,24][r],0x44000000+c['seed']+r,
          0x55000000+c['seed']+r,2+r,0x77000000+c['seed']+r,0x88000000+c['seed']+r,
          0x99000000+c['seed']+r,0xaa000000+c['seed']+r]
        u.mem_write(RECORDS+r*40,struct.pack('<10I',*words))
    dev=bytearray([c['seed']&255]*0x100)
    for at,val,fmt in ((0,c['device_id'],'<I'),(0x0c,c['flags'],'<I'),(0x14,c['min_a'],'<i'),
      (0x20,c['min_b'],'<i'),(0x44,c['field44'],'<I'),(0x6c,c['device_type'],'<I'),(0x70,c['surface'],'<I')):
        dev[at:at+4]=struct.pack(fmt,val)
    u.mem_write(DEVICE,bytes(dev))
    u.mem_write(0x619790,bytes([c['seed']&255])*0x71);u.mem_write(0x619800,bytes([c['alternate']]))
    for va,val in ((0x619780,c['seed']^0x11111111),(0x619784,c['seed']^0x22222222),
      (0x619788,c['seed']^0x33333333),(0x61978c,c['seed']^0x44444444),
      (0x5deb1c,c['seed']^0x55555555),(0x5ce908,c['seed']^0x66666666),
      (0x69dd1d,c['seed']),(0x657da4,c['global_value']),
      (0x657d5c,c['setting5c']),(0x657d60,c['setting60']),(0x657d68,c['setting68']),
      (0x657d6c,c['setting6c']),(0x657d70,c['setting70']),(0x657d78,c['setting78']),
      (0x657d80,c['setting80'])):put(u,va,val)
    u.mem_write(OUT,b'\xa5'*40)
    events=[];gi=si=0
    def cstring(mu,addr):
        out=bytearray()
        while True:
            b=mu.mem_read(addr+len(out),1)[0]
            if b==0:return out.decode('ascii')
            out.append(b)
    def hook(mu,addr,_size,_):
        nonlocal gi,si
        if addr not in (MODESET,DEVICE_API,GET,SET,CONFIG,CLOCK,VIRTUAL):return
        sp=mu.reg_read(UC_X86_REG_ESP);ret=get(mu,sp)
        if addr==MODESET:
            events.append({'kind':'mode_set','key':get(mu,sp+4),'value':get(mu,sp+8)})
            mu.reg_write(UC_X86_REG_ESP,sp+12);mu.reg_write(UC_X86_REG_EIP,ret)
        elif addr==DEVICE_API:
            events.append({'kind':'device'});mu.reg_write(UC_X86_REG_EAX,DEVICE)
            mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
        elif addr==GET:
            key=get(mu,sp+4);result=c['gets'][gi];gi+=1
            events.append({'kind':'get','key':key,'result':result});mu.reg_write(UC_X86_REG_EAX,result)
            mu.reg_write(UC_X86_REG_ESP,sp+8);mu.reg_write(UC_X86_REG_EIP,ret)
        elif addr==SET:
            key,value=get(mu,sp+4),get(mu,sp+8);result=c['sets'][si];si+=1
            events.append({'kind':'set','key':key,'value':value,'result':result});mu.reg_write(UC_X86_REG_EAX,result)
            mu.reg_write(UC_X86_REG_ESP,sp+12);mu.reg_write(UC_X86_REG_EIP,ret)
        elif addr==CONFIG:
            dst,keyptr=get(mu,sp+4),get(mu,sp+8);key=cstring(mu,keyptr)
            result=c['trident'] if key=='Trident Blade' else c['voodoo']
            mu.mem_write(dst,b'setting\0');events.append({'kind':'config','key':key,'destination':dst-DEVICE,'result':result})
            mu.reg_write(UC_X86_REG_EAX,result);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
        elif addr==CLOCK:
            events.append({'kind':'clock','result':c['clock']});mu.reg_write(UC_X86_REG_EAX,c['clock'])
            mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
        else:
            events.append({'kind':'driver'})
            mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
    u.hook_add(UC_HOOK_CODE,hook)
    def invoke(entry,args):
        put(u,STACK,EXIT)
        for i,a in enumerate(args):put(u,STACK+4+4*i,a)
        u.reg_write(UC_X86_REG_ESP,STACK)
        try:u.emu_start(entry,EXIT,count=100000)
        except Exception as exc:raise RuntimeError(f'original joint x86 failed at {entry:08x} for {c}: EIP={u.reg_read(UC_X86_REG_EIP):08x}; events={events}') from exc
        delta=u.reg_read(UC_X86_REG_ESP)-STACK
        if delta!=4:raise RuntimeError(f'cdecl stack delta {entry:08x} case {c}: {delta}')
    invoke(0x44e720,[c['index'],OUT])
    query=list(struct.unpack('<10I',u.mem_read(OUT,40)))
    invoke(0x44ebf0,[c['index']])
    invoke(0x44ed10,[])
    settings=[signed(get(u,a)) for a in (0x657d5c,0x657d60,0x657d68,0x657d6c,0x657d70,0x657d78,0x657d80)]
    return {'query':query,'state':list(u.mem_read(0x619790,0x71)),
      'globals':[get(u,a) for a in (0x619780,0x619784,0x619788,0x61978c,0x5ce908,0x5deb1c)]+[u.mem_read(0x69dd1d,1)[0]]+settings,
      'device_tail':list(u.mem_read(DEVICE+0x80,32)),'calls':events}

def main():
    parser=argparse.ArgumentParser()
    parser.add_argument('--probe',type=Path,default=ROOT/'local/builds/v2/001-original-recovery/bin/Release/render_state_integration_probe.exe')
    parser.add_argument('--report',type=Path,default=RUN/'verification.json')
    args=parser.parse_args();probe=args.probe
    m,data=module_data();inputs=cases()
    feed=''.join(native_input(c)+'\n' for c in inputs)
    proc=subprocess.run([str(probe)],input=feed,text=True,capture_output=True,check=True)
    rows=proc.stdout.splitlines()
    if len(rows)!=len(inputs):raise RuntimeError(f'probe rows {len(rows)} != cases {len(inputs)}; stderr={proc.stderr}')
    fixtures=[]
    for c,line in zip(inputs,rows):
        native=json.loads(line);expect=original(m,data,c)
        if native!=expect:raise RuntimeError(f'case {c}: original={expect}; native={native}')
        fixtures.append({'input':{k:v for k,v in c.items() if k not in ('gets','sets')},
          'output':native,'get_result_count':len(c['gets']),'set_result_count':len(c['sets'])})
    rel=lambda x:x.relative_to(ROOT).as_posix()
    sources=[ITER/'source/recovered/Porsche.exe/render_mode.cpp',ITER/'source/recovered/Porsche.exe/render_settings.cpp',
      ITER/'source/recovered/Porsche.exe/render_state_init.cpp',ITER/'source/recovered/render_state_integration_probe.cpp']
    # Hash the transitive local project headers actually compiled by these units.
    headers=[ITER/'source/include/porsche/render_mode.hpp',ITER/'source/include/porsche/render_settings.hpp',
      ITER/'source/include/porsche/render_state_init.hpp',ITER/'source/include/porsche/render_display.hpp',
      ITER/'source/include/porsche/render_objects.hpp',ITER/'source/include/porsche/render_startup.hpp',
      ITER/'source/include/porsche/render_activate.hpp']
    deps=sources+headers+[RUN/'CMakeLists.txt',RUN/'README.md',
      ROOT/'research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm',
      ROOT/'research/v2/binaries/Porsche.exe-ddd748fdbe6d/decompiled.c',Path(__file__).resolve()]
    report={'schema':1,'binary':'Porsche.exe','sha256':SHA,'entry_vas':['0044e720','0044ebf0','0044e890','0044ed10','0044f020','00535b40'],
      'coverage':'joint mode query/commit, renderer settings application, normal and alternate state update',
      'cases':len(inputs),'native_cpp_equal_original_x86':True,'game_launch_verified':False,
      'boundaries':'Unrecovered boundaries only: renderer driver vtable+0x24 (thiscall/no stack arguments), IAT 0x6bd934 device lookup (cdecl), 0x6bd984/0x6bd97c renderer state APIs (stdcall), IAT 0x6bd918 (stdcall), 0x5a1e10 config lookup (cdecl), and direct clock 0x555bc0 (cdecl). Functions 0x44e720/0x44ebf0/0x44e890/0x44ed10/0x44f020 and 0x535b40 execute as original x86 or actual linked C++ units. Canonical globals are owned by Run063/066; probe-only storage is fixture backing.',
      'source_sha256':{rel(p):hashlib.sha256(p.read_bytes().replace(b'\r\n',b'\n')).hexdigest() for p in deps},
      'probe_sha256':hashlib.sha256(probe.read_bytes()).hexdigest(),'fixtures':fixtures}
    report['source_sha256']=source_hashes(deps,compiled_sources=[ITER/'source/recovered/Porsche.exe/render_mode.cpp',ITER/'source/recovered/Porsche.exe/render_settings.cpp',ITER/'source/recovered/Porsche.exe/render_state_init.cpp',ITER/'source/recovered/render_state_integration_probe.cpp',ITER/'source/recovered/Porsche.exe/application_state.cpp',ITER/'source/recovered/Porsche.exe/application_globals.cpp'])
    out=args.report;out.parent.mkdir(parents=True,exist_ok=True)
    out.write_text(json.dumps(report,indent=2)+'\n',encoding='utf8')
    print(f'verified {len(inputs)} joint renderer mode/settings/state integration cases; report {rel(out)}')
if __name__=='__main__':main()
