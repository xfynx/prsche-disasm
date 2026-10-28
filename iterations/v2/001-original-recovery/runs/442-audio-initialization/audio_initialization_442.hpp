#pragma once
#include "porsche/application_audio_device.hpp"
#include "audio_capabilities_443.hpp"

namespace porsche {
// Three separate original loader-zero bytes, outside the canonical device span.
extern std::uint8_t audio_backend_flag_summary_006b4883;
extern std::uint8_t audio_backend_flag_summary_006b4884;
extern std::uint8_t audio_backend_flag_summary_006b4885;
// OS/CPU algorithm remains an explicit unresolved production boundary.
std::uint32_t __cdecl audio_backend_cpu_features_00597070();
} // namespace porsche
