#pragma once
#include <cstdint>

namespace porsche {
using TextureCompare577 = std::int32_t (__cdecl *)(std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t);
extern TextureCompare577 render_texture_comparator_005df2c8;
std::int32_t __cdecl render_texture_compare_00554310(std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t);
std::int32_t __cdecl render_texture_select_00554820(std::uint32_t*, std::uint32_t*);
std::int32_t __cdecl render_texture_depth_convert_005350e0(std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t, std::int32_t);
void __cdecl render_texture_expand_00555780(std::uint32_t, std::uint32_t, std::int32_t);
void __cdecl render_texture_convert_005556b0(std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t);
}
