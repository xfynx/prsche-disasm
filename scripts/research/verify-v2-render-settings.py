import argparse
from v2_source_dependencies import source_hashes
#!/usr/bin/env python3
import hashlib, json, struct, subprocess, sys
from pathlib import Path

ROOT=Path(__file__).resolve().parents[2]
ITER=ROOT/'iterations/v2/001-original-recovery'
RUN=ITER/'runs/066-render-settings'
SHA='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_EIP,UC_X86_REG_ESP

STACK,EXIT,DEVICE=0x3101000,0x3200000,0x3103000
CURRENT,GET_STATE,SET_STATE,CONFIG=0x3300000,0x3300010,0x3300020,0x3300030
def put(u,a,v):u.mem_write(a,struct.pack('<I',v&0xffffffff))
def get(u,a):return struct.unpack('<I',u.mem_read(a,4))[0]
def put_bytes(u,a,b):u.mem_write(a,b)

def case(seed,**kw):
    c=dict(seed=seed,id=0x12345678,flags=0x20,min_a=640,min_b=800,field44=0x11223344,
        type=0,surface=0x400000,global_value=0,width=800,height=600,format=16,
        trident=0,voodoo=0,
        gets=[(seed*0x101+i*13)&0xffffffff for i in range(11)],
        sets=[(seed+i*7)&1 for i in range(24)])
    c.update(kw);return c

