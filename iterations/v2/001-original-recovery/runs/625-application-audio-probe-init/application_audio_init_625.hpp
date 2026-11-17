// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "porsche/application_services.hpp"
#include "porsche/application_audio_init.hpp"
#include "porsche/application_audio_device.hpp"
#include "porsche/application_state.hpp"
#include "porsche/file_events.hpp"

namespace porsche {

// Immutable 128-byte .rdata mode table at 005b4ac0..005b4b3f owned by 004a66b0.
extern const std::uint8_t application_audio_mode_data_005b4ac0[0x80];

} // namespace porsche
