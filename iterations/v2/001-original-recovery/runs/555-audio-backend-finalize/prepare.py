"""Emit three checked static pan-source bodies and a shared native comparison config."""
import hashlib
import importlib.util
import json
import re
from pathlib import Path

ROOT=Path(__file__).resolve().parents[5]
RUN=Path(__file__).resolve().parent
spec=importlib.util.spec_from_file_location('native555',ROOT/'scripts/research/verify-v2-native-batch.py')
n=importlib.util.module_from_spec(spec)
spec.loader.exec_module(n)
raw=(ROOT/'local/game/Porsche.exe').read_bytes()
scope=json.loads((RUN/'scope-evidence.json').read_bytes())
sha=lambda b:hashlib.sha256(b).hexdigest()
assert sha(raw)==scope['module_sha256']
names={0x58e0e0:('application_audio_backend_finalize_0058e0e0','void',''),
       0x58e0b0:('audio_backend_pan_curve_0058e0b0','I','I'),
       0x58e290:('audio_backend_pan_copy_0058e290','void','I,U')}
bindings={0x6b48dc:'application_audio_device_state_006b48c0+0x2c',
          0x6b48ec:'application_audio_device_state_006b48c0+0x3c',
          0x6b181f:'audio_backend_pan_storage_006b181f',
          0x6b1820:'audio_backend_pan_storage_006b181f+1',
          0x6b1821:'audio_backend_pan_storage_006b181f+2'}
header='''#pragma once
#include "porsche/application_audio_device.hpp"
namespace porsche {
// Exact original touched span: count0 last-column byte, then 256 four-byte rows.
struct AudioBackendPanStorage555 {std::uint8_t before;std::uint8_t table[1024];};
static_assert(sizeof(AudioBackendPanStorage555)==1025);
static_assert(offsetof(AudioBackendPanStorage555,table)==1);
extern AudioBackendPanStorage555 audio_backend_pan_storage_006b181f;
std::int32_t __cdecl audio_backend_pan_curve_0058e0b0(std::int32_t);
void __cdecl audio_backend_pan_copy_0058e290(std::int32_t,std::uint32_t);
}
'''
(RUN/'audio_backend_finalize_555.hpp').write_text(header,encoding='utf-8',newline='\n')
source='''// Porsche.exe SHA256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Three original bodies/511B. Static instructions retain wrap/divide/copy order.
#include "audio_backend_finalize_555.hpp"
#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Original x86 integer/stack semantics require MSVC x86
#endif
namespace porsche {
AudioBackendPanStorage555 audio_backend_pan_storage_006b181f{};
using U=std::uint32_t;using I=std::int32_t;
'''
records=[]
selected=[b for b in scope['bodies'] if int(b['va'],16) in names]
for b in selected:
    va=int(b['va'],16)
    assert sha(n.pe_at(raw,va,b['bytes']))==b['sha256']
    assert b''.join(bytes.fromhex(i['raw']) for i in b['instructions'])==n.pe_at(raw,va,b['bytes'])
    name,result,args=names[va]
    labels={int(i['asm'].split()[-1],16) for i in b['instructions'] if re.match(r'j\w+ 0x',i['asm'])}
    source+=f'\n// {b["va"]}/{b["bytes"]}B SHA256 {b["sha256"]}\n__declspec(naked) {result} __cdecl {name}({args}) {{\n    __asm {{\n'
    for i in b['instructions']:
        original=i['asm'];asm=original;at=int(i['va'],16)
        if at in labels:source+=f'    L{at:08x}:\n'
        if original.startswith('call '):asm='call '+names[int(original.split()[1],16)][0]
        elif re.match(r'j\w+ 0x',original):asm=original.split()[0]+' L'+f'{int(original.split()[1],16):08x}'
        else:
            for value,symbol in bindings.items():asm=re.sub(r'\b'+hex(value)+r'\b',symbol,asm)
            if asm.startswith('rep '):asm=' '.join(asm.split()[:2])
        source+='        '+asm+' // '+i['va']+'\n'
        records.append(dict(va=i['va'],raw=i['raw'],source=asm))
    source+='    }\n}\n'
source+='}\n'
(RUN/'audio_backend_finalize_555.cpp').write_text(source,encoding='utf-8',newline='\n')
(RUN/'translation-evidence.json').write_text(json.dumps(dict(module_sha256=sha(raw),instructions=records,bindings=bindings),indent=2)+'\n',encoding='utf-8',newline='\n')

positions={0x58e0e0:0,0x58e0b0:0x200,0x58e290:0x300}
chunks=[];patches=[]
for b in selected:
    va=int(b['va'],16);pos=positions[va]
    chunks.append(f'const B raw_{va:x}[]={{@BODY_{va:08x}@}};std::memcpy(slab+{pos},raw_{va:x},sizeof raw_{va:x});')
    for i in b['instructions']:
        a=int(i['va'],16)-va+pos;buf=bytes.fromhex(i['raw'])
        if i['asm'].startswith('call '):
            target=int(i['asm'].split()[1],16)
            patches.append(f'require(rd(slab+{a+1})==0x{int.from_bytes(buf[1:],"little"):08x},"raw call operand");wr(slab+{a+1},ptr(slab+{positions[target]})-ptr(slab+{a+5}));')
        for value,symbol in bindings.items():
            if hex(value) in i['asm']:
                operand=value.to_bytes(4,'little')
                assert buf.count(operand)==1
                operand_at=buf.index(operand)
                target=('ptr(application_audio_device_state_006b48c0.data())+'+str(value-0x6b48c0)) if value>=0x6b4800 else ('ptr(&audio_backend_pan_storage_006b181f)+'+str(value-0x6b181f))
                patches.append(f'require(rd(slab+{a+operand_at})==0x{value:08x},"raw data operand");wr(slab+{a+operand_at},{target});')
