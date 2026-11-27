#include "flare_cleanup_slots_882.hpp"
#include "porsche/application_alloc.hpp"
#include "porsche/context_effects.hpp"
#include <cstdint>
#include <cstring>
namespace porsche {
void* scene_flare_resource_00627e18 = nullptr;
void* scene_flare_aux_00627e1c = nullptr;
void* scene_route_sky_bytes_00627e38 = nullptr;
void* scene_route_sky_aux_00627e3c = nullptr;
void __cdecl scene_flare_aux_cleanup_004599c0() {
    if (scene_flare_aux_00627e1c) application_release_0059f050(scene_flare_aux_00627e1c);
    scene_flare_aux_00627e1c = nullptr;
}
void __cdecl scene_route_sky_cleanup_0045ccb0() {
    void* bytes = scene_route_sky_bytes_00627e38;
    if (bytes) {
        *static_cast<unsigned char*>(bytes) = 0;
        application_release_0059f050(bytes);
    }
    void* aux = scene_route_sky_aux_00627e3c;
    scene_route_sky_bytes_00627e38 = nullptr;
    application_release_0059f050(aux);
    scene_route_sky_aux_00627e3c = nullptr;
}
void __cdecl scene_flare_resource_cleanup_00459630() {
    void* resource = scene_flare_resource_00627e18;
    if (resource) {
        void* table;
        std::memcpy(&table, static_cast<unsigned char*>(resource) + 0x104, sizeof table);
        context_table_release_0059ecd0(table);
        application_release_0059f050(resource);
    }
    scene_flare_resource_00627e18 = nullptr;
}
}
