"""Run original Porsche.exe THRASH DLL loader beside native C++ with typed Win32 hooks."""
import argparse
import hashlib
import json
from pathlib import Path
import struct
import subprocess
import sys

ROOT=Path(__file__).resolve().parents[2]
RUN=ROOT/'iterations/v2/001-original-recovery/runs/028-render-loader'
sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ESP,UC_X86_REG_EIP

SHA='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
DRIVER,STACK,EXIT,STUB,PROC,ABOUT=(0x3200000,0x3308000,0x3400000,0x3500000,0x3600000,0x3700000)
IAT={0x5b2050:0x3500000,0x5b205c:0x3500010,0x5b2088:0x3500020,
     0x5b2138:0x3500030,0x5b21b4:0x3500040,0x5b213c:0x3500050}
REPORT=0x3500400

def module_and_data():
    index=ROOT/'research/binary-index/static/binaries.jsonl'
    module=next(v for v in map(json.loads,index.read_text(encoding='utf8').splitlines()) if v['file']=='Porsche.exe')
    data=(ROOT/'local/game'/module['path']).read_bytes()
    if module['sha256']!=SHA or hashlib.sha256(data).hexdigest()!=SHA:
        raise RuntimeError('Porsche.exe SHA mismatch')
    return module,data

def machine(module,data):
    uc=Uc(UC_ARCH_X86,UC_MODE_32);base=int(module['image_base'],16)
    uc.mem_map(base,0x300000)
    for section in module['sections']:
        uc.mem_write(base+section['rva'],data[section['raw_offset']:section['raw_offset']+section['raw_size']])
    for address,size in ((DRIVER,0x2000),(0x3300000,0x10000),(EXIT,0x1000),
                         (STUB,0x1000),(PROC,0x1000),(ABOUT,0x1000)):
        uc.mem_map(address,size)
    for iat,stub in IAT.items():put32(uc,iat,stub)
    put32(uc,0x5debf0,REPORT)
    return uc

def put32(uc,address,value):uc.mem_write(address,struct.pack('<I',value&0xffffffff))
def get32(uc,address):return struct.unpack('<I',uc.mem_read(address,4))[0]
def cstr(uc,address):return bytes(uc.mem_read(address,512)).split(b'\x00',1)[0].decode('latin1')

def original(module,data,case):
    mode,missing,has_module,about_kind,major,token=case
    uc=machine(module,data);uc.mem_write(DRIVER,b'dx7\x00')
    uc.mem_write(0x6bd910,bytes([0xcc])*172)
    for address,value in ((0x69e5e8,0x9999),(0x69e5ec,token),(0x6a64b4,0x7777),
                          (0x5deb70,0x88),(0x5deb74,0x6666),(0x5deb78,0x5555)):
        put32(uc,address,value)
    put32(uc,STACK,EXIT);put32(uc,STACK+4,0 if mode==0 else DRIVER)
    uc.reg_write(UC_X86_REG_ESP,STACK)
    calls=[];proc_index=0
    def record(s):calls.append(s+';')
    def hook(machine,address,_size,_user):
        nonlocal proc_index
        if address not in (*IAT.values(),REPORT,0x5a0fbf,0x574eb0,0x594f00) and not PROC<=address<PROC+0x1000:
            return
        sp=machine.reg_read(UC_X86_REG_ESP);ret=get32(machine,sp)
        arg=lambda i:get32(machine,sp+4+4*i)
        result=0;cleanup=0
        if address==IAT[0x5b2050]:
            name=cstr(machine,arg(0));record('load|'+name);cleanup=4
            if mode==1:result=0x11110000
            elif mode==2 and name=='dx7z':result=0x22220000
        elif address==IAT[0x5b205c]:
            symbol=cstr(machine,arg(1));record(f'getproc|{arg(0)}|{symbol}');cleanup=8
            result=0 if proc_index==missing else PROC+proc_index*0x10
            proc_index+=1
        elif address==IAT[0x5b2088]:record(f'free|{arg(0)}');cleanup=4;result=1
        elif address==IAT[0x5b2138]:
            record('module|'+cstr(machine,arg(0)));cleanup=4;result=0x33330000 if has_module else 0
        elif address==IAT[0x5b21b4]:record(f'disable|{arg(0)}');cleanup=4;result=1
        elif address==IAT[0x5b213c]:record('lasterror');result=5
        elif address==REPORT:record('report|'+cstr(machine,arg(0)))
        elif address==0x5a0fbf:
            fmt=cstr(machine,arg(1))
            if fmt=='%s':out=cstr(machine,arg(2))
            elif fmt=='%sz':out=cstr(machine,arg(2))+'z'
            elif fmt.startswith('You have DirectX'):
                out=fmt%(arg(2),cstr(machine,arg(3)))
            elif fmt.startswith('THRASH_opendll - LOADLIBRARY'):
                out=fmt%(cstr(machine,arg(2)),arg(3),arg(4))
            else:raise RuntimeError(f'unexpected format {fmt!r}')
            machine.mem_write(arg(0),out.encode('latin1')+b'\x00')
            record(f'format|{fmt}|{out}')
        elif address==0x574eb0:
            record('directx|'+cstr(machine,arg(1)))
            put32(machine,arg(0),0);put32(machine,arg(0)+4,major)
        elif address==0x594f00:record(f'reset|{arg(0)}')
        elif PROC<=address<PROC+0x1000:
            index=(address-PROC)//0x10
            if index==24:
                record(f'setstate|{arg(0)}|{arg(1)}');cleanup=8
            elif index==0:
                record('about')
                if about_kind:
                    put32(machine,ABOUT,{1:0x33444658,2:0x33444632,3:0x11223344}[about_kind])
                    result=ABOUT
            else:raise RuntimeError(f'unexpected exported call index {index}')
        machine.reg_write(UC_X86_REG_EAX,result)
        machine.reg_write(UC_X86_REG_ESP,sp+4+cleanup)
        machine.reg_write(UC_X86_REG_EIP,ret)
    uc.hook_add(UC_HOOK_CODE,hook)
    uc.emu_start(0x574fa0,EXIT,count=6000)
    if uc.reg_read(UC_X86_REG_EIP)!=EXIT:raise RuntimeError('loader did not return')
    driver=get32(uc,0x6a64b4)
    return {'ret':uc.reg_read(UC_X86_REG_EAX),
            'exports':bytes(uc.mem_read(0x6bd910,172)).hex(),
            'handle':get32(uc,0x69e5e8),'driver':DRIVER if driver==DRIVER else driver,
            'err_flag':get32(uc,0x5deb70),'err_file':get32(uc,0x5deb74),
            'err_line':get32(uc,0x5deb78),'calls':''.join(calls).encode('latin1').hex()}

