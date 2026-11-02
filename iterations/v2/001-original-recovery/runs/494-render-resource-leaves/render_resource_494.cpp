// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Complete 0053c3d0/30B, 00533f80/50B, 005338d0/53B and 0044e870/20B.
#include "render_resource_494.hpp"
#include "porsche/window_shutdown.hpp"
#include "porsche/heap.hpp"
#include <cstring>
namespace porsche {
namespace {
using U=std::uint32_t;using B=std::uint8_t;
U load(const void* p,U offset){U value;std::memcpy(&value,static_cast<const B*>(p)+offset,4);return value;}
void store(void* p,U offset,U value){std::memcpy(static_cast<B*>(p)+offset,&value,4);}
}
FrameControlSlotFields_494 frame_control_slot_fields_494[32]{};
U __cdecl render_resource_total_phys_0053c3d0(){
    U status[8]; // Original initializes only dwLength; the API owns the rest.
    status[0]=32;
    render_resource_global_memory_status_005b2140(status);
    return status[2];
}
void __cdecl render_display_texture_reset_0053c3d0(){(void)render_resource_total_phys_0053c3d0();}
U __cdecl render_resource_release_texture_00533f80(void* texture){
    const U buffer=load(texture,0x28);
    if(buffer!=0&&buffer==window_shutdown_config_005de620[10])window_shutdown_prepare_00534550();
    auto* const bytes=static_cast<B*>(texture);
    bytes[0x0c]=0;bytes[0x0d]=0;
    store(texture,0,0x57494e6b);
    return free_00531f90(texture);
}
void __cdecl render_display_release_texture_00533f80(void* texture){(void)render_resource_release_texture_00533f80(texture);}
void __cdecl splash_progress_release_texture_00533f80(U texture){(void)render_resource_release_texture_00533f80(reinterpret_cast<void*>(texture));}
void __cdecl frame_control_slot_release_005338d0(std::int32_t slot){
    if(slot<0||slot>=32)return;
    auto& entry=frame_control_slot_fields_494[slot];
    if(entry.state==0xffffffffu)return;
    void* const device=reinterpret_cast<void*>(entry.device);
    const U vtable=load(device,0);
    // Original indirect stdcall transport leaves ECX equal to the vtable.
    __asm {
        mov ecx,vtable
        push device
        call dword ptr [ecx+20h]
    }
    entry.active=0;
}
}
