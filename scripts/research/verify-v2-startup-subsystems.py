"""Compare the recovered keyboard/joystick startup slice against Porsche.exe x86."""
import argparse
import hashlib
import json
from pathlib import Path
import struct
import subprocess
import sys

ROOT=Path(__file__).resolve().parents[2]
RUN=ROOT/'iterations/v2/001-original-recovery/runs/043-startup-subsystems'
sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_EIP,UC_X86_REG_ESP

STACK=0x0200f000;EXIT=0x02200000
KEYBOARD_LAYOUT=0x0069e5a0;JOY_INITIALIZED=0x005deac4;JOY_COUNT=0x006a5bf4
FUNCTIONS=(0x564e70,0x564ab0,0x564850)

def cases():
    return [(7,0x0d01,0,0),(7,0x0d04,1,0),(7,0x0d00,3,0x12345678),
            (4,0,3,0xabcdef01),(7,0x0d02,4,0),(7,0x0d05,-1,0)]

def original(case,module,data,functions):
    type0,type1,devices,initial=case
    uc=Uc(UC_ARCH_X86,UC_MODE_32);base=int(module['image_base'],16);uc.mem_map(base,0x300000)
    for section in module['sections']:
        uc.mem_write(base+section['rva'],data[section['raw_offset']:section['raw_offset']+section['raw_size']])
    uc.mem_map(0x02000000,0x10000);uc.mem_map(EXIT,0x1000)
    def put(p,v):uc.mem_write(p,struct.pack('<I',v&0xffffffff))
    def word(p):return struct.unpack('<I',uc.mem_read(p,4))[0]
    def words(p,n):return struct.unpack('<'+'I'*n,uc.mem_read(p,n*4))
    def signed(v):return v if v<0x80000000 else v-0x100000000
    put(KEYBOARD_LAYOUT,initial);put(JOY_INITIALIZED,0);put(JOY_COUNT,0)
    ranges=[]
    for va in FUNCTIONS:
        row=functions.get(f'{va:08x}')
        if row:ranges.extend((int(a,16),int(b,16)) for a,b in row['ranges'])
    calls=[];coverage=set();trace=[]
    def hook(m,address,_size,_user):
        trace.append(address)
        if address==EXIT:m.emu_stop();return
        if address in FUNCTIONS:coverage.add(f'{address:08x}')
        if address in (0x564e79,0x564e82):
            sp=m.reg_read(UC_X86_REG_ESP);kind=word(sp)
            value=type0 if kind==0 else type1
            calls.append(['keyboard',kind,value])
            m.reg_write(UC_X86_REG_EAX,value);m.reg_write(UC_X86_REG_ESP,sp+4)
            m.reg_write(UC_X86_REG_EIP,address+2);return
        if address==0x564abe:
            calls.append(['joy_count',devices&0xffffffff])
            m.reg_write(UC_X86_REG_EAX,devices&0xffffffff);m.reg_write(UC_X86_REG_EIP,address+6);return
        if address==0x564ae1:
            sp=m.reg_read(UC_X86_REG_ESP);joy_id,caps,size=words(sp,3)
            calls.append(['joy_caps',joy_id,size]);m.mem_write(caps,b'\0'*size)
            m.reg_write(UC_X86_REG_EAX,0);m.reg_write(UC_X86_REG_ESP,sp+12)
            m.reg_write(UC_X86_REG_EIP,address+2);return
        if not any(a<=address<=b for a,b in ranges):
            raise RuntimeError(f'unexpected original instruction {address:08x}; trace={trace[-20:]}')
    uc.hook_add(UC_HOOK_CODE,hook)
    def execute(va,args=()):
        uc.mem_write(STACK,struct.pack('<'+'I'*(len(args)+1),EXIT,*[v&0xffffffff for v in args]))
        uc.reg_write(UC_X86_REG_ESP,STACK)
        try:uc.emu_start(va,EXIT+1,count=100000)
        except Exception as error:
            raise RuntimeError(f'x86 failed at {uc.reg_read(UC_X86_REG_EIP):08x}, {case}, trace={trace[-20:]}') from error
        if uc.reg_read(UC_X86_REG_EIP)!=EXIT or uc.reg_read(UC_X86_REG_ESP)!=STACK+4:
            raise RuntimeError(f'x86 stack/return mismatch at {va:08x}, {case}')
        return uc.reg_read(UC_X86_REG_EAX)
    key_result=execute(0x564e70)
    execute(0x564ab0)
    execute(0x564850)
    return {'key_result':key_result,'keyboard_value':word(KEYBOARD_LAYOUT),
            'joystick_initialized':word(JOY_INITIALIZED)&0xff,'joystick_count':signed(word(JOY_COUNT)),
            'calls':calls},coverage

