#pragma once
#include "../504-audio-coded-constructors/audio_coded_constructors_504.hpp"
#include "../512-audio-nibble-decoders/audio_nibble_decoders_512.hpp"
#include "../519-audio-stream-capture-fill/audio_stream_capture_fill_519.hpp"
namespace porsche {
std::int32_t __cdecl audio_nibble_drain_0059d5f0(std::uint32_t available,std::uint32_t buffer,std::uint32_t requested,std::uint32_t output_slot);
// Actual59c9c0 stored callback and59c9d6 cdecl5 call; original505B unresolved.
std::int32_t __cdecl audio_nibble_loop_continue_0059c690(std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t);
}
