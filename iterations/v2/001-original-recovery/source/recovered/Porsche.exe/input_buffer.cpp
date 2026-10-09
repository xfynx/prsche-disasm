#include "porsche/input_buffer.hpp"
#include <cstring>

namespace porsche {
std::uint32_t __cdecl input_property_mode8_0056fff0(InputBufferDevice* device) {
    InputBufferProperty property{0x14u, 0x10u, 0u, 0u, 0u};
    const auto result = device->vtable->get_property_14(device, 2u, &property);
    if (result != 0) return 0;
    if (property.value_10 == 0) return 2;
    if (property.value_10 == 1) return 3;
    return 0;
}

std::uint32_t __cdecl input_caps_0056fdb0(InputBufferDevice* device, void* output_21c) {
    std::memset(output_21c, 0, 0x21c);
    alignas(std::uint32_t) std::uint8_t caps[0x244]{};
    *reinterpret_cast<std::uint32_t*>(caps) = 0x244;
    const auto result = device->vtable->get_capabilities_3c(device, caps);
    if (result != 0) return result;
    return input_caps_success_unrecovered_0056fdf9(device, output_21c, caps);
}
}
