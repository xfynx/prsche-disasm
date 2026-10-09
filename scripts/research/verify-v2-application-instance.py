"""Compare recovered named-instance initialization with original Porsche.exe x86."""
import argparse
import hashlib
import json
from pathlib import Path
import struct
import subprocess
import sys

from v2_source_dependencies import source_hashes

ROOT=Path(__file__).resolve().parents[2]
RUN=ROOT/'iterations/v2/001-original-recovery/runs/050-application-instance'
sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_EIP,UC_X86_REG_ESP

ARENA,ARENA_BYTES,STACK,EXIT=0x03600000,0x10000,0x0200f000,0x02200000
NAME=0x0069e5a8;MUTEX=0x006a5c28;OVERRIDE=0x006afcc0;EXIT_FLAG=0x005df9bc
CASES=[
    (0,1,2,0x03604000,183,0x03605000,0), # caller's Porsche name; existing HWND
    (0,0,1,0x03604010,183,0,0),         # fallback name through override; no HWND
    (2,0,1,0x03604020,183,0x03605010,0),# retain global name when arg is null
    (2,1,1,0x03604030,183,0x03605020,0),# mutex arg does not replace existing window name
    (0,1,1,0x03604040,0,0x03605030,0),  # not an existing named instance
    (0,1,1,0x03604050,183,0x03605040,1), # duplicate followed by terminal exit boundary
]
NAMES={1:'Porsche',2:'Other',3:'Override'}

def original(case,module,data,function_rows):
    global_id,arg_id,override_id,mutex_handle,last_error,window_handle,exit_flag=case
    uc=Uc(UC_ARCH_X86,UC_MODE_32);base=int(module['image_base'],16);uc.mem_map(base,0x300000)
    for section in module['sections']:
        uc.mem_write(base+section['rva'],data[section['raw_offset']:section['raw_offset']+section['raw_size']])
    uc.mem_map(ARENA,ARENA_BYTES);uc.mem_write(ARENA,b'\xcc'*ARENA_BYTES)
    uc.mem_map(0x02000000,0x10000);uc.mem_map(EXIT,0x2000)
    def put(addr,*vals):uc.mem_write(addr,struct.pack('<'+'I'*len(vals),*(v&0xffffffff for v in vals)))
    def word(addr):return struct.unpack('<I',uc.mem_read(addr,4))[0]
    def readstr(addr):
        if not addr:return None
        out=bytearray()
        while len(out)<256:
            b=uc.mem_read(addr+len(out),1)[0]
            if not b:break
            out.append(b)
        return out.decode('ascii','replace')
    def nameptr(i):return (0x5d1298 if i==1 else ARENA+0x1000 if i==2 else ARENA+0x1100 if i==3 else 0)
    for offset,value in ((0x1000,b'Other'),(0x1100,b'Override')):
        uc.mem_write(ARENA+offset,value+b'\0')
    put(NAME,nameptr(global_id));put(MUTEX,0);put(EXIT_FLAG,exit_flag)
    put(OVERRIDE,ARENA+0x2000);put(ARENA+0x2000,nameptr(override_id))
    calls=[];coverage=set()
    functions=[]
    for va in ('005655f0','00557370'):
        row=function_rows.get(va)
        if row:functions.extend((int(a,16),int(b,16)) for a,b in row['ranges'])
    endpoints={
        EXIT+0x100:('CreateMutexA',3),EXIT+0x110:('GetLastError',0),
        EXIT+0x120:('FindWindowA',2),EXIT+0x130:('ShowWindow',2),
        EXIT+0x140:('SetForegroundWindow',1),0x5a246e:('exit_boundary_005a246e',1)}
    for cell,target in ((0x5b21ac,EXIT+0x100),(0x5b213c,EXIT+0x110),
                        (0x5b22a0,EXIT+0x120),(0x5b22a8,EXIT+0x130),(0x5b2300,EXIT+0x140)):
        put(cell,target)
    terminal=False
    def hook(machine,address,_size,_user):
        nonlocal terminal
        if address==EXIT:machine.emu_stop();return
        if address in (0x5655f0,0x557370):coverage.add(f'{address:08x}')
        endpoint=endpoints.get(address)
        if endpoint is None:
            if not any(lo<=address<=hi for lo,hi in functions):raise RuntimeError(f'unexpected original pc {address:08x}')
            return
        label,n=endpoint;sp=machine.reg_read(UC_X86_REG_ESP);ret,*args=struct.unpack('<'+'I'*(n+1),machine.mem_read(sp,4*(n+1)))
        if label=='CreateMutexA':
            calls.append(['create_mutex',args[0],args[1],readstr(args[2])]);result=mutex_handle
        elif label=='GetLastError':calls.append(['get_last_error']);result=last_error
        elif label=='FindWindowA':calls.append(['find_window',readstr(args[0]),readstr(args[1])]);result=window_handle
        elif label=='ShowWindow':calls.append(['show_window',args[0],args[1]]);result=1
        elif label=='SetForegroundWindow':calls.append(['foreground',args[0]]);result=1
        else:
            calls.append(['exit_boundary_005a246e',args[0]]);terminal=True;machine.emu_stop();return
        machine.reg_write(UC_X86_REG_EAX,result);machine.reg_write(UC_X86_REG_ESP,sp+4*(n+1));machine.reg_write(UC_X86_REG_EIP,ret)
    uc.hook_add(UC_HOOK_CODE,hook)
    arg=nameptr(arg_id);put(STACK,EXIT,arg);uc.reg_write(UC_X86_REG_ESP,STACK)
    uc.emu_start(0x5655f0,EXIT+1,count=10000)
    if not terminal and (uc.reg_read(UC_X86_REG_EIP)!=EXIT or uc.reg_read(UC_X86_REG_ESP)!=STACK+4):raise RuntimeError('original return ABI mismatch')
    finalptr=word(NAME);mhandle=word(MUTEX)
    out={'terminal':terminal,'name':readstr(finalptr),'mutex':mhandle,'calls':calls}
    if not terminal:out['return']=uc.reg_read(UC_X86_REG_EAX)
    return out,coverage

