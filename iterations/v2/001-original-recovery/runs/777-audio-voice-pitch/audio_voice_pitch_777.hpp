// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "../434-audio-canonical-bindings/audio_canonical_434.hpp"
#include "../751-audio-voice-start/audio_voice_start_751.hpp"

namespace porsche {

// Original 256-byte pitch scale table at 005e1d3c..005e1e3b (.data).
extern const std::uint8_t audio_pitch_scale_table_005e1d3c[256];

// Recovered functions (2 bodies, 328 code bytes total; 00589f40 matches audio_voice_start_751.hpp).
std::int32_t __cdecl audio_voice_pitch_scale_00589e80(std::int32_t cents);
void __cdecl audio_voice_recompute_pitch_00589f40(std::uint32_t voice_slot);

} // namespace porsche
