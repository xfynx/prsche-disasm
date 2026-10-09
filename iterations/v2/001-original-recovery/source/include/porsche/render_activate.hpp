#pragma once
#include "porsche/render_display.hpp"
#include <cstdint>

namespace porsche {
// Porsche.exe SHA256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
// Canonical DWORD at 0x619780: the currently applied display-mode table index.
extern std::uint32_t render_display_mode_index_00619780;

// Exact mode-request consumer at 0x467fc0; explicit object parameter models ECX.
void __cdecl render_display_reconfigure_00467fc0(RenderDisplay* display,
    std::uint32_t width,std::uint32_t height,std::uint32_t mode,
    std::uint32_t transition);

// Typed video-mode boundary reached by 0x467fc0. The result consumer is
// shared with render-window recovery through render_display.hpp's declaration.
std::uint32_t __cdecl render_activate_video_mode_005376c0(
    std::uint32_t width,std::uint32_t height,std::uint32_t mode,
    std::uint32_t transition,std::uint32_t one);
}
