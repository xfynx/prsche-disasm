// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "porsche/application_audio_device.hpp"
#include "../434-audio-canonical-bindings/audio_canonical_434.hpp"
#include "../751-audio-voice-start/audio_voice_start_751.hpp"

namespace porsche {

// Allocator-private BSS cells (12 bytes total: 8B selection list + 4B generation).
extern std::int16_t audio_voice_selection_006b48a8[4];
extern std::uint32_t audio_voice_generation_006ad74c;

// Recovered functions (2 bodies, 820 code bytes total; 005898f0 matches audio_voice_start_751.hpp).
std::int32_t __cdecl audio_voice_selection_contains_005898b0(
    std::int32_t candidate,
    std::int32_t count);
std::int32_t __cdecl audio_backend_allocate_voice_005898f0(
    std::int32_t channel_count,
    std::uint32_t priority,
    std::uint32_t* handle,
    std::uint32_t first,
    std::uint32_t last);

} // namespace porsche
