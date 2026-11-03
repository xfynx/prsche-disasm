#pragma once
#include "../519-audio-stream-capture-fill/audio_stream_capture_fill_519.hpp"
namespace porsche {
extern const float audio_stream_s16_scale_005b3e10;
extern const float audio_stream_coefficient_scale_005b3880;
// Nonstandard original CRT input: live ST0, consumed once. cdecl0 preserves
// ordinary callee state and returns signed64 bits in EDX:EAX.
std::int64_t __cdecl audio_stream_ftol_005a0f98();
void __cdecl audio_stream_correlate_00597120(std::uint32_t input,std::int32_t count,std::int32_t order,std::uint32_t output);
// Actual original stage contracts; these providers remain open.
void __cdecl audio_stream_metric_00597360(std::uint32_t input,std::uint32_t metric);
void __cdecl audio_stream_coefficients_00597180(std::uint32_t correlation,std::int32_t order,std::uint32_t coefficients,std::uint32_t gain);
}
