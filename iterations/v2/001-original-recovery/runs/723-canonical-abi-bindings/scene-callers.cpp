#include <cstdint>
#include "bindings.hpp"
namespace porsche {
void* __cdecl scene_transfer_enter_004521c0();
}
extern "C" void __cdecl call_scene_legacy_723() {
    (void)porsche::scene_transfer_enter_004521c0();
}
extern "C" void* __cdecl scene_legacy_address_723() {
    return reinterpret_cast<void*>(&porsche::scene_transfer_enter_004521c0);
}
