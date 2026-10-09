"""Differentially compare recovered Porsche.exe 0055f420 with original x86."""
import argparse
import hashlib
import json
from pathlib import Path
import struct
import subprocess
import sys

ROOT=Path(__file__).resolve().parents[2]
RUN=ROOT/'iterations/v2/001-original-recovery/runs/044-window-thread-start'
sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_EIP,UC_X86_REG_ESP

ARENA,STACK,EXIT=0x3600000,0x200f000,0x2200000
ARENA_BYTES=0x20000
IAT={0x5b2074:(0x100,'current_id',0),0x5b2094:(0x200,'current_process',0),
     0x5b2170:(0x300,'current_thread',0),0x5b20a0:(0x400,'duplicate',7),
     0x5b217c:(0x500,'create_thread',6),0x5b209c:(0x600,'resume',1),
     0x5b2188:(0x700,'priority',2),0x5b2164:(0x800,'close',1),0x5b2160:(0x900,'sleep',2)}
FUNCTIONS=(0x55f420,0x55f320,0x55f3b0,0x55f560,0x55f730,0x55f8b0)
CASES=[
    (1,4,0,0,1,0xffffffff,0x4004000,0,0x11110000,1),
    (1,2,3,0x2000,3,0x87654321,0x4004100,1,0x22220000,0xffffffff),
    (1,0,0,0x40,0xfffffffe,0,0,0,0x33330000,7),
    (0,0,0,0,0xffffffff,0xffffffff,0x4004200,0,0x44440000,0xffffffff),
    (0,0,0,0x1000,2,0xabcdef01,0x4004300,2,0x55550000,0),
]

