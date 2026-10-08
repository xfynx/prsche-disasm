"""Compare recovered FE/heap/file queues, worker and wait with original x86."""
import argparse
import hashlib
import json
from pathlib import Path
import struct
import random
import subprocess
import sys
from v2_manual_index import records as manual_records

ROOT=Path(__file__).resolve().parents[2]
RUN=ROOT/'iterations/v2/001-original-recovery/runs/008-file-scheduler/files-regression'
sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_EBX,UC_X86_REG_ECX,UC_X86_REG_EDX,UC_X86_REG_ESI,UC_X86_REG_EDI,UC_X86_REG_EBP,UC_X86_REG_EFLAGS,UC_X86_REG_ESP,UC_X86_REG_EIP
FILES=[0x533b90,0x533bf0,0x533c20,0x533cd0,0x533da0,0x533de0,0x59e040,
       0x567af0,0x567b80,0x567bf0,0x567df0,0x5680c0,0x568200,0x5682a0,
       0x5684c0,0x5684e0,0x568aa0,0x568ae0,0x568b10,0x568b90,0x5925d0]
LISTS=[0x5806e0,0x580730,0x580790,0x580850,0x5808f0,0x580930,0x580ad0,0x580c10,0x580ea0,0x580ec0]
HEAP=[0x531c60,0x531ca0,0x531f90,0x5320b0,0x5323e0,0x556620,0x556650,0x569640,0x5697f0,0x56e2c0,0x5b0000,0x56e5f0,0x56e640]
FE=[0x4b51e0,0x4b5250,0x4b5430,0x4b5470,0x4b5ee0,0x4b60d0,0x4b6660,0x4b4b80,0x4b4cd0]
FUNCTIONS=FILES+LISTS+HEAP+FE+[0x568530,0x567f70]
IO,HEAP_ARENA,BUFFER,STACK,EXIT=0x3100000,0x3000000,0x3200000,0x200f000,0x2200000

def cases():
    data=bytes((i*37+19)&255 for i in range(32768))
    result=[]
    def add(mode,body,offset=0,count=0,group=100,device=0,serial=1,fail=0):
        result.append('|'.join(map(str,[mode,'-' if body is None else body.hex(),offset,count,group,device,serial,fail])))
    for size in [0,1,31,8191,8192,8193,16384,32768]:
        for count in sorted({0,1,size,max(0,size-1),min(32768,size+1)}):
            add('D',data[:size],count=count)
    for offset in [1,7,8191,8192,8193,32767,32768,32769,0xffffffff]:
        add('D',data,offset,16385)
    for device in range(4):
        for group in [0,255,256,0xffffffff]:add('D',data,11,16385,group,device,0xffffff)
    add('D',None,count=8193)
    add('D',data,count=32768,fail=1)
    fe=(ROOT/'local/game/fe.txt').read_bytes()
    for body in [fe,None,b'',b'FE=1\nLOCKSIM=-1\nNUMCARS=7\n',b'#NUMCARS=3\nNUMCARS=4\n',b'NUMCARS=9']:
        add('F',body)
    for selector in range(5):
        for body in [b'abc',None]:add('O',body,selector)
    rng=random.Random(0x580850)
    for variant in [0,1]:
        for nodes in [0,1,2,4,8,15]:
            pairs=[(rng.randrange(0x100000000),rng.randrange(256)) for _ in range(nodes)]
            if nodes>2:pairs[1]=pairs[0]
            add('Q',b''.join(struct.pack('<IB',*p) for p in pairs),variant)
    return result

