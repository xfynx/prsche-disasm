"""Extend unchanged534 fixture scaffolding with only new550 codec caller scenes."""
from pathlib import Path
import hashlib,importlib.util,json,re,sys
ROOT=Path(__file__).resolve().parents[5];RUN=Path(__file__).resolve().parent
sys.path[:0]=[str(ROOT/'local/tools/python-unicorn')]
import capstone
spec=importlib.util.spec_from_file_location('n550prepare',ROOT/'scripts/research/verify-v2-native-batch.py');n=importlib.util.module_from_spec(spec);spec.loader.exec_module(n)
base=RUN.parent/'534-audio-nibble-process'
cfg=json.loads((base/'native-config.json').read_text());source=(RUN/'audio_codec_process_550.cpp').relative_to(ROOT).as_posix()
cfg.update(run=550,experiment='local/experiments/v2-audio-codec-frontier-550',fixture=(RUN/'native-fixture.cpp.in').relative_to(ROOT).as_posix(),pass_marker='audio_codec_process_original_x86_vs_cpp=PASS',timeout_seconds=120)
cfg['sources']=[source,*cfg['sources']];cfg['include_dirs']=[RUN.relative_to(ROOT).as_posix(),*cfg['include_dirs']]
cfg['headers']=[(RUN/f).relative_to(ROOT).as_posix() for f in ['scope-evidence.json','original-index-supplement.json','fixture-codec.inc','prepare.py']]
fixture=(base/'native-fixture.cpp.in').read_text().split('int main(){')[0]
fixture=fixture.replace('#include "audio_nibble_process_534.hpp"','#include "audio_nibble_process_534.hpp"\n#include "audio_codec_process_550.hpp"\nstatic void codec_released(unsigned);\nstatic void codec_consumed(unsigned,unsigned);')
for name in ['audio_adpcm_process_00597e30','audio_adpcm_stream_process_0059c1e0','audio_resampler_stream_process_0059b690']:
    stub=f'I __cdecl {name}(U,U,U,U,U){{ExitProcess(90);return 0;}}\n'
    assert fixture.count(stub)==1;fixture=fixture.replace(stub,'')
fixture=fixture.replace('static void __cdecl released(U value){','static void __cdecl released(U value){\n    if(active_kind>=100){codec_released(value);return;}')
fixture=fixture.replace('static void __cdecl consumed(U index,U count){','static void __cdecl consumed(U index,U count){\n    if(active_kind>=100){codec_consumed(index,count);return;}')
raw=(ROOT/'local/game/Porsche.exe').read_bytes();sha=lambda b:hashlib.sha256(b).hexdigest()
defs=[(0x597e30,232,0),(0x59c1e0,378,0x200),(0x59b690,404,0x400),(0x59a800,190,0x600),(0x59a8c0,74,0x700),(0x58fef0,31,0x800)]
targets={0x598a50:'slab+0x800',0x561800:'slab+0xc00',0x5618c0:'slab+0xd00',0x59a800:'codec_slab+0x600',0x59a8c0:'codec_slab+0x700',0x58fef0:'codec_slab+0x800',0x59a910:'reinterpret_cast<void*>(&audio_adpcm_decode_0059a910)',0x597810:'reinterpret_cast<void*>(&audio_resampler_decode_00597810)'}
scalars={0x5b2608:'&audio_adpcm_scale_005b2608',0x5b27b4:'&audio_adpcm_factor_scale_005b27b4',0x5c1804:'&audio_adpcm_factor_bias_005c1804',0x5e34a0:'audio_adpcm_bit_masks_005e34a0'}
chunks=[];patches=[];md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
for va,size,offset in defs:
    data=n.pe_at(raw,va,size);token=f'@CODEC_{va:08X}@';cfg['original_bodies'].append(dict(va=f'{va:08x}',bytes=size,sha256=sha(data),token=token))
    chunks.append(f'const B raw_{va:x}[]={{'+token+f'}};std::memcpy(codec_slab+{offset},raw_{va:x},sizeof(raw_{va:x}));')
    for ins in md.disasm(data,va):
        if ins.mnemonic=='call' and ins.bytes[0]==0xe8:
            target=int(ins.op_str,16);assert target in targets,(hex(va),ins.op_str)
            at=offset+ins.address-va
            patches.append(f'require(rd(codec_slab+{at+1})==0x{int.from_bytes(ins.bytes[1:],"little"):08x},"raw codec relative operand");wr(codec_slab+{at+1},ptr({targets[target]})-ptr(codec_slab+{at+5}));')
    for original,target in scalars.items():
        needle=original.to_bytes(4,'little');start=0
        while (at:=data.find(needle,start))>=0:
            patches.append(f'require(rd(codec_slab+{offset+at})==0x{original:x},"raw codec data operand");wr(codec_slab+{offset+at},ptr({target}));');start=at+4
