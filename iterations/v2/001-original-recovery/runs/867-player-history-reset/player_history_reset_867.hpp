#pragma once
#include <cstdint>

namespace porsche {
extern std::uint32_t session_history_enabled_005e67a4;
extern std::uint32_t session_history_players_005e8bd4[9];
extern std::uint32_t session_history_snapshots_005e6df0[4];
extern std::uint32_t session_history_state_005e6658[18];

void __cdecl reset_player_history_0040ab00(void* history);
void __cdecl frame_reset_service_004069e0();
}
