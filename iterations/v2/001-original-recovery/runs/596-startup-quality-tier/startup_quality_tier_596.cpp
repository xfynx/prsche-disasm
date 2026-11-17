// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 0044dfb0..0044dfd2, 35 bytes, sha256 d522b7537756b3933f2ae53933abf93ee439e98952c830423ba32a15ffc82628.
// Original 0044e370..0044e405, 150 bytes, sha256 f4fee5f73afda6f1ff395d60f11e1e3bcd6a3ec1c127761bf639debafdf5ec50.
#include "startup_quality_tier_596.hpp"
#include <cstdint>
#include <cstring>

namespace porsche {

std::uint32_t render_quality_selected_00619770 = 0u;

std::int32_t __cdecl render_quality_tier_0044e370() {
    const std::int32_t time_val = static_cast<std::int32_t>(render_mode_time_value_005ce908);
    const std::int32_t edi = time_val / 1000000;

    std::uint32_t state0 = 0u;
    std::memcpy(&state0, render_mode_state_00619790, sizeof state0);
    const std::int32_t esi = static_cast<std::int32_t>(state0 >> 20u);

    const std::int32_t phys = static_cast<std::int32_t>(render_resource_total_phys_0053c3d0());
    const std::int32_t mb = (phys / 1024) / 1024;

    if (esi < 3 || mb < 0x21 || edi < 0xeb) {
        return 0;
    }
    if (esi < 9 || mb < 0x41) {
        return 1;
    }
    if (esi < 14 || mb < 0x55 || edi < 0x1c2 || render_display_actual_mode_0061978c <= 0x10u) {
        return 2;
    }
    return 3;
}

void __cdecl startup_sequence_call_0044dfb0() {
    std::uint32_t tier = static_cast<std::uint32_t>(render_quality_tier_0044e370());
    application_state_006573e8.word(0x00657d88u) = tier;
    if (tier == 3u && render_display_actual_mode_0061978c < 0x20u) {
        tier = 2u;
    }
    render_quality_selected_00619770 = tier;
}

} // namespace porsche
