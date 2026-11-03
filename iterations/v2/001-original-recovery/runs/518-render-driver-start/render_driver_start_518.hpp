#pragma once
#include <cstdint>
namespace porsche {
std::uint8_t __fastcall render_driver_alt_start_00556b10(void*,void*);
std::uint8_t __fastcall render_driver_main_start_00557180(void*,void*);
void* __fastcall render_resource_bind_driver_00540440(void*,void*,void*);
std::uint32_t __fastcall render_driver_context_defaults_005405f0(void*,void*);
std::uint32_t __stdcall render_driver_reg_flush_005b2004(std::uint32_t);
// Six actual original children remain typed strong unresolved providers.
std::uint8_t __cdecl render_driver_initialize_00556bb0(std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t);
void* __fastcall render_resource_bound_child_ctor_00535b50(void*,void*,void*);
void* __fastcall render_driver_buffer_ctor_00537700(void*,void*);
void __cdecl render_driver_calibrate_00536870();
void __fastcall render_driver_context_mode_00549220(void*,void*,std::uint32_t);
void __fastcall render_driver_apply_states_00538af0(void*,void*);
}
