from v2_source_dependencies import source_hashes
"""Differentially verify bounded Porsche.exe startup dispatch and CD relaunch."""
import argparse
import hashlib
import json
from pathlib import Path
import re
import struct
import subprocess
import sys

ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ECX,UC_X86_REG_ESP,UC_X86_REG_EIP

STACK,EXIT,ARENA=0x200f000,0x2200000,0x3600000
FUNCTIONS=[0x4a5410,0x4a5c30]
BOUNDARIES={
    0x59e9d0:4,0x59edb0:2,0x565030:1,0x59ef90:1,0x48fc80:0,
    0x55fcf0:0,0x564e70:0,0x564ab0:0,0x564850:1,0x536e50:0,
    0x5367b0:3,0x4b6ff0:0,0x563ad0:3,0x5655f0:1,0x5a2c24:1,
    0x5a0fbf:3,0x5a246e:1,
}
IAT={0x5b2064:(0x2200100,'module',3),0x5b2060:(0x2200200,'drive_type',1),
     0x5b204c:(0x2200300,'create_process',10)}

def cases():
    rows=[(0,existing,allocated,0,3,1,'-') for existing,allocated in ((0,0),(0,1),(1,0),(1,1))]
    for name in ('-','C:\\Game\\Porsche.exe','D:\\Porsche.exe','C:/Porsche.exe'):
        branches=((0,3,1),) if name=='-' else ((0,3,1),(1,3,1),(1,5,0),(1,5,1))
        for check,kind,created in branches:
            rows.append((1,0,0,check,kind,created,name))
    return rows

def original(case,module,data,functions):
    mode,existing,allocated,check,kind,created,filename=case
    uc=Uc(UC_ARCH_X86,UC_MODE_32);base=int(module['image_base'],16)
    uc.mem_map(base,0x300000)
    for s in module['sections']:uc.mem_write(base+s['rva'],data[s['raw_offset']:s['raw_offset']+s['raw_size']])
    uc.mem_map(0x2000000,0x10000);uc.mem_write(0x2000000,b'\xcc'*0x10000)
    uc.mem_map(EXIT,0x1000);uc.mem_map(ARENA,0x10000)
    def word(p):return struct.unpack('<I',uc.mem_read(p,4))[0]
    def put(p,v):uc.mem_write(p,struct.pack('<I',v&0xffffffff))
    def string(p,limit=300):return bytes(uc.mem_read(p,limit)).split(b'\0',1)[0].decode('latin1')
    put(0x5debf0,0);put(0x628c70,ARENA+0x400 if existing else 0)
    for address,(target,_,_) in IAT.items():put(address,target)
    calls=[];hit=set();terminal=False
    ranges=[(int(x,16),int(y,16)) for va in FUNCTIONS for x,y in functions[f'{va:08x}']['ranges']]
    def hook(machine,p,size,user):
        nonlocal terminal
        if p==EXIT:machine.emu_stop();return
        if p in FUNCTIONS:hit.add(f'{p:08x}')
        if p not in BOUNDARIES and p not in {x[0] for x in IAT.values()}:
            if not any(start<=p<=end for start,end in ranges):raise RuntimeError(f'Unexpected original code {p:08x}')
            return
        sp=machine.reg_read(UC_X86_REG_ESP)
        if p in BOUNDARIES:
            n=BOUNDARIES[p];stdcall=False;name=None
        else:
            name,n=next((name,n) for target,name,n in IAT.values() if target==p);stdcall=True
        vals=struct.unpack('<'+'I'*(n+1),machine.mem_read(sp,4*(n+1)))
        ret,args=vals[0],vals[1:];value=0
        if p==0x48fc80:calls.append([p,machine.reg_read(UC_X86_REG_ECX)])
        elif p==0x59ef90:calls.append([p,*args]);value=ARENA+0x200 if allocated else 0
        elif p==0x5655f0:calls.append(['name',string(args[0])])
        elif p==0x5a2c24:
            arg=args[0] if args[0]<0x80000000 else args[0]-0x100000000
            calls.append([p,arg]);value=check
        elif p==0x5a0fbf:
            if args[1]==0x5d1290:
                ch=args[2]&255;calls.append(['drive_format',args[2] if args[2]<0x80000000 else args[2]-0x100000000]);machine.mem_write(args[0],bytes([ch])+b':\\\0')
            elif args[1]==0x5d1280:
                drive=string(args[2]);calls.append(['command_format',drive]);machine.mem_write(args[0],(drive+'Autorun.exe').encode('latin1')+b'\0')
            else:raise RuntimeError(f'unexpected format {args[1]:08x}')
        elif p==0x5a246e:
            calls.append([p,args[0]]);terminal=True;machine.emu_stop();return
        elif name=='module':
            calls.append(['module',args[0],args[2]])
            if filename!='-':machine.mem_write(args[1],filename.encode('latin1')+b'\0');value=len(filename)
        elif name=='drive_type':calls.append(['drive_type',string(args[0])]);value=kind
        elif name=='create_process':
            calls.append(['create_process',string(args[1]),args[4],args[5],bytes(machine.mem_read(args[8],68)).hex(),bytes(machine.mem_read(args[9],16)).hex()]);value=created
        else:calls.append([p,*args])
        machine.reg_write(UC_X86_REG_EAX,value)
        machine.reg_write(UC_X86_REG_ESP,sp+4*(n+1) if stdcall else sp+4)
        machine.reg_write(UC_X86_REG_EIP,ret)
    uc.hook_add(UC_HOOK_CODE,hook)
    put(STACK,EXIT);uc.reg_write(UC_X86_REG_ESP,STACK)
    uc.emu_start(FUNCTIONS[mode],EXIT+1,count=100000)
    if not terminal and uc.reg_read(UC_X86_REG_EIP)!=EXIT:raise RuntimeError('original ABI/return failure')
    return {'globals':[word(0x5debf0),word(0x628c70)],'terminal':terminal,'calls':calls},hit

