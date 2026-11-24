// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run799: 0044d7e0..0044d991 (434B), 0044d710..0044d7cf (194B).
#include "scene_texture_descriptor_799.hpp"

#include "porsche/fe_stream.hpp"
#include "porsche/heap.hpp"
#include "render_descriptor.hpp"
#include "scene_sky_texture_791.hpp"
#include "startup_text_fallbacks_650.hpp"

#include <cstring>

namespace porsche {
namespace {

using U = std::uint32_t;
using I = std::int32_t;
using B = std::uint8_t;
using W = std::uint16_t;
using SW = std::int16_t;

SW load16s(const void* base, U offset) {
    SW value = 0;
    std::memcpy(&value, static_cast<const B*>(base) + offset, sizeof(value));
    return value;
}

U load32(const void* base, U offset) {
    U value = 0u;
    std::memcpy(&value, static_cast<const B*>(base) + offset, sizeof(value));
    return value;
}

const void* load_cptr(const void* base, U offset) {
    const void* ptr = nullptr;
    std::memcpy(&ptr, static_cast<const B*>(base) + offset, sizeof(ptr));
    return ptr;
}

void store16(void* base, U offset, W value) {
    std::memcpy(static_cast<B*>(base) + offset, &value, sizeof(value));
}

void store32(void* base, U offset, U value) {
    std::memcpy(static_cast<B*>(base) + offset, &value, sizeof(value));
}

void store_cptr(void* base, U offset, const void* ptr) {
    std::memcpy(static_cast<B*>(base) + offset, &ptr, sizeof(ptr));
}

} // namespace

std::uint32_t scene_texture_format_prefs_0_005ce48c[8] = {
    3u, 11u, 4u, 5u, 7u, 6u, 0u, 0u,
};

std::uint32_t scene_texture_format_prefs_1_005ce4ac[8] = {
    7u, 3u, 5u, 4u, 11u, 6u, 0u, 0u,
};

std::uint32_t scene_texture_format_prefs_2_005ce4cc[8] = {
    3u, 7u, 5u, 4u, 11u, 6u, 0u, 0u,
};

std::uint32_t scene_texture_format_prefs_3_005ce4ec[8] = {
    4u, 11u, 3u, 5u, 7u, 6u, 0u, 0u,
};

std::uint32_t scene_texture_format_prefs_4_005ce50c[8] = {
    6u, 7u, 3u, 5u, 4u, 11u, 0u, 0u,
};

void* __stdcall scene_texture_descriptor_shrink_mip_0044d710(const void* descriptor) {
    I bpp = static_cast<I>(render_descriptor_bits_00537f90(descriptor));
    if (bpp == 15) {
        bpp = 16;
    }

    const I width = static_cast<I>(load16s(descriptor, 0x04u));
    const I height = static_cast<I>(load16s(descriptor, 0x06u));
    const I top_bytes = height * width * (bpp / 8);

    I total_bytes = top_bytes + 0x10;
    I mip_bytes = top_bytes / 4;
    for (U mips = load32(descriptor, 0x0cu) >> 28u; mips != 0u; --mips) {
        total_bytes += mip_bytes;
        mip_bytes /= 4;
    }

    const I alloc_bytes = total_bytes - top_bytes;
    B* const out = static_cast<B*>(allocate_00531ca0("ShrinkMIP", alloc_bytes, 0x10u));
    heap_copy_dispatch_005323e0(out, descriptor, 0x10u);
    heap_copy_dispatch_005323e0(
        out + 0x10u,
        static_cast<const B*>(descriptor) + top_bytes + 0x10,
        static_cast<U>(alloc_bytes - 0x10));

    const U header_word = load32(out, 0x0cu);
    const U updated_word =
        ((header_word & 0xf0000000u) - 1u) ^ ((~header_word) & 0x0fffffffu);
    store32(out, 0x0cu, updated_word);
    store16(out, 0x04u, static_cast<W>(load16s(out, 0x04u) / 2));
    store16(out, 0x06u, static_cast<W>(load16s(out, 0x06u) / 2));
    return out;
}

void* __fastcall scene_texture_descriptor_parse_0044d7e0(
    void* out_desc, void* /*unused_edx*/,
    const void* chunk, std::uint32_t mode, std::uint32_t /*fourcc*/) {
    B* const out = static_cast<B*>(out_desc);
    store_cptr(out, 0x14u, nullptr);
    store_cptr(out, 0x18u, nullptr);
    out[0] = 0u;
    store_cptr(out, 0x0cu, chunk);
    store_cptr(out, 0x10u, chunk);

    const B* const mask_a =
        reinterpret_cast<const B*>(startup_text_quality_mask_ptr_0044dfe0(mode));
    bool allow_alt = true;
    if ((mask_a[2] & 0x20u) != 0u) {
        allow_alt = (load16s(chunk, 0x08u) != 0);
    }

    const B* const mask_b =
        reinterpret_cast<const B*>(startup_text_quality_mask_ptr_0044dfe0(mode));
    if (mask_b[0] == 0x10u) {
        render_texture_format_table_set_00554950(
            4u, scene_texture_format_prefs_0_005ce48c);
        render_texture_format_table_set_00554950(
            6u,
            allow_alt ? scene_texture_format_prefs_1_005ce4ac
                      : scene_texture_format_prefs_2_005ce4cc);
    } else {
        render_texture_format_table_set_00554950(
            4u, scene_texture_format_prefs_3_005ce4ec);
        render_texture_format_table_set_00554950(
            6u, scene_texture_format_prefs_4_005ce50c);
    }

    const B shrink_mask = mask_a[1];
    const SW width = load16s(chunk, 0x04u);
    if (((shrink_mask & 0x01u) != 0u && width == 0x200) ||
        ((shrink_mask & 0x02u) != 0u && width == 0x100) ||
        ((shrink_mask & 0x04u) != 0u && width == 0x80) ||
        ((shrink_mask & 0x08u) != 0u && width == 0x40) ||
        ((shrink_mask & 0x10u) != 0u && width == 0x20)) {
        out[0] = 1u;
        const void* const cur = load_cptr(out, 0x0cu);
        void* const shrunk = ((mask_a[2] & 0x04u) != 0u)
            ? scene_texture_descriptor_shrink_mip_0044d710(cur)
            : scene_texture_descriptor_shrink_005557d0(cur);
        store_cptr(out, 0x18u, shrunk);
        store_cptr(out, 0x0cu, shrunk);
    }

    if ((mask_a[2] & 0x10u) != 0u) {
        out[0] = 1u;
        const void* const cur = load_cptr(out, 0x0cu);
        I bpp = static_cast<I>(render_descriptor_bits_00537f90(cur));
        if (bpp == 15) {
            bpp = 16;
        }
        const I w = static_cast<I>(load16s(cur, 0x04u));
        const I h = static_cast<I>(load16s(cur, 0x06u));
        const I copy_bytes = h * w * (bpp / 8) + 0x14;
        void* const conv = allocate_00531ca0("RTex:SHPconv", copy_bytes * 2, 0x10u);
        store_cptr(out, 0x14u, conv);
        heap_copy_dispatch_005323e0(conv, cur, static_cast<U>(copy_bytes));
        store_cptr(out, 0x0cu, conv);
    }

    store32(out, 0x08u, ((mask_a[2] & 0x04u) != 0u) ? 1u : 0u);
    if ((mask_a[2] & 0x02u) != 0u) {
        const void* const cur = load_cptr(out, 0x0cu);
        I shift_val = static_cast<I>(load16s(cur, 0x04u)) >> 2;
        U shift_count = 0u;
        while (shift_val > 0) {
            shift_val >>= 1;
            ++shift_count;
        }
        store32(out, 0x04u, shift_count);
    } else {
        store32(out, 0x04u, 0u);
    }

    return out_desc;
}

} // namespace porsche
