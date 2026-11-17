// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "porsche/frame_services.hpp"
#include "porsche/application_audio_device.hpp"
#include "../434-audio-canonical-bindings/audio_canonical_434.hpp"
#include "../435-audio-stop-voice/audio_stop_435.hpp"

namespace porsche {

// Loader-zero .data globals owned by 004af900 (21 bytes total).
extern std::int8_t frame_audio_mode_006573a4;
extern std::uint32_t frame_audio_tag_00657388;
extern std::int32_t frame_audio_primary_handle_006573a8;
extern std::int32_t frame_audio_secondary_handle_006573ac;
extern std::int32_t frame_audio_extra_handles_00656ae8[2];

// Original entry 00589df0..00589e7b (140 bytes).
void __cdecl audio_voice_recompute_gain_00589df0(std::uint32_t voice_slot);

// Original entry 00590d10..00590d4d (62 bytes).
std::uint32_t __cdecl audio_voice_apply_gain_00590d10(std::uint32_t voice_slot);

// Original entry 005662b0..0056633c (141 bytes).
std::int32_t __cdecl audio_channel_volume_005662b0(std::uint32_t handle, std::uint32_t volume);

// frame_services_boundary_00566340 (50 bytes) and frame_services_boundary_004af900 (112 bytes)
// are declared in porsche/frame_services.hpp.

} // namespace porsche
