// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>
#include "porsche/frame_services.hpp"
#include "porsche/application_audio_device.hpp"
#include "../478-audio-resource-controls/audio_resource_controls_478.hpp"
#include "../561-audio-stream-creation/audio_stream_creation_561.hpp"
#include "../434-audio-canonical-bindings/audio_canonical_434.hpp"

namespace porsche {

// Original entry 00565dd0..00565e6e (159 bytes).
std::int32_t __cdecl audio_channel_ramp_00565dd0(
    std::uint32_t handle, std::int32_t steps, std::int32_t target);

// Original entry 00566ae0..00566b37 (88 bytes).
std::int32_t __cdecl audio_stream_service_ramp_00566ae0(
    std::int32_t slot, std::int32_t ms, std::int32_t target);

// Original entry 004ae3c0..004ae464 (165 bytes) is declared in
// porsche/frame_services.hpp as frame_services_boundary_004ae3c0.

} // namespace porsche
