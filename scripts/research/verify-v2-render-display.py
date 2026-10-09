from v2_source_dependencies import source_hashes
"""Compare the display constructor's measured prefix and full entry with original x86."""
import argparse
import hashlib
import json
import re
from pathlib import Path
from functools import lru_cache
import struct
import subprocess
import sys

ROOT=Path(__file__).resolve().parents[2]
RUN=ROOT/'iterations/v2/001-original-recovery/runs/032-render-display'
sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ECX,UC_X86_REG_EDX,UC_X86_REG_ESP,UC_X86_REG_EIP

SHA='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
DISPLAY,RESOURCE,DRIVER,VTABLE,SUBOBJECT,NAME,RESOLUTION,STACK,STUB,DRIVER_START,DRIVER_PRESENT=(
    0x3101000,0x3102000,0x3103000,0x3104000,0x3105000,0x3200000,0x3200100,
    0x3308000,0x3500000,0x3500200,0x3500210)
MODE,SURFACE_MEMORY,SURFACE,READBACK,TEXTURE,TEMPORARY=(
    0x3400000,0x3401000,0x3402000,0x3403000,0x3404000,0x3405000)
IAT={0x5b2274:0x3500000,0x5b226c:0x3500010,0x5b2044:0x3500020,
     0x5b2268:0x3500030,0x5b2270:0x3500040}
THRASH={0x6bd984:STUB+0x100,0x6bd97c:STUB+0x110,0x6bd9b0:STUB+0x120,
        0x6bd954:STUB+0x130,0x6bd91c:STUB+0x140,0x6bd9a8:STUB+0x150,
        0x6bd970:STUB+0x160,0x6bd978:STUB+0x170,0x6bd96c:STUB+0x180}

def module_and_data():
    path=ROOT/'research/binary-index/static/binaries.jsonl'
    module=next(v for v in map(json.loads,path.read_text(encoding='utf8').splitlines()) if v['file']=='Porsche.exe')
    data=(ROOT/'local/game'/module['path']).read_bytes()
    if module['sha256']!=SHA or hashlib.sha256(data).hexdigest()!=SHA:
        raise RuntimeError('Porsche.exe SHA mismatch')
    return module,data

def machine(module,data):
    uc=Uc(UC_ARCH_X86,UC_MODE_32);base=int(module['image_base'],16)
    uc.mem_map(base,0x300000)
    for section in module['sections']:
        uc.mem_write(base+section['rva'],data[section['raw_offset']:section['raw_offset']+section['raw_size']])
    for addr,size in ((0x3100000,0x10000),(NAME,0x2000),(0x3300000,0x10000),(0x3400000,0x10000),(STUB,0x1000)):
        uc.mem_map(addr,size)
    for iat,stub in IAT.items():put32(uc,iat,stub)
    for table,stub in THRASH.items():put32(uc,table,stub)
    put32(uc,VTABLE,DRIVER_PRESENT);put32(uc,VTABLE+4,DRIVER_START)
    put32(uc,SUBOBJECT,VTABLE)
    return uc

def put32(uc,addr,value):uc.mem_write(addr,struct.pack('<I',value&0xffffffff))
def get32(uc,addr):return struct.unpack('<I',uc.mem_read(addr,4))[0]
def cstr(uc,addr):return bytes(uc.mem_read(addr,256)).split(b'\x00',1)[0].decode('latin1')

