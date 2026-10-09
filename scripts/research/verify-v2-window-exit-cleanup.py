"""Compare the bounded 00558350 cleanup path with original x86 execution."""
import argparse, hashlib, json, struct, subprocess, sys
from pathlib import Path

ROOT=Path(__file__).resolve().parents[2]
RUN=ROOT/'iterations/v2/001-original-recovery/runs/085-window-exit-cleanup'
SHA='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ESP,UC_X86_REG_EIP
from v2_source_dependencies import source_hashes

STACK,EXIT,BOUNDARY,OBJECT,VTABLE,CONFIG=0x3108000,0x3200000,0x3210000,0x3300000,0x3301000,0x3400000
LOCK=0x2222000
BOUNDARIES={0x5322b0:'enter',0x557990:'cleanup',0x531f90:'free',0x5322c0:'leave',BOUNDARY:'vtable'}

def put(u,a,v):u.mem_write(a,struct.pack('<I',v&0xffffffff))
def word(u,a):return struct.unpack('<I',u.mem_read(a,4))[0]

def original(module,image,config_address,allocation,empty=False):
    u=Uc(UC_ARCH_X86,UC_MODE_32); u.mem_map(0x400000,0x300000)
    for s in module['sections']:
        if s['raw_size']:
            u.mem_write(0x400000+s['rva'],image[s['raw_offset']:s['raw_offset']+s['raw_size']])
    u.mem_map(0x3100000,0x10000);u.mem_map(EXIT,0x1000);u.mem_map(BOUNDARY,0x1000)
    u.mem_map(OBJECT,0x1000);u.mem_map(VTABLE,0x1000);u.mem_map(CONFIG,0x1000)
    put(u,0x6a57d8,LOCK);put(u,OBJECT,VTABLE);put(u,VTABLE+8,BOUNDARY)
    state=config_address
    put(u,state,0 if empty else OBJECT);put(u,state+4,0x11111111);put(u,state+0x10,allocation);put(u,state+0x24,0x22222222)
    trace=[]
    def hook(m,address,_size,_):
        if address not in BOUNDARIES:return
        sp=m.reg_read(UC_X86_REG_ESP);arg=word(m,sp+4);name=BOUNDARIES[address]
        if name=='enter':trace.append('enter:lock' if arg==LOCK else 'enter:other')
        elif name=='leave':trace.append('leave:lock' if arg==LOCK else 'leave:other')
        elif name=='cleanup':trace.append('cleanup:self' if arg==state else 'cleanup:other')
        elif name=='free':trace.append('free:'+str(arg))
        else:trace.append('vtable:object' if arg==OBJECT else 'vtable:other')
        m.reg_write(UC_X86_REG_EAX,1 if name=='free' else 0)
        m.reg_write(UC_X86_REG_ESP,sp+(8 if name=='vtable' else 4));m.reg_write(UC_X86_REG_EIP,word(m,sp))
    u.hook_add(UC_HOOK_CODE,hook)
    put(u,STACK,EXIT);put(u,STACK+4,0 if config_address==0x6b77a0 else state)
    u.reg_write(UC_X86_REG_ESP,STACK);u.emu_start(0x558350,EXIT,count=10000)
    return {'fields':[word(u,state+x) for x in (0,4,0x10,0x24)],'calls':trace}

def parse(line):
    parts=line.split();n=int(parts[5]);return {'fields':[int(x) for x in parts[1:5]],'calls':parts[6:6+n]}

def main():
    ap=argparse.ArgumentParser();ap.add_argument('--probe',type=Path,default=ROOT/'local/builds/v2/001-original-recovery/window-exit-cleanup-085/bin/Release/window_exit_cleanup_probe.exe');ap.add_argument('--report',type=Path,default=RUN/'verification.json');args=ap.parse_args()
    module=next(json.loads(x) for x in (ROOT/'research/binary-index/static/binaries.jsonl').read_text(encoding='utf8').splitlines() if json.loads(x)['file']=='Porsche.exe')
    image=(ROOT/'local/game'/module['path']).read_bytes()
    if hashlib.sha256(image).hexdigest()!=SHA:raise RuntimeError('original Porsche.exe SHA mismatch')
    cases=[('empty',0x3400000,0,True),('no_allocation',0x3400000,0,False),('fallback_with_allocation',0x6b77a0,0x76543210,False)]
    run=subprocess.run([str(args.probe)],text=True,capture_output=True,check=True,timeout=10)
    actual={line.split()[0]:parse(line) for line in run.stdout.splitlines()}
    outputs=[]
    for name,address,allocation,empty in cases:
        expected=original(module,image,address,allocation,empty)
        if actual.get(name)!=expected:raise RuntimeError(f'{name}: original={expected}, native={actual.get(name)}')
        outputs.append({'case':name,'output':expected})
    deps=['iterations/v2/001-original-recovery/source/include/porsche/window_exit_cleanup.hpp','iterations/v2/001-original-recovery/source/recovered/Porsche.exe/window_exit_cleanup.cpp','iterations/v2/001-original-recovery/source/recovered/window_exit_cleanup_probe.cpp','iterations/v2/001-original-recovery/runs/085-window-exit-cleanup/CMakeLists.txt','iterations/v2/001-original-recovery/runs/085-window-exit-cleanup/README.md','scripts/research/verify-v2-window-exit-cleanup.py']
    report={'schema':1,'sha256':SHA,'full_function_vas':['00558350'],'partial_function_vas':[],'original_sha256':SHA,'function_vas':['00558350'],'function_va':'00558350','range':['00558350','005583ba'],'body_bytes':107,'caller_va':'0053ba72','cases':outputs,'native_cpp_equal_original_x86':True,'native_abi':'cdecl; one pointer parameter; caller stack cleanup','boundary_limits':'00557990 and the object vtable +8 are intercepted as explicit unknown-effect boundaries; free_00531f90 and lock calls are observed at their call boundary. No full heap/object/driver behavior is claimed.','source_sha256':source_hashes(deps,compiled_sources=deps[:3]),'probe_sha256':hashlib.sha256(args.probe.read_bytes()).hexdigest(),'game_launch_verified':False}
    args.report.parent.mkdir(parents=True,exist_ok=True);args.report.write_text(json.dumps(report,indent=2)+'\n',encoding='utf8')
    print(json.dumps({'cases':len(outputs),'matched':True,'report':str(args.report)}))
if __name__=='__main__':main()
