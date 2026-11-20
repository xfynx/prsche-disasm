// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

namespace porsche {

// Owned .rdata string 005bb3fc..005bb425 (41B including NUL):
// "getclutptr - UNSUPPORTED CLUT TYPE 0x%x\n".
extern const char render_getclutptr_message_005bb3fc[41];

// Original 005346d0..0053482f (352B, __cdecl, ret pointer in EAX). Resolves the
// clut resource for descriptor; type 0x2a returns the in-place clut data
// pointer, converted types return the caller's 1024-byte BGRA8888 palette, and
// a failed lookup returns render_pixel_palette_006b4b20.
std::uint32_t* __cdecl render_getclutptr_from_resource_005346d0(
    const void* descriptor, std::uint32_t* palette);

} // namespace porsche