def original(wire,module,data,functions,definitions):
    fields=wire.split('|');mode=fields[0];present=fields[1]!='-'
    filedata=bytes.fromhex(fields[1]) if present else b''
    offset,count,group,device,serial,readfail=map(int,fields[2:8]);count=min(count,32768)
    expected_name=b'fe.txt' if mode!='O' or offset==0 else b'root/fe.txt' if offset==1 else b'fallback/fe.txt' if offset==2 else b'missing'
    uc=Uc(UC_ARCH_X86,UC_MODE_32);base=int(module['image_base'],16);uc.mem_map(base,0x300000)
    for section in module['sections']:
        uc.mem_write(base+section['rva'],data[section['raw_offset']:section['raw_offset']+section['raw_size']])
    for address,size in [(IO,0x20000),(HEAP_ARENA,0x20000),(BUFFER,0x20000),(0x2000000,0x10000),(EXIT,0x1000)]:uc.mem_map(address,size)
    uc.mem_write(IO,b'\xcc'*0x20000);uc.mem_write(HEAP_ARENA,b'\xcc'*0x20000);uc.mem_write(BUFFER,b'\xcc'*0x20000)
    def words(p,n):return list(struct.unpack('<'+'I'*n,uc.mem_read(p,n*4)))
    def put(p,*values):uc.mem_write(p,struct.pack('<'+'I'*len(values),*[x&0xffffffff for x in values]))
    def string(p):
        if not p:return b''
        out=bytearray()
        while (byte:=uc.mem_read(p+len(out),1)[0]):
            out.append(byte)
            if len(out)>65536:raise RuntimeError('Unterminated fixture string')
        return bytes(out)
    def hxstr(p):return (string(p)+b'\0').hex() if p else ''
    def signed(x):return x if x<0x80000000 else x-0x100000000
    devices=IO+0x100;pool=IO+0x2000;physical=IO+0x4000
    put(0x6a5c7c,devices);uc.mem_write(devices,b'\0'*(4*112))
    put(0x6a5c80,0)
    for i in range(4):
        d=devices+i*112;put(d,1);put(d+0x34,0x5684c0);put(d+0x5c,d);put(d+0x64,d+0x64);put(d+0x68,serial if i==device else 1);put(d+0x6c,0xff)
    put(0x6a5c58,16,0,pool,pool+15*48,0,0,0);put(0x6a5c38,0,0,0,0,0,0,0)
    for i in range(16):put(pool+i*48,pool+(i+1)*48 if i<15 else 0);put(pool+i*48+12,0)
    put(0x6af084,physical);put(0x6af080,1);uc.mem_write(physical,b'\0'*32);put(physical,1|(device<<8),0xffffffff)
    put(0x6b4f20,*([0]*16));put(0x69cb00,0)
    put(0x5b21a4,EXIT+0x100) # Actual CALL [005b21a4] in 00592600; stdcall import.
    put(0x5b21b0,EXIT+0x300);put(0x5b2144,EXIT+0x400);put(0x5b2148,EXIT+0x500)
    if mode=='O':
        uc.mem_write(0x6af370,bytes([int(offset!=0)]));uc.mem_write(0x6af168,b'root/\0');uc.mem_write(0x6af26c,b'\0' if offset==4 else b'fallback/\0');put(0x6afbe4,EXIT+0x200)
    ranges=[(int(a,16),int(b,16)) for va in FUNCTIONS+[0x5ae3c0] for a,b in functions[f'{va:08x}']['ranges']]
    calls=[];event_states=[];coverage=set();object_used=0;resumes=[];backend_error=0
    def event_snapshot():
        state=bytearray(uc.mem_read(devices,4*112))
        for i in range(4):
            at=i*112+0x34
            if struct.unpack_from('<I',state,at)[0]:struct.pack_into('<I',state,at,0x5684c0)
        for i in range(16):
            o=pool+i*48;start=len(state);state.extend(uc.mem_read(o,48))
            context=words(o+0x1c,1)[0]
            if context not in (0,0xcccccccc):struct.pack_into('<I',state,start+0x1c,0x2200200)
        state.extend(uc.mem_read(0x6a5c58,28));state.extend(uc.mem_read(0x6a5c38,28));state.extend(uc.mem_read(0x6a5c80,4))
        return state.hex()
    endpoints={0x5322b0:1,0x5322c0:1,0x5321f0:0,0x5a0fbf:3,0x53c290:3,
               EXIT+0x300:1,EXIT+0x400:4,EXIT+0x500:3,0x568e90:1,0x568390:1,0x55fb30:1,
               0x55fc30:1,0x55fb90:1,0x55fce0:0,0x568900:3,0x592140:2,0x591df0:3,0x591fa0:3,0x591ce0:5,
               0x5924d0:2,0x592490:1,0x591980:1,0x55f780:1,0x5366e0:1,0x55f740:1,0x55fc60:1,0x55fc40:1,
               0x592290:1,0x561b80:1,0x565340:1,EXIT+0x100:1,EXIT+0x200:2,0x4119e0:1,0x411a80:1,0x411b40:1}
    saved_regs=[UC_X86_REG_EBX,UC_X86_REG_ECX,UC_X86_REG_EDX,UC_X86_REG_ESI,UC_X86_REG_EDI,UC_X86_REG_EBP,UC_X86_REG_EFLAGS]
    def hook(machine,p,length,user):
        nonlocal object_used,backend_error
        if p in FUNCTIONS:coverage.add(f'{p:08x}')
        if p==EXIT:machine.emu_stop();return
        if p==EXIT+0x600:
            sp,ret,registers=resumes.pop()
            for reg,value in registers.items():uc.reg_write(reg,value)
            uc.reg_write(UC_X86_REG_EAX,0);uc.reg_write(UC_X86_REG_ESP,sp+4);uc.reg_write(UC_X86_REG_EIP,ret)
            put(0x6a5c80,0);put(devices+device*112,1)
            return
        nargs=endpoints.get(p)
        if nargs is None:
            if not any(a<=p<=b for a,b in ranges):raise RuntimeError(f'Unexpected original code {p:08x}')
            return
        sp=uc.reg_read(UC_X86_REG_ESP)
        if p==0x5a0fbf and string(words(sp+8,1)[0])==b'%s%s':nargs=4
        ret,*args=words(sp,nargs+1);result=0
        if p in [0x5322b0,0x5322c0]:calls.append(['enter' if p==0x5322b0 else 'leave',args[0]])
        elif p==0x5321f0:calls.append(['create'])
        elif p==0x5a0fbf:
            fmt=string(args[1]);arg=string(args[2]);text=fmt.replace(b'%s',arg,1)
            if nargs==4:
                calls.append(['format',hxstr(args[1]),hxstr(args[2]),hxstr(args[3])]);text=text.replace(b'%s',string(args[3]),1)
            else:calls.append(['heap_format',hxstr(args[1]),hxstr(args[2])])
            uc.mem_write(args[0],text+b'\0')
        elif p==0x53c290:
            calls.append(['fill',*args]);uc.mem_write(args[0],bytes([args[1]&255])*args[2])
        elif p==EXIT+0x300:
            uc.mem_write(args[0],b'\0'*36);put(args[0]+4,4096);calls.append(['system_info',4096])
        elif p==EXIT+0x400:
            n=args[1];object_used=(object_used+4095)&~4095;result=IO+0x5000+object_used if n else 0
            if n:uc.mem_write(result,b'\0'*n);object_used+=n
            calls.append(['virtual_alloc',*args,result])
        elif p==EXIT+0x500:calls.append(['virtual_free',*args]);result=1
        elif p==0x568e90:calls.append(['route',hxstr(args[0])]);result=device
        elif p==0x568390:put(devices+args[0]*112,1)
        elif p==0x55fb30:
            event_states.append(event_snapshot());calls.append(['signal',args[0]])
            for i in range(4):
                if args[0]==devices+i*112:
                    put(0x6a5c80,0)
                    resumes.append((sp,ret,{reg:uc.reg_read(reg) for reg in saved_regs}))
                    put(sp-8,EXIT+0x600,i)
                    uc.reg_write(UC_X86_REG_ESP,sp-8);uc.reg_write(UC_X86_REG_EIP,0x568530)
                    return
        elif p==0x55fc30:event_states.append(event_snapshot());calls.append(['worker_signal',args[0]])
        elif p==0x55fb90:event_states.append(event_snapshot());calls.append(['worker_wait',args[0]]);put(0x6a5c80,1)
        elif p==0x55fce0:calls.append(['error']);result=backend_error
        elif p==0x568900:
            calls.append(['backend_open',hxstr(args[0]),args[1],args[2]])
            result=0xffffffff if present and string(args[0])==expected_name else 0
            backend_error=0 if result else 2
        elif p==0x592140:
            calls.append(['backend_seek',*args]);result=int(args[0]==0xffffffff and not readfail)
            backend_error=0 if result else 5
        elif p==0x591df0:
            calls.append(['backend_read',*args]);current=words(devices+device*112+0x20,1)[0]
            off=words(current+0x24,1)[0] if current else 0
            result=min(args[2],len(filedata)-off) if off<len(filedata) else 0
            if result:uc.mem_write(args[1],filedata[off:off+result])
            backend_error=0
        elif p==0x591fa0:calls.append(['backend_write',*args]);result=args[2];backend_error=0
        elif p==0x591ce0:
            calls.append(['backend_info',args[0],args[1],args[2],0x200ff00,args[4]])
            put(args[3],len(filedata));result=1;backend_error=0
        elif p in (0x5924d0,0x592490,0x591980):result=1
        elif p==0x55f780:calls.append(['current_thread']);result=0
        elif p==0x5366e0:calls.append(['pump']);result=0
        elif p==0x55f740:calls.append(['sleep',args[0]])
        elif p==0x55fc60:event_states.append(event_snapshot());calls.append(['wait_event',args[0]])
        elif p==0x55fc40:event_states.append(event_snapshot());calls.append(['reset_event',args[0]])
        elif p==0x592290:
            calls.append(['physical_close',args[0]]);result=1
            if args[0]==0xffffffff:uc.mem_write(physical,b'\0')
        elif p==0x561b80:calls.append(['exists',hxstr(args[0])]);result=int(present and string(args[0])==expected_name)
        elif p==EXIT+0x100:calls.append(['last_error',args[0]])
        elif p==EXIT+0x200:calls.append(['missing',hxstr(args[0]),signed(args[1])])
        elif p==0x565340:calls.append(['diagnostic',words(0x5deb78,1)[0],hxstr(args[0])])
        # FE action callbacks are unresolved, with no effects in this fixture.
        uc.reg_write(UC_X86_REG_EAX,result&0xffffffff)
        uc.reg_write(UC_X86_REG_ESP,sp+(4*(nargs+1) if p in [EXIT+0x100,EXIT+0x300,EXIT+0x400,EXIT+0x500] else 4));uc.reg_write(UC_X86_REG_EIP,ret)
    uc.hook_add(UC_HOOK_CODE,hook)
    def execute(va,args):
        put(STACK,EXIT,*args);uc.reg_write(UC_X86_REG_ESP,STACK);uc.emu_start(va,EXIT+1,count=8000000)
        if uc.reg_read(UC_X86_REG_EIP)!=EXIT or uc.reg_read(UC_X86_REG_ESP)!=STACK+4:raise RuntimeError(f'Original ABI/budget failure {va:08x}')
        return uc.reg_read(UC_X86_REG_EAX)
    uc.mem_write(BUFFER+0x10000,b'heap\0');execute(0x5697f0,[0,BUFFER+0x10000,HEAP_ARENA,65536,8,64,0,0,0,0,0,0])
    returns=[];streamhex='';globals_text='';actions='';lengths=[]
    if mode=='D':
        uc.mem_write(BUFFER+0x10000,b'fe.txt\0');put(BUFFER+0x10100,0)
        ok=execute(0x533b90,[BUFFER+0x10000,1,group,BUFFER+0x10100])&255
        handle=words(BUFFER+0x10100,1)[0]
        if ok:returns=[execute(0x533bf0,[handle,offset,BUFFER,count,group]),signed(execute(0x533de0,[handle,group])),execute(0x533da0,[handle,group])]
    elif mode=='O':
        uc.mem_write(BUFFER+0x10000,b'fe.txt\0');put(BUFFER+0x10100,0x11223344)
        ok=execute(0x59e040,[BUFFER+0x10000,1,group,BUFFER+0x10100])&255;handle=words(BUFFER+0x10100,1)[0]
        returns=[ok,handle]
        if ok:returns.append(execute(0x533da0,[handle,group]))
    elif mode=='Q':
        nodes=len(filedata)//5;queue=devices+0x24
        for i in range(nodes):
            opid,g=struct.unpack_from('<IB',filedata,i*5);node=pool+i*48;put(node,0,opid);uc.mem_write(node+17,bytes([g]))
            returns.append(execute(0x5684c0,[node,0]));execute(0x580730 if offset else 0x580850,[queue,node])
        returns.append(execute(0x580ad0,[queue,0,0]))
        if nodes:
            returns.append(execute(0x580ad0,[queue,0x567bf0,words(pool+4,1)[0]]))
            returns.append(execute(0x580c10,[queue,0x567bf0,words(pool+(nodes//2)*48+4,1)[0]]))
            returns.append(execute(0x580930,[queue,pool+(nodes-1)*48]))
        returns.append(execute(0x580930,[queue,pool+15*48]));execute(0x580730,[queue,0]);execute(0x580850,[queue,0])
        while (node:=execute(0x580790,[queue])):returns.append(node)
        returns.append(execute(0x580790,[queue]));returns.append(execute(0x580c10,[queue,0,0]))
    elif mode=='F':
        stream=execute(0x4b6660,[0,0]);p=stream
        while words(p,1)[0]:
            n=execute(0x4b4cd0,[p]);lengths.append(n);p+=n*4
            if len(lengths)>4096:raise RuntimeError('Invalid FE stream')
        streamhex=bytes(uc.mem_read(stream,p-stream+4)).hex()
        for pos in [stream+sum(lengths[:i])*4 for i in range(len(lengths))]:execute(0x4b4b80,[pos]);execute(0x4b4cd0,[pos])
        globals_text=','.join(str(words(d['target'],1)[0]) for d in definitions if d['opcode'] and d['target'])
        actions=bytes(uc.mem_read(0x5e9130,0x21e*4)).hex()
    else:raise RuntimeError('Unknown fixture mode')
    snapshot=bytearray(uc.mem_read(IO,0x5000))
    for i in range(16):
        pos=0x2000+i*48
        if words(pool+i*48+0x1c,1)[0] not in [0,0xcccccccc]:struct.pack_into('<I',snapshot,pos+0x1c,0x2200200)
    return {'returns':returns,'buffer':bytes(uc.mem_read(BUFFER,count+16)).hex(),'io':snapshot.hex(),
            'objects':bytes(uc.mem_read(IO+0x5000,object_used)).hex(),
            'free_operations':bytes(uc.mem_read(0x6a5c58,28)).hex(),'free_auxiliary':bytes(uc.mem_read(0x6a5c38,28)).hex(),
            'heap':bytes(uc.mem_read(HEAP_ARENA,65536)).hex(),'calls':calls,'event_states':event_states,'stream':streamhex,'globals':globals_text,'actions':actions,'lengths':lengths},coverage

def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--limit',type=int)
    parser.add_argument('--report-dir',type=Path,default=RUN);args=parser.parse_args()
    module=next(json.loads(l) for l in (ROOT/'research/binary-index/static/binaries.jsonl').read_text().splitlines() if json.loads(l)['file']=='Porsche.exe')
    data=(ROOT/'local/game'/module['path']).read_bytes()
    if hashlib.sha256(data).hexdigest()!=module['sha256']:raise RuntimeError('Original SHA differs')
    functions={r['entry_va']:r for r in map(json.loads,(ROOT/'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/functions.jsonl').read_text().splitlines())}
    functions.update({r['entry_va']:r for r in manual_records(module['sha256'])})
    definitions=json.loads((ROOT/'iterations/v2/001-original-recovery/runs/003-fe-stream/tables.json').read_text())['tables']['definitions']['rows']
    inputs=cases();inputs=inputs[:args.limit] if args.limit else inputs
    probe=ROOT/'local/builds/v2/001-original-recovery/bin/Release/files_probe.exe'
    native=subprocess.run([str(probe)],input='\n'.join(inputs)+'\n',text=True,capture_output=True,check=True,timeout=120)
    outputs=[json.loads(line) for line in native.stdout.splitlines()]
    if len(inputs)!=len(outputs):raise RuntimeError('Native output count differs')
    coverage=set();fixtures=[]
    for i,(wire,actual) in enumerate(zip(inputs,outputs)):
        expected,hit=original(wire,module,data,functions,definitions);coverage|=hit
        if expected!=actual:
            path=ROOT/'local/reports/v2-files-mismatch.json';path.write_text(json.dumps({'case':i,'input':wire,'expected':expected,'actual':actual},indent=2)+'\n')
            raise RuntimeError(f'Case {i} differs: {[k for k in expected if expected[k]!=actual.get(k)]}; {path}')
        fixtures.append({'input':wire,'output_sha256':hashlib.sha256(json.dumps(expected,sort_keys=True).encode()).hexdigest(),'records':len(expected['lengths']),'stream_bytes':len(expected['stream'])//2})
        if wire.startswith('F|') and wire.split('|',2)[1]==(ROOT/'local/game/fe.txt').read_bytes().hex():
            if (len(expected['lengths']),len(expected['stream'])//2)!=(23,188):
                raise RuntimeError('Real fe.txt did not produce 23 records / 188 bytes')
    print(json.dumps({'cases':len(inputs),'functions':sorted(coverage),'native_equal_original':True}))
    if args.limit:return
    source=ROOT/'iterations/v2/001-original-recovery/source'
    names={'files_probe.cpp','fe_stream.hpp','heap.hpp','files.hpp','file_device.hpp','file_worker.hpp','file_wait.hpp',
           'fe_stream.cpp','heap.cpp','heap_callbacks.cpp','io_lists.cpp','io_worker_lists.cpp','files.cpp',
           'file_pages.cpp','file_device.cpp','file_worker.cpp','file_wait.cpp'}
    paths=[p for p in source.rglob('*') if p.is_file() and p.name in names]
    report={'schema':1,'sha256':module['sha256'],'function_vas':sorted(coverage),'cases':len(inputs),'native_cpp_equal_original_x86':True,
            'binary_matched':False,'game_launch_verified':False,
            'comparison':'Whole heap, IO/device/operation state, copied names, buffers, streams, global words, ordered boundary calls and state at each event. Stack contexts and recovered code pointers use documented VA identities.',
            'boundaries':{'worker':'Original worker and wait execute synchronously through the event fixture; backend disk/archive calls, thread identity, pump and platform event semantics remain recording endpoints.',
                          'Win32_allocation':'Original 0056e5f0/0056e640 execute; GetSystemInfo/VirtualAlloc/VirtualFree are recording OS endpoints, without OS lifetime or failure fidelity claims.',
                          'OS_CRT':'Recording lock/format/fill/physical close/exists/routing/diagnostic endpoints; original CRT ASCII comparator executes in C locale.',
                          'FE_callbacks':'No effects at 004119e0/00411a80/00411b40 test endpoints; callback semantics remain unrecovered.'},
            'source_sha256':{str(p.relative_to(ROOT)).replace('\\','/'):hashlib.sha256(p.read_bytes().replace(b'\r\n',b'\n')).hexdigest() for p in paths},
            'probe_sha256':hashlib.sha256(probe.read_bytes()).hexdigest(),'fixtures':fixtures}
    args.report_dir.mkdir(parents=True,exist_ok=True);(args.report_dir/'verification.json').write_text(json.dumps(report,indent=2)+'\n',newline='\n')
    (args.report_dir/'source-functions.jsonl').write_text(''.join(json.dumps({'sha256':module['sha256'],**functions[va]})+'\n' for va in sorted(coverage)),newline='\n')
    calls=[json.loads(l) for l in (ROOT/'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/calls.jsonl').read_text().splitlines()]
    (args.report_dir/'source-calls.jsonl').write_text(''.join(json.dumps(r)+'\n' for r in calls if r.get('from_function') in coverage),newline='\n')

if __name__=='__main__':main()
