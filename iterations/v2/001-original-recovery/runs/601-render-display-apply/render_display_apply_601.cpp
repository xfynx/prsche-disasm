// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 004b70d0..004b713f, 112 bytes, sha256 f66b33262c7e8c7359db1375edf07762afb70f3a097fc2a7f7c2e386538635d2.
// Original 0056a680..0056a6a5, 38 bytes, sha256 bc9d060f3142e5d9c77ac11fd7ab813c7024df413694c2aa55e4e8381aa28cd8.
#include "render_display_apply_601.hpp"

namespace porsche {

std::uint32_t render_display_scale_x_005e517c = 0x3f800000u;
std::uint32_t render_display_scale_y_005e5180 = 0x3f800000u;
std::uint32_t render_display_step_base_005e5184 = 0x00000080u;

std::uint32_t render_display_offset_x_006afc7c = 0u;
std::uint32_t render_display_offset_y_006afc80 = 0u;
std::uint32_t render_teardown_state_0065b398 = 0u;

std::uint32_t render_frame_timer_word_006a5dd4 = 0u;
std::uint32_t render_frame_timer_word_006a5dd8 = 0u;
std::uint32_t render_frame_timer_tick_006a5ddc = 0u;
std::uint32_t render_frame_timer_word_006a5de0 = 0u;
std::uint32_t render_frame_timer_word_006a5de4 = 0u;
std::uint32_t render_frame_timer_word_006a5de8 = 0u;

namespace {
std::uint32_t scaled_display_step_601(std::uint32_t base_val) {
    const std::uint64_t q = static_cast<std::uint64_t>(base_val);
    __asm {
        fild qword ptr q
        fmul dword ptr [render_display_scale_y_005e5180]
    }
    return static_cast<std::uint32_t>(audio_stream_ftol_005a0f98());
}
} // namespace

void __cdecl render_frame_timer_reset_0056a680() {
    render_frame_timer_word_006a5dd4 = 0u;
    render_frame_timer_word_006a5dd8 = 0u;
    render_frame_timer_word_006a5de0 = 0u;
    render_frame_timer_word_006a5de4 = 0u;
    render_frame_timer_word_006a5de8 = 0u;
    render_frame_timer_tick_006a5ddc = current_tick_006b7c40;
}

void __cdecl render_display_apply_004b70d0(std::uint32_t field7c, std::uint32_t field74) {
    reinterpret_cast<void(__cdecl*)(std::uint32_t, std::uint32_t, std::uint32_t)>(&startup_service_noop_00516950)(field7c, field74, 0x80u);
    render_display_scale_x_005e517c = 0x3f000000u;
    render_display_scale_y_005e5180 = 0x3f800000u;
    render_frame_timer_reset_0056a680();
    const std::uint32_t base_val = render_display_step_base_005e5184;
    render_display_offset_x_006afc7c = 0u;
    const std::uint32_t step = scaled_display_step_601(base_val);
    const std::uint32_t height = render_display_texture_height_005deacc;
    render_teardown_state_0065b398 = 1u;
    render_display_offset_y_006afc80 = height - step;
}

} // namespace porsche
