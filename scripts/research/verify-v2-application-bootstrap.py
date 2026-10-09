"""Compare the combined recovered application heap and live allocation path to x86."""
import argparse
import hashlib
import json
from pathlib import Path
import struct
import subprocess
import sys

ROOT=Path(__file__).resolve().parents[2]
RUN=ROOT/'iterations/v2/001-original-recovery/runs/040-application-bootstrap'
sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ESI,UC_X86_REG_ESP,UC_X86_REG_EIP

ARENA=0x03600000; ARENA_BYTES=0x10000; STACK=0x0200f000; EXIT=0x02200000
PAGE=0x006af3f8; PRIMARY=0x006af3b4; HEAPS=0x006b4f20
DEFAULT=0x005deb98; OBJECT_HEAP=0x006af3fc; ACTIVE_TABLE=0x005e4fe8
FUNCTIONS=[0x531c60,0x531ca0,0x531f70,0x531f90,0x5320b0,0x5323e0,
           0x556620,0x556650,0x569640,0x5697f0,0x56e2c0,0x5b0000,
           0x59ed40,0x59ef90,0x59f050,0x5aef80]
BOUNDS=[(0x531ca0,0x531d8b),(0x531f70,0x531f87),(0x531f90,0x53207e),
        (0x5320b0,0x5321ef),(0x5697f0,0x5698b7),(0x59ed40,0x59ed8a),
        (0x59ef90,0x59efb5),(0x59f050,0x59f062),(0x5aef80,0x5aefca),
        (0x56e2c0,0x56e2f0),(0x5b0000,0x5b00a0),(0x5323e0,0x532410)]
BOUNDARIES={0x5321f0:'lock_create',0x5322b0:'enter',0x5322c0:'leave',
            0x5a0fbf:'format',0x53c290:'fill',0x59ed80:'virtual_alloc'}

def cases():
    # Each case exercises the real startup table entry and real allocator/free
    # against one initialized 64 KiB arena. Frees include adjacent coalescing.
    return [
      'A,32;F,0',
      'A,0;A,80;F,0;F,1',
      'A,8;A,24;A,56;F,1;A,40;F,0;F,2;F,3',
      'A,4096;A,512;F,0;F,1',
      'A,16;A,16;A,16;A,16;F,3;F,1;F,0;F,2',
      'A,1024;A,64;F,1;A,128;F,0;F,2',
    ]

