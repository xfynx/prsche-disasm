#include "audio_backend_range_755.hpp"

namespace porsche {
extern std::uint8_t audio_device_voice_limit_006b48dd;
extern std::int16_t audio_device_priority_limit_006b49a4;

void __cdecl audio_backend_candidate_range_0058a4b0(std::uint32_t candidate,
                                                    std::uint32_t* first,
                                                    std::uint32_t* last) {
    if ((candidate & 4u) != 0u) {
        *first = 0u;
        *last = audio_device_voice_limit_006b48dd;
    } else if ((candidate & 0x10u) != 0u) {
        *first = audio_device_voice_limit_006b48dd;
        *last = static_cast<std::uint32_t>(static_cast<std::int32_t>(audio_device_priority_limit_006b49a4));
    }
}
}
