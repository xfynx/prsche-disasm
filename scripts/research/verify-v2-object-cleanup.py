"""Differentially verify the object cleanup consumers 00557990/00558c80."""
import argparse,hashlib,json,struct,subprocess,sys
from pathlib import Path

ROOT=Path(__file__).resolve().parents[2]
RUN=ROOT/'iterations/v2/001-original-recovery/runs/088-object-cleanup'
SHA='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ESP,UC_X86_REG_EIP
from v2_source_dependencies import source_hashes

STACK,EXIT,BOUNDARY=0x3108000,0x3200000,0x3210000
CONFIG,MAIN,A,B,VTABLE=0x3400000,0x3500000,0x3501000,0x3502000,0x3503000
V8,V28,UPDATE=BOUNDARY,BOUNDARY+4,0x5588a0
FIELDS=(0,0x43c,0x448,0x44c,0x450,0x454)

def put(u,a,v):u.mem_write(a,struct.pack('<I',v&0xffffffff))
def word(u,a):return struct.unpack('<I',u.mem_read(a,4))[0]
def setup(u,state,match=0,handles=False):
    u.mem_map(0x3100000,0x10000);u.mem_map(EXIT,0x1000);u.mem_map(BOUNDARY,0x1000)
    u.mem_map(CONFIG,0x1000);u.mem_map(0x3500000,0x5000)
    put(u,MAIN,VTABLE);put(u,A,VTABLE);put(u,B,VTABLE)
    put(u,VTABLE+8,V8);put(u,VTABLE+0x28,V28)
    put(u,state,MAIN);put(u,state+0x43c,match)
    put(u,state+0x448,B if handles else 0);put(u,state+0x44c,A if handles else 0)
    put(u,state+0x450,0xaaaa5555);put(u,state+0x454,0x5555aaaa)

def original(module,image,case):
    u=Uc(UC_ARCH_X86,UC_MODE_32);u.mem_map(0x400000,0x300000)
    for section in module['sections']:
        if section['raw_size']:u.mem_write(0x400000+section['rva'],image[section['raw_offset']:section['raw_offset']+section['raw_size']])
    state=CONFIG if case!='null_state_fallback' else 0x6b77a0
    setup(u,state, B if case=='two_handles' else A if case=='null_state_fallback' else 0,case=='two_handles')
    if case=='null_state_fallback':put(u,0x6b77a0+0x43c,A)
    trace=[]
    def hook(m,address,_size,_):
        if address not in (V8,V28,UPDATE):return
        sp=m.reg_read(UC_X86_REG_ESP);arg=word(m,sp+4)
        if address==V8:trace.append('v8:a' if arg==A else 'v8:b' if arg==B else 'v8:main');cleanup=8
        elif address==V28:trace.append('v28:main' if arg==MAIN else 'v28:other');cleanup=8
        else:trace.append('update:state' if arg==state else 'update:other');cleanup=4
        m.reg_write(UC_X86_REG_EAX,0);m.reg_write(UC_X86_REG_ESP,sp+cleanup);m.reg_write(UC_X86_REG_EIP,word(m,sp))
    u.hook_add(UC_HOOK_CODE,hook)
    args=[0, A] if case=='null_state_fallback' else [state]
    for i,value in enumerate([EXIT,*args]):put(u,STACK+i*4,value)
    u.reg_write(UC_X86_REG_ESP,STACK)
    u.emu_start(0x558c80 if case=='null_state_fallback' else 0x557990,EXIT,count=20000)
    names={MAIN:'main',A:'a',B:'b'}
    return {'fields':[names.get(word(u,state+x),str(word(u,state+x))) for x in FIELDS],'calls':trace}

def parse(line):
    p=line.split();count=int(p[7]);return {'fields':[x for x in p[1:7]],'calls':p[8:8+count]}

def main():
    ap=argparse.ArgumentParser();ap.add_argument('--probe',type=Path,default=ROOT/'local/builds/v2/001-original-recovery/object-cleanup-088/bin/Release/object_cleanup_probe.exe');ap.add_argument('--report',type=Path,default=RUN/'verification.json');args=ap.parse_args()
    module=next(json.loads(x) for x in (ROOT/'research/binary-index/static/binaries.jsonl').read_text(encoding='utf8').splitlines() if json.loads(x)['file']=='Porsche.exe')
    image=(ROOT/'local/game'/module['path']).read_bytes()
    if hashlib.sha256(image).hexdigest()!=SHA:raise RuntimeError('original Porsche.exe SHA mismatch')
    run=subprocess.run([str(args.probe)],text=True,capture_output=True,check=True,timeout=10)
    actual={line.split()[0]:parse(line) for line in run.stdout.splitlines()}
    cases=['empty','two_handles','null_state_fallback'];outputs=[]
    for case in cases:
        expected=original(module,image,case)
        if actual.get(case)!=expected:raise RuntimeError(f'{case}: original={expected}, native={actual.get(case)}')
        outputs.append({'case':case,'output':expected})
    dependencies=['iterations/v2/001-original-recovery/source/include/porsche/object_cleanup.hpp','iterations/v2/001-original-recovery/source/recovered/Porsche.exe/object_cleanup.cpp','iterations/v2/001-original-recovery/source/recovered/object_cleanup_probe.cpp','iterations/v2/001-original-recovery/runs/088-object-cleanup/CMakeLists.txt','iterations/v2/001-original-recovery/runs/088-object-cleanup/README.md','scripts/research/verify-v2-object-cleanup.py']
    report={'schema':1,'sha256':SHA,'full_function_vas':['00557990', '00558c80'],'partial_function_vas':[],'original_sha256':SHA,'function_vas':['00557990','00558c80'],'body_bytes':{'00557990':100,'00558c80':45},'cases':outputs,'native_cpp_equal_original_x86':True,'abi':{'00557990':'cdecl(void*)','00558c80':'cdecl(void*,void*)','vtable_00557990_plus_28':'stdcall(void*)','vtable_00558c80_plus_8':'stdcall(void*)'},'boundaries':'005588a0 remains an explicit boundary. Its observed closure reads/writes config +43c/+440/+444, globals 006a3afc/006a3b00/006a3b04, and lock 006a57d8; calls GetTickCount, vtable +0x80 (two stdcall args), and lock leave. Vtable +0x28 and +0x8 effects are recorded only.','source_sha256':source_hashes(dependencies,compiled_sources=dependencies[:3]),'probe_sha256':hashlib.sha256(args.probe.read_bytes()).hexdigest(),'game_launch_verified':False}
    args.report.parent.mkdir(parents=True,exist_ok=True);args.report.write_text(json.dumps(report,indent=2)+'\n',encoding='utf8')
    print(json.dumps({'cases':len(outputs),'matched':True,'report':str(args.report)}))
if __name__=='__main__':main()
