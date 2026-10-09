"""Run069: differential test for the original window event ring."""
import argparse, hashlib, json, subprocess, sys
from pathlib import Path

from v2_source_dependencies import source_hashes

ROOT=Path(__file__).resolve().parents[2]
RUN=ROOT/'iterations/v2/001-original-recovery/runs/069-window-event-queue'
SHA='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ESP,UC_X86_REG_EIP

ENQUEUE,DEQUEUE=0x53a9e0,0x53aa60
STACK,EXIT=0x3108000,0x3200000
LOCK=0x3105000
RING=0x69e4e0

def put(u,a,v):u.mem_write(a,(v&0xffffffff).to_bytes(4,'little'))
def word(u,a):return int.from_bytes(u.mem_read(a,4),'little')
def translate(payload,typ):return (payload ^ (typ*13) ^ 0x39)&0xff

def cases():
    out=[]
    def blank():return bytearray((i*37+11)&255 for i in range(128))
    # Empty, one record, skipped zero translation then a translated record,
    # direct signed 16-bit value, zero stored value, and wraparound consumption.
    for cap,read,write,records in [
        (4,0,0,[]),
        (4,0,1,[(0x12,0x23,0)]),
        (5,3,0,[(0,0x39,0),(0x12,0x23,0)]),
        (4,1,2,[(0xabcd,0x45,7)]),
        (4,0,2,[(0x8001,0x91,2),(0x22,0x11,0)]),
        (4,3,1,[(0,0x39,0),(0,0x40,0)]),
    ]:
        ring=blank()
        idx=read
        for value,payload,typ in records:
            off=idx*4;ring[off:off+4]=bytes((typ&255,payload&255,value&255,(value>>8)&255));idx=(idx+1)%cap
        out.append((1,cap,read,write,LOCK,0,0,0,bytes(ring)))

    # Enqueue: different capacities, ordinary insertion, full overwrite, and
    # slots near the physical ring end. Padding bytes are deliberately nonzero.
    for cap,read,write,args in [
        (1,0,0,(0x1234,0x56,0x78)),
        (2,0,1,(0x00ab,0x01cd,0x02ef)),
        (4,0,3,(0x9876,0x45,0x12)),
        (4,3,2,(0xffff,0x101,0x102)),
        (32,30,31,(0x8000,0x80,0x7f)),
        (32,0,0,(0,0,0)),
    ]:
        ring=blank()
        out.append((0,cap,read,write,LOCK,*args,bytes(ring)))
    # Exercise every cursor pair across representative capacities, including
    # the capacity-1 ring where advancing wraps to the same cursor.
    for cap in (1,2,4,8,32):
        for read in range(cap):
            for write in range(cap):
                ring=blank()
                out.append((0,cap,read,write,LOCK,0x5a5a,(read*7+write)&255,
                            (read+write)&255,bytes(ring)))
    # Exercise each nonempty starting read cursor at representative sizes.
    for cap in (2,4,8,32):
        for read in range(cap):
            ring=blank();off=read*4
            ring[off:off+4]=bytes((0x12,0x34,1,0))
            out.append((1,cap,read,(read+1)%cap,LOCK,0,0,0,bytes(ring)))
    return out

def run_original(module,data,c):
    op,cap,read,write,lock,value,payload,typ,ring=c
    u=Uc(UC_ARCH_X86,UC_MODE_32);u.mem_map(0x400000,0x300000)
    for sec in module['sections']:u.mem_write(0x400000+sec['rva'],data[sec['raw_offset']:sec['raw_offset']+sec['raw_size']])
    u.mem_map(0x3100000,0x10000);u.mem_map(EXIT,0x1000);u.mem_map(0x3210000,0x1000)
    u.mem_write(EXIT,b'\xc3'*0x1000)
    put(u,0x69e564,lock);put(u,0x69e560,cap);put(u,0x69e0d8,read);put(u,0x69e568,write)
    u.mem_write(RING,ring)
    events=[]
    def body_hook(m,address,size,_):
        if address not in (0x5322b0,0x5322c0,0x560080):return
        sp=m.reg_read(UC_X86_REG_ESP);ret=word(m,sp)
        if address==0x560080:
            # Original boundary consumes two cdecl args (payload, type).
            event_payload,event_type=word(m,sp+4),word(m,sp+8)
            events.append(('T',event_payload,event_type))
            m.reg_write(UC_X86_REG_EAX,translate(event_payload,event_type))
        else:
            events.append(('E' if address==0x5322b0 else 'L',word(m,sp+4)))
        m.reg_write(UC_X86_REG_ESP,sp+4);m.reg_write(UC_X86_REG_EIP,ret)
    # Use just the original call targets, preserving the call sites and caller cleanup.
    u.hook_add(UC_HOOK_CODE,body_hook)
    args=[EXIT]
    if op==0:args += [value,payload,typ]
    for i,v in enumerate(args):put(u,STACK+i*4,v)
    u.reg_write(UC_X86_REG_ESP,STACK)
    u.emu_start(ENQUEUE if op==0 else DEQUEUE,EXIT,count=10000)
    out_ring=bytes(u.mem_read(RING,128))
    ev=','.join((f'{e[0]}{e[1]:x}' if e[0] in ('E','L') else f'T{e[1]:x}:{e[2]:x}') for e in events)
    return (u.reg_read(UC_X86_REG_EAX),word(u,0x69e0d8),word(u,0x69e568),ev,out_ring)

