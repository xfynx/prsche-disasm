// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 005330a0..00533115 (118B), 00533320..0053335a (59B),
// 00533360..0053339a (59B), 00572f30..00572f5a (43B),
// 00572f5b..00572f8f (53B), 00570420..0057046b (76B),
// and 00570490..005704b1 (34B).
#include "input_ff_render_leaves_683.hpp"

#include <cstddef>

namespace porsche {

static_assert(sizeof(void*) == 4u, "original x86 layout requires 32-bit pointers");
static_assert(sizeof(InputSlot) == 0x10cu);
static_assert(offsetof(InputSlot, device) == 0x00u);
static_assert(offsetof(InputSlot, flags_04) == 0x04u);

void* input_directinput_0069cb08 = nullptr;

namespace {

void input_slot_send_ff_command(std::int32_t slot_index, std::uint32_t command) {
    if (input_slot_has_device_00532b50(slot_index) == 0u) {
        return;
    }
    const InputSlot& slot = input_slots_006be040[slot_index];
    if ((slot.flags_04 & 1u) == 0u) {
        return;
    }
    (void)input_device_ff_command_00533160(slot.device, command);
}

} // namespace

std::uint32_t __cdecl input_slot_enable_ff_005330a0(std::int32_t slot_index) {
    if (input_directinput_0069cb08 == nullptr) {
        return 0u;
    }
    if (input_slot_has_device_00532b50(slot_index) == 0u) {
        return 0u;
    }
    const auto* const caps = static_cast<const std::uint8_t*>(
        fe_input_getstate_00532e10(static_cast<std::uint32_t>(slot_index), 2u));
    if ((caps[4] & 2u) == 0u) {
        return 0u;
    }
    InputSlot& slot = input_slots_006be040[slot_index];
    if ((slot.flags_04 & 1u) != 0u) {
        return 0u;
    }
    if (input_slot_reset_ff_00533120(slot_index) != 0u) {
        return 0u;
    }
    slot.flags_04 |= 1u;
    return 1u;
}

void __cdecl input_slot_pause_ff_00533320(std::int32_t slot_index) {
    input_slot_send_ff_command(slot_index, 0x10u);
}

void __cdecl input_slot_continue_ff_00533360(std::int32_t slot_index) {
    input_slot_send_ff_command(slot_index, 0x20u);
}

std::uint32_t __cdecl render_color_888_to_565_00572f30(std::uint32_t color) {
    return ((color & 0x00f80000u) >> 8) |
           ((color & 0x0000fc00u) >> 5) |
           ((color >> 3) & 0x1fu);
}

std::uint32_t __cdecl render_color_888_to_1555_00572f5b(std::uint32_t color) {
    if (color == 0u) {
        return 0u;
    }
    return 0x8000u |
           ((color & 0x00f80000u) >> 9) |
           ((color & 0x0000f800u) >> 6) |
           ((color >> 3) & 0x1fu);
}

void __cdecl render_palette_555_to_565_00570420(
    std::uint16_t* dst, const std::uint16_t* src, std::int32_t count) {
    for (std::int32_t i = 0; i < count; ++i) {
        const std::uint32_t v = src[i];
        const std::uint32_t g5 = (v >> 5) & 0x1fu;
        const std::uint32_t g6 = (g5 << 1) | (g5 >> 4);
        const std::uint32_t r5 = (v & 0x7c00u) << 1;
        const std::uint32_t b5 = v & 0x1fu;
        dst[i] = static_cast<std::uint16_t>(r5 | (g6 << 5) | b5);
    }
}

void __cdecl render_palette_copy_strided16_00570490(
    std::uint16_t* dst, const std::uint16_t* src, std::int32_t count) {
    for (std::int32_t i = 0; i < count; ++i) {
        *dst++ = *src;
        src += 2;
    }
}

} // namespace porsche
