from v2_source_dependencies import source_hashes
"""Verify original page allocation, list construction and file-device startup.

OS imports and event/thread/lock creation are explicit recording boundaries.
The original worker's first initialized write is supplied by the thread fixture;
the worker loop is indexed, not reconstructed or executed by this test.
"""
import argparse
import hashlib
import json
from pathlib import Path
import struct
import subprocess
import sys
from v2_manual_index import records
ROOT=Path(__file__).resolve().parents[2]
RUN=ROOT/'iterations/v2/001-original-recovery/runs/006-file-device'
sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ESP,UC_X86_REG_EIP
FUNCTIONS=[0x56e5f0,0x56e640,0x580630,0x580670,0x580680,0x568390,0x580ea0,0x580ec0]
ARENA,STACK,EXIT=0x3300000,0x200f000,0x2200000

def cases():
    result=[]
    for page in [1,1024,3000,4096,8192,65536]:
        for size in sorted({0,1,page-1,page,page+1,0x7fffffff-page,0x7fffffff,0x80000000,0xffffffff-page,0xfffffffe,0xffffffff}):
            for cached in [0,1]:
                for allocated,freed in [(0,0),(0x12345000,1),(0x12345000,0xffffffff)]:
                    result.append('|'.join(map(str,['P',page,cached,size,allocated,freed])))
    for index in [0,1,15,31]:
        for initialized in [0,1]:
            for thread in [0,1,0xffffffff]:
                for custom in [0,1]:
                    for twice in [0,1]:result.append('|'.join(map(str,['D',index,initialized,thread,custom,0xfedcba98,twice])))
    return result

def original(wire,module,data,functions):
    f=wire.split('|');uc=Uc(UC_ARCH_X86,UC_MODE_32);base=int(module['image_base'],16)
    uc.mem_map(base,0x300000)
    for s in module['sections']:uc.mem_write(base+s['rva'],data[s['raw_offset']:s['raw_offset']+s['raw_size']])
    uc.mem_map(ARENA,0x10000);uc.mem_write(ARENA,b'\xcc'*0x10000)
    uc.mem_map(0x2000000,0x10000);uc.mem_map(EXIT,0x1000)
    def words(p,n):return list(struct.unpack('<'+'I'*n,uc.mem_read(p,n*4)))
    def put(p,*values):uc.mem_write(p,struct.pack('<'+'I'*len(values),*[v&0xffffffff for v in values]))
    def string(p):
        out=bytearray()
        while (v:=uc.mem_read(p+len(out),1)[0]):out.append(v)
        return bytes(out)
    for iat,target in [(0x5b21b0,EXIT+0x100),(0x5b2144,EXIT+0x200),(0x5b2148,EXIT+0x300)]:put(iat,target)
    ranges=[(int(a,16),int(b,16)) for v in FUNCTIONS for a,b in functions[f'{v:08x}']['ranges']]
    calls=[];coverage=set();locks=0;events=0
    page,allocated,freed,thread=0,0,0,0
    if f[0]=='P':page,cached,size,allocated,freed=map(int,f[1:]);put(0x6a6418,page if cached else 0)
    else:
        index,initialized,thread,custom,argument,twice=map(int,f[1:]);put(0x6a5c7c,ARENA+0x100);put(ARENA+0x100+index*112,initialized)
        put(0x6a5c58,0,0,0,0,0,0,0x2001000);put(0x6a5c38,0,0,0,0,0,0,0)
    endpoints={EXIT+0x100:1,EXIT+0x200:4,EXIT+0x300:3,0x5321f0:0,0x5322b0:1,0x5322c0:1,
               0x55fb20:0,0x55fc20:0,0x55fc60:1,0x55fc40:1,0x55f5f0:6,0x565340:1}
    def hook(machine,p,length,user):
        nonlocal locks,events
        if p==EXIT:machine.emu_stop();return
        if p in FUNCTIONS:coverage.add(f'{p:08x}')
        n=endpoints.get(p)
        if n is None:
            if not any(a<=p<=b for a,b in ranges):raise RuntimeError(f'Unexpected original code {p:08x}')
            return
        sp=uc.reg_read(UC_X86_REG_ESP);ret,*args=words(sp,n+1);value=0
        if p==EXIT+0x100:uc.mem_write(args[0],b'\0'*36);put(args[0]+4,page);calls.append(['system_info'])
        elif p==EXIT+0x200:calls.append(['virtual_alloc',*args]);value=allocated
        elif p==EXIT+0x300:calls.append(['virtual_free',*args]);value=freed
        elif p==0x5321f0:calls.append(['create']);value=0x2002000+locks*16;locks+=1
        elif p in [0x5322b0,0x5322c0]:calls.append(['enter' if p==0x5322b0 else 'leave',args[0]])
        elif p in [0x55fb20,0x55fc20]:
            value=(0x4001000 if p==0x55fb20 else 0x4002000)+events*16;events+=1
            calls.append(['auto_event' if p==0x55fb20 else 'manual_event',value])
        elif p in [0x55fc60,0x55fc40]:calls.append(['wait_event' if p==0x55fc60 else 'reset_event',args[0]])
        elif p==0x55f5f0:
            calls.append(['thread',*args[:4],-1 if args[4]==0xffffffff else args[4],args[5]])
            value=thread
            if thread:put(ARENA+0x100+args[1]*112,1)
        elif p==0x565340:calls.append(['diagnostic',words(0x5deb78,1)[0],string(args[0]).hex()])
        uc.reg_write(UC_X86_REG_EAX,value);uc.reg_write(UC_X86_REG_ESP,sp+4*(n+1) if p in [EXIT+0x100,EXIT+0x200,EXIT+0x300] else sp+4);uc.reg_write(UC_X86_REG_EIP,ret)
    uc.hook_add(UC_HOOK_CODE,hook)
    def execute(va,args):
        put(STACK,EXIT,*args);uc.reg_write(UC_X86_REG_ESP,STACK);uc.emu_start(va,EXIT+1,count=1000000)
        if uc.reg_read(UC_X86_REG_EIP)!=EXIT or uc.reg_read(UC_X86_REG_ESP)!=STACK+4:raise RuntimeError(f'Original ABI/budget failure {va:08x}')
        return uc.reg_read(UC_X86_REG_EAX)
    if f[0]=='P':
        put(STACK+0x800,size);pointer=execute(0x56e5f0,[STACK+0x800]);free=execute(0x56e640,[pointer])
        returns=[words(STACK+0x800,1)[0],pointer,free,words(0x6a6418,1)[0]]
    else:
        key=0x5684c0 if custom else 0;execute(0x580630,[ARENA+0x2000,key,argument]);execute(0x580680,[ARENA+0x2040,key,argument,ARENA+0x2000])
        execute(0x568390,[index])
        if twice:execute(0x568390,[index])
        returns=[execute(0x580670,[ARENA+0x4000,argument])]
    return {'returns':returns,'arena':bytes(uc.mem_read(ARENA,0x10000)).hex(),'calls':calls},coverage

