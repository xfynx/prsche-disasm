"""Prepare one diagnostic packet with reused native transport/canonical owners."""
import hashlib,importlib.util,json,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[5];RUN=Path(__file__).resolve().parent
rel=lambda p:p.relative_to(ROOT).as_posix();load=lambda p:json.loads(p.read_bytes());sha=lambda b:hashlib.sha256(b).hexdigest()
scope=load(ROOT/'local/reports/resource-next-549-evidence.json')
spec=importlib.util.spec_from_file_location('native549',ROOT/'scripts/research/verify-v2-native-batch.py');native=importlib.util.module_from_spec(spec);spec.loader.exec_module(native)
pe=(ROOT/'local/game/Porsche.exe').read_bytes();assert sha(pe)==scope['original_sha256']
raw_slot=native.pe_at(pe,0x554bd0,228)
scope['actual546composition']=dict(entry_va='00554bd0',bytes=228,sha256=sha(raw_slot),raw_hex=raw_slot.hex(),boundary='full32-slot capacity only;diagnostic549actual and controlled noreturn process endpoint;other546children fail closed')
scope['raw_body_child_transport']='New116B calls actual canonical345 startup and353vsprintf/formatter entry on both sides;unchanged accepted child proof reused,underlying core/config/device endpoints controlled'
(RUN/'scope-evidence.json').write_text(json.dumps(scope,indent=2)+'\n',encoding='utf8',newline='\n')
text=(RUN/'fixture-body.inc').read_text(encoding='utf8');near=(RUN.parent/'546-render-resource-allocation/native-fixture.cpp.in').read_text(encoding='utf8')
text=text.replace('@ABI_X87_HELPERS@',near[near.index('static void capture(Fpu& f)'):near.index('static void event(U tag')])
text=text.replace('@RELOCATORS@',near[near.index('static void absolute(B*'):near.index('static void init()')])
for token,va,size in [('INITIAL_DEVICES',0x5e1c88,100),('INITIAL_CHANNELS',0x5df4a0,512),('FORMAT_DATA',0x5df16c,280)]:text=text.replace('@'+token+'@',','.join(f'0x{x:02x}' for x in native.pe_at(pe,va,size)))
absolute={0x6a3a44:'&render_texture_slot_count_006a3a44',0x5df16c:'raw_table',0x5bc208:'render_texture_capacity_message_005bc208'}
for va in [0x6a33fc,0x6a3400,0x6a3404,0x6a3408,0x6a340c,0x6a3a04]:absolute[va]=f'raw_slots+{va-0x6a33f8}'
relocs=[]
for va,target in absolute.items():
 count=raw_slot.count(struct.pack('<I',va));assert count
 relocs.append(f'absolute(code[1],228,0x{va:x},{target},{count});')
for va,target in [(0x55ec50,'code[0]'),(0x5a246e,'reinterpret_cast<void*>(&process_exit_005a246e)')]:relocs.append(f'relative(code[1],228,0x554bd0,0x{va:x},{target},1);')
text=text.replace('@SLOT_RELOCATIONS@','\n    '.join(relocs));(RUN/'native-fixture.cpp.in').write_text(text,encoding='utf8',newline='\n')
source=rel(RUN/'render_diagnostic_549.cpp');production=(ROOT/source).read_text(encoding='utf8');controls=[
('startup-gate','if(!application_diagnostic_started_006a57cc)application_secondary_start();','if(application_diagnostic_started_006a57cc)application_secondary_start();'),
('channel-mask','application_diagnostic_channels_005df4a0[channel].flags&1','application_diagnostic_channels_005df4a0[channel].flags&2'),
('channel-index','application_diagnostic_channels_005df4a0[channel].flags','application_diagnostic_channels_005df4a0[(channel+1)&63].flags'),
('channel-disabled','    if(!(application_diagnostic_channels_005df4a0[channel].flags&1))return;',''),
('varargs-offset','reinterpret_cast<const std::uint32_t*>(arguments)','reinterpret_cast<const std::uint32_t*>(arguments)+1'),
('formatter-result','(void)application_diagnostic_mono_vsprintf_005a299e(buffer,format,reinterpret_cast<const std::uint32_t*>(arguments));','if(application_diagnostic_mono_vsprintf_005a299e(buffer,format,reinterpret_cast<const std::uint32_t*>(arguments))<0){va_end(arguments);return;}'),
('device-count','i<8','i<7'),
('device-mask','application_diagnostic_devices_005e1c8c[i].flags&1','application_diagnostic_devices_005e1c8c[i].flags&2'),
('device-null','if(callback)reinterpret_cast','if(!callback)reinterpret_cast'),
('device-channel','>(callback)(channel,buffer);','>(callback)(i,buffer);'),
('device-buffer','>(callback)(channel,buffer);','>(callback)(channel,buffer+1);'),
('device-order','for(std::uint32_t i=0;i<8;++i)','for(std::uint32_t i=8;i--;)'),
('device-break','>(callback)(channel,buffer);','>(callback)(channel,buffer);break;'),
]
mutations=[]
for name,old,new in controls:
 assert production.count(old)==1,(name,production.count(old));mutations.append(dict(name=name,source=source,old=old,new=new,expected_exit=1,failure_marker='divergence'))
