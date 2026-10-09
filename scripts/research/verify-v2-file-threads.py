from v2_source_dependencies import source_hashes
"""Differentially verify recovered Porsche.exe thread and registry functions."""
import argparse
import hashlib
import json
from pathlib import Path
import struct
import subprocess
import sys

ROOT=Path(__file__).resolve().parents[2]
RUN=ROOT/'iterations/v2/001-original-recovery/runs/010-file-threads/threads-unit'
sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ESP,UC_X86_REG_EIP
from v2_manual_index import records as manual_records

FUNCTIONS=[0x55f2b0,0x55f320,0x55f3b0,0x55f4f0,0x55f560,0x55f5f0,0x55f730,0x55f780,0x55f7e0,0x55f8b0]
ARENA,STACK,EXIT=0x3600000,0x200f000,0x2200000
IAT={0x5b2074:(0x100,'current_id',0),0x5b2094:(0x200,'current_process',0),
     0x5b2170:(0x300,'current_thread',0),0x5b20a0:(0x400,'duplicate',7),
     0x5b217c:(0x500,'create_thread',6),0x5b209c:(0x600,'resume',1),
     0x5b2188:(0x700,'priority',2),0x5b2164:(0x800,'close',1),0x5b2160:(0x900,'sleep',2)}

def wire(mode,*values):return '|'.join(map(str,(mode,*values,*([0]*(8-len(values))))))
def cases():
    rows=[]
    for count in (0,1,100,341):
        for existed,locked,failed in ((0,0,0),(0,1,0),(1,0,0),(0,0,1)):
            rows.append(wire('T',count,existed,locked,failed))
    for count in (0,1,100):
        for initialized,failed,duplicate,registered in ((0,0,1,0),(0,1,1,0),(0,0,0,0),(0,0,1,1),(1,0,1,0)):
            rows.append(wire('I',count,initialized,failed,duplicate,registered))
    for cap,mask,serial in ((0,0,1),(1,0,1),(1,1,1),(3,0,0xffffffff),(3,1,7),(3,3,0)):
        rows.append(wire('R',cap,mask,serial,0x4005000,0x12345678))
    for slot,serial,cap,entry_serial,handle in ((0,7,2,7,0x4005000),(0,8,2,7,0x4005000),
                                                 (0,7,2,7,0),(-1,7,2,7,0x4005000),(2,7,2,7,0x4005000),
                                                 (1,7,2,7,0x4005000),(0,0,2,0,0x4005000)):
        rows.append(wire('U',slot,serial,cap,entry_serial,handle))
    for choice in (0,1):rows.append(wire('G',0x1234,0x4005000,choice))
    for initialized,identity,current,main,record in ((1,0,0x1234,0x1234,0x99),(1,0,0x1234,0x55,0x99),
        (1,0xffffffff,0x1234,0x55,0x99),(1,0xfffffffe,0x1234,0x55,0x1234),
        (1,0xfffffffe,0x1234,0x55,0x99),(0,0,0x1234,0,0x99),(0,0xfffffffe,0x1234,0,0x1234)):
        rows.append(wire('C',identity,current,initialized,main,record))
    for priority in (1,2,3,0xffffffff,0xfffffffe,0xfffffffd,0,4):
        for identity,handle,main in ((0,0x4005000,0x4006000),(0xffffffff,0x4005000,0x4006000),
                                     (0xfffffffe,0x4005000,0x4006000),(0xfffffffe,0,0x4006000)):
            rows.append(wire('P',identity,priority,1,handle,main,0x1234))
    rows.append(wire('P',0,3,0,0,0,1))
    for created,loops,initialized in ((0,0,1),(0x4004000,0,1),(0x4004000,2,1),(0x4004000,1,0)):
        rows.append(wire('S',0x42,0x2000,3,created,loops,initialized,7))
    for noarg in (0,1):
        for mutate in (0,1):rows.append(wire('B',noarg,mutate,0xabcdef12))
    return rows

