// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "porsche/formatter_float_helpers.hpp"
#include "porsche/formatter_text.hpp"

namespace porsche {

// 6-byte .data operator string at original VA 0x005d13bc..0x005d13c1 ("&|!~^\0").
extern char audio_transition_pattern_ops_005d13bc[6];

// Original 004a5f90..004a615f (464B, __cdecl uint32_t, ret 0).
// Note: `pattern` must be mutable writable memory; operator splits temporarily
// NUL-terminate *split in place and restore it (and '!' for '~' splits).
std::uint32_t __cdecl audio_transition_pattern_match_004a5f90(
    const char* text, char* pattern);

} // namespace porsche
