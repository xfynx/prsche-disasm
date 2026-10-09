from v2_source_dependencies import source_hashes
"""Compare the recovered file worker with SHA-guarded Porsche.exe x86 execution."""
import argparse
import hashlib
import json
from pathlib import Path
import struct
import subprocess
import sys

ROOT=Path(__file__).resolve().parents[2]
RUN=ROOT/'iterations/v2/001-original-recovery/runs/007-file-worker'
sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ESP,UC_X86_REG_EIP
from v2_manual_index import records

ARENA=0x3400000
STACK=0x200f000
EXIT=0x2200000
CALLBACK=EXIT+0x100
DIAGNOSTIC=EXIT+0x200
FUNCTIONS=[0x568530,0x580670,0x580730,0x580790,0x580850,0x5808f0,0x580930,0x580ea0,0x580ec0,0x5806e0]
ENDPOINTS={0x5322b0:1,0x5322c0:1,0x55fc30:1,0x55fb90:1,0x55fce0:0,
           0x568900:3,0x592140:2,0x591df0:3,0x591fa0:3,0x591ce0:5,
           0x5924d0:2,0x592490:1,0x591980:1,0x592290:1,
           0x5684c0:2,CALLBACK:3,DIAGNOSTIC:2}

def cases():
    rows=[]
    for op in range(12):
        for result,error in [(1,0),(0,0),(0,5)]:
            rows.append((0,op,0,0,result,error,0,0))
    rows += [(6,0,mask,0,1,0,0,0) for mask in (0,1,2,4,8,16,32,3,5,6,7,63)]
    rows += [(0,op,2,0,1,5,0,0) for op in (0,1,2,7,11)]
    rows += [(2,op,0,0,1,0,0,3) for op in (0,2,7,10)]
    rows += [(1,0,0,0,1,0,0,0),(5,0,0,0,1,0,0,0),(0,0,0,0,1,0,1,0),
             (4,2,0,1,1,0,0,0),(8,9,0,0,1,0,0,0),
             (9,2,0,0,1,0,0,0),(10,2,0x80,0,0,0,0,0),(10,2,0xff,0,0,0,0,0),
             (0,12,0,0,1,0,0,0),(0,0xffffffff,0,0,1,0,0,0),
             (11,2,0,0,1,0,0,0),(12,0,0,0,1,0,0,0)]
    return ['|'.join(map(str,r)) for r in rows]

