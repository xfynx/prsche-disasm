"""Compare recovered 005728b0 mouse consumer with the original x86 body."""
import argparse
import hashlib
import json
import struct
import subprocess
import sys
from pathlib import Path

from v2_source_dependencies import source_hashes

ROOT=Path(__file__).resolve().parents[2]
ITER=ROOT/'iterations/v2/001-original-recovery'
RUN=ITER/'runs/089-mouse-input'
SHA='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ESP,UC_X86_REG_EIP

STACK,EXIT=0x3101000,0x3200000
ENTER_IAT,LEAVE_IAT=0x5b2078,0x5b206c
ENTER_FN,LEAVE_FN,CURSOR_FN,CALLBACK_FN=0x3300000,0x3300010,0x53a970,0x3300030

def put(u,address,value):u.mem_write(address,struct.pack('<I',value&0xffffffff))
def get(u,address):return struct.unpack('<I',u.mem_read(address,4))[0]

def cases():
    return [
      # Gate and shared lock checks return before touching any state.
      (0,0x2000,0x3300030,40,50,3,1,0,0,100,100,40,50),
      (1,0,0x3300030,40,50,3,1,0,0,100,100,40,50),
      # In-bounds updates cached position and button state under the lock.
      (1,0x2000,0,40,50,3,1,0,0,100,100,1,2),
      # Clamp both signed axes, emit cursor helper before cache writes, callback after unlock.
      (1,0x2000,0x3300030,0xfffffff0,250,5,1,0xfffffff6,10,100,200,40,50),
      # Same clamped/canonical point: no cursor helper and no cache writes.
      (1,0x2000,0x3300030,0xfffffff0,250,7,0,0xfffffff6,10,100,200,0xfffffff6,200),
      # Callback does not depend on x and can still run when x is zero.
      (1,0x2000,0x3300030,0,25,2,1,0,0,100,100,4,5),
      # Nonzero x does not trigger a callback when transition is zero.
      (1,0x2000,0x3300030,25,30,6,0,0,0,100,100,25,30),
      # Original initialized callback target is a no-op.
      (1,0x2000,0x5367b0,25,30,1,0,0,0,100,100,25,30),
      # Equal boundaries exercise signed JG/JGE branch edges.
      (1,0x2000,0x3300030,20,30,0,0,20,30,20,30,0,0),
      # The original sequence also defines behavior for inverted bounds.
      (1,0x2000,0x3300030,5,9,0x80000000,1,20,20,10,10,5,9),
    ]

def original(module,data,c):
    gate,lock,callback,x,y,mask,transition,low_x,low_y,high_x,high_y,last_x,last_y=c
    u=Uc(UC_ARCH_X86,UC_MODE_32)
    u.mem_map(0x400000,0x300000)
    for section in module['sections']:
        if section['raw_size']:
            u.mem_write(0x400000+section['rva'],
                        data[section['raw_offset']:section['raw_offset']+section['raw_size']])
    u.mem_map(0x3100000,0x10000);u.mem_map(EXIT,0x1000);u.mem_map(0x3300000,0x1000)
    u.mem_write(EXIT,b'\xc3'*0x1000);u.mem_write(0x3300000,b'\xc3'*0x1000)
    put(u,ENTER_IAT,ENTER_FN);put(u,LEAVE_IAT,LEAVE_FN)
    put(u,0x5deaac,gate);put(u,0x69e59c,lock);put(u,0x5debec,callback)
    put(u,0x6a643c,low_x);put(u,0x6a6438,low_y)
    put(u,0x6a6430,high_x);put(u,0x6a6434,high_y)
    put(u,0x6a6448,last_x);put(u,0x6a6444,last_y);put(u,0x6a6440,0xdeadbeef)
    put(u,0x6b77a0+0x458,0x87654321)
    events=[]
    targets=(ENTER_FN,LEAVE_FN,CURSOR_FN,CALLBACK_FN)
    def hook(mu,address,_size,_):
        if address not in targets:return
        sp=mu.reg_read(UC_X86_REG_ESP);ret=get(mu,sp)
        if address in (ENTER_FN,LEAVE_FN):
            events.append([1 if address==ENTER_FN else 3,get(mu,sp+4),0,0])
            # Enter/LeaveCriticalSection are WINAPI stdcall edges.
            cleanup=4;eax=0
        elif address==CURSOR_FN:
            events.append([2,get(mu,sp+4),get(mu,sp+8),get(mu,sp+12)])
            # 0053a970 is an explicit callee boundary in this packet.
            cleanup=0;eax=0
        else:
            events.append([4,callback,get(mu,sp+4),0])
            cleanup=0;eax=0
        mu.reg_write(UC_X86_REG_EAX,eax)
        mu.reg_write(UC_X86_REG_ESP,sp+4+cleanup)
        mu.reg_write(UC_X86_REG_EIP,ret)
    u.hook_add(UC_HOOK_CODE,hook)
    put(u,STACK,EXIT)
    for i,value in enumerate((x,y,mask,transition)):put(u,STACK+4+i*4,value)
    u.reg_write(UC_X86_REG_ESP,STACK)
    try:u.emu_start(0x5728b0,EXIT,count=10000)
    except Exception as exc:
        raise RuntimeError(f'original x86 case={c} EIP={u.reg_read(UC_X86_REG_EIP):08x} events={events}') from exc
    return {'events':events,'state':[get(u,0x6a6440),get(u,0x6a6448),get(u,0x6a6444)],
            'stack_delta':u.reg_read(UC_X86_REG_ESP)-STACK}

