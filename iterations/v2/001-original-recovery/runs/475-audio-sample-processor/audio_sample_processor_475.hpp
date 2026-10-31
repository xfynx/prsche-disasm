#pragma once
#include "../458-audio-release-chain/audio_release_chain_458.hpp"
namespace porsche {
// Original loader-zero DWORD callback cells. Never independent pointer aliases.
extern std::uint32_t audio_mixer_voice_hook_006b16b4;
extern std::uint32_t audio_mixer_block_hook_006b16b8;
extern std::uint32_t audio_mixer_accumulate_006b17d4;
void __cdecl audio_mixer_process_block_00598760(std::uint32_t count,std::uint32_t* buffers);
// Exact callsite contracts; these bodies remain unrecovered.
std::uint32_t __cdecl audio_mixer_ramp_voice_005980c0(std::uint32_t record,std::uint32_t count);
void __cdecl audio_mixer_stop_slot_00598670(std::uint32_t index);
}
