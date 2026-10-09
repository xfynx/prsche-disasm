#include "porsche/movie_header.hpp"

#include <array>
#include <cstdint>
#include <cstring>
#include <iostream>

namespace {
void __cdecl record_draw(std::int32_t, std::int32_t, std::int32_t, std::int32_t,
                         std::uint32_t, std::uint32_t, std::int32_t, std::uint32_t) {}
}

int main() {
    std::uint32_t tag, period, width_bits, height_bits, mode;
    std::int32_t screen_width, screen_height, arg3, arg4;
    std::uint32_t arg5;
    while (std::cin >> tag >> period >> width_bits >> height_bits >> mode
                    >> screen_width >> screen_height >> arg3 >> arg4 >> arg5) {
        std::array<std::uint8_t, 0x20> chunk{};
        const auto width = static_cast<std::int16_t>(width_bits);
        const auto height = static_cast<std::int16_t>(height_bits);
        std::memcpy(chunk.data(), &tag, sizeof(tag));
        std::memcpy(chunk.data() + 0x0c, &period, sizeof(period));
        std::memcpy(chunk.data() + 0x10, &width, sizeof(width));
        std::memcpy(chunk.data() + 0x12, &height, sizeof(height));
        porsche::MovieHeaderState state{};
        const bool accepted = porsche::movie_header_prepare_004dc850(
            chunk.data(), static_cast<std::int32_t>(arg3), static_cast<std::int32_t>(mode),
            arg5, screen_width, screen_height, &state, &record_draw);
        const auto& d = state.draw;
        std::cout << "{\"accepted\":" << (accepted ? 1 : 0)
                  << ",\"period\":" << state.frame_period_0065e268
                  << ",\"width\":" << state.width_0065e280
                  << ",\"height\":" << state.height_0065e3e8
                  << ",\"counter\":" << state.counter_0065e28c
                  << ",\"decoded\":" << state.decoded_frame_count_0065e3e4
                  << ",\"delta\":" << state.decoded_delta_0065ba5c
                  << ",\"draw\":[" << d.x << ',' << d.y << ',' << d.width << ',' << d.height
                  << ',' << d.fixed_mode << ',' << d.caller_arg3 << ',' << d.caller_arg4
                  << ',' << d.caller_arg5 << "]}\n";
    }
    return std::cin.eof() ? 0 : 2;
}
