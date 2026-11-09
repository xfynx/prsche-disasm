"""One lifecycle batch, shared native runner and existing canonical support TUs."""
from pathlib import Path
import hashlib,json,re,struct,sys
ROOT=Path(__file__).resolve().parents[5];RUN=Path(__file__).resolve().parent
sys.path[:0]=[str(ROOT/'local/tools/python-unicorn')]
import capstone
e=json.loads((RUN/'scope-evidence.json').read_bytes());sha=lambda b:hashlib.sha256(b).hexdigest();src=(RUN/'application_audio_lifecycle_556.cpp').relative_to(ROOT).as_posix()
bodies=[];patches=[];chunks=[];md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32);md.detail=True
calls={0x5365e0:'reinterpret_cast<void*>(&window_scheduler_register_005365e0)',0x5366a0:'reinterpret_cast<void*>(&window_scheduler_remove_005366a0)',0x531f90:'reinterpret_cast<void*>(&free_00531f90)',0x5678c0:'reinterpret_cast<void*>(&application_audio_stream_estimate_005678c0)',0x561960:'reinterpret_cast<void*>(&application_audio_stream_descriptor_00561960)',0x567660:'reinterpret_cast<void*>(&application_audio_stream_begin_00567660)',0x567690:'reinterpret_cast<void*>(&application_audio_stream_stop_00567690)'}
data={0x656ab4:'&audio_resource_query_root_00656ab4',0x655d30:'&application_audio_selected_channel_00655d30',0x4ad9c0:'reinterpret_cast<void*>(&application_audio_service_callback_004ad9c0)'}
for va,offset in [(0x4ae010,0),(0x4ae2b0,0x100),(0x4ae310,0x200)]:
 row=next(b for b in e['bodies'] if int(b['va'],16)==va);b=bytes.fromhex(row['raw_hex']);token=f'@BODY_{va:08X}@';bodies.append(dict(va=row['va'],bytes=row['bytes'],sha256=row['sha256'],token=token))
 chunks.append(f'const B raw_{va:x}[]={{'+token+f'}};std::memcpy(slab+{offset},raw_{va:x},sizeof raw_{va:x});')
 for i in md.disasm(b,va):
  at=offset+i.address-va
  if i.mnemonic=='call':
   target=int(i.op_str,16);assert target in calls
   patches.append(f'require(rd(slab+{at+1})==0x{int.from_bytes(i.bytes[1:],"little"):08x},"raw child operand");wr(slab+{at+1},ptr({calls[target]})-ptr(slab+{at+5}));')
  for value,target in data.items():
   needle=value.to_bytes(4,'little');position=i.bytes.find(needle)
   if position>=0:patches.append(f'require(rd(slab+{at+position})==0x{value:x},"raw global/callback operand");wr(slab+{at+position},ptr({target}));')
fixture=(RUN/'fixture-lifecycle.inc').read_text().replace('@ORIGINAL_BODIES@','\n    '.join(chunks)).replace('@ORIGINAL_RELOCATIONS@','\n    '.join(patches))
(RUN/'native-fixture.cpp.in').write_text(fixture,encoding='utf-8',newline='\n')
source=(ROOT/src).read_text()
mutations=[('divide40','signed_configuration/40','signed_configuration/41'),('divide1024','signed_configuration/1024','static_cast<I>(configuration>>10)'),('required-wrap','estimated+configuration','estimated'),('descriptor-byte8','descriptor[8]=0;','descriptor[8]=1;'),('descriptor-byte10','descriptor[10]=0;','descriptor[10]=1;'),('configure-root-late','object=audio_resource_query_root_00656ab4;descriptor[8]','descriptor[8]'),('begin-root-late','object=audio_resource_query_root_00656ab4;store(object+0x70,static_cast<U>(channel));','store(object+0x70,static_cast<U>(channel));'),('stop-root-late','object=audio_resource_query_root_00656ab4;store(object+0x70,0xffffffffu);','store(object+0x70,0xffffffffu);'),('channel-signed','static_cast<I>(channel)>=0','channel>0'),('prepare-clear','store(object+0x7c,0);return true;','store(object+0x7c,1);return true;'),('selected-channel','application_audio_selected_channel_00655d30=word(object+0x70);','application_audio_selected_channel_00655d30=0;'),('registered-mark','object=audio_resource_query_root_00656ab4;store(object+0x78,1);','object=audio_resource_query_root_00656ab4;store(object+0x78,0);'),('shutdown-late-resource','object=audio_resource_query_root_00656ab4;\n    const U second','\n    const U second'),('shutdown-clear','audio_resource_query_root_00656ab4=0;','audio_resource_query_root_00656ab4=object;')]
for name,old,new in mutations:assert source.count(old)==1,(name,source.count(old))
cfg=dict(run=556,experiment='local/experiments/v2-application-audio-lifecycle-556',original_pe='local/game/Porsche.exe',original_sha256=e['module_sha256'],sources=[src,'iterations/v2/001-original-recovery/runs/478-audio-resource-controls/audio_resource_controls_478.cpp',*[f'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/{name}.cpp' for name in ['window_scheduler','window_runtime','shared_runtime_globals','heap']]],fixture=(RUN/'native-fixture.cpp.in').relative_to(ROOT).as_posix(),include_dirs=[RUN.relative_to(ROOT).as_posix(),'iterations/v2/001-original-recovery/source/include'],headers=[(RUN/name).relative_to(ROOT).as_posix() for name in ['scope-evidence.json','callback-index-supplement.json','scope-inspect.py','prepare.py','fixture-lifecycle.inc']],original_bodies=bodies,pass_marker='application_audio_lifecycle_original_x86_vs_cpp=PASS',timeout_seconds=120,mutations=[dict(name=name,source=src,old=old,new=new,expected_exit=1,failure_marker='divergence') for name,old,new in mutations])
(RUN/'native-config.json').write_text(json.dumps(cfg,indent=2)+'\n',encoding='utf-8',newline='\n');print('prepared556',len(bodies),'bodies',len(mutations),'controls')
