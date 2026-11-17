#pragma once

#include <cstdint>
#include "porsche/render_startup.hpp"
#include "porsche/startup_service_516950.hpp"
#include "porsche/window_runtime.hpp"
#include "../496-render-present-caller-repair/render_display_496.hpp"
#include "../522-audio-stream-transform/audio_stream_transform_522.hpp"

namespace porsche {

// File-backed .data DWORDs at original VAs 0x005e517c..0x005e5187 (12 bytes).
extern std::uint32_t render_display_scale_x_005e517c;
extern std::uint32_t render_display_scale_y_005e5180;
extern std::uint32_t render_display_step_base_005e5184;

// Loader-zero .data DWORDs at original VAs 0x006afc7c, 0x006afc80, 0x0065b398 (12 bytes).
extern std::uint32_t render_display_offset_x_006afc7c;
extern std::uint32_t render_display_offset_y_006afc80;
extern std::uint32_t render_teardown_state_0065b398;

// Loader-zero .data DWORDs at original VAs 0x006a5dd4..0x006a5deb (24 bytes).
extern std::uint32_t render_frame_timer_word_006a5dd4;
extern std::uint32_t render_frame_timer_word_006a5dd8;
extern std::uint32_t render_frame_timer_tick_006a5ddc;
extern std::uint32_t render_frame_timer_word_006a5de0;
extern std::uint32_t render_frame_timer_word_006a5de4;
extern std::uint32_t render_frame_timer_word_006a5de8;

// Original entry 0056a680..0056a6a5 (38 bytes).
void __cdecl render_frame_timer_reset_0056a680();

} // namespace porsche
