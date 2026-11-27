// Original 004110a0..00411122 (131 bytes), SHA-256
// 7c5681ee1b73fc014d3de3a57f9ecd146fe0ed9ade126126fa52e5189a72eae2.
#include "frame_reset_service_861.hpp"

#include "porsche/application_state.hpp"
#include "player_service_tables_831.hpp"

namespace porsche {

std::uint32_t frame_reset_order_table_005e8b88[9u] = {};
std::uint32_t frame_reset_pair_table_005e8bac[9u] = {};
std::uint32_t frame_reset_secondary_table_005e8c24[128u] = {};

void __cdecl frame_reset_service_004110a0() {
    // The initial primary count is latched for the complete three-table copy.
    // The original performs no capacity check; callers must preserve the
    // established 0..9 primary domain.
    std::int32_t primary_bound = static_cast<std::int32_t>(
        application_state_006573e8.word(0x00658080u));
    for (std::int32_t index = 0; index < primary_bound; ++index) {
        const std::uint32_t object =
            application_player_object_table_005e8b34[index];
        frame_reset_order_table_005e8b88[index] = object;
        frame_reset_pair_table_005e8bac[index] = object;
    }

    // Unlike the copy, the callback walk reloads its bound after every call.
    // This intentionally permits a callback to shrink or extend the walk.
    for (std::int32_t index = 0; index < primary_bound; ++index) {
        frame_player_reset_00410730(
            application_player_object_table_005e8b34[index], index);
        primary_bound = static_cast<std::int32_t>(
            application_state_006573e8.word(0x00658080u));
    }

    std::int32_t secondary_bound = static_cast<std::int32_t>(
        application_state_006573e8.word(0x0065807cu));
    for (std::int32_t index = 0; index < secondary_bound; ++index) {
        // The first secondary index uses the primary bound retained from the
        // preceding path. Only subsequent iterations reload it at 004110ff.
        if (index != 0) {
            primary_bound = static_cast<std::int32_t>(
                application_state_006573e8.word(0x00658080u));
        }
        frame_player_reset_00410730(
            frame_reset_secondary_table_005e8c24[index],
            primary_bound + index);
        secondary_bound = static_cast<std::int32_t>(
            application_state_006573e8.word(0x0065807cu));
    }
}

} // namespace porsche
