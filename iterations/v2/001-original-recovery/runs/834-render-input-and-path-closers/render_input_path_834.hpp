// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "porsche/input_state.hpp"
#include "porsche/process_exit.hpp"
#include "porsche/render_display.hpp"
#include "porsche/render_startup.hpp"
#include "porsche/resource_paths.hpp"

namespace porsche {

static_assert(sizeof(void*) == 4, "original x86 pointer ABI");

// Newly owned read-only .data literals at 005cf78c..005cf7b1 (38B) and
// 005cf7b4..005cf7ba (7B), consumed by render_missing_setup_00467535.
extern const char render_missing_setup_text_005cf78c[38];
extern const char render_missing_setup_title_005cf7b4[7];

} // namespace porsche
