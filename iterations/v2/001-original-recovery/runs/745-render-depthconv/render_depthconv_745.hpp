// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

namespace porsche {

// Canonical storage remains external to this proof-only packet.
extern std::uint32_t* render_depthconv_palette_ptr_005de2f8;
extern std::uint32_t render_depthconv_palette_scratch_006bda20[256];

// Original 00534b90..00534d35 (422B, __cdecl, ret 0).
// The returned value is an original 32-bit callback VA token. It is intentionally
// not a host-callable binding until every table target has a canonical provider.
void* __cdecl render_shape_row_converter_00534b90(
    const void* shape, std::uint32_t target_type, std::int32_t direct_mode);

} // namespace porsche
