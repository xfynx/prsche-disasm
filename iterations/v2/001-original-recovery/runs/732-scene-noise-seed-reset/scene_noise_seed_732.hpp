// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run732: scene noise seed reset (0044f240, 174B) and companion PRNG seed writer (00538110, 65B).
#pragma once

#include <cstdint>

namespace porsche {

// 4-byte .rdata float at original VA 0x005b3ca4 (raw dword 0x2f800000 = 2^-32f).
extern const float scene_noise_inv_2pow32_005b3ca4;

// 4-byte .data flag at original VA 0x005ce938 (initial dword 0x00000001).
extern std::uint32_t scene_noise_flag_005ce938;

// 1,068-byte .bss gradient table at original VA 0x00619804..0x00619c2f (267 floats).
extern float scene_noise_gradient_00619804[267];

// 8,192-byte .bss permutation table at original VA 0x00619c30..0x0061bc2f (4,096 int16_t words).
extern std::int16_t scene_noise_perm_00619c30[4096];

// Original 00538110..00538150 (65B, __cdecl void(uint32_t), ret 0).
void __cdecl render_seed_prng_seed_00538110(std::uint32_t seed);

// Original 0044f240..0044f2ed (174B, __cdecl void(), ret 0).
void __cdecl scene_stage_reset_0044f240();

} // namespace porsche