def main():
    parser=argparse.ArgumentParser()
    parser.add_argument('--probe',type=Path,default=ROOT/'local/builds/v2/mouse-input-089/bin/Release/mouse_input_probe.exe')
    parser.add_argument('--report',type=Path,default=RUN/'verification.json')
    parser.add_argument('--report-dir',type=Path)
    args=parser.parse_args()
    report_path=args.report_dir/'verification.json' if args.report_dir else args.report
    module=next(json.loads(line) for line in (ROOT/'research/binary-index/static/binaries.jsonl').read_text(encoding='utf8').splitlines() if json.loads(line)['file']=='Porsche.exe')
    binary=(ROOT/'local/game'/module['path']).read_bytes()
    if hashlib.sha256(binary).hexdigest()!=SHA:raise RuntimeError('immutable Porsche.exe SHA mismatch')
    inputs=cases()
    feed=''.join(' '.join(map(str,c))+'\n' for c in inputs)
    proc=subprocess.run([str(args.probe)],input=feed,text=True,capture_output=True,check=True)
    lines=proc.stdout.splitlines()
    if len(lines)!=len(inputs):raise RuntimeError(f'probe line count {len(lines)} != {len(inputs)}: {proc.stderr}')
    fixtures=[]
    for case,line in zip(inputs,lines):
        native=json.loads(line);expected=original(module,binary,case)
        if expected['stack_delta']!=4:raise RuntimeError(f'cdecl stack imbalance: {case} -> {expected}')
        if native['events']!=expected['events'] or native['state']!=expected['state']:
            raise RuntimeError(f'case={case}\nx86={expected}\nnative={native}')
        fixtures.append({'input':list(case),'output':{'events':native['events'],
                          'state':native['state'],'stack_delta':expected['stack_delta']}})
    rel=lambda path:path.resolve().relative_to(ROOT).as_posix()
    deps=[ITER/'source/include/porsche/mouse_input.hpp',
          ITER/'source/include/porsche/heap.hpp',
          ITER/'source/include/porsche/render_driver_calls.hpp',
          ITER/'source/include/porsche/render_event_route.hpp',
          ITER/'source/include/porsche/window_create.hpp',
          ITER/'source/include/porsche/window_state.hpp',
          ITER/'source/recovered/Porsche.exe/mouse_input.cpp',
          ITER/'source/recovered/mouse_input_probe.cpp',RUN/'CMakeLists.txt',RUN/'README.md',
          ROOT/'research/binary-index/README.md',
          ROOT/'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/functions.jsonl',
          ROOT/'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/calls.jsonl',
          ROOT/'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/references.jsonl',
          ROOT/'research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm',
          ROOT/'research/v2/binaries/Porsche.exe-ddd748fdbe6d/decompiled.c',Path(__file__).resolve()]
    report={'schema':1,'binary':'Porsche.exe','sha256':SHA,'entry_va':'005728b0',
            'coverage':'full 005728b0..0057298a; callees 0053a970 and 005367b0 are typed boundaries/recovered no-op',
            'full_function_vas':['005728b0'],'partial_function_vas':[],
            'cases':len(inputs),'native_cpp_equal_original_x86':True,
            'binary_matched':False,'game_launch_verified':False,
            'boundaries':'The critical-section enter/leave calls remain the recovered heap lock API. The 0053a970 cursor helper is a typed boundary recorded at its exact original call ABI; its USER32 subcalls are outside this consumer proof. Callback targets other than original no-op 005367b0 are a typed dynamic boundary at 005debec. No native HWND routing is claimed by this isolated consumer proof.',
            'abi':{'convention':'cdecl','arguments':['x','y','button_mask','transition'],
                   'fourth_argument_read':True,'callback_gate':'transition != 0 and callback pointer != 0',
                   'callback_argument':'button_mask'},
            'source_sha256':{rel(path):hashlib.sha256(path.read_bytes().replace(b'\r\n',b'\n')).hexdigest() for path in deps},
            'probe_sha256':hashlib.sha256(args.probe.read_bytes()).hexdigest(),'fixtures':fixtures}
    report['source_sha256']=source_hashes(report['source_sha256'].keys(),compiled_sources=[
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/mouse_input.cpp',
        'iterations/v2/001-original-recovery/source/recovered/mouse_input_probe.cpp'])
    report_path.parent.mkdir(parents=True,exist_ok=True)
    report_path.write_text(json.dumps(report,indent=2)+'\n',encoding='utf8')
    print(json.dumps({'cases':len(inputs),'entry_va':'005728b0',
                      'native_cpp_equal_original_x86':True,'report':rel(report_path)}))

if __name__=='__main__':main()
