#include "flare_teardown_879.hpp"
#include <cstdint>
#include "porsche/application_alloc.hpp"
#include "porsche/startup_service_516950.hpp"
namespace porsche {
void __fastcall scene_flare_teardown_0045db10(void* self, void*) {
    auto* slots = static_cast<std::uint32_t*>(self);
    using Delete = void (__fastcall *)(void*, void*, unsigned);
    for (unsigned i = 0; i < 10; ++i) {
        auto* object = reinterpret_cast<void*>(slots[i]);
        if (object) {
            auto* vtable = *static_cast<std::uint32_t**>(object);
            reinterpret_cast<Delete>(vtable[2])(object, nullptr, 1);
        }
    }
    for (unsigned index = 19; index >= 17; --index) {
        auto* object = reinterpret_cast<void*>(slots[index]);
        if (object) {
            startup_service_noop_00516950();
            application_release_0059f050(object);
        }
    }
    scene_flare_aux_cleanup_004599c0();
    scene_sky_cleanup_00460220();
    scene_route_sky_cleanup_0045ccb0();
    scene_flare_resource_cleanup_00459630();
}
}
