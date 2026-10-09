import argparse
"""Differentially exercise app_main_004b6a50 with x86 callee boundaries."""
import hashlib, json, struct, subprocess, sys
from pathlib import Path

ROOT=Path(__file__).resolve().parents[2]
RUN=ROOT/'iterations/v2/001-original-recovery/runs/058-application-main'
sys.path.insert(0,str(ROOT/'scripts/research'))
from v2_source_dependencies import source_hashes
sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_EIP,UC_X86_REG_ESP

IMAGE,IMAGE_BYTES=0x400000,0x300000
ARENA,ARENA_BYTES,STACK,EXIT=0x03600000,0x10000,0x0200f000,0x02200000
STREAM,NETWORK,SWAP=ARENA+0x1000,ARENA+0x2000,ARENA+0x3000
SHA='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
CASES=[(0,0,0,0,0,1,0,0,0),(1,0,0,1,0,1,0,0,0),
       (0,0,1,0,0,1,1,1,0),(0,0,1,0,0,1,2,1,0),
       (0,1,0,0,0,1,0,0,3),(0,0,1,0,3,1,0,1,0),
       (0,1,0,0,3,1,0,1,0),(0,0,0,0,3,1,0,1,0),
       (0,0,0,1,0,1,0,0,0,1),(0,0,0,0,0,0,0,0,0),
       (0,1,0,0,3,1,0,2,0,0),(0,0,0,0,3,1,0,2,0,0)]
CASES=[tuple(c)+(0,) if len(c)==9 else tuple(c) for c in CASES]
CASES.append((0,1,1,0,3,1,0,1,0,0))
CASES=[tuple(c)+(0,) for c in CASES]
CASES.append((0,0,0,0,0,1,0,1,0,0,1))

CASES.append((0,0,1,0,0,1,3,1,0,0,0))

CALLS={
 0x59ed40:('0059ed40',1,0),0x59ed90:('0059ed90',1,0),
 0x4a5c30:('004a5c30',0,0),0x4a5410:('004a5410',0,0),0x5a246e:('005a246e',1,0),
 0x59d650:('0059d650',0,0),0x53c290:('0053c290',3,0),
 0x4b6660:('004b6660',2,STREAM),0x531f90:('00531f90',1,1),
 0x4a6840:('004a6840',2,0),0x5a177b:('005a177b',1,0),
 0x467470:('00467470',0,0),0x0048dcb0:('0048dcb0',2,0),
 0x0048e1a0:('0048e1a0',3,0),0x4dd600:('004dd600',0,0),
 0x4d1a90:('004d1a90',0,0),0x4d3420:('004d3420',3,None),
 0x4d1ba0:('004d1ba0',0,0),0x467fc0:('00467fc0',4,0,16),
 0x4b4da0:('004b4da0',1,0),0x4a4a70:('004a4a70',1,0),
 0x0048da60:('0048da60',2,0),0x4b67b0:('004b67b0',0,0),
 0x4acb80:('004acb80',0,0),0x4a88a0:('004a88a0',0,0),
 0x471b60:('00471b60',0,0),0x414eb0:('00414eb0',0,0),
 0x4640b0:('004640b0',0,0),0x413ea0:('00413ea0',0,0),
 0x4a6e30:('004a6e30',0,0),0x0048cdf0:('0048cdf0',0,0),
 0x425780:('00425780',0,0),0x5366e0:('005366e0',1,0),
 0x4152e0:('004152e0',0,0),0x412030:('00412030',0,0),
 0x4b68f0:('004b68f0',0,0),0x0048dad0:('0048dad0',0,0),
 0x0048e6f0:('0048e6f0',0,0),0x4a6960:('004a6960',0,0),
 0x563d30:('00563d30',0,0),0x4a54b0:('004a54b0',0,0),
 0x467740:('00467740',0,0),0x4a54e0:('004a54e0',0,0),
}
CREATE_IAT=EXIT+0x100; MESSAGE_IAT=EXIT+0x110

