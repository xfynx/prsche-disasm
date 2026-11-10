"""Emit one checked seven-body routing/size/descriptor source and native batch."""
from pathlib import Path
import hashlib,json,re,sys
ROOT=Path(__file__).resolve().parents[5];RUN=Path(__file__).resolve().parent
sys.path[:0]=[str(ROOT/'local/tools/python-unicorn')]
import capstone
e=json.loads((RUN/'scope-evidence.json').read_bytes());md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
names={0x561960:('application_audio_stream_descriptor_00561960','I','B*'),0x5611d0:('audio_stream_record_bytes_005611d0','U','U'),0x5611e0:('audio_stream_storage_bytes_005611e0','U','U'),0x5678a0:('audio_stream_service_bytes_005678a0','U','U,U'),0x5678c0:('application_audio_stream_estimate_005678c0','U','U,U'),0x56afc0:('audio_stream_codec_bytes_0056afc0','U','U,U,U'),0x567660:('application_audio_stream_begin_00567660','I','B*,U,U,U,U')}
calls={v:n[0] for v,n in names.items()}|{0x589790:'audio_stream_prefix_bytes_00589790',0x5673d0:'application_audio_stream_create_005673d0'}
header='''#pragma once
#include "../556-application-audio-lifecycle/application_audio_lifecycle_556.hpp"
#include "../508-audio-stream-producer-lifecycle/audio_stream_producer_lifecycle_508.hpp"
namespace porsche {
std::uint32_t __cdecl audio_stream_record_bytes_005611d0(std::uint32_t);
std::uint32_t __cdecl audio_stream_storage_bytes_005611e0(std::uint32_t);
std::uint32_t __cdecl audio_stream_service_bytes_005678a0(std::uint32_t,std::uint32_t);
std::uint32_t __cdecl audio_stream_codec_bytes_0056afc0(std::uint32_t,std::uint32_t,std::uint32_t);
// Original five-argument begin forwards all five plus two explicit zero words.
// The seven-argument creator remains a real unresolved algorithm/provider.
std::int32_t __cdecl application_audio_stream_create_005673d0(std::uint8_t*,std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t);
}
'''
(RUN/'audio_stream_service_559.hpp').write_text(header,encoding='utf-8',newline='\n')
source='''// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Seven original bodies258B; exact wrap/store/call order. No new data/state.
#include "audio_stream_service_559.hpp"
#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Exact x86 register/stack/wrapping semantics require MSVC x86
#endif
namespace porsche {
using U=std::uint32_t;using I=std::int32_t;using B=std::uint8_t;
'''
selected=[b for b in e['bodies'] if int(b['va'],16) in names];mapping=[];offsets={int(b['va'],16):i*0x100 for i,b in enumerate(selected)};chunks=[];patches=[]
for b in selected:
 va=int(b['va'],16);name,ret,args=names[va];source+=f'// {va:08x}/{b["bytes"]}B SHA256 {b["sha256"]}\n__declspec(naked) {ret} __cdecl {name}({args}){{\n    __asm {{\n'
 for ins in b['instructions']:
  asm=ins['asm'];address=int(ins['va'],16)
  if asm.startswith('call '):asm='call '+calls[int(asm.split()[1],16)]
  source+='        '+asm+' // '+ins['va']+'\n';mapping.append(dict(va=ins['va'],raw=ins['raw'],source=asm))
 source+='    }\n}\n'
 token=f'@BODY_{va:08X}@';off=offsets[va];chunks.append(f'const B raw_{va:x}[]={{'+token+f'}};std::memcpy(service_slab+{off},raw_{va:x},sizeof raw_{va:x});')
 for ins in b['instructions']:
  if not ins['asm'].startswith('call '):continue
  target=int(ins['asm'].split()[1],16);at=off+int(ins['va'],16)-va;raw=bytes.fromhex(ins['raw']);dest=f'service_slab+{offsets[target]}' if target in offsets else f'reinterpret_cast<void*>(&{calls[target]})'
  patches.append(f'require(rd(service_slab+{at+1})==0x{int.from_bytes(raw[1:],"little"):08x},"raw service child operand");wr(service_slab+{at+1},ptr({dest})-ptr(service_slab+{at+5}));')