def cases():
    out=[(0,-1,0,0,8,17)]
    out.extend((mode,-1,has_module,about,8,17) for mode in (1,2)
               for has_module in (0,1) for about in (0,1,2,3))
    out.extend((1,missing,1,1,8,23) for missing in range(36))
    out.extend((3,-1,0,0,major,19) for major in (0,5,6,7,8,0x10006))
    return out

def source_record(module,data):
    path=ROOT/'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/functions.jsonl'
    f=next(v for v in map(json.loads,path.read_text(encoding='utf8').splitlines()) if v['entry_va']=='00574fa0')
    start,end=(int(v,16) for v in f['ranges'][0]);rva=start-int(module['image_base'],16)
    section=next(s for s in module['sections'] if s['rva']<=rva and rva+end-start<s['rva']+s['raw_size'])
    offset=section['raw_offset']+rva-section['rva']
    return {'sha256':SHA,'body_sha256':hashlib.sha256(data[offset:offset+end-start+1]).hexdigest(),**f}

def main():
    parser=argparse.ArgumentParser()
    parser.add_argument('--probe',type=Path,default=ROOT/'local/builds/v2/render-loader-028/bin/Release/render_loader_probe.exe')
    args=parser.parse_args();module,data=module_and_data();inputs=cases()
    native=subprocess.run([str(args.probe)],input='\n'.join(' '.join(map(str,v)) for v in inputs)+'\n',
                          text=True,capture_output=True,check=True,timeout=60)
    rows=list(map(json.loads,native.stdout.splitlines()))
    if len(rows)!=len(inputs):raise RuntimeError('native row count mismatch')
    fixtures=[]
    for i,(case,actual) in enumerate(zip(inputs,rows)):
        expected=original(module,data,case)
        if actual!=expected:
            RUN.mkdir(parents=True,exist_ok=True)
            dest=RUN/'mismatch.json';dest.write_text(json.dumps({'case':case,'expected':expected,'actual':actual},indent=2)+'\n')
            raise RuntimeError(f'case {i} differs: {[k for k in expected if expected[k]!=actual.get(k)]}; {dest}')
        fixtures.append({'case':case,'output_sha256':hashlib.sha256(json.dumps(expected,sort_keys=True).encode()).hexdigest()})
    paths=['iterations/v2/001-original-recovery/source/include/porsche/render_loader.hpp',
           'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/render_loader.cpp',
           'iterations/v2/001-original-recovery/source/recovered/render_loader_probe.cpp',
           'scripts/research/verify-v2-render-loader.py']
    report={'schema':1,'sha256':SHA,'cases':len(inputs),'native_cpp_equal_original_x86':True,
            'function_vas':['00574fa0'],'full_function_vas':['00574fa0'],'partial_function_vas':[],
            'binary_matched':False,'game_launch_verified':False,
            'source_sha256':{p:hashlib.sha256((ROOT/p).read_bytes().replace(b'\r\n',b'\n')).hexdigest() for p in paths},
            'probe_sha256':hashlib.sha256(args.probe.read_bytes()).hexdigest(),'fixtures':fixtures}
    RUN.mkdir(parents=True,exist_ok=True)
    (RUN/'verification.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf8')
    (RUN/'source-functions.jsonl').write_text(json.dumps(source_record(module,data))+'\n',encoding='utf8')
    print(json.dumps({'cases':len(inputs),'function_vas':['00574fa0'],'native_cpp_equal_original_x86':True}))

if __name__=='__main__':main()
