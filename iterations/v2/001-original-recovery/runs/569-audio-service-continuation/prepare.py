"""Derive Run569 fixture from unchanged accepted Run565 support scaffold."""
from pathlib import Path
import json
root=Path(__file__).resolve().parents[5];run=Path(__file__).resolve().parent
base=root/'iterations/v2/001-original-recovery/runs/565-audio-stream-codec-lifecycle'
fixture=(base/'native-fixture.cpp.in').read_text(encoding='utf-8')
prefix=fixture[:fixture.index('static void init_slab(){')]
def change(old,new):
 global prefix
 assert prefix.count(old)==1,repr(old)
 prefix=prefix.replace(old,new)
change('static const B path_original[]={@STRING_PATH@},greedy_original[]={@STRING_GREEDY@},frame_original[]={@STRING_FRAME@};\n','')
change('static const char path_string[]="\\\\real\\\\cmn\\\\stream.c",greedy_message[]="STREAM_setgreedylevel - invalid stream handle\\n",frame_message[]="STREAM_buffersize - invalid stream handle\\n";\n','')
change('U active,file,line;Fpu fp;','U active,file,line,lock;Fpu fp;')
change('struct Event{U tag,a,b,value;','struct Event{U tag,a,b,c,d,value;')
change('s.line=class_error_line_005deb78;','s.line=class_error_line_005deb78;s.lock=application_audio_device_state_006b48c0[0xdf];')
change('static Event& event(U tag,U a=0,U b=0){require(trace.count<4,"events");Event& e=trace.events[trace.count++];e.tag=tag;e.a=a;e.b=b;snapshot(e.state);return e;}',
       'static Event& event(U tag,U a=0,U b=0,U c=0,U d=0){require(trace.count<4,"events");Event& e=trace.events[trace.count++];e.tag=tag;e.a=a;e.b=b;e.c=c;e.d=d;snapshot(e.state);return e;}')
change('void __stdcall platform_enter_critical_section(void*){ExitProcess(90);}', 'void __stdcall platform_enter_critical_section(void* p){event(30,ptr(p));}')
change('void __stdcall platform_leave_critical_section(void*){ExitProcess(90);}', 'void __stdcall platform_leave_critical_section(void* p){event(31,ptr(p));}')
change('void __cdecl audio_stream_service_tick_00567270(){ExitProcess(90);}', '''void __cdecl audio_stream_service_tick_00567270(){ExitProcess(90);}
I __cdecl audio_service_stream_start_00567550(U,U,U,U,U);
U __cdecl audio_stream_codec_memory_0056b690(U a,U b,U c,U d){auto& e=event(20,a,b,c,d);e.value=level;return level;}
U __cdecl audio_stream_codec_file_0056c040(U a,U b,U c,U d){auto& e=event(21,a,b,c,d);e.value=level;return level;}''')
fixture_out=prefix+(run/'fixture-body.inc').read_text(encoding='utf-8')
(run/'native-fixture.cpp.in').write_text(fixture_out,encoding='utf-8',newline='\n')
cfg=json.loads((base/'native-config.json').read_bytes())
source='iterations/v2/001-original-recovery/runs/569-audio-service-continuation/audio_service_continuation_569.cpp'
cfg.update(run=569,experiment='local/experiments/v2-audio-service-continuation-569',fixture='iterations/v2/001-original-recovery/runs/569-audio-service-continuation/native-fixture.cpp.in',pass_marker='audio_service_continuation_original_x86_vs_cpp=PASS')
cfg['sources'].insert(0,source)
cfg['headers']=['iterations/v2/001-original-recovery/runs/569-audio-service-continuation/scope-evidence.json','iterations/v2/001-original-recovery/runs/569-audio-service-continuation/fixture-body.inc','iterations/v2/001-original-recovery/runs/569-audio-service-continuation/prepare.py']
cfg['original_bodies']=[{'va':'00567550','bytes':267,'sha256':'b9eeaa6a11b9823aee36d503f54fdf85d06b29c71c5f18d423f6f98b4a64e76c','token':'@BODY_00567550@'}]
changes=[('capacity','jl has_space','jle has_space'),('generation','add ecx,0x100','add ecx,0x101'),('data_mode','cmp eax,1','cmp eax,2'),('word','mov word ptr [esi+0x28],ax','mov word ptr [esi+0x28],bx'),('index','inc cl','add cl,2'),('error','mov eax,0xfffffff6','mov eax,0xfffffff5')]
cfg['mutations']=[dict(name=name,source=source,old=old,new=new,expected_exit=1,failure_marker='divergence') for name,old,new in changes]
(run/'native-config.json').write_text(json.dumps(cfg,indent=2)+'\n',encoding='utf-8',newline='\n')
print('prepared',len(cfg['sources']),'sources',len(changes),'mutations')
