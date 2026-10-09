"""Compare the original CRT exit dispatcher with the recovered C++ x86 build."""
import argparse
import hashlib
import json
from pathlib import Path
import struct
import subprocess
import sys

from v2_source_dependencies import source_hashes

ROOT=Path(__file__).resolve().parents[2]
RUN=ROOT/'iterations/v2/001-original-recovery/runs/053-crt-shutdown'
sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_EIP,UC_X86_REG_ESP

ARENA,ARENA_BYTES,STACK,EXIT=0x03600000,0x10000,0x0200f000,0x02200000
BASE,NEXT=0x006c1534,0x006c1530
MODE,STARTED,STATE=0x006afce0,0x006afce4,0x006afce8
CASES=[(0,0,1,0x123,0,-1),(0,0,1,77,4,2),(0,1,0x102,88,2,-1),
       (0,1,0,99,1,-1),(1,0,1,101,3,-1),(1,0,0,102,2,1),(0,0,1,103,0,-1),
       (0,0,1,104,4,-2)]

def original(case,module,binary,rows):
    initial_state,skip_callbacks,return_after,code,count,null_index=case
    uc=Uc(UC_ARCH_X86,UC_MODE_32);image=int(module['image_base'],16);uc.mem_map(image,0x300000)
    for section in module['sections']:
        uc.mem_write(image+section['rva'],binary[section['raw_offset']:section['raw_offset']+section['raw_size']])
    uc.mem_map(ARENA,ARENA_BYTES);uc.mem_write(ARENA,b'\xcc'*ARENA_BYTES)
    uc.mem_map(0x02000000,0x10000);uc.mem_map(EXIT,0x2000)
    def put(addr,*values):uc.mem_write(addr,struct.pack('<'+'I'*len(values),*(v&0xffffffff for v in values)))
    def word(addr):return struct.unpack('<I',uc.mem_read(addr,4))[0]
    put(MODE,0xabcd1200);put(STARTED,0x12345678);put(STATE,initial_state)
    base=ARENA+0x4000;put(BASE,base);put(NEXT,base);put(base,0)
    for i in range(count):
        callback=0 if i+1==null_index else EXIT+0x200+(i+1)*0x10
        put(base+i*4,callback)
    put(NEXT,base+count*4)
    calls=[];coverage=set();terminal=False
    funcs=[]
    for va in ('005a2490','005a2535','005a253e','005a2547'):
        row=rows.get(va)
        if row:funcs.extend((int(a,16),int(b,16)) for a,b in row['ranges'])
    endpoints={EXIT+0x100:('get_current_process',0),EXIT+0x110:('terminate_process',2),
        EXIT+0x120:('exit_process',1),0x5a4ba4:('lock',1),0x5a4c05:('unlock',1),
        0x5a36d6:('static_onexit',0),0x5ac147:('static_cexit',0)}
    put(0x5b2094,EXIT+0x100);put(0x5b216c,EXIT+0x110);put(0x5b21a8,EXIT+0x120)
    for i in range(1,count+1):endpoints[EXIT+0x200+i*0x10]=(f'callback_{i}',0)
    def hook(machine,address,_size,_user):
        nonlocal terminal
        if address==EXIT:machine.emu_stop();return
        if address in (0x5a2490,0x5a2535,0x5a253e,0x5a2547):coverage.add(f'{address:08x}')
        endpoint=endpoints.get(address)
        if endpoint is None:
            if not any(lo<=address<=hi for lo,hi in funcs):raise RuntimeError(f'unexpected original pc {address:08x}, calls={calls[-8:]}')
            return
        name,n=endpoint;sp=machine.reg_read(UC_X86_REG_ESP);ret,*args=struct.unpack('<'+'I'*(n+1),machine.mem_read(sp,4*(n+1)))
        if name=='get_current_process':calls.append(['get_current_process']);result=0xffffffff
        elif name=='terminate_process':calls.append(['terminate_process',args[0],args[1]]);result=0
        elif name=='exit_process':calls.append(['exit_process',args[0]]);terminal=True;machine.emu_stop();return
        elif name=='lock':calls.append(['lock',args[0]]);result=0
        elif name=='unlock':calls.append(['unlock',args[0]]);result=0
        elif name=='static_onexit':calls.append(['callback',0x005a36d6]);result=0
        elif name=='static_cexit':calls.append(['callback',0x005ac147]);result=0
        else:
            calls.append(['callback',address]);result=0
            if null_index==-2 and name=='callback_4':put(BASE,word(BASE)+8)
        if address in (0x5a36d6,0x5ac147,0x5a4ba4,0x5a4c05):coverage.add(f'{address:08x}')
        machine.reg_write(UC_X86_REG_EAX,result)
        stdcall=name in ('get_current_process','terminate_process','exit_process')
        machine.reg_write(UC_X86_REG_ESP,sp+4*(n+1) if stdcall else sp+4);machine.reg_write(UC_X86_REG_EIP,ret)
    uc.hook_add(UC_HOOK_CODE,hook)
    put(STACK,EXIT,code,skip_callbacks,return_after);uc.reg_write(UC_X86_REG_ESP,STACK)
    uc.emu_start(0x5a2490,EXIT+1,count=100000)
    if not terminal and (uc.reg_read(UC_X86_REG_EIP)!=EXIT or uc.reg_read(UC_X86_REG_ESP)!=STACK+4):raise RuntimeError('shutdown return ABI mismatch')
    out={'terminal':terminal,'base':word(BASE),'next':word(NEXT),'exit_state':word(STATE),
        'started':word(STARTED),'mode':word(MODE),'arena':bytes(uc.mem_read(ARENA,ARENA_BYTES)).hex(),'calls':calls}
    return out,coverage

