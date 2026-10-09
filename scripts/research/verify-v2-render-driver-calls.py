"""Differentially execute the THRASH video-mode/configuration dispatch path."""
import argparse,hashlib,json,struct,subprocess,sys
from pathlib import Path

from v2_source_dependencies import source_hashes

ROOT=Path(__file__).resolve().parents[2]
ITER=ROOT/'iterations/v2/001-original-recovery'
RUN=ITER/'runs/056-render-driver-calls'
SHA='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_EIP,UC_X86_REG_ESP

STACK,ABOUT,MODES,ABOUT_FN,EXIT=0x3101000,0x3103000,0x3104000,0x3300000,0x3200000
ABOUT_PROC,APPLY=0x572a12,0x5728b0
def put(u,a,v):u.mem_write(a,struct.pack('<I',v&0xffffffff))
def get(u,a):return struct.unpack('<I',u.mem_read(a,4))[0]

def cases():
    def rec(w,h,m,two,one,extra=0):
        x=[w,h,m,extra,1,two,one,0,0,0]
        return x
    return [
      (1,[640,480,8,0,0,0],[0,0,0],[]),
      (1,[800,600,16,1,0,0],[0,0,0],[rec(800,600,16,1,0)]),
      (1,[1024,768,16,3,1,0],[0,0,0],[rec(1024,768,16,3,1),rec(1024,768,32,3,1)]),
      (1,[640,480,16,0,1,0],[0,0,0],[rec(640,480,8,0,1),rec(640,480,16,0,1)]),
      (1,[1280,720,32,4,1,0],[0,0,0],[rec(1280,720,32,4,1),rec(1280,720,24,2,1)]),
      (1,[640,480,9,2,0,0],[0,0,0],[rec(640,480,8,2,0),rec(640,480,10,2,0)]),
      (1,[640,480,10,0,0,0],[0,0,0],[[640,480,0xffffffff,0,1,0xffffffff,0xffffffff,0,0,0]]),
      (1,[640,480,0x80000000,0,0,0],[0,0,0],[rec(640,480,0,0,0)]),
      (0,[0x11,0x22,0x33,640,480,0x66],[1280,720,32],[]),
      (0,[0xffffffff,0,7,800,600,0xabcdef01],[0x10,0x20,0x30],[]),
      (0,[1,2,3,4,5,6],[0,0,0],[]),
    ]

def original(module,data,case):
    op,args,limits,records=case
    u=Uc(UC_ARCH_X86,UC_MODE_32);u.mem_map(0x400000,0x300000)
    for sec in module['sections']:
        if sec['raw_size']:u.mem_write(0x400000+sec['rva'],data[sec['raw_offset']:sec['raw_offset']+sec['raw_size']])
    u.mem_map(0x3100000,0x10000);u.mem_map(EXIT,0x1000);u.mem_map(ABOUT_FN,0x1000);u.mem_write(EXIT,b'\xc3'*0x1000)
    u.mem_write(ABOUT,b'\0'*0x100);u.mem_write(MODES,b'\0'*0x1000)
    put(u,ABOUT+0x3c,len(records));put(u,ABOUT+0x40,MODES)
    for i,row in enumerate(records,1):
        for j,value in enumerate(row):put(u,MODES+i*40+j*4,value)
    put(u,0x6bd934,ABOUT_FN)
    for va,value in zip((0x6a6448,0x6a6444,0x6a6440),limits):put(u,va,value)
    events=[]
    def hook(mu,address,_size,_):
        if address not in (ABOUT_FN,APPLY):return
        sp=mu.reg_read(UC_X86_REG_ESP);ret=get(mu,sp)
        if address==ABOUT_FN:
            mu.reg_write(UC_X86_REG_EAX,ABOUT);mu.reg_write(UC_X86_REG_ESP,sp+4)
        else:
            vals=[get(mu,sp+4+i*4) for i in range(4)];events.append(vals)
            mu.reg_write(UC_X86_REG_EAX,0);mu.reg_write(UC_X86_REG_ESP,sp+4)
        mu.reg_write(UC_X86_REG_EIP,ret)
    u.hook_add(UC_HOOK_CODE,hook)
    put(u,STACK,EXIT)
    for i,value in enumerate(args):put(u,STACK+4+i*4,value)
    u.reg_write(UC_X86_REG_ESP,STACK)
    entry=0x5376c0 if op else 0x537600
    try:u.emu_start(entry,EXIT,count=10000)
    except Exception as exc:raise RuntimeError(f'x86 failed for {case}: EIP={u.reg_read(UC_X86_REG_EIP):08x} events={events}') from exc
    delta=u.reg_read(UC_X86_REG_ESP)-STACK
    if op:return {'result':u.reg_read(UC_X86_REG_EAX),'about_calls':1,'about_proc':0x13572468,'stack_delta':delta}
    globals_out=[get(u,va) for va in (0x69e094,0x69e08c,0x69e090,0x69e070,0x69e074,0x69e06c,
      0x6a643c,0x6a6438,0x6a6430,0x6a6434)]
    return {'globals':globals_out,'applied':events,'stack_delta':delta}