def native_line(c):
    op,cap,read,write,lock,value,payload,typ,ring=c
    return f'{op} {cap} {read} {write} {lock:x} {value:x} {payload:x} {typ:x} {ring.hex()}\n'

def main():
    p=argparse.ArgumentParser();p.add_argument('--probe',type=Path,default=ROOT/'local/builds/v2/window-event-queue-069/bin/Release/window_event_queue_probe.exe');p.add_argument('--report-dir',type=Path,default=RUN);a=p.parse_args()
    module=next(json.loads(x) for x in (ROOT/'research/binary-index/static/binaries.jsonl').read_text(encoding='utf8').splitlines() if json.loads(x)['file']=='Porsche.exe')
    data=(ROOT/'local/game'/module['path']).read_bytes();assert hashlib.sha256(data).hexdigest()==SHA
    inputs=cases();proc=subprocess.run([str(a.probe)],input=''.join(native_line(c) for c in inputs),text=True,capture_output=True,check=True)
    lines=proc.stdout.splitlines();assert len(lines)==len(inputs),(len(lines),len(inputs));fixtures=[]
    for c,line in zip(inputs,lines):
        fields=line.split();actual=(int(fields[0]),int(fields[1]),int(fields[2]),fields[3],bytes.fromhex(fields[4]))
        expected=run_original(module,data,c)
        # Enqueue's original EAX is whatever the typed lock-leave edge leaves
        # behind, so only its state and ordered boundary trace are meaningful.
        if c[0]==0:actual=(expected[0],*actual[1:])
        if actual!=expected:raise RuntimeError(f'{c[:8]} expected={expected[:4]} actual={actual[:4]} ring={expected[4].hex()} != {actual[4].hex()}')
        fixtures.append({'op':'dequeue' if c[0] else 'enqueue','capacity':c[1],'read':c[2],'write':c[3],'args':c[5:8],'events':actual[3]})
    deps=['iterations/v2/001-original-recovery/'+x for x in ('source/include/porsche/window_event_queue.hpp','source/include/porsche/window_messages.hpp','source/include/porsche/heap.hpp','source/recovered/Porsche.exe/window_event_queue.cpp','source/recovered/window_event_queue_probe.cpp','runs/069-window-event-queue/CMakeLists.txt','runs/069-window-event-queue/README.md')]+['scripts/research/verify-v2-window-event-queue.py']
    report={'schema':1,'sha256':SHA,'function_vas':['0053a9e0','0053aa60'],'full_function_vas':['0053a9e0','0053aa60'],'partial_function_vas':[],'cases':len(inputs),'native_cpp_equal_original_x86':True,'binary_matched':False,'game_launch_verified':False,'boundaries':'005322b0/005322c0 lock enter/leave are recorded typed boundaries; 00560080 input translation is an explicit typed boundary with deterministic fixture responses. Enqueue EAX is not a defined status result. Capacities are limited to initialized ring range 1..32.','source_sha256':{x:hashlib.sha256((ROOT/x).read_bytes().replace(b'\r\n',b'\n')).hexdigest() for x in deps},'probe_sha256':hashlib.sha256(a.probe.read_bytes()).hexdigest(),'fixtures':fixtures}
    report['source_sha256']=source_hashes(report['source_sha256'].keys(),compiled_sources=['iterations/v2/001-original-recovery/source/recovered/Porsche.exe/window_event_queue.cpp','iterations/v2/001-original-recovery/source/recovered/window_event_queue_probe.cpp'])
    a.report_dir.mkdir(parents=True,exist_ok=True);(a.report_dir/'verification.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf8')
    print(json.dumps({'cases':len(inputs),'function_vas':report['function_vas'],'native_cpp_equal_original_x86':True}))
if __name__=='__main__':main()
