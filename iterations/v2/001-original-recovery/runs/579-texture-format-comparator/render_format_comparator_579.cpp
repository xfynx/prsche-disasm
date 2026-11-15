// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original00554310/529B and00554530/38B. Domain and data witnesses in PLAN.md.
#include "render_format_comparator_579.hpp"
#include "format_preferences_579.hpp"
#include "../577-render-texture-transfer/render_texture_transfer_577.hpp"
#include "porsche/render_settings.hpp"
#include <cstring>
#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Original x86 pointer and call semantics required.
#endif

namespace porsche {
namespace {
using U = std::uint32_t;
using I = std::int32_t;

bool indexed(U format) {
    return format == 1 || format == 2 || format == 9;
}

U load(U address) {
    U value;
    std::memcpy(&value, reinterpret_cast<const void*>(address), sizeof value);
    return value;
}

U capability(U offset, U format) {
    const U info = reinterpret_cast<U>(render_texture_driver_info_006a3a54);
    return load(load(info + offset) + format * 4u);
}

U preference_score(U* preferences, U wanted) {
    U score = 0;
    bool found = false;
    if (preferences) {
        for (U rank = 0; preferences[rank] != 0; ++rank) {
            if (preferences[rank] == wanted) {
                found = true;
                score += rank;
            }
        }
    }
    return found ? score : score + 20u;
}
}

U __cdecl render_texture_state_probe_00554530() {
    const U previous = render_settings_get_state_006bd984(10);
    const U result = render_settings_set_state_006bd97c(10, 1);
    (void)render_settings_set_state_006bd97c(10, previous);
    return result;
}

I __cdecl render_texture_compare_00554310(U source, U source_palette,
                                         U destination, U destination_palette) {
    const U input = source & 0xfffff0ffu;
    const U input_palette = source_palette & 0xfffff0ffu;
    destination &= 0xfffff0ffu;
    destination_palette &= 0xfffff0ffu;
    const bool source_indexed = indexed(input);
    const bool destination_indexed = indexed(destination);
    if (source_indexed) {
        if (input_palette == 0 || (destination_indexed && destination_palette == 0))
            return 10000;
    } else if (destination_indexed) {
        return 10000;
    }

    (void)render_texture_state_probe_00554530();
    U score = preference_score(render_texture_format_preference_table_005def98[input], destination);
    if (render_texture_format_flags_005df15c[input] != 0 && (source & 0x100u) == 0 &&
        (render_texture_format_flags_005df15c[destination] == 0 || (capability(0x30, destination) & 4u) == 4u)) {
        score += 20;
    }
    if ((capability(0x30, destination) & 1u) != 1u)
        score += 20;
    if (source_indexed && !destination_indexed)
        return static_cast<I>(score + 10u);
    if (!source_indexed && !destination_indexed)
        return static_cast<I>(score);

    score += preference_score(render_texture_palette_preference_table_005df0a8[input_palette], destination_palette);
    if (render_texture_palette_flags_005df0cc[input_palette] != 0 && (source_palette & 0x100u) == 0 &&
        (render_texture_palette_flags_005df0cc[destination_palette] == 0 || (capability(0x38, destination_palette) & 4u) == 4u)) {
        score += 20;
    }
    if ((capability(0x38, destination_palette) & 1u) != 1u)
        score += 20;
    return static_cast<I>(score);
}
}
