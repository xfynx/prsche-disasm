// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 0058f7a0..0058f7db, 60 bytes. Reuse canonical Run452 state.
#include "audio_resource_slot_718.hpp"
#include <cstring>
namespace porsche {
void* __cdecl audio_group_slot_0058f7a0(std::uint32_t key) {
    const std::uint32_t count = audio_resource_map_count_006b48a0 & 0xffffu;
    const std::uint32_t base = audio_resource_map_006b48a4;
    for (std::uint32_t index = 0; index < count; ++index) {
        const std::uint32_t row = base + index * 8u;
        std::uint32_t value;
        std::memcpy(&value, reinterpret_cast<const void*>(row), 4u);
        if (value == 0u) {
            std::memcpy(reinterpret_cast<void*>(row), &key, 4u);
            return reinterpret_cast<void*>(audio_resource_map_006b48a4 + index * 8u);
        }
    }
    return nullptr;
}
}
