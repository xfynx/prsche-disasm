from v2_source_dependencies import source_hashes
#!/usr/bin/env python3
import argparse, hashlib, json, struct, subprocess, sys
from pathlib import Path

ROOT=Path(__file__).resolve().parents[2]
ITER=ROOT/'iterations/v2/001-original-recovery'
RUN=ITER/'runs/063-render-mode'
SHA='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ECX,UC_X86_REG_EIP,UC_X86_REG_ESP

STACK,EXIT=0x3101000,0x3200000
DISPLAY,DRIVER,MODES,VTABLE,OUT=0x3103000,0x3104000,0x3105000,0x3106000,0x3107000
V9,APPLY,ALTERNATE,CLOCK,SETSTATE=0x3300000,0x3300010,0x3300020,0x3300030,0x3300040
def put(u,a,v):u.mem_write(a,struct.pack('<I',v&0xffffffff))
def get(u,a):return struct.unpack('<I',u.mem_read(a,4))[0]

def cases():
    words=[800,600,15,0x44,0x55,3,0x77,0x88,0x99,0xaa]
    base=dict(index=1,fullscreen=0,seed=0,prev=0,clock=0x12345678,s5c=0,s60=0,s68=0,s6c=0,s70=2,s78=1,s80=20,sa6=0,words=words)
    cs=[]
    for fullscreen in (0,1):
        c=base.copy();c.update(op=0,fullscreen=fullscreen);cs.append(c)
    for fullscreen,index in ((0,0),(0,2),(1,1)):
        c=base.copy();c.update(op=1,fullscreen=fullscreen,index=index);cs.append(c)
    for mode in (0,1,2,3,-1):
      for setting60 in (0,1,2):
        for table_index in range(4):
          c=base.copy();c.update(op=2,seed=0,s5c=1,s60=setting60,s68=2,s6c=mode,s70=table_index,s78=1,s80=25,sa6=int(mode==3),words=[0]*10)
          cs.append(c)
    c=base.copy();c.update(op=2,seed=0,clock=0xfedcba98,s5c=0,s60=0,s68=0,s6c=0,s70=0,s78=0,s80=0,sa6=0,words=[0]*10);cs.append(c)
    c=base.copy();c.update(op=2,prev=1,s5c=0,s60=2,s68=1,s6c=3,s70=1,s78=0,s80=25,sa6=0,words=[0]*10);cs.append(c)
    # Existing-state alternate branch must delegate without touching the base branch.
    c=base.copy();c.update(op=2,seed=0x5a,s5c=0,s60=0,s68=0,s6c=0,s70=1,s78=0,s80=5,sa6=0,words=[0]*10);cs.append(c)
    return cs

def module_data():
    entries=[json.loads(x) for x in (ROOT/'research/binary-index/static/binaries.jsonl').read_text(encoding='utf8').splitlines()]
    m=next(x for x in entries if x['file']=='Porsche.exe')
    data=(ROOT/'local/game'/m['path']).read_bytes()
    if hashlib.sha256(data).hexdigest()!=SHA:raise RuntimeError('original binary SHA mismatch')
    return m,data

