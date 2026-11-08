#pragma once
#include <cstdint>
// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run552 coded-audio kernel family. Exact original ABI/state contracts:
// 0059a910 void __cdecl(state, unused)          frame decode into state+0x680
// 0059abe0 void __cdecl(state, flag, out, stride) dequantize 108 slots
// 0059ad80 void __cdecl(state, bits)             skip bits, single refill
// 0059adc0 void __cdecl(base)                    54-point 3-tap smoothing
// 0059ae00 void __cdecl(state, offset, count)    12x12 synthesis blocks
// 0059b580 void __cdecl(source, out)             12-output lattice window
namespace porsche {
// Read-only original data, exact raw bit patterns.
extern const std::uint32_t audio_coded_scale_005e34c4[64];
extern const std::uint32_t audio_coded_level_005e37c8[87];
extern const std::uint8_t audio_coded_context_005e35c4[512];
extern const std::uint32_t audio_coded_quarter_005b2468;
extern const std::uint32_t audio_coded_gain_005b2778[2];
extern const std::uint32_t audio_coded_window_005c1808[4];
void __cdecl audio_coded_skip_bits_0059ad80(std::uint32_t state,std::uint32_t bits);
void __cdecl audio_coded_smooth_0059adc0(std::uint32_t base);
void __cdecl audio_coded_dequantize_0059abe0(std::uint32_t state,std::uint32_t flag,
                                             std::uint32_t out,std::int32_t stride);
void __cdecl audio_coded_window_0059b580(std::uint32_t source,std::uint32_t out);
void __cdecl audio_coded_synthesize_0059ae00(std::uint32_t state,std::uint32_t offset,
                                             std::int32_t count);
void __cdecl audio_coded_decode_0059a910(std::uint32_t state,std::uint32_t unused);
}