def original(input_line,module,data,functions):
    f=input_line.split('|');mode=f[0];a=list(map(int,f[1:]))
    uc=Uc(UC_ARCH_X86,UC_MODE_32);base=int(module['image_base'],16)
    uc.mem_map(base,0x300000)
    for s in module['sections']:uc.mem_write(base+s['rva'],data[s['raw_offset']:s['raw_offset']+s['raw_size']])
    uc.mem_map(ARENA,0x20000);uc.mem_write(ARENA,b'\xcc'*0x20000)
    uc.mem_map(0x2000000,0x10000);uc.mem_map(EXIT,0x2000)
    def words(p,n):return list(struct.unpack('<'+'I'*n,uc.mem_read(p,4*n)))
    def put(p,*values):uc.mem_write(p,struct.pack('<'+'I'*len(values),*[v&0xffffffff for v in values]))
    def bytefill(p,value,size):uc.mem_write(p,bytes([value&255])*size)
    for iat,(target,_,_) in IAT.items():put(iat,EXIT+target)
    record,table,launch=ARENA+0x200,ARENA+0x1000,ARENA+0x9000
    globals_addrs=[0x6a57d0,0x6a57d4,0x6a57d8,0x6a57dc,0x6a57e0,0x6a57e4,0x6a57e8,0x6a57ec,0x5df6a0]
    for address,value in zip(globals_addrs,[0,0,0,0,0,0,0,0,1]):put(address,value)
    current_id=0x1234;duplicate_result=1;created_handle=0x4004000;priority_result=1;resume_result=1;sleep_target=0;sleeps=0;allocate_fail=0;lock_no=0;pending_launch=0
    calls=[];coverage=set()
    endpoints={EXIT+target:(label,n) for target,label,n in IAT.values()}
    endpoints.update({0x5322b0:('enter',1),0x5322c0:('leave',1),0x5321f0:('lock_create',0),
                      0x53c290:('fill',3),0x56e5f0:('allocate',1),0x557380:('exit_register',1),
                      EXIT+0xe00:('callback0',0),EXIT+0xe10:('callback1',1)})
    ranges=[(int(x,16),int(y,16)) for va in FUNCTIONS for x,y in functions[f'{va:08x}']['ranges']]
    def hook(machine,p,size,user):
        nonlocal lock_no,sleeps,pending_launch
        if p==EXIT:machine.emu_stop();return
        if p in FUNCTIONS:coverage.add(f'{p:08x}')
        endpoint=endpoints.get(p)
        if endpoint is None:
            if not any(x<=p<=y for x,y in ranges):raise RuntimeError(f'Unexpected original code {p:08x} sp={uc.reg_read(UC_X86_REG_ESP):08x} stack={words(uc.reg_read(UC_X86_REG_ESP),8)} calls={calls[-4:]}')
            return
        label,n=endpoint;sp=uc.reg_read(UC_X86_REG_ESP);ret,*args=words(sp,n+1);value=0
        if label in ('enter','leave'):calls.append([label,args[0]])
        elif label=='lock_create':value=0x2001000+lock_no*16;lock_no+=1;calls.append([label,value])
        elif label=='fill':calls.append([label,*args]);bytefill(args[0],args[1],args[2])
        elif label=='allocate':
            requested=words(args[0],1)[0];rounded=(requested+4095)&~4095;put(args[0],rounded)
            value=0 if allocate_fail else table;calls.append([label,requested,rounded,value])
        elif label=='current_id':calls.append([label]);value=current_id
        elif label=='current_process':calls.append([label]);value=0x4001000
        elif label=='current_thread':calls.append([label]);value=0x4002000
        elif label=='duplicate':
            calls.append([label,*args]);value=duplicate_result
            if value:put(args[3],0x4003000)
        elif label=='create_thread':
            pending_launch=args[3];known=words(pending_launch+4,4)
            calls.append([label,args[0],args[1],args[2],known[0],known[1],known[2],known[3],args[4]])
            put(args[5],0x56781234);value=created_handle
        elif label=='resume':
            calls.append([label,args[0]]);value=resume_result
            if not sleep_target and pending_launch:put(pending_launch,0)
        elif label=='priority':calls.append([label,args[0],args[1] if args[1]<0x80000000 else args[1]-0x100000000]);value=priority_result
        elif label=='close':calls.append([label,args[0]]);value=1
        elif label=='sleep':
            calls.append([label,*args]);sleeps+=1
            if sleeps>=sleep_target and pending_launch:put(pending_launch,0)
        elif label=='exit_register':calls.append([label,args[0]])
        elif label=='callback0':
            calls.append([label])
            if sleep_target:put(record+0x18,1);put(record+0x14,99)
        elif label=='callback1':
            calls.append([label,args[0]])
            if sleep_target:put(record+0x18,1);put(record+0x14,99)
        stdcall=p in {EXIT+target for target,_,_ in IAT.values()}
        uc.reg_write(UC_X86_REG_EAX,value)
        uc.reg_write(UC_X86_REG_ESP,sp+4*(n+1) if stdcall else sp+4)
        uc.reg_write(UC_X86_REG_EIP,ret)
    uc.hook_add(UC_HOOK_CODE,hook)
    if mode=='T':
        put(0x6a57ec,0x2002000 if a[2] else 0);put(0x6a57e4,table if a[1] else 0);allocate_fail=a[3]
        va,args=0x55f3b0,[a[0]]
    elif mode=='I':
        put(0x6a57dc,a[1]);allocate_fail=a[2];duplicate_result=a[3];put(0x6a57e0,a[4]);va,args=0x55f320,[a[0]]
    elif mode=='R':
        put(0x6a57e8,a[0]);put(0x6a57e4,table);put(0x6a57ec,0x2002000);put(0x5df6a0,a[2])
        for i in range(min(a[0],3)):put(table+i*12,7 if a[1]&(1<<i) else 0,0,0)
        va,args=0x55f560,[record,a[3],a[4]]
    elif mode=='U':
        put(0x6a57e8,a[2]);put(0x6a57e4,table);put(0x6a57ec,0x2002000)
        for i in range(3):put(table+i*12,a[3],a[4],0x56781234)
        va,args=0x55f2b0,[a[0],a[1]]
    elif mode=='G':
        put(record,a[1]);put(record+0x10,a[0]);va,args=(0x55f7e0 if a[2] else 0x55f730),[record]
    elif mode=='C':
        put(0x6a57dc,a[2]);put(0x6a57d4,a[3]);put(record+0x10,a[4]);current_id=a[1]
        va,args=0x55f780,[record if a[0]==0xfffffffe else a[0]]
    elif mode=='P':
        put(0x6a57dc,a[2]);put(0x6a57d0,a[4]);put(record,a[3]);priority_result=a[5]
        va,args=0x55f8b0,[record if a[0]==0xfffffffe else a[0],a[1]]
    elif mode=='S':
        put(0x6a57dc,a[5]);put(0x6a57d8,0x2001000);put(0x6a57ec,0x2002000)
        put(0x6a57e4,table);put(0x6a57e8,3);put(0x5df6a0,a[6])
        for i in range(3):put(table+i*12,0,0,0)
        created_handle=a[3];sleep_target=a[4]
        va,args=0x55f5f0,[EXIT+0xe10,a[0],a[1],a[2],0xffffffff,record]
    elif mode=='B':
        put(0x6a57ec,0x2002000);put(0x6a57e4,table);put(0x6a57e8,2)
        put(record+0x18,0);put(record+0x14,7);put(table,7,0x4005000,0x1234)
        put(launch,0x4006000,record,EXIT+0xe00 if a[0] else 0,EXIT+0xe10,a[2]);sleep_target=a[1]
        va,args=0x55f4f0,[launch]
    else:raise RuntimeError('Invalid fixture mode')
    put(STACK,EXIT,*args);uc.reg_write(UC_X86_REG_ESP,STACK)
    uc.emu_start(va,EXIT+1,count=1000000)
    expected_sp=STACK+8 if mode=='B' else STACK+4
    if uc.reg_read(UC_X86_REG_EIP)!=EXIT or uc.reg_read(UC_X86_REG_ESP)!=expected_sp:
        raise RuntimeError(f'Original ABI/budget failure {va:08x}')
    return {'return':0 if mode in ('I','U') else uc.reg_read(UC_X86_REG_EAX),'globals':words(0x6a57d0,8)+words(0x5df6a0,1),
            'arena':bytes(uc.mem_read(ARENA,0x20000)).hex(),'calls':calls},coverage

