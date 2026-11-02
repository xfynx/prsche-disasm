#pragma once
#include <cstdint>
namespace porsche {
// Narrow original writable cells; adjacent caller globals and69ed0c are separate owners.
extern std::uint32_t render_resource_cells_0069ecc0[13];
extern std::uint32_t render_resource_option_0069ed04;
extern std::uint32_t render_resource_callback1_0069ed10,render_resource_callback2_0069ed14;
void* __cdecl render_display_resource_ctor_00540390(void* object,std::uint32_t optional_source);
void* __cdecl render_display_surface_ctor_00538d10(void* object,std::uint32_t driver);
void* __cdecl render_transform_stack_ctor_00539e50(void* object,std::uint32_t capacity);
void __cdecl render_matrix_identity_00539c90(void* matrix);
}
