// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 0058c1f0..0058ccbe (2,767B, 58 subpixel lerp routines via 005e1e60)
// and 0058ccbf..0058ccef (49B, __cdecl, ret 0).
#include "sprite_sample_823.hpp"

#include <cstring>

namespace porsche {

namespace {

struct SampleWeights {
    std::uint8_t w00;
    std::uint8_t w01;
    std::uint8_t w10;
    std::uint8_t w11;
};

// Exact 64-entry (v_sub * 8 + u_sub) eighths table extracted from Porsche.exe 005e1e60[0..63]
// and 0058c1f0..0058ccbe (preserves original shift-and-add rounding & row-4 aliasing).
static const SampleWeights kBilinearWeights_005e1e60[64] = {
    {8, 0, 0, 0}, {7, 1, 0, 0}, {6, 2, 0, 0}, {5, 3, 0, 0}, {4, 4, 0, 0}, {3, 5, 0, 0}, {2, 6, 0, 0}, {1, 7, 0, 0},
    {7, 0, 1, 0}, {6, 1, 1, 0}, {5, 2, 1, 0}, {4, 3, 1, 0}, {4, 4, 0, 0}, {3, 4, 0, 1}, {2, 5, 0, 1}, {1, 6, 0, 1},
    {6, 0, 2, 0}, {5, 1, 2, 0}, {4, 2, 2, 0}, {4, 2, 1, 1}, {3, 3, 1, 1}, {2, 4, 1, 1}, {2, 4, 0, 2}, {1, 5, 0, 2},
    {5, 0, 3, 0}, {4, 1, 3, 0}, {4, 1, 2, 1}, {3, 2, 2, 1}, {2, 2, 2, 2}, {2, 3, 1, 2}, {1, 4, 1, 2}, {1, 4, 0, 3},
    {4, 0, 4, 0}, {4, 0, 4, 0}, {3, 1, 3, 1}, {2, 2, 2, 2}, {2, 2, 2, 2}, {2, 2, 2, 2}, {1, 3, 1, 3}, {0, 4, 0, 4},
    {3, 0, 5, 0}, {3, 0, 4, 1}, {2, 1, 4, 1}, {2, 1, 3, 2}, {2, 2, 2, 2}, {1, 2, 2, 3}, {1, 2, 1, 4}, {0, 3, 1, 4},
    {2, 0, 6, 0}, {2, 0, 5, 1}, {2, 0, 4, 2}, {1, 1, 4, 2}, {1, 1, 3, 3}, {1, 1, 2, 4}, {0, 2, 2, 4}, {0, 2, 1, 5},
    {1, 0, 7, 0}, {1, 0, 6, 1}, {1, 0, 5, 2}, {1, 0, 4, 3}, {0, 0, 4, 4}, {0, 1, 3, 4}, {0, 1, 2, 5}, {0, 1, 1, 6},
};

std::uint32_t read_u32(const void* p) {
    std::uint32_t value = 0u;
    std::memcpy(&value, p, sizeof(value));
    return value;
}

std::uint32_t scale_eighth(std::uint32_t p, std::uint8_t w) {
    const std::uint32_t h = (p >> 1u) & 0x7f7f7f7fu;
    const std::uint32_t q = (p >> 2u) & 0x3f3f3f3fu;
    const std::uint32_t e = (p >> 3u) & 0x1f1f1f1fu;
    switch (w) {
        case 1u: return e;
        case 2u: return q;
        case 3u: return q + e;
        case 4u: return h;
        case 5u: return h + e;
        case 6u: return h + q;
        case 7u: return p - e;
        case 8u: return p;
        default: return 0u;
    }
}

} // namespace

std::uint32_t __cdecl render_sprite_sample_0058ccbf(
    const void* src, std::int32_t u_fixed, std::int32_t v_fixed, std::int32_t row_bytes) {
    const std::uint32_t u_sub = (static_cast<std::uint32_t>(u_fixed) >> 13u) & 7u;
    const std::uint32_t v_sub = (static_cast<std::uint32_t>(v_fixed) >> 13u) & 7u;
    const SampleWeights& sw = kBilinearWeights_005e1e60[(v_sub << 3u) | u_sub];
    const auto* const base = static_cast<const std::uint8_t*>(src);

    std::uint32_t acc = 0u;
    if (sw.w00 != 0u) {
        acc += scale_eighth(read_u32(base), sw.w00);
    }
    if (sw.w01 != 0u) {
        acc += scale_eighth(read_u32(base + 4), sw.w01);
    }
    if (sw.w10 != 0u) {
        acc += scale_eighth(read_u32(base + row_bytes), sw.w10);
    }
    if (sw.w11 != 0u) {
        acc += scale_eighth(read_u32(base + row_bytes + 4), sw.w11);
    }
    return acc;
}

} // namespace porsche
