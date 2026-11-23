// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "../518-render-driver-start/render_driver_start_518.hpp"
#include "../521-render-initialize/render_initialize_521.hpp"
#include "../525-render-driver-destruction/render_driver_destruction_525.hpp"
#include "../536-render-resource-nodes/render_resource_node_536.hpp"
#include "../671-font-state-and-vec3-dist/font_state_vec3_671.hpp"
#include "porsche/application_alloc.hpp"
#include "porsche/game_setup.hpp"

namespace porsche {

// Owned loader-zero .bss state cells for render driver calibration & service init.
extern std::uint32_t render_calibration_initialized_0069de40; // 0069de40..0069de43 (4B)
extern std::uint32_t render_calibration_cookie_0069de48;      // 0069de48..0069de4b (4B)
extern std::uint8_t render_calibration_flag_0069de4c;         // 0069de4c (1B)
extern void* render_service_font_0069eb90;                    // 0069eb90..0069eb93 (4B)
extern std::uint32_t render_service_initialized_0069eb94;     // 0069eb94..0069eb97 (4B)
extern std::int32_t render_service_capacity_0069eba0;         // 0069eba0..0069eba3 (4B)
extern std::int32_t* render_service_indices_0069eba4;         // 0069eba4..0069eba7 (4B)

// Typed unrecovered .data / .rdata / callee boundaries.
extern std::uint32_t render_mouse_ops_table_005dfb60[];
extern const std::uint8_t render_debug_font_005dfd8c[];
extern const std::uint32_t render_calibration_vtable_005bb708[1];
extern void* render_service_ops_005dec08;
void* __cdecl render_debug_font_create_0053c6c0(const void* font_data);
void __cdecl render_font_prepare_00571a10(void* font);

// Original 00536870..00536947 (216B, __cdecl, ret 0; void).
// Declared in ../518-render-driver-start/render_driver_start_518.hpp.
void __cdecl render_driver_calibrate_00536870();

// Original 0053c8d0..0053c8d9 (10B, __cdecl, ret 0; void).
void __cdecl render_service_set_ops_0053c8d0(void* ops_table);

// Original 0053c8e0..0053c90c (45B, __cdecl, ret 0; void).
// Declared in ../521-render-initialize/render_initialize_521.hpp.
void __cdecl render_initialize_service_0053c8e0();

// Original 0053d840..0053d895 (86B, __cdecl, ret 0; void).
void __cdecl render_service_init_indices_0053d840(std::int32_t count);

} // namespace porsche
