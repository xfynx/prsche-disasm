#pragma once

#include <cstdint>
#include "porsche/startup_sequence.hpp"
#include "porsche/render_mode.hpp"
#include "porsche/application_state.hpp"
#include "../494-render-resource-leaves/render_resource_494.hpp"

namespace porsche {

// Loader-zero .data DWORD at original VA 0x00619770.
extern std::uint32_t render_quality_selected_00619770;

// Original entry 0044e370..0044e405 (150 bytes).
std::int32_t __cdecl render_quality_tier_0044e370();

} // namespace porsche
