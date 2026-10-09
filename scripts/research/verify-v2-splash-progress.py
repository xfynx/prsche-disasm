"""Compare the recovered 004a4a70 splash/progress consumer to original x86."""
import argparse
import hashlib
import json
import struct
import subprocess
import sys
from pathlib import Path

ROOT=Path(__file__).resolve().parents[2]
RUN=ROOT/'iterations/v2/001-original-recovery/runs/095-splash-progress'
SHA='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ECX,UC_X86_REG_EIP,UC_X86_REG_ESP,UC_X86_REG_FPCW
from v2_source_dependencies import source_hashes

STACK=0x3108000;EXIT=0x3200000;BOUNDARY=0x3210000
CONFIG=0x3400000;BG=0x3500000;ALT=0x3510000;LOAD=0x3520000;TEXT=0x3530000
PLAYER=0x3540000;SELECTION=0x3541000;LOCK_CONTEXT=0x3542000;TEXTURE=0x3543000

def case(name,phase,enabled=0,texture=False,game_type=0,no_loading=0,fmt=0,
         width=640,height=480,net=0,config_live=0,alt_exists=0,text_exists=0,
         wait=0,render_format=0,count=0,player_mode=0,mirror=0,reverse=0,
         label=1,player_value=4):
    return dict(name=name,phase=phase,enabled=enabled,texture=texture,game_type=game_type,
        no_loading=no_loading,format=fmt,width=width,height=height,net=net,
        config_live=config_live,alt_exists=alt_exists,text_exists=text_exists,
        wait=wait,render_format=render_format,count=count,player_mode=player_mode,
        mirror=mirror,reverse=reverse,label=label,player_value=player_value)

# The cases vary phase gates, static texture creation/reuse, the no-loading
# guard, FE render variants, both resource-exists results, network config byte
# predicates, wait-loop order, mirror/reverse modes, list count and player lookup.
CASES=[
    case('phase0_default',0),
    case('phase0_existing_texture',0,enabled=1,texture=True,width=800,height=600),
    case('phase0_no_loading',0,no_loading=1),
    case('phase1_disabled',1),
    case('phase1_enabled',1,enabled=1,width=801,height=601),
    case('phase2_enabled',2,enabled=1),
    case('phase3_enabled',3,enabled=1),
    case('phase4_enabled',4,enabled=1,game_type=4,render_format=0x209),
    case('phase4_other_format',4,enabled=1,game_type=4,render_format=0x222),
    case('phase5_mode0_alt_missing',5,enabled=1,alt_exists=0),
    case('phase5_mode0_alt_present',5,enabled=1,alt_exists=1,mirror=0),
    case('phase5_mode4_variant',5,enabled=1,game_type=4,render_format=0x20a,
         alt_exists=1,mirror=1,reverse=1),
    case('phase5_mode9_skips_background',5,enabled=1,game_type=9,alt_exists=1),
    case('phase6_enabled',6,enabled=1),
    case('phase7_enabled',7,enabled=1),
    case('phase8_enabled',8,enabled=1),
    case('phase9_enabled',9,enabled=1),
    case('phase10_disable',10,enabled=1,texture=True),
    case('negative_disabled',-1),
    case('negative_enabled',-1,enabled=1,texture=True),
    case('network_valid_phase1',1,enabled=1,net=9,config_live=1,count=0),
    case('network_config_not_live',1,enabled=1,net=9,config_live=0,count=0),
    case('network_bad_be',1,enabled=1,net=8,config_live=1,count=0),
    case('network_bad_bf',1,enabled=1,net=11,config_live=1,count=0),
    case('network_negative_dc',1,enabled=1,net=13,config_live=1,count=0),
    case('network_phase5_loading_text',5,enabled=1,net=9,config_live=1,
         text_exists=1,player_mode=8,count=0),
    case('network_wait_then_continue',2,enabled=1,net=9,config_live=1,wait=1),
    case('network_player_missing',2,enabled=1,net=9,config_live=1,count=1,
         player_mode=0,label=3,player_value=17),
    case('network_player_hidden',2,enabled=1,net=9,config_live=1,count=1,
         player_mode=1,label=2,player_value=91),
    case('network_player_visible_empty',2,enabled=1,net=9,config_live=1,count=1,
         player_mode=3,label=6,player_value=123),
    case('network_player_visible_selected',2,enabled=1,net=9,config_live=1,count=1,
         player_mode=7,label=9,player_value=0x10203),
    case('network_player_visible_negative_progress',2,enabled=1,net=9,config_live=1,count=1,
         player_mode=7,label=5,player_value=0xffffffff),
    case('network_player_visible_max_progress',2,enabled=1,net=9,config_live=1,count=1,
         player_mode=7,label=3,player_value=0x7fffffff),
    case('network_player_visible_min_progress',2,enabled=1,net=9,config_live=1,count=1,
         player_mode=7,label=4,player_value=0x80000000),
    case('network_phase5_dispatch_and_layers',5,enabled=1,net=9,config_live=1,
         text_exists=1,player_mode=8,count=1,label=4,player_value=500),
]

