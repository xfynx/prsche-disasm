"""Reuse frozen570 fixture scaffolding for the same three572 originals."""
from pathlib import Path
import json

ROOT = Path(__file__).resolve().parents[5]
RUN = Path(__file__).resolve().parent
BASE = ROOT / 'iterations/v2/001-original-recovery/runs/570-startup-service-bindings'

scope = (RUN / 'scope.py').read_text(encoding='utf-8')
scope = scope.replace("base=root/'iterations/v2/001-original-recovery/runs/567-audio-codec-control-integration'",
                      "base=root/'iterations/v2/001-original-recovery/runs/573-audio-greedy-integration'")
scope = scope.replace("'baseline':'Run567 attempt 001'", "'baseline':'Run573 attempt 001'")
scope = scope.replace("result['new_byte']", "result['canonical_service_flag']")
scope = scope.replace("assert 'new_byte' in result", "assert 'canonical_service_flag' in result")
(RUN / 'scope.py').write_text(scope, encoding='utf-8', newline='\n')

tail = (RUN / 'fixture-tail.inc').read_text(encoding='utf-8')
tail = tail.replace('Trace original{};U result=0;', 'Trace& original=expected;U result=0;')
tail = tail.replace('if(flags&512){put(p,0x10,0x11223344);',
                    'if(flags&512){render_texture_dirty_006a3a48=0;put(p,0x10,0x11223344);')
tail = tail.replace('trace.abi=invoke(fn,receiver,args,argc,cleanup,result);',
                    'trace.abi=invoke(fn,side==2?arena.storage[1]+offset:receiver,args,argc,cleanup,result);')
start = tail.index(' for(kind=0;kind<3;++kind)')
end = tail.index('\n __asm fninit', start)
tail = tail[:start] + ''' for(kind=0;kind<3;++kind)for(offset=0;offset<4;++offset)for(dirty_mode=0;dirty_mode<2;++dirty_mode)for(scene=0;scene<2;++scene)for(layout=0;layout<2;++layout)for(U f:{0u,256u,512u,1024u,1792u})for(U v:{0u,1u,16u,17u,0x100u,0x101u}){
  if(kind==0&&v!=0)continue;
  if(kind==2&&v>17)continue;
  flags=f;value=0x9b8a7c6d;input_value=v;compare();
 }''' + tail[end:]
(RUN / 'fixture-tail.inc').write_text(tail, encoding='utf-8', newline='\n')

fixture = (BASE / 'native-fixture.cpp.in').read_text(encoding='utf-8')
prefix = fixture[:fixture.index('static void init(){')]
changes = [
    ('#include "startup_service_570.hpp"', '#include "startup_service_570.hpp"\n#include "startup_lifecycle_572.hpp"'),
    ('fill_calls,nesting;', 'fill_calls,nesting,input_value;'),
    ('B tag,padding[3],values[80];', 'B tag,padding[3],values[80];unsigned short full_tag;U mxcsr;'),
    ('fill_calls,nesting,service;', 'fill_calls,nesting,service,mode;'),
    ('s.service=startup_service_active_0069dd1e;', 's.service=startup_service_active_0069dd1e;s.mode=startup_lifecycle_mode_005de6b8;'),
    ('static void reset(){trace={};', 'static void reset(){memset(&trace,0,sizeof trace);'),
]
for old, new in changes:
    assert prefix.count(old) == 1, old
    prefix = prefix.replace(old, new)
start = prefix.index('static void capture(Fpu& f)')
end = prefix.index('static void seed_fpu()', start)
prefix = prefix[:start] + '''static void capture(Fpu& f){B environment[28];
 __asm {fxsave floating
        fnstenv environment
        fldenv environment}
 f.control=*reinterpret_cast<unsigned short*>(floating);f.status=*reinterpret_cast<unsigned short*>(floating+2);f.tag=floating[4];memset(f.padding,0,3);
 f.full_tag=*reinterpret_cast<unsigned short*>(environment+8);f.mxcsr=*reinterpret_cast<U*>(floating+24);
 for(U i=0;i<8;++i){const U physical=((f.status>>11)+i)&7u;if(f.tag&(1u<<physical))memcpy(f.values+i*10,floating+32+i*16,10);else memset(f.values+i*10,0,10);}
}

''' + prefix[end:]
(RUN / 'native-fixture.cpp.in').write_text(prefix + tail, encoding='utf-8', newline='\n')

