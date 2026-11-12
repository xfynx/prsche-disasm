"""Adapt the accepted Run543 canonical child fixture without changing it."""
from pathlib import Path
import json
root=Path(__file__).resolve().parents[5];run=Path(__file__).resolve().parent
base=root/'iterations/v2/001-original-recovery/runs/543-render-slot-reset'
f=(base/'native-fixture.cpp.in').read_text(encoding='utf-8')
prefix=f[:f.index('static void init(){')]
reset=f[f.index('static void reset(){'):f.index('static void compare(){')]
def change(old,new):
 global prefix
 assert prefix.count(old)==1,repr(old)
 prefix=prefix.replace(old,new)
change('#include "render_slot_reset_543.hpp"','#include "render_slot_reset_543.hpp"\n#include "startup_service_570.hpp"')
change('U globals[7],exports[43],fill_calls,nesting;','U globals[7],exports[43],fill_calls,nesting,service;')
change('s.fill_calls=fill_calls;s.nesting=nesting;','s.fill_calls=fill_calls;s.nesting=nesting;s.service=startup_service_active_0069dd1e;')
change('static U __stdcall treset(){event(0x6bd988,{});','static U __stdcall treset(){event(0x6bd988,{});\n    if(flags&256){startup_service_active_0069dd1e=0x77;put(arena.storage[0]+offset,8,0x12344321);put(arena.storage[0]+offset,12,0xabcdef01);}')
(run/'native-fixture.cpp.in').write_text(prefix+reset+(run/'fixture-tail.inc').read_text(encoding='utf-8'),encoding='utf-8',newline='\n')
cfg=json.loads((base/'native-config.json').read_bytes())
source='iterations/v2/001-original-recovery/runs/570-startup-service-bindings/startup_service_570.cpp'
cfg.update(run=570,experiment='local/experiments/v2-startup-service-bindings-570',fixture='iterations/v2/001-original-recovery/runs/570-startup-service-bindings/native-fixture.cpp.in',pass_marker='startup_service_original_x86_vs_cpp=PASS')
cfg['sources'].insert(0,source)
cfg['include_dirs'].insert(0,'iterations/v2/001-original-recovery/runs/570-startup-service-bindings')
cfg['headers']=['iterations/v2/001-original-recovery/runs/570-startup-service-bindings/scope-evidence.json','iterations/v2/001-original-recovery/runs/570-startup-service-bindings/fixture-tail.inc','iterations/v2/001-original-recovery/runs/570-startup-service-bindings/prepare.py']
cfg['original_bodies']=[{'va':'00536080','bytes':27,'sha256':'42b0ba96bdb248dc0e467b70c0ac9447cab2f79286826d5eecdade18bda21837','token':'@BODY_00536080@'}]
mutations=[('first-field','std::memcpy(p+8,&zero,4);','std::memcpy(p+8,&zero,3);'),('second-field','std::memcpy(p+12,&zero,4);','std::memcpy(p+12,&zero,3);'),('late-byte','render_texture_invalidate_00555330();\n    startup_service_active_0069dd1e=0;','startup_service_active_0069dd1e=0;\n    render_texture_invalidate_00555330();'),('child','render_texture_invalidate_00555330();','/* removed child */')]
cfg['mutations']=[dict(name=name,source=source,old=old,new=new,expected_exit=1,failure_marker='divergence') for name,old,new in mutations]
(run/'native-config.json').write_text(json.dumps(cfg,indent=2)+'\n',encoding='utf-8',newline='\n')
print('prepared',len(cfg['sources']),'sources',len(mutations),'mutations')
