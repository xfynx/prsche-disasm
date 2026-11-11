"""Prepare exact integer transport over proven sparse original state owners."""
import hashlib
import json
from pathlib import Path

ROOT=Path(__file__).resolve().parents[5]
RUN=Path(__file__).resolve().parent
scope=json.loads((RUN/'scope-evidence.json').read_bytes())
ledger=json.loads((RUN/'owner-ledger.json').read_bytes())
sha=lambda b:hashlib.sha256(b).hexdigest()
assert sha((ROOT/'local/game/Porsche.exe').read_bytes())==scope['module_sha256']
owners={r['owner']:r for r in ledger['existing_owners']}
expressions={
 'canonical_device':'reinterpret_cast<volatile B*>(&application_audio_device_state_006b48c0)',
 'thread_callbacks460':'reinterpret_cast<volatile B*>(&audio_thread_callbacks_006b4a3c)',
 'pixel_palette380':'reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)',
 'notify_kind462':'reinterpret_cast<volatile B*>(&audio_ds_notify_kind_006b4886)',
 'device_buffers455':'reinterpret_cast<volatile B*>(&audio_device_buffers_006b4888)',
 'device_callback455':'reinterpret_cast<volatile B*>(&audio_device_callback_006b4898)',
 'voice_table435':'reinterpret_cast<volatile B*>(&audio_backend_voice_table_006b489c)',
 'resource_count452':'reinterpret_cast<volatile B*>(&audio_resource_map_count_006b48a0)',
 'resource_map452':'reinterpret_cast<volatile B*>(&audio_resource_map_006b48a4)',
}
includes='''#include "porsche/application_audio_device.hpp"
#include "porsche/frame_services.hpp"
#include "../435-audio-stop-voice/audio_stop_435.hpp"
#include "../452-audio-record-resources/audio_record_resources_452.hpp"
#include "../455-audio-device-lifecycle/audio_device_lifecycle_455.hpp"
#include "../460-audio-thread-worker/audio_thread_worker_460.hpp"
#include "../462-audio-directsound-initialize/audio_directsound_state_462.hpp"
#include "../380-pixel-helpers/pixel_helpers.hpp"
'''
header='#pragma once\n'+includes+'namespace porsche {\n'
source='''// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// 565c70/90B,565cd0/137B,590250/56B are PARTIAL for upper address bits.
// All32 low-byte groups use exact sparse owners; no contiguous slot array.
// 590290/3B is complete. Pointer views are modern host transport, not PE data.
#include "audio_period_control_558.hpp"
#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Original pointer width and genuine3B zero leaf require MSVC x86
#endif
namespace porsche {
using U=std::uint32_t;using I=std::int32_t;using B=std::uint8_t;
'''
for span in ledger['new_spans']:
    name='audio_period_sparse_'+span['va'];size=span['bytes']
    header+=f'extern std::uint8_t {name}[{size}];\n'
    source+=f'alignas(4) std::uint8_t {name}[{size}]{{}}; // exact PE-loader-zero touched span\n'

def address(va,size):
    for owner,r in owners.items():
        start=int(r['va'],16)
        if start<=va and va+size<=start+r['bytes']:
            return expressions[owner]+f'+0x{va-start:x}',owner,va-start
    for span in ledger['new_spans']:
        start=int(span['va'],16)
        if start<=va and va+size<=start+span['bytes']:
            return 'audio_period_sparse_'+span['va']+f'+0x{va-start:x}','new_'+span['va'],va-start
    raise AssertionError((hex(va),size))

fields=[('value',0,4),('byte4',4,1),('byte5',5,1),('arg4',8,4),('arg5',12,4),('notify',None,1)]
bindings=[]
for field,offset,size in fields:
    symbol='audio_period_'+field+'_views_558'
    header+=f'extern volatile std::uint8_t* const {symbol}[32];\n'
    source+=f'volatile B* const {symbol}[32]={{\n'
    for group in range(32):
        va=0x6b4886+group if offset is None else 0x6b4a08+group*16+offset
        expr,owner,off=address(va,size)
        source+='    '+expr+(',\n' if group!=31 else '\n')
        bindings.append(dict(field=field,group=group,va=f'{va:08x}',bytes=size,owner=owner,offset=off,source=expr))
    source+='};\n'
