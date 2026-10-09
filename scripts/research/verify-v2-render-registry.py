"""Differentially execute recovered render registry routines in Porsche.exe x86."""
import argparse
import hashlib, json, struct, subprocess, sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
RUN=ROOT/'iterations/v2/001-original-recovery/runs/042-render-registry'
sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ECX,UC_X86_REG_EIP,UC_X86_REG_ESP
SHA='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
STACK=0x0200f000;EXIT=0x02200000;CORE=0x03000000;COMPANY=0x03001000;TITLE=0x03001100;OUT=0x03001200
ENTRY={0:0x4b76f0,1:0x4b7220,2:0x4b7240,3:0x4b7340,4:0x4b7150,5:0x4b76f0}
TABLE=0x5d6f28
def cases():
    # op,index,seed,hkey,open statuses(3),create,close,query statuses(2),payload size/seed,numeric
    base=lambda op,ix=0:(op,ix,0x35,0x12345678,2,2,2,0,5,1,1,5,0x40,0x78563412)
    a=[base(0),base(0),base(0),base(0),base(5),base(4),base(1)]
    a[0]=(*base(0)[:4],0,2,2,1,5,1,1,5,0x40,0x78563412) # legacy alias exists
    a[1]=(*base(0)[:4],2,0,2,1,5,1,1,5,0x40,0x78563412) # second alias exists
    a[2]=(*base(0)[:4],2,2,0,1,5,1,1,5,0x40,0x78563412) # title exists
    a[3]=(*base(0)[:4],2,2,2,0,5,1,1,5,0x40,0x78563412) # open miss, create success
    a.append((*base(0)[:4],2,2,2,5,5,1,1,5,0x40,0x78563412)) # create error
    a[4]=(*base(5)[:4],2,2,0,0,5,1,1,5,0x40,0x78563412)
    a[5]=(*base(4)[:4],2,2,2,0,5,1,1,5,0x40,0x78563412)
    a[6]=(*base(1)[:4],2,2,2,0,5,1,1,5,0x40,0x78563412)
    for ix,size in [(0,8),(1,256),(2,7),(3,4),(4,12),(5,0),(6,255),(7,3),(8,6)]:
        x=list(base(2,ix));x[10]=0;x[11]=size;x[12]=0x20+ix;a.append(tuple(x))
    for ix in range(9):
        x=list(base(3,ix));x[10]=0;x[11]=4;x[12]=0x70+ix;a.append(tuple(x))
    x=list(base(2,0));x[9:11]=[5,0];a.append(tuple(x)) # missing text value, set then query
    x=list(base(3,1));x[9:11]=[5,0];a.append(tuple(x)) # numeric default then query
    return a
