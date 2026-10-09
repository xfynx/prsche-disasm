#pragma once
#include "porsche/render_activate.hpp"
#include "porsche/window_position.hpp"
#include <cstdint>

namespace porsche {
// Porsche.exe SHA256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
// Full consumer body 0x468030..0x4680c5; explicit object parameter is ECX.
void __cdecl render_display_video_result_00468030(RenderDisplay* display,
    std::uint32_t result);

// Unresolved callees are typed boundaries. 0x44e720 fills the ten-word
// selected-mode record; 0x537600 submits the resulting video dimensions.
void __cdecl render_window_query_mode_info_0044e720(std::uint32_t index,
    std::uint32_t* record10);
void __cdecl render_window_driver_select_mode_vslot7(void* driver,
    std::uint32_t index);
void __cdecl render_window_commit_mode_0044ebf0(std::uint32_t index);
void __cdecl render_window_time_update_0044ed10();
void __cdecl render_window_video_base_00537600(std::uint32_t a,std::uint32_t b,
    std::uint32_t c,std::uint32_t width,std::uint32_t height,std::uint32_t f);
std::int32_t __stdcall render_window_show_cursor(std::int32_t show);
}