gate='if(!(application_diagnostic_channels_005df4a0[channel].flags&1))return;'
late_channel=production.replace('    if(!application_diagnostic_started_', '    const auto early=application_diagnostic_channels_005df4a0[channel].flags;\n    if(!application_diagnostic_started_').replace(gate,'if(!(early&1))return;')
late_flags=production.replace('    char buffer[2048];','    std::uint32_t early[8];for(std::uint32_t j=0;j<8;++j)early[j]=application_diagnostic_devices_005e1c8c[j].flags;\n    char buffer[2048];').replace('application_diagnostic_devices_005e1c8c[i].flags&1','early[i]&1')
late_callbacks=production.replace('    char buffer[2048];','    std::uint32_t early[8];for(std::uint32_t j=0;j<8;++j)early[j]=application_diagnostic_devices_005e1c8c[j].callback;\n    char buffer[2048];').replace('const auto callback=application_diagnostic_devices_005e1c8c[i].callback;','const auto callback=early[i];')
for name,new in [('channel-before-startup',late_channel),('device-flags-before-format',late_flags),('device-callback-before-format',late_callbacks)]:
 assert new!=production;mutations.append(dict(name=name,source=source,old=production,new=new,expected_exit=1,failure_marker='divergence'))
cfg=load(RUN.parent/'546-render-resource-allocation/native-config.json')
cfg.update(run=549,experiment='local/experiments/v2-render-diagnostic-549',sources=[source,rel(RUN.parent/'345-diagnostic-devices/diagnostic_devices.cpp'),rel(RUN.parent/'353-diagnostic-mono/diagnostic_mono.cpp'),'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/formatter_entry.cpp',rel(RUN.parent/'546-render-resource-allocation/render_resource_allocation_546.cpp')],fixture=rel(RUN/'native-fixture.cpp.in'),headers=[rel(RUN/'render_diagnostic_549.hpp'),rel(RUN/'scope-evidence.json')],original_bodies=[dict(va='0055ec50',bytes=116,sha256=sha(native.pe_at(pe,0x55ec50,116)),token='@DIAGNOSTIC@'),dict(va='00554bd0',bytes=228,sha256=sha(raw_slot),token='@SLOT@')],mutations=mutations,pass_marker='render_diagnostic_original_x86_vs_cpp=PASS',timeout_seconds=240)
cfg['include_dirs']=[rel(RUN),rel(RUN.parent/'345-diagnostic-devices'),rel(RUN.parent/'353-diagnostic-mono'),rel(RUN.parent/'546-render-resource-allocation'),*cfg['include_dirs']]
(RUN/'native-config.json').write_text(json.dumps(cfg,indent=2)+'\n',encoding='utf8',newline='\n')
print('prepared549:1original116B/0newdata,actual345+353+formatter+546capacity,16controls')
