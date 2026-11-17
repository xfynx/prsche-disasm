// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "porsche/files.hpp"
#include "porsche/render_loader.hpp"
#include "porsche/window_scheduler.hpp"
#include "diagnostic_mono.hpp"
#include "render_diagnostic_549.hpp"
#include "porsche/render_window.hpp"
#include "porsche/render_display.hpp"
#include "porsche/heap.hpp"
#include "porsche/file_wait.hpp"
#include "porsche/application_instance.hpp"
#include "porsche/exit_shutdown.hpp"

namespace porsche {

// Owned by texture_constructor.cpp (0x005deb80); declared here without including texture_constructor.hpp.
extern std::uint32_t texture_create_errors_005deb80;

// Loader-zero .data globals owned by 00565340 (24 bytes total).
extern std::uint32_t diagnostic_abort_active_006a5c24;
extern std::uint32_t diagnostic_abort_finish_005deb6c;
extern std::uint32_t diagnostic_abort_has_location_005deb84;
extern std::uint32_t diagnostic_abort_cleanup_005deb8c;
extern std::uint32_t diagnostic_abort_hook_005deb90;
extern std::uint32_t diagnostic_abort_filter_005deb94;

// Read-only .rdata strings owned by 00565340 (51 bytes total).
extern const char diagnostic_indent_fmt_005bd4c4[5];
extern const char diagnostic_abort_title_005bd4cc[14];
extern const char diagnostic_abort_file_line_fmt_005bd4dc[30];
extern const char diagnostic_newline_005d0b1c[2];

} // namespace porsche
