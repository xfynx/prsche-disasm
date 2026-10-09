#pragma once
#include "porsche/render_display.hpp"
#include <cstdint>

namespace porsche {
// Porsche.exe SHA256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
// Original entries 0x44e720, 0x44ebf0 and 0x44ed10.
struct RenderModeRecord10 { std::uint32_t words[10]; };

// Canonical state storage for the contiguous original byte range 0x619790..0x619800.
extern std::uint8_t render_mode_state_00619790[0x71];
// Original settings/data globals, each defined once by this owner.
extern std::int32_t& render_mode_setting_00657d5c;
extern std::int32_t& render_mode_setting_00657d60;
extern std::int32_t& render_mode_setting_00657d68;
extern std::int32_t& render_mode_setting_00657d6c;
extern std::int32_t& render_mode_setting_00657d70;
extern std::int32_t& render_mode_setting_00657d78;
extern std::int32_t& render_mode_setting_00657d80;
extern std::uint32_t render_mode_time_value_005ce908;
extern std::uint8_t render_mode_option_0069dd1d;

// cdecl (index, ten-DWORD output); only words written by the original are changed.
void __cdecl render_mode_query_0044e720(std::uint32_t index,
    std::uint32_t* record10);
// cdecl(index), commits canonical VA 0x619780/84/88/8c and invokes 0x44e890.
void __cdecl render_mode_commit_0044ebf0(std::uint32_t index);
// cdecl(), updates the renderer state block at 0x619790.
void __cdecl render_mode_update_state_0044ed10();
void __cdecl render_mode_set_option_00535b40(std::uint32_t value);

// Explicit unresolved edges retained from the original call graph.
void __cdecl render_mode_driver_prepare_vslot9(void* driver);
void __cdecl render_mode_apply_settings_0044e890();
void __cdecl render_mode_update_alternate_0044f020();
std::uint32_t __cdecl render_mode_clock_00555bc0();
void __stdcall render_mode_setstate_iat_006bd918(std::uint32_t key,
    std::uint32_t value);
}