def main():
    parser=argparse.ArgumentParser()
    parser.add_argument("--probe",type=Path,default=ROOT/"local/builds/v2/001-original-recovery/bin/Release/application_instance_probe.exe")
    parser.add_argument("--report-dir",type=Path,default=RUN)
    args=parser.parse_args()
    args.report_dir.mkdir(parents=True,exist_ok=True)
    module=next(x for x in map(json.loads,(ROOT/'research/binary-index/static/binaries.jsonl').read_text().splitlines()) if x['file']=='Porsche.exe')
    binary=(ROOT/'local/game'/module['path']).read_bytes();sha='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
    if hashlib.sha256(binary).hexdigest()!=sha:raise RuntimeError('original SHA mismatch')
    rows={x['entry_va'].lower():x for x in map(json.loads,(ROOT/'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/functions.jsonl').read_text().splitlines())}
    probe=args.probe
    process=subprocess.run([str(probe)],input=''.join(' '.join(map(str,c))+'\n' for c in CASES),text=True,capture_output=True,check=True,timeout=30)
    actual=[json.loads(x) for x in process.stdout.splitlines()]
    if len(actual)!=len(CASES):raise RuntimeError('native output count differs')
    coverage=set();fixtures=[]
    for i,(case,got) in enumerate(zip(CASES,actual)):
        want,hit=original(case,module,binary,rows);coverage|=hit
        if got!=want:raise AssertionError(f'case {i} mismatch: expected {want}; got {got}')
        fixtures.append({'input':case,'output_sha256':hashlib.sha256(json.dumps(want,sort_keys=True).encode()).hexdigest()})
    if not {'005655f0','00557370'}<=coverage:raise RuntimeError('original function coverage incomplete')
    paths=['iterations/v2/001-original-recovery/source/include/porsche/application_instance.hpp',
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/application_instance.cpp',
        'iterations/v2/001-original-recovery/source/recovered/application_instance_probe.cpp',
        'iterations/v2/001-original-recovery/runs/050-application-instance/CMakeLists.txt',
        'scripts/research/verify-v2-application-instance.py']
    report={'schema':1,'module':'Porsche.exe','sha256':sha,'range':'005655f0..0056567c',
        'function_vas':sorted(coverage),'full_function_vas':['00557370','005655f0'],
        'partial_function_vas':['005a246e'],'cases':len(CASES),'native_cpp_equal_original_x86':True,
        'binary_matched':False,'game_launch_verified':False,
        'comparison':'Current window-name contents, mutex global, ordered CreateMutexA/GetLastError/FindWindowA/ShowWindow/SetForegroundWindow calls, and nonterminal return value. The exit-flag case compares state and calls only through terminal 005a246e(0).',
        'boundaries':{'win32':'CreateMutexA, GetLastError, FindWindowA, ShowWindow, and SetForegroundWindow are deterministic fixtures.',
            'terminal':'00557370 is recovered as PUSH 0; CALL 005a246e. The 005a246e leaf is an exit recording boundary; no post-exit behavior is claimed.',
            'scope':'Caller 004a5c30 continues with executable-path and Autorun/CD-ROM handling, which is outside this package.'},
        'source_sha256':{p:hashlib.sha256((ROOT/p).read_bytes().replace(b'\r\n',b'\n')).hexdigest() for p in paths},
        'probe_sha256':hashlib.sha256(probe.read_bytes()).hexdigest(),'fixtures':fixtures}
    report['source_sha256']=source_hashes(report['source_sha256'].keys(),compiled_sources=['iterations/v2/001-original-recovery/source/recovered/Porsche.exe/application_instance.cpp', 'iterations/v2/001-original-recovery/source/recovered/application_instance_probe.cpp'])
    (args.report_dir/'verification.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf8',newline='\n')
    print(json.dumps({'functions':sorted(coverage),'cases':len(CASES),'native_cpp_equal_original_x86':True,'report':str(args.report_dir/'verification.json')}))
if __name__=='__main__':main()
