// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 00568f30..00569073, 324 bytes, sha256 5e6b1d75fd6acadf6f6d18a792fc14c961c3e15f768f610d53e1c32a8642c40e.
#include "frame_surface_setup_616.hpp"

namespace porsche {

std::uint32_t frame_surface_state_006a5c84 = 0u;
std::uint32_t frame_surface_width_006a5c88 = 0u;
std::uint32_t frame_surface_arg1_006a5c8c = 0u;
std::uint32_t frame_surface_arg0_006a5c90 = 0u;
std::uint32_t frame_surface_arg4_006a5c94 = 0u;
std::uint32_t frame_surface_sentinel_006a5c98 = 0u;
std::uint32_t frame_surface_height_006a5c9c = 0u;

void __cdecl frame_pump_boundary_00568f30(
    std::uint32_t a0, std::uint32_t a1, std::uint32_t a2,
    std::uint32_t a3, std::uint32_t a4, std::uint32_t a5) {
    (void)frame_pump_boundary_005693e0();
    frame_surface_arg0_006a5c90 = a0;
    frame_surface_arg1_006a5c8c = a1;
    frame_surface_height_006a5c9c = a3;
    frame_surface_sentinel_006a5c98 = 0xffffffffu;
    frame_surface_width_006a5c88 = a2;
    frame_surface_arg4_006a5c94 = a4;
    frame_surface_state_006a5c84 = 2u;
    if (a5 != 0u) {
        return;
    }

    using ThrashAbout_616 = const std::uint32_t* (__stdcall *)();
    using ThrashGetState_616 = std::uint32_t (__stdcall *)(std::uint32_t, std::uint32_t*);
    const std::uint32_t* const about = reinterpret_cast<ThrashAbout_616>(
        static_cast<std::uintptr_t>(render_thrash_exports_006bd910[9]))();
    std::uint32_t dd_ptr = 0u;
    if (about[0x7cu / 4u] == 7u &&
        reinterpret_cast<ThrashGetState_616>(
            static_cast<std::uintptr_t>(render_thrash_exports_006bd910[27]))(
            0x26u, &frame_interface_final_flag_006a5ca0) != 0u) {
        dd_ptr = frame_interface_final_flag_006a5ca0;
        if (dd_ptr != 0u) {
            const auto* const vtbl = *reinterpret_cast<std::uintptr_t* const*>(
                static_cast<std::uintptr_t>(dd_ptr));
            using EnumModesSlot9_616 = std::int32_t (__stdcall *)(
                std::uint32_t self, std::uint32_t flags, void* desc,
                std::uint32_t* ctx, std::uint32_t callback_va);
            (void)reinterpret_cast<EnumModesSlot9_616>(vtbl[9])(
                dd_ptr, 0x11u, nullptr, &frame_interface_second_006a5ca4, 0x00569080u);
            dd_ptr = frame_interface_final_flag_006a5ca0;
        }
    } else {
        dd_ptr = frame_interface_final_flag_006a5ca0;
    }

    if (frame_interface_second_006a5ca4 == 0u) {
        (void)frame_pump_boundary_005693e0();
        return;
    }

    std::uint32_t ddsd[31] = {};
    const std::uint32_t h = frame_surface_height_006a5c9c;
    const std::uint32_t w = frame_surface_width_006a5c88;
    ddsd[0] = 0x7cu;
    ddsd[1] = 0x1027u;
    ddsd[2] = h;
    ddsd[3] = w;
    ddsd[5] = 1u;
    ddsd[18] = 0x20u;
    ddsd[19] = 4u;
    ddsd[20] = 0x32595559u;
    ddsd[26] = 0x4098u;

    const auto* const vtbl = *reinterpret_cast<std::uintptr_t* const*>(
        static_cast<std::uintptr_t>(dd_ptr));
    using CreateSurfaceSlot6_616 = std::int32_t (__stdcall *)(
        std::uint32_t self, const std::uint32_t* desc,
        std::uint32_t* out_surface, void* unk);
    if (reinterpret_cast<CreateSurfaceSlot6_616>(vtbl[6])(
            dd_ptr, ddsd, &frame_interface_first_006a5ca8, nullptr) != 0) {
        (void)frame_pump_boundary_005693e0();
        return;
    }
    frame_surface_state_006a5c84 = 1u;
}

} // namespace porsche