def put(u,a,v):u.mem_write(a,struct.pack('<I',v&0xffffffff))
def put16(u,a,v):u.mem_write(a,struct.pack('<h',((v+0x8000)&0xffff)-0x8000))
def get(u,a):return struct.unpack('<I',u.mem_read(a,4))[0]
def s32(v):return struct.unpack('<i',struct.pack('<I',v&0xffffffff))[0]
def cstr(u,a):
    if not a:return '<null>'
    out=bytearray()
    for n in range(1024):
        b=u.mem_read(a+n,1)[0]
        if not b:break
        out.append(b)
    return out.decode('ascii','replace')
def write_cstr(u,a,value):u.mem_write(a,value.encode('ascii')+b'\0')

def normalize(a):
    for base,name in ((BG,'bg'),(ALT,'alt'),(LOAD,'loading'),(TEXT,'text'),(TEXTURE,'texture')):
        if base<=a<base+0x1000:return f'{name}+{a-base}'
    if PLAYER<=a<PLAYER+0x1000:return 'player'
    if SELECTION<=a<SELECTION+0x1000:return 'selection'
    if a==0x4444:return 'lock-handle'
    return 'ptr'

def fill_resource(u,base):
    u.mem_write(base,bytes(0x1000))
    for field in range(0x0c,0x380,8):
        slot=(field-0x0c)//8
        put(u,base+field,0x500+slot*0x10)
    for offset in range(0x500,0xf00,0x10):
        put16(u,base+offset+4,offset&0x7f)
        put16(u,base+offset+6,(offset>>1)&0x7f)
        put16(u,base+offset+8,(offset&0x3f)-0x20)
        put16(u,base+offset+10,(offset&0x1f)-0x10)

def resource_for(path):
    if 'MLoading' in path:return LOAD,'loading'
    if 'loadtext' in path:return TEXT,'text'
    if 'ALT\\' in path:return ALT,'alt'
    return BG,'bg'

def native_line(c):
    vals=(c['name'],c['phase'],c['enabled'],int(c['texture']),c['game_type'],c['no_loading'],
      c['format'],c['width'],c['height'],c['net'],c['config_live'],c['alt_exists'],
      c['text_exists'],c['wait'],c['render_format'],c['count'],c['player_mode'],
      c['mirror'],c['reverse'],c['label'],c['player_value'])
    return ' '.join(str(v) for v in vals)+'\n'