def dependencies():
    root=ROOT/'iterations/v2/001-original-recovery/source'
    queue=[root/'recovered/startup_services_probe.cpp',root/'recovered/Porsche.exe/startup_services.cpp']
    seen=set()
    while queue:
        path=queue.pop()
        if path in seen:continue
        seen.add(path)
        for inc in re.findall(rb'^\s*#include\s+"([^"]+)"',path.read_bytes(),re.M):
            child=root/'include'/inc.decode('ascii')
            if child.exists():queue.append(child)
    return sorted(str(p.relative_to(ROOT)).replace('\\','/') for p in seen)

def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--probe',type=Path,default=ROOT/'local/builds/v2/001-original-recovery/bin/Release/startup_services_probe.exe')
    parser.add_argument('--report-dir',type=Path,default=ROOT/'iterations/v2/001-original-recovery/runs/022-startup-services')
    args=parser.parse_args()
    module=next(x for x in map(json.loads,(ROOT/'research/binary-index/static/binaries.jsonl').read_text().splitlines()) if x['file']=='Porsche.exe')
    data=(ROOT/'local/game'/module['path']).read_bytes()
    if hashlib.sha256(data).hexdigest()!='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39':raise RuntimeError('original SHA mismatch')
    functions={r['entry_va']:r for r in map(json.loads,(ROOT/'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/functions.jsonl').read_text().splitlines())}
    inputs=cases();process=subprocess.run([str(args.probe)],input=''.join(' '.join(map(str,c))+'\n' for c in inputs),text=True,capture_output=True,check=True,timeout=60)
    try:native=list(map(json.loads,process.stdout.splitlines()))
    except json.JSONDecodeError as exc:
        lines=process.stdout.splitlines()
        for index,line in enumerate(lines):
            try:json.loads(line)
            except json.JSONDecodeError:raise RuntimeError(f'native JSON line {index}: {line!r}') from exc
        raise
    if len(native)!=len(inputs):raise RuntimeError('native output count mismatch')
    hit=set();fixtures=[]
    for index,(case,actual) in enumerate(zip(inputs,native)):
        expected,covered=original(case,module,data,functions);hit|=covered
        if expected!=actual:
            path=ROOT/'local/reports/v2-startup-services-mismatch.json';path.parent.mkdir(parents=True,exist_ok=True)
            path.write_text(json.dumps({'case':case,'expected':expected,'actual':actual},indent=2)+'\n')
            raise RuntimeError(f'case {index} differs: {[key for key in expected if expected[key]!=actual.get(key)]}; {path}')
        fixtures.append({'input':case,'output_sha256':hashlib.sha256(json.dumps(expected,sort_keys=True).encode()).hexdigest()})
    if hit!={f'{v:08x}' for v in FUNCTIONS}:raise RuntimeError('original coverage incomplete')
    paths=dependencies();report={'schema':1,'module':'Porsche.exe','sha256':module['sha256'],
        'function_vas':sorted(hit),'cases':len(inputs),'native_cpp_equal_original_x86':True,'binary_matched':False,
        'comparison':'Global callback/network pointer, conditional ordered typed callee/Win32 calls, normalized buffers at OS calls, terminal exit branch.',
        'boundaries':'All 004a5410 subsystem initializers, CRT formatter/drive predicate/name, Win32 filename/drive/process and exit are recording endpoints; no callee behavior or actual process launch is claimed.',
        'source_sha256':{p:hashlib.sha256((ROOT/p).read_bytes().replace(b'\r\n',b'\n')).hexdigest() for p in paths},
        'probe_sha256':hashlib.sha256(args.probe.read_bytes()).hexdigest(),'fixtures':fixtures}
    args.report_dir.mkdir(parents=True,exist_ok=True)
    report['source_sha256']=source_hashes([*report['source_sha256'],Path(__file__)])
    (args.report_dir/'verification.json').write_text(json.dumps(report,indent=2)+'\n',newline='\n')
    print(json.dumps({'cases':len(inputs),'function_vas':sorted(hit),'native_cpp_equal_original_x86':True}))

if __name__=='__main__':main()
