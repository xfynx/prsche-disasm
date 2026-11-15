#include "texture_children_577.hpp"
#include "render_texture_transfer_577.hpp"
#include "../546-render-resource-allocation/render_resource_allocation_546.hpp"
#include "porsche/heap.hpp"
#include "porsche/render_loader.hpp"

namespace porsche {
// The initialized PE slot contains the VA of 00554310; this relocation is the
// corresponding host callable. The actual comparator remains a link frontier.
TextureCompare577 render_texture_comparator_005df2c8 = render_texture_compare_00554310;
static const std::uint32_t* words(std::uint32_t address) {
    return reinterpret_cast<const std::uint32_t*>(address);
}

std::int32_t __cdecl render_texture_select_00554820(std::uint32_t* format, std::uint32_t* palette) {
    std::int32_t selected = 0, best = 10000;
    std::uint32_t selected_palette = 0;
    if (!format || !*format) return 0;
    const std::uint32_t requested = *format;
    if (!render_texture_driver_info_006a3a54)
        render_texture_driver_info_006a3a54 = render_loader_about_006bd934(render_thrash_exports_006bd910[9]);
    const std::uint32_t* info = render_texture_driver_info_006a3a54;
    if (info[12]) {
        for (std::int32_t type = 1; type < static_cast<std::int32_t>(info[11] + 1u); ++type) {
            if (words(info[12])[type]) {
                const bool indexed = type == 1 || type == 2 || type == 9;
                const std::int32_t limit = indexed ? static_cast<std::int32_t>(info[13] + 1u) : 1;
                for (std::int32_t pal = indexed ? 1 : 0; pal < limit; ++pal) {
                    if (!pal || words(info[14])[pal]) {
                        const std::int32_t score = render_texture_comparator_005df2c8(requested, palette ? *palette : 0, type, pal);
                        if (score < best) { best = score; selected = type; selected_palette = pal; }
                        info = render_texture_driver_info_006a3a54;
                    }
                }
            }
        }
    }
    *format = selected;
    if (palette) *palette = selected_palette;
    return selected;
}

void __cdecl render_texture_expand_00555780(std::uint32_t dst, std::uint32_t src, std::int32_t bytes) {
    const std::int32_t count = bytes >> 1;
    auto* out = reinterpret_cast<std::uint16_t*>(dst);
    const auto* in = reinterpret_cast<const std::uint8_t*>(src);
    for (std::int32_t i = 0; i < count; ++i) {
        const std::uint16_t byte = in[i], nibble = byte & 15u;
        out[i] = static_cast<std::uint16_t>(((byte << 4) | nibble) << 4 | nibble);
    }
}

void __cdecl render_texture_convert_005556b0(std::uint32_t a, std::uint32_t b, std::uint32_t c, std::uint32_t d,
                                            std::uint32_t src, std::uint32_t dst, std::uint32_t srcpal, std::uint32_t dstpal, std::uint32_t bytes) {
    a &= 0xfffff0ffu; b &= 0xfffff0ffu; c &= 0xfffff0ffu; d &= 0xfffff0ffu;
    const std::int32_t pixels = static_cast<std::int32_t>(bytes * 8u) / static_cast<std::int32_t>(render_texture_format_bits_005df16c[c]);
    if (render_texture_depth_convert_005350e0(a,b,c,d,src,dst,srcpal,dstpal,pixels)) return;
    if (a == 8 && c == 7) {
        render_texture_expand_00555780(dst, src, static_cast<std::int32_t>(bytes));
    } else if (a == c && b == d) {
        heap_copy_dispatch_005323e0(reinterpret_cast<void*>(dst), reinterpret_cast<const void*>(src), bytes);
        if (srcpal && dstpal)
            heap_copy_dispatch_005323e0(reinterpret_cast<void*>(dstpal), reinterpret_cast<const void*>(srcpal), 0x400);
    }
}
}
