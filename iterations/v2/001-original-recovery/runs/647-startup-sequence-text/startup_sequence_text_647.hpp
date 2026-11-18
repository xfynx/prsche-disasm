// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "porsche/application_state.hpp"
#include "porsche/fe_stream.hpp"
#include "porsche/formatter_entry.hpp"
#include "porsche/install_paths.hpp"
#include "porsche/render_mode.hpp"
#include "porsche/startup_sequence.hpp"
#include "../313-pr9-resource-open/resource_open_313.hpp"
#include "../499-rooted-file-exists/rooted_file_exists_499.hpp"
#include "../596-startup-quality-tier/startup_quality_tier_596.hpp"
#include "../644-render-startup-text-leaves/render_startup_text_leaves_644.hpp"

namespace porsche {

struct StartupTextSlotEntry647 {
    std::uint32_t size;
    std::int8_t format;
    std::uint8_t mip_enabled;
    std::uint8_t pad[2];
    std::uint32_t counts[7];
};
static_assert(sizeof(StartupTextSlotEntry647) == 36u);

// 96-byte .data table at original VA 0x005ce59c..0x005ce5fb (4 tiers x 6 entries).
extern std::uint32_t startup_text_quality_masks_005ce59c[24];

// 396-byte .data table at original VA 0x005ce768..0x005ce8f3 (11 x 36-byte entries).
// Note: 0x005ce770 = [0].counts[0], 0x005ce7b8 = [2].counts[0],
// 0x005ce8bc = [9].counts[2], 0x005ce8c0 = [9].counts[3].
extern StartupTextSlotEntry647 startup_text_slots_005ce768[11];

// 9-byte .data format string at original VA 0x005ce8f4..0x005ce8fc ("%s%s.dtx\0").
extern char startup_text_dtx_fmt_005ce8f4[9];

// Original entry 0044e010..0044e276 (615 bytes, __cdecl, ret 0).
// Returns bool (AL = 0 or 1). Reads 0x0065b2b8 and 0x00657444 (ignores text_va).
bool __cdecl startup_text_load_0044e010(std::uint32_t text_va);

// Unrecovered fallback targets referenced by 0044df10's local jump table.
void __cdecl startup_text_fallback_0_0044df70();
void __cdecl startup_text_fallback_1_0044df80();
void __cdecl startup_text_fallback_2_0044df90();
void __cdecl startup_text_fallback_3_0044dfa0();

} // namespace porsche
