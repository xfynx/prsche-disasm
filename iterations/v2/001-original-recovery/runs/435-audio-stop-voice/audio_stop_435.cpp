// Porsche.exe SHA256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Complete 00565d60..00565dc9 (106B), 0058a8b0..0058a907 (88B).
#include "audio_stop_435.hpp"
#include <cstring>

namespace porsche {
std::uint32_t audio_backend_voice_table_006b489c = 0;

std::int32_t __cdecl audio_channel_stop_00565d60(std::uint32_t handle) {
    if (application_audio_device_state_006b48c0[0xdc] == 0) return -10;
    audio_backend_lock_005896d0();
    const std::int32_t channel = audio_backend_find_channel_00589d20(handle);
    if (channel >= 0) {
        std::uint32_t slot = 0xffffffffu;
        while (audio_backend_next_voice_00590340(channel, &slot) != 0) {
            audio_backend_stop_voice_0058a8b0(slot);
        }
    }
    audio_backend_unlock_005896f0();
    return channel;
}

std::int32_t __cdecl audio_backend_stop_voice_0058a8b0(std::uint32_t voice_slot) {
    // x86 shift/sub/LEA: multiplication and table address wrap in 32 bits.
    const std::uint32_t slot_va = audio_backend_voice_table_006b489c + voice_slot * 0xf8u;
    auto* const slot = reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(slot_va));
    std::uint32_t callback_va;
    std::memcpy(&callback_va, slot + 0xc8, 4);
    using Callback = void (__cdecl*)(void*);
    reinterpret_cast<Callback>(static_cast<std::uintptr_t>(callback_va))(slot + 0x2c);
    // Callback may replace flags/table. ESI retains this slot, flags reload here.
    if ((slot[0] & 1u) != 0) {
        const std::uint32_t zero = 0;
        std::memcpy(slot + 0xf4, &zero, 4);
    } else if ((slot[0] & 2u) != 0) {
        audio_backend_voice_release_00597010(slot + 0x64);
    }
    // Release may change flags; this TEST is a second memory read.
    if ((slot[0] & 0x10u) != 0) audio_backend_voice_finalize_00589c00(voice_slot);
    return 0;
}
} // namespace porsche
