// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "porsche/splash_progress.hpp"
#include "porsche/shared_runtime_globals.hpp"
#include "porsche/files.hpp"
#include "../374-render-descriptor/render_descriptor.hpp"
#include "../378-buffer-select/buffer_select.hpp"

namespace porsche {

// Read-only .rdata strings owned by 00563320 (126 bytes total).
extern const char splash_hflip_bits_fmt_005bced8[47];
extern const char splash_hflip_packed_fmt_005bcf08[61];
extern const char splash_hflip_file_005bcf48[18];

// Original entry 0056e2a8..0056e2bf (24 bytes).
std::uint32_t __cdecl render_buffer_read_word_0056e2a8(const void* src, std::int32_t bytes);

// Original entry 005712f0..00571320 (49 bytes).
std::int32_t __cdecl splash_shape_row_stride_005712f0(const void* shape);

// splash_progress_update_sprite_00563320 (286 bytes) is declared in porsche/splash_progress.hpp.

} // namespace porsche