def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--limit',type=int)
    parser.add_argument('--report-dir',type=Path,default=ROOT/'iterations/v2/001-original-recovery/runs/009-file-events/device-regression');args=parser.parse_args()
    module=next(json.loads(l) for l in (ROOT/'research/binary-index/static/binaries.jsonl').read_text().splitlines() if json.loads(l)['file']=='Porsche.exe')
    data=(ROOT/'local/game'/module['path']).read_bytes()
    if hashlib.sha256(data).hexdigest()!=module['sha256']:raise RuntimeError('Original SHA differs')
    functions={r['entry_va']:r for r in map(json.loads,(ROOT/'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/functions.jsonl').read_text().splitlines())};functions.update({r['entry_va']:r for r in records(module['sha256'])})
    inputs=cases();inputs=inputs[:args.limit] if args.limit else inputs
    probe=ROOT/'local/builds/v2/001-original-recovery/bin/Release/device_probe.exe'
    native=subprocess.run([str(probe)],input='\n'.join(inputs)+'\n',text=True,capture_output=True,check=True,timeout=60)
    outputs=[json.loads(line) for line in native.stdout.splitlines()]
    if len(inputs)!=len(outputs):raise RuntimeError('Native output count differs')
    coverage=set();fixtures=[]
    for i,(wire,actual) in enumerate(zip(inputs,outputs)):
        expected,hit=original(wire,module,data,functions);coverage|=hit
        if actual!=expected:
            path=ROOT/'local/reports/v2-device-mismatch.json';path.write_text(json.dumps({'case':i,'input':wire,'expected':expected,'actual':actual},indent=2)+'\n');raise RuntimeError(f'Case {i} differs: {[k for k in expected if expected[k]!=actual.get(k)]}; {path}')
        fixtures.append({'input':wire,'output_sha256':hashlib.sha256(json.dumps(expected,sort_keys=True).encode()).hexdigest()})
    print(json.dumps({'cases':len(inputs),'functions':sorted(coverage),'native_equal_original':True}))
    if args.limit:return
    paths=['source/recovered/Porsche.exe/file_pages.cpp','source/recovered/Porsche.exe/file_device.cpp','source/recovered/Porsche.exe/io_lists.cpp','source/recovered/device_probe.cpp','source/include/porsche/file_device.hpp','source/include/porsche/files.hpp','source/include/porsche/heap.hpp','source/include/porsche/fe_stream.hpp']
    paths=['iterations/v2/001-original-recovery/'+p for p in paths]
    report={'schema':1,'sha256':module['sha256'],'function_vas':sorted(coverage),'cases':len(inputs),'native_cpp_equal_original_x86':True,'binary_matched':False,'game_launch_verified':False,
            'comparison':'Full device/list arena, page rounded size/cache, returned allocation/free values, and ordered OS/event/thread/diagnostic calls; code pointers normalized to original VA identities.',
            'boundaries':{'OS':'GetSystemInfo/VirtualAlloc/VirtualFree recording endpoints; include non-OS page sizes only as synthetic arithmetic fixtures.',
                          'thread':'0055f5f0 records parameters; fixture supplies only worker initialized=1 write confirmed at 0056854b. Worker loop, events, concurrency, real thread state not executed.',
                          'lock_event_diagnostic':'Recording 005321f0/005322b0/005322c0, 0055fb20/0055fc20/0055fc60/0055fc40 and 00565340.'},
            'source_sha256':{p:hashlib.sha256((ROOT/p).read_bytes().replace(b'\r\n',b'\n')).hexdigest() for p in paths},'probe_sha256':hashlib.sha256(probe.read_bytes()).hexdigest(),'fixtures':fixtures}
    report['source_sha256']=source_hashes([*report['source_sha256'],Path(__file__)])
    args.report_dir.mkdir(parents=True,exist_ok=True);(args.report_dir/'verification.json').write_text(json.dumps(report,indent=2)+'\n',newline='\n')
    (args.report_dir/'source-functions.jsonl').write_text(''.join(json.dumps({'sha256':module['sha256'],**functions[va]})+'\n' for va in sorted(coverage)),newline='\n')

if __name__=='__main__':main()
