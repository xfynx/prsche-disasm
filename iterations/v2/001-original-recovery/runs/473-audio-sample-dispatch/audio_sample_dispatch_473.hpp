#pragma once
#include "../466-audio-mixer-control/audio_mixer_control_466.hpp"
#include "../458-audio-release-chain/audio_release_chain_458.hpp"
namespace porsche {
extern std::uint32_t audio_voice_completion_counter_006aeff0;
extern std::uint16_t audio_mixer_block_stride_006b16ac;
void __cdecl audio_thread_mix_render_0058fbc0(std::uint32_t* buffers,std::uint32_t samples);
void __cdecl audio_mixer_render_chunks_00598940(std::uint32_t* buffers,std::uint32_t samples);
void __cdecl audio_voice_check_finished_0058f650();
// Proved raw callsite contracts; the lower algorithms remain unresolved.
void __cdecl audio_mixer_process_block_00598760(std::uint32_t count,std::uint32_t* buffers);
void __cdecl audio_mixer_convert_block_0059bce0(std::uint32_t count,std::uint32_t source,std::uint32_t destination);
}
