// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 005759f0..00575a1a, 43 bytes, sha256 9d035527fbf1e5fd9be53dccc97879658db1d8f64fd206f18975d251f5b348f2.
#include "render_initialize_callbacks_604.hpp"

namespace porsche {

std::uint32_t render_saved_display_hook_006a64c0 = 0u;

void __cdecl render_initialize_callbacks_005759f0() {
    using ThrashSetState_604 = void (__stdcall *)(std::uint32_t key, std::uint32_t value);
    reinterpret_cast<ThrashSetState_604>(render_thrash_exports_006bd910[27])(0x27u, 0x00575a20u);
    if (render_saved_display_hook_006a64c0 == 0u) {
        const std::uint32_t prev = render_thrash_exports_006bd910[40];
        render_thrash_exports_006bd910[40] = 0x00575980u;
        render_saved_display_hook_006a64c0 = prev;
    }
}

} // namespace porsche
