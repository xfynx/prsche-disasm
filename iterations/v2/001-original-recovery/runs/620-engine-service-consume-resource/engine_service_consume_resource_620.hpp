// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "porsche/engine_service_427a60.hpp"
#include "porsche/startup_services.hpp"
#include "splash_network_queries_510.hpp"
#include "porsche/render_objects.hpp"
#include "porsche/fe_stream.hpp"
#include "porsche/heap.hpp"
#include "porsche/network_workers_members.hpp"

namespace porsche {

// Read-only .rdata string owned by 00490420 / 0048cb50 (12 bytes).
extern const char data_packet_tag_005d072c[12];

// Original entry 00490420..004904c9 (170 bytes, __thiscall / __fastcall with 3 stack args, RET 0Ch).
void __fastcall network_item_add_packet_00490420(
    void* item, void* unused_edx,
    std::uint32_t resource, void* value, std::int32_t count);

// engine_service_consume_resource_0048cb50 (361 bytes) is declared in porsche/engine_service_427a60.hpp.

} // namespace porsche
