// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "porsche/frame_services.hpp"
#include "porsche/application_audio_device.hpp"
#include "../434-audio-canonical-bindings/audio_canonical_434.hpp"
#include "../435-audio-stop-voice/audio_stop_435.hpp"

namespace porsche {

// Original entry 00590290..00590292 (3 bytes).
std::int32_t __cdecl audio_send_validate_00590290(std::uint32_t flags, std::uint32_t level);

// Original entry 00589d70..00589de8 (121 bytes).
void __cdecl audio_voice_recompute_send_00589d70(std::uint32_t bus, std::uint32_t voice_slot);

// Original entry 00598eb0..00598f12 (99 bytes).
std::uint32_t __cdecl audio_voice_apply_send_00598eb0(std::uint32_t voice_slot, std::uint32_t bus);

// Original entry 005902a0..0059033c (157 bytes).
std::int32_t __cdecl audio_channel_send_level_005902a0(std::uint32_t handle, std::uint32_t bus,
                                                       std::int32_t level);

// frame_services_boundary_00565cd0 (137 bytes) is declared in porsche/frame_services.hpp.

} // namespace porsche
