#pragma once
#include "porsche/render_display.hpp"
#include "porsche/render_loader.hpp"
#include <cstdint>

namespace porsche {
// Exact data touched by the original THRASH dispatch adapters.
extern std::uint32_t render_driver_requested_a_0069e08c;
extern std::uint32_t render_driver_requested_b_0069e090;
extern std::uint32_t render_driver_requested_c_0069e094;
extern std::uint32_t render_driver_requested_d_0069e070;
extern std::uint32_t render_driver_requested_e_0069e074;
extern std::uint32_t render_driver_requested_f_0069e06c;
extern std::uint32_t render_driver_bounds_a_006a643c;
extern std::uint32_t render_driver_bounds_b_006a6438;
extern std::uint32_t render_driver_bounds_c_006a6430;
extern std::uint32_t render_driver_bounds_d_006a6434;
extern std::uint32_t render_driver_limit_a_006a6448;
extern std::uint32_t render_driver_limit_b_006a6444;
extern std::uint32_t render_driver_limit_c_006a6440;

// 0x5728b0 is the next renderer/window routine. Its internal body is outside
// this run; this boundary preserves the original four cdecl stack arguments.
void __cdecl render_driver_apply_005728b0(std::uint32_t a,std::uint32_t b,
                                          std::uint32_t c,std::uint32_t zero);

std::uint32_t __cdecl render_driver_select_mode_00572a00(
    std::uint32_t width,std::uint32_t height,std::uint32_t mode,
    std::uint32_t two,std::uint32_t one);
std::uint32_t __cdecl render_driver_compare_mode_00572990(
    const std::uint32_t mode_record[10],std::uint32_t width,
    std::uint32_t height,std::uint32_t mode,std::uint32_t two,
    std::uint32_t one);
void __cdecl render_driver_apply_settings_005726f0(
    std::uint32_t a,std::uint32_t b,std::uint32_t d,std::uint32_t e);
}
