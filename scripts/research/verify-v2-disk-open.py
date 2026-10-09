from v2_source_dependencies import source_hashes
"""Differential Porsche.exe physical-open and slot-allocation unit."""
import argparse
import hashlib
import json
from pathlib import Path
import random
import struct
import subprocess
import sys

ROOT=Path(__file__).resolve().parents[2]
RUN=ROOT/'iterations/v2/001-original-recovery/runs/016-disk-open'
sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ESP,UC_X86_REG_EIP

ARENA,STACK,EXIT=0x03400000,0x0200f000,0x02200000
FILES,PATH,ENCODED=ARENA,ARENA+0x1000,ARENA+0x2000
TABLE_LOCK,DEVICE_LOCK,NEW_LOCK=0x02001000,0x02002000,0x02003000
IAT={0x5b21a4:(0x100,'error',1),0x5b2090:(0x110,'free',5),
     0x5b21fc:(0x120,'create',7),0x5b2238:(0x130,'size',2),
     0x5b21c0:(0x140,'mapping',6),0x5b21bc:(0x150,'view',5)}


def cases():
    out=[]
    for kind in (0,1):
        for pattern in range(4):
            for flags in (0,1,2,3,0x10,0x20,0x30,0x800,0x802,0xf37,0xffff):
                if kind==1 and flags: continue
                for request in (0,256,4096):
                    for free_ok,sector in ((0,0),(1,0),(1,512)):
                        for create_ok,map_ok,view_ok in ((0,0,0),(1,0,0),(1,1,0),(1,1,1)):
                            if kind==1 and (request or free_ok or create_ok): continue
                            out.append((kind,pattern,flags,request,free_ok,sector,create_ok,12345,map_ok,view_ok,pattern&1,0))
    out += [(1,p,0,0,1,512,1,12345,1,1,0,1) for p in range(4)]
    rng=random.Random(0x5919a0)
    for _ in range(80):
        out.append((0,rng.randrange(4),rng.getrandbits(12),rng.randrange(0,70000),
                    rng.randrange(2),rng.choice((0,512,2048)),rng.randrange(2),
                    rng.getrandbits(32),rng.randrange(2),rng.randrange(2),rng.randrange(2),0))
    return out


def original(module,data,case):
    kind,pattern,flags,request,free_ok,sector,create_ok,file_size,map_ok,view_ok,locked,init=case
    uc=Uc(UC_ARCH_X86,UC_MODE_32);base=int(module['image_base'],16)
    uc.mem_map(base,0x300000)
    for section in module['sections']:
        uc.mem_write(base+section['rva'],data[section['raw_offset']:section['raw_offset']+section['raw_size']])
    uc.mem_map(ARENA,0x10000);uc.mem_map(0x2000000,0x10000);uc.mem_map(EXIT,0x1000)
    uc.mem_write(FILES,b'\xcc'*64)
    uc.mem_write(FILES,bytes([int(pattern in (1,2))]))
    uc.mem_write(FILES+32,bytes([int(pattern in (2,3))]))
    uc.mem_write(PATH,b'C:\\sample.dat\x00')
    uc.mem_write(ENCODED,struct.pack('<I',0xaaaaaaaa))
    def put(address,*values):uc.mem_write(address,struct.pack('<'+'I'*len(values),*(v&0xffffffff for v in values)))
    def words(address,count):return struct.unpack('<'+'I'*count,uc.mem_read(address,count*4))
    put(0x6af084,0 if init else FILES);put(0x6af080,2);put(0x6af07c,TABLE_LOCK)
    uc.mem_write(0x6aeffc,bytes(128));put(0x6aeffc+12,DEVICE_LOCK if locked else 0)
    for iat,(offset,_,_) in IAT.items():put(iat,EXIT+offset)
    endpoints={0x591820:('init',1,False),0x591760:('path',1,False),
               0x5321f0:('newlock',0,False),0x5322b0:('enter',1,False),
               0x5322c0:('leave',1,False),0x53c290:('fill',3,False)}
    endpoints.update({EXIT+offset:(name,argc,True) for offset,name,argc in IAT.values()})
    calls=[]
    def hook(machine,address,_size,_user):
        if address not in endpoints:return
        name,argc,stdcall=endpoints[address]
        sp=machine.reg_read(UC_X86_REG_ESP);ret,*args=words(sp,argc+1)
        value=0
        if name=='init':
            calls.append(['init',args[0]]);put(0x6af084,FILES);put(0x6af080,2);put(0x6af07c,TABLE_LOCK)
        elif name=='path':calls.append(['path',bytes(machine.mem_read(args[0],14)).hex()]);value=3
        elif name=='newlock':calls.append(['newlock']);value=NEW_LOCK
        elif name in ('enter','leave'):calls.append([name,args[0]])
        elif name=='fill':calls.append(['fill',args[2]]);machine.mem_write(args[0],bytes([args[1]&255])*args[2])
        elif name=='error':calls.append(['error',args[0]])
        elif name=='free':
            calls.append(['free',bytes(machine.mem_read(args[0],4)).hex()]);
            for address2,v in zip(args[1:],(4,sector,8,16)):put(address2,v)
            value=free_ok
        elif name=='create':
            calls.append(['create',bytes(machine.mem_read(args[0],14)).hex(),args[1],args[2],args[4],args[5]])
            value=0x12345000 if create_ok else 0xffffffff
        elif name=='size':calls.append(['size',args[0]]);value=file_size
        elif name=='mapping':calls.append(['mapping',args[0],args[2],args[3],args[4]]);value=0x23456000 if map_ok else 0
        elif name=='view':calls.append(['view',*args]);value=0x34567000 if view_ok else 0
        machine.reg_write(UC_X86_REG_EAX,value)
        machine.reg_write(UC_X86_REG_ESP,sp+4*(argc+1) if stdcall else sp+4)
        machine.reg_write(UC_X86_REG_EIP,ret)
    uc.hook_add(UC_HOOK_CODE,hook)
    target=0x5919a0 if kind==0 else 0x591c50
    args=(PATH,flags,request,ENCODED) if kind==0 else ()
    put(STACK,EXIT,*args);uc.reg_write(UC_X86_REG_ESP,STACK)
    uc.emu_start(target,EXIT,count=50000)
    if uc.reg_read(UC_X86_REG_EIP)!=EXIT:raise RuntimeError('Original did not return')
    return {'return':uc.reg_read(UC_X86_REG_EAX),'encoded':words(ENCODED,1)[0] if kind==0 else 0,
            'files':bytes(uc.mem_read(FILES,64)).hex(),'mutex':words(0x6aeffc+12,1)[0],
            'calls':calls}


