// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#include "render_driver_state_581.hpp"
#include "porsche/game_setup.hpp"
#include "porsche/render_settings.hpp"
#include "porsche/startup_service_516950.hpp"
#include "render_buffer_523.hpp"
#include <cstdint>
#include <cstring>

namespace porsche {
using U = std::uint32_t;
using B = std::uint8_t;

U render_driver_state_pairs_005ded30[12] = {
    6, 1, 10, 2, 56, 0, 2, 0, 24, 0, 0, 0
};
using Callback = void (__cdecl *)(U, U);
Callback render_driver_state_callbacks_005ded60[6] = {
    &render_driver_commit_state_005405c0,
    // Original callback target is 00540480 (cdecl2); callback dispatch ignores
    // EAX, so its U return is transported through the matching x86 call ABI.
    reinterpret_cast<Callback>(&render_buffer_state_00540480),
    &render_driver_select_state_00540550,
    &render_driver_set_movie_state_00540590,
    &render_driver_x87_handler_00540500,
    reinterpret_cast<Callback>(&startup_service_noop_00516950)
};
static_assert(sizeof(void*) == 4, "original callback table is x86");

namespace {
U read_word(const void* p, U offset) {
    U value;
    std::memcpy(&value, static_cast<const B*>(p) + offset, sizeof value);
    return value;
}
void write_word(void* p, U offset, U value) {
    std::memcpy(static_cast<B*>(p) + offset, &value, sizeof value);
}
}

void __fastcall render_driver_apply_states_00538af0(void*, void*) {
    // Original cdecl body has no stack arguments and never reads ECX or EDX.
    // Volatile loads preserve the original reread of each mutable pair/table
    // slot after any callback has changed later entries.
    volatile U* const pairs = render_driver_state_pairs_005ded30;
    Callback volatile* const callbacks = render_driver_state_callbacks_005ded60;
    for (U i = 0; i != 6; ++i) {
        const U value = pairs[i * 2 + 1];
        const U key = pairs[i * 2];
        Callback const callback = callbacks[i];
        callback(key, value);
    }
}

void __cdecl render_display_finish_driver_00537850(void* self, U value) {
    render_display_finish_driver_core_00537850(self, nullptr, value);
}

void __fastcall render_display_finish_driver_core_00537850(void* self,
                                                            void*, U value) {
    write_word(self, 8, value);
    (void)render_buffer_state_00540480(4, value);
}

void __cdecl render_driver_commit_state_005405c0(U key, U value) {
    const U previous = render_settings_get_state_006bd984(key);
    const U result = render_buffer_state_00540480(key, value);
    if (result == 0) {
        (void)render_buffer_state_00540480(key, previous);
        render_driver_state_pairs_005ded30[1] = previous;
    }
}

void __cdecl render_driver_select_state_00540550(U key, U value) {
    if (value == 0xffffffffu) {
        (void)render_buffer_state_00540480(0x194, 7);
        (void)render_buffer_state_00540480(0x195, 6);
    } else {
        (void)render_buffer_state_00540480(key, value);
    }
}

void __cdecl render_driver_set_movie_state_00540590(U, U enabled) {
    U value = 0;
    if (enabled == 1) {
        // Original chain: [[[0069ed0c]+0]+4]+0x10.
        const void* level1 = game_setup_movie_service_0069ed0c;
        const U level2_address = read_word(level1, 0);
        const void* level2 = reinterpret_cast<const void*>(level2_address);
        const U level3_address = read_word(level2, 4);
        const void* level3 = reinterpret_cast<const void*>(level3_address);
        value = read_word(level3, 0x10);
    }
    (void)render_buffer_state_00540480(2, value);
}
}
