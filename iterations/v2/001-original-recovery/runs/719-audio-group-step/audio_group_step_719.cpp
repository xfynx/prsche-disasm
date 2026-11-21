// Original Porsche.exe SHA256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Complete233B0058a970..0058aa58. Canonical application audio device storage.
#include "audio_group_step_719.hpp"
namespace porsche {
std::uint32_t __cdecl audio_group_step_0058a970(std::uint32_t* out, const void* record) {
    using U = std::uint32_t;
    using I = std::int32_t;
    const U count = application_audio_device_state_006b48c0[0x27u];
    if (static_cast<I>(*out) >= static_cast<I>(count)) return 0u;
    const auto* bytes = static_cast<const std::uint8_t*>(record);
    const U mask = bytes[0x18u];
    const U low_mask = mask & 0x1cu;
    do {
        const U index = *out;
        const U address = reinterpret_cast<U>(application_audio_device_state_006b48c0.data()) + 0x28u + index;
        const U sample = *reinterpret_cast<const std::uint8_t*>(address);
        const U low = sample & 0x1cu;
        U result = low_mask == 0u ? low : mask & low;
        bool valid = low_mask == 0u || result != 0u;
        if (valid) {
            const U high = sample & 0xe0u;
            const U high_result = (mask & 0xe0u) == 0u ? high : mask & high;
            result |= high_result;
            valid = (mask & 0xe0u) == 0u || high_result != 0u;
        }
        if (valid && (low & 0x10u) != 0u) {
            const U subtype = sample & 0x3u;
            const U subtype_result = (mask & 0x3u) == 0u ? subtype : mask & subtype;
            result |= subtype_result;
            valid = (mask & 0x3u) == 0u || subtype_result != 0u;
        }
        if (valid && bytes[3u] != 1u && (result & 0xc0u) != 0u) valid = false;
        *out = index + 1u;
        if (valid && result != 0u) return result;
    } while (static_cast<I>(*out) < static_cast<I>(count));
    return 0u;
}
}
