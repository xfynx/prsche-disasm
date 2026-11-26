// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
#include "session_input_reset_853.hpp"

#include "../400-frame-loop-clusters/frame_loop_clusters_400.hpp"
#include "../683-input-ff-slot-callers-and-render-leaves/input_ff_render_leaves_683.hpp"
#include "../695-ff-effect-initialize/ff_effect_initialize_695.hpp"
#include "../831-player-service-tables-and-callbacks/player_service_tables_831.hpp"
#include "porsche/startup_service_516950.hpp"

#include <cstring>

namespace porsche {

std::int32_t application_active_player_count_005e8b58 = 0;
void* session_player_extension_slots_005e6774[9] = {};

namespace {

using SlotRelease = void(__thiscall*)(void*, std::uint32_t);

void store_ff_state(std::size_t offset, std::uint32_t value) {
    std::memcpy(frame_control_ff_state_005e9408 + offset, &value, sizeof value);
}

} // namespace

void __cdecl frame_reset_service_004066d0() {
    for (std::int32_t index = 0; index < application_active_player_count_005e8b58; ++index) {
        void* const extension = session_player_extension_slots_005e6774[index];
        if (extension != nullptr) {
            const auto* const vtable = *static_cast<SlotRelease* const*>(extension);
            vtable[1](extension, 1u);
            session_player_extension_slots_005e6774[index] = nullptr;
        }
    }
    startup_service_noop_00516950();
}

void __cdecl frame_reset_service_00412150() {
    std::uint32_t enabled;
    std::memcpy(&enabled, frame_control_ff_state_005e9408 + 0x04, sizeof enabled);
    if (enabled == 0) {
        return;
    }

    std::int32_t slot_index;
    std::memcpy(&slot_index, frame_control_ff_state_005e9408 + 0x08, sizeof slot_index);
    store_ff_state(0x0c, application_player_object_table_005e8b34[0]);
    store_ff_state(0x12c, 1u);
    store_ff_state(0x10, 0u);
    store_ff_state(0x14, 0u);
    input_slot_pause_ff_00533320(slot_index);
}

} // namespace porsche
