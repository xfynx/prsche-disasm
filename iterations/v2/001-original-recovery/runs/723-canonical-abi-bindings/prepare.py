import json,pathlib,hashlib
root=pathlib.Path(__file__).resolve().parents[5]
run=pathlib.Path(__file__).resolve().parent
rel=run.relative_to(root).as_posix()
aliases={
'?application_sim_boundary_004a6c90@porsche@@YAXPBDH@Z':'?application_audio_probe_message_004a6c90@porsche@@YAXPBDI@Z',
'?scene_transfer_enter_004521c0@porsche@@YAPAXXZ':'?scene_transfer_enter_004521c0@porsche@@YAXXZ'}
(run/'bindings.json').write_text(json.dumps(aliases,indent=2)+'\n',encoding='utf-8',newline='\n')
(run/'bindings.hpp').write_text('#pragma once\n// Link aliases only: no wrapper, return manufacture or new original body.\n'+''.join('#pragma comment(linker,"/alternatename:'+a+'='+b+'")\n' for a,b in aliases.items()),encoding='utf-8',newline='\n')
(run/'bindings.cmake').write_text('# Include after the accepted baseline has defined porsche_original_game_link.\n'+'target_link_options(porsche_original_game_link PRIVATE\n'+''.join('  "/alternatename:'+a+'='+b+'"\n' for a,b in aliases.items())+')\n',encoding='utf-8',newline='\n')
for tag,old,provider,wrapper in [
 ('audio','697-audio-period-callback-and-probe-message','&porsche::application_audio_probe_message_004a6c90','&call_audio_legacy_723'),
 ('scene','702-entry-fe-scene-route-transfer-leaves','&scene_transfer_enter_004521c0','&call_scene_legacy_723')]:
 baseline=root/'iterations/v2/001-original-recovery/runs'/old
 config=json.loads((baseline/'native-config.json').read_text())
 text=(baseline/'native-fixture.cpp.in').read_text(encoding='utf-8')
 assert text.count(provider)==1
 declaration='extern "C" void __cdecl call_audio_legacy_723(const char*,std::int32_t);\n' if tag=='audio' else 'extern "C" void __cdecl call_scene_legacy_723();\n'
 text='#include <cstdint>\n'+declaration+text.replace(provider,wrapper)
 address_fn='audio_legacy_address_723' if tag=='audio' else 'scene_legacy_address_723'
 canonical='&porsche::application_audio_probe_message_004a6c90' if tag=='audio' else '&scene_transfer_enter_004521c0'
 text='extern "C" void* __cdecl '+address_fn+'();\n'+text
 text=text.replace('int main() {','int main() {\n    require('+address_fn+'() == reinterpret_cast<void*>('+canonical+'), "legacy address identity");',1)
 config['run']=723
 config['experiment']='local/experiments/v2-canonical-abi-bindings-723-'+tag
 config['sources'].append(rel+'/'+tag+'-callers.cpp')
 config['fixture']=rel+'/'+tag+'-fixture.cpp.in'
 config['include_dirs'].append(rel)
 config['headers']+=[rel+'/bindings.json',rel+'/bindings.cmake']
 config['mutations']=[{'name':tag+'-legacy-call-control','source':rel+'/'+tag+'-callers.cpp',
 'old':'porsche::application_sim_boundary_004a6c90(text,kind);' if tag=='audio' else '(void)porsche::scene_transfer_enter_004521c0();',
 'new':'porsche::application_sim_boundary_004a6c90(text,kind ^ 1);' if tag=='audio' else '(void)0;',
 'expected_exit':1,'failure_marker':'divergence'}]
 (run/(tag+'-fixture.cpp.in')).write_text(text,encoding='utf-8',newline='\n')
 (run/(tag+'-native-config.json')).write_text(json.dumps(config,indent=2)+'\n',encoding='utf-8',newline='\n')
print('prepared723 aliases',len(aliases))
