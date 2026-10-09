#pragma once

#include <cstdint>

namespace porsche {

struct MovieHeaderDrawArgs {
    std::int32_t x;
    std::int32_t y;
    std::int32_t width;
    std::int32_t height;
    std::uint32_t fixed_mode;
    std::uint32_t caller_arg3;
    std::int32_t caller_arg4;
    std::uint32_t caller_arg5;
};

struct MovieHeaderState {
    std::uint32_t frame_period_0065e268;
    std::int32_t width_0065e280;
    std::int32_t height_0065e3e8;
    std::uint32_t counter_0065e28c;
    std::uint32_t decoded_frame_count_0065e3e4;
    std::uint32_t decoded_delta_0065ba5c;
    MovieHeaderDrawArgs draw;
};

using MovieHeaderDrawBoundary = void (__cdecl *)(
    std::int32_t, std::int32_t, std::int32_t, std::int32_t,
    std::uint32_t, std::uint32_t, std::int32_t, std::uint32_t);

// Bounded 004dc850 slice: consumes an already accepted MAD-family header and
// prepares its dimensions before the original 004dc180 renderer boundary.
// Stream scanning, frame playback, audio and input are outside this function.
bool movie_header_prepare_004dc850(
    const std::uint8_t* chunk,
    std::int32_t caller_arg3,
    std::int32_t caller_arg4,
    std::uint32_t caller_arg5,
    std::int32_t screen_width,
    std::int32_t screen_height,
    MovieHeaderState* state,
    MovieHeaderDrawBoundary draw_boundary);

} // namespace porsche
