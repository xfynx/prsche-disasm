// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

namespace porsche {

// Original entry 0053c640..0053c67e (63 bytes, __cdecl, ret 0).
void* __cdecl shape_find_entry_0053c640(const void* shape, const void* tag);

// Original entry 00556370..005563ac (61 bytes, __cdecl, ret 0).
void __cdecl render_memmove_00556370(void* dst, const void* src, std::uint32_t size);

// Original entry 005563b0..005563c7 (24 bytes, __cdecl, ret 0).
void __cdecl render_copy_bytes_005563b0(const void* src, void* dst, std::uint32_t size);

// Original entry 00554930..00554942 (19 bytes, __cdecl, ret 0).
void __cdecl render_texture_format_16bit_mode_00554930(std::int32_t mode_flag);

// Original entry 00555640..0055569e (95 bytes, __cdecl, ret 0).
void __cdecl render_texture_slot_bind_00555640(
    std::int32_t stage_index,
    std::uint32_t value,
    std::uint32_t width,
    std::uint32_t height,
    std::uint32_t format_a,
    std::uint32_t format_b,
    std::uint32_t flags);

} // namespace porsche