def original(case,module,data,function_rows):
    initialized,capacity,occupied,stack,priority,unused4,created,sleep_target,record_seed,serial=case
    uc=Uc(UC_ARCH_X86,UC_MODE_32);base=int(module['image_base'],16);uc.mem_map(base,0x300000)
    for section in module['sections']:
        uc.mem_write(base+section['rva'],data[section['raw_offset']:section['raw_offset']+section['raw_size']])
    uc.mem_map(ARENA,ARENA_BYTES);uc.mem_write(ARENA,b'\xcc'*ARENA_BYTES)
    uc.mem_map(0x2000000,0x10000);uc.mem_map(EXIT,0x2000)
    def words(p,n):return list(struct.unpack('<'+'I'*n,uc.mem_read(p,4*n)))
    def put(p,*vals):uc.mem_write(p,struct.pack('<'+'I'*len(vals),*[v&0xffffffff for v in vals]))
    for iat,(target,_,_) in IAT.items():put(iat,EXIT+target)
    record,table=ARENA+0x200,ARENA+0x1000
    global_addresses=[0x6a57d0,0x6a57d4,0x6a57d8,0x6a57dc,0x6a57e0,0x6a57e4,0x6a57e8,0x6a57ec,0x5df6a0]
    for address,value in zip(global_addresses,[0,0,0,0,0,0,0,0,serial]):put(address,value)
    put(record,*[record_seed+i*0x101 for i in range(7)])
    for i in range(8):put(table+i*12,0x7000+i if occupied&(1<<i) else 0,0x4005000+i*0x100,0x6000+i)
    if initialized:
        put(0x6a57d8,0x2001000);put(0x6a57dc,1);put(0x6a57e4,table)
        put(0x6a57e8,capacity);put(0x6a57ec,0x2002000)

    calls=[];coverage=set();lock_count=0;sleep_count=0;pending=0
    endpoints={EXIT+target:(name,count) for target,name,count in IAT.values()}
    endpoints.update({0x5322b0:('enter',1),0x5322c0:('leave',1),0x5321f0:('lock_create',0),
                      0x53c290:('fill',3),0x56e5f0:('allocate',1),0x557380:('exit_register',1)})
    ranges=[(int(a,16),int(b,16)) for va in FUNCTIONS for a,b in function_rows[f'{va:08x}']['ranges']]
    def hook(machine,address,_size,_user):
        nonlocal lock_count,sleep_count,pending
        if address==EXIT:machine.emu_stop();return
        if address in FUNCTIONS:coverage.add(f'{address:08x}')
        endpoint=endpoints.get(address)
        if endpoint is None:
            if not any(lo<=address<=hi for lo,hi in ranges):
                raise RuntimeError(f'unexpected x86 address {address:08x}; calls={calls[-5:]}')
            return
        name,count=endpoint;sp=machine.reg_read(UC_X86_REG_ESP)
        ret,*args=words(sp,count+1);result=0
        if name in ('enter','leave'):calls.append([name,args[0]])
        elif name=='lock_create':
            result=0x2001000+lock_count*16;lock_count+=1;calls.append([name,result])
        elif name=='fill':
            calls.append([name,*args]);
            if args[0]:machine.mem_write(args[0],bytes([args[1]&255])*args[2])
        elif name=='allocate':
            requested=words(args[0],1)[0];rounded=(requested+4095)&~4095;put(args[0],rounded)
            result=table;calls.append([name,requested,rounded,result])
        elif name=='current_id':calls.append([name]);result=0x1234
        elif name=='current_process':calls.append([name]);result=0x4001000
        elif name=='current_thread':calls.append([name]);result=0x4002000
        elif name=='duplicate':
            calls.append([name,*args]);result=1
            if result:put(args[3],0x4003000)
        elif name=='create_thread':
            pending=args[3];payload=words(pending,5)
            callback=0x53b8d0 if payload[2]==EXIT+0xe00 else payload[2]
            worker=0x2200e10 if payload[3] else 0
            calls.append([name,args[0],args[1],args[2],payload[1],callback,worker,payload[4],args[4]])
            put(args[5],0x56781234);result=created
        elif name=='resume':
            calls.append([name,args[0]]);result=1
            if not sleep_target and pending:put(pending,0)
        elif name=='priority':
            signed=args[1] if args[1]<0x80000000 else args[1]-0x100000000
            calls.append([name,args[0],signed]);result=1
        elif name=='close':calls.append([name,args[0]]);result=1
        elif name=='sleep':
            calls.append([name,*args]);sleep_count+=1
            if sleep_count>=sleep_target and pending:put(pending,0)
        elif name=='exit_register':calls.append([name,args[0]])
        stdcall=address in {EXIT+target for target,_,_ in IAT.values()}
        machine.reg_write(UC_X86_REG_EAX,result)
        machine.reg_write(UC_X86_REG_ESP,sp+4*(count+1) if stdcall else sp+4)
        machine.reg_write(UC_X86_REG_EIP,ret)
    uc.hook_add(UC_HOOK_CODE,hook)
    args=(EXIT+0xe00,stack,priority,unused4,record)
    put(STACK,EXIT,*args);uc.reg_write(UC_X86_REG_ESP,STACK)
    try:uc.emu_start(0x55f420,EXIT+1,count=1000000)
    except Exception as error:raise RuntimeError(f'x86 failed at {uc.reg_read(UC_X86_REG_EIP):08x} case={case} calls={calls[-5:]}') from error
    if uc.reg_read(UC_X86_REG_EIP)!=EXIT or uc.reg_read(UC_X86_REG_ESP)!=STACK+4:
        raise RuntimeError(f'x86 ABI mismatch for {case}')
    return {'return':uc.reg_read(UC_X86_REG_EAX),'globals':words(0x6a57d0,8)+words(0x5df6a0,1),
            'arena':bytes(uc.mem_read(ARENA,ARENA_BYTES)).hex(),'calls':calls},coverage

