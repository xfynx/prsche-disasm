#pragma once
#include "../501-audio-pcm-stream-lookup/audio_pcm_stream_lookup_501.hpp"
namespace porsche {
extern std::uint32_t audio_adpcm_bit_masks_005e34a0[9];
extern const float audio_adpcm_scale_005b2608;
extern const float audio_adpcm_factor_scale_005b27b4;
extern const float audio_adpcm_factor_bias_005c1804;
std::uint32_t __cdecl audio_adpcm_read_bits_0059a8c0(std::uint32_t state,std::uint32_t bits);
void __cdecl audio_adpcm_initialize_0059a800(std::uint32_t data,std::uint32_t state);
std::uint32_t __cdecl audio_nibble_position_00597db0(std::uint32_t object);
std::uint32_t __cdecl audio_adpcm_position_00597e20(std::uint32_t object);
// Actual475 cdecl5 dispatch; real callback bodies remain unresolved.
std::int32_t __cdecl audio_adpcm_process_00597e30(std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t);
std::int32_t __cdecl audio_adpcm_stream_process_0059c1e0(std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t);
std::int32_t __cdecl audio_nibble_process_00597c40(std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t);
std::int32_t __cdecl audio_nibble_loop_process_0059c890(std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t);
std::int32_t __cdecl audio_nibble_stream_process_0059c3c0(std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t);
std::int32_t __cdecl audio_resampler_stream_process_0059b690(std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t);
// Actual597d28/59c4b3/59c4ff/59c953 push state, discard4, ignore return.
void __cdecl audio_nibble_decode_x87_0059a5a0(std::uint32_t state);
void __cdecl audio_nibble_decode_sse_0059a660(std::uint32_t state);
void __cdecl audio_nibble_decode_3dnow_0059a730(std::uint32_t state);
}
