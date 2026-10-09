#include "porsche/application_main.hpp"
#include "porsche/application_state.hpp"
#include "porsche/fe_stream.hpp"
#include "porsche/render_display.hpp"
#include "porsche/render_mode.hpp"
#include "porsche/render_settings.hpp"
#include "porsche/render_startup.hpp"
#include "porsche/startup.hpp"

#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <string>
#include <type_traits>

namespace porsche {
#include "Porsche.exe/fe_tables.inc"
std::uint32_t fe_enabled_0065b298{};
char* argv_0065b20c[32]{};
std::uint32_t __cdecl callback_004119e0(std::int32_t) { return 0; }
std::uint32_t __cdecl callback_00411a80(std::int32_t) { return 0; }
std::uint32_t __cdecl callback_00411b40(std::int32_t) { return 0; }
}

namespace {
constexpr std::uint32_t base = porsche::application_state_base_va;
constexpr std::size_t span = porsche::application_state_bytes;
static_assert(sizeof(porsche::ApplicationStateArena) == span);
static_assert(std::is_same<std::make_unsigned<std::int32_t>::type,
    std::uint32_t>::value);

std::string hex(const std::uint8_t* bytes, std::size_t count) {
    constexpr char digits[] = "0123456789abcdef";
    std::string out;
    out.reserve(count * 2);
    for (std::size_t i = 0; i < count; ++i) {
        out += digits[bytes[i] >> 4];
        out += digits[bytes[i] & 0xf];
    }
    return out;
}

}

int main() {
    using namespace porsche;
    auto& arena = application_state_006573e8;
    bool fe_arena_owner = true;
    bool fe_fegame = true;
    bool fe_racetype = true;
    bool main_renderer_aliases = true;
    bool byte_word_views = true;
    bool signed_word_alias = true;
    bool string_views = true;

    global_006573e8 = 0x11223344u;
    fe_arena_owner &= &global_006573e8 == &arena.word(0x006573e8u);
    const auto& racetype = fe_definitions_005d1e40[14];
    const auto& fegame = fe_definitions_005d1e40[45];
    fe_fegame &= fegame.opcode == 48 && fegame.name
        && std::string(fegame.name) == "FEGAME_TYPE" && fegame.target == &global_006573e8;
    fe_racetype &= racetype.opcode == 16 && racetype.name
        && std::string(racetype.name) == "RACE_TYPE" && racetype.target == &global_006573ec;

    global_006573ec = 0x55667788u;
    fe_arena_owner &= arena.word(0x006573ecu) == 0x55667788u;
    global_00657424 = 0x89abcdefu;
    main_renderer_aliases &= arena.word(0x00657424u) == 0x89abcdefu;

    render_width_00657a48 = 1366;
    main_renderer_aliases &= &render_width_00657a48 == &render_display_requested_width_00657a48;
    main_renderer_aliases &= arena.word(0x00657a48u) == 1366;
    render_display_requested_height_00657a4c = 768;
    main_renderer_aliases &= render_height_00657a4c == 768;
    render_display_requested_mode_00657a50 = 3;
    render_selected_00657a58 = 1;
    main_renderer_aliases &= arena.word(0x00657a50u) == 3 && arena.word(0x00657a58u) == 1;

    global_00657a60 = 0x10203040u;
    global_00657a64 = 0x5au;
    byte_word_views &= arena.word(0x00657a60u) == 0x10203040u;
    byte_word_views &= arena.byte(0x00657a64u) == 0x5au;
    global_00657e34 = 0xabu;
    byte_word_views &= arena.byte(0x00657e34u) == 0xabu;

    render_mode_setting_00657d5c = -1234567;
    signed_word_alias &= arena.word(0x00657d5cu) == static_cast<std::uint32_t>(-1234567);
    arena.word(0x00657d60u) = 0xfffffff9u;
    signed_word_alias &= render_mode_setting_00657d60 == -7;
    render_settings_value_00657da4 = 0x76543210u;
    signed_word_alias &= arena.word(0x00657da4u) == 0x76543210u;

    render_selector_00657a38[0] = 'D';
    render_selector_00657a38[1] = '\0';
    global_00657a84[0] = 'N';
    global_00657a84[1] = '\0';
    string_views &= arena.byte(0x00657a38u) == 'D';
    string_views &= application_main_config_string_00657a84() == global_00657a84;

    for (std::size_t i = 0; i < 32; ++i)
        argv_0065b20c[i] = reinterpret_cast<char*>(static_cast<std::uintptr_t>(0x1000u + i));
    const auto argv_before = argv_0065b20c[0];
    const auto argv_last = argv_0065b20c[31];

    application_main_fill_fe_arena_0053c290(base, 0, static_cast<std::uint32_t>(span));
    bool zero = true;
    for (std::size_t i = 0; i < span; ++i) zero &= arena.bytes()[i] == 0;
    bool argv_unchanged = argv_before == argv_0065b20c[0] && argv_last == argv_0065b20c[31];
    bool rejected_unknown_span = false;
    try {
        application_main_fill_fe_arena_0053c290(base + static_cast<std::uint32_t>(span), 0, 4);
    } catch (const std::out_of_range&) {
        rejected_unknown_span = true;
    }
    std::cout << "{\"span_bytes\":" << span
        << ",\"end_exclusive\":\"0065b20c\",\"fe_arena_owner_ok\":" << (fe_arena_owner ? "true" : "false")
        << ",\"fe_fegame_target_ok\":" << (fe_fegame ? "true" : "false")
        << ",\"fe_racetype_target_ok\":" << (fe_racetype ? "true" : "false")
        << ",\"main_renderer_aliases_ok\":" << (main_renderer_aliases ? "true" : "false")
        << ",\"byte_word_views_ok\":" << (byte_word_views ? "true" : "false")
        << ",\"signed_word_alias_ok\":" << (signed_word_alias ? "true" : "false")
        << ",\"string_views_ok\":" << (string_views ? "true" : "false")
        << ",\"zero_after_fill\":" << (zero ? "true" : "false")
        << ",\"argv_fixture_unchanged\":" << (argv_unchanged ? "true" : "false")
        << ",\"unknown_span_rejected\":" << (rejected_unknown_span ? "true" : "false")
        << ",\"arena_hex\":\"" << hex(arena.bytes(), span) << "\"}\n";
    return fe_arena_owner && fe_fegame && fe_racetype && main_renderer_aliases && byte_word_views && signed_word_alias
        && string_views && zero && argv_unchanged && rejected_unknown_span ? 0 : 1;
}
