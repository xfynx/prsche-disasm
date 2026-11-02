#pragma once
#include <cstdint>
namespace porsche {
const void* __cdecl render_matrix_multiply_005398b0(const void* left,const void* right,void* output);
void* __cdecl render_matrix_attach_00539b00(void* destination,const void* source);
void __cdecl render_display_transform_attach_00539b00(void* destination,void* source);
std::uint32_t __cdecl render_surface_config_005392d0(void* surface,std::uint32_t scale,std::uint32_t near_word,std::uint32_t far_word);
void __cdecl render_display_surface_config_005392d0(void* surface,std::uint32_t scale,std::uint32_t near_word,std::uint32_t far_word);
}
