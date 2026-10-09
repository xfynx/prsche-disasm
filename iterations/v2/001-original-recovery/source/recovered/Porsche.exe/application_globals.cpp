#include "porsche/application_main.hpp"
#include "porsche/application_state.hpp"
#include "porsche/render_display.hpp"
#include "porsche/render_mode.hpp"
#include "porsche/render_settings.hpp"
#include "porsche/render_startup.hpp"

#include <stdexcept>
#include <type_traits>

namespace porsche {
static_assert(std::is_trivial<ApplicationStateArena>::value,
    "arena backing must be zero-initialized before reference aliases");
namespace {
std::uint32_t& arena_u32(std::uint32_t va) {
    return application_state_006573e8.word(va);
}
std::int32_t& arena_i32(std::uint32_t va) {
    static_assert(sizeof(std::int32_t) == sizeof(std::uint32_t));
    static_assert(std::is_same<std::make_unsigned<std::int32_t>::type,
        std::uint32_t>::value,
        "the host signed type must be the corresponding unsigned alias");
    return reinterpret_cast<std::int32_t&>(arena_u32(va));
}
std::uint8_t& arena_u8(std::uint32_t va) {
    return application_state_006573e8.byte(va);
}
}

// Generated FE table target aliases. fe_tables.inc retains only extern refs;
// this translation unit is the single canonical owner of their references.
std::uint32_t& global_006573e8 = application_state_006573e8.words_[((0x006573e8u - application_state_base_va) / 4)];
std::uint32_t& global_006573ec = application_state_006573e8.words_[((0x006573ecu - application_state_base_va) / 4)];
std::uint32_t& global_006573f0 = application_state_006573e8.words_[((0x006573f0u - application_state_base_va) / 4)];
std::uint32_t& global_006573f4 = application_state_006573e8.words_[((0x006573f4u - application_state_base_va) / 4)];
std::uint32_t& global_006573f8 = application_state_006573e8.words_[((0x006573f8u - application_state_base_va) / 4)];
std::uint32_t& global_006573fc = application_state_006573e8.words_[((0x006573fcu - application_state_base_va) / 4)];
std::uint32_t& global_00657400 = application_state_006573e8.words_[((0x00657400u - application_state_base_va) / 4)];
std::uint32_t& global_00657404 = application_state_006573e8.words_[((0x00657404u - application_state_base_va) / 4)];
std::uint32_t& global_00657408 = application_state_006573e8.words_[((0x00657408u - application_state_base_va) / 4)];
std::uint32_t& global_0065740c = application_state_006573e8.words_[((0x0065740cu - application_state_base_va) / 4)];
std::uint32_t& global_00657414 = application_state_006573e8.words_[((0x00657414u - application_state_base_va) / 4)];
std::uint32_t& global_00657418 = application_state_006573e8.words_[((0x00657418u - application_state_base_va) / 4)];
std::uint32_t& global_00657420 = application_state_006573e8.words_[((0x00657420u - application_state_base_va) / 4)];
std::uint32_t& global_0065742c = application_state_006573e8.words_[((0x0065742cu - application_state_base_va) / 4)];
std::uint32_t& global_00657430 = application_state_006573e8.words_[((0x00657430u - application_state_base_va) / 4)];
std::uint32_t& global_00657434 = application_state_006573e8.words_[((0x00657434u - application_state_base_va) / 4)];
std::uint32_t& global_00657438 = application_state_006573e8.words_[((0x00657438u - application_state_base_va) / 4)];
std::uint32_t& global_0065743c = application_state_006573e8.words_[((0x0065743cu - application_state_base_va) / 4)];
std::uint32_t& global_00657440 = application_state_006573e8.words_[((0x00657440u - application_state_base_va) / 4)];
std::uint32_t& global_00657494 = application_state_006573e8.words_[((0x00657494u - application_state_base_va) / 4)];
std::uint32_t& global_00657840 = application_state_006573e8.words_[((0x00657840u - application_state_base_va) / 4)];
std::uint32_t& global_00657a24 = application_state_006573e8.words_[((0x00657a24u - application_state_base_va) / 4)];
std::uint32_t& global_00657a28 = application_state_006573e8.words_[((0x00657a28u - application_state_base_va) / 4)];
std::uint32_t& global_00657a2c = application_state_006573e8.words_[((0x00657a2cu - application_state_base_va) / 4)];
std::uint32_t& global_00657a30 = application_state_006573e8.words_[((0x00657a30u - application_state_base_va) / 4)];
std::uint32_t& global_00657a34 = application_state_006573e8.words_[((0x00657a34u - application_state_base_va) / 4)];
std::uint32_t& global_00657c74 = application_state_006573e8.words_[((0x00657c74u - application_state_base_va) / 4)];
std::uint32_t& global_00657c78 = application_state_006573e8.words_[((0x00657c78u - application_state_base_va) / 4)];
std::uint32_t& global_00657c7c = application_state_006573e8.words_[((0x00657c7cu - application_state_base_va) / 4)];
std::uint32_t& global_00657c80 = application_state_006573e8.words_[((0x00657c80u - application_state_base_va) / 4)];
std::uint32_t& global_0065807c = application_state_006573e8.words_[((0x0065807cu - application_state_base_va) / 4)];
std::uint32_t& global_00658080 = application_state_006573e8.words_[((0x00658080u - application_state_base_va) / 4)];
std::uint32_t& global_00658084 = application_state_006573e8.words_[((0x00658084u - application_state_base_va) / 4)];
std::uint32_t& global_00658088 = application_state_006573e8.words_[((0x00658088u - application_state_base_va) / 4)];

// Application-main state shares those same storage locations.
std::uint32_t& global_00657424 = application_state_006573e8.words_[((0x00657424u - application_state_base_va) / 4)];
std::uint32_t& global_00657428 = application_state_006573e8.words_[((0x00657428u - application_state_base_va) / 4)];
std::uint32_t& global_006577d8 = application_state_006573e8.words_[((0x006577d8u - application_state_base_va) / 4)];
std::uint32_t& global_006577dc = application_state_006573e8.words_[((0x006577dcu - application_state_base_va) / 4)];
std::uint32_t& global_00657a60 = application_state_006573e8.words_[((0x00657a60u - application_state_base_va) / 4)];
std::uint8_t& global_00657a64 = arena_u8(0x00657a64u);
std::uint8_t& global_00657e34 = arena_u8(0x00657e34u);
char* global_00657a84 = application_state_006573e8.characters(0x00657a84u);

// Renderer names retain their established API while sharing the arena.
char* render_selector_00657a38 = application_state_006573e8.characters(0x00657a38u);
std::uint32_t& render_width_00657a48 = application_state_006573e8.words_[((0x00657a48u - application_state_base_va) / 4)];
std::uint32_t& render_height_00657a4c = application_state_006573e8.words_[((0x00657a4cu - application_state_base_va) / 4)];
std::uint32_t& render_selected_00657a58 = application_state_006573e8.words_[((0x00657a58u - application_state_base_va) / 4)];
std::uint32_t& render_display_requested_width_00657a48 = application_state_006573e8.words_[((0x00657a48u - application_state_base_va) / 4)];
std::uint32_t& render_display_requested_height_00657a4c = application_state_006573e8.words_[((0x00657a4cu - application_state_base_va) / 4)];
std::uint32_t& render_display_requested_mode_00657a50 = application_state_006573e8.words_[((0x00657a50u - application_state_base_va) / 4)];
std::int32_t& render_mode_setting_00657d5c = arena_i32(0x00657d5cu);
std::int32_t& render_mode_setting_00657d60 = arena_i32(0x00657d60u);
std::int32_t& render_mode_setting_00657d68 = arena_i32(0x00657d68u);
std::int32_t& render_mode_setting_00657d6c = arena_i32(0x00657d6cu);
std::int32_t& render_mode_setting_00657d70 = arena_i32(0x00657d70u);
std::int32_t& render_mode_setting_00657d78 = arena_i32(0x00657d78u);
std::int32_t& render_mode_setting_00657d80 = arena_i32(0x00657d80u);
std::uint32_t& render_settings_value_00657da4 = application_state_006573e8.words_[((0x00657da4u - application_state_base_va) / 4)];

char* application_main_config_string_00657a84() noexcept {
    return application_state_006573e8.characters(0x00657a84u);
}

void __cdecl application_main_fill_fe_arena_0053c290(std::uint32_t target_va,
    std::uint32_t value, std::uint32_t count) {
    if (target_va != application_state_base_va || count != application_state_bytes)
        throw std::out_of_range("0053c290 production adapter supports only proven FE arena span");
    application_state_fill_0053c290(application_state_006573e8,
        target_va, value, count);
}

} // namespace porsche
