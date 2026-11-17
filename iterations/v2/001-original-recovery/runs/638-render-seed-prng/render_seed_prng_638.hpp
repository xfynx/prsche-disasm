// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

namespace porsche {

// 24-byte .data PRNG state block at original VA 0x005de910..0x005de927 (6 x uint32_t).
alignas(4) extern std::uint32_t render_seed_prng_state_005de910[6];

// Original 00538040..00538100 (193B, __cdecl uint32_t, ret 0).
std::uint32_t __cdecl render_seed_prng_next_00538040();

} // namespace porsche
