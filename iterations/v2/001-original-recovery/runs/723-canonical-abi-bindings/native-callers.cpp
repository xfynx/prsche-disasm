// Fixture-only callers using the exact frozen Run691/693 declarations.
#include <cstdint>
#include "bindings.hpp"
namespace porsche {
void __cdecl application_sim_boundary_004a6c90(const char*,std::int32_t);
void* __cdecl scene_transfer_enter_004521c0();
}
extern "C" void __cdecl call_audio_legacy_723(const char* text,std::int32_t kind) {
    porsche::application_sim_boundary_004a6c90(text,kind);
}
extern "C" void __cdecl call_scene_legacy_723() {
    (void)porsche::scene_transfer_enter_004521c0();
}
extern "C" void* __cdecl audio_legacy_address_723() {
    return reinterpret_cast<void*>(&porsche::application_sim_boundary_004a6c90);
}
extern "C" void* __cdecl scene_legacy_address_723() {
    return reinterpret_cast<void*>(&porsche::scene_transfer_enter_004521c0);
}
