// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 005345e0..00534629 (74B), 00535340..00535354 (21B),
// 00535360..00535377 (24B), 00571490..005714d5 (70B),
// 00571520..0057152d (14B), and 00573070..00573072 (3B).
#include "render_depth_helpers_674.hpp"

#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Original EMMS instruction boundary requires MSVC x86
#endif

namespace porsche {

static_assert(sizeof(void*) == 4u, "original x86 layout requires 32-bit pointers");

std::int32_t render_depth_format_table_005de574[14] = {
    -1, 0, 1, 2, 3, 4, 5, 6, -1, -1, -1, 2, -1, -1,
};

std::uint32_t render_depth_level_table_005de5ac[7] = {
    1u, 2u, 3u, 4u, 5u, 6u, 7u,
};

std::int32_t __cdecl render_shape_type_to_depth_index_005345e0(std::uint32_t shape_type) {
    switch (shape_type) {
    case 0x01u:
    case 0x40u:
    case 0x7au:
        return 0;
    case 0x02u:
    case 0x41u:
    case 0x7bu:
        return 1;
    case 0x03u:
    case 0x7eu:
        return 2;
    case 0x04u:
    case 0x78u:
        return 3;
    case 0x05u:
    case 0x43u:
    case 0x7fu:
        return 4;
    case 0x7du:
        return 5;
    case 0x6du:
        return 6;
    case 0x42u:
        return 7;
    default:
        return -1;
    }
}

std::int32_t __cdecl render_depth_format_index_00535340(std::uint32_t format_index) {
    if (format_index >= 14u) {
        return -1;
    }
    return render_depth_format_table_005de574[format_index];
}

std::uint32_t __cdecl render_depth_level_00535360(std::int32_t depth_index) {
    if (depth_index < 0 || depth_index >= 7) {
        return 0u;
    }
    return render_depth_level_table_005de5ac[depth_index];
}

std::uint32_t __cdecl render_chunk_size_00571490(const void* header) {
    const auto* const bytes = static_cast<const std::uint8_t*>(header);
    const std::uint8_t marker = bytes[1];
    if (marker != 0xfbu && marker != 0x32u) {
        return 0u;
    }
    switch (bytes[0] & 0xfeu) {
    case 0x10u:
    case 0x18u:
    case 0x30u:
    case 0x32u:
    case 0x34u:
    case 0x46u:
        return render_descriptor_read_be_0056e290(bytes + 2, 3u);
    default:
        return 0u;
    }
}

std::uint32_t __cdecl render_chunk_size_wrapper_00571520(const void* header) {
    return render_chunk_size_00571490(header);
}

void __cdecl render_mmx_empty_00573070() {
    __asm {
        emms
    }
}

} // namespace porsche
