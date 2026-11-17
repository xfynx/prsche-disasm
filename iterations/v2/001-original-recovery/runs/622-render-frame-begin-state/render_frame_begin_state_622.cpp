// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 00534540..0053454b, 12 bytes, sha256 a24b8810ee0261f826f3539727ca897e3f3fd094c494fa4cb88eabb9bfbc4c15.
// Owned .data 005de680..005de6ab, 44 bytes, sha256 220c387157e14d3be6c2715c7a6a737fbc0e32f0d1f11763ea4db572f1b5f69c.
// Original 00535a90..00535af7, 104 bytes, sha256 79cb8e354813241bd94bcf84855d3a7f8039c7b1a1a30680c164a5931d39c174.
#include "render_frame_begin_state_622.hpp"

namespace porsche {

std::uint32_t render_frame_begin_descriptor_005de680[11] = {
    0u, 0u, 0u, 0u, 2u, 0u, 0u, 0x280u, 0x1e0u, 0u, 0u
};

namespace {

void __cdecl render_frame_begin_00534540() {
    std::uint32_t staging[12] = {};
    for (std::uint32_t i = 0u; i < 11u; ++i) {
        staging[i] = render_frame_begin_descriptor_005de680[i];
    }
    staging[11] = window_shutdown_state_005de6ac;
    const std::uint32_t pre_ac = staging[11];
    (void)render_descriptor_bind_00534480(staging);
    for (std::uint32_t i = 0u; i < 11u; ++i) {
        render_frame_begin_descriptor_005de680[i] = staging[i];
    }
    if (staging[11] != pre_ac) {
        window_shutdown_state_005de6ac = staging[11];
    }
}

} // namespace

void __cdecl game_setup_draw_begin_00534540() {
    render_frame_begin_00534540();
}

void __cdecl splash_progress_driver_frame_begin_00534540() {
    render_frame_begin_00534540();
}

std::uint32_t __cdecl render_resource_texture_state_00535a90(
    std::uint32_t key, std::uint32_t value) {
    if (render_resource_texture_fallback_0069dd1c == 0u) {
        return render_settings_set_state_006bd97c(key, value);
    }
    const std::int32_t stage = (key & 0x80000000u) != 0u
        ? static_cast<std::int32_t>((key >> 16u) | 0xffff0000u)
        : static_cast<std::int32_t>(key >> 16u);
    const std::uint32_t base = static_cast<std::uint32_t>(stage) * 14u;
    const std::uint32_t remapped_key = (key & 0x000f0000u) | 0x0du;
    std::uint32_t out_value = value;
    if (render_state_flush_records_005de6bc[base + 11u] == 1u ||
        render_state_flush_records_005de6bc[base + 13u] == 1u) {
        out_value = 1u;
    }
    return render_settings_set_state_006bd97c(remapped_key, out_value);
}

} // namespace porsche
