#include "porsche/engine_service_427a60.hpp"

#include "porsche/files.hpp"
#include "porsche/game_setup.hpp"
#include "porsche/fe_stream.hpp"

namespace porsche {

void __cdecl engine_service_00427a60() {
    char path[100];
    file_format_005a0fbf(path, "%s%s.fsh", engine_service_root_0065b360,
                         "pic16");
    const std::int32_t exists =
        engine_service_file_exists_0059dd00(path);
    void* resource = game_setup_resource_file_open_0059d8e0(path, 0);
    engine_service_consume_resource_0048cb50(0, resource, exists);
    free_00531f90(resource);
}

} // namespace porsche
