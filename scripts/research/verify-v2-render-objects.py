"""Compare complete 0x467700 and bounded 0x4677e0 prefix against original x86."""
import argparse
import hashlib
import json
from pathlib import Path
import struct
import subprocess
import sys

ROOT=Path(__file__).resolve().parents[2]
RUN=ROOT/'iterations/v2/001-original-recovery/runs/026-render-objects'
sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ECX,UC_X86_REG_ESP,UC_X86_REG_EIP

CORE,DISPLAY,PUBLISHER,TITLE,STACK,EXIT=(0x3102000,0x3101000,0x3200000,0x3200100,0x3308000,0x3400000)
SHA='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'

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
    for address,size in ((0x3100000,0x4000),(0x3200000,0x2000),(0x3300000,0x10000),(EXIT,0x1000)):
        uc.mem_map(address,size)
    return uc

def put32(uc,address,value):uc.mem_write(address,struct.pack('<I',value&0xffffffff))
def read32(uc,address):return struct.unpack('<I',uc.mem_read(address,4))[0]

def original(module,data,seed,flags,first,second):
    uc=machine(module,data)
    uc.mem_write(PUBLISHER,b'Electronic Arts\x00')
    uc.mem_write(TITLE,b'Need for Speed - Porsche Unleashed\x00')
    uc.mem_write(CORE,bytes([seed])*0x118)
    put32(uc,STACK,EXIT);put32(uc,STACK+4,PUBLISHER);put32(uc,STACK+8,TITLE)
    uc.reg_write(UC_X86_REG_ECX,CORE);uc.reg_write(UC_X86_REG_ESP,STACK)
    uc.emu_start(0x467700,EXIT,count=100)
    if uc.reg_read(UC_X86_REG_EIP)!=EXIT or uc.reg_read(UC_X86_REG_EAX)!=CORE:
        raise RuntimeError('core original return mismatch')
    core=bytes(uc.mem_read(CORE,0x118)).hex()
    uc.mem_write(DISPLAY,bytes([seed])*0x80)
    put32(uc,0x628130,0);put32(uc,0x5deb1c,0xabcdef01)
    for i,v in enumerate((EXIT,PUBLISHER,7,flags,TITLE)):put32(uc,STACK+4*i,v)
    uc.reg_write(UC_X86_REG_ECX,DISPLAY);uc.reg_write(UC_X86_REG_ESP,STACK)
    calls=['first'];clock_index=0;member_index=0
    def hook(machine,address,_size,_user):
        nonlocal clock_index,member_index
        if address not in (0x466380,0x555bc0):return
        if address==0x466380:
            pointer=machine.reg_read(UC_X86_REG_ECX)
            if pointer!=DISPLAY+0x14+0x20*member_index:
                raise RuntimeError(f'member thiscall pointer {pointer:#x}')
            calls.append('member14' if member_index==0 else 'member34')
            machine.mem_write(pointer,bytes([0xa1 if member_index==0 else 0xb2])*0x20)
            member_index+=1
        else:
            calls.append('clock')
            machine.reg_write(UC_X86_REG_EAX,(first,second)[clock_index])
            clock_index+=1
        sp=machine.reg_read(UC_X86_REG_ESP)
        machine.reg_write(UC_X86_REG_EIP,read32(machine,sp))
        machine.reg_write(UC_X86_REG_ESP,sp+4)
    uc.hook_add(UC_HOOK_CODE,hook)
    uc.emu_start(0x4677e0,0x46784f,count=200)
    if uc.reg_read(UC_X86_REG_EIP)!=0x46784f or member_index!=2 or clock_index!=2:
        raise RuntimeError('display prefix did not stop at Win32 boundary')
    return {'core':core,'adapter':core,'display':bytes(uc.mem_read(DISPLAY,0x80)).hex(),
            'raw_return':True,'adapter_return':True,
            'global_display':read32(uc,0x628130)==DISPLAY,
            'global_clock':read32(uc,0x5deb1c),'calls':','.join(calls)}

def source_record(module,data,va):
    path=ROOT/'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/functions.jsonl'
    f=next(v for v in map(json.loads,path.read_text(encoding='utf8').splitlines()) if v['entry_va']==va)
    start,end=(int(v,16) for v in f['ranges'][0]);rva=start-int(module['image_base'],16)
    section=next(s for s in module['sections'] if s['rva']<=rva and rva+end-start<s['rva']+s['raw_size'])
    offset=section['raw_offset']+rva-section['rva']
    return {'sha256':SHA,'body_sha256':hashlib.sha256(data[offset:offset+end-start+1]).hexdigest(),**f}

def main():
    parser=argparse.ArgumentParser()
    parser.add_argument('--probe',type=Path,default=ROOT/'local/builds/v2/001-original-recovery/bin/Release/render_objects_probe.exe')
    args=parser.parse_args()
    module,data=module_and_data()
    cases=[(s,f,c1,c2) for s in (0,0x5a,0xcc,0xff) for f in (0,1,0x102,0xffffffff)
           for c1,c2 in ((0,0),(1,0x12345678))]
    lines=['%x %x %x %x'%case for case in cases]
    native=subprocess.run([str(args.probe)],input='\n'.join(lines)+'\n',text=True,capture_output=True,check=True,timeout=60)
    actual=list(map(json.loads,native.stdout.splitlines()))
    if len(actual)!=len(cases):raise RuntimeError('native row count mismatch')
    fixtures=[]
    for i,(case,row) in enumerate(zip(cases,actual)):
        expected=original(module,data,*case)
        if row!=expected:
            RUN.mkdir(parents=True,exist_ok=True)
            dest=RUN/'mismatch.json'
            dest.write_text(json.dumps({'case':case,'expected':expected,'actual':row},indent=2)+'\n')
            raise RuntimeError(f'case {i} differs in {[k for k in expected if expected[k]!=row.get(k)]}: {dest}')
        fixtures.append({'case':case,'output_sha256':hashlib.sha256(json.dumps(expected,sort_keys=True).encode()).hexdigest()})
    records=[source_record(module,data,va) for va in ('00467700','004677e0')]
    paths=['iterations/v2/001-original-recovery/source/include/porsche/render_objects.hpp',
           'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/render_objects.cpp',
           'iterations/v2/001-original-recovery/source/recovered/render_objects_probe.cpp',
           'scripts/research/verify-v2-render-objects.py']
    report={'schema':1,'sha256':SHA,'cases':len(cases),'native_cpp_equal_original_x86':True,
            'function_vas':['00467700','004677e0'],
            'full_function_vas':['00467700'],'partial_function_vas':['004677e0'],
            'partial_coverage':{'004677e0':'004677e0..00467849 inclusive; stop before 0046784f GetDesktopWindow'},
            'display_stopped_before':'0046784f GetDesktopWindow',
            'binary_matched':False,'game_launch_verified':False,
            'source_sha256':{p:hashlib.sha256((ROOT/p).read_bytes().replace(b'\r\n',b'\n')).hexdigest() for p in paths},
            'probe_sha256':hashlib.sha256(args.probe.read_bytes()).hexdigest(),'fixtures':fixtures}
    RUN.mkdir(parents=True,exist_ok=True)
    (RUN/'verification.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf8')
    (RUN/'source-functions.jsonl').write_text(''.join(json.dumps(v)+'\n' for v in records),encoding='utf8')
    print(json.dumps({'cases':len(cases),'full_core':True,'display_prefix':True,'native_cpp_equal_original_x86':True}))

if __name__=='__main__':main()
