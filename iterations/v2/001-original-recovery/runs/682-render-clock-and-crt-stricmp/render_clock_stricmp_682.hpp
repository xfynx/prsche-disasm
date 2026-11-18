// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "porsche/formatter_float_helpers.hpp"
#include "porsche/formatter_parser.hpp"
#include "porsche/heap.hpp"
#include "porsche/render_mode.hpp"
#include "porsche/render_objects.hpp"
#include "porsche/shared_runtime_globals.hpp"
#include "../345-diagnostic-devices/diagnostic_devices.hpp"
#include "../677-audio-bank-state-and-cpu-feature-leaves/audio_bank_cpu_leaves_677.hpp"
#include "../679-render-clock-calibration-leaves/render_clock_calibration_679.hpp"

namespace porsche {

using RenderClockGetVersionExA = std::int32_t (__stdcall*)(void* version_information);

// Win32 IAT facade for 00555bc0: [0x005b2150] GetVersionExA.
// QueryPerformanceFrequency ([0x005b214c]) reuses render_clock_query_performance_frequency
// from Run679 (render_clock_calibration_679.hpp).
extern RenderClockGetVersionExA render_clock_get_version_ex_a;

// Newly owned .data globals from Porsche.exe (all initial PE values are 0).
extern std::uint32_t render_clock_hz_005deae4;
extern char cpu_vendor_005deae8[16];
extern std::uint32_t cpu_serial_005deaf8[3];
extern std::uint32_t cpu_family_005deb04;
extern std::uint32_t cpu_model_005deb08;
extern std::uint32_t cpu_stepping_005deb0c;
extern std::uint32_t cpu_has_3dnow_005deb20;
extern std::uint32_t cpu_has_cmov_005deb28;
extern std::uint32_t cpu_has_movnt_005deb2c;
extern std::uint32_t cpu_is_centaur_005deb3c;

// Original 005a1ebf..005a1f49 (139B, __cdecl, ret 0): CRT atol.
std::int32_t __cdecl crt_atol_005a1ebf(const char* str);

// Original 005a1f4a..005a1f54 (11B, __cdecl, ret 0): CRT atoi.
std::int32_t __cdecl crt_atoi_005a1f4a(const char* str);

} // namespace porsche
