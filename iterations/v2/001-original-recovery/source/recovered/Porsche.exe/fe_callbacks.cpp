#include "porsche/fe_callbacks.hpp"
#include "porsche/fe_stream.hpp"

namespace porsche {
std::int8_t fe_input_devices_005e8e60[32];
static_assert(0x94 + 32 <= 0x21e);
std::uint32_t* const fe_input_masks_005e9380 = fe_action_state_005e9130 + 0x94;

// The three callbacks share the 0x00411a1c/0x00411a99/0x00411b59 scan.
// A negative signed byte terminates the list; an existing index is overwritten.
static void record_if_present(std::uint32_t index) {
    if (!fe_input_getstate_00532e10(index, 6)) return;
    for (std::uint32_t slot = 0; slot < 32; ++slot) {
        const auto old = fe_input_devices_005e8e60[slot];
        if (old < 0 || static_cast<std::uint32_t>(old) == index) {
            fe_input_devices_005e8e60[slot] = static_cast<std::int8_t>(index);
            return;
        }
    }
}

std::uint32_t __cdecl callback_004119e0(std::int32_t packed) {
    const auto bits = static_cast<std::uint32_t>(packed);
    const auto index = bits >> 16;
    if (index < 32) fe_input_masks_005e9380[index] &= ~(1u << (bits & 31));
    record_if_present(index);
    return 0;
}

std::uint32_t __cdecl callback_00411a80(std::int32_t packed) {
    record_if_present(static_cast<std::uint32_t>(packed) >> 16);
    return 0;
}

std::uint32_t __cdecl callback_00411b40(std::int32_t packed) {
    record_if_present(static_cast<std::uint32_t>(packed) >> 20);
    return 0;
}
}