header+='''// Genuine unresolved algorithm providers, never fixture stubs in game.
void __cdecl audio_period_callback_005901b0(std::int32_t,std::uint32_t);
std::int32_t __cdecl audio_period_channel_notify_005902a0(std::uint32_t,std::uint32_t,std::int32_t);
std::int32_t __cdecl audio_period_callback_set_00590250(std::uint32_t);
std::int32_t __cdecl audio_period_value_accept_00590290(std::uint32_t,std::uint32_t);
}
'''
source+='''namespace {
// Volatile character representations preserve cross-owner aliases and field
// order. Atomic/inter-thread observations remain outside this native contract.
U load32(const volatile B* p){return U(p[0])|(U(p[1])<<8)|(U(p[2])<<16)|(U(p[3])<<24);}
void write32(volatile B* p,U value){p[0]=static_cast<B>(value);p[1]=static_cast<B>(value>>8);p[2]=static_cast<B>(value>>16);p[3]=static_cast<B>(value>>24);}
volatile B* device(){return reinterpret_cast<volatile B*>(&application_audio_device_state_006b48c0)+0x10;}
I signed_count(){const volatile B* p=device()+0xe4;const U value=U(p[0])|(U(p[1])<<8);return value<0x8000?static_cast<I>(value):static_cast<I>(value)-65536;}
I signed_byte(B value){return value<128?static_cast<I>(value):static_cast<I>(value)-256;}
}
__declspec(naked) I __cdecl audio_period_value_accept_00590290(U,U){
    __asm {
        xor eax,eax
        ret
    }
}
// Original565cd0: caller ignores EAX, but the genuine leaf's signed result
// controls the branch. The low24 upper address bits are not silently masked.
void __cdecl frame_services_boundary_00565cd0(U flags,U value){
    const U selector=flags&0xffffff1fu;
    if((flags&0xe0u)==0)flags|=0xe0u;
    if(flags&0x20u)*audio_period_byte4_views_558[selector]=static_cast<B>(value);
    if(flags&0x80u)*audio_period_byte5_views_558[selector]=static_cast<B>(value);
    if(audio_period_value_accept_00590290(flags,value)<0)return;
    if(device()[0xdc]==0)return;
    if(signed_count()<=0)return;
    U index=0,offset=0;
    do{
        const U channels=load32(device()+0x140);
        const volatile B* record=reinterpret_cast<const volatile B*>(channels+offset);
        const I setting=signed_byte(record[selector+0x45]);
        const U handle=load32(record);
        (void)audio_period_channel_notify_005902a0(handle,selector,setting);
        ++index;offset+=0x70u;
    }while(static_cast<I>(index)<signed_count());
}
I __cdecl audio_period_callback_set_00590250(U flags){
    const B active=device()[0xdc];
    const U selector=flags&0xffffff1fu; // exact original AND AL,1F semantics
    *audio_period_notify_views_558[selector]=static_cast<B>(flags);
    audio_device_callback_006b4898=reinterpret_cast<U>(&audio_period_callback_005901b0);
    if(active)audio_period_callback_005901b0(static_cast<I>(flags),load32(audio_period_value_views_558[selector]));
    return 0;
}
void __cdecl application_audio_period_control_00565c70(U flags,U value,U third,U fourth,U fifth){
    const U selector=flags&0xffffff1fu; // preserve the unproved upper address domain
    if((flags&0xe0u)==0)flags|=0xe0u;
    write32(audio_period_value_views_558[selector],third);
    write32(audio_period_arg4_views_558[selector],fourth);
    write32(audio_period_arg5_views_558[selector],fifth);
    (void)audio_period_callback_set_00590250(flags);
    frame_services_boundary_00565cd0(flags,third==0?0:value);
}
}
'''
(RUN/'audio_period_control_558.hpp').write_text(header,encoding='utf-8',newline='\n')
(RUN/'audio_period_control_558.cpp').write_text(source,encoding='utf-8',newline='\n')
(RUN/'view-bindings.json').write_text(json.dumps(dict(module_sha256=scope['module_sha256'],bindings=bindings,new_spans=ledger['new_spans']),indent=2)+'\n',encoding='utf-8',newline='\n')

