from v2_source_dependencies import source_hashes
"""Verify startup allocator dispatch against original Porsche.exe x86."""
import argparse
import hashlib,json,struct,subprocess,sys
from pathlib import Path

ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ESP,UC_X86_REG_EIP
EXIT=0x2200000
STACK=0x200f000
ARENA=0x3600000
FUNCTIONS=[0x531f70,0x59ef90,0x59efc0,0x59eff0,0x59f020,0x59f050]

def cases():
    rows=[]
    for op in range(5):
        for size in (0,1,0x268,0xffffffff):
            for heap in (0,1,0xffffffff):
                for result in (0,1):rows.append((op,size,heap,result))
    for address in (0,ARENA+0x200):
        for result in (0,1):rows.append((5,address,1,result))
    return rows

def original(case,module,data):
    op,size,heap,outcome=case
    uc=Uc(UC_ARCH_X86,UC_MODE_32);base=int(module['image_base'],16)
    uc.mem_map(base,0x300000)
    for section in module['sections']:
        uc.mem_write(base+section['rva'],data[section['raw_offset']:section['raw_offset']+section['raw_size']])
    uc.mem_map(0x2000000,0x10000);uc.mem_map(EXIT,0x1000);uc.mem_map(ARENA,0x1000)
    def put(address,value):uc.mem_write(address,struct.pack('<I',value&0xffffffff))
    def word(address):return struct.unpack('<I',uc.mem_read(address,4))[0]
    def cstring(address):return bytes(uc.mem_read(address,32)).split(b'\0',1)[0].decode('latin1')
    put(0x5e4fe8,0x5e4700);put(0x6af3fc,heap)
    put(STACK,EXIT)
    args=(0x5e5070,size,heap) if op==0 else ((size,heap) if op in (2,4) else (size,))
    for i,arg in enumerate(args):put(STACK+4+i*4,arg)
    uc.reg_write(UC_X86_REG_ESP,STACK)
    calls=[]
    bounds=[(0x531f70,0x531f87),(0x59ef90,0x59efb5),(0x59efc0,0x59efe4),
            (0x59eff0,0x59f010),(0x59f020,0x59f044),(0x59f050,0x59f062)]
    def hook(machine,address,length,user):
        if address==EXIT:machine.emu_stop();return
        if address not in (0x531ca0,0x531f90):
            if not any(first<=address<=last for first,last in bounds):
                raise RuntimeError(f'unexpected original code {address:08x}')
            return
        sp=machine.reg_read(UC_X86_REG_ESP);ret=word(sp)
        if address==0x531ca0:
            name=cstring(word(sp+4));bytes_=word(sp+8);index=word(sp+12)
            calls.append(['alloc',name,bytes_,index]);result=ARENA+0x200 if outcome else 0
        else:
            calls.append(['free','',word(sp+4),0]);result=outcome
        machine.reg_write(UC_X86_REG_EAX,result)
        machine.reg_write(UC_X86_REG_ESP,sp+4)
        machine.reg_write(UC_X86_REG_EIP,ret)
    uc.hook_add(UC_HOOK_CODE,hook)
    uc.emu_start(FUNCTIONS[op],EXIT+1,count=1000)
    assert uc.reg_read(UC_X86_REG_EIP)==EXIT
    return {'return':uc.reg_read(UC_X86_REG_EAX),'calls':calls}

def main():
    parser=argparse.ArgumentParser()
    parser.add_argument('--probe',type=Path,default=ROOT/'local/builds/v2/001-original-recovery/bin/Release/application_alloc_probe.exe')
    parser.add_argument('--report-dir',type=Path,default=ROOT/'iterations/v2/001-original-recovery/runs/031-application-alloc')
    args=parser.parse_args();binary=args.probe
    report=args.report_dir
    report.mkdir(parents=True,exist_ok=True)
    module=next(x for x in map(json.loads,(ROOT/'research/binary-index/static/binaries.jsonl').read_text().splitlines()) if x['file']=='Porsche.exe')
    data=(ROOT/'local/game'/module['path']).read_bytes()
    assert hashlib.sha256(data).hexdigest()=='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
    inputs=cases()
    process=subprocess.run([str(binary)],input=''.join(' '.join(map(str,x))+'\n' for x in inputs),text=True,capture_output=True,check=True)
    native=list(map(json.loads,process.stdout.splitlines()))
    assert len(native)==len(inputs)
    for i,(case,actual) in enumerate(zip(inputs,native)):
        expected=original(case,module,data)
        if actual!=expected:raise AssertionError(f'case {i} {case}: original={expected} native={actual}')
    paths=['iterations/v2/001-original-recovery/source/include/porsche/application_alloc.hpp',
           'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/application_alloc.cpp',
           'iterations/v2/001-original-recovery/source/recovered/application_alloc_probe.cpp']
    paths += ['scripts/research/verify-v2-application-alloc.py']
    paths += ['iterations/v2/001-original-recovery/source/include/porsche/fe_stream.hpp','iterations/v2/001-original-recovery/source/include/porsche/application_heap.hpp']
    result={'schema':1,'module':'Porsche.exe','sha256':module['sha256'],'module_sha256':module['sha256'],
            'function_vas':[f'{x:08x}' for x in FUNCTIONS],'cases':len(inputs),
            'native_cpp_equal_original_x86':True,
            'scope':'Active startup allocator table and wrappers; core allocate/free stop at existing recovered implementation boundary',
            'source_sha256':{p:hashlib.sha256((ROOT/p).read_bytes().replace(b'\r\n',b'\n')).hexdigest() for p in paths},
            'probe_sha256':hashlib.sha256(binary.read_bytes()).hexdigest()}
    result['source_sha256']=source_hashes([*result['source_sha256'],Path(__file__)])
    (report/'verification.json').write_text(json.dumps(result,indent=2)+'\n',newline='\n')
    print(json.dumps({'cases':len(inputs),'function_vas':result['function_vas'],'native_cpp_equal_original_x86':True}))
if __name__=='__main__':main()
