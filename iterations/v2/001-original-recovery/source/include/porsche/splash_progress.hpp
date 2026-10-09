#pragma once

#include <cstdint>

namespace porsche {

// Single native owners for raw-backed/BSS Porsche.exe words touched by the
// 004a4a70 splash/loading/progress consumer. Other globals are shared views.
extern std::uint32_t splash_progress_texture_00655a24;
extern std::uint8_t splash_progress_enabled_00655a28;
extern std::uint32_t splash_progress_format_005dead0;
// Shared loader roots read by multiple original consumers. Ownership stays at
// the shared runtime layer; this unit only consumes the canonical references.
extern const char* splash_progress_alternate_base_0065b350;

void __cdecl splash_progress_004a4a70(std::int32_t phase);

// The function's direct engine/asset calls remain explicit contracts. Their
// effects are outside this recovered consumer and are not supplied here.
std::uint32_t __cdecl splash_progress_create_texture_00535950(
    std::uint32_t width,std::uint32_t height,std::uint32_t format,std::uint32_t flags);
void __cdecl splash_progress_dispatch_004edc00(std::uint32_t record,
    void** result,std::uint32_t source,std::int32_t progress);
void __cdecl splash_progress_release_stack_0048d550(void* allocation);
std::int32_t __cdecl splash_progress_resource_begin_004ad670();
std::int32_t __cdecl splash_progress_resource_end_004ad6c0();
void __cdecl splash_progress_pump_005366e0(std::uint32_t zero);
std::int32_t __cdecl splash_progress_bind_texture_00534480(std::uint32_t texture);

void __cdecl splash_progress_format_005a0fbf(char* output,const char* format,...);
std::int32_t __cdecl splash_progress_file_exists_0059dc30(const char* path);
void* __cdecl splash_progress_load_resource_0059d8e0(const char* path,std::uint32_t flags);
std::uint32_t __cdecl splash_progress_render_format_005032d0();
void __cdecl splash_progress_draw_tile_00563440(const void* item,
    std::int32_t x,std::int32_t y,std::int32_t width,std::int32_t height);
void __cdecl splash_progress_update_sprite_00563320(void* item);
void __cdecl splash_progress_draw_sprite_00563160(void* item,
    std::int32_t x,std::int32_t y,std::int32_t width,std::int32_t height);
void __cdecl splash_progress_free_00531f90(void* resource);
void __cdecl splash_progress_draw_overlay_00562810(void* item,
    std::int32_t x,std::int32_t y,std::int32_t width,std::int32_t height);
void __cdecl splash_progress_draw_text_00562680(std::int32_t x,std::int32_t y,
    std::uint32_t value,std::uint32_t font,std::uint32_t color);
void __cdecl splash_progress_enter_lock_005322b0(void* lock);
void __cdecl splash_progress_leave_lock_005322c0(void* lock);
std::int32_t __cdecl splash_progress_find_item_0048d720(std::int32_t index);
std::uint8_t __fastcall splash_progress_item_visible_00490390(void* item);
// Native boundary is an explicit-object C bridge. The original x86 edge is
// separately proved as ECX=this, short key on stack, callee ret 4.
void* __cdecl splash_progress_item_data_004903f0(void* item,std::int16_t key);
void __cdecl splash_progress_frame_begin_004b0d70();
void __cdecl splash_progress_driver_frame_begin_00534540();
void __cdecl splash_progress_driver_draw_0053d570(
    std::uint32_t texture,std::int32_t x,std::int32_t y);
void __cdecl splash_progress_driver_frame_end_00534550();
void __stdcall splash_progress_thrash_window_006bd9b0(std::uint32_t mode);
void __stdcall splash_progress_thrash_clear_window_006bd91c();
void __stdcall splash_progress_thrash_sync_006bd978(std::uint32_t zero);
void __stdcall splash_progress_thrash_pageflip_006bd948();
void __cdecl splash_progress_release_texture_00533f80(std::uint32_t texture);

} // namespace porsche