positions={0x565c70:0,0x565cd0:0x100,0x590250:0x200,0x590290:0x280,0x4ab470:0x300}
selected=[b for b in scope['bodies'] if int(b['va'],16) in positions]
chunks=[];patches=[]
data={0x6b4a08:'ptr(shadow_period)',0x6b4a0c:'ptr(shadow_period)+4',0x6b4a0d:'ptr(shadow_period)+5',
      0x6b4886:'ptr(shadow_notify)',0x6b4898:'ptr(shadow_notify)+18',
      0x6b499c:'ptr(application_audio_device_state_006b48c0.data())+0xdc',
      0x6b49a4:'ptr(application_audio_device_state_006b48c0.data())+0xe4',
      0x6b4a00:'ptr(application_audio_device_state_006b48c0.data())+0x140',
      0x5901b0:'ptr(reinterpret_cast<void*>(&audio_period_callback_005901b0))',
      0x655d40:'ptr(&caller_configured)',0x656868:'ptr(caller_flags)',0x656869:'ptr(caller_flags)+1'}
for b in selected:
    va=int(b['va'],16);position=positions[va];buf=bytes.fromhex(b['raw_hex'])
    assert sha(buf)==b['sha256']
    chunks.append(f'const B raw_{va:x}[]={{@BODY_{va:08x}@}};std::memcpy(slab+{position},raw_{va:x},sizeof raw_{va:x});')
    if va==0x4ab470:chunks.append(f'std::memcpy(slab+0x380,raw_{va:x},sizeof raw_{va:x});')
    for ins in b['instructions']:
        raw_ins=bytes.fromhex(ins['raw']);offset=int(ins['va'],16)-va
        locations=[position+offset]+([0x380+offset] if va==0x4ab470 else [])
        for at in locations:
            if ins['asm'].startswith('call '):
                target=int(ins['asm'].split()[1],16)
                if target==0x5901b0:expr='ptr(reinterpret_cast<void*>(&audio_period_callback_005901b0))'
                elif target==0x5902a0:expr='ptr(reinterpret_cast<void*>(&audio_period_channel_notify_005902a0))'
                elif va==0x4ab470 and at>=0x380:expr='ptr(reinterpret_cast<void*>(&application_audio_period_control_00565c70))'
                else:expr=f'ptr(slab+{positions[target]})'
                patches.append(f'require(rd(slab+{at+1})==0x{int.from_bytes(raw_ins[1:],"little"):08x},"raw relative target");wr(slab+{at+1},{expr}-ptr(slab+{at+5}));')
                continue
            for value,expr in data.items():
                needle=value.to_bytes(4,'little')
                if needle in raw_ins:
                    assert raw_ins.count(needle)==1
                    operand=at+raw_ins.index(needle)
                    patches.append(f'require(rd(slab+{operand})==0x{value:08x},"raw absolute target");wr(slab+{operand},{expr});')
captures=[];resets=[];cursor=0
for span in ledger['new_spans']:
    name='audio_period_sparse_'+span['va'];size=span['bytes']
    captures.append(f'std::memcpy(s.sparse+{cursor},{name},{size});')
    resets.append(f'for(U i=0;i<{size};++i){name}[i]=static_cast<B>(i*19+{cursor}+5);')
    cursor+=size