@lru_cache(maxsize=None)
def callee_pop(address):
    if address in (IAT[0x5b2274],):return 0
    if address==IAT[0x5b226c]:return 4
    if address in (IAT[0x5b2044],IAT[0x5b2268]):return 8
    if address==IAT[0x5b2270]:return 16
    if address in THRASH.values():
        export={THRASH[0x6bd984]:4,THRASH[0x6bd97c]:8,THRASH[0x6bd9b0]:4,
            THRASH[0x6bd954]:4,THRASH[0x6bd91c]:0,THRASH[0x6bd9a8]:16,
            THRASH[0x6bd970]:0,THRASH[0x6bd978]:4,THRASH[0x6bd96c]:20}
        return export[address]
    if address==DRIVER_START:return 0
    if address==DRIVER_PRESENT:return 0
    path=ROOT/'research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm'
    lines=path.read_text(encoding='utf8').splitlines()
    marker=f'; function {address:08x}'
    try:start=next(i for i,line in enumerate(lines) if line.lower().startswith(marker))
    except StopIteration:return 0
    end=next((i for i in range(start+1,len(lines)) if lines[i].startswith('; FUNCTION ')),len(lines))
    returns=list(re.finditer(r'\bRET(?:\s+0x([0-9a-fA-F]+))?', '\n'.join(lines[start:end]),re.I))
    return int(returns[-1].group(1),16) if returns and returns[-1].group(1) else 0

ASM=[]
for line in (ROOT/'research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm').read_text(encoding='utf8').splitlines():
    match=re.match(r'^([0-9a-fA-F]{8})\s+.*\bCALL 0x([0-9a-fA-F]{8})',line)
    if match and 0x4677e0<=int(match.group(1),16)<=0x467ebe:ASM.append(int(match.group(2),16))
ASM_CALLS=set(ASM)

