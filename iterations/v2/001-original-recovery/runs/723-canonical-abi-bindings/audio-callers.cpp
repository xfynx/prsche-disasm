#include <cstdint>
#include "bindings.hpp"
namespace porsche {
void __cdecl application_sim_boundary_004a6c90(const char*,std::int32_t);
}
extern "C" void __cdecl call_audio_legacy_723(const char* text,std::int32_t kind) {
    porsche::application_sim_boundary_004a6c90(text,kind);
}
extern "C" void* __cdecl audio_legacy_address_723() {
    return reinterpret_cast<void*>(&porsche::application_sim_boundary_004a6c90);
}
