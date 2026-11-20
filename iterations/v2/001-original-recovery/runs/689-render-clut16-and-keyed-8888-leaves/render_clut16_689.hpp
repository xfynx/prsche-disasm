// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

namespace porsche {

// Owned zero-initialized .data cell 006a6420..006a6423 (4B, PE loader-zeroed).
// Full 32-bit color key compared against zero-extended 16-bit clut pixels by
// 00570780/00570820; also read at 005705b3 (00570590, not yet recovered).
extern std::uint32_t render_palette_color_key_006a6420;

// Owned .rdata string 005bb3e4..005bb3fa (23B): "\\real\\cmn\\depthconv.c".
extern const char render_clut16_file_005bb3e4[23];

// Owned .rdata string 005bb428..005bb452 (43B).
extern const char render_clut16_message_005bb428[43];

// Original 00570780..00570813 (148B, __cdecl, ret 0; void). Expands count
// 16-bit RGB555 entries (bit 15 stored as the 8-bit alpha byte, 0x00 or 0xff)
// to BGRA8888 with 5-bit field bit replication; a full-32-bit color-key match
// writes 0.
void __cdecl render_palette_5551_to_8888_key_00570780(
    std::uint32_t* dst, const std::uint16_t* src, std::int32_t count);

// Original 00570820..0057089f (128B, __cdecl, ret 0; void). Expands count
// 16-bit RGB565 entries to opaque BGRA8888 (alpha 0xff) with 5/6-bit field bit
// replication; a full-32-bit color-key match writes 0.
void __cdecl render_palette_565_to_8888_key_00570820(
    std::uint32_t* dst, const std::uint16_t* src, std::int32_t count);

// Original 00534830..005349d2 (419B, __cdecl, ret pointer in EAX). getclut16ptr:
// resolves the clut resource for the descriptor, converts its 16-bit palette
// into the 512-byte palette (word at +0x1fe cleared to 0 for every resolved
// type except 0x29) or returns the in-place clut data pointer for type 0x29.
std::uint16_t* __cdecl render_clut16_from_resource_00534830(
    const void* descriptor, std::uint16_t* palette);

} // namespace porsche
