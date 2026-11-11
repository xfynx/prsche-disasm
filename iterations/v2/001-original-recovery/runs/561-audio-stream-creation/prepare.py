"""Static original stream-creation instructions and one shared native batch."""
from pathlib import Path
import json,re
ROOT=Path(__file__).resolve().parents[5];RUN=Path(__file__).resolve().parent
scope=json.loads((RUN/'scope-evidence.json').read_bytes())
names={0x5673d0:('application_audio_stream_create_005673d0','I','B*,U,U,U,U,U,U'),0x567690:('application_audio_stream_stop_00567690','I','U'),0x567740:('audio_stream_service_reset_00567740','I','U'),0x566d60:('audio_stream_service_lookup_00566d60','U','I'),0x5673b0:('audio_stream_service_count_005673b0','U',''),0x566d40:('audio_stream_service_shutdown_00566d40','U',''),0x58ff50:('audio_stream_service_register_0058ff50','void','AudioStreamServiceCallback561'),0x58ff70:('audio_stream_service_unregister_0058ff70','void','AudioStreamServiceCallback561')}
calls={va:row[0] for va,row in names.items()}|{0x5611e0:'audio_stream_storage_bytes_005611e0',0x561200:'audio_stream_construct_00561200',0x56aff0:'audio_stream_codec_create_0056aff0',0x56c840:'audio_stream_codec_frames_0056c840',0x5912e0:'audio_stream_codec_set_005912e0',0x5617d0:'network_lifecycle_device_release_005617d0',0x56b3b0:'audio_stream_codec_destroy_0056b3b0',0x561730:'network_lifecycle_device_cancel_00561730',0x56c420:'audio_stream_codec_reset_0056c420',0x58ac30:'audio_backend_pool_release_0058ac30',0x58fef0:'application_audio_backend_configure_0058fef0'}
data={0x6b7740:'audio_stream_service_storage_006b7740',0x6b7780:'audio_stream_service_storage_006b7740+0x40',0x6b499c:'application_audio_device_state_006b48c0+0xec',0x6b49a1:'application_audio_device_state_006b48c0+0xf1',0x6b49c8:'application_audio_device_state_006b48c0+0x118',0x6b49fc:'application_audio_device_state_006b48c0+0x14c'}
code={0x566e10:'audio_stream_service_release_00566e10',0x566e40:'audio_stream_service_consumed_00566e40',0x567270:'audio_stream_service_tick_00567270',0x566d40:'audio_stream_service_shutdown_00566d40'}
header='''#pragma once
#include "../559-audio-stream-service/audio_stream_service_559.hpp"
#include "../438-audio-pool-allocator/audio_pool_438.hpp"
namespace porsche {
struct AudioStreamServiceStorage561 {std::uint32_t slots[16];std::int8_t index_map[16];};
static_assert(sizeof(AudioStreamServiceStorage561)==80);
static_assert(offsetof(AudioStreamServiceStorage561,index_map)==64);
extern AudioStreamServiceStorage561 audio_stream_service_storage_006b7740;
using AudioStreamServiceCallback561=void(__cdecl*)();
std::int32_t __cdecl audio_stream_service_reset_00567740(std::uint32_t);
std::uint32_t __cdecl audio_stream_service_lookup_00566d60(std::int32_t);
std::uint32_t __cdecl audio_stream_service_count_005673b0();
std::uint32_t __cdecl audio_stream_service_shutdown_00566d40();
void __cdecl audio_stream_service_register_0058ff50(AudioStreamServiceCallback561);
void __cdecl audio_stream_service_unregister_0058ff70(AudioStreamServiceCallback561);
// Real unowned codec algorithms and callback bodies; no game fixture provider.
std::uint32_t __cdecl audio_stream_codec_create_0056aff0(std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t);
std::int32_t __cdecl audio_stream_codec_frames_0056c840(std::uint32_t);
std::int32_t __cdecl audio_stream_codec_set_005912e0(std::uint32_t,std::int32_t);
void __cdecl audio_stream_codec_reset_0056c420(std::uint32_t);
void __cdecl audio_stream_codec_destroy_0056b3b0(std::uint32_t);
void __cdecl audio_stream_service_release_00566e10(std::uint32_t);
void __cdecl audio_stream_service_consumed_00566e40(std::uint32_t,std::uint32_t);
void __cdecl audio_stream_service_tick_00567270();
}
'''
(RUN/'audio_stream_creation_561.hpp').write_text(header,encoding='utf-8',newline='\n')
source='''// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Eight original bodies909B; exact integer/state/order and80B original zero state.
#include "audio_stream_creation_561.hpp"
#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Original x86 ABI/stack/wrap semantics require MSVC x86
#endif
namespace porsche {
AudioStreamServiceStorage561 audio_stream_service_storage_006b7740{};
using U=std::uint32_t;using I=std::int32_t;using B=std::uint8_t;
'''
selected=[b for b in scope['bodies'] if int(b['va'],16) in names];positions={int(b['va'],16):p for b,p in zip(selected,[0,0x200,0x300,0x400,0x500,0x600,0x700,0x800])};mapping=[];chunks=[];patches=[]
for row in selected:
 va=int(row['va'],16);name,result,args=names[va];labels={int(i['asm'].split()[-1],16) for i in row['instructions'] if re.match(r'j\w+ 0x',i['asm'])};source+=f'// {va:08x}/{row["bytes"]}B SHA256 {row["sha256"]}\n__declspec(naked) {result} __cdecl {name}({args}){{\n    __asm {{\n'
 for ins in row['instructions']:
  at=int(ins['va'],16);original=ins['asm'];asm=original
  if at in labels:source+=f'    L{at:08x}:\n'
  if asm.startswith('call '):asm='call '+calls[int(asm.split()[1],16)]
  elif re.match(r'j\w+ 0x',asm):asm=asm.split()[0]+' L'+f'{int(asm.split()[1],16):08x}'
  else:
   for value,symbol in data.items():
    if re.search(r'\b'+hex(value)+r'\b',asm):asm=re.sub(r'\b'+hex(value)+r'\b',symbol if '[' in asm else 'offset '+symbol,asm)
   for value,symbol in code.items():asm=re.sub(r'\b'+hex(value)+r'\b','offset '+symbol,asm)
   if asm.startswith('rep '):asm=' '.join(asm.split()[:2])
  source+='        '+asm+' // '+ins['va']+'\n';mapping.append(dict(va=ins['va'],raw=ins['raw'],source=asm))
 source+='    }\n}\n'
 off=positions[va];token=f'@CREATE_{va:08X}@';chunks.append(f'const B raw_{va:x}[]={{'+token+f'}};std::memcpy(creation_slab+{off},raw_{va:x},sizeof raw_{va:x});')
 for ins in row['instructions']:
  at=off+int(ins['va'],16)-va;raw=bytes.fromhex(ins['raw']);asm=ins['asm']
  if asm.startswith('call '):
   target=int(asm.split()[1],16);dest=f'creation_slab+{positions[target]}' if target in positions else f'reinterpret_cast<void*>(&{calls[target]})'
   patches.append(f'require(rd(creation_slab+{at+1})==0x{int.from_bytes(raw[1:],"little"):08x},"raw creation child");wr(creation_slab+{at+1},ptr({dest})-ptr(creation_slab+{at+5}));')
  for value,symbol in (data|code).items():
   if not re.search(r'\b'+hex(value)+r'\b',asm):continue
   needle=value.to_bytes(4,'little');assert raw.count(needle)==1;operand=at+raw.index(needle)
   if value in code:dest='ptr(reinterpret_cast<void*>(&'+symbol+'))'
   elif value in [0x6b7740,0x6b7780]:dest='ptr(&audio_stream_service_storage_006b7740)'+('' if value==0x6b7740 else '+64')
   else:dest='ptr(application_audio_device_state_006b48c0.data())+'+str(value-0x6b48c0)
   patches.append(f'require(rd(creation_slab+{operand})==0x{value:08x},"raw creation data");wr(creation_slab+{operand},{dest});')