def original(module,data,case):
    seed,flags,depth,driver_result,actual_w,actual_h,actual_m,request_w,request_h,request_m,selected,full=case
    uc=machine(module,data)
    for address,size in ((DISPLAY,0x80),(RESOURCE,8),(DRIVER,0x24),(SURFACE_MEMORY,0x224),
                         (SURFACE,0x240),(READBACK,0x4000),(TEXTURE,0x100),(TEMPORARY,0x100)):
        uc.mem_write(address,bytes([seed])*size)
    uc.mem_write(READBACK,bytes(0x4000))
    uc.mem_write(NAME,b'dx7\x00');uc.mem_write(RESOLUTION,b'800x600\x00')
    put32(uc,MODE,0);put32(uc,MODE+4,0);put32(uc,MODE+8,selected)
    put32(uc,VTABLE,DRIVER_PRESENT);put32(uc,VTABLE+4,DRIVER_START);put32(uc,SUBOBJECT,VTABLE)
    for addr,value in ((0x628130,0),(0x5deb1c,0xabcdef01),
        (0x69ecf8,0x5555),(0x69ecfc,0x6666),(0x69ed00,0x7777),(0x69ed08,0x8888),
        (0x619784,actual_w),(0x619788,actual_h),(0x61978c,actual_m),
        (0x657a48,request_w),(0x657a4c,request_h),(0x657a50,request_m),
        (0x5deac8,0),(0x5deacc,0)):
        put32(uc,addr,value)
    for i,v in enumerate((0x3500800,NAME,selected,flags,RESOLUTION)):put32(uc,STACK+4*i,v)
    uc.reg_write(UC_X86_REG_ECX,DISPLAY);uc.reg_write(UC_X86_REG_ESP,STACK)
    calls=[];member_index=0;clock_index=0
    def record(s):calls.append(s+';')
    targets=set(IAT.values())|set(THRASH.values())|ASM_CALLS|{DRIVER_START,DRIVER_PRESENT}
    def hook(machine,address,_size,_user):
        nonlocal member_index,clock_index
        if address not in targets:return
        sp=machine.reg_read(UC_X86_REG_ESP);ret=get32(machine,sp)
        arg=lambda n:get32(machine,sp+4+n*4)
        result=0;cleanup=callee_pop(address)
        if address==0x466380:
            ptr=machine.reg_read(UC_X86_REG_ECX)
            if ptr!=DISPLAY+0x14+0x20*member_index:raise RuntimeError('member thiscall')
            record('member14' if member_index==0 else 'member34')
            machine.mem_write(ptr,bytes([0xa1 if member_index==0 else 0xb2])*0x20);member_index+=1
        elif address==0x555bc0:
            record('clock');result=(0x123,0x456)[clock_index];clock_index+=1
        elif address==IAT[0x5b2274]:record('desktop');result=0x1111
        elif address==IAT[0x5b226c]:record(f'windowdc|{arg(0)}');result=0x2222
        elif address==IAT[0x5b2044]:record(f'caps|{arg(0)}|{arg(1)}');result=depth
        elif address==IAT[0x5b2268]:record(f'releasedc|{arg(0)}|{arg(1)}')
        elif address==IAT[0x5b2270]:record(f'message|{cstr(machine,arg(2))}|{cstr(machine,arg(1))}|{arg(3)}')
        elif address==0x5a0fbf:
            record(f'depthformat|{arg(2)}');machine.mem_write(arg(0),b'Please set your display to 256 colors or higher.\n\x00')
        elif address==0x557370:record('depthfailure')
        elif address==0x59ef90:
            size=arg(0);record(f'alloc|{size}');result=RESOURCE if size==8 else DRIVER if size==0x24 else SURFACE_MEMORY
        elif address==0x540390:
            if machine.reg_read(UC_X86_REG_ECX)!=RESOURCE:raise RuntimeError('resource thiscall')
            record(f'resourcector|{arg(0)}');put32(machine,RESOURCE+4,0x11223344);result=RESOURCE
        elif address in (0x557100,0x556a90):
            if machine.reg_read(UC_X86_REG_ECX)!=DRIVER or arg(0)!=RESOURCE:raise RuntimeError('driver constructor ABI')
            alt=int(address==0x556a90);record(f'driverctor|{alt}')
            put32(machine,DRIVER,VTABLE);put32(machine,DRIVER+0x20,RESOURCE);result=DRIVER
        elif address==DRIVER_START:
            record(f'driverstart|{int(machine.reg_read(UC_X86_REG_ECX)==DRIVER)}');result=driver_result
            if full:put32(machine,DRIVER+0x18,SUBOBJECT)
        elif address==DRIVER_PRESENT:record(f'driver-present|{arg(0)}');result=0x44556677
        elif address==0x5a246e:record(f'driverfailure|{arg(0)}')
        elif address==0x44e2c0:record('prevideo')
        elif address==0x537600:record('videobase|'+'|'.join(str(arg(i)) for i in range(6)))
        elif address==0x5376c0:record('videomode|'+'|'.join(str(arg(i)) for i in range(5)));result=0x43
        elif address==0x468030:record(f'videoresult|{arg(0)}')
        elif address==0x53c3d0:record('texture-reset')
        elif address==0x553fc0:record(f'reserve|{arg(0)}');result=0
        elif address==0x5a177b:record(f'texture-report|{cstr(machine,arg(0))}|{arg(1)}')
        elif address==0x538d10:record('surface-ctor');result=SURFACE
        elif address==0x538da0:record('surface-init');result=0
        elif address==0x5392d0:record('surface-config')
        elif address==0x539f40:record('surface-transform');result=SURFACE
        elif address==0x539b80:record('transform-init')
        elif address==0x539b30:record('transform-compose')
        elif address==0x539b00:record('transform-attach')
        elif address==0x466e80:record(f'local-transform|{arg(0)}')
        elif address==0x555390:record('thr-cleanup')
        elif address==0x535950:record('texture-create|8|8|16|0');result=TEXTURE
        elif address==0x534480:record('texture-bind')
        elif address==0x537e00:record(f'fill|{arg(0)}')
        elif address==0x556910:record('select-buffer|'+ '|'.join(str(arg(i)) for i in range(3)))
        elif address==0x554960:record('texture-alloc|8|8|4|0|0|UV Test');result=TEMPORARY
        elif address==0x5550e0:record('texture-update')
        elif address==0x554d70:record('texture-copy|0')
        elif address==0x555440:record('texture-release')
        elif address==THRASH[0x6bd984]:
            key=arg(0);record(f'getstate|{key}')
            result={2:0x102,7:0x107,10:0x10a,3:0x103}.get(key,MODE)
        elif address==THRASH[0x6bd97c]:record(f'setstate|{arg(0)}|{arg(1)}')
        elif address==THRASH[0x6bd9b0]:record(f'window|{arg(0)}')
        elif address==THRASH[0x6bd954]:record(f'set-texture|{arg(0)}')
        elif address==THRASH[0x6bd91c]:record('clear-window')
        elif address==THRASH[0x6bd9a8]:record('draw-quad')
        elif address==THRASH[0x6bd970]:record('flush')
        elif address==THRASH[0x6bd978]:record(f'sync|{arg(0)}')
        elif address==0x531ca0:record(f'readback-alloc|{arg(1)}|{arg(2)}');result=READBACK
        elif address==THRASH[0x6bd96c]:
            record('readrect|'+ '|'.join(str(arg(i)) for i in range(4)));machine.mem_write(arg(4),bytes(0x4000))
        elif address==0x468110:result=int(arg(0)==arg(1))
        elif address==0x533f80:record('texture-free')
        elif address==0x44e870:record(f'present|{arg(0)}');result=0
        elif address==0x537850:record('driver-finish|1')
        elif address==0x4b0eb0:record('finish-init')
        machine.reg_write(UC_X86_REG_EAX,result&0xffffffff)
        machine.reg_write(UC_X86_REG_ESP,sp+4+cleanup)
        machine.reg_write(UC_X86_REG_EIP,ret)
    uc.hook_add(UC_HOOK_CODE,hook)
    stop=0x3500800 if full else 0x4679cc
    try:uc.emu_start(0x4677e0,stop,count=25000)
    except Exception as exc:
        sp=uc.reg_read(UC_X86_REG_ESP)
        raise RuntimeError(f'original x86 case={case} stopped at {uc.reg_read(UC_X86_REG_EIP):08x} edx={uc.reg_read(UC_X86_REG_EDX):08x} local={get32(uc,sp+0x14):08x}') from exc
    if uc.reg_read(UC_X86_REG_EIP)!=stop:raise RuntimeError(f'display x86 did not stop at {stop:x}')
    display=bytearray(uc.mem_read(DISPLAY,0x80))
    for offset,value in ((0x54,DISPLAY+0x14),(0x6c,RESOURCE),(0x70,DRIVER)):
        display[offset:offset+4]=struct.pack('<I',value)
    if full:display[0x7c:0x80]=struct.pack('<I',SURFACE)
    driver=bytearray(uc.mem_read(DRIVER,0x24));driver[:4]=struct.pack('<I',0x5bc3f0 if flags&0xff else 0x5bc41c)
    if full:driver[0x18:0x1c]=struct.pack('<I',SUBOBJECT)
    driver[0x20:0x24]=struct.pack('<I',RESOURCE)
    return {'display':display.hex(),'resource':bytes(uc.mem_read(RESOURCE,8)).hex(),
            'driver':driver.hex(),'global_display':get32(uc,0x628130)==DISPLAY,
            'clock_global':get32(uc,0x5deb1c),'name_global':get32(uc,0x69ecf8),
            'callback1':get32(uc,0x69ecfc),'callback2':get32(uc,0x69ed00),
            'selected':get32(uc,0x69ed08),'texture_width':get32(uc,0x5deac8),
            'texture_height':get32(uc,0x5deacc),'calls':''.join(calls).encode('latin1').hex()}

