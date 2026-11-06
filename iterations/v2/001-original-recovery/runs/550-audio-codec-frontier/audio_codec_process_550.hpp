#pragma once
#include "../504-audio-coded-constructors/audio_coded_constructors_504.hpp"
#include "../519-audio-stream-capture-fill/audio_stream_capture_fill_519.hpp"
#include "porsche/application_audio_device.hpp"
namespace porsche {
// Original state+flag and input+output+state kernel ABIs. Math remains unrecovered.
void __cdecl audio_adpcm_decode_0059a910(std::uint32_t state,std::uint32_t flag);
void __cdecl audio_resampler_decode_00597810(std::uint32_t input,std::uint32_t output,std::uint32_t state);
}
