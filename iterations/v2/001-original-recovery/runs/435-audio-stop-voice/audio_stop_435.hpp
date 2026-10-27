#pragma once
#include "audio_canonical_434.hpp"

namespace porsche {
// Separate original BSS cell, outside canonical device span 006b48b0..006b4a3b.
extern std::uint32_t audio_backend_voice_table_006b489c;
std::int32_t __cdecl audio_backend_stop_voice_0058a8b0(std::uint32_t voice_slot);
// Unrecovered production endpoints. Their returns are unused by 0058a8b0.
void __cdecl audio_backend_voice_release_00597010(void* voice_data);
void __cdecl audio_backend_voice_finalize_00589c00(std::uint32_t voice_slot);
}