def original(case,module,data,functions):
    op,ix,seed,key,o0,o1,o2,create_status,close_status,q0,q1,dsize,dseed,number=case
    uc=Uc(UC_ARCH_X86,UC_MODE_32);base=int(module['image_base'],16);uc.mem_map(base,0x300000)
    for s in module['sections']:uc.mem_write(base+s['rva'],data[s['raw_offset']:s['raw_offset']+s['raw_size']])
    for address,size in [(0x02000000,0x10000),(EXIT,0x1000),(CORE,0x1000),(COMPANY,0x1000)]:uc.mem_map(address,size)
    def put(p,v):uc.mem_write(p,struct.pack('<I',v&0xffffffff))
    def word(p):return struct.unpack('<I',uc.mem_read(p,4))[0]
    def words(p,n):return struct.unpack('<'+'I'*n,uc.mem_read(p,n*4))
    def cstr(p):
        b=bytearray()
        while len(b)<1024:
            v=uc.mem_read(p+len(b),1)[0]
            if not v:break
            b.append(v)
        return b.decode('ascii')
    uc.mem_write(COMPANY,b'Electronic Arts\0');uc.mem_write(TITLE,b'Need for Speed - Porsche Unleashed\0')
    core=bytearray([seed&255])*0x118;struct.pack_into('<I',core,0,0x5b3fbc);struct.pack_into('<I',core,4,COMPANY);struct.pack_into('<I',core,0xc,TITLE);struct.pack_into('<I',core,0x114,key);uc.mem_write(CORE,bytes(core))
    uc.mem_write(OUT,bytes([seed&255])*256)
    calls=[];nopen=0;nquery=0;store={};coverage=set();trace=[]
    ranges=[]
    for va in (0x4b7150,0x4b7220,0x4b7240,0x4b7340):
        row=functions.get(f'{va:08x}')
        if row:ranges += [(int(a,16),int(b,16)) for a,b in row['ranges']]
    ranges += [(0x4b7150,0x4b71a9),(0x4b7220,0x4b7238),
               (0x4b7240,0x4b7339),(0x4b7340,0x4b73eb),
               (0x4b76f0,0x4b77c9)]
    def hook(m,address,_size,_user):
        nonlocal nopen,nquery
        trace.append(address)
        if address==EXIT:m.emu_stop();return
        if address in ENTRY.values():coverage.add(f'{address:08x}')
        if address in (0x4b7741,0x4b7780):
            sp=m.reg_read(UC_X86_REG_ESP);root,path,res,access,out=words(sp,5);status=(o0,o1,o2)[min(nopen,2)];nopen+=1
            calls.append(f'open|{root}|{cstr(path)}|{res}|{access}|{status}')
            if status==0:put(out,0x51000000+nopen-1)
            m.reg_write(UC_X86_REG_EAX,status);m.reg_write(UC_X86_REG_ESP,sp+20);m.reg_write(UC_X86_REG_EIP,address+6);return
        if address in (0x4b772b,0x4b776a):
            # Bounded external formatting endpoint: the original supplies the
            # exact format and arguments; emulate only this CRT-style call.
            sp=m.reg_read(UC_X86_REG_ESP);dst,fmt,company,product=words(sp,4)
            if cstr(fmt)!='SOFTWARE\\%s\\%s':raise RuntimeError('unexpected registry path format')
            path=('SOFTWARE\\'+cstr(company)+'\\'+cstr(product)).encode('ascii')+b'\0'
            uc.mem_write(dst,path);m.reg_write(UC_X86_REG_EAX,len(path)-1)
            m.reg_write(UC_X86_REG_EIP,address+5);return
        if address==0x4b7793:
            sp=m.reg_read(UC_X86_REG_ESP);root,path,out=words(sp,3);calls.append(f'create|{root}|{cstr(path)}|{create_status}')
            if create_status==0:put(out,0x52000000)
            m.reg_write(UC_X86_REG_EAX,create_status);m.reg_write(UC_X86_REG_ESP,sp+12);m.reg_write(UC_X86_REG_EIP,address+6);return
        if address==0x4b722a:
            sp=m.reg_read(UC_X86_REG_ESP);h=word(sp);calls.append(f'close|{h}|{close_status}')
            m.reg_write(UC_X86_REG_EAX,close_status);m.reg_write(UC_X86_REG_ESP,sp+4);m.reg_write(UC_X86_REG_EIP,address+6);return
        if address in (0x4b7197,0x4b72c8,0x4b73c1):
            sp=m.reg_read(UC_X86_REG_ESP);h,name,res,typ,p,n=words(sp,6);payload=bytes(uc.mem_read(p,n)) if n else b''
            nm=cstr(name);calls.append(f'set|{h}|{nm}|{res}|{typ}|{n}|{payload.hex()}');store[nm]=(typ,payload)
            m.reg_write(UC_X86_REG_EAX,0);m.reg_write(UC_X86_REG_ESP,sp+24);m.reg_write(UC_X86_REG_EIP,address+(2 if address==0x4b7197 else 6));return
        if address in (0x4b727d,0x4b72e4,0x4b7374,0x4b73dd):
            sp=m.reg_read(UC_X86_REG_ESP);h,name,res,typ,p,size=words(sp,6);cap=word(size);status=(q0,q1)[min(nquery,1)];nquery+=1;nm=cstr(name)
            payload=store.get(nm,(1,bytes((dseed+i)&255 for i in range(dsize))))[1] if status==0 else b''
            if status==0:
                put(size,len(payload));
                if p and payload:uc.mem_write(p,payload[:cap])
                if typ:put(typ,store.get(nm,(1,payload))[0])
            after=word(size);written=bytes(uc.mem_read(p,min(after,cap))) if status==0 and p else b''
            calls.append(f'query|{h}|{nm}|{cap}|{int(res!=0)}|{int(typ!=0)}|{status}|{after}|{written.hex()}')
            m.reg_write(UC_X86_REG_EAX,status);m.reg_write(UC_X86_REG_ESP,sp+24);m.reg_write(UC_X86_REG_EIP,address+6);return
        if not any(a<=address<=b for a,b in ranges):raise RuntimeError(f'outside covered code at {address:08x}: {trace[-16:]}')
    uc.hook_add(UC_HOOK_CODE,hook)
    args=() if op in (1,4) else ((ix,OUT) if op==2 else (ix,) if op==3 else ())
    uc.reg_write(UC_X86_REG_ECX,CORE);uc.mem_write(STACK,struct.pack('<'+'I'*(len(args)+1),EXIT,*args));uc.reg_write(UC_X86_REG_ESP,STACK)
    try:uc.emu_start(ENTRY[op],EXIT+1,count=200000)
    except Exception as e:raise RuntimeError(f'x86 at {uc.reg_read(UC_X86_REG_EIP):08x}, case={case}, trace={trace[-20:]}') from e
    expected_sp=STACK+4+(8 if op==2 else 4 if op==3 else 0)
    if uc.reg_read(UC_X86_REG_EIP)!=EXIT or uc.reg_read(UC_X86_REG_ESP)!=expected_sp:raise RuntimeError(f'x86 return/stack mismatch {op}: {uc.reg_read(UC_X86_REG_ESP):x}/{expected_sp:x}')
    result=uc.reg_read(UC_X86_REG_EAX) if op in (0,3) else 0
    out=bytes(uc.mem_read(OUT,256));raw=bytearray(uc.mem_read(CORE,0x118));struct.pack_into('<I',raw,4,0x03200000);struct.pack_into('<I',raw,0xc,0x03200100)
    event_text=';'.join(calls).encode('ascii').hex()
    return {'ret':result,'core':raw.hex(),'out':out.hex(),'calls':event_text},coverage