def original(m,data,c):
    u=Uc(UC_ARCH_X86,UC_MODE_32);u.mem_map(0x400000,0x300000)
    for sec in m['sections']:
        if sec['raw_size']:u.mem_write(0x400000+sec['rva'],data[sec['raw_offset']:sec['raw_offset']+sec['raw_size']])
    # Redirect complete out-of-scope callees before execution; a code hook at a
    # mapped entry fires before, but does not suppress, the original instruction.
    for source,target in ((0x44e890,APPLY),(0x44f020,ALTERNATE),(0x555bc0,CLOCK)):
        u.mem_write(source,b'\xe9'+struct.pack('<i',target-(source+5)))
    u.mem_map(0x3100000,0x10000);u.mem_map(EXIT,0x1000);u.mem_map(0x3300000,0x1000)
    u.mem_write(EXIT,b'\xc3'*0x1000)
    for a,v in ((0x628130,DISPLAY),(DISPLAY+0x60,c['fullscreen']),(DISPLAY+0x70,DRIVER),
                (DRIVER,VTABLE),(DRIVER+8,MODES),(VTABLE+0x24,V9),(0x6bd918,SETSTATE)):
        if a!=DISPLAY+0x60 and a!=DISPLAY+0x70:put(u,a,v)
        else:put(u,a,v)
    for rec in range(4):
        for i,w in enumerate(c['words']):put(u,MODES+rec*0x28+i*4,w)
    for i in range(0x71):u.mem_write(0x619790+i,bytes([c['seed']&255]))
    u.mem_write(0x619799,bytes([c['prev']&0xff]))
    for va,val in ((0x657d5c,c['s5c']),(0x657d60,c['s60']),(0x657d68,c['s68']),
       (0x657d6c,c['s6c']),(0x657d70,c['s70']),(0x657d78,c['s78']),(0x657d80,c['s80']),
       (0x5ce908,0x66666666),(0x5deb1c,0x55555555),(0x69dd1d,0x77),
       (0x619780,0x11111111),(0x619784,0x22222222),(0x619788,0x33333333),(0x61978c,0x44444444)):
        put(u,va,val)
    u.mem_write(0x6197a6,bytes([c['sa6']&0xff]))
    u.mem_write(OUT,struct.pack('<10I',*([0xa5a5a5a5]*10)))
    events=[]
    def hook(mu,addr,_size,_):
        if addr not in (V9,APPLY,ALTERNATE,CLOCK,SETSTATE):return
        sp=mu.reg_read(UC_X86_REG_ESP);ret=get(mu,sp)
        if addr==V9:events.append('vslot9');mu.reg_write(UC_X86_REG_EAX,0)
        elif addr==APPLY:events.append('apply');mu.reg_write(UC_X86_REG_EAX,0)
        elif addr==ALTERNATE:events.append('alternate');mu.reg_write(UC_X86_REG_EAX,0)
        elif addr==CLOCK:events.append('clock');mu.reg_write(UC_X86_REG_EAX,c['clock'])
        else:events.append('setstate');mu.reg_write(UC_X86_REG_EAX,0)
        mu.reg_write(UC_X86_REG_ESP,sp+(12 if addr==SETSTATE else 4));mu.reg_write(UC_X86_REG_EIP,ret)
    u.hook_add(UC_HOOK_CODE,hook)
    entry={0:0x44e720,1:0x44ebf0,2:0x44ed10}[c['op']]
    put(u,STACK,EXIT)
    args=([c['index'],OUT] if c['op']==0 else [c['index']] if c['op']==1 else [])
    for i,v in enumerate(args):put(u,STACK+4+i*4,v)
    u.reg_write(UC_X86_REG_ESP,STACK)
    try:u.emu_start(entry,EXIT,count=100000)
    except Exception as exc:raise RuntimeError(f"x86 {c}: EIP={u.reg_read(UC_X86_REG_EIP):08x}, events={events}") from exc
    globals_=[get(u,0x619780),get(u,0x619784),get(u,0x619788),get(u,0x61978c),get(u,0x5deb1c),get(u,0x5ce908),u.mem_read(0x69dd1d,1)[0]]
    out=list(struct.unpack('<10I',u.mem_read(OUT,40)))
    state=list(u.mem_read(0x619790,0x71))
    return {'out':out,'globals':globals_,'counts':[events.count('vslot9'),events.count('apply'),events.count('alternate'),events.count('setstate')],
      'state':state,'stack_delta':u.reg_read(UC_X86_REG_ESP)-STACK,'events':events}

