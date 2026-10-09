#include "porsche/movie_header.hpp"

#include <cstring>

namespace porsche {
namespace {

std::uint32_t read_u32(const std::uint8_t* p) {
    std::uint32_t value;
    std::memcpy(&value, p, sizeof(value));
    return value;
}

std::int32_t read_i16(const std::uint8_t* p) {
    std::int16_t value;
    std::memcpy(&value, p, sizeof(value));
    return value;
}

bool is_movie_tag(std::uint32_t tag) {
    return tag == 0x6d44414dU || tag == 0x6544414dU || tag == 0x6b44414dU;
}

std::int32_t signed_half(std::int32_t value) {
    return value / 2; // C++ signed division matches x86 IDIV truncation toward zero.
}

std::int32_t subtract_wrap(std::int32_t left, std::int32_t right) {
    const auto bits = static_cast<std::uint32_t>(left) - static_cast<std::uint32_t>(right);
    std::int32_t value;
    std::memcpy(&value, &bits, sizeof(value));
    return value;
}

} // namespace

bool movie_header_prepare_004dc850(
    const std::uint8_t* chunk,
    std::int32_t caller_arg3,
    std::int32_t caller_arg4,
    std::uint32_t caller_arg5,
    std::int32_t screen_width,
    std::int32_t screen_height,
    MovieHeaderState* state,
    MovieHeaderDrawBoundary draw_boundary) {
    if (!chunk || !state || !draw_boundary || !is_movie_tag(read_u32(chunk)))
        return false;

    const auto frame_period = read_u32(chunk + 0x0c);
    const auto width = read_i16(chunk + 0x10);
    const auto height = read_i16(chunk + 0x12);

    MovieHeaderDrawArgs draw{};
    if (caller_arg4 == 0) {
        draw.x = signed_half(subtract_wrap(screen_width, width));
        draw.y = signed_half(subtract_wrap(screen_height, height));
    } else {
        draw.x = subtract_wrap(signed_half(screen_width), width);
        draw.y = subtract_wrap(signed_half(screen_height), height);
    }
    draw.width = width;
    draw.height = height;
    draw.fixed_mode = 6;
    draw.caller_arg3 = static_cast<std::uint32_t>(caller_arg3);
    draw.caller_arg4 = caller_arg4;
    draw.caller_arg5 = caller_arg5;

    state->frame_period_0065e268 = frame_period;
    state->width_0065e280 = width;
    state->height_0065e3e8 = height;
    state->counter_0065e28c = 1;
    state->decoded_frame_count_0065e3e4 = 0;
    state->decoded_delta_0065ba5c = 0;
    state->draw = draw;
    draw_boundary(draw.x, draw.y, draw.width, draw.height, draw.fixed_mode,
                  draw.caller_arg3, draw.caller_arg4, draw.caller_arg5);
    return true;
}

} // namespace porsche