def cases():
    return [
        case(1),
        case(2,type=1,flags=0x40,global_value=1,trident=1,voodoo=1,min_a=1280,min_b=1024,
             width=1920,height=1080,format=32,surface=0x800000),
        case(3,type=9,trident=1,voodoo=1,width=640,height=480,format=15,surface=0x200000),
        case(4,type=10,global_value=1,min_a=900,min_b=900,field44=7,surface=0x300000),
        case(5,type=15,flags=0xc0,voodoo=1,width=1024,height=768,format=24),
        case(6,type=3,voodoo=1),
        case(7,type=14,trident=1),
        case(8,type=2,global_value=1),
        case(9,id=0x33444632,type=3,trident=1,voodoo=1),
        case(10,id=0x33444658,type=10,flags=0x80),
        case(11,type=1,min_a=-5,min_b=10,flags=0x7f,global_value=0),
        case(12,type=0,field44=0xffffffff,surface=0xffffffff,width=3840,height=2160,format=32,
             trident=1,voodoo=1,gets=[0,1,0xffffffff,3,4,5,6,7,8,9,10]),
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
    # 0x5a1e10 is the only direct call boundary. Route its complete entry to
    # a synthetic stub because a code hook does not suppress mapped code.
    u.mem_write(0x5a1e10,b'\xe9'+struct.pack('<i',CONFIG-(0x5a1e10+5)))
    for slot,target in ((0x6bd934,CURRENT),(0x6bd984,GET_STATE),(0x6bd97c,SET_STATE)):
        put(u,slot,target)
    dev=bytearray([c['seed']&255]*0x100)
    for at,val,fmt in ((0,c['id'],'<I'),(0x0c,c['flags'],'<I'),(0x14,c['min_a'],'<i'),
        (0x20,c['min_b'],'<i'),(0x44,c['field44'],'<I'),(0x6c,c['type'],'<I'),(0x70,c['surface'],'<I')):
        dev[at:at+4]=struct.pack(fmt,val)
    u.mem_write(DEVICE,bytes(dev))
    u.mem_write(0x619790,bytes([c['seed']&255])*0x71)
    for va,val in ((0x619784,c['width']),(0x619788,c['height']),(0x61978c,c['format']),
                   (0x657da4,c['global_value'])):put(u,va,val)
    events=[];gi=si=0
    def cstring(mu,addr):
        out=bytearray()
        while True:
            b=mu.mem_read(addr+len(out),1)[0]
            if b==0:return out.decode('ascii')
            out.append(b)
    def hook(mu,addr,_size,_):
        nonlocal gi,si
        if addr not in (CURRENT,GET_STATE,SET_STATE,CONFIG):return
        sp=mu.reg_read(UC_X86_REG_ESP);ret=get(mu,sp)
        if addr==CURRENT:
            events.append({'kind':'device'});mu.reg_write(UC_X86_REG_EAX,DEVICE);cleanup=4
        elif addr==GET_STATE:
            key=get(mu,sp+4);result=c['gets'][gi];gi+=1
            events.append({'kind':'get','key':key,'result':result});mu.reg_write(UC_X86_REG_EAX,result);cleanup=8
        elif addr==SET_STATE:
            key,value=get(mu,sp+4),get(mu,sp+8);result=c['sets'][si];si+=1
            events.append({'kind':'set','key':key,'value':value,'result':result});mu.reg_write(UC_X86_REG_EAX,result);cleanup=12
        else:
            dst,keyptr=get(mu,sp+4),get(mu,sp+8);key=cstring(mu,keyptr)
            result=c['trident'] if key=='Trident Blade' else c['voodoo']
            mu.mem_write(dst,b'setting\0')
            events.append({'kind':'config','key':key,'destination':dst-DEVICE,'result':result})
            mu.reg_write(UC_X86_REG_EAX,result);cleanup=4
        mu.reg_write(UC_X86_REG_ESP,sp+cleanup);mu.reg_write(UC_X86_REG_EIP,ret)
    u.hook_add(UC_HOOK_CODE,hook)
    put(u,STACK,EXIT);u.reg_write(UC_X86_REG_ESP,STACK)
    try:u.emu_start(0x44e890,EXIT,count=100000)
    except Exception as exc:raise RuntimeError(f"original x86 failed for {c}: EIP={u.reg_read(UC_X86_REG_EIP):08x}; calls={events}") from exc
    return {'state':list(u.mem_read(0x619790,0x71)),
        'device_buffer':list(u.mem_read(DEVICE+0x80,32)),
        'mode':[get(u,0x619784),get(u,0x619788),get(u,0x61978c)],
        'calls':events,'stack_delta':u.reg_read(UC_X86_REG_ESP)-STACK}

def main():
    parser=argparse.ArgumentParser()
    parser.add_argument('--probe',type=Path,default=ROOT/'local/builds/v2/001-original-recovery/bin/Release/render_settings_probe.exe')
    parser.add_argument('--report',type=Path,default=RUN/'verification.json')
    args=parser.parse_args();probe=args.probe
    m,data=module_data();inputs=cases()
    feed=''.join(' '.join(map(str,[c[k] for k in ('id','flags','min_a','min_b','field44','type','surface','global_value','width','height','format','trident','voodoo','seed')]+c['gets']+c['sets']))+'\n' for c in inputs)
    proc=subprocess.run([str(probe)],input=feed,text=True,capture_output=True,check=True)
    rows=proc.stdout.splitlines()
    if len(rows)!=len(inputs):raise RuntimeError(f'probe rows {len(rows)} != cases {len(inputs)}; stderr={proc.stderr}')
    fixtures=[]
    for c,line in zip(inputs,rows):
        native=json.loads(line);expect=original(m,data,c)
        if expect['stack_delta']!=4:raise RuntimeError(f"original cdecl stack delta {c}: {expect['stack_delta']}")
        if native!= {k:v for k,v in expect.items() if k!='stack_delta'}:
            raise RuntimeError(f"case {c}: original={expect}; native={native}")
        fixtures.append({'input':c,'output':native,'original_stack_delta':expect['stack_delta']})
    rel=lambda x:x.relative_to(ROOT).as_posix()
    deps=[ITER/'source/include/porsche/render_settings.hpp',ITER/'source/include/porsche/render_mode.hpp',
      ITER/'source/include/porsche/render_display.hpp',ITER/'source/recovered/Porsche.exe/render_settings.cpp',
      ITER/'source/recovered/render_settings_probe.cpp',RUN/'CMakeLists.txt',RUN/'README.md',
      ROOT/'research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm',
      ROOT/'research/v2/binaries/Porsche.exe-ddd748fdbe6d/decompiled.c',Path(__file__).resolve()]
    report={'schema':1,'binary':'Porsche.exe','sha256':SHA,'entry_va':'0044e890',
      'coverage':'complete 0x44e890 consumer; engine APIs and config parser remain typed boundaries',
      'full_function_vas':['0044e890'],'partial_function_vas':[],'cases':len(inputs),
      'native_cpp_equal_original_x86':True,'game_launch_verified':False,
      'boundaries':'0x6bd934 returns renderer device pointer; 0x6bd984/0x6bd97c are stdcall get/set state APIs; 0x5a1e10 is cdecl config lookup. State-block and applied-mode globals reuse canonical Run063 storage. Device field semantics are limited to offsets read by 0x44e890.',
      'source_sha256':{rel(p):hashlib.sha256(p.read_bytes().replace(b'\r\n',b'\n')).hexdigest() for p in deps},
      'probe_sha256':hashlib.sha256(probe.read_bytes()).hexdigest(),'fixtures':fixtures}
    report['source_sha256']=source_hashes(deps,compiled_sources=[ITER/'source/recovered/Porsche.exe/render_settings.cpp',ITER/'source/recovered/render_settings_probe.cpp',ITER/'source/recovered/Porsche.exe/application_state.cpp',ITER/'source/recovered/Porsche.exe/application_globals.cpp'])
    out=args.report;out.parent.mkdir(parents=True,exist_ok=True)
    out.write_text(json.dumps(report,indent=2)+'\n',encoding='utf8')
    print(f'verified {len(inputs)} full-state/call-trace renderer-settings cases; report {rel(out)}')
if __name__=='__main__':main()
