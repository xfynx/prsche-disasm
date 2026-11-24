// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run791: 0044da10..0044db1f (272B), 00536460..0053646a (11B),
//         00554950..0055495f (16B), 00555630..00555630 (1B).
#include "scene_sky_texture_791.hpp"

#include "format_preferences_579.hpp"
#include "porsche/application_alloc.hpp"
#include "porsche/fe_stream.hpp"
#include "porsche/render_mode.hpp"
#include "render_resource_533.hpp"
#include "startup_text_fallbacks_650.hpp"

#include <cstring>

namespace porsche {
namespace {

using U = std::uint32_t;
using B = std::uint8_t;

constexpr U kCar0Base = 0x30524143u; // "CAR0"

U load32(const void* base, U offset) {
    U value = 0u;
    std::memcpy(&value, static_cast<const B*>(base) + offset, sizeof(value));
    return value;
}

void* load_ptr(const void* base, U offset) {
    void* ptr = nullptr;
    std::memcpy(&ptr, static_cast<const B*>(base) + offset, sizeof(ptr));
    return ptr;
}

struct ParsedTextureDesc {
    U word_00;
    U extra_flags_04;
    U word_08;
    const void* descriptor_0c;
    U word_10;
    void* buffer_14;
    void* buffer_18;
    U word_1c;
};

} // namespace

std::uint32_t scene_sky_format_prefs_a_005ce52c[8] = {
    4u, 11u, 3u, 5u, 7u, 6u, 0u, 0u,
};

std::uint32_t scene_sky_format_prefs_b_005ce54c[8] = {
    6u, 7u, 3u, 5u, 4u, 11u, 0u, 0u,
};

void __cdecl render_texture_noop_00555630(std::uint32_t /*value*/) {
}

void __fastcall render_resource_node_prepare_00536460(void* self, void* /*unused_edx*/) {
    render_texture_noop_00555630(load32(self, 0x08u));
}

void __cdecl render_texture_format_table_set_00554950(
    std::uint32_t slot, std::uint32_t* table) {
    render_texture_format_preference_table_005def98[slot] = table;
}

void* __cdecl scene_sky_texture_create_0044da10(
    const void* chunk, std::uint32_t tag, std::uint32_t mode,
    void* driver, std::uint32_t flags) {
    const U mode_flags = (render_mode_state_00619790[0x18u] != 0u)
        ? flags
        : 0u;
    const U* const quality_mask_ptr = startup_text_quality_mask_ptr_0044dfe0(mode);

    const U fourcc = (tag < 0x20u)
        ? ((tag << 24u) + kCar0Base)
        : tag;

    ParsedTextureDesc parsed{};
    (void)scene_texture_descriptor_parse_0044d7e0(
        &parsed, nullptr, chunk, mode, fourcc);

    char name_buf[16]{};
    std::memcpy(name_buf, &fourcc, sizeof(fourcc));
    name_buf[4] = '\0';
    std::strcat(name_buf, "      ");

    const U extra_flags = (render_mode_state_00619790[0x1eu] != 0u)
        ? parsed.extra_flags_04
        : 0u;

    void* node = startup_network_allocate_0059ef90(0x54u);
    if (node != nullptr) {
        node = render_resource_node_ctor_00535bc0(
            node, nullptr, parsed.descriptor_0c,
            driver, extra_flags | mode_flags, name_buf);
    }

    if ((static_cast<B>((*quality_mask_ptr >> 16u) & 0xffu) & 0x08u) != 0u) {
        render_resource_node_prepare_00536460(node, nullptr);
    }

    if (parsed.buffer_14 != nullptr) {
        (void)free_00531f90(parsed.buffer_14);
    }
    if (parsed.buffer_18 != nullptr) {
        (void)free_00531f90(parsed.buffer_18);
    }

    render_texture_format_table_set_00554950(4u, scene_sky_format_prefs_a_005ce52c);
    render_texture_format_table_set_00554950(6u, scene_sky_format_prefs_b_005ce54c);
    return node;
}

} // namespace porsche