def main():
    parser=argparse.ArgumentParser();parser.add_argument('--probe',type=Path,default=ROOT/'local/builds/v2/001-original-recovery/bin/Release/window_thread_start_probe.exe');parser.add_argument('--limit',type=int,default=0);parser.add_argument('--report-dir',type=Path,default=RUN);args=parser.parse_args()
    module=next(x for x in map(json.loads,(ROOT/'research/binary-index/static/binaries.jsonl').read_text().splitlines()) if x['file']=='Porsche.exe')
    binary=(ROOT/'local/game'/module['path']).read_bytes();sha='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
    if hashlib.sha256(binary).hexdigest()!=sha or module['sha256']!=sha:raise RuntimeError('original SHA mismatch')
    function_rows={r['entry_va']:r for r in map(json.loads,(ROOT/'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/functions.jsonl').read_text().splitlines())}
    probe=args.probe
    selected=CASES[:args.limit or None]
    process=subprocess.run([str(probe)],input=''.join(' '.join(map(str,row))+'\n' for row in selected),text=True,capture_output=True,check=True,timeout=30)
    outputs=[json.loads(line) for line in process.stdout.splitlines()]
    if len(outputs)!=len(selected):raise RuntimeError('native output count differs')
    coverage=set();fixtures=[]
    for index,(case,actual) in enumerate(zip(selected,outputs)):
        expected,hit=original(case,module,binary,function_rows);coverage|=hit
        if actual!=expected:
            keys=[key for key in expected if actual.get(key)!=expected[key]]
            path=ROOT/'local/reports/v2-window-thread-start-mismatch.json';path.parent.mkdir(parents=True,exist_ok=True)
            path.write_text(json.dumps({'case':case,'expected':expected,'actual':actual},indent=2)+'\n',encoding='utf8')
            raise AssertionError(f'case {index} differs in {keys}: {path}')
        fixtures.append({'input':case,'output_sha256':hashlib.sha256(json.dumps(expected,sort_keys=True).encode()).hexdigest()})
    print(json.dumps({'range':'0055f420..0055f4ee','cases':len(selected),'functions':sorted(coverage),'native_cpp_equal_original_x86':True}))
    if args.limit:return
    if '0055f420' not in coverage:raise RuntimeError('original start function was not executed')
    paths=[
        'iterations/v2/001-original-recovery/source/include/porsche/window_threads.hpp',
        'iterations/v2/001-original-recovery/source/include/porsche/file_threads.hpp',
        'iterations/v2/001-original-recovery/source/include/porsche/file_events.hpp',
        'iterations/v2/001-original-recovery/source/include/porsche/file_wait.hpp',
        'iterations/v2/001-original-recovery/source/include/porsche/file_worker.hpp',
        'iterations/v2/001-original-recovery/source/include/porsche/file_device.hpp',
        'iterations/v2/001-original-recovery/source/include/porsche/files.hpp',
        'iterations/v2/001-original-recovery/source/include/porsche/heap.hpp',
        'iterations/v2/001-original-recovery/source/include/porsche/fe_stream.hpp',
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/window_threads.cpp',
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/file_threads.cpp',
        'iterations/v2/001-original-recovery/source/recovered/window_threads_probe.cpp',
        'iterations/v2/001-original-recovery/runs/044-window-thread-start/CMakeLists.txt',
        'scripts/research/verify-v2-window-thread-start.py']
    report={'schema':1,'module':'Porsche.exe','sha256':sha,'range':'0055f420..0055f4ee',
        'function_vas':sorted(coverage),'full_function_vas':['0055f420'],'partial_function_vas':[],
        'cases':len(selected),'native_cpp_equal_original_x86':True,'binary_matched':False,'game_launch_verified':False,
        'comparison':'Full 128 KiB arena, shared thread globals, return value, and ordered heap/OS calls. Caller ThreadRecord is 28 bytes. The callback is the caller-supplied window worker address; OS creation/resume/sleep are deterministic recording fixtures.',
        'boundaries':{'thread_os':'CreateThread, thread IDs/handle duplication, priority, resume, close and SleepEx are deterministic fixtures; real scheduler/concurrency and worker execution are not asserted.',
                      'allocation':'Thread registry allocation is a deterministic page-rounded fixture; the original allocation wrapper is separately recovered.'},
        'source_sha256':{p:hashlib.sha256((ROOT/p).read_bytes().replace(b'\r\n',b'\n')).hexdigest() for p in paths},
        'probe_sha256':hashlib.sha256(probe.read_bytes()).hexdigest(),'fixtures':fixtures}
    report_dir=args.report_dir if args.report_dir.is_absolute() else ROOT/args.report_dir
    report_dir.mkdir(parents=True,exist_ok=True)
    (report_dir/'verification.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf8',newline='\n')
    print(json.dumps({'report':str(report_dir/'verification.json'),'native_equal_original_x86':True}))
if __name__=='__main__':main()
