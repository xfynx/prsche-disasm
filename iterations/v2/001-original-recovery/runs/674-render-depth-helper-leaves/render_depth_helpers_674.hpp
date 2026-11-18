// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "../537-render-resource-descriptor-cleanup/render_resource_descriptor_537.hpp"

namespace porsche {

// Owned initialized .data table at 005de574..005de5ab (14 x 4B = 56B).
extern std::int32_t render_depth_format_table_005de574[14];

// Owned initialized .data table at 005de5ac..005de5c7 (7 x 4B = 28B).
extern std::uint32_t render_depth_level_table_005de5ac[7];

// Original 005345e0..00534629 (74B, __cdecl, ret 0).
std::int32_t __cdecl render_shape_type_to_depth_index_005345e0(std::uint32_t shape_type);

// Original 00535340..00535354 (21B, __cdecl, ret 0).
std::int32_t __cdecl render_depth_format_index_00535340(std::uint32_t format_index);

// Original 00535360..00535377 (24B, __cdecl, ret 0).
std::uint32_t __cdecl render_depth_level_00535360(std::int32_t depth_index);

// Original 00571490..005714d5 (70B, __cdecl, ret 0).
std::uint32_t __cdecl render_chunk_size_00571490(const void* header);

// Original 00571520..0057152d (14B, __cdecl, ret 0).
std::uint32_t __cdecl render_chunk_size_wrapper_00571520(const void* header);

// Original 00573070..00573072 (3B, __cdecl, ret 0).
void __cdecl render_mmx_empty_00573070();

} // namespace porsche
