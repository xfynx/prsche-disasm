#include "frame_control_state_729.hpp"

#include <cstddef>
#include <cstdint>
#include <cstring>

namespace porsche {
namespace {

std::uint32_t read_u32(const std::uint8_t* address) {
    std::uint32_t value;
    std::memcpy(&value, address, sizeof(value));
    return value;
}

std::int16_t read_i16(const std::uint8_t* address) {
    std::int16_t value;
    std::memcpy(&value, address, sizeof(value));
    return value;
}

void release_from_current_row(std::size_t field_offset) {
    std::uint8_t* const state = frame_control_ff_state_005e9408;
    const std::uint32_t index = read_u32(state + 0x08u);
    const std::size_t row_offset = 0x18u + static_cast<std::size_t>(index) * 8u;
    const std::int16_t slot = read_i16(state + row_offset + field_offset);
    frame_control_slot_release_005338d0(static_cast<std::int32_t>(slot));
}

} // namespace

void __cdecl application_main_function_00412030() {
    if (read_u32(frame_control_ff_state_005e9408 + 0x04u) == 0u) {
        return;
    }

    // The original reloads the row index and signed 16-bit field for each call.
    release_from_current_row(0x04u);
    release_from_current_row(0x02u);
    release_from_current_row(0x00u);
    release_from_current_row(0x06u);
}

} // namespace porsche