source+='}\n';(RUN/'audio_stream_service_559.cpp').write_text(source,encoding='utf-8',newline='\n');(RUN/'translation-evidence.json').write_text(json.dumps(dict(instructions=mapping,offsets={f'{v:08x}':o for v,o in offsets.items()}),indent=2)+'\n',encoding='utf-8',newline='\n')
base=RUN.parent/'556-application-audio-lifecycle';cfg=json.loads((base/'native-config.json').read_bytes());base_fixture=(base/'native-fixture.cpp.in').read_text();fixture=base_fixture.split('int main(){')[0]
fixture=fixture.replace('#include "application_audio_lifecycle_556.hpp"','#include "audio_stream_service_559.hpp"')
def remove_function(text,signature):
 start=text.index(signature);at=text.index('{',start);end=at+1;depth=1
 while depth:depth+=(text[end]=='{')-(text[end]=='}');end+=1
 return text[:start]+text[end:]
for signature in ['U __cdecl application_audio_stream_estimate_005678c0(U a,U b)','I __cdecl application_audio_stream_descriptor_00561960(B* p)','I __cdecl application_audio_stream_begin_00567660(B* p,U a,U b,U c,U d)']:fixture=remove_function(fixture,signature)
fixture=fixture.replace('struct Event{U tag,args[5];','struct Event{U tag,args[7];')
fixture=fixture.replace('static U objects[2],buffers[4],heap_events,child_calls,descriptor_address;','static U objects[2],buffers[4],heap_events,child_calls,descriptor_address;static U captured_return;')
fixture=fixture.replace('    call fn\n    mov eax,argc','    call fn\n    mov captured_return,eax\n    mov eax,argc')
fixture=remove_function(fixture,'I __cdecl audio_channel_stop_00565d60(U)')
fixture+=(RUN/'fixture-service.inc').read_text().replace('@SERVICE_BODIES@','\n    '.join(chunks)).replace('@SERVICE_RELOCATIONS@','\n    '.join(patches))
start=base_fixture.index('const B raw_4ae010[]');end=base_fixture.index('require(FlushInstructionCache(GetCurrentProcess(),slab',start)
fixture=fixture.replace('@BORROWED556_BODIES@',base_fixture[start:end])
(RUN/'native-fixture.cpp.in').write_text(fixture,encoding='utf-8',newline='\n')
newsource=(RUN/'audio_stream_service_559.cpp').relative_to(ROOT).as_posix();cfg.update(run=559,experiment='local/experiments/v2-audio-stream-service-559',fixture=(RUN/'native-fixture.cpp.in').relative_to(ROOT).as_posix(),pass_marker='audio_stream_service_original_x86_vs_cpp=PASS',timeout_seconds=180)
support=json.loads((RUN.parent/'550-audio-codec-frontier/native-config.json').read_bytes())
cfg['sources']=list(dict.fromkeys([newsource,*cfg['sources'],*support['sources']]))
cfg['include_dirs']=list(dict.fromkeys([RUN.relative_to(ROOT).as_posix(),*cfg['include_dirs'],*support['include_dirs']]))
cfg['headers']=[(RUN/x).relative_to(ROOT).as_posix() for x in ['scope-evidence.json','scope-inspect.py','prepare.py','translation-evidence.json','fixture-service.inc']]
cfg['original_bodies']+=[dict(va=b['va'],bytes=b['bytes'],sha256=b['sha256'],token=f'@BODY_{b["va"].upper()}@') for b in selected]
mutations=[('record-wrap','lea eax, [eax + eax*2 + 0xc]','lea eax, [eax + eax*2 + 0xb]'),('record-shift','shl eax, 3 // 005611d8','shl eax, 2 // 005611d8'),('storage-add','add eax, esi // 005611f5','sub eax, esi // 005611f5'),('service-overhead','0xf8] // 005678b7','0xf7] // 005678b7'),('estimate-increment','inc esi // 005678d3','dec esi // 005678d3'),('codec-overhead','0x19] // 0056afc4','0x18] // 0056afc4'),('descriptor-preserve','mov word ptr [eax + 0x14], cx','mov dword ptr [eax + 0x14], ecx'),('descriptor-field','0x3c // 00561983','0x3d // 00561983'),('begin-zero','push 0 // 0056766c','push 1 // 0056766c')]
for name,old,new in mutations:assert source.count(old)==1,(name,old,source.count(old))
cfg['mutations']=[dict(name=name,source=newsource,old=old,new=new,expected_exit=1,failure_marker='divergence') for name,old,new in mutations]
(RUN/'native-config.json').write_text(json.dumps(cfg,indent=2)+'\n',encoding='utf-8',newline='\n');print('prepared559 7bodies258B/0data/9controls+actual556subset')