def original(wire,module,data,functions):
    mode,opcode,flags,group,backend,error,shutdown,count=map(int,wire.split('|'))
    uc=Uc(UC_ARCH_X86,UC_MODE_32);base=int(module['image_base'],16)
    uc.mem_map(base,0x300000)
    for section in module['sections']:
        uc.mem_write(base+section['rva'],data[section['raw_offset']:section['raw_offset']+section['raw_size']])
    uc.mem_map(ARENA,0x10000);uc.mem_write(ARENA,b'\xcc'*0x10000)
    uc.mem_map(0x2000000,0x10000);uc.mem_map(EXIT,0x1000)
    def put(p,*values):uc.mem_write(p,struct.pack('<'+'I'*len(values),*[x&0xffffffff for x in values]))
    def words(p,n):return struct.unpack('<'+'I'*n,uc.mem_read(p,4*n))
    def put_bytes(p,b):uc.mem_write(p,b)
    def cstring(p):
        out=bytearray()
        while (v:=uc.mem_read(p+len(out),1)[0]):
            if len(out)>=1024:raise RuntimeError('Unterminated original diagnostic string')
            out.append(v)
        return out.hex()
    put(0x6a5c7c,ARENA+0x100);put(0x6a5c80,shutdown);put(0x5debf0,DIAGNOSTIC)
    put(ARENA+0x100,*([0]*28));dev=ARENA+0x100
    put(dev,0 if mode==5 else 1)
    put(dev+0x24,0,0,0,0,0x5684c0,0,0x2001000)
    put(dev+0x40,0,0,0,0,0x580670,0,0x2001000)
    put(dev+0x5c,0x4001000);put(dev+0x64,0x4002000);put(dev+0x6c,0 if mode==4 else 0xffffffff if mode==11 else 0xff)
    put(0x6a5c58,*([0]*7));put(0x6a5c38,0,0,0,0,0,0,0x2003000)
    n=3 if mode==2 else 0 if mode in (1,5,12) else 1
    for i in range(n):
        o=ARENA+0x1000+i*0x80
        put_bytes(o,b'\xcc'*48)
        put(o,ARENA+0x1000+(i+1)*0x80 if i+1<n else 0,0x81234000+i*0x20,opcode,0 if mode in (6,10) else flags)
        put_bytes(o+0x10,bytes(((flags&255) if mode==10 else 0x7e,group&255)))
        put(o+0x14,0xabcdef12,0x12340000+i*0x100,ARENA+0x6000+i*4,0 if mode==9 else CALLBACK,flags if mode==6 else 0x31+i,0x41+i,0 if mode==8 else ARENA+0x4000+i*0x100)
        if opcode in (0,3,9):
            put_bytes(ARENA+0x3000+i*0x100,b'worker.bin\0')
            if mode!=8:put(o+0x2c,ARENA+0x3000+i*0x100)
        if opcode==10:
            put(ARENA+0x2000,0)
            put(0x6a5c38,1,0,ARENA+0x2000,ARENA+0x2000,0,0,0x2003000)
            put(o+0x2c,ARENA+0x2000)
    if n:put(dev+0x24,n,1,ARENA+0x1000,ARENA+0x1000+(n-1)*0x80)
    ranges=[(int(a,16),int(b,16)) for va in FUNCTIONS for a,b in functions[f'{va:08x}']['ranges']]
    calls=[];states=[];coverage=set();signals=0
    def snapshot():
        state=bytearray(uc.mem_read(dev,0x70))
        for i in range(3):state.extend(uc.mem_read(ARENA+0x1000+i*0x80,48))
        state.extend(uc.mem_read(0x6a5c38,28))
        return state.hex()
    def hook(machine,p,size,user):
        nonlocal signals
        if p==EXIT:machine.emu_stop();return
        if p in FUNCTIONS:coverage.add(f'{p:08x}')
        argc=ENDPOINTS.get(p)
        if argc is None:
            if not any(a<=p<=b for a,b in ranges):raise RuntimeError(f'Unexpected original code {p:08x}')
            return
        sp=uc.reg_read(UC_X86_REG_ESP);ret,*args=words(sp,argc+1);value=0
        if p!=0x5684c0:states.append(snapshot())
        if p in (0x5322b0,0x5322c0):calls.append(['enter' if p==0x5322b0 else 'leave',args[0]])
        elif p==0x55fc30:
            calls.append(['signal',args[0]]);signals+=1
            if signals >= (count+1 if count else 2):put(0x6a5c80,1)
        elif p==0x55fb90:calls.append(['wait',args[0]]);put(0x6a5c80,1)
        elif p==0x55fce0:calls.append(['error']);value=error
        elif p==0x568900:calls.append(['open',*args]);value=backend
        elif p in (0x592140,0x591df0,0x591fa0,0x591ce0,0x5924d0,0x592490,0x591980,0x592290):
            label={0x592140:'seek',0x591df0:'read',0x591fa0:'write',0x591ce0:'info',0x5924d0:'backend_d0',0x592490:'backend_90',0x591980:'backend_80',0x592290:'close'}[p]
            calls.append([label,*([args[0],args[1],args[2],0x200ff00,args[4]] if p==0x591ce0 else args)]);value=backend
            if p==0x591ce0 and backend:put(args[3],0x12345678)
        elif p==0x5684c0:value=((words(args[0]+4,1)[0]>>5)&0xffffff)|((uc.mem_read(args[0]+0x11,1)[0])<<24)
        elif p==CALLBACK:calls.append(['callback',args[0],args[1] if args[1]<0x80000000 else args[1]-0x100000000,args[2]])
        elif p==DIAGNOSTIC:calls.append(['diagnostic',words(0x5deb78,1)[0],cstring(args[0]),cstring(words(0x5deb74,1)[0]),args[1]])
        uc.reg_write(UC_X86_REG_EAX,value)
        uc.reg_write(UC_X86_REG_ESP,sp+4)
        uc.reg_write(UC_X86_REG_EIP,ret)
    uc.hook_add(UC_HOOK_CODE,hook)
    if mode==12:
        for va,argv in [(0x5806e0,[dev+0x40,0]),(0x5808f0,[0x6a5c38,0])]:
            put(STACK,EXIT,*argv);uc.reg_write(UC_X86_REG_ESP,STACK)
            uc.emu_start(va,EXIT+1,count=1000000)
            if uc.reg_read(UC_X86_REG_EIP)!=EXIT or uc.reg_read(UC_X86_REG_ESP)!=STACK+4:raise RuntimeError(f'Helper ABI/budget failure {va:08x}')
    else:
        put(STACK,EXIT,0);uc.reg_write(UC_X86_REG_ESP,STACK)
        uc.emu_start(0x568530,EXIT+1,count=1000000)
        if uc.reg_read(UC_X86_REG_EIP)!=EXIT or uc.reg_read(UC_X86_REG_ESP)!=STACK+4:raise RuntimeError('Worker ABI/budget failure')
    return {'arena':bytes(uc.mem_read(ARENA,0x10000)).hex(),'aux':bytes(uc.mem_read(0x6a5c38,28)).hex(),
            'shutdown':words(0x6a5c80,1)[0],'calls':calls,'states':states},coverage

