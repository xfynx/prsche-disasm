#include "porsche/input_state.hpp"

namespace porsche {
std::int32_t input_count_0069cb0c;
InputSlot input_slots_006be040[32];

static bool lost(std::uint32_t result) {
    return result == 0x8007000cu || result == 0x8007001eu;
}

std::uint32_t __cdecl input_poll_0056fd00(InputDevice* device) {
    auto result = device->vtable->poll_64(device);
    if (lost(result)) {
        result = device->vtable->acquire_1c(device);
        if (result == 0) result = device->vtable->poll_64(device);
    }
    return result;
}

std::uint32_t __cdecl input_read_0056fd30(InputDevice* device, std::uint32_t size, void* destination) {
    auto result = device->vtable->get_state_24(device, size, destination);
    if (lost(result)) {
        result = device->vtable->acquire_1c(device);
        if (result == 0) result = device->vtable->get_state_24(device, size, destination);
    }
    return result;
}

std::uint32_t __cdecl input_poll_read_0056fce0(InputDevice* device, void* destination, std::uint32_t size) {
    input_poll_0056fd00(device);
    return input_read_0056fd30(device, size, destination);
}

void* __cdecl fe_input_getstate_00532e10(std::uint32_t raw_index, std::uint32_t mode) {
    const auto index = static_cast<std::int32_t>(raw_index);
    if (index >= input_count_0069cb0c) return nullptr;
    // The original signed compare admits negative indices and reads before
    // 0x006be040. That adjacent memory is outside this bounded slot unit.
    if (index < 0) return input_negative_index_00532e10(index, mode);
    if (index >= 32) return input_unmapped_index_00532e10(raw_index, mode);
    auto& slot = input_slots_006be040[index];
    if (!slot.device) return nullptr;
    if (mode != 6) return input_unrecovered_mode_00532e10(raw_index, mode, &slot);
    std::uint32_t size;
    switch (slot.type_08 & 0xffu) {
    case 1: case 4: size = 0x50; break;
    case 2: size = 0x10; break;
    case 3: size = 0x100; break;
    default: input_invalid_type_00532eae(slot.type_08 & 0xffu); return nullptr;
    }
    input_poll_read_0056fce0(slot.device, slot.state_0c, size);
    return &slot.type_08;
}
}
