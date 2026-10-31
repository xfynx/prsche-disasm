#pragma once
#include "audio_directsound_state_462.hpp"
#include "../455-audio-device-lifecycle/audio_device_lifecycle_455.hpp"
#include "../458-audio-release-chain/audio_release_chain_458.hpp"
#include "../439-audio-voice-cleanup/voice_cleanup_439.hpp"
namespace porsche {
struct AudioMixerConfig462 {
    std::uint32_t rate;
    std::uint8_t bits,channels,mono,opaque_07;
    void(__cdecl* callback)(std::uint32_t);
};
static_assert(sizeof(AudioMixerConfig462)==12);
std::int32_t __cdecl audio_device_initialize_ds_0058ebe0();
// Original unresolved children; no production implementations in this packet.
void __cdecl audio_ds_mixer_initialize_00598230(const AudioMixerConfig462* config);
std::int32_t __cdecl audio_ds_apply_property_0058e780(std::uint32_t a,std::uint32_t b,std::uint32_t c);
void __cdecl audio_ds_spatial_vector_00597f80(std::uint32_t angle,std::uint32_t elevation,std::uint32_t* xyz_bits);
extern const std::uint8_t audio_ds_spatial_interface_guid_005bfd00[16];
extern const std::uint8_t audio_ds_buffer_property_guid_005c17e8[16];
extern const double audio_ds_spatial_scale_005b6bd8;
}
