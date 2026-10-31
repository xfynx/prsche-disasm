#pragma once
#include <cstdint>
extern float _DAT_005b253c;
extern float _DAT_005b2624;
namespace porsche {
alignas(4) extern std::uint16_t audio_sine_quarter_005e3924[257];
std::int32_t __cdecl audio_fixed_sine_0059b630(std::uint32_t phase);
void __cdecl audio_ds_spatial_vector_00597f80(std::uint32_t heading,std::uint32_t elevation,std::uint32_t* output);
}
