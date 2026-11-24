// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 00538b30..00538c7d (334B), 00537830..00537844 (21B),
// 00537890..005378b6 (39B), 005378c0..005378d4 (21B), 005378e0..005378f4 (21B),
// 00537900..00537914 (21B), 00537920..00537936 (23B), 00537940..00537956 (23B),
// 00537960..00537976 (23B), 00537980..00537994 (21B), 005379a0..005379c3 (36B),
// and 005404a0..005404d2 (51B).
#include "render_driver_select_mode_797.hpp"

#include <cstring>

namespace porsche {

static_assert(sizeof(void*) == 4u, "original x86 layout requires 32-bit pointers");

std::uint32_t render_driver_state2_enabled_005ded4c = 0u;
std::uint32_t render_driver_tex_offset_005dedf4 = 2u;

namespace {

std::uint32_t read_u32(const void* base, std::size_t offset) {
    std::uint32_t value = 0u;
    std::memcpy(&value, static_cast<const std::uint8_t*>(base) + offset, sizeof(value));
    return value;
}

void write_u32(void* base, std::size_t offset, std::uint32_t value) {
    std::memcpy(static_cast<std::uint8_t*>(base) + offset, &value, sizeof(value));
}

void write_f32(void* base, std::size_t offset, float value) {
    std::memcpy(static_cast<std::uint8_t*>(base) + offset, &value, sizeof(value));
}

void* read_ptr(const void* base, std::size_t offset) {
    return reinterpret_cast<void*>(static_cast<std::uintptr_t>(read_u32(base, offset)));
}

std::uint32_t addr_u32(const void* ptr) {
    return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(ptr));
}

void write_state(void* cfg, std::size_t offset, std::uint32_t key, std::uint32_t value) {
    write_u32(cfg, offset, value);
    (void)render_buffer_state_00540480(key, value);
}

void write_alias_state(
    void* cfg, std::size_t offset, std::uint32_t key, std::uint32_t value) {
    write_u32(cfg, offset, value);
    (void)render_buffer_state_alias_005404e0(key, value);
}

} // namespace

void __cdecl render_driver_set_tex_state_005404a0(
    std::uint32_t key, std::uint32_t value) {
    auto* const ctx = static_cast<std::uint8_t*>(render_driver_context_0069e0d4);
    if ((read_u32(ctx, 0x117e4u) & 0x20000u) != 0u) {
        const float scaled = static_cast<float>(
            static_cast<double>(static_cast<std::int32_t>(value)) * (1.0 / 32768.0));
        write_f32(ctx, 0x1180cu, scaled);
        return;
    }
    (void)render_settings_set_state_006bd97c(key, value);
}

void __fastcall render_driver_set_state28_00537830(
    void* cfg, void*, std::uint32_t value) {
    write_state(cfg, 0x04u, 0x28u, value);
}

void __fastcall render_driver_set_state2_00537890(
    void* cfg, void*, std::uint32_t value) {
    if (read_u32(cfg, 0x10u) != value) {
        write_u32(cfg, 0x10u, value);
        if (render_driver_state2_enabled_005ded4c == 1u) {
            (void)render_buffer_state_00540480(2u, value);
        }
    }
}

void __fastcall render_driver_set_state3c_005378c0(
    void* cfg, void*, std::uint32_t value) {
    write_state(cfg, 0x2cu, 0x3cu, value);
}

void __fastcall render_driver_set_state9_005378e0(
    void* cfg, void*, std::uint32_t value) {
    write_state(cfg, 0x14u, 9u, value);
}

void __fastcall render_driver_set_state15_00537900(
    void* cfg, void*, std::uint32_t value) {
    write_state(cfg, 0x18u, 0x15u, value);
}

void __fastcall render_driver_set_alias_e_00537920(
    void* cfg, void*, std::uint32_t value) {
    write_alias_state(cfg, 0x1cu, 0x0eu, value);
}

void __fastcall render_driver_set_alias_16_00537940(
    void* cfg, void*, std::uint32_t value) {
    write_alias_state(cfg, 0x20u, 0x16u, value);
}

void __fastcall render_driver_set_alias_17_00537960(
    void* cfg, void*, std::uint32_t value) {
    write_alias_state(cfg, 0x24u, 0x17u, value);
}

