// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#include "player_history_reset_867.hpp"
#include "../831-player-service-tables-and-callbacks/player_service_tables_831.hpp"
#include "../853-session-input-reset/session_input_reset_853.hpp"
#include "porsche/application_services_next.hpp"
#include "porsche/application_state.hpp"
#include "porsche/startup_service_516950.hpp"
#include <algorithm>
#include <cstring>

namespace porsche {
std::uint32_t session_history_enabled_005e67a4 = 0;
std::uint32_t session_history_players_005e8bd4[9] = {};
std::uint32_t session_history_snapshots_005e6df0[4] = {};
std::uint32_t session_history_state_005e6658[18] = {};

void __cdecl reset_player_history_0040ab00(void* history) {
    auto* bytes = static_cast<unsigned char*>(history);
    const std::uint32_t seven = 7, one = 1, zero = 0;
    std::memcpy(bytes + 8, &seven, 4);
    std::memcpy(bytes, &seven, 4);
    std::memcpy(bytes + 0x14, &one, 4);
    std::memset(bytes + 0x20, 0xff, 7 * 4);
    std::memcpy(bytes + 0x3c, &zero, 4);
}

void __cdecl frame_reset_service_004069e0() {
    session_history_enabled_005e67a4 = application_state_006573e8.word(0x006573ec) != 3;
    for (std::int32_t index = 0; index < application_active_player_count_005e8b58; ++index) {
        const auto player = application_player_object_table_005e8b34[index];
        reset_player_history_0040ab00(reinterpret_cast<void*>(player + 0xe3c));
    }
    const auto route = application_audio_source_storage_005e8bfc[1];
    session_history_snapshots_005e6df0[1] = route;
    session_history_snapshots_005e6df0[0] = route;
    const auto player = session_history_players_005e8bd4[0];
    session_history_snapshots_005e6df0[3] = player;
    session_history_snapshots_005e6df0[2] = player;
    startup_service_noop_00516950();
    std::fill_n(session_history_state_005e6658, 16, 0u);
    session_history_state_005e6658[17] = 0;
}
} // namespace porsche
