"""Compare Porsche.exe 0x467470 renderer startup consumer with bounded C++ unit."""
import argparse
import hashlib
import json
from pathlib import Path
import struct
import subprocess
import sys

ROOT=Path(__file__).resolve().parents[2]
RUN=ROOT/'iterations/v2/001-original-recovery/runs/024-render-startup'
sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ECX,UC_X86_REG_ESP,UC_X86_REG_EIP

CORE,DISPLAY,VTABLE,STRINGS,STACK,EXIT=0x3100000,0x3101000,0x3102000,0x3200000,0x3308000,0x3400000
FIRST,ALLOC,CORE_CTOR,DISPLAY_CTOR,REG_TEXT,REG_CHOICE,ACTIVATE,FORMAT,APPLY,MISC1,MISC2=(
    0x3103000,0x3103010,0x3103020,0x3103030,0x3103040,0x3103050,
    0x3103060,0x3103070,0x3103080,0x3103090,0x31030a0)


def cases():
    out=[]
    for selector,regtext in ((b'glide',b'dx'),(b'registry',b'dx'),
                             (b'registry',b'glide'),(b'registry',b'z')):
        for existing in (0,1):
            for selected in (0,3,0x87654321):
                out.append((selector,regtext,b'800x600',b'prefix_',selected,640,480,existing,5))
    out += [(b'other',b'dx',b'1024x768',b'device_',7,1024,768,0,2),
            (b'registry',b'dx',b'640x480',b'',0,800,600,0,0)]
    return out


def wire(case):
    return '|'.join([(part.hex() or '-') for part in case[:4]] + [str(v) for v in case[4:]])


def original(module,data,case):
    selector,regtext,regresolution,name,selected,width,height,existing,choice=case
    uc=Uc(UC_ARCH_X86,UC_MODE_32);base=int(module['image_base'],16)
    uc.mem_map(base,0x300000)
    for section in module['sections']:
        uc.mem_write(base+section['rva'],data[section['raw_offset']:section['raw_offset']+section['raw_size']])
    uc.mem_map(0x3100000,0x4000);uc.mem_map(STRINGS,0x1000);uc.mem_map(0x3300000,0x10000);uc.mem_map(EXIT,0x1000)
    def put(address,*values):uc.mem_write(address,struct.pack('<'+'I'*len(values),*(v&0xffffffff for v in values)))
    def words(address,count):return struct.unpack('<'+'I'*count,uc.mem_read(address,count*4))
    def cstr(address):
        return bytes(uc.mem_read(address,256)).split(b'\x00',1)[0]
    uc.mem_write(0x657a38,selector+b'\x00'+bytes(15-len(selector)))
    put(0x657a48,width);put(0x657a4c,height);put(0x657a58,selected)
    uc.mem_write(STRINGS,name+b'\x00');put(0x65b304,STRINGS)
    put(0x65b39c,0);put(0x628130,DISPLAY if existing else 0)
    put(CORE,VTABLE);put(VTABLE,FIRST)
    put(DISPLAY+0x74,0x11223344);put(DISPLAY+0x7c,0x55667788)
    endpoints={0x59ef90:(ALLOC,1,False),0x467700:(CORE_CTOR,2,True),
               0x4677e0:(DISPLAY_CTOR,4,True),0x4b7240:(REG_TEXT,2,True),
               0x4b7340:(REG_CHOICE,1,True),0x4b7220:(ACTIVATE,0,False),
               0x5a0fbf:(FORMAT,4,False),0x4b70d0:(APPLY,2,False),
               0x465df0:(MISC1,0,False),0x449b40:(MISC2,0,False)}
    endpoints={va:(name,argc,cleanup) for va,(name,argc,cleanup) in endpoints.items()}
    endpoints[FIRST]=('first',0,False)
    calls=[];allocations=0
    def hook(machine,address,_size,_user):
        nonlocal allocations
        if address not in endpoints:return
        label,argc,cleanup=endpoints[address]
        sp=machine.reg_read(UC_X86_REG_ESP);ret,*args=words(sp,argc+1)
        result=0
        if label==ALLOC:
            allocations+=1;calls.append(['alloc',args[0]])
            result=CORE if allocations==1 else DISPLAY
        elif label==CORE_CTOR:
            calls.append(['core_ctor',cstr(args[0]).hex(),cstr(args[1]).hex()])
            put(CORE,VTABLE);result=CORE
        elif label=='first':
            if machine.reg_read(UC_X86_REG_ECX)!=CORE:raise RuntimeError('Core vtable ABI mismatch')
            calls.append(['first'])
        elif label==REG_TEXT:
            if machine.reg_read(UC_X86_REG_ECX)!=CORE:raise RuntimeError('Registry text thiscall mismatch')
            calls.append(['regtext',args[0]])
            text=regtext if args[0]==0 else regresolution
            machine.mem_write(args[1],text+b'\x00')
        elif label==REG_CHOICE:
            calls.append(['choice',args[0]]);result=choice
        elif label==ACTIVATE:calls.append(['activate'])
        elif label==FORMAT:
            calls.append(['format',args[2],args[3]])
            machine.mem_write(args[0],f'{args[2]:d}x{args[3]:d}'.encode()+b'\x00')
        elif label==DISPLAY_CTOR:
            calls.append(['display_ctor',cstr(args[0]).hex(),args[1],args[2],cstr(args[3]).hex()])
            put(DISPLAY+0x74,0x11223344);put(DISPLAY+0x7c,0x55667788);result=DISPLAY
        elif label==APPLY:calls.append(['apply',*args])
        elif label==MISC1:calls.append(['misc1'])
        elif label==MISC2:calls.append(['misc2'])
        machine.reg_write(UC_X86_REG_EAX,result)
        machine.reg_write(UC_X86_REG_ESP,sp+4*(argc+1) if cleanup else sp+4)
        machine.reg_write(UC_X86_REG_EIP,ret)
    uc.hook_add(UC_HOOK_CODE,hook)
    put(STACK,EXIT);uc.reg_write(UC_X86_REG_ESP,STACK)
    uc.emu_start(0x467470,EXIT,count=20000)
    if uc.reg_read(UC_X86_REG_EIP)!=EXIT:raise RuntimeError('Original consumer did not return')
    return {'core':int(words(0x65b39c,1)[0]!=0),'display':int(words(0x628130,1)[0]!=0),
            'selector':bytes(uc.mem_read(0x657a38,16)).hex(),
            'display_state':bytes(uc.mem_read(DISPLAY,0x80)).hex(),'calls':calls}


