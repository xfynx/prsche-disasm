#pragma once
#include "porsche/render_objects.hpp"
#include "porsche/render_startup.hpp"
#include "porsche/shared_runtime_globals.hpp"
#include <cstdint>

namespace porsche {
struct DisplayModeRecord { std::uint32_t a,b,format; };
// Porsche.exe SHA256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
// Original constructor entry 0x4677e0; full fixture reaches RET 0x10.
extern std::uint32_t render_display_name_0069ecf8;
extern std::uint32_t render_display_callback1_0069ecfc,render_display_callback2_0069ed00;
extern std::uint32_t render_display_selected_0069ed08;
extern std::uint32_t render_display_actual_width_00619784,render_display_actual_height_00619788;
extern std::uint32_t render_display_actual_mode_0061978c;
extern std::uint32_t& render_display_requested_width_00657a48;
extern std::uint32_t& render_display_requested_height_00657a4c;
extern std::uint32_t& render_display_requested_mode_00657a50;
extern std::uint32_t render_display_texture_width_005deac8,render_display_texture_height_005deacc;

// Typed recording boundaries for the original direct Win32 and engine calls.
std::uint32_t __cdecl render_get_desktop_005b2274();
std::uint32_t __cdecl render_get_window_dc_005b226c(std::uint32_t window);
std::int32_t __cdecl render_get_device_caps_005b2044(std::uint32_t dc,std::int32_t index);
void __cdecl render_release_dc_005b2268(std::uint32_t window,std::uint32_t dc);
void __cdecl render_message_box_005b2270(std::uint32_t window,const char* text,const char* title,std::uint32_t flags);
void __cdecl render_format_depth_005a0fbf(char* out,std::int32_t depth);
void __cdecl render_depth_failure_00557370();
void* __cdecl render_display_allocate_0059ef90(std::uint32_t size);
void* __cdecl render_display_resource_ctor_00540390(void* resource,std::uint32_t zero);
void* __cdecl render_display_driver_ctor_00557100(void* driver,void* resource);
void* __cdecl render_display_driver_alt_ctor_00556a90(void* driver,void* resource);
std::uint8_t __cdecl render_display_driver_start_vslot1(void* driver);
void __cdecl render_driver_failure_005a246e(std::uint32_t code);
void __cdecl render_display_prevideo_0044e2c0();
void __cdecl render_display_video_base_00537600(std::uint32_t a,std::uint32_t b,
    std::uint32_t c,std::uint32_t width,std::uint32_t height,std::uint32_t f);
std::uint32_t __cdecl render_display_video_mode_005376c0(std::uint32_t width,
    std::uint32_t height,std::uint32_t mode,std::uint32_t two,std::uint32_t one);
void __cdecl render_display_video_result_00468030(RenderDisplay* display,std::uint32_t result);

// Calls and state used by the remainder of the original constructor.
void __cdecl render_display_texture_reset_0053c3d0();
int __cdecl render_display_texture_reserve_00553fc0(std::uint32_t bytes);
void __cdecl render_display_texture_report_005a177b(const char* format,std::uint32_t bytes);
void* __cdecl render_display_surface_ctor_00538d10(void* surface,std::uint32_t driver_field);
void __cdecl render_display_surface_init_00538da0(void* surface,float width,float height,
    std::uint32_t a,std::uint32_t b,std::uint32_t c,std::uint32_t d);
void __cdecl render_display_surface_config_005392d0(void* surface,std::uint32_t a,
    std::uint32_t b,std::uint32_t c);
void* __cdecl render_display_surface_transform_00539f40(void* surface,std::uint32_t a,
                                                         std::uint32_t b,std::uint32_t c);
void __cdecl render_display_transform_init_00539b80(void* transform);
void __cdecl render_display_transform_compose_00539b30(void* matrix,void* transform,
                                                        std::uint32_t x,std::uint32_t y);
void __cdecl render_display_transform_attach_00539b00(void* surface,void* transform);
void __cdecl render_display_local_transform_00466e80(void* object,std::uint32_t zero);
std::uint32_t __cdecl render_display_getstate_006bd984(std::uint32_t key);
void __cdecl render_display_setstate_006bd97c(std::uint32_t key,std::uint32_t value);
void __cdecl render_display_thr_cleanup_00555390();
void __cdecl render_display_window_006bd9b0(std::uint32_t mode);
void __cdecl render_display_set_texture_006bd954(std::uint32_t value);
void __cdecl render_display_clear_window_006bd91c();
void* __cdecl render_display_texture_create_00535950(std::uint32_t w,std::uint32_t h,
                                                      std::uint32_t bits,std::uint32_t flags);
void __cdecl render_display_texture_bind_00534480(void* texture);
void __cdecl render_display_fill_00537e00(std::uint32_t color);
void __cdecl render_display_select_buffer_00556910(std::uint32_t index,std::uint32_t zero,
                                                    std::uint32_t one);
void* __cdecl render_display_texture_alloc_00554960(std::uint32_t w,std::uint32_t h,
    std::uint32_t format,std::uint32_t a,std::uint32_t b,const char* name);
void __cdecl render_display_texture_update_005550e0();
void __cdecl render_display_texture_copy_00554d70(void* texture,void* pixels,std::uint32_t zero);
void __cdecl render_display_texture_release_00555440(void* texture);
void __cdecl render_display_draw_quad_006bd9a8(const void* a,const void* b,const void* c,const void* d);
void __cdecl render_display_flush_006bd970();
void __cdecl render_display_sync_006bd978(std::uint32_t zero);
void* __cdecl render_display_buffer_alloc_00531ca0(const char* format,std::uint32_t bytes,
                                                    std::uint32_t zero);
void __cdecl render_display_read_rect_006bd96c(std::uint32_t x,std::uint32_t y,
    std::uint32_t width,std::uint32_t height,void* output);
bool __cdecl render_display_compare_pixel_00468110(std::uint32_t pixel,std::uint32_t format);
void __cdecl render_display_release_texture_00533f80(void* texture);
std::uint32_t __cdecl render_display_present_0044e870(std::uint32_t ok);
std::uint32_t __cdecl render_display_driver_present_vslot0(void* driver,std::uint32_t ok);
void __cdecl render_display_finish_driver_00537850(void* driver_field,std::uint32_t one);
void __cdecl render_display_finish_init_004b0eb0();

// Replays the function through the call at 0x4679c7, the current measured boundary.
RenderDisplay* __cdecl render_display_through_004679c7(RenderDisplay* object,
    const char* name,std::uint32_t selected,std::uint32_t flags,const char* resolution);
}
