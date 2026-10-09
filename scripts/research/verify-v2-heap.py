from v2_source_dependencies import source_hashes
"""Compare recovered heap initialization/allocation/free/resize with original x86.

OS locks, CRT formatting/fill and optimized copy targets are recording boundaries.
The fallback forward copy and full allocator execute original instructions.
"""
import argparse
import hashlib
import json
from pathlib import Path
import random
import struct
import subprocess
import sys

ROOT=Path(__file__).resolve().parents[2]
RUN=ROOT/'iterations/v2/001-original-recovery/runs/004-original-heap'
sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_EDX,UC_X86_REG_ESP,UC_X86_REG_EIP
FUNCTIONS=[0x531c60,0x531ca0,0x531f90,0x5320b0,0x5323e0,0x556620,0x556650,0x569640,0x5697f0,0x56e2c0,0x5b0000]
ARENA,BUFFER,STACK,EXIT=0x3000000,0x2100000,0x2008000,0x2200000
FLAGS=[0x5deb1c,0x5deb18,0x5deb10,0x5deb30]

def cases():
    result=[]
    def case(ops,quantum=8,align=64,suffix=0,guard=0,named=0,locked=0,size=4096):
        return '|'.join(map(str,[quantum,align,suffix,guard,named,locked,size]))+'|'+ '|'.join(ops)
    for q in [4,8,16,32]:
        for flags in [0,16,32,48]:
            for size in [-1,0,1,7,8,63,64,65,3800,3855,3856,3857,3919,3920,3921,8192]:
                result.append(case([f'A,{size},{flags},6e616d65','F,0'],quantum=q))
    for named,guard,suffix in [(0,0,0),(1,0,16),(0,1,16),(1,1,16)]:
        for direction in [0,16,32,48]:
            for n in [0,1,8,33,128,2048,-1]:
                result.append(case([f'A,512,{direction},616263','W,0,0102030405',f'R,0,{n}'],
                                   named=named,guard=guard,suffix=suffix,locked=1))
    result += [case(['A,0,0,','F,0'],named=1,suffix=16),
               case(['A,16,0,-','R,0,32'],named=1,suffix=16),
               case(['A,80,2048,616263','F,0'],suffix=16),
               case(['O,0','A,8192,0,616263'],locked=1),
               case(['O,1','A,8192,16,-'],locked=1)]
    rng=random.Random(0x531ca0)
    for direction in [0,16,32,48]:
        for _ in range(12):
            ops=[f'A,{rng.randrange(8,96)},{direction},616263' for i in range(12)]
            order=list(range(12));rng.shuffle(order)
            ops += [f'F,{i}' for i in order[:6]]
            ops += [f'A,{rng.randrange(8,96)},{direction},-' for i in range(3)]
            ops += [f'F,{i}' for i in order[6:]+list(range(12,15))]
            result.append(case(ops))
    # FE requests use a 32 KiB allocation from the high end, a temporary file
    # allocation from the low end, then free/resize. Resource stays immutable.
    fe=(ROOT/'local/game/fe.txt').read_bytes()
    result.append(case(['A,32768,16,464520446174612053747265616d',f'A,{len(fe)},0,66652e747874',
                        'W,1,'+fe.hex(),'F,1','R,0,188'],size=65536))
    for alignment in [16,32,64,128,256]:
        result.append(case(['A,128,16,-','A,128,0,-','F,0','F,1'],align=alignment))
    for index in [1,3,15,17,259,513]:
        result.append(case([f'J,{index}',f'A,128,{index&15},616263','F,0'],suffix=16))
    for d in range(8):
        for n in [0,1,2,3,4,7,8,31,32,33,65]:
            result.append(case(['B,2048,'+bytes(range(96)).hex(),f'C,{3072+d},2048,{n}']))
    for delta in [-5,-2,-1,0,1,2,5]:
        result.append(case(['B,2048,'+bytes(range(128)).hex(),f'C,{2048+delta},2048,64']))
    for n in [-1,0,1,2,3,4,5]: result.append(case([f'H,2048,305419896,{n}']))
    for bits in range(16): result.append(case(['B,2048,'+bytes(range(32)).hex(),f'G,{bits}','D,3072,2048,32']))
    return result

