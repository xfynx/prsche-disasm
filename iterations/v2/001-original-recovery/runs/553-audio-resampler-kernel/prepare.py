"""Prepare one553 exact-x87 production body and shared native fixture/config."""
from pathlib import Path
import hashlib,json,re,struct
ROOT=Path(__file__).resolve().parents[5];RUN=Path(__file__).resolve().parent
e=json.loads((RUN/'scope-evidence.json').read_text());sha=lambda b:hashlib.sha256(b).hexdigest()
kernel=next(b for b in e['bodies'] if b['va']=='00597810')
symbols={int(d['va'],16):'audio_resampler_scalar_'+d['va'] for d in e['data']}
header='#pragma once\n#include "../550-audio-codec-frontier/audio_codec_process_550.hpp"\n#include "../522-audio-stream-transform/audio_stream_transform_522.hpp"\nnamespace porsche {\n'
source='// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39\n// Original678B LPC/noise-pulse synthesis; exact x87/order/spills and aliasing.\n#include "audio_resampler_kernel_553.hpp"\n#if !defined(_MSC_VER) || !defined(_M_IX86)\n#error Original x87 semantics require MSVC x86\n#endif\nnamespace porsche {\n'
for d in e['data']:
 typ='std::uint64_t' if d['bytes']==8 else 'std::uint32_t';sym=symbols[int(d['va'],16)]
 header+=f'extern const {typ} {sym};\n';source+=f'const {typ} {sym}=0x{int.from_bytes(bytes.fromhex(d["raw_hex"]),"little"):0{d["bytes"]*2}x}'+('ull' if d['bytes']==8 else 'u')+';\n'
header+='// Original rand5a17c9 remains a real unresolved cdecl0 provider.\nstd::int32_t __cdecl audio_resampler_rand_005a17c9();\n}\n'
(RUN/'audio_resampler_kernel_553.hpp').write_text(header,encoding='utf-8',newline='\n')
source+='// Packet: u16 period/256,u8 gain/256,10 signed coefficient bytes/128.\n// State: old period/gain,coefficients,10 history values and countdown+c0.\n// Descending ten-stage lattice preserves live80-bit values and qword spills.\n__declspec(naked) void __cdecl audio_resampler_decode_00597810(std::uint32_t,std::uint32_t,std::uint32_t){\n    __asm {\n'
labels={int(i['asm'].split()[-1],16) for i in kernel['instructions'] if re.match(r'j\w+ 0x',i['asm'])}
for i in kernel['instructions']:
 va=int(i['va'],16);asm=i['asm']
 if va in labels:source+=f'    L{va:x}:\n'
 if re.match(r'j\w+ 0x',asm):asm=asm.split()[0]+' L'+asm.split()[-1][2:]
 if asm=='call 0x5a17c9':asm='call audio_resampler_rand_005a17c9'
 if asm=='call 0x5a0f98':asm='call audio_stream_ftol_005a0f98'
 for address,symbol in symbols.items():asm=asm.replace(f'[0x{address:x}]',f'[{symbol}]')
 asm=re.sub(r'0x([0-9a-f]+)',lambda m:'0'+m[1]+'h',asm)
 if asm in ['fdiv st(1)','fdivr st(2)','fmul st(2)','fadd st(1)']:asm=asm.split()[0]+' st(0),'+asm.split()[1]
 if asm=='fsubp st(3)':asm='fsubp st(3),st(0)'
 if asm.startswith('rep movsd'):asm='rep movsd'
 if asm.startswith('rep stosd'):asm='rep stosd'
 source+='        '+asm+'\n'
source+='    }\n}\n}\n'
(RUN/'audio_resampler_kernel_553.cpp').write_text(source,encoding='utf-8',newline='\n')
base=RUN.parent/'550-audio-codec-frontier';cfg=json.loads((base/'native-config.json').read_text())
fixture=(base/'native-fixture.cpp.in').read_text().split('int main(){')[0]
fixture=fixture.replace('#include "audio_codec_process_550.hpp"','#include "audio_resampler_kernel_553.hpp"')
def remove_function(text,signature):
 start=text.index(signature);opening=text.index('{',start);depth=1;end=opening+1
 while depth:
  depth+=(text[end]=='{')-(text[end]=='}');end+=1
 return text[:start]+text[end:]
