from v2_source_dependencies import source_hashes
import argparse
"""Compare original x86 and native C++ page wrappers (Porsche.exe 59ed40/59ed90)."""
import hashlib,json,struct,subprocess,sys
from pathlib import Path

ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ESP,UC_X86_REG_EIP

EXIT=0x2200000
ARENA=0x3600000
STACK=0x200f000
TARGETS={0x2200100:'page',0x2200200:'alloc',0x2200300:'free'}
IAT={0x5b21b0:0x2200100,0x5b2144:0x2200200,0x5b2148:0x2200300}

def cases():
    out=[]
    for cached in (0,4096,8192):
        for value in (0,1,4095,4096,4097,0xffffffff):
            for success in (0,1):out.append((0,value,cached,4096,success))
    for value in (0,ARENA+0x200):
        for success in (0,1):out.append((1,value,4096,4096,success))
    for primary,objects,success in ((0x1800000,0x400000,1),(4097,0,1),(4097,4096,0),(4097,4096,0xffffffff)):
        out.append((2,primary,objects,4096,success))
    for count in (0,1,2,400):out.append((3,count,4096,4096,1))
    return out

def extended(case,module,data):
    op,value,cached,page,success=case
    uc=Uc(UC_ARCH_X86,UC_MODE_32);base=int(module['image_base'],16)
    uc.mem_map(base,0x300000)
    for section in module['sections']:
        uc.mem_write(base+section['rva'],data[section['raw_offset']:section['raw_offset']+section['raw_size']])
    uc.mem_map(0x2000000,0x10000);uc.mem_map(EXIT,0x1000);uc.mem_map(ARENA,0x10000)
    def put(addr,x):uc.mem_write(addr,struct.pack('<I',x&0xffffffff))
    def word(addr):return struct.unpack('<I',uc.mem_read(addr,4))[0]
    for addr,target in IAT.items():put(addr,target)
    put(STACK,EXIT)
    for i,x in enumerate((value,cached,page,0x1234) if op==2 else (value,0)):
        put(STACK+4+4*i,x)
    if op==2:
        put(0x5debf0,0x2200d00)
    else:
        put(0x6af3f8,cached)
        put(0x5e4fe8,0x5e4700);put(0x5e4704,0x2200e00)
        put(0x5e4728,ARENA+0x300);put(0x5e472c,ARENA+0x500)
        put(0x5e4fec,ARENA+0x800);put(ARENA+0x800,ARENA+0x400)
    uc.reg_write(UC_X86_REG_ESP,STACK)
    events=[];locks=0;nodes=0
    boundaries={0x55f320:1,0x53c290:3,0x5321f0:0,0x5aef80:2,
        0x59ebc0:5,0x2200d00:2,0x55eba0:0,0x55ecd0:2,0x55f150:2,
        0x55ef90:2,0x5679f0:3,0x5322b0:1,0x5322c0:1,0x2200e00:3}
    def hook(machine,address,size,user):
        nonlocal locks,nodes
        if address==EXIT:machine.emu_stop();return
        if address not in TARGETS and address not in boundaries:
            valid=((0x59e9d0<=address<=0x59eb13 or 0x59ed40<=address<=0x59ed8a) if op==2
                   else 0x59edb0<=address<=0x59ee23)
            if not valid:raise RuntimeError(f'unexpected code {address:08x}')
            return
        sp=machine.reg_read(UC_X86_REG_ESP);ret=word(sp);result=0
        if address in TARGETS:
            name=TARGETS[address]
            if name=='page':
                put(word(sp+4)+4,page);events.append(['page',0,0,0]);argc=1
            elif name=='alloc':
                args=[word(sp+4+4*i) for i in range(4)]
                events.append(['alloc',*args[1:]]);result=ARENA+0x200 if success else 0;argc=4
            else:raise RuntimeError('unexpected free')
            stdcall=True
        else:
            argc=boundaries[address];args=[word(sp+4+4*i) for i in range(argc)];stdcall=False
            if address==0x55f320:events.append(['os',args[0],0,0])
            elif address==0x53c290:
                events.append(['fill',args[1],args[2],0]);machine.mem_write(args[0],bytes([args[1]&255])*args[2])
            elif address==0x5321f0:
                events.append(['lock_create',locks,0,0]);result=ARENA+0x300+4*locks;locks+=1
            elif address==0x5aef80:events.append(['commit',args[0],args[1],0])
            elif address==0x59ebc0:
                events.append(['object',args[0],args[2],args[3]]);result=success
            elif address==0x2200d00:events.append(['diagnostic',args[1],0,0])
            elif address==0x55eba0:events.append(['secondary',0,0,0])
            elif address==0x55ecd0:events.append(['queue_kind',*args,0])
            elif address==0x55f150:events.append(['printf',args[0],0,0])
            elif address==0x55ef90:events.append(['heap_kind',*args,0])
            elif address==0x5679f0:events.append(['finish',*args])
            elif address==0x5322b0:events.append(['lock_enter',args[0],0,0])
            elif address==0x5322c0:events.append(['lock_leave',args[0],0,0])
            elif address==0x2200e00:
                events.append(['queue_alloc',args[0],args[1],args[2]])
                result=ARENA+0x600+nodes*16;nodes+=1
        machine.reg_write(UC_X86_REG_EAX,result)
        machine.reg_write(UC_X86_REG_ESP,sp+4*(argc+1) if stdcall else sp+4)
        machine.reg_write(UC_X86_REG_EIP,ret)
    uc.hook_add(UC_HOOK_CODE,hook)
    uc.emu_start(0x59e9d0 if op==2 else 0x59edb0,EXIT+1,count=100000)
    assert uc.reg_read(UC_X86_REG_EIP)==EXIT
    if op==2:
        state=[int.from_bytes(uc.mem_read(0x6af3f4,1),'little'),word(0x5deb74),word(0x5deb78)]
        state.extend(word(0x5e4728+i*0x8c) for i in range(16))
        return {'value':word(0x6af3fc),'page':word(0x6af3f8),'result':word(0x6af3b4),
                'calls':events,'state':state}
    chain=[];node=word(0x5e472c)
    for i in range(nodes):
        chain.append((node-(ARENA+0x600))//16)
        node=word(node+4)
    return {'value':nodes if word(0x5e472c)!=ARENA+0x500 else 0,
            'page':word(0x6af3f8),'result':nodes,'calls':events,'chain':chain}

def original(case,module,data):
    op,value,cached,page,success=case
    uc=Uc(UC_ARCH_X86,UC_MODE_32);base=int(module['image_base'],16)
    uc.mem_map(base,0x300000)
    for section in module['sections']:
        uc.mem_write(base+section['rva'],data[section['raw_offset']:section['raw_offset']+section['raw_size']])
    uc.mem_map(0x2000000,0x10000);uc.mem_map(EXIT,0x1000);uc.mem_map(ARENA,0x1000)
    def put(addr,x):uc.mem_write(addr,struct.pack('<I',x&0xffffffff))
    def word(addr):return struct.unpack('<I',uc.mem_read(addr,4))[0]
    for addr,target in IAT.items():put(addr,target)
    put(0x6af3f8,cached);put(ARENA+0x100,value)
    put(STACK,EXIT);put(STACK+4,ARENA+0x100 if op==0 else value)
    uc.reg_write(UC_X86_REG_ESP,STACK)
    events=[]
    def hook(machine,address,size,user):
        if address==EXIT:machine.emu_stop();return
        if address not in TARGETS:
            first,last=(0x59ed40,0x59ed8a) if op==0 else (0x59ed90,0x59eda2)
            if not first<=address<=last:raise RuntimeError(f'unexpected code {address:08x}')
            return
        name=TARGETS[address];sp=machine.reg_read(UC_X86_REG_ESP)
        ret=word(sp)
        if name=='page':
            put(word(sp+4)+4,page);events.append(['page',0,0,0]);result=0;argc=1
        elif name=='alloc':
            args=[word(sp+4+4*i) for i in range(4)]
            assert args[0]==0
            events.append(['alloc',*args[1:]]);result=ARENA+0x200 if success else 0;argc=4
        else:
            args=[word(sp+4+4*i) for i in range(3)]
            events.append(['free',*args]);result=success;argc=3
        machine.reg_write(UC_X86_REG_EAX,result)
        machine.reg_write(UC_X86_REG_ESP,sp+4*(argc+1))
        machine.reg_write(UC_X86_REG_EIP,ret)
    uc.hook_add(UC_HOOK_CODE,hook)
    uc.emu_start(0x59ed40 if op==0 else 0x59ed90,EXIT+1,count=1000)
    assert uc.reg_read(UC_X86_REG_EIP)==EXIT
    return {'value':word(ARENA+0x100) if op==0 else value,'page':word(0x6af3f8),
            'result':uc.reg_read(UC_X86_REG_EAX),'calls':events}

def main():
    parser=argparse.ArgumentParser()
    parser.add_argument('--probe',type=Path,default=ROOT/'local/builds/v2/001-original-recovery/bin/Release/application_heap_probe.exe')
    parser.add_argument('--report-dir',type=Path,default=ROOT/'iterations/v2/001-original-recovery/runs/025-application-heap')
    args=parser.parse_args();binary=args.probe;report=args.report_dir
    report.mkdir(parents=True,exist_ok=True)
    module=next(x for x in map(json.loads,(ROOT/'research/binary-index/static/binaries.jsonl').read_text().splitlines()) if x['file']=='Porsche.exe')
    data=(ROOT/'local/game'/module['path']).read_bytes()
    assert hashlib.sha256(data).hexdigest()=='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
    inputs=cases()
    process=subprocess.run([str(binary)],input=''.join(' '.join(map(str,x))+'\n' for x in inputs),text=True,capture_output=True,check=True)
    native=list(map(json.loads,process.stdout.splitlines()))
    assert len(native)==len(inputs)
    for i,(case,actual) in enumerate(zip(inputs,native)):
        expected=(extended if case[0]>=2 else original)(case,module,data)
        if actual!=expected:
            raise AssertionError(f'case {i} {case}: original={expected} native={actual}')
    paths=['iterations/v2/001-original-recovery/source/include/porsche/application_heap.hpp',
           'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/application_heap.cpp',
           'iterations/v2/001-original-recovery/source/recovered/application_heap_probe.cpp']
    result={'schema':1,'module':'Porsche.exe','sha256':module['sha256'],'module_sha256':module['sha256'],
            'function_vas':['0059e9d0','0059ed40','0059ed90','0059edb0'],'cases':len(inputs),
            'native_cpp_equal_original_x86':True,
            'scope':'Startup, page wrappers, and bounded queue with controlled OS/allocator/FE callees',
            'source_sha256':{p:hashlib.sha256((ROOT/p).read_bytes().replace(b'\r\n',b'\n')).hexdigest() for p in paths},
            'probe_sha256':hashlib.sha256(binary.read_bytes()).hexdigest()}
    result['source_sha256']=source_hashes([*result['source_sha256'],Path(__file__)])
    (report/'verification.json').write_text(json.dumps(result,indent=2)+'\n',newline='\n')
    print(json.dumps({'cases':len(inputs),'function_vas':result['function_vas'],'native_cpp_equal_original_x86':True}))
if __name__=='__main__':main()
