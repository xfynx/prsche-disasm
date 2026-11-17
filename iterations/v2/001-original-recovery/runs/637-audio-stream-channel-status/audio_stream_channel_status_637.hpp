// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "porsche/frame_services.hpp"
#include "porsche/application_audio_device.hpp"
#include "../561-audio-stream-creation/audio_stream_creation_561.hpp"
#include "../434-audio-canonical-bindings/audio_canonical_434.hpp"

namespace porsche {

// Original entry 00567810..0056784f (64 bytes).
std::int32_t __cdecl audio_stream_service_volume_00567810(
    std::int32_t slot, std::uint32_t volume);

// Original entry 00567850..00567893 (68 bytes).
std::int32_t __cdecl audio_stream_service_status_00567850(std::int32_t slot);

// Original entry 00591320..00591372 (83 bytes).
std::int32_t __cdecl audio_channel_status_00591320(std::uint32_t handle);

} // namespace porsche