def original(case,module,binary):
    setup,tick,network_ready,enabled,mode,alloc,wait_mode,existing,post_mode,setup_repeat,config_name=case
    uc=Uc(UC_ARCH_X86,UC_MODE_32);uc.mem_map(IMAGE,IMAGE_BYTES)
    for sec in module['sections']:
        if sec['raw_size']:
            uc.mem_write(IMAGE+sec['rva'],binary[sec['raw_offset']:sec['raw_offset']+sec['raw_size']])
    uc.mem_map(ARENA,ARENA_BYTES);uc.mem_write(ARENA,b'\0'*ARENA_BYTES)
    uc.mem_map(0x02000000,0x10000);uc.mem_map(EXIT,0x2000)
    def put(a,*v):uc.mem_write(a,struct.pack('<'+'I'*len(v),*(x&0xffffffff for x in v)))
    def word(a):return struct.unpack('<I',uc.mem_read(a,4))[0]
    def byte(a):return uc.mem_read(a,1)[0]
    put(0x0065b298,enabled);put(0x006573e8,0);put(0x00657424,0);put(0x00657428,0);put(0x0065743c,0)
    put(0x006577d8,17);put(0x006577dc,19);put(0x00606a88,0);put(0x00606874,0);put(0x005e99f4,0)
    put(0x00657a60,0x100 if wait_mode==3 else int(wait_mode==1));put(0x00657a64,int(wait_mode==2));put(0x00657e34,0)
    uc.mem_write(0x00657a84,(b'LobbyX\0' if config_name else b'')+b'\0'*(0x100-(7 if config_name else 0)));put(0x00628130,0);put(0x00628c70,NETWORK if existing else 0)
    if existing:
        put(NETWORK+8,1);uc.mem_write(NETWORK+0xbe,bytes([1 if existing>1 else 0]));put(NETWORK+0xdc,0 if existing>1 else 0xffffffff)
    put(0x0065b360,0);uc.mem_write(STREAM,b'\0'*16);put(0x005b2084,CREATE_IAT);put(0x005b2270,MESSAGE_IAT)
    calls=[];setup_count=0
    names={CREATE_IAT:('CreateDirectoryA',2,0),MESSAGE_IAT:('MessageBoxA',4,0)}
    names.update({addr:(row[0],row[1],row[2]) for addr,row in CALLS.items()})
    def hook(machine,addr,size,_):
        nonlocal setup_count
        if 0x004b6a50<=addr<=0x004b6fe5 or 0x004b4b80<=addr<=0x004b4d55:return
        if addr==EXIT:machine.emu_stop();return
        row=names.get(addr)
        if row is None:
            raise RuntimeError(f'Unexpected original PC {addr:08x}; calls={calls[-8:]}')
        name,nargs,result=row;sp=machine.reg_read(UC_X86_REG_ESP)
        ret=struct.unpack('<I',machine.mem_read(sp,4))[0]
        calls.append(name)
        if addr==0x59ed40: result=SWAP if alloc else 0
        elif addr==0x4d3420:
            result=setup if setup_count==0 else setup_repeat;setup_count+=1
        elif addr==0x4b67b0:put(0x00606a88,tick)
        elif addr==0x004152e0 and post_mode:put(0x006573e8,post_mode)
        elif addr==0x0048dcb0:
            put(0x00628c70,NETWORK);put(NETWORK+8,1);machine.mem_write(NETWORK+0xbe,bytes([network_ready]));put(NETWORK+0xdc,0 if network_ready else 0xffffffff)
        elif addr==0x0048e1a0:
            machine.mem_write(0x00657a64,b'\0');put(0x00628c70,NETWORK);put(NETWORK+8,1);machine.mem_write(NETWORK+0xbe,bytes([network_ready]));put(NETWORK+0xdc,0 if network_ready else 0xffffffff)
        # the recovered 4b6660 is represented by an empty deterministic stream
        if addr==0x4b6660:
            put(STREAM,48 if mode else 0,mode if mode else 0,0)
        if addr==0x531f90:result=1
        machine.reg_write(UC_X86_REG_EAX,0 if result is None else result)
        cleanup=4
        if addr==0x0048dcb0:cleanup=12
        if addr==0x0048e1a0:cleanup=16
        if addr==0x467fc0:cleanup=20
        if addr==0x4d3420:cleanup=16
        if addr==0x5a246e:cleanup=8
        if addr==CREATE_IAT:cleanup=12
        if addr==MESSAGE_IAT:cleanup=20
        machine.reg_write(UC_X86_REG_ESP,sp+cleanup);machine.reg_write(UC_X86_REG_EIP,ret)
    uc.hook_add(UC_HOOK_CODE,hook)
    put(STACK,EXIT,0,0);uc.reg_write(UC_X86_REG_ESP,STACK)
    try:uc.emu_start(0x004b6a50,EXIT+1,count=100000)
    except Exception as exc:raise RuntimeError(f'x86 run failed pc={uc.reg_read(UC_X86_REG_EIP):08x} sp={uc.reg_read(UC_X86_REG_ESP):08x} calls={calls[-16:]}') from exc
    if uc.reg_read(UC_X86_REG_EIP)!=EXIT:raise RuntimeError(f'main did not return to sentinel pc={uc.reg_read(UC_X86_REG_EIP):08x} sp={uc.reg_read(UC_X86_REG_ESP):08x} wait={word(0x00657a60)} net={word(0x00628c70):08x} calls={calls[-10:]}')
    net=word(0x00628c70)
    network_name=bytes(uc.mem_read(net+0x59,32)).split(b'\0',1)[0].decode('ascii') if net else ''
    out={'ret':uc.reg_read(UC_X86_REG_EAX),'calls':calls,
       'globals':[word(0x006573e8),word(0x00657424),word(0x00657428),word(0x0065743c),word(0x006577d8),word(0x006577dc),byte(0x00657e34),word(0x00657a60),byte(0x00657a64),word(0x00606a88),word(0x00606874),word(0x005e99f4)],
       'network':[1 if net else 0,word(net+8) if net else 0,byte(net+0xbc) if net else 0,byte(net+0xbe) if net else 0,byte(net+0xbf) if net else 0,byte(net+0xc4) if net else 0,byte(net+0xc5) if net else 0,struct.unpack('<i',uc.mem_read(net+0xdc,4))[0] if net else 0],
       'network_name':network_name}
    return out

