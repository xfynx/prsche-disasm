#include "sky_texture_reload_880.hpp"
#include "porsche/fe_stream.hpp"
#include "porsche/render_display.hpp"
#include "render_resource_node_536.hpp"
#include "scene_sky_texture_791.hpp"
#include <cstring>

namespace porsche {
namespace {
using Byte = unsigned char;
using Word = std::uint32_t;

struct ParsedTexture {
    Byte prefix[12];
    const void* descriptor;
    Word original;
    void* conversion;
    void* mip;
};
static_assert(sizeof(ParsedTexture) == 0x1c);

template<typename T> T read(const void* base, unsigned offset) {
    T result;
    std::memcpy(&result, static_cast<const Byte*>(base) + offset, sizeof(result));
    return result;
}
template<typename T> void write(void* base, unsigned offset, T value) {
    std::memcpy(static_cast<Byte*>(base) + offset, &value, sizeof(value));
}
}

void __fastcall render_resource_reload_00536510(void* node, void*, const void* descriptor) {
    auto* data = static_cast<const Byte*>(descriptor);
    write(node, 0x14, render_resource_node_format_00556690(data));
    auto* palette = static_cast<Byte*>(render_resource_node_palette_00537fb0(data));
    const Word palette_format = palette ? render_resource_node_format_00556690(palette) : 0;
    write(node, 0x18, palette_format);

    const Word width = static_cast<Word>(read<std::int16_t>(data, 4));
    const Word height = static_cast<Word>(read<std::int16_t>(data, 6));
    write(node, 0x0c, width);
    write(node, 0x10, height);
    if (!read<void*>(node, 8)) {
        auto* name = reinterpret_cast<const char*>(static_cast<Byte*>(node) + 0x24);
        void* texture = render_display_texture_alloc_00554960(
            width, height, read<Word>(node, 0x14), palette_format, read<Word>(node, 0x1c), name);
        write(node, 8, texture);
    }
    render_display_texture_copy_00554d70(read<void*>(node, 8),
        const_cast<Byte*>(data + 0x10), palette ? reinterpret_cast<Word>(palette + 0x10) : 0);
}

void __cdecl scene_sky_texture_update_0044d9a0(
        void* node, const void* chunk, Word tag, Word mode) {
    ParsedTexture parsed;
    scene_texture_descriptor_parse_0044d7e0(&parsed, nullptr, chunk, mode, tag);
    render_resource_reload_00536510(node, nullptr, parsed.descriptor);
    if (parsed.conversion) free_00531f90(parsed.conversion);
    if (parsed.mip) free_00531f90(parsed.mip);
    render_texture_format_table_set_00554950(4, scene_sky_format_prefs_a_005ce52c);
    render_texture_format_table_set_00554950(6, scene_sky_format_prefs_b_005ce54c);
}
}
