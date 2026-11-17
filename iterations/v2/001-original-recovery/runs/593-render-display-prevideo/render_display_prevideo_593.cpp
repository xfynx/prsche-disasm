// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 0044e2c0..0044e364, 165 bytes, sha256 31b476817095733dd64d11fbd5ff1de498b1439cccac96ecc4652fc87aac047e.
#include "render_display_prevideo_593.hpp"
#include "porsche/render_mode.hpp"
#include "porsche/render_activate.hpp"
#include <cstdint>
#include <cstring>

namespace porsche {
namespace {
using U = std::uint32_t;
using B = std::uint8_t;
static_assert(sizeof(void*) == 4, "x86 pointer width required");

U load32(const void* base, U offset) {
    U value;
    std::memcpy(&value, static_cast<const B*>(base) + offset, sizeof value);
    return value;
}
} // namespace

void __cdecl render_display_prevideo_0044e2c0() {
    const auto* display = reinterpret_cast<const B*>(render_display_00628130);
    U width = 0x280u;
    U height = 0x1e0u;
    U format = 0x10u;
    if (display[0x60] == 0u) {
        void* driver = reinterpret_cast<void*>(static_cast<std::uintptr_t>(load32(display, 0x70u)));
        render_mode_driver_prepare_vslot9(driver);
        const auto* modes = reinterpret_cast<const B*>(static_cast<std::uintptr_t>(load32(driver, 8u)));
        U local_record[10];
        std::memcpy(local_record, modes + 0x28u, sizeof local_record);
        format = local_record[2];
        height = local_record[1];
        width = local_record[0];
    }
    render_display_mode_index_00619780 = 1u;
    render_display_actual_width_00619784 = width;
    render_display_actual_height_00619788 = height;
    render_display_actual_mode_0061978c = format;
    if (format == 0x0fu) {
        render_display_actual_mode_0061978c = 0x10u;
    }
    render_mode_state_00619790[0x0a] = 1u;
    render_mode_apply_settings_0044e890();
    render_mode_update_state_0044ed10();
    const U final_height = render_display_actual_height_00619788;
    const U final_width = render_display_actual_width_00619784;
    render_display_video_base_00537600(0u, 0u, 0u, final_width, final_height, 0u);
}
} // namespace porsche