def original(wire,module,data,functions):
    uc=Uc(UC_ARCH_X86,UC_MODE_32);base=int(module['image_base'],16);uc.mem_map(base,0x300000)
    for s in module['sections']:
        uc.mem_write(base+s['rva'],data[s['raw_offset']:s['raw_offset']+s['raw_size']])
    uc.mem_map(0x02000000,0x10000);uc.mem_map(EXIT,0x1000);uc.mem_map(ARENA,ARENA_BYTES)
    def put(p,v):uc.mem_write(p,struct.pack('<I',v&0xffffffff))
    def word(p):return struct.unpack('<I',uc.mem_read(p,4))[0]
    def words(p,n):return struct.unpack('<'+'I'*n,uc.mem_read(p,n*4))
    def cstring(p):
        if not p:return b''
        out=bytearray()
        while (b:=uc.mem_read(p+len(out),1)[0]):
            out.append(b)
            if len(out)>4096:raise RuntimeError('string fixture bound exceeded')
        return bytes(out)
    def snapshot():return bytes(uc.mem_read(ARENA,ARENA_BYTES)).hex()
    put(PAGE,0x1000);put(ACTIVE_TABLE,0x005e4700);put(OBJECT_HEAP,0)
    put(STACK,EXIT)
    calls=[];coverage=set();trace=[]
    # Reuse the exact body ranges published for the source functions where available.
    ranges=[]
    for va in FUNCTIONS:
        row=functions.get(f'{va:08x}')
        if row:ranges.extend((int(a,16),int(b,16)) for a,b in row['ranges'])
    if not ranges:ranges=BOUNDS
    def hook(m,address,_size,_user):
        trace.append(address)
        if address==EXIT:m.emu_stop();return
        if address in FUNCTIONS:coverage.add(f'{address:08x}')
        if address in BOUNDARIES:
            name=BOUNDARIES[address];sp=m.reg_read(UC_X86_REG_ESP)
            if name=='virtual_alloc':
                _,size,flags,protect=words(sp,4)
                calls.append(['alloc',size,flags,protect])
                m.reg_write(UC_X86_REG_EAX,ARENA if size<=ARENA_BYTES else 0)
                m.reg_write(UC_X86_REG_ESP,sp+16);m.reg_write(UC_X86_REG_EIP,address+6);return
            argc={'lock_create':0,'enter':1,'leave':1,'format':3,'fill':3,'virtual_alloc':4}[name]
            args=list(words(sp+4,argc)) if argc else []
            value=0
            if name=='lock_create':calls.append(['lock_create']);value=0x00700000
            elif name in ('enter','leave'):calls.append([name,args[0]])
            elif name=='format':
                fmt=cstring(args[1]);label=cstring(args[2]);calls.append(['format',fmt.decode('latin1'),label.decode('latin1')])
                uc.mem_write(args[0],fmt.replace(b'%s',label)+b'\0')
            elif name=='fill':
                calls.append(['fill',args[0]-ARENA,args[1],args[2]])
                uc.mem_write(args[0],bytes([args[1]&255])*args[2])
            m.reg_write(UC_X86_REG_EAX,value);m.reg_write(UC_X86_REG_ESP,sp+4);m.reg_write(UC_X86_REG_EIP,word(sp));return
        if not any(a<=address<=b for a,b in ranges):
            raise RuntimeError(f'unexpected original code {address:08x}; trace={[f"{x:08x}" for x in trace[-16:]]}')
    uc.hook_add(UC_HOOK_CODE,hook)
    def execute(va,args):
        uc.mem_write(STACK,struct.pack('<'+'I'*(len(args)+1),EXIT,*[x&0xffffffff for x in args]))
        uc.reg_write(UC_X86_REG_ESP,STACK)
        try:uc.emu_start(va,EXIT+1,count=100000)
        except Exception as error:
            tail=','.join(format(x,'08x') for x in trace[-20:])
            raise RuntimeError(f'emulation failed at {uc.reg_read(UC_X86_REG_EIP):08x} for {wire}; trace={tail}') from error
        if uc.reg_read(UC_X86_REG_EIP)!=EXIT or uc.reg_read(UC_X86_REG_ESP)!=STACK+4:
            raise RuntimeError(f'Original exit/stack differs at {va:08x}, {wire}; trace={[f"{x:08x}" for x in trace[-16:]]}')
        return uc.reg_read(UC_X86_REG_EAX)
    put(0x0200f100,ARENA_BYTES)
    execute(0x59ed40,[0x0200f100])
    rounded=word(0x0200f100)
    put(PRIMARY,ARENA) # startup_heap stores this before the primary commit.
    execute(0x5aef80,[ARENA,rounded])
    states=[snapshot()];returns=[];slots=[]
    for op in wire.split(';'):
        kind,n=op.split(',');n=int(n)
        if kind=='A':
            p=execute(0x59ef90,[n]);slots.append(p);returns.append(p-ARENA if p else 0xffffffff)
        else:
            p=slots[n];returns.append(execute(0x59f050,[p]))
        states.append(snapshot())
    # Native text is relocated. Canonicalize the heap's callback field to the
    # original callback VA; every other arena byte is compared verbatim.
    states=[s[:0x4c*2]+struct.pack('<I',0x005aef70).hex()+s[0x50*2:] for s in states]
    return {'returns':returns,'heaps':[word(HEAPS+4*i) for i in range(16)],
            'default':word(DEFAULT),'primary':word(PRIMARY),'page':word(PAGE),
            'object_heap':word(OBJECT_HEAP),'calls':calls,'states':states},coverage

