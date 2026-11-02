#pragma once
#include "../493-audio-pcm-constructors/audio_pcm_constructors_493.hpp"
namespace porsche {
// Exact [006b7cc0,006b7d00) range scanned by0059c130 and00561200.
extern std::uint32_t audio_stream_slots_006b7cc0[16];
// Original0059caa2/0059ca6e cdecl3 contracts; providers remain unrecovered.
std::uint32_t __cdecl audio_stream_acquire_00561800(std::uint32_t index,std::uint32_t member,std::uint32_t* length);
void __cdecl audio_stream_acknowledge_005618c0(std::uint32_t index,std::uint32_t member,std::uint32_t count);
}