def original(module,image,c):
    u=Uc(UC_ARCH_X86,UC_MODE_32);u.mem_map(0x400000,0x300000)
    # Unicorn does not consistently reset x87 state between isolated machines;
    # Windows/x86 architectural reset state is 0x037f (extended, nearest).
    u.reg_write(UC_X86_REG_FPCW,0x037f)
    for sec in module['sections']:
        if sec['raw_size']:
            u.mem_write(0x400000+sec['rva'],image[sec['raw_offset']:sec['raw_offset']+sec['raw_size']])
    for base,size in ((0x3100000,0x10000),(EXIT,0x1000),(BOUNDARY,0x1000),
        (CONFIG,0x1000),(BG,0x50000)):
        u.mem_map(base,size)
    for base in (BG,ALT,LOAD,TEXT):fill_resource(u,base)
    u.mem_write(TEXTURE,bytes(0x40));put(u,TEXTURE+0x28,0x12345678)
    u.mem_write(PLAYER,bytes(0x100));put(u,PLAYER,0x99)
    u.mem_write(SELECTION,bytes(0x100));put(u,SELECTION+4,ALT);put(u,SELECTION+8,1)
    put(u,SELECTION+12,1 if c['player_mode']&4 else 0)
    u.mem_write(LOCK_CONTEXT,struct.pack('<I',0x4444))
    # Caller/consumer globals; the virtual arena tail remains PE zero-fill.
    put(u,0x655a24,TEXTURE if c['texture'] else 0)
    u.mem_write(0x655a28,bytes((c['enabled']&255,)))
    put(u,0x5dead0,c['format'])
    put(u,0x6573e8,c['game_type']);put(u,0x657440,c['no_loading'])
    put(u,0x65741c,0xabcdef01);put(u,0x65742c,c['mirror']);put(u,0x657430,c['reverse'])
    put(u,0x657c84,1 if c['player_mode']&8 else 0)
    put(u,0x658084,c['count']);put(u,0x658608,c['player_value'])
    put(u,0x658200,c['label'])
    put(u,0x65b334,CONFIG+0x200);put(u,0x65b350,CONFIG+0x240)
    # Empty bytes at 00657444 are the original BSS C-string in this fixture.
    u.mem_write(0x657444,bytes(0x40))
    put(u,0x5deac8,c['width']);put(u,0x5deacc,c['height'])
    if c['net']:
        u.mem_write(CONFIG,bytes(0x300));put(u,CONFIG+8,1 if c['config_live'] else 0)
        u.mem_write(CONFIG+0xbe,bytes(((1 if c['net']&1 else 0),)))
        u.mem_write(CONFIG+0xbf,bytes(((1 if c['net']&2 else 0),)))
        put(u,CONFIG+0xdc,0xffffffff if c['net']&4 else 0)
        put(u,CONFIG+0x10,LOCK_CONTEXT if c['net']&8 else 0)
        put(u,0x628c70,CONFIG)
    else:put(u,0x628c70,0)
    write_cstr(u,CONFIG+0x200,'FE\\');write_cstr(u,CONFIG+0x240,'ALT\\')

    trace=[];recent=[];pumps=[c['wait']]
    def instruction(m,address,size,_):
        recent.append(address)
        if len(recent)>24:del recent[0]
    u.hook_add(UC_HOOK_CODE,instruction,begin=0x4a4a70,end=0x4a53e7)
    resbegin=[c['wait']];resend=[c['wait']]
    def event_call(m,address,_size,_):
        esp=m.reg_read(UC_X86_REG_ESP);ret=get(m,esp)
        def arg(i):return get(m,esp+4+i*4)
        def finish(value=None,cleanup=0):
            if value is not None:m.reg_write(UC_X86_REG_EAX,value&0xffffffff)
            m.reg_write(UC_X86_REG_ESP,esp+4+cleanup)
            m.reg_write(UC_X86_REG_EIP,ret)
        def add(event):trace.append(event)
        if address==0x535950:
            add(f'create:{arg(0)}:{arg(1)}:{arg(2)}:{arg(3)}')
            m.mem_write(TEXTURE,bytes(0x40));put(m,TEXTURE+0x28,0x12345678);finish(TEXTURE)
        elif address==0x4edc00:
            cursor_addr=arg(1);cursor=get(m,cursor_addr)
            for i,v in enumerate((arg(0),arg(2),arg(3))):put(m,cursor+i*4,v)
            put(m,cursor_addr,cursor+12);add(f'dispatch:{arg(0)}:{arg(2)}:{s32(arg(3))}');finish()
        elif address==0x48d550:
            p=arg(0);add('records:'+':'.join(str(get(m,p+i*4)) for i in range(4)));finish()
        elif address==0x4ad670:
            add('resource-begin');finish(2 if resbegin[0] else 0)
        elif address==0x4ad6c0:
            add('resource-end');finish(1 if resend[0] else 0)
        elif address==0x5366e0:
            add(f'pump:{arg(0)}');pumps[0]=0;resbegin[0]=0;resend[0]=0;finish()
        elif address==0x534480:
            add('bind:'+normalize(arg(0)));finish(1)
        elif address==0x5a0fbf:
            out,fmt=arg(0),cstr(m,arg(1));
            if fmt=='%s%s.fsh':value=cstr(m,arg(2))+cstr(m,arg(3))+'.fsh'
            elif fmt=='%sera%d.fsh':value=cstr(m,arg(2))+'era'+str(s32(arg(3)))+'.fsh'
            elif fmt=='%sera%dtr.fsh':value=cstr(m,arg(2))+'era'+str(s32(arg(3)))+'tr.fsh'
            elif fmt=='%sMLoading.fsh':value=cstr(m,arg(2))+'MLoading.fsh'
            elif fmt=='%sloadtext.fsh':value=cstr(m,arg(2))+'loadtext.fsh'
            else:raise RuntimeError('unhandled format '+fmt)
            write_cstr(m,out,value);add('format:'+value);finish(cleanup=0)
        elif address==0x59dc30:
            p=cstr(m,arg(0));ok=c['alt_exists'] if 'ALT\\' in p else c['text_exists']
            add('exists:'+p+':'+('1' if ok else '0'));finish(1 if ok else 0)
        elif address==0x59d8e0:
            p=cstr(m,arg(0));base,label=resource_for(p)
            add('load:'+label+':'+p+':'+str(arg(1)));finish(base)
        elif address==0x5032d0:
            add('render-format:'+str(c['render_format']));finish(c['render_format'])
        elif address==0x563440:
            add('tile:'+normalize(arg(0))+':'+':'.join(str(s32(arg(i))) for i in range(1,5)));finish()
        elif address==0x563320:
            add('flip:'+normalize(arg(0)));finish()
        elif address==0x563160:
            add('sprite:'+normalize(arg(0))+':'+':'.join(str(s32(arg(i))) for i in range(1,5)));finish()
        elif address==0x531f90:
            add('free:'+normalize(arg(0)));finish()
        elif address==0x562810:
            add('overlay:'+normalize(arg(0))+':'+':'.join(str(s32(arg(i))) for i in range(1,5)));finish()
        elif address==0x562680:
            add('text:'+':'.join(str(s32(arg(i))) if i<2 else str(arg(i)) for i in range(5)));finish()
        elif address==0x5322b0:
            add('enter:'+normalize(arg(0)));finish()
        elif address==0x5322c0:
            add('leave:'+normalize(arg(0)));finish()
        elif address==0x48d720:
            add('find:'+str(s32(arg(0))));finish(PLAYER if (c['player_mode']&1) else 0)
        elif address==0x490390:
            add('visible:'+normalize(m.reg_read(UC_X86_REG_ECX)));finish(1 if c['player_mode']&2 else 0)
        elif address==0x4903f0:
            add('item-data:'+normalize(m.reg_read(UC_X86_REG_ECX))+':'+str(s32(arg(0))))
            finish(SELECTION if c['player_mode']&4 else 0,4)
        elif address==0x4b0d70:add('frame-state');finish()
        elif address==0x534540:add('driver-begin');finish()
        elif address==0x53d570:
            add('present:'+str(arg(0))+':'+str(s32(arg(1)))+':'+str(s32(arg(2))))
            finish()
        elif address==0x534550:add('driver-end');finish()
        elif address==BOUNDARY+0x1a0:add(f'window:{arg(0)}');finish(cleanup=4)
        elif address==BOUNDARY+0x1b0:add('clear');finish()
        elif address==BOUNDARY+0x1c0:add(f'sync:{arg(0)}');finish(cleanup=4)
        elif address==BOUNDARY+0x1d0:add('pageflip');finish()
        elif address==0x533f80:add('release-texture:'+str(arg(0)));finish()

    hook_targets=[0x535950,0x4edc00,0x48d550,0x4ad670,0x4ad6c0,0x5366e0,
      0x534480,0x5a0fbf,0x59dc30,0x59d8e0,0x5032d0,0x563440,0x563320,0x563160,
      0x531f90,0x562810,0x562680,0x5322b0,0x5322c0,0x48d720,0x490390,0x4903f0,
      0x4b0d70,0x534540,0x53d570,0x534550,0x533f80]
    for va in hook_targets:u.hook_add(UC_HOOK_CODE,event_call,begin=va,end=va)
    for va,target in ((0x6bd9b0,BOUNDARY+0x1a0),(0x6bd91c,BOUNDARY+0x1b0),
                      (0x6bd978,BOUNDARY+0x1c0),(0x6bd948,BOUNDARY+0x1d0)):
        put(u,va,target)
    u.hook_add(UC_HOOK_CODE,event_call,begin=BOUNDARY+0x1a0,end=BOUNDARY+0x1d0)
    put(u,STACK,EXIT);put(u,STACK+4,c['phase']);u.reg_write(UC_X86_REG_ESP,STACK)
    try:
        u.emu_start(0x4a4a70,EXIT,count=500000)
    except Exception as exc:
        raise RuntimeError(f"original fault phase={c['phase']} EIP={u.reg_read(UC_X86_REG_EIP):08x} ESP={u.reg_read(UC_X86_REG_ESP):08x} EAX={u.reg_read(UC_X86_REG_EAX):08x} ins={','.join(f'{a:08x}' for a in recent)} trace={trace[-8:]}") from exc
    enabled=u.mem_read(0x655a28,1)[0];texture=get(u,0x655a24)
    texture_state='none' if texture==0 else 'fixture' if texture==TEXTURE else 'other'
    return dict(enabled=enabled,texture=texture_state,mode=get(u,0x6573e8),
        width=get(u,0x5deac8),height=get(u,0x5deacc),events=trace)

