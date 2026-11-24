// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "porsche/render_event_route.hpp"
#include "../290-frame-service-cluster/frame_service_290.hpp"
#include "../334-resource-open/resource_open_334.hpp"

namespace porsche {

static_assert(sizeof(void*) == 4, "original x86 pointer ABI");

// Owned zero-initialized .bss player object pointer table at 005e8b34..005e8b57
// (9 DWORDs = 36 bytes, immediately before the counter at 005e8b58).
extern std::uint32_t application_player_object_table_005e8b34[9u];

// Owned zero-initialized .bss player setup block table at 005e75a0..005e8ab7
// (9 slots * 0x96 DWORDs = 5,400 bytes, immediately before the counter at 005e8ab8).
extern std::uint32_t application_player_setup_table_005e75a0[9u * 0x96u];

} // namespace porsche
