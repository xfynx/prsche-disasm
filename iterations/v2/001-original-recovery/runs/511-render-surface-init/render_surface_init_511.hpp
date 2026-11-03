#pragma once
#include <cstdint>
namespace porsche {
extern const float render_surface_half_005b23f0;
std::uint32_t __stdcall render_surface_bounds_00556d00(std::uint32_t* width,std::uint32_t* height);
void __cdecl render_surface_init_bits_00538da0(void* surface,std::uint32_t width,std::uint32_t height,std::uint32_t x,std::uint32_t y,std::uint32_t opaque1e8,std::uint32_t opaque1ec);
void __cdecl render_display_surface_init_00538da0(void* surface,float width,float height,std::uint32_t x,std::uint32_t y,std::uint32_t opaque1e8,std::uint32_t opaque1ec);
}
