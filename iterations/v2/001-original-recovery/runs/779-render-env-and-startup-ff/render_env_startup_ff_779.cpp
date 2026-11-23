// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 00573030..00573061 (50B) and 004121b0..0041222b (124B).
#include "render_env_startup_ff_779.hpp"

#include <cstring>

namespace porsche {

const char render_environment_fmt_005c0838[6] = "%s=%s";
void* startup_frame_tick_table_00606ad0 = nullptr;

namespace {

std::uint32_t load_state_u32(std::size_t offset) {
    std::uint32_t value = 0u;
    std::memcpy(&value, frame_control_ff_state_005e9408 + offset, sizeof value);
    return value;
}

void store_state_u32(std::size_t offset, std::uint32_t value) {
    std::memcpy(frame_control_ff_state_005e9408 + offset, &value, sizeof value);
}

} // namespace

std::uint32_t __cdecl render_environment_00573030(
    const char* name, const char* value, std::uint32_t ignored) {
    (void)ignored;
    char entry[0x200];
    formatter_entry_005a0fbf(entry, render_environment_fmt_005c0838, name, value);
    (void)crt_putenv_005a38c7(entry);
    return 0u;
}

void __cdecl startup_sequence_call_004121b0() {
    ff_effect_initialize_00411d20();
    if (load_state_u32(0x04u) == 0u) {
        return;
    }
    if (static_cast<std::int32_t>(global_00657424) >= 2) {
        return;
    }
    const std::uint32_t player = application_player_object_table_005e8b34[0];
    store_state_u32(0x0cu, player);
    store_state_u32(0x12cu, 1u);
    store_state_u32(0x10u, 0u);
    store_state_u32(0x14u, 0u);
    startup_sorted_table_insert_00414c30(
        startup_frame_tick_table_00606ad0,
        static_cast<std::uint32_t>(
            reinterpret_cast<std::uintptr_t>(&ff_effect_frame_tick_004123e0)),
        player,
        10);
    if (load_state_u32(0x04u) == 0u) {
        input_slot_stop_ff_00533480(static_cast<std::int32_t>(load_state_u32(0x08u)));
        store_state_u32(0x128u, 0u);
        store_state_u32(0x130u, 0u);
        store_state_u32(0x124u, 0u);
    }
}

} // namespace porsche
