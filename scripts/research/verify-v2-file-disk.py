"""Differentially verify the recovered physical disk backend against Porsche.exe x86."""
import argparse
import hashlib
import json
from pathlib import Path
import struct
import subprocess
import sys

ROOT=Path(__file__).resolve().parents[2]
RUN=ROOT/'iterations/v2/001-original-recovery/runs/011-file-disk'
sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ESP,UC_X86_REG_EIP

ARENA,STACK,EXIT=0x03400000,0x0200f000,0x02200000
FUNCTIONS={0:0x591df0,1:0x592140,2:0x592290,3:0x591ce0}
RANGES={0:(0x591df0,0x591f96),1:(0x592140,0x592206),2:(0x592290,0x592350),3:(0x591ce0,0x591de4)}

def cases():
    rows=[]
    for mapped in (0,1):
        for cursor,size,block,request,read_mode,error in ((0,8,4,2,1,0),(3,8,4,8,1,0),(20,8,4,2,1,0),
                                                            (0,8,4,2,0,5),(0,8,4,2,2,0x3e5),(0,8,4,0,1,0)):
            rows.append((0,1,mapped,cursor,size,block,request,read_mode,3,error,0x55,1,0))
    rows += [(0,0,0,0,8,4,2,1,2,0,0,1,0),(0,2,0,0,8,4,2,1,2,0,0,1,0)]
    for mapped in (0,1):
        for cursor,size,target,seek in ((0,8,3,0x1234),(0,8,20,0x1234),(0,8,0xffffffff,0x1234)):
            rows.append((1,1,mapped,cursor,size,4,target,1,0,0,seek,1,0))
    rows += [(1,0,0,0,8,4,3,1,0,0,0,1,0),(1,2,0,0,8,4,3,1,0,0,0,1,0)]
    rows += [(2,1,0,0,8,4,0,1,0,0,0,1,0),(2,1,1,0,8,4,0,1,0,0,0,1,0),(2,0,0,0,8,4,0,1,0,0,0,1,0)]
    for free_ok in (0,1):
        for output_free in (0,1): rows.append((3,1,0,0,8,4,0,1,0,0,0,free_ok,output_free))
    rows += [(3,0,0,0,8,4,0,1,0,0,0,1,1),(3,2,0,0,8,4,0,1,0,0,0,1,1)]
    return ['|'.join(map(str,row)) for row in rows]

