#pragma once
#include "../543-render-slot-reset/render_slot_reset_543.hpp"
#include <cstdint>
namespace porsche {
extern std::uint32_t render_texture_preferred_bytes_005df2c4;
extern volatile std::uint32_t render_texture_width_sentinel_006a3a08;
// Sparse first DWORDs at005df16c+20*i, admitted indices0..13 only.
extern const std::uint32_t render_texture_format_bits_005df16c[14];
extern const char render_texture_heap_name_005bbfdc[5];
extern const char render_texture_capacity_message_005bc208[138];
int __cdecl render_display_texture_reserve_00553fc0(std::uint32_t bytes);
int __cdecl render_texture_lazy_reserve_00554b50();
void* __cdecl render_texture_bytes_00554b20(std::uint32_t bytes,const char* name);
void* __cdecl render_texture_node_00554b90(const char* name);
void __cdecl render_texture_header_00554ad0(void* output,std::uint32_t width,std::uint32_t height,std::uint32_t format,std::uint32_t flags);
std::uint32_t __cdecl render_texture_slot_00554bd0(std::uint32_t width,std::uint32_t formatA,std::uint32_t formatB,std::uint32_t flags);
// Canonical569a70 remains in application_heap_init.cpp; integration supplies a
// typed owner export, never another scan. Diagnostic remains a real dependency.
std::uint32_t __cdecl application_heap_slot_00569a70();
void __cdecl render_texture_diagnostic_0055ec50(std::uint32_t channel,const char* message,...);
}
