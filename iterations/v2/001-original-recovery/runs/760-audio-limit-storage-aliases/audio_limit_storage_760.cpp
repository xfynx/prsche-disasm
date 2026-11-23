#include "audio_limit_storage_760.hpp"
#include "porsche/application_audio_device.hpp"
namespace porsche {
std::uint8_t& audio_device_voice_limit_006b48dd =
    *reinterpret_cast<std::uint8_t*>(application_audio_device_state_006b48c0.data() + 0x1du);
std::int16_t& audio_device_priority_limit_006b49a4 =
    *reinterpret_cast<std::int16_t*>(application_audio_device_state_006b48c0.data() + 0xe4u);
}



