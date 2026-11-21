// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run732: scene noise seed reset (0044f240..0044f2ed, 174B) and companion PRNG seed writer
// (00538110..00538150, 65B).
// Original body SHA-256 (raw PE bytes, verified by verify-v2-native-batch.py):
//   0044f240 567e16f088870cff7382e0038b3c9c6dd4d8f2f672a006168ea1db49f30f5d92
//   00538110 400655825fa9e64352eb1a689b4d317efd33a5ef69d9f3ad6e59da71d6b5f885
#include "scene_noise_seed_732.hpp"

#include "application_view_lifecycle_693.hpp"
#include "render_seed_prng_638.hpp"
#include "render_surface_init_511.hpp"

#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Original x86/x87 target required.
#endif

namespace porsche {

const float scene_noise_inv_2pow32_005b3ca4 = 2.3283064365386963e-10f;
std::uint32_t scene_noise_flag_005ce938 = 1u;
float scene_noise_gradient_00619804[267]{};
std::int16_t scene_noise_perm_00619c30[4096]{};

namespace {

void store_scaled_noise_word(float* dst, std::uint32_t word) noexcept {
    const std::uint32_t wide[2] = {word, 0u};
    __asm {
        mov eax, dst
        fild qword ptr wide
        fmul scene_noise_inv_2pow32_005b3ca4
        fsub render_surface_half_005b23f0
        fadd st(0), st(0)
        fstp dword ptr [eax]
    }
}

} // namespace

void __cdecl render_seed_prng_seed_00538110(std::uint32_t seed) {
    std::uint32_t acc = seed + 0xf22d0e56u;
    render_seed_prng_state_005de910[0] = acc;
    acc -= 0x69fbe76du;
    render_seed_prng_state_005de910[1] = acc;
    acc += 0x3df3b646u;
    render_seed_prng_state_005de910[2] = acc;
    acc += 0x40dde76du;
    render_seed_prng_state_005de910[3] = acc;
    acc -= 0x68cd851fu;
    render_seed_prng_state_005de910[4] = acc;
    acc += 0xd1a9fbe7u;
    render_seed_prng_state_005de910[5] = acc;
}

void __cdecl scene_stage_reset_0044f240() {
    scene_noise_flag_005ce938 = 0u;
    const std::uint32_t saved_seed = render_seed_prng_next_00538040();
    render_seed_prng_seed_00538110(0x3039u);

    for (std::uint32_t i = 0u; i < 267u; ++i) {
        const std::uint32_t word = render_seed_prng_next_00538040();
        store_scaled_noise_word(&scene_noise_gradient_00619804[i], word);
    }

    for (std::int32_t i = 0; i < 4096; ++i) {
        scene_noise_perm_00619c30[i] = static_cast<std::int16_t>(i);
    }

    for (std::int32_t i = 4095; i >= 0; --i) {
        const std::uint32_t j = render_seed_prng_next_00538040() & 0x0fffu;
        const std::int16_t cur = scene_noise_perm_00619c30[i];
        scene_noise_perm_00619c30[i] = scene_noise_perm_00619c30[j];
        scene_noise_perm_00619c30[j] = cur;
    }

    render_seed_prng_seed_00538110(saved_seed);
}

} // namespace porsche