fixture=remove_function(fixture,'void __cdecl audio_resampler_decode_00597810(U input,U output,U state)')
fixture=remove_function(fixture,'void __cdecl audio_stream_transform_00597660(U input,U output)')
fixture+='\nnamespace porsche {\nvoid __cdecl audio_stream_metric_00597360(U,U){ExitProcess(90);}\nvoid __cdecl audio_stream_coefficients_00597180(U,I,U,U){ExitProcess(90);}\n}\n'
fixture+=(RUN/'fixture-kernel.inc').read_text()
cfg.update(run=553,experiment='local/experiments/v2-audio-resampler-kernel-553',fixture=(RUN/'native-fixture.cpp.in').relative_to(ROOT).as_posix(),pass_marker='audio_resampler_kernel_original_x86_vs_cpp=PASS',timeout_seconds=120)
cfg['sources']=[(RUN/'audio_resampler_kernel_553.cpp').relative_to(ROOT).as_posix(),(RUN.parent/'522-audio-stream-transform/audio_stream_transform_522.cpp').relative_to(ROOT).as_posix(),*cfg['sources']]
cfg['include_dirs']=[RUN.relative_to(ROOT).as_posix(),*cfg['include_dirs']]
cfg['headers']=[(RUN/x).relative_to(ROOT).as_posix() for x in ['scope-evidence.json','scope-inspect.py','prepare.py','fixture-kernel.inc']]
cfg['original_bodies']+=[dict(va=b['va'],bytes=b['bytes'],sha256=b['sha256'],token='@KERNEL553@' if b['va']=='00597810' else '@FTOL553@') for b in e['bodies'] if b['va'] in ['00597810','005a0f98']]
patches=[]
for i in kernel['instructions']:
 raw=bytes.fromhex(i['raw']);at=int(i['va'],16)-0x597810
 if i['asm'].startswith('call '):
  target='reinterpret_cast<void*>(&audio_resampler_rand_005a17c9)' if '5a17c9' in i['asm'] else 'kernel_slab+0x300'
  patches.append(f'wr(kernel_slab+{at+1},ptr({target})-ptr(kernel_slab+{at+5}));')
 for address,symbol in symbols.items():
  if f'[0x{address:x}]' in i['asm']:
   assert raw[-4:]==address.to_bytes(4,'little');patches.append(f'wr(kernel_slab+{at+len(raw)-4},ptr(&{symbol}));')
fixture=fixture.replace('@KERNEL_RELOC553@','\n    '.join(patches))
checks='\n'.join(f'const B d_{d["va"]}[]={{'+','.join('0x'+d['raw_hex'][i:i+2] for i in range(0,len(d['raw_hex']),2))+'};require(std::memcmp(d_'+d['va']+',&'+symbols[int(d['va'],16)]+','+str(d['bytes'])+')==0,"canonical original scalar '+d['va']+'");' for d in e['data'])
fixture=fixture.replace('@DATA_CHECK553@',checks)
(RUN/'native-fixture.cpp.in').write_text(fixture,encoding='utf-8',newline='\n')
mutations=[('signed-coefficient','movsx esi, byte ptr [edx + eax + 3]','movzx esi, byte ptr [edx + eax + 3]'),('history-subtract','fsubp st(3),st(0)','faddp st(3),st(0)'),('history-store','fstp qword ptr [ecx + 8]','fstp qword ptr [ecx + 010h]'),('countdown','dec eax','inc eax'),('block-count','mov edi, 0a0h','mov edi, 09fh'),('smoothing-order','fsub qword ptr [ebx + 8]','fadd qword ptr [ebx + 8]'),('gain-order','fmul qword ptr [esp + 020h]','fadd qword ptr [esp + 020h]'),('clipping','test ah, 041h','test ah, 040h'),('state-period','mov dword ptr [ebx], eax','mov dword ptr [ebx], edx')]
for name,old,new in mutations:assert source.count(old)==1,(name,old,source.count(old))
cfg['mutations']=[dict(name=name,source=(RUN/'audio_resampler_kernel_553.cpp').relative_to(ROOT).as_posix(),old=old,new=new,expected_exit=1,failure_marker='divergence') for name,old,new in mutations]
(RUN/'native-config.json').write_text(json.dumps(cfg,indent=2)+'\n',encoding='utf-8',newline='\n')
print('prepared553 kernel/data and shared550/522 support,9 controls')
