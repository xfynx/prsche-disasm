// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 00532b50..00532b7d (46B), 00533160..00533199 (58B),
// 00533480..005334d1 (82B), 00532ff0..00533004 (21B),
// 004116d0..0041170d (62B), and 00411710..00411752 (67B).
#include "startup_input_slot_math_676.hpp"

#include <cstddef>

namespace porsche {

static_assert(sizeof(void*) == 4u, "original x86 layout requires 32-bit pointers");
static_assert(sizeof(InputSlot) == 0x10cu);
static_assert(offsetof(InputSlot, device) == 0x00u);
static_assert(offsetof(InputSlot, flags_04) == 0x04u);
static_assert(offsetof(InputVtable, acquire_1c) == 0x1cu);
static_assert(offsetof(InputVtable, other_28) + 12u * sizeof(void*) == 0x58u);

namespace {

using InputFfCommandFn = std::uint32_t(__stdcall*)(void*, std::uint32_t);

} // namespace

std::int32_t fe_input_device_count_005e8e5c = 0;

std::uint32_t __cdecl input_slot_has_device_00532b50(std::int32_t index) {
    if (index >= input_count_0069cb0c || index < 0 || index >= 32) {
        return 0u;
    }
    return input_slots_006be040[index].device != nullptr ? 1u : 0u;
}

std::uint32_t __cdecl input_device_ff_command_00533160(
    InputDevice* device, std::uint32_t command) {
    auto call_ff = [device, command]() -> std::uint32_t {
        const auto fn = reinterpret_cast<InputFfCommandFn>(device->vtable->other_28[12]);
        return fn(device, command);
    };

    std::uint32_t result = call_ff();
    if (result == 0x8007000cu || result == 0x8007001eu || result == 0x80040205u) {
        result = device->vtable->acquire_1c(device);
        if (result == 0u) {
            result = call_ff();
        }
    }
    return result;
}

void __cdecl input_slot_stop_ff_00533480(std::int32_t index) {
    if (input_slot_has_device_00532b50(index) == 0u) {
        return;
    }
    const InputSlot& slot = input_slots_006be040[index];
    if ((slot.flags_04 & 1u) == 0u) {
        return;
    }
    (void)input_device_ff_command_00533160(slot.device, 2u);
    for (std::size_t i = 0u; i < 32u; ++i) {
        frame_control_slot_fields_494[i].active = 0u;
    }
}

void __cdecl input_zero_memory_00532ff0(void* destination, std::uint32_t bytes) {
    heap_fill_0053c290(destination, 0u, bytes);
}

bool __cdecl fe_input_any_attached_004116d0() {
    for (std::int32_t i = 0; i < fe_input_device_count_005e8e5c && i < 32; ++i) {
        const std::int8_t device = fe_input_devices_005e8e60[i];
        if (device >= 0) {
            const auto* const caps = static_cast<const std::uint8_t*>(
                fe_input_getstate_00532e10(
                    static_cast<std::uint32_t>(static_cast<std::int32_t>(device)), 2u));
            if ((caps[4] & 2u) != 0u) {
                return true;
            }
        }
    }
    return false;
}

bool __cdecl fe_input_device_attached_00411710(std::int32_t device_index) {
    for (std::int32_t i = 0; i < fe_input_device_count_005e8e5c && i < 32; ++i) {
        const auto entry = static_cast<std::int32_t>(fe_input_devices_005e8e60[i]);
        if (entry == device_index) {
            const auto* const caps = static_cast<const std::uint8_t*>(
                fe_input_getstate_00532e10(static_cast<std::uint32_t>(entry), 2u));
            if ((caps[4] & 2u) != 0u) {
                return true;
            }
        }
    }
    return false;
}

} // namespace porsche
