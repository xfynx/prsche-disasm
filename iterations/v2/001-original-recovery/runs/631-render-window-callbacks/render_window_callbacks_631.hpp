// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

namespace porsche {

// Read-only 16-byte .rdata IID at original VA 0x005bef50
// ({b3a6f3e0-2b43-11cf-a2de-00aa00b93356}, IID_IDirectDraw2).
alignas(4) extern const std::uint8_t render_window_ddraw2_iid_005bef50[16];

} // namespace porsche