def main():
    parser=argparse.ArgumentParser()
    parser.add_argument("--probe",type=Path,default=ROOT/"local/builds/v2/001-original-recovery/bin/Release/render_registry_probe.exe")
    parser.add_argument("--report-dir",type=Path,default=RUN)
    args=parser.parse_args()
    report_dir=args.report_dir
    report_dir.mkdir(parents=True,exist_ok=True)
    module=next(x for x in map(json.loads,(ROOT/'research/binary-index/static/binaries.jsonl').read_text().splitlines()) if x['file']=='Porsche.exe')
    data=(ROOT/'local/game'/module['path']).read_bytes()
    if hashlib.sha256(data).hexdigest()!=SHA:raise RuntimeError('Original binary SHA mismatch')
    functions={x['entry_va']:x for x in map(json.loads,(ROOT/'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/functions.jsonl').read_text().splitlines())}
    probe=args.probe;inputs=cases()
    proc=subprocess.run([str(probe)],input=''.join(' '.join(map(str,c))+'\n' for c in inputs),text=True,capture_output=True,check=True,timeout=60)
    actual=[json.loads(x) for x in proc.stdout.splitlines()]
    if len(actual)!=len(inputs):raise RuntimeError('Native output count differs')
    coverage=set();fixtures=[]
    for i,(case,got) in enumerate(zip(inputs,actual)):
        want,hit=original(case,module,data,functions);coverage|=hit
        if got!=want:raise AssertionError(f'case {i} {case}: x86={want}, native={got}')
        fixtures.append({'input':case,'output_sha256':hashlib.sha256(json.dumps(want,sort_keys=True).encode()).hexdigest()})
    rel=['iterations/v2/001-original-recovery/source/include/porsche/render_registry.hpp','iterations/v2/001-original-recovery/source/include/porsche/render_objects.hpp','iterations/v2/001-original-recovery/source/recovered/Porsche.exe/render_registry.cpp','iterations/v2/001-original-recovery/source/recovered/render_registry_probe.cpp','iterations/v2/001-original-recovery/runs/042-render-registry/CMakeLists.txt','scripts/research/verify-v2-render-registry.py']
    result={'schema':1,'module':'Porsche.exe','sha256':SHA,'function_vas':sorted(coverage),'cases':len(inputs),'native_cpp_equal_original_x86':True,'binary_matched':False,'game_launch_verified':False,'source_sha256':{p:hashlib.sha256((ROOT/p).read_bytes().replace(b'\r\n',b'\n')).hexdigest() for p in rel},'fixtures':fixtures}
    (report_dir/'verification.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    print(f"PASS {len(inputs)} differential cases; covered {', '.join(result['function_vas'])}; report {report_dir/'verification.json'}")
if __name__=='__main__':main()
