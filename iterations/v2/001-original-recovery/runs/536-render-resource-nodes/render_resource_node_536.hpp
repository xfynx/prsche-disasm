#pragma once
#include "render_resource_533.hpp"
#include <cstdint>
namespace porsche {
extern const std::uint32_t render_resource_node_table_005bb6d4[1];
extern char render_resource_node_name_format_005de748[6];
void* __fastcall render_resource_node_state_ctor_005379d0(void*,void*);
// Actual children remain strongly unresolved; no legal stage domain is inferred.
void* __fastcall render_resource_node_destroy_00535d30(void*,void*,std::uint32_t flags);
std::uint32_t __cdecl render_resource_node_format_00556690(const void* descriptor);
void* __cdecl render_resource_node_palette_00537fb0(const void* descriptor);
std::uint32_t __cdecl render_resource_texture_query_00554de0(void* texture,void* output24);
}