def main():
    ap=argparse.ArgumentParser();ap.add_argument('--probe',type=Path,default=ROOT/'local/builds/v2/render-mode-063/bin/Release/render_mode_probe.exe');ap.add_argument('--report',type=Path,default=RUN/'verification.json');args=ap.parse_args()
    m,data=module_data();inputs=cases()
    feed=''.join(' '.join(map(str,[c['op'],c['index'],c['fullscreen'],c['seed'],c['prev'],c['clock'],c['s5c'],c['s60'],c['s68'],c['s6c'],c['s70'],c['s78'],c['s80'],c['sa6'],*c['words']]))+'\n' for c in inputs)
    proc=subprocess.run([str(args.probe)],input=feed,text=True,capture_output=True,check=True)
    rows=proc.stdout.splitlines()
    if len(rows)!=len(inputs):raise RuntimeError(f'probe rows {len(rows)} != cases {len(inputs)}; stderr={proc.stderr}')
    fixtures=[]
    for c,line in zip(inputs,rows):
        native=json.loads(line);expect=original(m,data,c)
        if expect['stack_delta']!=4:raise RuntimeError(f"unexpected original stack delta {c}: {expect['stack_delta']}")
        observed={k:native[k] for k in ('out','globals','counts','state')}
        wanted={k:expect[k] for k in observed}
        if observed!=wanted:raise RuntimeError(f"case {c}: original={wanted}; native={observed}; x86 events={expect['events']}")
        fixtures.append({'input':c,'output':observed,'stack_delta':expect['stack_delta'],'x86_events':expect['events']})
    rel=lambda x:x.resolve().relative_to(ROOT).as_posix()
    deps=[ITER/'source/include/porsche/render_mode.hpp',ITER/'source/include/porsche/render_display.hpp',ITER/'source/include/porsche/render_startup.hpp',ITER/'source/include/porsche/render_objects.hpp',ITER/'source/include/porsche/render_activate.hpp',ITER/'source/recovered/Porsche.exe/render_mode.cpp',ITER/'source/recovered/render_mode_probe.cpp',RUN/'CMakeLists.txt',RUN/'README.md',ROOT/'research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm',ROOT/'research/v2/binaries/Porsche.exe-ddd748fdbe6d/decompiled.c',Path(__file__).resolve()]
    report={'schema':1,'binary':'Porsche.exe','sha256':SHA,'entry_vas':['0044e720','0044ebf0','0044ed10','00535b40'],'coverage':'full three assigned consumers; unresolved typed apply/alternate/driver/clock/setstate boundaries','full_function_vas':['0044e720','0044ebf0','0044ed10','00535b40'],'partial_function_vas':[],'cases':len(inputs),'native_cpp_equal_original_x86':True,'game_launch_verified':False,'boundaries':'0x44e720/0x44ebf0 mode selection uses the typed driver vtable+0x24 boundary (original thiscall, no stack args). 0x44ebf0 delegates the original 0x44e890 engine state application. 0x44ed10 preserves alternate initializer 0x44f020 and clock 0x555bc0, plus stdcall renderer state API IAT slot 0x6bd918 (two DWORD args). The small 0x535b40 callee is recovered as the exact low-byte store to 0x69dd1d. Same-VA display pointer, mode globals and clock use canonical external owners.','source_sha256':{rel(p):hashlib.sha256(p.read_bytes().replace(b'\r\n',b'\n')).hexdigest() for p in deps},'probe_sha256':hashlib.sha256(args.probe.read_bytes()).hexdigest(),'fixtures':fixtures}
    report['source_sha256']=source_hashes(report['source_sha256'].keys(),compiled_sources=['iterations/v2/001-original-recovery/source/recovered/Porsche.exe/render_mode.cpp', 'iterations/v2/001-original-recovery/source/recovered/render_mode_probe.cpp'])
    args.report.parent.mkdir(parents=True,exist_ok=True);args.report.write_text(json.dumps(report,indent=2)+'\n',encoding='utf8')
    print(f"verified {len(inputs)} x86/native renderer mode cases; report {rel(args.report)}")
if __name__=='__main__':main()
