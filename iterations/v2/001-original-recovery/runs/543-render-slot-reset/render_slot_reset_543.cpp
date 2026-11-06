// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Complete555330/81B,555390/100B,555400/64B; six sparse loader-zero DWORDs.
#include "render_slot_reset_543.hpp"
#include "porsche/render_loader.hpp"
#include "porsche/application_heap_state.hpp"
#include "porsche/heap.hpp"
#include "porsche/file_device.hpp"
#include <cstring>
namespace porsche {
using U=std::uint32_t;using B=std::uint8_t;
U render_texture_slot_count_006a3a44=0;
U render_texture_dirty_006a3a48=0;
U render_texture_pending_006a3a58=0;
U render_texture_arena_006a3a5c=0;
U render_texture_heap_id_006a3a60=0;
U render_texture_epoch_006a3a64=0;
namespace {
U get(U p){U v;std::memcpy(&v,reinterpret_cast<const void*>(p),4);return v;}
void put(U p,U v){std::memcpy(reinterpret_cast<void*>(p),&v,4);}
U slot_address(U index){return reinterpret_cast<U>(render_texture_slots_006a33f8)+index*48;}
}
void __cdecl render_texture_invalidate_00555330(){
    if(!render_texture_dirty_006a3a48)return;
    using Reset=U (__stdcall*)();
    (void)reinterpret_cast<Reset>(static_cast<std::uintptr_t>(render_thrash_exports_006bd910[30]))();
    const auto count=static_cast<std::int32_t>(render_texture_slot_count_006a3a44);
    for(std::int32_t i=0;i<count;++i){
        const U record=slot_address(static_cast<U>(i));
        U node=get(record+0x24);
        put(record+0x28,0);put(record+0x2c,0);
        while(node){put(node+0x10,0);put(node+8,0);put(node+0xc,0);node=get(node);}
    }
    render_texture_dirty_006a3a48=0;render_texture_pending_006a3a58=0;
}
void __cdecl render_texture_reset_00555390(){
    render_texture_invalidate_00555330();
    ++render_texture_epoch_006a3a64;
    for(std::int32_t i=0;i<static_cast<std::int32_t>(render_texture_slot_count_006a3a44);++i)
        heap_fill_0053c290(reinterpret_cast<void*>(slot_address(static_cast<U>(i))),0,48);
    render_texture_arena_release_00555400();
    render_texture_slot_count_006a3a44=0;render_texture_count_006a3a40=0;render_texture_dirty_006a3a48=0;
}
void __cdecl render_texture_arena_release_00555400(){
    if(!render_texture_arena_006a3a5c)return;
    (void)application_heap_destroy_005699f0(render_texture_heap_id_006a3a60);
    void* arena=reinterpret_cast<void*>(render_texture_arena_006a3a5c);
    render_texture_heap_id_006a3a60=0;
    (void)platform_virtual_free(arena,0,0x8000);
    render_texture_arena_006a3a5c=0;
}
}
