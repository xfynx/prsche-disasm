// Porsche.exe SHA256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Full00412cd0(22B),00412e60(5B),00532d30(93B); no new state owners.
#include "sim_input_teardown_725.hpp"
#include <cstring>
namespace porsche {
namespace {
using U=std::uint32_t;
U read(const void* p){U x;std::memcpy(&x,p,4);return x;}
void call(void* object,U offset){
    using F=U(__stdcall*)(void*);
    const U table=read(object);
    reinterpret_cast<F>(read(reinterpret_cast<const void*>(table+offset)))(object);
}
}
void __cdecl application_sim_boundary_00412cd0(){
    if(read(frame_control_ff_state_005e9408+4u)!=0u){
        input_slot_stop_ff_00533480(static_cast<std::int32_t>(read(frame_control_ff_state_005e9408+8u)));
    }
}
void __cdecl application_sim_boundary_00412e60(){input_shutdown_00532d30();}
void __cdecl input_shutdown_00532d30(){
    input_effect_cleanup_00533050();
    for(std::int32_t i=0;i<input_count_0069cb0c;++i){
        auto& slot=input_slots_006be040[i];
        if(slot.device!=nullptr){
            call(slot.device,0x20u);
            call(slot.device,8u);
            slot.device=nullptr;
        }
    }
    if(void* const root=input_directinput_0069cb08){
        call(root,8u);
        input_directinput_0069cb08=nullptr;
    }
}
}
