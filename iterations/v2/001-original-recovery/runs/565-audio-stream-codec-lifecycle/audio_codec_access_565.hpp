#pragma once
#include <cstdint>
namespace porsche {
// Original argument words remain raw x86 values; no handle remapping is implied.
std::uint32_t __cdecl audio_stream_handle_validate_0056b380(std::uint32_t,std::uint32_t*,std::uint32_t*);
void __cdecl audio_stream_greedy_set_0056b4c0(std::uint32_t,std::int32_t);
void __cdecl audio_stream_greedy_transition_0056b540(std::uint32_t,std::uint32_t);
std::int32_t __cdecl audio_stream_codec_frames_0056c840(std::uint32_t);
std::int32_t __cdecl audio_stream_codec_set_005912e0(std::uint32_t,std::int32_t);
}
