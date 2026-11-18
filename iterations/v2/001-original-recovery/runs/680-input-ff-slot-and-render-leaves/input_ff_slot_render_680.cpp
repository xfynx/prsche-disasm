// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 005337a0..005337d5 (54B), 005337e0..00533808 (41B),
// 00533730..00533757 (40B), 00533760..0053379f (64B),
// 00533120..0053315b (60B), and 00574080..0057409c (29B).
#include "input_ff_slot_render_680.hpp"

#include <cstddef>

namespace porsche {

namespace {

using EffectMethodFn = std::uint32_t(__stdcall*)(void*);

struct EffectVtable {
    void* other_00[10];
    EffectMethodFn download_28;
    EffectMethodFn unload_2c;
};

struct EffectObject {
    EffectVtable* vtable;
};

} // namespace

static_assert(sizeof(void*) == 4u, "original x86 layout requires 32-bit pointers");
static_assert(offsetof(EffectVtable, download_28) == 0x28u);
static_assert(offsetof(EffectVtable, unload_2c) == 0x2cu);
static_assert(sizeof(InputSlot) == 0x10cu);
static_assert(offsetof(InputSlot, device) == 0x00u);
static_assert(offsetof(InputVtable, acquire_1c) == 0x1cu);
static_assert(sizeof(FrameControlSlotFields_494) == 12u);
static_assert(offsetof(FrameControlSlotFields_494, device) == 4u);
static_assert(offsetof(FrameControlSlotFields_494, state) == 8u);
static_assert(sizeof(window_shutdown_config_005de620) == 48u);

std::uint32_t __cdecl input_effect_download_005337a0(
    InputDevice* device, void* effect) {
    auto* const fx = static_cast<EffectObject*>(effect);
    auto call_download = [fx]() -> std::uint32_t {
        const auto fn = fx->vtable->download_28;
        return fn(fx);
    };

    std::uint32_t result = call_download();
    if (result == 0x8007000cu || result == 0x8007001eu || result == 0x80040205u) {
        result = device->vtable->acquire_1c(device);
        if (result == 0u) {
            result = call_download();
        }
    }
    return result;
}

void __cdecl frame_control_slot_unload_005337e0(std::int32_t slot) {
    if (slot < 0 || slot >= 32) {
        return;
    }
    const FrameControlSlotFields_494& entry = frame_control_slot_fields_494[slot];
    if (entry.state == 0xffffffffu) {
        return;
    }
    auto* const fx = reinterpret_cast<EffectObject*>(
        static_cast<std::uintptr_t>(entry.device));
    (void)fx->vtable->unload_2c(fx);
}

std::int32_t __cdecl frame_control_slot_find_free_00533730() {
    for (std::int32_t i = 0; i < 32; ++i) {
        if (frame_control_slot_fields_494[i].state == 0xffffffffu) {
            return i;
        }
    }
    return -1;
}

void __cdecl frame_control_slot_download_00533760(std::int32_t slot) {
    if (slot < 0 || slot >= 32) {
        return;
    }
    const FrameControlSlotFields_494& entry = frame_control_slot_fields_494[slot];
    if (entry.state == 0xffffffffu) {
        return;
    }
    (void)input_effect_download_005337a0(
        input_slots_006be040[entry.state].device,
        reinterpret_cast<void*>(static_cast<std::uintptr_t>(entry.device)));
}

std::uint32_t __cdecl input_slot_reset_ff_00533120(std::int32_t slot_index) {
    const auto target_state = static_cast<std::uint32_t>(slot_index);
    for (std::size_t i = 0u; i < 32u; ++i) {
        if (frame_control_slot_fields_494[i].state == target_state) {
            frame_control_slot_fields_494[i].state = 0xffffffffu;
        }
    }
    return input_device_ff_command_00533160(
        input_slots_006be040[slot_index].device, 1u);
}

std::int32_t __cdecl render_pixel_offset_00574080(std::int32_t x, std::int32_t y) {
    const std::uint32_t bpp =
        reinterpret_cast<const std::uint8_t*>(window_shutdown_config_005de620)[0x0eu];
    const std::uint32_t pitch = window_shutdown_config_005de620[9];
    const std::int32_t x_bytes =
        static_cast<std::int32_t>(bpp * static_cast<std::uint32_t>(x)) >> 3;
    const std::uint32_t y_bytes = pitch * static_cast<std::uint32_t>(y);
    return static_cast<std::int32_t>(static_cast<std::uint32_t>(x_bytes) + y_bytes);
}

} // namespace porsche