cfg = json.loads((BASE / 'native-config.json').read_text())
source = 'iterations/v2/001-original-recovery/runs/572-startup-service-lifecycle/startup_lifecycle_572.cpp'
cfg.update(run=572, experiment='local/experiments/v2-startup-service-lifecycle-572',
           fixture='iterations/v2/001-original-recovery/runs/572-startup-service-lifecycle/native-fixture.cpp.in',
           pass_marker='startup_lifecycle_original_x86_vs_cpp=PASS')
cfg['sources'] = [source, *cfg['sources'], 'iterations/v2/001-original-recovery/runs/357-render-display-bindings/render_binding.cpp']
cfg['include_dirs'] = ['iterations/v2/001-original-recovery/runs/572-startup-service-lifecycle', *cfg['include_dirs']]
cfg['headers'] = ['iterations/v2/001-original-recovery/runs/572-startup-service-lifecycle/' + p
                  for p in ['scope-evidence.json', 'fixture-tail.inc', 'prepare.py']]
scope = json.loads((RUN / 'scope-evidence.json').read_text())
cfg['original_bodies'] = [dict(va=b['va'], bytes=b['bytes'], sha256=b['sha256'], token='@BODY_' + b['va'].upper() + '@')
                           for b in scope['bodies']]
mode = scope['original_mode_byte']
cfg['original_bodies'].append(dict(va=mode['va'], bytes=1, sha256=mode['sha256'], token='@MODE_005DE6B8@', kind='original-data-witness'))
mutations = [
    ('receiver-field', 'std::memcpy(p+8,&zero,4);', 'std::memcpy(p+8,&zero,3);'),
    ('low-byte', 'const B low=static_cast<B>(input);', 'const B low=input?1:0;'),
    ('late-active', 'if(startup_lifecycle_mode_005de6b8){render_display_texture_update_005550e0();render_display_texture_release_00555440(nullptr);}\n    startup_service_active_0069dd1e=1;',
     'startup_service_active_0069dd1e=1;\n    if(startup_lifecycle_mode_005de6b8){render_display_texture_update_005550e0();render_display_texture_release_00555440(nullptr);}'),
    ('early-pending', 'render_display_set_texture_006bd954(0);return;', 'render_display_set_texture_006bd954(0);render_texture_pending_006a3a58=value;return;'),
    ('late-getter', 'render_texture_process_005554b0(texture);\n        std::memcpy(&selected,static_cast<B*>(texture)+0x10,4);',
     'std::memcpy(&selected,static_cast<B*>(texture)+0x10,4);\n        render_texture_process_005554b0(texture);'),
    ('pending-order', 'render_display_set_texture_006bd954(selected);\n    render_texture_pending_006a3a58=value;',
     'render_texture_pending_006a3a58=value;\n    render_display_set_texture_006bd954(selected);'),
    ('invalidate', 'render_texture_invalidate_00555330();', '/* removed real invalidation */'),
]
source_text = (ROOT / source).read_text()
assert all(source_text.count(old) == 1 for _, old, _ in mutations)
cfg['mutations'] = [dict(name=name, source=source, old=old, new=new, expected_exit=1, failure_marker='divergence')
                    for name, old, new in mutations]
(RUN / 'native-config.json').write_text(json.dumps(cfg, indent=2) + '\n', encoding='utf-8', newline='\n')
print('572 prepared:', len(cfg['sources']), 'TUs,', len(mutations), 'controls; unchanged three-body scope')
