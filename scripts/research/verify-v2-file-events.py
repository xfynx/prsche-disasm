from v2_source_dependencies import source_hashes
"""Differentially verify Porsche.exe event wrappers against original x86."""
import argparse
import hashlib
import json
from pathlib import Path
import struct
import subprocess
import sys

ROOT=Path(__file__).resolve().parents[2]
RUN=ROOT/'iterations/v2/001-original-recovery/runs/009-file-events/events-unit'
sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ESP,UC_X86_REG_EIP

FUNCTIONS=[0x55f740,0x55fb20,0x55fb30,0x55fb40,0x55fb60,0x55fb90,0x55fbb0,0x55fbf0,
           0x55fc10,0x55fc20,0x55fc30,0x55fc40,0x55fc60,0x55fc80,0x55fce0]
ARENA,STACK,EXIT=0x3500000,0x200f000,0x2200000
IAT={0x5b2160:(0x100,'sleep',2),0x5b2190:(0x200,'create',4),
     0x5b2194:(0x300,'set',1),0x5b2198:(0x400,'wait',5),
     0x5b219c:(0x500,'reset',1),0x5b2164:(0x600,'close',1),
     0x5b213c:(0x700,'error',0)}

def wire(va,count=1,wait=0,rate=0,ticks=0,handles=(0x4010000,0x4020000,0x4030000),action=1,other=1):
    return '|'.join(map(str,(va,count,wait,rate,ticks,*handles,action,other)))

def cases():
    cases=[]
    for va in FUNCTIONS:
        for action,other in [(0,0),(1,1),(0xffffffff,0xffffffff),(0,0x12345678)]:
            cases.append(wire(va,wait=0,action=action,other=other))
    results=[0,1,2,3,0x80,0x81,0x102,0xffffffff]
    for va in (0x55fb60,0x55fbf0):
        for count in (0,1,3):
            for result in results:
                cases.append(wire(va,count=count,wait=result,ticks=0x1234))
    for va in (0x55fb40,0x55fb90,0x55fc60):
        for first in (0,0x4010000):
            for result in results:
                cases.append(wire(va,wait=result,handles=(first,0x4020000,0x4030000)))
    for rate in (0,1,3,100,0xffffffff):
        for ticks in (0,1,0x12345678,0x7fffffff,0x80000000,0xffffffff):
            for result in (0,0x102,0xffffffff):
                cases.append(wire(0x55fbb0,wait=result,rate=rate,ticks=ticks))
    for result in (0,0x102,0xffffffff):
        cases.append(wire(0x55fbb0,wait=result,handles=(0,0x4020000,0x4030000)))
    return cases

def original(input_line,module,data,functions):
    va,count,raw_wait,rate,ticks,h0,h1,h2,raw_action,raw_other=map(int,input_line.split('|'))
    uc=Uc(UC_ARCH_X86,UC_MODE_32);base=int(module['image_base'],16)
    uc.mem_map(base,0x300000)
    for section in module['sections']:
        uc.mem_write(base+section['rva'],data[section['raw_offset']:section['raw_offset']+section['raw_size']])
    uc.mem_map(ARENA,0x1000);uc.mem_write(ARENA,b'\xcc'*0x1000)
    uc.mem_map(0x2000000,0x10000);uc.mem_map(EXIT,0x1000)
    def put(p,*values):uc.mem_write(p,struct.pack('<'+'I'*len(values),*[v&0xffffffff for v in values]))
    def words(p,n):return struct.unpack('<'+'I'*n,uc.mem_read(p,n*4))
    put(ARENA+0x100,h0,h1,h2);put(0x5deb48,rate)
    for iat,(target,_,_) in IAT.items():put(iat,EXIT+target)
    ranges=[(int(a,16),int(b,16)) for va0 in FUNCTIONS for a,b in functions[f'{va0:08x}']['ranges']]
    endpoints={EXIT+target:(label,n) for target,label,n in IAT.values()}
    calls=[];coverage=set()
    def hook(machine,p,size,user):
        if p==EXIT:machine.emu_stop();return
        if p in FUNCTIONS:coverage.add(f'{p:08x}')
        endpoint=endpoints.get(p)
        if endpoint is None:
            if not any(a<=p<=b for a,b in ranges):raise RuntimeError(f'Unexpected code {p:08x}')
            return
        label,n=endpoint;sp=uc.reg_read(UC_X86_REG_ESP);ret,*args=words(sp,n+1)
        if label=='wait':
            values=list(words(args[1],args[0])) if args[0] else []
            calls.append(['wait',args[0],values,args[2],args[3],args[4]])
            value=raw_wait
        elif label=='create':calls.append(['create',*args]);value=raw_other
        elif label=='set':calls.append(['set',*args]);value=raw_action
        elif label=='reset':calls.append(['reset',*args]);value=raw_action
        elif label=='close':calls.append(['close',*args]);value=raw_other
        elif label=='error':calls.append(['error']);value=raw_other
        elif label=='sleep':calls.append(['sleep',*args]);value=raw_other
        uc.reg_write(UC_X86_REG_EAX,value)
        uc.reg_write(UC_X86_REG_ESP,sp+4*(n+1))
        uc.reg_write(UC_X86_REG_EIP,ret)
    uc.hook_add(UC_HOOK_CODE,hook)
    arguments={0x55f740:[ticks],0x55fb20:[],0x55fb30:[h0],0x55fb40:[h0],
               0x55fb60:[count,ARENA+0x100,ticks],0x55fb90:[h0],0x55fbb0:[h0,ticks],
               0x55fbf0:[count,ARENA+0x100],0x55fc10:[h0],0x55fc20:[],0x55fc30:[h0],
               0x55fc40:[h0],0x55fc60:[h0],0x55fc80:[h0],0x55fce0:[]}[va]
    put(STACK,EXIT,*arguments);uc.reg_write(UC_X86_REG_ESP,STACK)
    uc.emu_start(va,EXIT+1,count=50000)
    if uc.reg_read(UC_X86_REG_EIP)!=EXIT or uc.reg_read(UC_X86_REG_ESP)!=STACK+4:
        raise RuntimeError(f'Original ABI/budget failure {va:08x}')
    return {'return':uc.reg_read(UC_X86_REG_EAX),'rate':words(0x5deb48,1)[0],
            'arena':bytes(uc.mem_read(ARENA,0x1000)).hex(),'calls':calls},coverage

