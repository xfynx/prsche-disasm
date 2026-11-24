// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "porsche/application_state.hpp"
#include "porsche/fe_callbacks.hpp"
#include "porsche/formatter_stdio.hpp"
#include "porsche/input_state.hpp"
#include "porsche/startup_sequence.hpp"
#include "../400-frame-loop-clusters/frame_loop_clusters_400.hpp"
#include "../598-startup-clock-callback/startup_clock_callback_598.hpp"
#include "../680-input-ff-slot-and-render-leaves/input_ff_slot_render_680.hpp"
#include "../688-frame-control-create-and-gain/input_ff_frame_control_688.hpp"
#include "../695-ff-effect-initialize/ff_effect_initialize_695.hpp"

namespace porsche {

static_assert(sizeof(void*) == 4, "original x86 pointer ABI");

// Loader-zero .bss cell at 005e9540..005e9543 (4 bytes, immediately after
// Run695's 005e9408..005e953b block; 005e953c..005e953f unused).
extern std::int32_t ff_effect_cooldown_005e9540;

// Newly owned read-only .data format literals for startup_sequence_report_005a177b.
extern const char startup_audio_heap_fmt_005d1400[26];
extern const char startup_mem_left_fmt_005d6e3c[36];

// Recovered functions (ff_effect_frame_tick_004123e0 declared in input_ff_render_leaves_683 /
// callers; startup_sequence_report_005a177b declared in porsche/startup_sequence.hpp).
void __cdecl ff_effect_frame_tick_004123e0();
void __cdecl ff_effect_scale_steer_00412730(
    const void* car, std::int32_t* out_abs, std::int32_t* out_signed);
void __cdecl ff_effect_update_engine_004127a0(const void* car);
void __cdecl ff_effect_update_speed_gear_004128b0(const void* car);
void __cdecl ff_effect_trigger_collision_00412cf0(
    std::int32_t* direction_ptr,
    std::uint32_t* duration_ptr,
    const std::uint32_t* strength_ptr);
double __cdecl ff_effect_calc_grip_004938a0(const void* car);
double __cdecl ff_effect_calc_road_00493980(const void* car);
std::uint32_t __cdecl ff_effect_update_params_00533910(
    std::int32_t slot,
    std::uint32_t start_mode,
    const void* type_specific_ptr,
    std::uint32_t* duration_ptr,
    const std::uint32_t* gain_ptr,
    const std::int32_t* button_ptr,
    const std::uint32_t* direction_deg_ptr,
    const std::uint32_t* envelope_4words_ptr);
void __cdecl ff_effect_slot_start_00533810(std::int32_t slot);
std::uint32_t __cdecl ff_effect_start_retry_00533880(
    void* input_dev, void* effect_obj, std::uint32_t iterations, std::uint32_t flags);
std::uint32_t __cdecl ff_effect_slot_active_00533b40(std::int32_t slot);

} // namespace porsche
