// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "../464-audio-probe-startup/audio_probe_startup_464.hpp"
#include "porsche/clock_worker.hpp"
#include "porsche/file_events.hpp"
#include "porsche/heap.hpp"

namespace porsche {

using RenderClockQueryPerformanceFrequency =
    std::int32_t (__stdcall*)(std::int64_t* frequency);
using RenderClockQueryPerformanceCounter =
    std::int32_t (__stdcall*)(std::int64_t* performance_count);

// Win32 IAT facades for 00555fa0:
// [0x005b214c] QueryPerformanceFrequency, [0x005b2154] QueryPerformanceCounter.
extern RenderClockQueryPerformanceFrequency render_clock_query_performance_frequency;
extern RenderClockQueryPerformanceCounter render_clock_query_performance_counter;

// Newly owned .data flags from Porsche.exe (initial PE values: 0, 1, 0, 0).
extern std::uint32_t cpu_has_p6_005deb14;
extern std::uint32_t cpu_has_rdtsc_005deb24;
extern std::uint32_t cpu_is_cyrix_005deb34;
extern std::uint32_t cpu_is_amd_005deb38;

// Original 00555a10..00555bbe (431B, __cdecl, ret 0).
std::int32_t __cdecl render_clock_quantize_hz_00555a10(std::int32_t raw_hz);

// Original 00555fa0..005560ad (270B, __cdecl, ret 0).
std::int32_t __cdecl render_clock_measure_qpc_rdtsc_00555fa0();

// Original 005560b0..005561c5 (278B, __cdecl, ret 0).
std::int32_t __cdecl render_clock_measure_div_loop_005560b0();

} // namespace porsche
