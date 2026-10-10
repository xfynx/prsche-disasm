#include "porsche/frame_services.hpp"

#include "porsche/application_state.hpp"
#include "porsche/startup_service_516950.hpp"

#include <cstddef>
#include <cstdint>
#include <cstring>

namespace porsche {
namespace {
std::array<std::uint8_t, 2> frame_services_flag_storage_00656868{};
std::array<std::uint32_t, 5> frame_services_words_005d1740_storage{
    0x7fu, 0x7fu, 0x7fu, 0x7fu, 0x7fu};

std::uint32_t& application_word(std::uint32_t va) {
    return application_state_006573e8.word(va);
}

std::int32_t arithmetic_shift_right_7(std::uint32_t bits) noexcept {
    std::int32_t signed_bits{};
    std::memcpy(&signed_bits, &bits, sizeof(signed_bits));
    const auto widened = static_cast<std::int64_t>(signed_bits);
    const auto shifted = widened >= 0 ? widened / 128
        : -((-widened + 127) / 128);
    return static_cast<std::int32_t>(shifted);
}
} // namespace

std::array<std::uint32_t, 146> frame_services_records_00656180{};
std::uint8_t& frame_services_byte_00656868 = frame_services_flag_storage_00656868[0];
std::uint8_t& frame_services_byte_00656869 = frame_services_flag_storage_00656868[1];
std::uint32_t frame_services_word_005d14b0 = 0x50u;
std::array<std::uint32_t, 5>& frame_services_words_005d1740 =
    frame_services_words_005d1740_storage;

std::uint32_t __cdecl frame_services_004ab150() {
    const auto gate = application_word(0x00657c94u);
    if (gate != 0)
        return gate;

    frame_services_boundary_004af900(0, 0);
    for (std::size_t index = 0; index < 73; ++index) {
        const auto record_word = frame_services_records_00656180[index * 2];
        if (record_word != 0xffffffffu)
            frame_services_boundary_00566340(record_word, 0);
    }

    frame_services_boundary_004ae3c0(0);
    if (frame_services_byte_00656868 != 0) {
        frame_services_boundary_00565cd0(0, 0);
        frame_services_byte_00656869 = 0;
        frame_services_byte_00656868 = 0;
    }

    frame_services_boundary_004ad510();
    frame_services_words_005d1740[1] = application_word(0x00657ca4u);
    frame_services_words_005d1740[0] = application_word(0x00657ca0u);
    frame_services_words_005d1740[2] = application_word(0x00657ca8u);
    frame_services_words_005d1740[3] = application_word(0x00657cacu);
    frame_services_words_005d1740[4] = application_word(0x00657cb0u);
    return application_word(0x00657cacu);
}

std::uint32_t __cdecl frame_services_004ab200() {
    const auto gate = application_word(0x00657c94u);
    if (gate != 0)
        return gate;

    const std::uint32_t product_bits = frame_services_word_005d14b0 *
        frame_services_words_005d1740[0];
    const auto shifted = static_cast<std::uint32_t>(
        arithmetic_shift_right_7(product_bits));
    frame_services_boundary_004ae8c0(shifted);
    frame_services_boundary_004ae4d0(0, 0);
    startup_service_noop_00516950();

    application_word(0x00657ca4u) = frame_services_words_005d1740[1];
    application_word(0x00657ca0u) = frame_services_words_005d1740[0];
    application_word(0x00657ca8u) = frame_services_words_005d1740[2];
    application_word(0x00657cacu) = frame_services_words_005d1740[3];
    application_word(0x00657cb0u) = frame_services_words_005d1740[4];
    return frame_services_words_005d1740[2];
}
} // namespace porsche