def main():
    parser=argparse.ArgumentParser()
    parser.add_argument("--probe",type=Path,default=ROOT/"local/builds/v2/001-original-recovery/application-main-058/bin/Release/application_main_probe.exe")
    parser.add_argument("--report-dir",type=Path,default=RUN)
    args=parser.parse_args()
    args.report_dir.mkdir(parents=True,exist_ok=True)
    module=next(x for x in map(json.loads,(ROOT/'research/binary-index/static/binaries.jsonl').read_text().splitlines()) if x['file']=='Porsche.exe')
    binary=(ROOT/'local/game'/module['path']).read_bytes()
    if hashlib.sha256(binary).hexdigest()!=SHA:raise RuntimeError('original SHA mismatch')
    probe=args.probe
    inp=''.join(' '.join(map(str,c))+'\n' for c in CASES)
    got=[json.loads(x) for x in subprocess.run([str(probe)],input=inp,text=True,capture_output=True,check=True,timeout=30).stdout.splitlines()]
    if len(got)!=len(CASES):raise RuntimeError('probe case count mismatch')
    outputs=[]
    for i,(case,native) in enumerate(zip(CASES,got)):
        expected=original(case,module,binary)
        if native!=expected:
            keys=[k for k in expected if native.get(k)!=expected[k]]
            raise AssertionError(f'case {i} mismatch {keys}; x86 globals={expected.get("globals")} C++ globals={native.get("globals")}; x86 calls={expected["calls"]}; C++ calls={native.get("calls")}')
        outputs.append({'input':case,'sha256':hashlib.sha256(json.dumps(expected,sort_keys=True).encode()).hexdigest()})
    full=['004b6a50']
    paths=['iterations/v2/001-original-recovery/source/include/porsche/application_main.hpp',
      'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/application_main.cpp',
      'iterations/v2/001-original-recovery/source/recovered/application_main_probe.cpp',
      'iterations/v2/001-original-recovery/runs/058-application-main/CMakeLists.txt',
      'scripts/research/verify-v2-application-main.py']
    report={'schema':1,'module':'Porsche.exe','sha256':SHA,'range':'004b6a50..004b6fe5',
      'function_vas':['004b6a50'],'full_function_vas':full,'partial_function_vas':[],
      'cases':len(CASES),'native_cpp_equal_original_x86':True,'game_launch_verified':False,
      'comparison':'Return value, ordered boundary calls, selected startup/FE globals, and network fields/string across 15 controlled x86/native cases covering allocation success/failure, setup exit/re-entry, both startup waits, FE modes, simulation tick, configuration-name copy, and network continuation/action branches.',
      'boundaries':{'arena_fill':'0053c290 is recorded only; the 0x3e24-byte FE arena is not present as a unified host allocation, so no native memset is performed.',
        'callees':'Unknown game/network/UI consumers are intercepted as typed fixture boundaries on both sides. Tests drive return values and network state; their internal behavior is not claimed.',
        'wrappers':'The production source calls accepted page, startup, FE, resource, and render wrappers directly. This isolated probe substitutes those signatures to compare the main caller only.'},
      'source_sha256':source_hashes(paths,compiled_sources=[
          'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/application_main.cpp',
          'iterations/v2/001-original-recovery/source/recovered/application_main_probe.cpp']),
      'probe_sha256':hashlib.sha256(probe.read_bytes()).hexdigest(),'fixtures':outputs}
    (args.report_dir/'verification.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf8',newline='\n')
    print(json.dumps({'functions':full,'cases':len(CASES),'native_cpp_equal_original_x86':True,'report':str(args.report_dir/'verification.json')}))
if __name__=='__main__':main()
