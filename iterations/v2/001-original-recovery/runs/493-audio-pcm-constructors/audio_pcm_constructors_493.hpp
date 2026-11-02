#pragma once
#include "../492-audio-pcm-cpp/audio_pcm_cpp_492.hpp"
namespace porsche {
std::int32_t __cdecl audio_pcm_channel_owner_00589710(std::uint32_t channel);
std::uint32_t __cdecl audio_pcm_channel_member_00589740(std::uint32_t channel);
std::uint32_t __cdecl audio_pcm_position_00597b50(std::uint32_t object);
std::int32_t __cdecl audio_pcm_process_00597b60(std::uint32_t object,std::uint32_t count,std::uint32_t input,std::uint32_t output,std::uint32_t flags);
std::int32_t __cdecl audio_pcm_loop_process_0059cba0(std::uint32_t object,std::uint32_t count,std::uint32_t input,std::uint32_t output,std::uint32_t flags);
void __cdecl audio_pcm_decode_u8_0059a520(std::uint32_t count,std::uint32_t source,std::uint32_t output);
// Proved original constructor call/assignment contracts; bodies remain open.
std::int32_t __cdecl audio_pcm_stream_find_0059c130(std::int32_t owner);
std::int32_t __cdecl audio_pcm_stream_process_0059ca50(std::uint32_t object,std::uint32_t count,std::uint32_t input,std::uint32_t output,std::uint32_t flags);
}
