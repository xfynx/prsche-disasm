"""Reuse540 transport helpers; configure the shared native batch runner."""
import json,hashlib
from pathlib import Path
ROOT=Path(__file__).resolve().parents[5]
RUN=Path(__file__).resolve().parent
rel=lambda p:p.relative_to(ROOT).as_posix()
near=(RUN.parent/'540-render-texture-cleanup-reader/native-fixture.cpp.in').read_text(encoding='utf8')
helpers=near[near.index('static void capture(Fpu& f)'):near.index('static void event(U tag')]
relocs=near[near.index('static void absolute(B*'):near.index('\n',near.index('static void relative(B*'))]
fixture=(RUN/'fixture-body.inc').read_text(encoding='utf8').replace('@ABI_X87_HELPERS@',helpers).replace('@RELOCATORS@',relocs)
(RUN/'native-fixture.cpp.in').write_text(fixture,encoding='utf8',newline='\n')
scope=json.loads((RUN/'scope-evidence.json').read_text(encoding='utf8'))
bodies=[dict(va=x['va'],bytes=x['bytes'],sha256=x['sha256'],token='@'+token+'@') for x,token in zip(scope['functions'],['INVALIDATE','RESET','RELEASE'])]
assert all(fixture.count(x['token'])==1 for x in bodies)
source=rel(RUN/'render_slot_reset_543.cpp');text=(ROOT/source).read_text(encoding='utf8');mutations=[]
items=[
('dirty-gate','if(!render_texture_dirty_006a3a48)return;','if(render_texture_dirty_006a3a48)return;'),
('dirty-final','render_texture_dirty_006a3a48=0;render_texture_pending_006a3a58=0;','render_texture_dirty_006a3a48=1;render_texture_pending_006a3a58=0;'),
('pending-final','render_texture_dirty_006a3a48=0;render_texture_pending_006a3a58=0;','render_texture_dirty_006a3a48=0;render_texture_pending_006a3a58=1;'),
('slot-stride','index*48;','index*44;'),
('slot-flags','put(record+0x28,0);put(record+0x2c,0);','put(record+0x28,0);put(record+0x2c,1);'),
('node-fields','put(node+0x10,0);put(node+8,0);put(node+0xc,0);','put(node+0x14,0);put(node+8,0);put(node+0xc,0);'),
('invalidate-signed','for(std::int32_t i=0;i<count;++i)','for(U i=0;i<static_cast<U>(count);++i)'),
('epoch-increment','++render_texture_epoch_006a3a64;','--render_texture_epoch_006a3a64;'),
('fill-size',',0,48);',',0,44);'),
('reset-total','render_texture_count_006a3a40=0;','render_texture_count_006a3a40=1;'),
('reset-pending','render_texture_slot_count_006a3a44=0;render_texture_count_006a3a40=0;render_texture_dirty_006a3a48=0;','render_texture_slot_count_006a3a44=0;render_texture_count_006a3a40=0;render_texture_dirty_006a3a48=0;render_texture_pending_006a3a58=0;'),
('arena-empty','if(!render_texture_arena_006a3a5c)return;','if(!render_texture_arena_006a3a5c){render_texture_heap_id_006a3a60=0;return;}'),
('arena-late-null','void* arena=reinterpret_cast<void*>(render_texture_arena_006a3a5c);','void* arena=reinterpret_cast<void*>(render_texture_arena_006a3a5c);if(!arena)return;'),
('arena-free-mode','platform_virtual_free(arena,0,0x8000)','platform_virtual_free(arena,0,0x4000)'),
('heap-id-argument','application_heap_destroy_005699f0(render_texture_heap_id_006a3a60)','application_heap_destroy_005699f0(render_texture_slot_count_006a3a44)'),
]
old='    using Reset=U (__stdcall*)();\n    (void)reinterpret_cast<Reset>(static_cast<std::uintptr_t>(render_thrash_exports_006bd910[30]))();\n    const auto count=static_cast<std::int32_t>(render_texture_slot_count_006a3a44);'
new='    const auto count=static_cast<std::int32_t>(render_texture_slot_count_006a3a44);\n    using Reset=U (__stdcall*)();\n    (void)reinterpret_cast<Reset>(static_cast<std::uintptr_t>(render_thrash_exports_006bd910[30]))();'
items.append(('invalidate-count-before-call',old,new))
old='    for(std::int32_t i=0;i<static_cast<std::int32_t>(render_texture_slot_count_006a3a44);++i)'
new='    const auto count=static_cast<std::int32_t>(render_texture_slot_count_006a3a44);\n    for(std::int32_t i=0;i<count;++i)'
items.append(('fill-captured-count',old,new))
old='    (void)application_heap_destroy_005699f0(render_texture_heap_id_006a3a60);\n    void* arena=reinterpret_cast<void*>(render_texture_arena_006a3a5c);'
new='    void* arena=reinterpret_cast<void*>(render_texture_arena_006a3a5c);\n    (void)application_heap_destroy_005699f0(render_texture_heap_id_006a3a60);'
items.append(('arena-before-heap',old,new))
old='    render_texture_heap_id_006a3a60=0;\n    (void)platform_virtual_free(arena,0,0x8000);'
new='    (void)platform_virtual_free(arena,0,0x8000);\n    render_texture_heap_id_006a3a60=0;'
items.append(('heap-id-after-free',old,new))
old='    (void)platform_virtual_free(arena,0,0x8000);\n    render_texture_arena_006a3a5c=0;'
new='    if(platform_virtual_free(arena,0,0x8000))render_texture_arena_006a3a5c=0;'
items.append(('free-failure-keeps-arena',old,new))
for name,old,new in items:
    assert text.count(old)==1,(name,text.count(old));mutations.append(dict(name=name,source=source,old=old,new=new,expected_exit=1,failure_marker='divergence'))
cfg=dict(run=543,experiment='local/experiments/v2-render-slot-reset-543',original_pe='local/game/Porsche.exe',original_sha256=scope['original_sha256'],sources=[source],fixture=rel(RUN/'native-fixture.cpp.in'),include_dirs=[rel(RUN),'iterations/v2/001-original-recovery/runs/536-render-resource-nodes','iterations/v2/001-original-recovery/runs/533-render-resource-factories','iterations/v2/001-original-recovery/source/include'],headers=[rel(RUN/'render_slot_reset_543.hpp'),rel(RUN/'scope-evidence.json')],original_bodies=bodies,pass_marker='render_slot_reset_original_x86_vs_cpp=PASS',timeout_seconds=240,mutations=mutations)
(RUN/'native-config.json').write_text(json.dumps(cfg,indent=2)+'\n',encoding='utf8',newline='\n')
print('prepared3rawbodies,20controls using unchanged540 ABI/x87/SEH helpers')