extra=(RUN/'fixture-codec.inc').read_text().replace('@CODEC_RAW@','\n    '.join(chunks)).replace('@CODEC_RELOC@','\n    '.join(patches))
for token,va,size in [('MASKS',0x5e34a0,36),('SCALE',0x5b2608,4),('FACTOR',0x5b27b4,4),('BIAS',0x5c1804,4)]:
    data=n.pe_at(raw,va,size);cfg['original_bodies'].append(dict(va=f'{va:08x}',bytes=size,sha256=sha(data),token=f'@{token}550@'))
fixture+=extra
(RUN/'native-fixture.cpp.in').write_text(fixture,encoding='utf-8',newline='\n')
mutations=[
('position-unsigned','if(position>=limit)','if(static_cast<I>(position)>=static_cast<I>(limit))'),
('position-advance','const U advanced=position+requested;','const U advanced=position;'),
('carry-late','U late=word(object+0xd50);remaining-=count;output+=count*4u;store(object+0xd50,late-count);','U late=prior;remaining-=count;output+=count*4u;store(object+0xd50,late-count);'),
('carry-origin','object+(0x353u-prior)*4u','object+(0x353u-prior)*4u+4u'),
('block432','store(object+0xd50,0x1b0);count=minimum(remaining,0x1b0);','store(object+0xd50,0x1af);count=minimum(remaining,0x1af);'),
('silence-missing','if(static_cast<I>(overflow)>0){U left=overflow;','if(false){U left=overflow;'),
('stream-ack-order','if(pending){audio_stream_acknowledge_005618c0(word(object+0xd54),byte(object+0xd60),pending);store(object+0xd58,0);}','if(pending){store(object+0xd58,0);audio_stream_acknowledge_005618c0(word(object+0xd54),byte(object+0xd60),pending);}'),
('marker-reset','if(byte(data)){shalf(object+0xd5e,0);','if(byte(data)){'),
('rawbit-reset','store(object+0x14,8);','store(object+0x14,7);'),
('adpcm-half-late','shalf(object+0xd5c,half(object+0xd5c)+count);shalf(object+0xd5e,half(object+0xd5e)-count);','shalf(object+0xd5c,half(object+0xd5c)+count);shalf(object+0xd5e,buffered-count);'),
('stream-silence','if(processed)application_audio_backend_configure_0058fef0','if(true)application_audio_backend_configure_0058fef0'),
('stream-return','return static_cast<I>(word(object+0xd58));','return 1;'),
('resampler-ack-order','if(pending){audio_stream_acknowledge_005618c0(word(object+0xe0),byte(object+0xec),pending);store(object+0xe4,0);}','if(pending){store(object+0xe4,0);audio_stream_acknowledge_005618c0(word(object+0xe0),byte(object+0xec),pending);}'),
('resampler160','shalf(object+0xea,0xa0);','shalf(object+0xea,0x9f);'),
('resampler-position-late','const U position=half(object+0xe8);remaining-=count;','const U position=0;remaining-=count;'),
('resampler-silence','if(processed)zero_words(output,remaining*4u);','if(true)zero_words(output,remaining*4u);'),
('resampler-return','return static_cast<I>(word(object+0xe4));','return 1;')]
text=(ROOT/source).read_text()
for name,old,new in mutations:assert text.count(old)==1,(name,text.count(old))
cfg['mutations']=[dict(name=name,source=source,old=old,new=new,expected_exit=1,failure_marker='divergence') for name,old,new in mutations]
(RUN/'native-config.json').write_text(json.dumps(cfg,indent=2)+'\n',encoding='utf-8',newline='\n')
print('prepared550',len(defs),'new/rawsupport chunks;',len(mutations),'controls')