def original(wire,module,data,functions):
    uc=Uc(UC_ARCH_X86,UC_MODE_32);base=int(module['image_base'],16);uc.mem_map(base,0x300000)
    for s in module['sections']:uc.mem_write(base+s['rva'],data[s['raw_offset']:s['raw_offset']+s['raw_size']])
    uc.mem_map(0x2000000,0x10000);uc.mem_map(BUFFER,0x10000);uc.mem_map(EXIT,0x1000);uc.mem_map(ARENA,0x20000)
    parts=wire.split('|');quantum,align,suffix,guard,named,locked,size=map(int,parts[:7])
    uc.mem_write(ARENA,b'\xcc'*size);uc.mem_write(0x6b4f20,b'\0'*64);uc.mem_write(0x69cb00,b'\0'*4)
    for p in FLAGS:uc.mem_write(p,struct.pack('<I',int(p==0x5deb10)))
    calls=[];coverage=set();failure_mode=0;failure_count=0
    ranges=[(int(a,16),int(b,16)) for va in FUNCTIONS for a,b in functions[f'{va:08x}']['ranges']]
    def words(p,n):return struct.unpack('<'+'I'*n,uc.mem_read(p,n*4))
    def put(p,x):uc.mem_write(p,struct.pack('<I',x&0xffffffff))
    def signed(x):return x if x<0x80000000 else x-0x100000000
    def cstring(p):
        if not p:return b''
        out=bytearray()
        while (c:=uc.mem_read(p+len(out),1)[0]):
            out.append(c)
            if len(out)>4096:raise RuntimeError('String exceeds fixture bound')
        return bytes(out)
    def hook(uc,p,length,user):
        nonlocal failure_count
        if p==EXIT:uc.emu_stop();return
        if p in FUNCTIONS:coverage.add(f'{p:08x}')
        n={0x5322b0:1,0x5322c0:1,0x5321f0:0,0x5a0fbf:3,0x53c290:3,
           0x5b0100:3,0x5b02c0:3,0x5b0480:3,EXIT+0x100:3}.get(p)
        if n is None:
            if not any(a<=p<=b for a,b in ranges):raise RuntimeError(f'Unexpected original code {p:08x}')
            return
        sp=uc.reg_read(UC_X86_REG_ESP);ret,*args=words(sp,n+1);value=0
        if p in (0x5322b0,0x5322c0):calls.append(['enter' if p==0x5322b0 else 'leave',args[0]-ARENA])
        elif p==0x5321f0:calls.append(['create']);value=0x2001000
        elif p==0x5a0fbf:
            fmt=cstring(args[1]);name=cstring(args[2]);calls.append(['format',fmt.decode(),name.decode()]);uc.mem_write(args[0],fmt.replace(b'%s',name)+b'\0')
        elif p==0x53c290:
            calls.append(['fill',args[0]-ARENA,args[1],args[2]]);uc.mem_write(args[0],bytes([args[1]&255])*args[2])
        elif p==EXIT+0x100:
            calls.append(['failure',cstring(args[0]).hex() if args[0] else 'null',signed(args[1]),args[2]])
            value=int(failure_mode==1 and failure_count==0);failure_count+=1
        else:
            calls.append([{0x5b0100:'copy100',0x5b02c0:'copy2c0',0x5b0480:'copy480'}[p],args[0]-ARENA,args[1]-ARENA,args[2]])
            uc.mem_write(args[0],bytes(uc.mem_read(args[1],args[2])))
        uc.reg_write(UC_X86_REG_EAX,value);uc.reg_write(UC_X86_REG_ESP,sp+4);uc.reg_write(UC_X86_REG_EIP,ret)
    uc.hook_add(UC_HOOK_CODE,hook)
    def execute(va,args,wide=False):
        uc.mem_write(STACK,struct.pack('<'+'I'*(len(args)+1),EXIT,*[x&0xffffffff for x in args]))
        uc.reg_write(UC_X86_REG_ESP,STACK);uc.emu_start(va,EXIT+1,count=1000000)
        if uc.reg_read(UC_X86_REG_EIP)!=EXIT or uc.reg_read(UC_X86_REG_ESP)!=STACK+4:raise RuntimeError(f'Original cdecl stack/exit differs at {va:08x}')
        value=uc.reg_read(UC_X86_REG_EAX)
        return value|(uc.reg_read(UC_X86_REG_EDX)<<32) if wide else value
    uc.mem_write(BUFFER,b'heap\0')
    returns=[execute(0x5697f0,[0,BUFFER,ARENA,size,quantum,align,suffix,guard,0,named,locked,0])];slots=[]
    states=[bytes(uc.mem_read(ARENA,size)).hex()]
    for op in parts[7:]:
        a=op.split(',');kind=a[0]
        if kind=='A':
            name=0 if a[3]=='-' else BUFFER+0x100
            if name:uc.mem_write(name,bytes.fromhex(a[3])+b'\0')
            p=execute(0x531ca0,[name,int(a[1]),int(a[2],0)]);slots.append(p);returns.append(p-ARENA if p else -1)
        elif kind=='F':returns.append(execute(0x531f90,[slots[int(a[1])]]))
        elif kind=='R':
            p=execute(0x569640,[slots[int(a[1])],int(a[2])]);slots[int(a[1])]=p;returns.append(p-ARENA if p else -1)
        elif kind in ('W','B'):
            uc.mem_write(slots[int(a[1])] if kind=='W' else ARENA+int(a[1]),bytes.fromhex(a[2]));returns.append(0)
        elif kind=='C':returns.append(execute(0x5b0000,[ARENA+int(a[1]),ARENA+int(a[2]),int(a[3])],True))
        elif kind=='D':execute(0x5323e0,[ARENA+int(a[1]),ARENA+int(a[2]),int(a[3])]);returns.append(0)
        elif kind=='H':returns.append(execute(0x56e2c0,[ARENA+int(a[1]),int(a[2]),int(a[3])])-ARENA)
        elif kind=='G':
            for i,p in enumerate(FLAGS):put(p,int(a[1])&(1<<i))
            returns.append(0)
        elif kind=='O':failure_mode=int(a[1]);failure_count=0;put(0x69cb00,EXIT+0x100);returns.append(0)
        elif kind=='J':
            uc.mem_write(BUFFER,b'heap\0');returns.append(execute(0x5697f0,[int(a[1]),BUFFER,ARENA,size,quantum,align,suffix,guard,0,named,locked,0]))
        else:raise RuntimeError('Unknown fixture operation')
        states.append(bytes(uc.mem_read(ARENA,size)).hex())
    return {'returns':returns,'arena':states[-1],'calls':calls,'states':states},coverage