fixture='''#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "audio_backend_finalize_555.hpp"
#include <cstdio>
#include <cstring>
#include <initializer_list>
using U=std::uint32_t;using I=std::int32_t;using B=std::uint8_t;using namespace porsche;
static B* slab;static U cases,events;
static U ptr(const void* p){return reinterpret_cast<U>(p);}
static U rd(const void* p){U v;std::memcpy(&v,p,4);return v;}
static void wr(void* p,U v){std::memcpy(p,&v,4);}
static void require(bool ok,const char* why){if(!ok){std::printf("divergence %s case=%u\\n",why,cases);std::fflush(stdout);ExitProcess(1);}}
namespace porsche {
// Dead dependencies of the canonical state-owner TU. None is executed here.
I __cdecl application_audio_backend_initialize_0058a4f0(){ExitProcess(90);return 0;}
void __cdecl application_audio_backend_apply_0058a690(){ExitProcess(90);}
void __cdecl application_audio_backend_configure_0058fef0(U,U){ExitProcess(90);}
void __cdecl application_audio_backend_configure_0058aa90(U,U){ExitProcess(90);}
U __cdecl application_audio_backend_allocate_0058aae0(U){ExitProcess(90);return 0;}
void __cdecl application_audio_backend_start_0058e2d0(){ExitProcess(90);}
I __cdecl application_audio_backend_start_device_0058fdb0(){ExitProcess(90);return 0;}
void __cdecl application_audio_backend_stop_device_0058fe80(){ExitProcess(90);}
void __cdecl application_audio_backend_stop_0058e2e0(){ExitProcess(90);}
}
static void setup(){
    require(sizeof(audio_backend_pan_storage_006b181f)==1025,"exact original data extent");
    for(B byte:reinterpret_cast<const B(&)[1025]>(audio_backend_pan_storage_006b181f))require(byte==0,"production PE-loader-zero before reset");
    slab=static_cast<B*>(VirtualAlloc(nullptr,4096,MEM_COMMIT|MEM_RESERVE,PAGE_EXECUTE_READWRITE));require(slab!=nullptr,"raw slab");
'''+ '\n'.join(chunks+patches)+'''
    require(FlushInstructionCache(GetCurrentProcess(),slab,4096)!=0,"original instruction cache");
}
#include "fixture-harness.inc"
'''
(RUN/'native-fixture.cpp.in').write_text(fixture,encoding='utf-8',newline='\n')
src=(RUN/'audio_backend_finalize_555.cpp').relative_to(ROOT).as_posix()
mutations=[('mono-weight','0x7f // 0058e0f9','0x7e // 0058e0f9'),
 ('curve-magic','0x81020409 // 0058e0b7','0x81020408 // 0058e0b7'),
 ('curve-sign','sar edx, 6 // 0058e0c3','shr edx, 6 // 0058e0c3'),
 ('curve-shift','shl eax, 7 // 0058e14c','shl eax, 6 // 0058e14c'),
 ('wrap-add','add esi, 0x10000 // 0058e144','add esi, 0xffff // 0058e144'),
 ('row-count','cmp ebp, 0x100 // 0058e274','cmp ebp, 0xff // 0058e274'),
 ('threshold-selection','jg L0058e18f // 0058e135','jl L0058e18f // 0058e135'),
 ('copy-phase','sar eax, 8 // 0058e29a','sar eax, 7 // 0058e29a'),
 ('copy-tail','and ecx, 3 // 0058e2bb','and ecx, 2 // 0058e2bb')]
for name,old,new in mutations:assert source.count(old)==1,(name,old)
cfg=dict(run=555,experiment='local/experiments/v2-audio-backend-finalize-555',fixture=(RUN/'native-fixture.cpp.in').relative_to(ROOT).as_posix(),
 pass_marker='audio_backend_finalize_original_x86_vs_cpp=PASS',timeout_seconds=180,original_pe='local/game/Porsche.exe',original_sha256=sha(raw),
 sources=[src,'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/application_audio_device.cpp'],
 include_dirs=[RUN.relative_to(ROOT).as_posix(),'iterations/v2/001-original-recovery/source/include'],
 headers=[(RUN/f).relative_to(ROOT).as_posix() for f in ['scope-evidence.json','scope-inspect.py','translation-evidence.json','prepare.py','fixture-harness.inc']],
 original_bodies=[dict(va=b['va'],bytes=b['bytes'],sha256=b['sha256'],token=f'@BODY_{b["va"]}@') for b in selected],
 mutations=[dict(name=name,source=src,old=old,new=new,expected_exit=1,failure_marker='divergence') for name,old,new in mutations])
(RUN/'native-config.json').write_text(json.dumps(cfg,indent=2)+'\n',encoding='utf-8',newline='\n')
print('prepared555 3bodies/511B;1025B exact touched span;9 controls')
