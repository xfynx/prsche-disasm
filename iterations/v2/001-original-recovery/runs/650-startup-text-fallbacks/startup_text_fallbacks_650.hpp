// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "porsche/render_mode.hpp"
#include "../596-startup-quality-tier/startup_quality_tier_596.hpp"
#include "../644-render-startup-text-leaves/render_startup_text_leaves_644.hpp"
#include "../647-startup-sequence-text/startup_sequence_text_647.hpp"

namespace porsche {

struct StartupTextFallbackEntry650 {
    std::int16_t size;
    std::int8_t format;
    std::uint8_t mip_enabled;
    std::int8_t slot0_count;
    std::int8_t slot1_count;
};
static_assert(sizeof(StartupTextFallbackEntry650) == 6u);

// 66-byte .data table at original VA 0x005ce658..0x005ce699 (11 x 6-byte entries).
extern StartupTextFallbackEntry650 startup_text_fallback_table_0_005ce658[11];

// 60-byte .data table at original VA 0x005ce69c..0x005ce6d7 (10 x 6-byte entries).
extern StartupTextFallbackEntry650 startup_text_fallback_table_1_005ce69c[10];

// 66-byte .data table at original VA 0x005ce6d8..0x005ce719 (11 x 6-byte entries).
extern StartupTextFallbackEntry650 startup_text_fallback_table_2_005ce6d8[11];

// 72-byte .data table at original VA 0x005ce71c..0x005ce763 (12 x 6-byte entries).
extern StartupTextFallbackEntry650 startup_text_fallback_table_4_005ce71c[12];

// Original entry 0044de50..0044de5f (16 bytes, __cdecl, ret 0).
void __cdecl startup_text_fallback_4_0044de50();

// Original entry 0044de60..0044df02 (163 bytes, __cdecl, ret 0).
void __cdecl startup_text_fallback_apply_0044de60(
    const StartupTextFallbackEntry650* entries,
    std::int32_t count);

// startup_text_fallback_{0..3}_0044df{70,80,90,a0} are declared in
// ../647-startup-sequence-text/startup_sequence_text_647.hpp.

// Original entry 0044dfe0..0044e004 (37 bytes, __cdecl, ret 0).
std::uint32_t* __cdecl startup_text_quality_mask_ptr_0044dfe0(std::uint32_t index);

} // namespace porsche
