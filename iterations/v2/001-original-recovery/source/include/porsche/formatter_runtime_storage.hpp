#pragma once

#include "porsche/formatter_cleanup.hpp"
#include "porsche/formatter_parser.hpp"

#include <cstdint>

namespace porsche {

// Canonical initial-image storage; this does not run CRT initialization.
// 005a3683..005a369c proves 20 entries, 32 bytes each, ending at 005e5768.
// Original HIGHLOW pointers relocate to native storage and entry aliases.
extern FormatterOriginalDescriptor32 formatter_iob_entries_005e54e8[20];
extern std::uint8_t formatter_iob_buffer_006c0520[0x1000];
extern const std::uint8_t formatter_invalid_handle_record_bytes_005e5f50[36];
extern const char formatter_null_narrow_bytes_005c1a34[7];
extern const std::uint16_t formatter_null_wide_bytes_005c1a24[7];

// 005abee8 is the original default callback target. Its body calls the CRT
// fatal-message boundary at 005a2e22; that external effect is intentionally
// unresolved here. Production linking must supply that effect before use;
// no replacement callback implementation is supplied. Typed entries reflect the two call-site
// ABIs that share that original address.
void __cdecl formatter_default_float_failure_005abee8(
    const void* words, char* output, int conversion, int precision,
    int float_mode);
void __cdecl formatter_default_text_failure_005abee8(char* text);

} // namespace porsche