def cases():
    out=[]
    for seed in (0,0xcc):
        for flags in (0,1,0x102):
            for depth in (0,7,8,16,32):
                for mode in (0,1,2):
                    actual=(640,480,16)
                    requested=((640,480,16),(800,600,32),(0,0,32))[mode]
                    for driver_result in (0,1):
                        out.append((seed,flags,depth,driver_result,*actual,*requested,7,0))
    for flags in (0,1,0x102):
        for selected in (1,2,3,4,5,6,7,8):
            actual=(640,480,16);requested=actual
            out.append((0,flags,16,1,*actual,*requested,selected,1))
    return out

def source_record(module,data):
    path=ROOT/'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/functions.jsonl'
    f=next(v for v in map(json.loads,path.read_text(encoding='utf8').splitlines()) if v['entry_va']=='004677e0')
    start,end=(int(v,16) for v in f['ranges'][0]);rva=start-int(module['image_base'],16)
    section=next(s for s in module['sections'] if s['rva']<=rva and rva+end-start<s['rva']+s['raw_size'])
    offset=section['raw_offset']+rva-section['rva']
    return {'sha256':SHA,'body_sha256':hashlib.sha256(data[offset:offset+end-start+1]).hexdigest(),**f}

def main():
    parser=argparse.ArgumentParser()
    parser.add_argument('--probe',type=Path,default=ROOT/'local/builds/v2/render-display-032/bin/Release/render_display_probe.exe')
    parser.add_argument('--report-dir',type=Path,default=RUN)
    args=parser.parse_args();module,data=module_and_data();inputs=cases()
    native=subprocess.run([str(args.probe)],input='\n'.join(' '.join(map(str,v)) for v in inputs)+'\n',
                          text=True,capture_output=True,check=True,timeout=60)
    rows=list(map(json.loads,native.stdout.splitlines()))
    if len(rows)!=len(inputs):raise RuntimeError('native row count mismatch')
    fixtures=[]
    for i,(case,actual) in enumerate(zip(inputs,rows)):
        expected=original(module,data,case)
        if actual!=expected:
            args.report_dir.mkdir(parents=True,exist_ok=True)
            dest=args.report_dir/'mismatch.json';dest.write_text(json.dumps({'case':case,'expected':expected,'actual':actual},indent=2)+'\n')
            raise RuntimeError(f'case {i} differs: {[k for k in expected if expected[k]!=actual.get(k)]}; {dest}')
        fixtures.append({'case':case,'output_sha256':hashlib.sha256(json.dumps(expected,sort_keys=True).encode()).hexdigest()})
    paths=['iterations/v2/001-original-recovery/source/include/porsche/render_display.hpp',
           'iterations/v2/001-original-recovery/source/include/porsche/render_objects.hpp',
           'iterations/v2/001-original-recovery/source/include/porsche/render_startup.hpp',
           'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/render_display.cpp',
           'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/render_objects.cpp',
           'iterations/v2/001-original-recovery/source/recovered/render_display_probe.cpp',
           'iterations/v2/001-original-recovery/runs/032-render-display/CMakeLists.txt',
           'scripts/research/verify-v2-render-display.py']
    full_cases=sum(bool(case[-1]) for case in inputs)
    report={'schema':1,'sha256':SHA,'cases':len(inputs),'native_cpp_equal_original_x86':True,
            'function_vas':['004677e0'],'full_function_vas':['004677e0'] if full_cases else [],
            'partial_function_vas':[],
            'full_constructor_cases':full_cases,'coverage_through':'00467ebe RET 0x10',
            'binary_matched':False,'game_launch_verified':False,
            'source_sha256':{p:hashlib.sha256((ROOT/p).read_bytes().replace(b'\r\n',b'\n')).hexdigest() for p in paths},
            'probe_sha256':hashlib.sha256(args.probe.read_bytes()).hexdigest(),'fixtures':fixtures}
    args.report_dir.mkdir(parents=True,exist_ok=True)
    report['source_sha256']=source_hashes(report['source_sha256'].keys(),compiled_sources=['iterations/v2/001-original-recovery/source/recovered/Porsche.exe/application_state.cpp','iterations/v2/001-original-recovery/source/recovered/Porsche.exe/application_globals.cpp'])
    (args.report_dir/'verification.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf8')
    (args.report_dir/'source-functions.jsonl').write_text(json.dumps(source_record(module,data))+'\n',encoding='utf8')
    print(json.dumps({'cases':len(inputs),'full_constructor_cases':full_cases,
                      'through':'00467ebe RET 0x10','native_cpp_equal_original_x86':True}))

if __name__=='__main__':main()