def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--probe',type=Path,default=ROOT/'local/builds/v2/001-original-recovery/application-bootstrap/bin/Release/application_bootstrap_probe.exe')
    parser.add_argument('--report-dir',type=Path,default=RUN)
    args=parser.parse_args();probe=args.probe if args.probe.is_absolute() else ROOT/args.probe
    module=next(r for r in map(json.loads,(ROOT/'research/binary-index/static/binaries.jsonl').read_text().splitlines()) if r['file']=='Porsche.exe')
    data=(ROOT/'local/game'/module['path']).read_bytes();sha='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
    if hashlib.sha256(data).hexdigest()!=sha:raise RuntimeError('Porsche.exe SHA differs')
    funcs={r['entry_va']:r for r in map(json.loads,(ROOT/'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/functions.jsonl').read_text().splitlines())}
    inputs=cases();native=subprocess.run([str(probe)],input='\n'.join(inputs)+'\n',text=True,capture_output=True,check=True,timeout=120)
    outputs=[json.loads(line) for line in native.stdout.splitlines()]
    if len(outputs)!=len(inputs):raise RuntimeError('Native output count differs')
    coverage=set();fixtures=[]
    for i,(wire,actual) in enumerate(zip(inputs,outputs)):
        expected,hit=original(wire,module,data,funcs);coverage|=hit
        actual['states']=[s[:0x4c*2]+struct.pack('<I',0x005aef70).hex()+s[0x50*2:] for s in actual['states']]
        if expected!=actual:
            keys=[k for k in expected if expected[k]!=actual[k]]
            report=args.report_dir/'mismatch.json';report.write_text(json.dumps({'case':i,'wire':wire,'keys':keys,
                'expected':expected,'actual':actual},indent=2)+'\n',newline='\n')
            if 'states' in keys:
                for step,(x,y) in enumerate(zip(expected['states'],actual['states'])):
                    if x!=y:
                        j=next((j for j,(a,b) in enumerate(zip(bytes.fromhex(x),bytes.fromhex(y))) if a!=b),None)
                        raise RuntimeError(f'case {i} step {step} full arena differs at +{j:#x}; see {report}')
            raise RuntimeError(f'case {i} {wire} differs in {keys}; see {report}')
        fixtures.append({'input':wire,'output_sha256':hashlib.sha256(json.dumps(expected,sort_keys=True).encode()).hexdigest()})
    paths=[
      'iterations/v2/001-original-recovery/source/include/porsche/application_heap.hpp',
      'iterations/v2/001-original-recovery/source/include/porsche/application_heap_init.hpp',
      'iterations/v2/001-original-recovery/source/include/porsche/application_alloc.hpp',
      'iterations/v2/001-original-recovery/source/include/porsche/heap.hpp',
      'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/application_heap.cpp',
      'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/application_heap_init.cpp',
      'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/application_alloc.cpp',
      'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/heap.cpp',
      'iterations/v2/001-original-recovery/source/recovered/application_bootstrap_probe.cpp',
      'iterations/v2/001-original-recovery/runs/040-application-bootstrap/CMakeLists.txt',
      'scripts/research/verify-v2-application-bootstrap.py']
    result={'schema':1,'module':'Porsche.exe','sha256':sha,
      'function_vas':sorted(coverage),'cases':len(inputs),'native_cpp_equal_original_x86':True,
      'binary_matched':False,'game_launch_verified':False,
      'comparison':'Full 64 KiB arena after heap commit and every live allocate/free, all 16 heap globals, primary/default/page/object state, returns and ordered boundary calls.',
      'initial_state':'Page size=4096 and active allocator table at 005e4700, matching startup state established by 0059e9d0; its broader FE setup body is excluded.',
      'boundaries':{'OS':'0059ed40 VirtualAlloc target and page-size input','CRT':'005a0fbf formatting; 0053c290 fill',
                    'locks':'005321f0 create and 005322b0/005322c0 enter/leave; single-thread fixture'},
      'source_sha256':{p:hashlib.sha256((ROOT/p).read_bytes().replace(b'\r\n',b'\n')).hexdigest() for p in paths},
      'probe_sha256':hashlib.sha256(probe.read_bytes()).hexdigest(),'fixtures':fixtures}
    args.report_dir.mkdir(parents=True,exist_ok=True);(args.report_dir/'verification.json').write_text(json.dumps(result,indent=2)+'\n',newline='\n')
    print(json.dumps({'cases':len(inputs),'functions':sorted(coverage),'native_equal_original_x86':True}))

if __name__=='__main__':main()
