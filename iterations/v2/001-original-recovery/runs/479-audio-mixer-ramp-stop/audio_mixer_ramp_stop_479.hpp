#pragma once
#include "../475-audio-sample-processor/audio_sample_processor_475.hpp"
namespace porsche {
extern std::uint32_t audio_mixer_stopped_hook_006b16a8;
extern const float audio_mixer_gain_scale_005b246c;
extern const float audio_mixer_gain_floor_005b2738;
void __cdecl audio_mixer_refresh_gain_005980a0(std::uint32_t record);
void __cdecl audio_mixer_detach_slot_00598690(std::uint32_t index);
void __cdecl audio_mixer_target_slot_00598700(std::uint32_t index,std::uint32_t gain_bits,const std::uint32_t* factors);
}