assert cursor==193
fixture=(RUN/'fixture-period.inc').read_text().replace('@ORIGINAL_BODIES@','\n    '.join(chunks)).replace('@ORIGINAL_RELOCATIONS@','\n    '.join(patches)).replace('@SPARSE_CAPTURE@','\n    '.join(captures)).replace('@SPARSE_RESET@','\n    '.join(resets))
(RUN/'native-fixture.cpp.in').write_text(fixture,encoding='utf-8',newline='\n')
src=(RUN/'audio_period_control_558.cpp').relative_to(ROOT).as_posix()
mutations=[('default-flags','if((flags&0xe0u)==0)flags|=0xe0u;\n    write32','if((flags&0xe0u)==0)flags|=0x20u;\n    write32'),
 ('third-captured','flags,third==0?0:value','flags,load32(audio_period_value_views_558[selector])==0?0:value'),
 ('fourth-field','audio_period_arg4_views_558[selector],fourth','audio_period_arg4_views_558[selector],fifth'),
 ('fifth-field','audio_period_arg5_views_558[selector],fifth','audio_period_arg5_views_558[selector],fourth'),
 ('flag20-write','if(flags&0x20u)*audio_period_byte4','if(flags&0x40u)*audio_period_byte4'),
 ('flag80-write','if(flags&0x80u)*audio_period_byte5','if(flags&0x40u)*audio_period_byte5'),
 ('leaf-sign','xor eax,eax\n        ret','or eax,-1\n        ret'),
 ('notify-kind','*audio_period_notify_views_558[selector]=static_cast<B>(flags);','*audio_period_notify_views_558[selector]=0;'),
 ('callback-install','audio_device_callback_006b4898=reinterpret_cast<U>(&audio_period_callback_005901b0);','audio_device_callback_006b4898=0;'),
 ('signed-setting','signed_byte(record[selector+0x45])','static_cast<I>(record[selector+0x45])'),
 ('late-count','}while(static_cast<I>(index)<signed_count());','}while(index<2);'),
 ('record-stride','offset+=0x70u;','offset+=0x6cu;'),
 ('late-channel-table','U index=0,offset=0;\n    do{\n        const U channels=load32(device()+0x140);','U index=0,offset=0;\n    const U channels=load32(device()+0x140);\n    do{')]
for name,old,new in mutations:assert source.count(old)==1,(name,source.count(old))
sources=[src,
 'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/application_audio_device.cpp',
 'iterations/v2/001-original-recovery/runs/455-audio-device-lifecycle/audio_device_lifecycle_455.cpp',
 'iterations/v2/001-original-recovery/runs/460-audio-thread-worker/audio_thread_worker_460.cpp',
 'iterations/v2/001-original-recovery/runs/462-audio-directsound-initialize/audio_directsound_state_462.cpp',
 'iterations/v2/001-original-recovery/runs/435-audio-stop-voice/audio_stop_435.cpp',
 'iterations/v2/001-original-recovery/runs/452-audio-record-resources/audio_record_resources_452.cpp',
 'iterations/v2/001-original-recovery/runs/443-audio-device-capabilities/audio_capabilities_443.cpp',
 'iterations/v2/001-original-recovery/runs/434-audio-canonical-bindings/audio_backend_434.cpp',
 'iterations/v2/001-original-recovery/runs/442-audio-initialization/audio_initialization_442.cpp',
 'iterations/v2/001-original-recovery/runs/380-pixel-helpers/pixel_helpers.cpp',
 'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/window_shutdown.cpp']
build_cfg=json.loads((RUN.parent/'554-audio-kernel-integration/build-config.json').read_bytes())
cfg=dict(run=558,experiment='local/experiments/v2-audio-period-control-558',fixture=(RUN/'native-fixture.cpp.in').relative_to(ROOT).as_posix(),
 original_pe='local/game/Porsche.exe',original_sha256=scope['module_sha256'],sources=sources,
 include_dirs=[RUN.relative_to(ROOT).as_posix(),*build_cfg['source_include_dirs']],
 headers=[(RUN/f).relative_to(ROOT).as_posix() for f in ['scope-evidence.json','scope-inspect.py','owner-ledger.json','owner-ledger.py','view-bindings.json','prepare.py','fixture-period.inc']],
 pass_marker='audio_period_original_x86_vs_cpp=PASS',timeout_seconds=180,
 original_bodies=[dict(va=b['va'],bytes=b['bytes'],sha256=b['sha256'],token=f'@BODY_{b["va"]}@') for b in selected],
 mutations=[dict(name=name,source=src,old=old,new=new,expected_exit=1,failure_marker='divergence') for name,old,new in mutations])
(RUN/'native-config.json').write_text(json.dumps(cfg,indent=2)+'\n',encoding='utf-8',newline='\n')
print('prepared558 4bodies286B/193B sparse zero;192 canonical/sparse pointer views;13 controls')
