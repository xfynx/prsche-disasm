// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "porsche/input_buffer.hpp"

namespace porsche {

// Owned initialized .data table at 005dfa20..005dfa3f (32 bytes = 8 axis offsets).
extern const std::uint32_t input_axis_offsets_005dfa20[8];

// Original continuation 0056fdf9..0056ff8c (404B) inside 0056fdb0..0056ff8c (477B).
// Declared in porsche/input_buffer.hpp.
std::uint32_t __cdecl input_caps_success_unrecovered_0056fdf9(
    InputBufferDevice* device, void* output_21c, const void* capabilities_244);

} // namespace porsche
