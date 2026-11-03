#pragma once
#include "audio_mixer_configuration_486.hpp"
namespace porsche {
// Original physical read window, not a semantic predictor-array capacity.
extern std::uint8_t audio_nibble_read_window_005e3b28[80];
extern std::uint8_t audio_nibble_read_tail_006b0800[192];
// Future59cd70's DWORD writer/unaligned readers must share this same storage.
constexpr std::uint32_t audio_nibble_resampler_scratch_offset_005e3b58=48;
// Actual504/506 consumers push one state pointer, clean4, ignore volatile return.
void __cdecl audio_nibble_decode_x87_0059a5a0(std::uint32_t state);
void __cdecl audio_nibble_decode_sse_0059a660(std::uint32_t state);
}
