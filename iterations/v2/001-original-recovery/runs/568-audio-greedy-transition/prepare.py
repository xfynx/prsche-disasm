"""Extend the frozen 565 oracle with two original bodies and real file lists."""
from pathlib import Path
import hashlib,importlib.util,json,re,sys
ROOT=Path(__file__).resolve().parents[5];RUN=Path(__file__).resolve().parent
sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'));import capstone
old=RUN.parent/'565-audio-stream-codec-lifecycle';cfg=json.loads((old/'native-config.json').read_bytes());scope=json.loads((RUN/'scope-evidence.json').read_bytes());rows={x['va']:x for x in scope['bodies']}
spec=importlib.util.spec_from_file_location('native568',ROOT/'scripts/research/verify-v2-native-batch.py');native=importlib.util.module_from_spec(spec);spec.loader.exec_module(native)
raw=(ROOT/'local/game/Porsche.exe').read_bytes();assert hashlib.sha256(raw).hexdigest()==cfg['original_sha256']
positions={0x56b540:0x400,0x5681b0:0x500};md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32);chunks=[];patches=[]
absolute={0x5debf0:'ptr(&diagnostic_handler_005debf0)',0x5deb74:'ptr(&shared_runtime_word_005deb74)',0x5deb78:'ptr(&shared_runtime_word_005deb78)',0x5bdb24:'ptr(transition_message)',0x6a5c7c:'ptr(&devices_006a5c7c)',0x567bf0:'ptr(reinterpret_cast<void*>(&operation_matches_00567bf0))'}
for va,off in positions.items():
 row=rows[f'{va:08x}'];data=bytes.fromhex(row['raw_hex']);chunks.append(f'const B body_{va:08x}[]={{@BODY_{va:08X}@}};std::memcpy(slab+{off},body_{va:08x},sizeof body_{va:08x});')
 for ins in md.disasm(data,va):
  pos=off+ins.address-va;op=ins.op_str
  if ins.mnemonic=='call' and op.startswith('0x'):
   target=int(op,16);dest={0x56b380:'slab',0x5681b0:'slab+0x500',0x580c10:'reinterpret_cast<void*>(&io_take_00580c10)',0x568200:'reinterpret_cast<void*>(&operation_queue_00568200)'}[target]
   patches.append(f'require(rd(slab+{pos+1})==0x{int.from_bytes(ins.bytes[1:],"little"):08x},"raw 568 call");wr(slab+{pos+1},ptr({dest})-ptr(slab+{pos+5}));')
  for value,dest in absolute.items():
   if not re.search(r'\b'+hex(value)+r'\b',op):continue
   b=value.to_bytes(4,'little');assert ins.bytes.count(b)==1;at=pos+ins.bytes.index(b)
   patches.append(f'require(rd(slab+{at})==0x{value:08x},"raw 568 data");wr(slab+{at},{dest});')