def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--limit',type=int)
    parser.add_argument('--report-dir',type=Path,default=ROOT/'iterations/v2/001-original-recovery/runs/009-file-events/worker-regression');args=parser.parse_args()
    module=next(x for x in map(json.loads,(ROOT/'research/binary-index/static/binaries.jsonl').read_text().splitlines()) if x['file']=='Porsche.exe')
    data=(ROOT/'local/game'/module['path']).read_bytes()
    assert hashlib.sha256(data).hexdigest()==module['sha256'],'Original SHA differs'
    functions={r['entry_va']:r for r in map(json.loads,(ROOT/'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/functions.jsonl').read_text().splitlines())}
    functions.update({r['entry_va']:r for r in records(module['sha256'])})
    inputs=cases();inputs=inputs[:args.limit] if args.limit else inputs
    probe=ROOT/'local/builds/v2/001-original-recovery/bin/Release/worker_probe.exe'
    native=subprocess.run([str(probe)],input='\n'.join(inputs)+'\n',text=True,capture_output=True,check=True,timeout=60)
    outputs=list(map(json.loads,native.stdout.splitlines()))
    assert len(outputs)==len(inputs),(len(outputs),len(inputs))
    coverage=set();fixtures=[]
    for i,(wire,actual) in enumerate(zip(inputs,outputs)):
        expected,hit=original(wire,module,data,functions);coverage|=hit
        if actual!=expected:
            path=ROOT/'local/reports/v2-worker-mismatch.json';path.parent.mkdir(parents=True,exist_ok=True)
            path.write_text(json.dumps({'case':i,'input':wire,'expected':expected,'actual':actual},indent=2)+'\n')
            raise RuntimeError(f'Case {i} differs: {[k for k in expected if expected[k]!=actual.get(k)]}; {path}')
        fixtures.append({'input':wire,'output_sha256':hashlib.sha256(json.dumps(expected,sort_keys=True).encode()).hexdigest()})
    print(json.dumps({'cases':len(inputs),'functions':sorted(coverage),'native_equal_original':True}))
    if args.limit:return
    paths=['source/recovered/Porsche.exe/file_worker.cpp','source/recovered/Porsche.exe/io_lists.cpp','source/recovered/Porsche.exe/io_worker_lists.cpp','source/recovered/worker_probe.cpp','source/include/porsche/file_worker.hpp','source/include/porsche/file_device.hpp','source/include/porsche/files.hpp']
    paths=['iterations/v2/001-original-recovery/'+p for p in paths]
    paths += ['iterations/v2/001-original-recovery/source/include/porsche/'+name for name in ['heap.hpp','fe_stream.hpp']]
    report={'schema':1,'sha256':module['sha256'],'function_vas':sorted(coverage),'cases':len(inputs),'native_cpp_equal_original_x86':True,'binary_matched':False,'game_launch_verified':False,
            'comparison':'Full worker arena, auxiliary list, shutdown state, ordered boundary calls and a device/operation/list state snapshot at every boundary; fixture stops loop via shutdown global only.',
            'source_sha256':{p:hashlib.sha256((ROOT/p).read_bytes().replace(b'\r\n',b'\n')).hexdigest() for p in paths},'probe_sha256':hashlib.sha256(probe.read_bytes()).hexdigest(),'fixtures':fixtures}
    args.report_dir.mkdir(parents=True,exist_ok=True)
    report['source_sha256']=source_hashes([*report['source_sha256'],Path(__file__)])
    (args.report_dir/'verification.json').write_text(json.dumps(report,indent=2)+'\n',newline='\n')
    (args.report_dir/'source-functions.jsonl').write_text(''.join(json.dumps({'sha256':module['sha256'],**functions[va]})+'\n' for va in sorted(coverage) if va in functions),newline='\n')

if __name__=='__main__':main()
