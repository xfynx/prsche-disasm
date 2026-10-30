#pragma once
#include <cstdint>
#include "../443-audio-device-capabilities/audio_capabilities_443.hpp"
namespace porsche {
// Original count is a DWORD; consumers use its unsigned low WORD.
extern std::uint32_t audio_resource_map_count_006b48a0;
extern std::uint32_t audio_resource_map_006b48a4;
// 256 physical rows of24B; slot0 is reserved by0058f5b0, not guarded here.
alignas(4) extern std::uint8_t audio_resource_slots_006ad7b8[0x1800];
std::uint32_t __cdecl audio_resource_find_0058f820(std::uint32_t key);
std::uint32_t __cdecl audio_resource_erase_0058f7e0(std::uint32_t key);
std::int32_t __cdecl audio_resource_release_slot_0058f290(std::uint32_t slot);
std::int32_t __cdecl audio_record_remove_005996d0(void* record);
// Existing Run448 ABI facade: ignores its extra argument; zero original bodies.
void __cdecl audio_group_process_005996d0(void* record,std::uint32_t* scratch);
}
