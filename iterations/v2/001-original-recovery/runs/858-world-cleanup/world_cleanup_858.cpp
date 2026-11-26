#include "world_cleanup_858.hpp"
#include "porsche/application_alloc.hpp"
#include "porsche/formatter_stdio.hpp"

namespace porsche {

extern "C" void __fastcall frame_world_destroy_00487590(void* object, void* edx);

void __cdecl application_sim_boundary_00471c40() {
    formatter_stdio_printf_005a177b("BWorld_DeInit...");
    void* const root = reinterpret_cast<void*>(
        static_cast<std::uintptr_t>(frame_service_root_00628960));
    if (root != nullptr) {
        frame_world_destroy_00487590(root, nullptr);
        application_release_0059f050(root);
    }
    frame_service_root_00628960 = 0;
    formatter_stdio_printf_005a177b("done.\n");
}

} // namespace porsche
