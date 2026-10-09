#pragma once
#include <cstdint>

namespace porsche {

// Canonical scalar owners for Porsche.exe words touched by 005588a0.
extern std::uint32_t object_update_word_006a3afc;
extern std::uint32_t object_update_word_006a3b00;
extern std::uint32_t object_update_word_006a3b04;
extern std::uint32_t object_update_word_005deb58;

// Typed platform boundary for the imported KERNEL32!GetTickCount at 005b2080.
std::uint32_t __stdcall platform_get_tick_count();

void __cdecl object_update_005588a0(void* configuration);

} // namespace porsche