def main():
    parser=argparse.ArgumentParser()
    parser.add_argument('--probe',type=Path,default=ROOT/'local/builds/v2/001-original-recovery/bin/Release/render_startup_probe.exe')
    parser.add_argument('--limit',type=int,default=0)
    parser.add_argument('--report-dir',type=Path,default=RUN)
    args=parser.parse_args()
    report_dir=args.report_dir
    module=next(v for v in map(json.loads,(ROOT/'research/binary-index/static/binaries.jsonl').read_text(encoding='utf8').splitlines()) if v['file']=='Porsche.exe')
    data=(ROOT/'local/game'/module['path']).read_bytes()
    sha='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
    if hashlib.sha256(data).hexdigest()!=sha or module['sha256']!=sha:raise RuntimeError('Original SHA mismatch')
    inputs=cases()[:args.limit or None]
    native=subprocess.run([str(args.probe)],input='\n'.join(map(wire,inputs))+'\n',text=True,capture_output=True,check=True,timeout=60)
    rows=list(map(json.loads,native.stdout.splitlines()))
    if len(rows)!=len(inputs):raise RuntimeError('Native row count mismatch')
    fixtures=[]
    for i,(case,actual) in enumerate(zip(inputs,rows)):
        expected=original(module,data,case)
        if actual!=expected:
            dest=ROOT/'local/reports/v2-render-startup-mismatch.json'
            dest.write_text(json.dumps({'index':i,'case':wire(case),'expected':expected,'actual':actual},indent=2)+'\n')
            raise RuntimeError(f'Case {i} differs in {[key for key in expected if expected[key]!=actual.get(key)]}; {dest}')
        fixtures.append({'input':wire(case),'output_sha256':hashlib.sha256(json.dumps(expected,sort_keys=True).encode()).hexdigest()})
    print(json.dumps({'cases':len(inputs),'function_vas':['00467470'],'native_cpp_equal_original_x86':True}))
    if args.limit:return
    paths=['iterations/v2/001-original-recovery/source/include/porsche/render_startup.hpp',
           'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/render_startup.cpp',
           'iterations/v2/001-original-recovery/source/recovered/render_startup_probe.cpp',
           'scripts/research/verify-v2-render-startup.py',
           'iterations/v2/001-original-recovery/CMakeLists.txt',
           'iterations/v2/001-original-recovery/source/recovered/sources.cmake']
    function=next(v for v in map(json.loads,(ROOT/'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/functions.jsonl').read_text(encoding='utf8').splitlines()) if v['entry_va']=='00467470')
    start,end=map(lambda value:int(value,16),function['ranges'][0])
    rva=start-int(module['image_base'],16)
    section=next(s for s in module['sections'] if s['rva']<=rva and rva+end-start<s['rva']+s['raw_size'])
    offset=section['raw_offset']+rva-section['rva']
    body=data[offset:offset+end-start+1]
    if len(body)!=642:raise RuntimeError('Renderer consumer body size differs')
    body_sha=hashlib.sha256(body).hexdigest()
    report={'schema':1,'sha256':sha,'function_vas':['00467470'],'cases':len(inputs),
            'native_cpp_equal_original_x86':True,'binary_matched':False,'game_launch_verified':False,
            'original_body_sha256':{'00467470':body_sha},
            'boundary':'allocators, constructors, registry, format, display, misc and virtual first call controlled; null-allocation original faults excluded; no real render acceptance',
            'source_sha256':{p:hashlib.sha256((ROOT/p).read_bytes().replace(b'\r\n',b'\n')).hexdigest() for p in paths},
            'probe_sha256':hashlib.sha256(args.probe.read_bytes()).hexdigest(),'fixtures':fixtures}
    report_dir.mkdir(parents=True,exist_ok=True)
    (report_dir/'verification.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf8')
    (report_dir/'source-functions.jsonl').write_text(json.dumps({'sha256':sha,'body_sha256':body_sha,**function})+'\n',encoding='utf8')

if __name__=='__main__':main()