def main():
    p=argparse.ArgumentParser();p.add_argument('--probe',type=Path,default=ROOT/'local/builds/v2/render-driver-calls-056/bin/Release/render_driver_calls_probe.exe');p.add_argument('--report',type=Path,default=RUN/'verification.json');a=p.parse_args()
    module=next(json.loads(x) for x in (ROOT/'research/binary-index/static/binaries.jsonl').read_text(encoding='utf8').splitlines() if json.loads(x)['file']=='Porsche.exe')
    data=(ROOT/'local/game'/module['path']).read_bytes();assert hashlib.sha256(data).hexdigest()==SHA
    inputs=cases()
    text=''.join(' '.join(map(str,[op,*args,*limits,len(rows),*(v for row in rows for v in row)]))+'\n' for op,args,limits,rows in inputs)
    proc=subprocess.run([str(a.probe)],input=text,text=True,capture_output=True,check=True)
    lines=proc.stdout.splitlines();assert len(lines)==len(inputs),(len(lines),len(inputs),proc.stderr)
    fixtures=[]
    for case,line in zip(inputs,lines):
        op,args,limits,rows=case;parts=list(map(int,line.split()[1:]));expected=original(module,data,case)
        if op:
            native={'result':parts[0],'about_calls':parts[1],'about_proc':parts[2]}
            assert expected['stack_delta']==4,expected
            if native!={'result':expected['result'],'about_calls':1,'about_proc':0x13572468}:
                raise RuntimeError(f'{case}: x86={expected} native={native}')
        else:
            native={'globals':parts[:10],'applied':[parts[10:14]],'apply_calls':parts[14]}
            assert expected['stack_delta']==4,expected
            if native!={'globals':expected['globals'],'applied':expected['applied'],'apply_calls':1}:
                raise RuntimeError(f'{case}: x86={expected} native={native}')
        fixtures.append({'input':{'op':op,'args':args,'limits':limits,'records':rows},'output':native})
    rel=lambda x:x.relative_to(ROOT).as_posix()
    deps=[ITER/'source/include/porsche/render_driver_calls.hpp',ITER/'source/include/porsche/render_display.hpp',ITER/'source/include/porsche/render_loader.hpp',ITER/'source/include/porsche/render_objects.hpp',ITER/'source/include/porsche/render_startup.hpp',ITER/'source/recovered/Porsche.exe/render_driver_calls.cpp',ITER/'source/recovered/Porsche.exe/render_loader.cpp',ITER/'source/recovered/render_driver_calls_probe.cpp',ROOT/'research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm',ROOT/'research/v2/binaries/Porsche.exe-ddd748fdbe6d/decompiled.c',RUN/'CMakeLists.txt',RUN/'README.md',Path(__file__).resolve()]
    report={'schema':1,'binary':'Porsche.exe','sha256':SHA,'entry_va':'00537600,005376c0','coverage':'full wrapper/config-selection bodies; typed downstream boundary at 005728b0 and loader about adapter at 006bd934','full_function_vas':['00537600','005376c0','005726f0','00572990','00572a00'],'partial_function_vas':[],'cases':len(inputs),'native_cpp_equal_original_x86':True,'binary_matched':False,'game_launch_verified':False,'boundaries':'005728b0 remains a typed four-argument cdecl engine/window boundary. THRASH_about is dispatched through render_thrash_exports_006bd910 slot VA 006bd934 and the existing render_loader_about_006bd934 adapter. Requested/configuration globals are owned here once and not duplicated by display/loader source.','source_sha256':{rel(x):hashlib.sha256(x.read_bytes().replace(b'\r\n',b'\n')).hexdigest() for x in deps},'probe_sha256':hashlib.sha256(a.probe.read_bytes()).hexdigest(),'fixtures':fixtures}
    report['source_sha256']=source_hashes(report['source_sha256'].keys(),compiled_sources=['iterations/v2/001-original-recovery/source/recovered/Porsche.exe/render_driver_calls.cpp', 'iterations/v2/001-original-recovery/source/recovered/render_driver_calls_probe.cpp'])
    a.report.parent.mkdir(parents=True,exist_ok=True);a.report.write_text(json.dumps(report,indent=2)+'\n',encoding='utf8')
    print(json.dumps({'cases':len(inputs),'full_function_vas':report['full_function_vas'],'native_cpp_equal_original_x86':True,'remaining_boundary':'005728b0'}))
if __name__=='__main__':main()