def parse_native_line(line):
    parts=line.split();count=int(parts[6])
    if len(parts)!=7+count:raise RuntimeError(f'bad native trace line {line[:180]}')
    return dict(enabled=int(parts[1]),texture=parts[2],mode=int(parts[3]),
        width=int(parts[4]),height=int(parts[5]),events=parts[7:])

def main():
    ap=argparse.ArgumentParser();ap.add_argument('--probe',type=Path,default=ROOT/'local/builds/v2/001-original-recovery/splash-progress-095/bin/Release/splash_progress_probe.exe');ap.add_argument('--report',type=Path,default=RUN/'verification.json');args=ap.parse_args()
    module=next(json.loads(s) for s in (ROOT/'research/binary-index/static/binaries.jsonl').read_text(encoding='utf8').splitlines() if json.loads(s)['file']=='Porsche.exe')
    image=(ROOT/'local/game'/module['path']).read_bytes()
    if hashlib.sha256(image).hexdigest()!=SHA:raise RuntimeError('original Porsche.exe SHA mismatch')
    proc=subprocess.run([str(args.probe)],input=''.join(native_line(c) for c in CASES),text=True,capture_output=True,check=True,timeout=30)
    actual={line.split()[0]:parse_native_line(line) for line in proc.stdout.splitlines()}
    outputs=[]
    for c in CASES:
        expected=original(module,image,c)
        found=actual.get(c['name'])
        if found!=expected:
            raise RuntimeError(f"{c['name']}: original={expected}, native={found}")
        outputs.append({'case':c['name'],'state':{k:expected[k] for k in ('enabled','texture','mode','width','height')},'ordered_calls':expected['events']})
    dependencies=[
      'iterations/v2/001-original-recovery/source/include/porsche/splash_progress.hpp',
      'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/splash_progress.cpp',
      'iterations/v2/001-original-recovery/source/recovered/splash_progress_probe.cpp',
      'iterations/v2/001-original-recovery/source/include/porsche/application_state.hpp',
      'iterations/v2/001-original-recovery/source/include/porsche/game_setup.hpp',
      'iterations/v2/001-original-recovery/source/include/porsche/render_display.hpp',
      'iterations/v2/001-original-recovery/source/include/porsche/startup_services.hpp',
      'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/application_state.cpp',
      'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/application_globals.cpp',
      'iterations/v2/001-original-recovery/runs/095-splash-progress/CMakeLists.txt',
      'iterations/v2/001-original-recovery/runs/095-splash-progress/README.md',
      'scripts/research/verify-v2-splash-progress.py']
    report={'schema':1,'sha256':SHA,'function_vas':['004a4a70'],'full_function_vas':['004a4a70'],'partial_function_vas':[],'original_sha256':SHA,'function_va':'004a4a70','body_bytes':2424,
      'cases':outputs,'case_count':len(outputs),'native_cpp_equal_original_x86':True,
      'source_sha256':source_hashes(dependencies,compiled_sources=dependencies[1:3]+dependencies[7:9]),
      'probe_sha256':hashlib.sha256(args.probe.read_bytes()).hexdigest(),
      'ownership':{'00655a24':'splash_progress_texture_00655a24 uint32 owner',
        '00655a28':'splash_progress_enabled_00655a28 uint8 owner',
        '005dead0':'splash_progress_format_005dead0 uint32 owner; raw-backed original DWORD zero',
        '006573e8..0065b20b':'existing ApplicationStateArena, direct typed word/byte views',
        '0065b334':'existing game_setup_load_base_0065b334 declaration; shared owner outside this TU',
        '0065b350':'splash_progress_alternate_base_0065b350 pointer-cell owner; original BSS zero/null',
        '005deac8/005deacc':'existing render_display texture-width/height owners'},
      'boundaries':'Direct loader, formatter, draw, player lookup, lock, frame, and THRASH calls are typed recorder boundaries; they do not implement renderer/assets or claim game execution.',
      'game_launch_verified':False}
    args.report.parent.mkdir(parents=True,exist_ok=True);args.report.write_text(json.dumps(report,indent=2)+'\n',encoding='utf8')
    print(json.dumps({'cases':len(outputs),'matched':True,'report':str(args.report)}))

if __name__=='__main__':main()