def main():
    parser=argparse.ArgumentParser()
    parser.add_argument("--probe",type=Path,default=ROOT/"local/builds/v2/001-original-recovery/bin/Release/startup_subsystems_probe.exe")
    parser.add_argument("--report-dir",type=Path,default=RUN)
    args=parser.parse_args()
    report_dir=args.report_dir
    report_dir.mkdir(parents=True,exist_ok=True)
    module=next(x for x in map(json.loads,(ROOT/'research/binary-index/static/binaries.jsonl').read_text().splitlines()) if x['file']=='Porsche.exe')
    data=(ROOT/'local/game'/module['path']).read_bytes()
    sha='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
    if hashlib.sha256(data).hexdigest()!=sha:raise RuntimeError('Original binary SHA mismatch')
    functions={r['entry_va']:r for r in map(json.loads,(ROOT/'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/functions.jsonl').read_text().splitlines())}
    probe=args.probe
    inputs=cases()
    proc=subprocess.run([str(probe)],input=''.join(f'{a} {b} {c} {d}\n' for a,b,c,d in inputs),
        text=True,capture_output=True,check=True,timeout=60)
    actual=[json.loads(line) for line in proc.stdout.splitlines()]
    if len(actual)!=len(inputs):raise RuntimeError('Native output count differs')
    coverage=set();fixtures=[]
    for i,(case,got) in enumerate(zip(inputs,actual)):
        want,hit=original(case,module,data,functions);coverage|=hit
        if got!=want:raise AssertionError(f'case {i} {case}: x86={want}, native={got}')
        fixtures.append({'input':case,'output_sha256':hashlib.sha256(json.dumps(want,sort_keys=True).encode()).hexdigest()})
    paths=['iterations/v2/001-original-recovery/source/include/porsche/startup_subsystems.hpp',
           'iterations/v2/001-original-recovery/source/include/porsche/window_runtime.hpp',
           'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/startup_subsystems.cpp',
           'iterations/v2/001-original-recovery/source/recovered/startup_subsystems_probe.cpp',
           'iterations/v2/001-original-recovery/runs/043-startup-subsystems/CMakeLists.txt',
           'scripts/research/verify-v2-startup-subsystems.py']
    result={'schema':1,'module':'Porsche.exe','sha256':sha,'function_vas':sorted(coverage),
        'cases':len(inputs),'native_cpp_equal_original_x86':True,'binary_matched':False,'game_launch_verified':False,
        'comparison':'Keyboard detection result and global 0069e5a0, joystick init/count globals, and ordered API calls/arguments.',
        'boundaries':{'USER32':'GetKeyboardType(0/1)','WINMM':'joyGetNumDevs and joyGetDevCapsA; caps output scratch is zero-filled by fixture'},
        'source_sha256':{p:hashlib.sha256((ROOT/p).read_bytes().replace(b'\r\n',b'\n')).hexdigest() for p in paths},
        'probe_sha256':hashlib.sha256(probe.read_bytes()).hexdigest(),'fixtures':fixtures}
    report_dir.mkdir(parents=True,exist_ok=True);(report_dir/'verification.json').write_text(json.dumps(result,indent=2)+'\n',newline='\n')
    print(json.dumps({'cases':len(inputs),'functions':sorted(coverage),'native_equal_original_x86':True}))

if __name__=='__main__':main()