void __fastcall render_driver_set_state_f_00537980(
    void* cfg, void*, std::uint32_t value) {
    write_state(cfg, 0x28u, 0x0fu, value);
}

void __fastcall render_driver_set_state18_005379a0(
    void* cfg, void*, std::uint32_t value) {
    if (read_u32(cfg, 0x30u) != value) {
        write_u32(cfg, 0x30u, value);
        render_driver_set_tex_state_005404a0(
            0x18u, render_driver_tex_offset_005dedf4 + value);
    }
}

std::uint8_t __fastcall render_driver_select_mode_00538b30(
    void* self, void*, std::uint32_t mode_index) {
    using SelectModeFn =
        std::uint32_t(__stdcall*)(std::uint32_t, std::uint32_t, std::uint32_t);
    const auto select_mode_fn =
        reinterpret_cast<SelectModeFn>(render_thrash_exports_006bd910[18]);
    if (select_mode_fn(mode_index, 2u, 2u) == 0u) {
        return 0u;
    }

    (void)render_driver_reg_flush_005b2004(0x80000000u);
    write_u32(self, 0x0cu, mode_index);
    render_driver_context_mode_00549220(render_driver_context_0069e0d4, nullptr, mode_index);
    render_resource_flush_states_00535b00();

    using Callback = void(__cdecl*)(std::uint32_t, std::uint32_t);
    volatile std::uint32_t* const pairs = render_driver_state_pairs_005ded30;
    Callback volatile* const callbacks = render_driver_state_callbacks_005ded60;
    for (std::uint32_t i = 0u; i < 6u; ++i) {
        const std::uint32_t value = pairs[i * 2u + 1u];
        const std::uint32_t key = pairs[i * 2u];
        const Callback callback = callbacks[i];
        callback(key, value);
    }

    void* cfg = read_ptr(self, 0x04u);
    render_driver_set_state28_00537830(cfg, nullptr, read_u32(cfg, 0x04u));
    cfg = read_ptr(self, 0x04u);
    render_driver_set_state2_00537890(cfg, nullptr, read_u32(cfg, 0x10u));
    cfg = read_ptr(self, 0x04u);
    render_display_finish_driver_core_00537850(cfg, nullptr, read_u32(cfg, 0x08u));
    cfg = read_ptr(self, 0x04u);
    render_driver_set_state9_005378e0(cfg, nullptr, read_u32(cfg, 0x14u));
    cfg = read_ptr(self, 0x04u);
    render_driver_set_state15_00537900(cfg, nullptr, read_u32(cfg, 0x18u));
    cfg = read_ptr(self, 0x04u);
    render_driver_set_alias_e_00537920(cfg, nullptr, read_u32(cfg, 0x1cu));
    cfg = read_ptr(self, 0x04u);
    render_driver_set_alias_16_00537940(cfg, nullptr, read_u32(cfg, 0x20u));
    cfg = read_ptr(self, 0x04u);
    render_driver_set_alias_17_00537960(cfg, nullptr, read_u32(cfg, 0x24u));
    cfg = read_ptr(self, 0x04u);
    render_driver_set_state_f_00537980(cfg, nullptr, read_u32(cfg, 0x28u));
    cfg = read_ptr(self, 0x04u);
    render_driver_set_state3c_005378c0(cfg, nullptr, read_u32(cfg, 0x2cu));
    cfg = read_ptr(self, 0x04u);
    render_driver_set_state18_005379a0(cfg, nullptr, read_u32(cfg, 0x30u));

    const RenderSettingsDevice* const device = render_settings_current_device_006bd934();
    write_u32(self, 0x10u, addr_u32(device));

    const std::uint32_t bound =
        render_descriptor_bind_00534480(cursor_snapshot_prefix_005de650);
    (void)window_shutdown_prepare_00534550();
    if (bound != 0u) {
        render_video_mode_005deaa8 = read_u32(self, 0x0cu);
        render_display_texture_width_005deac8 =
            read_u32(cursor_snapshot_prefix_005de650, 4u);
        render_display_texture_height_005deacc =
            read_u32(cursor_snapshot_prefix_005de650, 8u);
        splash_progress_format_005dead0 =
            static_cast<std::uint32_t>(window_shutdown_source_005de65d);
        render_video_state_005dead8 = 2u;
    }

    return 1u;
}

} // namespace porsche
