// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// 0045dbd0..0045dcf9, 298 bytes. Only the low mode byte is tested.
#include "scene_route_binding_874.hpp"
#include "porsche/install_paths.hpp"
#include "porsche/formatter_entry.hpp"
#include "porsche/application_alloc.hpp"
namespace porsche {
extern void* scene_flare_table_00627e48;
extern void* scene_route_sky_00627e4c;
std::uint32_t __cdecl free_00531f90(void*);
void* __cdecl resource_open_quiet_0059d9b0(const char*,std::uint32_t);
void* __cdecl resource_open_0059d8e0(const char*,std::uint32_t);
void* scene_route_archive_00627e50 = nullptr;
void __cdecl scene_route_bind_0045dbd0(void* root, std::uint32_t mode) {
    const bool update = static_cast<std::uint8_t>(mode) != 0;
    if(update) {
        (void)free_00531f90(scene_route_archive_00627e50);
        scene_route_archive_00627e50 = nullptr;
    }
    char path[256];
    formatter_entry_005a0fbf(path, "%sSky\\%s.fsh", install_paths_table_0065b2a0[6], root);
    scene_route_archive_00627e50 = resource_open_quiet_0059d9b0(path,0);
    if(!scene_route_archive_00627e50) {
        formatter_entry_005a0fbf(path, "%sSky\\default.fsh", install_paths_table_0065b2a0[6]);
        scene_route_archive_00627e50 = resource_open_0059d8e0(path,0);
    }
    if(update) {
        scene_sky_update_00460cd0(scene_route_sky_00627e4c,nullptr,scene_route_archive_00627e50);
        void* flare = scene_flare_table_00627e48;
        if(flare) {
            scene_flare_teardown_0045db10(flare,nullptr);
            (void)application_release_0059f050(flare);
        }
        scene_flare_table_00627e48 = nullptr;
    } else {
        void* sky = startup_network_allocate_0059ef90(0x238);
        scene_route_sky_00627e4c = sky ? scene_sky_ctor_00460a50(sky,nullptr,scene_route_archive_00627e50) : nullptr;
    }
    void* flare = startup_network_allocate_0059ef90(100);
    scene_flare_table_00627e48 = flare ? scene_flare_ctor_0045d800(flare,nullptr,static_cast<const char*>(root)) : nullptr;
}
}