def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--limit',type=int);parser.add_argument('--report-dir',type=Path,default=RUN);args=parser.parse_args();report_dir=args.report_dir if args.report_dir.is_absolute() else ROOT/args.report_dir
    module=next(x for x in map(json.loads,(ROOT/'research/binary-index/static/binaries.jsonl').read_text().splitlines()) if x['file']=='Porsche.exe')
    data=(ROOT/'local/game'/module['path']).read_bytes()
    if hashlib.sha256(data).hexdigest()!=module['sha256']:raise RuntimeError('Original SHA differs')
    functions={r['entry_va']:r for r in map(json.loads,(ROOT/'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/functions.jsonl').read_text().splitlines())}
    inputs=cases();inputs=inputs[:args.limit] if args.limit else inputs
    probe=ROOT/'local/builds/v2/001-original-recovery/bin/Release/event_probe.exe'
    native=subprocess.run([str(probe)],input='\n'.join(inputs)+'\n',text=True,capture_output=True,check=True,timeout=60)
    outputs=list(map(json.loads,native.stdout.splitlines()))
    if len(outputs)!=len(inputs):raise RuntimeError(f'Native output count {len(outputs)} != {len(inputs)}')
    coverage=set();fixtures=[]
    for i,(input_line,actual) in enumerate(zip(inputs,outputs)):
        expected,hit=original(input_line,module,data,functions);coverage|=hit
        if actual!=expected:
            path=ROOT/'local/reports/v2-events-mismatch.json';path.parent.mkdir(parents=True,exist_ok=True)
            path.write_text(json.dumps({'case':i,'input':input_line,'expected':expected,'actual':actual},indent=2)+'\n')
            raise RuntimeError(f'Case {i} differs: {[key for key in expected if expected[key]!=actual.get(key)]}; {path}')
        fixtures.append({'input':input_line,'output_sha256':hashlib.sha256(json.dumps(expected,sort_keys=True).encode()).hexdigest()})
    if coverage!={f'{va:08x}' for va in FUNCTIONS}:raise RuntimeError('Original function coverage incomplete')
    print(json.dumps({'cases':len(inputs),'functions':sorted(coverage),'native_equal_original':True}))
    if args.limit:return
    paths=['source/recovered/Porsche.exe/file_events.cpp','source/recovered/event_probe.cpp','source/include/porsche/file_events.hpp','source/include/porsche/file_wait.hpp','source/include/porsche/file_worker.hpp','source/include/porsche/file_device.hpp','source/include/porsche/files.hpp']
    paths=['iterations/v2/001-original-recovery/'+p for p in paths]
    paths += ['iterations/v2/001-original-recovery/source/include/porsche/'+name for name in ['heap.hpp','fe_stream.hpp']]
    report={'schema':1,'sha256':module['sha256'],'function_vas':sorted(coverage),'cases':len(inputs),
            'native_cpp_equal_original_x86':True,'binary_matched':False,'game_launch_verified':False,
            'comparison':'All 15 event function returns, fixed arena and ordered Win32 import calls; synthetic raw API results include timeout, abandoned and failed waits.',
            'boundaries':{'Win32':'CreateEvent/SetEvent/ResetEvent/WaitForMultipleObjectsEx/CloseHandle/GetLastError/SleepEx use recording stdcall endpoints; no real scheduler or OS event semantics.'},
            'source_sha256':{p:hashlib.sha256((ROOT/p).read_bytes().replace(b'\r\n',b'\n')).hexdigest() for p in paths},
            'probe_sha256':hashlib.sha256(probe.read_bytes()).hexdigest(),'fixtures':fixtures}
    report_dir.mkdir(parents=True,exist_ok=True)
    report['source_sha256']=source_hashes([*report['source_sha256'],Path(__file__)])
    (report_dir/'verification.json').write_text(json.dumps(report,indent=2)+'\n',newline='\n')
    (report_dir/'source-functions.jsonl').write_text(''.join(json.dumps({'sha256':module['sha256'],**functions[va]})+'\n' for va in sorted(coverage)),newline='\n')

if __name__=='__main__':main()