def original(wire,module,data):
    f=list(map(int,wire.split('|')))
    operation,valid,mapped,cursor,size,block,amount,read_mode,read_bytes,read_error,seek_result,free_result,free_out=f
    uc=Uc(UC_ARCH_X86,UC_MODE_32); base=int(module['image_base'],16)
    uc.mem_map(base,0x300000)
    for section in module['sections']: uc.mem_write(base+section['rva'],data[section['raw_offset']:section['raw_offset']+section['raw_size']])
    uc.mem_map(ARENA,0x20000); uc.mem_write(ARENA,b'\xcc'*0x20000)
    uc.mem_map(0x2000000,0x10000); uc.mem_map(EXIT,0x1000)
    def put(address,*values): uc.mem_write(address,struct.pack('<'+'I'*len(values),*[value&0xffffffff for value in values]))
    def words(address,count): return list(struct.unpack('<'+'I'*count,uc.mem_read(address,count*4)))
    def put_byte(address,value): uc.mem_write(address,bytes([value&255]))
    physical,view,output=ARENA,ARENA+0x1000,ARENA+0x2000
    put(0x6af084,physical); put(0x6af080,1); put(0x6aeffc+3*4,0x02001000)
    put_byte(physical,1 if valid else 0); put_byte(physical+1,3); put_byte(physical+2,0)
    put(physical+4,0x12345000,0x11223344,block,0x23456000 if mapped else 0xffffffff,view if mapped else 0,cursor,size)
    uc.mem_write(view,bytes((0x40+i)&255 for i in range(128))); uc.mem_write(output,b'\xcc'*128)
    mode,block_out,size_out,free_bytes=ARENA+0x3000,ARENA+0x3004,ARENA+0x3008,ARENA+0x300c
    put(mode,0xaaaaaaaa); put(block_out,0xbbbbbbbb); put(size_out,0xcccccccc); put(free_bytes,0xdddddddd)
    iat={0x5b21a4:0x100,0x5b21f4:0x110,0x5b213c:0x120,0x5b223c:0x130,0x5b21d8:0x140,0x5b2164:0x150,0x5b2090:0x160}
    for address,offset in iat.items(): put(address,EXIT+offset)
    endpoints={0x5322b0:('enter',1,False),0x5322c0:('leave',1,False),0x5323e0:('copy',3,False),0x55f740:('sleep',1,False),
               EXIT+0x100:('set_last_error',1,True),EXIT+0x110:('read',5,True),EXIT+0x120:('get_last_error',0,True),
               EXIT+0x130:('set_file_pointer',4,True),EXIT+0x140:('unmap',1,True),EXIT+0x150:('close',1,True),EXIT+0x160:('free_space',5,True)}
    calls=[]; attempts=0; coverage=set(); target=FUNCTIONS[operation]; lo,hi=RANGES[operation]
    def hook(machine,address,_,__):
        nonlocal attempts
        if address==EXIT: machine.emu_stop(); return
        if address==target: coverage.add(f'{address:08x}')
        endpoint=endpoints.get(address)
        if endpoint is None:
            if not lo<=address<=hi: raise RuntimeError(f'Unexpected original code {address:08x}')
            return
        label,count,stdcall=endpoint; sp=uc.reg_read(UC_X86_REG_ESP); ret,*args=words(sp,count+1); value=0
        if label in ('enter','leave'): calls.append([label,args[0]])
        elif label=='copy': machine.mem_write(args[0],bytes(machine.mem_read(args[1],args[2])))
        elif label=='sleep': calls.append([label,args[0]])
        elif label=='set_last_error': calls.append([label,args[0]])
        elif label=='read':
            calls.append([label,args[0],args[2]]); attempts+=1
            if read_mode==0 or (read_mode==2 and attempts==1): value=0
            else:
                count_read=min(read_bytes,args[2]); put(args[3],count_read); machine.mem_write(args[1],bytes((0xa0+i)&255 for i in range(count_read))); value=1
        elif label=='get_last_error': calls.append([label]); value=read_error
        elif label=='set_file_pointer': calls.append([label,args[0],args[1] if args[1]<0x80000000 else args[1]-0x100000000,args[3]]); value=seek_result
        elif label=='unmap': calls.append([label,args[0]])
        elif label=='close': calls.append([label,args[0]])
        elif label=='free_space':
            calls.append([label,bytes(machine.mem_read(args[0],4)).hex()]); put(args[1],4); put(args[2],512); put(args[3],0x101); value=free_result
        machine.reg_write(UC_X86_REG_EAX,value); machine.reg_write(UC_X86_REG_ESP,sp+4*(count+1) if stdcall else sp+4); machine.reg_write(UC_X86_REG_EIP,ret)
    uc.hook_add(UC_HOOK_CODE,hook)
    handle=0xfffffffe if valid==2 else (0xffffffff if valid else 0)
    args=([handle,output,amount] if operation==0 else [handle,amount] if operation==1 else [handle] if operation==2 else [handle,mode,block_out,size_out,free_bytes if free_out else 0])
    put(STACK,EXIT,*args); uc.reg_write(UC_X86_REG_ESP,STACK); uc.emu_start(target,EXIT+1,count=1000000)
    if uc.reg_read(UC_X86_REG_EIP)!=EXIT or uc.reg_read(UC_X86_REG_ESP)!=STACK+4: raise RuntimeError('Original ABI/budget failure')
    return {'return':uc.reg_read(UC_X86_REG_EAX),'file':bytes(uc.mem_read(physical,32)).hex(),'buffer':bytes(uc.mem_read(output,128)).hex(),
            'outputs':words(mode,4),'calls':calls},coverage

