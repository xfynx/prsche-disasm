#pragma once
#include "../462-audio-directsound-initialize/audio_directsound_state_462.hpp"
#include "../434-audio-canonical-bindings/audio_canonical_434.hpp"
#include "../442-audio-initialization/audio_initialization_442.hpp"
namespace porsche {
void __cdecl audio_thread_mix_0058f8e0();
void __cdecl audio_thread_mixer_0058f8f0();
// Exact used call contracts. Original lower bodies remain unrecovered.
void __cdecl audio_thread_mix_refresh_0058fcd0();
void __cdecl audio_thread_mix_render_0058fbc0(std::uint32_t* outputs,std::uint32_t count);
void __cdecl audio_thread_mix_voices_0058f6c0();
}
