#include "format_preferences_579.hpp"

#include <cstddef>

namespace porsche {
static_assert(sizeof(void*) == 4, "original pointer tables require Win32");

// Original writable .data payload 005dedcc..005def97 (460 bytes).
std::uint32_t render_texture_format_preferences_005dedcc[115] = {
    0x00000001u, 0x00000002u, 0x00000007u, 0x00000006u, 0x00000003u, 0x00000004u,
    0x0000000bu, 0x00000005u, 0x00000000u, 0x00000000u, 0x00000002u, 0x00000007u,
    0x00000006u, 0x00000003u, 0x00000004u, 0x0000000bu, 0x00000005u, 0x00000000u,
    0x00000000u, 0x00000003u, 0x00000007u, 0x00000006u, 0x0000000bu, 0x00000004u,
    0x00000005u, 0x00000000u, 0x00000000u, 0x00000004u, 0x0000000bu, 0x00000003u,
    0x00000005u, 0x00000007u, 0x00000006u, 0x00000000u, 0x00000000u, 0x00000005u,
    0x00000004u, 0x0000000bu, 0x00000003u, 0x00000007u, 0x00000006u, 0x00000000u,
    0x00000000u, 0x00000006u, 0x00000007u, 0x00000003u, 0x00000005u, 0x00000004u,
    0x0000000bu, 0x00000000u, 0x00000000u, 0x00000007u, 0x00000006u, 0x00000003u,
    0x00000004u, 0x0000000bu, 0x00000005u, 0x00000000u, 0x00000000u, 0x00000008u,
    0x00000007u, 0x00000006u, 0x00000003u, 0x00000004u, 0x0000000bu, 0x00000005u,
    0x00000000u, 0x00000000u, 0x00000009u, 0x00000007u, 0x00000006u, 0x00000003u,
    0x00000004u, 0x0000000bu, 0x00000005u, 0x00000000u, 0x00000000u, 0x0000000bu,
    0x00000003u, 0x00000004u, 0x00000005u, 0x00000007u, 0x00000006u, 0x00000000u,
    0x00000000u, 0x0000000cu, 0x00000004u, 0x0000000bu, 0x00000003u, 0x00000005u,
    0x00000007u, 0x00000006u, 0x00000000u, 0x00000000u, 0x0000000du, 0x00000007u,
    0x00000006u, 0x00000003u, 0x00000004u, 0x0000000bu, 0x00000005u, 0x00000000u,
    0x00000000u, 0x0000000eu, 0x00000000u, 0x00000000u, 0x0000000fu, 0x00000000u,
    0x00000000u, 0x00000010u, 0x00000000u, 0x00000000u, 0x00000011u, 0x00000000u,
    0x00000000u
};

// Original writable .data payload 005defe0..005df0a7 (200 bytes).
std::uint32_t render_texture_palette_preferences_005defe0[50] = {
    0x00000001u, 0x00000002u, 0x00000006u, 0x00000003u, 0x00000005u, 0x00000004u,
    0x00000000u, 0x00000002u, 0x00000001u, 0x00000006u, 0x00000003u, 0x00000005u,
    0x00000004u, 0x00000000u, 0x00000003u, 0x00000004u, 0x00000002u, 0x00000001u,
    0x00000006u, 0x00000005u, 0x00000000u, 0x00000004u, 0x00000005u, 0x00000006u,
    0x00000003u, 0x00000002u, 0x00000001u, 0x00000000u, 0x00000005u, 0x00000004u,
    0x00000006u, 0x00000002u, 0x00000001u, 0x00000003u, 0x00000000u, 0x00000006u,
    0x00000005u, 0x00000004u, 0x00000001u, 0x00000002u, 0x00000003u, 0x00000000u,
    0x00000008u, 0x00000002u, 0x00000001u, 0x00000006u, 0x00000003u, 0x00000005u,
    0x00000004u, 0x00000000u
};

// Original relocation table 005def98 (18 entries), preserving null entries and target offsets.
std::uint32_t* render_texture_format_preference_table_005def98[18] = {
    &render_texture_empty_format_006a3a28,
    render_texture_format_preferences_005dedcc,
    render_texture_format_preferences_005dedcc+10,
    render_texture_format_preferences_005dedcc+19,
    render_texture_format_preferences_005dedcc+27,
    render_texture_format_preferences_005dedcc+35,
    render_texture_format_preferences_005dedcc+43,
    render_texture_format_preferences_005dedcc+51,
    render_texture_format_preferences_005dedcc+59,
    render_texture_format_preferences_005dedcc+68,
    nullptr,
    render_texture_format_preferences_005dedcc+77,
    render_texture_format_preferences_005dedcc+85,
    render_texture_format_preferences_005dedcc+94,
    render_texture_format_preferences_005dedcc+103,
    render_texture_format_preferences_005dedcc+106,
    render_texture_format_preferences_005dedcc+109,
    render_texture_format_preferences_005dedcc+112
};

// Original relocation table 005df0a8 (9 entries), preserving null entries and target offsets.
std::uint32_t* render_texture_palette_preference_table_005df0a8[9] = {
    &render_texture_empty_palette_006a3a38,
    render_texture_palette_preferences_005defe0,
    render_texture_palette_preferences_005defe0+7,
    render_texture_palette_preferences_005defe0+14,
    render_texture_palette_preferences_005defe0+21,
    render_texture_palette_preferences_005defe0+28,
    render_texture_palette_preferences_005defe0+35,
    nullptr,
    render_texture_palette_preferences_005defe0+42
};

// Original writable first-DWORD field values at 005df15c+20*i; bounded indices 0..17.
std::uint32_t render_texture_format_flags_005df15c[18] = {
    0x00000000u, 0x00000000u, 0x00000000u, 0x00000001u, 0x00000000u, 0x00000000u,
    0x00000008u, 0x00000004u, 0x00000004u, 0x00000008u, 0x00000000u, 0x00000000u,
    0x00000000u, 0x00000004u, 0x00000000u, 0x00000000u, 0x00000004u, 0x00000008u
};

// Original writable first-DWORD field values at 005df0cc+16*i; bounded indices 0..8.
std::uint32_t render_texture_palette_flags_005df0cc[9] = {
    0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u, 0x00000008u, 0x00000004u,
    0x00000001u, 0x00000000u, 0x00000000u
};

std::uint32_t render_texture_empty_format_006a3a28 = 0u;
std::uint32_t render_texture_empty_palette_006a3a38 = 0u;

}