def main():
    parser=argparse.ArgumentParser(description=__doc__); parser.add_argument('--limit',type=int); parser.add_argument('--report-dir',type=Path,default=RUN); args=parser.parse_args()
    module=next(item for item in map(json.loads,(ROOT/'research/binary-index/static/binaries.jsonl').read_text().splitlines()) if item['file']=='Porsche.exe')
    data=(ROOT/'local/game'/module['path']).read_bytes()
    if hashlib.sha256(data).hexdigest()!=module['sha256']: raise RuntimeError('Original SHA differs')
    inputs=cases(); inputs=inputs[:args.limit] if args.limit else inputs
    probe=ROOT/'local/builds/v2/001-original-recovery/bin/Release/disk_probe.exe'
    native=subprocess.run([str(probe)],input='\n'.join(inputs)+'\n',text=True,capture_output=True,check=True,timeout=60)
    outputs=list(map(json.loads,native.stdout.splitlines()))
    if len(outputs)!=len(inputs): raise RuntimeError(f'Native output count {len(outputs)} != {len(inputs)}')
    coverage=set(); fixtures=[]
    for index,(wire,actual) in enumerate(zip(inputs,outputs)):
        expected,hit=original(wire,module,data); coverage|=hit
        if actual!=expected:
            mismatch=ROOT/'local/reports/v2-file-disk-mismatch.json'; mismatch.write_text(json.dumps({'case':index,'input':wire,'expected':expected,'actual':actual},indent=2)+'\n')
            raise RuntimeError(f'Case {index} differs: {[key for key in expected if expected[key]!=actual.get(key)]}; {mismatch}')
        fixtures.append({'input':wire,'output_sha256':hashlib.sha256(json.dumps(expected,sort_keys=True).encode()).hexdigest()})
    required={f'{address:08x}' for address in FUNCTIONS.values()}
    if coverage!=required: raise RuntimeError(f'Coverage incomplete: {sorted(coverage)}')
    print(json.dumps({'cases':len(inputs),'functions':sorted(coverage),'native_equal_original':True}))
    if args.limit: return
    paths=['source/include/porsche/file_disk.hpp','source/recovered/Porsche.exe/file_disk.cpp','source/recovered/disk_probe.cpp','source/include/porsche/files.hpp','source/include/porsche/file_events.hpp','source/include/porsche/file_wait.hpp','source/include/porsche/file_worker.hpp','source/include/porsche/file_device.hpp','source/include/porsche/heap.hpp','source/include/porsche/fe_stream.hpp','source/recovered/Porsche.exe/files.cpp','source/recovered/Porsche.exe/file_events.cpp']
    paths=['iterations/v2/001-original-recovery/'+path for path in paths]
    report={'schema':1,'sha256':module['sha256'],'function_vas':sorted(coverage),'cases':len(inputs),'native_cpp_equal_original_x86':True,'binary_matched':False,'game_launch_verified':False,
            'comparison':'PhysicalFile bytes, output buffer and info destinations, return values, and ordered lock/Win32/sleep boundary calls. Raw OS handles and mapped-view pointers are normalized to fixed fixture identities.',
            'boundaries':{'win32':'ReadFile, SetFilePointer, GetDiskFreeSpaceA, CloseHandle, UnmapViewOfFile, SetLastError and SleepEx use recording endpoints; no real disk I/O claim is made.',
                          'concurrency':'The original per-device mutex call order is compared, but real lock contention and pending I/O completion are not accepted.'},
            'source_sha256':{path:hashlib.sha256((ROOT/path).read_bytes().replace(b'\r\n',b'\n')).hexdigest() for path in paths},'probe_sha256':hashlib.sha256(probe.read_bytes()).hexdigest(),'fixtures':fixtures}
    args.report_dir.mkdir(parents=True,exist_ok=True)
    (args.report_dir/'verification.json').write_text(json.dumps(report,indent=2)+'\n',newline='\n')
    functions={item['entry_va']:item for item in map(json.loads,(ROOT/'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/functions.jsonl').read_text().splitlines())}
    (args.report_dir/'source-functions.jsonl').write_text(''.join(json.dumps({'sha256':module['sha256'],**functions[va]})+'\n' for va in sorted(coverage)),newline='\n')

if __name__=='__main__': main()
