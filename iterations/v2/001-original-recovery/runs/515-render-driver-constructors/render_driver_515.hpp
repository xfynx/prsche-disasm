#pragma once
#include <cstdint>
namespace porsche {
extern void* render_driver_context_0069e0d4;
extern const std::uint32_t render_driver_helper_table_005bb85c[1];
extern const std::uint32_t render_driver_base_table_005bb860[11];
extern const std::uint32_t render_driver_alt_table_005bc3f0[11];
extern const std::uint32_t render_driver_main_table_005bc41c[11];
void* __cdecl render_driver_base_ctor_00538a30(void*,void*);
void* __cdecl render_display_driver_alt_ctor_00556a90(void*,void*);
void* __cdecl render_display_driver_ctor_00557100(void*,void*);
std::uint8_t __fastcall render_driver_base_start_0050dd60(void*,void*);
std::uint32_t __fastcall render_driver_context_from_field1c_00538c80(void*,void*);
std::uint32_t __fastcall render_driver_selected_00538c90(void*,void*);
std::uint32_t __fastcall render_driver_cap44_00538ca0(void*,void*);
std::uint32_t __fastcall render_driver_cap3c_00538cb0(void*,void*);
std::uint32_t __fastcall render_driver_flush_00538cc0(void*,void*);
std::uint32_t __fastcall render_driver_window_00557220(void*,void*);
std::uint32_t __fastcall render_driver_pageflip_00557230(void*,void*);
std::uint32_t __fastcall render_driver_clip_00556cd0(void*,void*);
// Original address-taken methods remain strong unresolved production providers.
void* __fastcall render_driver_base_destroy_00538ab0(void*,void*,std::uint32_t);
void* __fastcall render_driver_alt_destroy_00556ab0(void*,void*,std::uint32_t);
void* __fastcall render_driver_main_destroy_00557120(void*,void*,std::uint32_t);
std::uint8_t __fastcall render_driver_alt_start_00556b10(void*,void*);
std::uint8_t __fastcall render_driver_main_start_00557180(void*,void*);
std::uint8_t __fastcall render_driver_select_mode_00538b30(void*,void*,std::uint32_t);
std::uint32_t __fastcall render_driver_probe_00556d20(void*,void*);
// Existing consumers' platform ABI transports; no original algorithm added.
std::uint8_t __cdecl render_display_driver_start_vslot1(void*);
std::uint32_t __cdecl render_display_driver_present_vslot0(void*,std::uint32_t);
void __cdecl render_window_driver_select_mode_vslot7(void*,std::uint32_t);
void __cdecl render_mode_driver_prepare_vslot9(void*);
}
