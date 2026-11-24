// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

namespace porsche {

extern std::uint32_t render_alloc_flags_005deb60;
extern std::uint32_t render_service_palette_0069eb98;
extern std::uint32_t render_service_default_ops_005dec18[12];
extern void* render_service_ops_005dec08;
extern std::uint32_t render_mouse_ops_table_005dfb60[];

std::uint32_t __cdecl render_service_set_flag_0053cec0(std::uint32_t value);
void* __cdecl render_service_alloc_0053d360(std::int32_t size);
void __cdecl render_service_free_0053d380(void* ptr);
void* __cdecl render_mouse_alloc_00572610(std::int32_t size);
void __cdecl render_mouse_free_00572630(void* ptr);

void __cdecl window_worker_callback();
std::uint32_t __cdecl window_worker_idle_callback(
    std::uint32_t period, std::uint32_t delay, std::uint32_t callback);

} // namespace porsche