fixture=(old/'native-fixture.cpp.in').read_text(encoding='utf-8').split('int main(){')[0]
fixture=fixture.replace('#include "audio_codec_access_565.hpp"','#include "audio_codec_access_565.hpp"\n#include "audio_greedy_transition_568.hpp"')
fixture=fixture.replace('static B* slab;','static B* slab;static FileDevice test_devices[32];static FileOperation test_ops[2];static U scene;')
fixture=fixture.replace('struct Snapshot{B memory[1024],slots[80];','struct Snapshot{B devices[sizeof test_devices],operations[sizeof test_ops],memory[1024],slots[80];')
fixture=fixture.replace('Event events[4]','Event events[32]').replace('trace.count<4','trace.count<32')
fixture=fixture.replace(' std::memcpy(s.memory,arena,sizeof arena);',' std::memcpy(s.devices,test_devices,sizeof test_devices);std::memcpy(s.operations,test_ops,sizeof test_ops);std::memcpy(s.memory,arena,sizeof arena);')
fixture=fixture.replace('void (__cdecl* diagnostic_handler_005debf0)(const char*)=file_diagnostic_00565340;\n','')
fixture=fixture.replace('void __cdecl audio_stream_greedy_transition_0056b540(U h,U value){auto& e=event(2,h,value);e.value=rd(arena+128+alignment+0x34);}\n','')
fixture=fixture.replace('void __cdecl heap_enter_005322b0(void*){ExitProcess(90);}','void __cdecl heap_enter_005322b0(void* p){event(3,ptr(p));}')
fixture=fixture.replace('void __cdecl heap_leave_005322c0(void*){ExitProcess(90);}','void __cdecl heap_leave_005322c0(void* p){event(4,ptr(p));}')
fixture=fixture.replace('void __cdecl file_diagnostic_00565340(const char* message)', 'U __cdecl file_event_signal_0055fb30(void* p){event(5,ptr(p));return 1;}\nvoid __cdecl file_diagnostic_00565340(const char* message)')
fixture=fixture.replace('static const char path_string[]=', 'static const B transition_original[]={@STRING_TRANSITION@};\nstatic const char transition_message[]="STREAM_setgreedystate - invalid stream handle\\n";\nstatic const char path_string[]=')
needle=' require(FlushInstructionCache(GetCurrentProcess(),slab,4096)!=0,"cache");'
fixture=fixture.replace(needle,'\n '.join(chunks+patches)+'\n wr(slab+368,ptr(slab+0x400)-ptr(slab+372));\n'+needle)
fixture=fixture.replace('static void execute(bool cpp){','static void prepare_group_scene(U object);\nstatic void execute(bool cpp){')
fixture=fixture.replace(' seed();U args[3]={};',' prepare_group_scene(object);seed();U args[3]={};')
fixture=fixture.replace(' trace.abi|=invoke(f,args,argc);',' if(which==4){f=cpp?reinterpret_cast<void*>(&audio_stream_greedy_transition_0056b540):slab+0x400;args[0]=(variant&8)?0:handle;args[1]=level;argc=2;}\n if(which==5){f=cpp?reinterpret_cast<void*>(&file_operation_set_group_005681b0):slab+0x500;args[0]=(scene==3)?1u:((scene==6)?0xfedcba1fu:5u);args[1]=level;argc=2;}\n trace.abi|=invoke(f,args,argc);')
fixture=fixture.replace('(which!=1&&captured_return!=expected_return)','(which!=1&&which!=4&&which!=5&&captured_return!=expected_return)')
fixture+=(RUN/'fixture-extension.inc').read_text(encoding='utf-8');(RUN/'native-fixture.cpp.in').write_text(fixture,encoding='utf-8',newline='\n')
source=(RUN/'audio_greedy_transition_568.cpp').relative_to(ROOT).as_posix();cfg.update(run=568,experiment='local/experiments/v2-audio-greedy-transition-568',fixture=(RUN/'native-fixture.cpp.in').relative_to(ROOT).as_posix(),pass_marker='audio_greedy_transition_original_x86_vs_cpp=PASS',timeout_seconds=180)
cfg['sources']=[source,*cfg['sources'],'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/files.cpp','iterations/v2/001-original-recovery/source/recovered/Porsche.exe/io_lists.cpp'];cfg['include_dirs'].insert(0,RUN.relative_to(ROOT).as_posix());cfg['headers']=[(RUN/x).relative_to(ROOT).as_posix() for x in ['scope-evidence.json','scope-inspect.py','prepare.py','fixture-extension.inc']]
cfg['original_bodies'] += [dict(va=f'{v:08x}',bytes=rows[f'{v:08x}']['bytes'],sha256=rows[f'{v:08x}']['sha256'],token=f'@BODY_{v:08X}@') for v in positions]
data=native.pe_at(raw,0x5bdb24,128).split(b'\0',1)[0]+b'\0';cfg['original_bodies'].append(dict(va='005bdb24',bytes=len(data),sha256=hashlib.sha256(data).hexdigest(),token='@STRING_TRANSITION@'))
edits=[('state-write','put(object+0x38,state)','put(object+0x38,state&255u)'),('state-gate','if(state&&word(object+0x28)==1)','if(!state&&word(object+0x28)==1)'),('mode-gate','word(object+0x28)==1','word(object+0x28)!=1'),('device-index','(id&31u)*0x70u','(id&15u)*0x70u'),('group-byte','static_cast<std::uint8_t>(group)','static_cast<std::uint8_t>(group>>8)'),('lookup-id','operation_matches_00567bf0,id','operation_matches_00567bf0,id+1u')]
text=(ROOT/source).read_text(encoding='utf-8');assert all(text.count(x)==1 for _,x,_ in edits)
cfg['mutations']=[dict(name=n,source=source,old=a,new=b,expected_exit=1,failure_marker='divergence') for n,a,b in edits]
cfg['mutations'].append(dict(name='wrapped-zero',source=source,old='if(device==0)return;',new='if(base==0)return;',expected_exit=98,failure_marker='native-fault'))
(RUN/'native-config.json').write_text(json.dumps(cfg,indent=2)+'\n',encoding='utf-8',newline='\n');print('568 prepared 2 bodies/178B/7 controls')
