// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 005363a0..00536451, 178 bytes, sha256 4317a6d2d78522e8b3b4a2b34d39961d5a73ce36fb94972a7510fdae7c7a03bf.
#include "frame_state_release_589.hpp"
#include "render_state_flush_527.hpp"
#include "startup_service_570.hpp"
#include "startup_lifecycle_572.hpp"
#include <cstring>

namespace porsche {
namespace {
using U = std::uint32_t;
using B = std::uint8_t;

U load32(const void* base, U offset) {
    U value;
    std::memcpy(&value, static_cast<const B*>(base) + offset, 4);
    return value;
}
} // namespace

void __fastcall startup_lifecycle_apply_raw_005363a0(void* receiver, void*) {
    for (U i = 0; i < 2; ++i) {
        if (load32(receiver, 8 + i * 4) != 0) {
            for (U j = 0; j < 7; ++j) {
                const U val = render_state_flush_records_005de6bc[14 * i + 2 * j + 1];
                const U key = render_state_flush_records_005de6bc[14 * i + 2 * j];
                reinterpret_cast<void(__cdecl*)(U, U)>(render_state_flush_callbacks_005de72c[j])(key, val);
            }
        }
    }
    if (startup_lifecycle_mode_005de6b8 == 0 || startup_service_active_0069dd1e == 0) {
        return;
    }
    const U first = load32(receiver, 8);
    if (first == 0) {
        const U second0 = load32(receiver, 12);
        if (second0 == 0) {
            render_display_texture_release_00555440(nullptr);
            return;
        }
        render_display_texture_release_00555440(reinterpret_cast<void*>(1));
    } else {
        const U first_handle = load32(reinterpret_cast<const void*>(first), 8);
        render_display_texture_release_00555440(reinterpret_cast<void*>(first_handle));
    }
    const U second = load32(receiver, 12);
    if (second != 0) {
        const U second_handle = load32(reinterpret_cast<const void*>(second), 8);
        render_display_texture_release_00555440(reinterpret_cast<void*>(second_handle));
    } else {
        render_display_texture_release_00555440(reinterpret_cast<void*>(2));
    }
}

void __cdecl frame_pump_boundary_005363a0(void* self) {
    startup_lifecycle_apply_raw_005363a0(self, nullptr);
}
}
