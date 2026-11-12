// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// 00536080/27 bytes; candidate pending original-x86 comparison.
#include "startup_service_570.hpp"
#include "../543-render-slot-reset/render_slot_reset_543.hpp"
#include <cstring>
namespace porsche {
std::uint8_t startup_service_active_0069dd1e=0;
void __fastcall startup_sequence_service_00536080(void* receiver,void*){
    const std::uint32_t zero=0;
    auto* p=static_cast<std::uint8_t*>(receiver);
    std::memcpy(p+8,&zero,4);
    std::memcpy(p+12,&zero,4);
    render_texture_invalidate_00555330();
    startup_service_active_0069dd1e=0;
}
void __cdecl game_setup_movie_service_begin_00536080(void* receiver){
    startup_sequence_service_00536080(receiver,nullptr);
}
}