def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--limit',type=int);parser.add_argument('--report-dir',type=Path,default=RUN);args=parser.parse_args();report_dir=args.report_dir if args.report_dir.is_absolute() else ROOT/args.report_dir
    module=next(x for x in map(json.loads,(ROOT/'research/binary-index/static/binaries.jsonl').read_text().splitlines()) if x['file']=='Porsche.exe')
    data=(ROOT/'local/game'/module['path']).read_bytes()
    if hashlib.sha256(data).hexdigest()!=module['sha256']:raise RuntimeError('Original SHA differs')
    functions={r['entry_va']:r for r in map(json.loads,(ROOT/'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/functions.jsonl').read_text().splitlines())}
    functions.update({r['entry_va']:r for r in manual_records(module['sha256'])})
    inputs=cases();inputs=inputs[:args.limit] if args.limit else inputs
    probe=ROOT/'local/builds/v2/001-original-recovery/bin/Release/thread_probe.exe'
    native=subprocess.run([str(probe)],input='\n'.join(inputs)+'\n',text=True,capture_output=True,check=True,timeout=60)
    outputs=list(map(json.loads,native.stdout.splitlines()))
    if len(outputs)!=len(inputs):raise RuntimeError(f'Native output count {len(outputs)} != {len(inputs)}')
    coverage=set();fixtures=[]
    for i,(input_line,actual) in enumerate(zip(inputs,outputs)):
        expected,hit=original(input_line,module,data,functions);coverage|=hit
        if actual!=expected:
            path=ROOT/'local/reports/v2-threads-mismatch.json';path.parent.mkdir(parents=True,exist_ok=True)
            path.write_text(json.dumps({'case':i,'input':input_line,'expected':expected,'actual':actual},indent=2)+'\n')
            raise RuntimeError(f'Case {i} differs: {[key for key in expected if expected[key]!=actual.get(key)]}; {path}')
        fixtures.append({'input':input_line,'output_sha256':hashlib.sha256(json.dumps(expected,sort_keys=True).encode()).hexdigest()})
    print(json.dumps({'cases':len(inputs),'functions':sorted(coverage),'native_equal_original':True}))
    if args.limit:return
    if coverage!={f'{va:08x}' for va in FUNCTIONS}:raise RuntimeError('Original function coverage incomplete')
    paths=['source/recovered/Porsche.exe/file_threads.cpp','source/recovered/thread_probe.cpp','source/include/porsche/file_threads.hpp','source/include/porsche/file_events.hpp','source/include/porsche/file_wait.hpp','source/include/porsche/file_worker.hpp','source/include/porsche/file_device.hpp','source/include/porsche/files.hpp','source/include/porsche/heap.hpp','source/include/porsche/fe_stream.hpp']
    paths=['iterations/v2/001-original-recovery/'+p for p in paths]
    report={'schema':1,'sha256':module['sha256'],'function_vas':sorted(coverage),'cases':len(inputs),
            'native_cpp_equal_original_x86':True,'binary_matched':False,'game_launch_verified':False,
            'comparison':'Full fixed thread/table arena, globals, typed return values and ordered OS/heap/callback calls. Void init/unregister EAX is normalized to zero; launch logging excludes its indeterminate handshake word before CreateThread.',
            'boundaries':{'thread_os':'Thread creation, priority, resume, thread IDs, handle duplication/close and SleepEx are deterministic recording endpoints; real concurrency and exit callback effects are unverified.',
                          'allocation':'Page-rounded size mutation and allocation result are controlled fixtures; real page wrapper is checked separately.'},
            'source_sha256':{p:hashlib.sha256((ROOT/p).read_bytes().replace(b'\r\n',b'\n')).hexdigest() for p in paths},
            'probe_sha256':hashlib.sha256(probe.read_bytes()).hexdigest(),'fixtures':fixtures}
    report_dir.mkdir(parents=True,exist_ok=True)
    report['source_sha256']=source_hashes([*report['source_sha256'],Path(__file__)])
    (report_dir/'verification.json').write_text(json.dumps(report,indent=2)+'\n',newline='\n')
    (report_dir/'source-functions.jsonl').write_text(''.join(json.dumps({'sha256':module['sha256'],**functions[va]})+'\n' for va in sorted(coverage)),newline='\n')

if __name__=='__main__':main()