def main():
    parser=argparse.ArgumentParser()
    parser.add_argument("--probe",type=Path,default=ROOT/"local/builds/v2/001-original-recovery/bin/Release/crt_shutdown_probe.exe")
    parser.add_argument("--report-dir",type=Path,default=RUN)
    args=parser.parse_args()
    args.report_dir.mkdir(parents=True,exist_ok=True)
    module=next(x for x in map(json.loads,(ROOT/'research/binary-index/static/binaries.jsonl').read_text().splitlines()) if x['file']=='Porsche.exe')
    binary=(ROOT/'local/game'/module['path']).read_bytes();sha='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
    if hashlib.sha256(binary).hexdigest()!=sha:raise RuntimeError('original SHA mismatch')
    rows={x['entry_va'].lower():x for x in map(json.loads,(ROOT/'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/functions.jsonl').read_text().splitlines())}
    probe=args.probe
    process=subprocess.run([str(probe)],input=''.join(' '.join(map(str,c))+'\n' for c in CASES),text=True,capture_output=True,check=True,timeout=30)
    actual=[json.loads(line) for line in process.stdout.splitlines()]
    if len(actual)!=len(CASES):raise RuntimeError('native output count differs')
    coverage=set();fixtures=[]
    for i,(case,got) in enumerate(zip(CASES,actual)):
        want,hit=original(case,module,binary,rows);coverage|=hit
        if got!=want:
            arena_diff=next((j for j,(a,b) in enumerate(zip(bytes.fromhex(want['arena']),bytes.fromhex(got['arena']))) if a!=b),None)
            keys=[k for k in want if want[k]!=got.get(k)]
            raise AssertionError(f'case {i} differs keys={keys}, expected calls={want["calls"]}, actual calls={got.get("calls")}, arena diff={arena_diff}')
        fixtures.append({'input':case,'output_sha256':hashlib.sha256(json.dumps(want,sort_keys=True).encode()).hexdigest()})
    full={'005a2490','005a2535','005a253e','005a2547'}
    if not full<=coverage:raise RuntimeError(f'coverage missing {sorted(full-coverage)}')
    paths=['iterations/v2/001-original-recovery/source/include/porsche/exit_shutdown.hpp',
      'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/exit_shutdown.cpp',
      'iterations/v2/001-original-recovery/source/recovered/exit_shutdown_probe.cpp',
      'iterations/v2/001-original-recovery/runs/053-crt-shutdown/CMakeLists.txt',
      'scripts/research/verify-v2-crt-shutdown.py']
    report={'schema':1,'module':'Porsche.exe','sha256':sha,'range':'005a2490..005a2534 plus helper 005a2547..005a2560',
      'function_vas':sorted(coverage),'full_function_vas':sorted(full),'partial_function_vas':sorted(coverage-full),
      'cases':len(CASES),'native_cpp_equal_original_x86':True,'binary_matched':False,'game_launch_verified':False,
      'comparison':'Full callback-list arena, CRT exit globals, lock/API/callback order across reverse registry traversal, null slots, skip flag, return-after flag, existing process-exit state, and terminal ExitProcess.',
      'boundaries':{'win32':'GetCurrentProcess, TerminateProcess (fixture returns failure to let the observed fallthrough run), and terminal ExitProcess are deterministic boundaries.',
        'callbacks':'Dynamic callbacks are test functions. Static function pointers in the original arrays at 005cb79c..005cb7a4 and 005cb7a8..005cb7b0 are recovered as call sites; their target bodies 005a36d6 and 005ac147 remain recording boundaries.',
        'lock':'Existing exact wrappers 005a2535/005a253e use lock ID 0xD; underlying lock API effects are fixture boundaries.'},
      'source_sha256':{p:hashlib.sha256((ROOT/p).read_bytes().replace(b'\r\n',b'\n')).hexdigest() for p in paths},
      'probe_sha256':hashlib.sha256(probe.read_bytes()).hexdigest(),'fixtures':fixtures}
    report['source_sha256']=source_hashes(report['source_sha256'].keys(),compiled_sources=['iterations/v2/001-original-recovery/source/recovered/Porsche.exe/exit_shutdown.cpp', 'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/exit_registry.cpp', 'iterations/v2/001-original-recovery/source/recovered/exit_shutdown_probe.cpp'])
    (args.report_dir/'verification.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf8',newline='\n')
    print(json.dumps({'functions':sorted(coverage),'cases':len(CASES),'native_cpp_equal_original_x86':True,'report':str(args.report_dir/'verification.json')}))
if __name__=='__main__':main()
