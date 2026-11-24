// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "porsche/application_heap.hpp"
#include "porsche/exit_shutdown.hpp"
#include "porsche/files.hpp"
#include "porsche/formatter_crt_runtime.hpp"
#include "porsche/timer_setup.hpp"
#include "porsche/window_create.hpp"

namespace porsche {

static_assert(sizeof(void*) == 4, "original x86 pointer ABI");

// Newly owned loader-zero .bss cell at 006afed0..006afed3 (4 bytes),
// holding the previous top-level exception filter restored by 005ac147.
extern void* exit_shutdown_prev_filter_006afed0;

// Newly owned .data string literal at 005e4ffc..005e5033 (56 bytes).
extern const char application_memory_insufficient_fmt_005e4ffc[56];

} // namespace porsche