def body_digest(module,data,entry):
    start,end=map(lambda value:int(value,16),entry['ranges'][0])
    rva=start-int(module['image_base'],16)
    section=next(s for s in module['sections'] if s['rva']<=rva and
                 rva+end-start<s['rva']+s['raw_size'])
    offset=section['raw_offset']+rva-section['rva']
    body=data[offset:offset+end-start+1]
    if len(body)!=entry['body_bytes']:raise RuntimeError('Original body range/size mismatch')
    return hashlib.sha256(body).hexdigest()


def main():
    parser=argparse.ArgumentParser()
    parser.add_argument('--probe',type=Path,default=ROOT/'local/builds/v2/001-original-recovery/bin/Release/disk_open_probe.exe')
    parser.add_argument('--limit',type=int,default=0)
    parser.add_argument('--report-dir',type=Path,default=RUN)
    args=parser.parse_args()
    report_dir=args.report_dir
    module=next(x for x in map(json.loads,(ROOT/'research/binary-index/static/binaries.jsonl').read_text(encoding='utf8').splitlines()) if x['file']=='Porsche.exe')
    data=(ROOT/'local/game'/module['path']).read_bytes()
    sha='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
    if hashlib.sha256(data).hexdigest()!=sha or module['sha256']!=sha:raise RuntimeError('Original SHA mismatch')
    inputs=cases()[:args.limit or None]
    native=subprocess.run([str(args.probe)],input='\n'.join(' '.join(map(str,c)) for c in inputs)+'\n',
                          text=True,capture_output=True,check=True,timeout=120)
    rows=list(map(json.loads,native.stdout.splitlines()))
    if len(rows)!=len(inputs):raise RuntimeError(f'Native rows {len(rows)} != cases {len(inputs)}')
    fixtures=[]
    for i,(case,actual) in enumerate(zip(inputs,rows)):
        expected=original(module,data,case)
        if actual!=expected:
            dest=ROOT/'local/reports/v2-disk-open-mismatch.json'
            dest.write_text(json.dumps({'case':i,'input':case,'expected':expected,'actual':actual},indent=2)+'\n')
            raise RuntimeError(f'Case {i} differs in {[k for k in expected if expected[k]!=actual.get(k)]}; {dest}')
        fixtures.append({'input':case,'output_sha256':hashlib.sha256(json.dumps(expected,sort_keys=True).encode()).hexdigest()})
    print(json.dumps({'cases':len(inputs),'native_cpp_equal_original_x86':True,'function_vas':['005919a0','00591c50']}))
    if args.limit:return
    paths=['iterations/v2/001-original-recovery/source/include/porsche/disk_open.hpp',
           'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/disk_open.cpp',
           'iterations/v2/001-original-recovery/source/recovered/disk_open_probe.cpp',
           'iterations/v2/001-original-recovery/source/include/porsche/file_disk.hpp',
           'iterations/v2/001-original-recovery/source/include/porsche/files.hpp',
           'scripts/research/verify-v2-disk-open.py',
           'iterations/v2/001-original-recovery/CMakeLists.txt',
           'iterations/v2/001-original-recovery/source/recovered/sources.cmake']
    functions={v['entry_va']:v for v in map(json.loads,(ROOT/'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/functions.jsonl').read_text(encoding='utf8').splitlines())}
    body_hashes={va:body_digest(module,data,functions[va]) for va in ('005919a0','00591c50')}
    report={'schema':1,'sha256':sha,'function_vas':['005919a0','00591c50'],'cases':len(inputs),
            'native_cpp_equal_original_x86':True,'binary_matched':False,'game_launch_verified':False,
            'boundaries':'Win32 open/mapping/space/last-error and original init/pathdevice/lock/fill are controlled typed recording endpoints; concurrency and real disk I/O unverified.',
            'source_sha256':{p:hashlib.sha256((ROOT/p).read_bytes().replace(b'\r\n',b'\n')).hexdigest() for p in paths},
            'original_body_sha256':body_hashes,
            'probe_sha256':hashlib.sha256(args.probe.read_bytes()).hexdigest(),'fixtures':fixtures}
    report_dir.mkdir(parents=True,exist_ok=True)
    report['source_sha256']=source_hashes([*report['source_sha256'],Path(__file__)])
    (report_dir/'verification.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf8')
    (report_dir/'source-functions.jsonl').write_text(''.join(json.dumps({'sha256':sha,'body_sha256':body_hashes[v],**functions[v]})+'\n' for v in ('005919a0','00591c50')),encoding='utf8')

if __name__=='__main__':main()
