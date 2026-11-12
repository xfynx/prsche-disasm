// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Candidate originals 00536050/46B, 005360a0/43B, 00555440/76B.
#include "startup_lifecycle_572.hpp"
#include "../570-startup-service-bindings/startup_service_570.hpp"
#include "../543-render-slot-reset/render_slot_reset_543.hpp"
#include "porsche/render_display.hpp"
#include <cstring>
namespace porsche {
using U=std::uint32_t;using B=std::uint8_t;
std::uint8_t startup_lifecycle_mode_005de6b8=1;
void __cdecl render_texture_process_005554b0(void*);
void __cdecl render_display_texture_release_00555440(void* texture){
    const U value=reinterpret_cast<U>(texture);
    if(render_texture_dirty_006a3a48==0&&value>16){render_display_set_texture_006bd954(0);return;}
    U selected=value;
    if(render_texture_dirty_006a3a48!=0&&value>16){
        render_texture_process_005554b0(texture);
        std::memcpy(&selected,static_cast<B*>(texture)+0x10,4);
    }
    render_display_set_texture_006bd954(selected);
    render_texture_pending_006a3a58=value;
}
void __fastcall startup_lifecycle_end_raw_00536050(void* receiver,void*){
    const U zero=0;B* p=static_cast<B*>(receiver);
    std::memcpy(p+8,&zero,4);std::memcpy(p+12,&zero,4);
    if(startup_lifecycle_mode_005de6b8){render_display_texture_update_005550e0();render_display_texture_release_00555440(nullptr);}
    startup_service_active_0069dd1e=1;
}
void __fastcall startup_lifecycle_frame_raw_005360a0(void*,void*,U input){
    const B low=static_cast<B>(input);startup_lifecycle_mode_005de6b8=low;
    if(low&&startup_service_active_0069dd1e){
        render_texture_invalidate_00555330();render_display_texture_update_005550e0();render_display_texture_release_00555440(nullptr);
    }
}
void __cdecl game_setup_movie_service_end_00536050(void* receiver){startup_lifecycle_end_raw_00536050(receiver,nullptr);}
void __cdecl frame_pump_boundary_005360a0(void* receiver,U input){startup_lifecycle_frame_raw_005360a0(receiver,nullptr,input);}
}
