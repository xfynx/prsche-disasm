// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

namespace porsche {

// Original .bss cell 0069dd10. 00533020 is its sole writer and 00533050
// is its sole other reader.
extern std::uint32_t input_effects_initialized_0069dd10;

// Controlled child boundary for original 005331a0. Its body is not recovered
// by this packet; the native fixture verifies only the caller-visible cdecl
// argument, ordering, return-insensitivity, and callback mutations.
void __cdecl input_slot_effect_cleanup_005331a0(std::int32_t slot_index);

// Original 00533050..0053309a (75B, cdecl0, void).
void __cdecl input_effect_cleanup_00533050();

} // namespace porsche
