#include "audio_backend_range_761.hpp"
#include "porsche/application_audio_device.hpp"
namespace porsche {
void __cdecl audio_backend_candidate_range_0058a4b0(std::uint32_t candidate, std::uint32_t* first, std::uint32_t* last) {
    const auto& state = application_audio_device_state_006b48c0;
    if ((candidate & 4u) != 0u) {
        *first = 0u;
        *last = state[0x1du];
    } else if ((candidate & 0x10u) != 0u) {
        *first = state[0x1du];
        const auto word = static_cast<std::int16_t>(state[0xe4u]) | static_cast<std::int16_t>(static_cast<std::uint16_t>(state[0xe5u]) << 8u);
        *last = static_cast<std::uint32_t>(static_cast<std::int32_t>(word));
    }
}
}
