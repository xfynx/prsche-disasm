// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 00538040..00538100 (193B) and 24B .data state block 005de910..005de927.
#include "render_seed_prng_638.hpp"

namespace porsche {

alignas(4) std::uint32_t render_seed_prng_state_005de910[6] = {
    0xf22d0e56u,
    0x883126e9u,
    0xc624dd2fu,
    0x0702c49cu,
    0x9e353f7du,
    0x6fdf3b64u,
};

std::uint32_t __cdecl render_seed_prng_next_00538040() {
    const std::uint32_t s4 = render_seed_prng_state_005de910[4];
    std::uint32_t s5 = render_seed_prng_state_005de910[5];
    std::uint32_t acc = s4 + s5;
    std::uint32_t carry = (acc < s5 || acc < s4) ? 1u : 0u;
    render_seed_prng_state_005de910[4] = acc;

    const std::uint32_t s3 = render_seed_prng_state_005de910[3];
    acc += carry + s3;
    carry = (acc < s3) ? 1u : 0u;
    render_seed_prng_state_005de910[3] = acc;

    const std::uint32_t s2 = render_seed_prng_state_005de910[2];
    acc += carry + s2;
    carry = (acc < s2) ? 1u : 0u;
    render_seed_prng_state_005de910[2] = acc;

    const std::uint32_t s1 = render_seed_prng_state_005de910[1];
    acc += carry + s1;
    carry = (acc < s1) ? 1u : 0u;
    render_seed_prng_state_005de910[1] = acc;

    acc = render_seed_prng_state_005de910[0] + (acc + carry);
    ++s5;
    render_seed_prng_state_005de910[5] = s5;
    render_seed_prng_state_005de910[0] = acc;

    if (s5 == 0u) {
        if (++render_seed_prng_state_005de910[4] == 0u) {
            if (++render_seed_prng_state_005de910[3] == 0u) {
                if (++render_seed_prng_state_005de910[2] == 0u) {
                    if (++render_seed_prng_state_005de910[1] == 0u) {
                        acc = ++render_seed_prng_state_005de910[0];
                    }
                }
            }
        }
    }
    return acc;
}

} // namespace porsche