def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--limit',type=int)
    parser.add_argument('--report-dir',type=Path,default=RUN,
                        help='checkpoint directory for mismatch and full verification reports')
    args=parser.parse_args()
    report_dir=args.report_dir if args.report_dir.is_absolute() else ROOT/args.report_dir
    module=next(r for r in map(json.loads,(ROOT/'research/binary-index/static/binaries.jsonl').read_text().splitlines()) if r['file']=='Porsche.exe')
    data=(ROOT/'local/game'/module['path']).read_bytes()
    if hashlib.sha256(data).hexdigest()!=module['sha256']:raise RuntimeError('Original SHA differs')
    funcs={r['entry_va']:r for r in map(json.loads,(ROOT/'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/functions.jsonl').read_text().splitlines())}
    inputs=cases();inputs=inputs[:args.limit] if args.limit else inputs
    probe=ROOT/'local/builds/v2/001-original-recovery/bin/Release/heap_probe.exe'
    native=subprocess.run([str(probe)],input='\n'.join(inputs)+'\n',text=True,capture_output=True,check=True,timeout=60)
    outputs=[json.loads(l) for l in native.stdout.splitlines()]
    if len(inputs)!=len(outputs):raise RuntimeError('Native output count differs')
    fixtures=[];coverage=set()
    for i,(wire,actual) in enumerate(zip(inputs,outputs)):
        expected,hit=original(wire,module,data,funcs);coverage|=hit
        if expected!=actual:
            report_dir.mkdir(parents=True,exist_ok=True)
            p=report_dir/'heap-mismatch.json';p.write_text(json.dumps({'case':i,'wire':wire,'expected':expected,'actual':actual},indent=2)+'\n')
            diffs=[k for k in expected if expected[k]!=actual[k]]
            byte_diffs=[j for j,(a,b) in enumerate(zip(bytes.fromhex(expected['arena']),bytes.fromhex(actual['arena']))) if a!=b]
            raise RuntimeError(f'Case {i} differs: {diffs}, first memory bytes {byte_diffs[:12]}; {p}')
        fixtures.append({'input':wire,'output_sha256':hashlib.sha256(json.dumps(expected,sort_keys=True).encode()).hexdigest(),'operations':len(wire.split('|'))-7})
    print(json.dumps({'cases':len(inputs),'functions':sorted(coverage),'native_equal_original':True}))
    if not args.limit:
        paths=['source/include/porsche/heap.hpp','source/include/porsche/fe_stream.hpp','source/recovered/Porsche.exe/heap.cpp','source/recovered/heap_probe.cpp']
        paths=['iterations/v2/001-original-recovery/'+p for p in paths]
        report={'schema':1,'sha256':module['sha256'],'function_vas':sorted(coverage),'cases':len(inputs),
            'native_cpp_equal_original_x86':True,'binary_matched':False,'game_launch_verified':False,
            'boundaries':{'locks':'005322b0/005322c0/005321f0 recording single-thread lock lifecycle',
                          'CRT':'005a0fbf %s LOW/HIGH formatting and 0053c290 zero fill recording endpoints',
                          'optimized_copy':'005b0100/005b02c0/005b0480 recording endpoints; only selection verified',
                          'allocation_failure':'0069cb00 recording callback, retry once or no retry'},
            'comparison':'Whole arena bytes after every operation including physical headers/free rings/payload/trailers, returns and external calls; fixed VA is probe-only',
            'source_sha256':{p:hashlib.sha256((ROOT/p).read_bytes().replace(b'\r\n',b'\n')).hexdigest() for p in paths},
            'probe_sha256':hashlib.sha256(probe.read_bytes()).hexdigest(),'fixtures':fixtures}
        report['source_sha256']=source_hashes([*report['source_sha256'],Path(__file__)])
        report_dir.mkdir(parents=True,exist_ok=True);(report_dir/'verification.json').write_text(json.dumps(report,indent=2)+'\n',newline='\n')
        (report_dir/'source-functions.jsonl').write_text(''.join(json.dumps({'sha256':module['sha256'],**funcs[va]})+'\n' for va in sorted(coverage)),newline='\n')

if __name__=='__main__':main()