source+='}\n';(RUN/'audio_stream_creation_561.cpp').write_text(source,encoding='utf-8',newline='\n');(RUN/'translation-evidence.json').write_text(json.dumps(dict(instructions=mapping,positions={f'{v:08x}':p for v,p in positions.items()},bindings=data,code_bindings=code),indent=2)+'\n',encoding='utf-8',newline='\n')
base=RUN.parent/'559-audio-stream-service';cfg=json.loads((base/'native-config.json').read_bytes());fixture=(base/'native-fixture.cpp.in').read_text().split('// New559 scenes')[0]
fixture=fixture.replace('#include "audio_stream_service_559.hpp"','#include "audio_stream_creation_561.hpp"')
def remove_function(text,signature):
 start=text.index(signature);at=text.index('{',start);end=at+1;depth=1
 while depth:depth+=(text[end]=='{')-(text[end]=='}');end+=1
 return text[:start]+text[end:]
for sig in ['I __cdecl application_audio_stream_stop_00567690(U channel)']:fixture=remove_function(fixture,sig)
fixture=fixture.replace('struct State{B heap[8192];','alignas(64) static B creation_areas[2][4096],creation_pool[1024],creation_descriptor[64];\nstruct State{B service_storage[80],service_areas[2][4096],service_pool[1024],service_descriptor[64],service_device[0x18c];U service_inner_slots[16];B heap[8192];')
fixture=fixture.replace('Event events[24]','Event events[64]').replace('trace.count<24','trace.count<64')
fixture=fixture.replace('setup=true;trace={};','setup=true;std::memset(&trace,0,sizeof trace);')
fixture=fixture.replace('    std::memcpy(s.heap,arena,sizeof arena);','    std::memcpy(s.service_storage,&audio_stream_service_storage_006b7740,80);std::memcpy(s.service_areas,creation_areas,sizeof creation_areas);std::memcpy(s.service_pool,creation_pool,sizeof creation_pool);std::memcpy(s.service_descriptor,creation_descriptor,sizeof creation_descriptor);std::memcpy(s.service_device,application_audio_device_state_006b48c0.preceding_data(),sizeof s.service_device);std::memcpy(s.service_inner_slots,audio_stream_slots_006b7cc0,sizeof s.service_inner_slots);\n    std::memcpy(s.heap,arena,sizeof arena);')
fixture+=(RUN/'fixture-creation.inc').read_text().replace('@CREATION_BODIES@','\n    '.join(chunks)).replace('@CREATION_RELOCATIONS@','\n    '.join(patches))
(RUN/'native-fixture.cpp.in').write_text(fixture,encoding='utf-8',newline='\n')
src=(RUN/'audio_stream_creation_561.cpp').relative_to(ROOT).as_posix();cfg.update(run=561,experiment='local/experiments/v2-audio-stream-creation-561',fixture=(RUN/'native-fixture.cpp.in').relative_to(ROOT).as_posix(),pass_marker='audio_stream_creation_original_x86_vs_cpp=PASS',timeout_seconds=180)
cfg['sources']=[src,*cfg['sources']];cfg['include_dirs']=[RUN.relative_to(ROOT).as_posix(),*cfg['include_dirs']];cfg['headers']=[(RUN/x).relative_to(ROOT).as_posix() for x in ['scope-evidence.json','scope-inspect.py','prepare.py','translation-evidence.json','fixture-creation.inc']]
cfg['original_bodies']=[dict(va=b['va'],bytes=b['bytes'],sha256=b['sha256'],token=f'@CREATE_{b["va"].upper()}@') for b in selected]
mutations=[('outer-bound','0x6b7780 // 00567402','0x6b777c // 00567402')]
# Mutation anchors use emitted source symbols, not raw image addresses.
mutations=[('outer-scan','offset audio_stream_service_storage_006b7740+0x40 // 005673fd','offset audio_stream_service_storage_006b7740+0x3c // 005673fd'),('factory-error','jge L00567481 // 00567476','jl L00567481 // 00567476'),('prefix-wrap','sub ecx, eax // 0056743d','add ecx, eax // 0056743d'),('descriptor-copy','mov ecx, 7 // 005674ff','mov ecx, 6 // 005674ff'),('map-store','mov byte ptr [ecx + audio_stream_service_storage_006b7740+0x40], dl','mov byte ptr [ecx + audio_stream_service_storage_006b7740+0x40], cl'),('publish-order','mov dword ptr [esi*4 + audio_stream_service_storage_006b7740], ebp','mov dword ptr [esi*4 + audio_stream_service_storage_006b7740], 0'),('external-flag','test eax, eax // 0056748c','xor eax, eax // 0056748c'),('stop-last','cmp eax, 1 // 005676cc','cmp eax, 2 // 005676cc'),('stop-clear','mov dword ptr [edi*4 + audio_stream_service_storage_006b7740], 0','mov dword ptr [edi*4 + audio_stream_service_storage_006b7740], esi'),('reset-buffer','push 0x54 // 005677eb','push 0x50 // 005677eb'),('reset-voice-count','mov al, byte ptr [esi + 0x32]','mov al, byte ptr [esi + 0x31]'),('lookup-sign','jl L00566d75 // 00566d6b','jle L00566d75 // 00566d6b'),('cleanup-16','cmp esi, 0x10 // 00566d4d','cmp esi, 0xf // 00566d4d'),('registration-late','mov al, byte ptr [application_audio_device_state_006b48c0+0xf1] // 0058ff62','mov al, 0 // 0058ff62'),('unregister-first','je L0058ff99 // 0058ff8c','jne L0058ff99 // 0058ff8c'),('callback-count-dec','dec bl // 0058ff99','inc bl // 0058ff99')]
for name,old,new in mutations:assert source.count(old)==1,(name,old,source.count(old))
cfg['mutations']=[dict(name=name,source=src,old=old,new=new,expected_exit=1,failure_marker='divergence') for name,old,new in mutations]
(RUN/'native-config.json').write_text(json.dumps(cfg,indent=2)+'\n',encoding='utf-8',newline='\n');print('prepared561 8body909B/80B/16controls')
