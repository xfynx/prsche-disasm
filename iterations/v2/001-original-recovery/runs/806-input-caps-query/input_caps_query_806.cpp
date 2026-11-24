// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original continuation 0056fdf9..0056ff8c (404B) inside 0056fdb0..0056ff8c (477B).
#include "input_caps_query_806.hpp"

#include <cstring>

namespace porsche {

static_assert(sizeof(void*) == 4u, "original x86 layout requires 32-bit pointers");

const std::uint32_t input_axis_offsets_005dfa20[8] = {
    0x00u, 0x04u, 0x08u, 0x0cu, 0x10u, 0x14u, 0x18u, 0x1cu,
};

namespace {

std::uint32_t read_u32(const void* base, std::size_t offset) {
    std::uint32_t value = 0u;
    std::memcpy(&value, static_cast<const std::uint8_t*>(base) + offset, sizeof(value));
    return value;
}

void write_u32(void* base, std::size_t offset, std::uint32_t value) {
    std::memcpy(static_cast<std::uint8_t*>(base) + offset, &value, sizeof(value));
}

void or_u32(void* base, std::size_t offset, std::uint32_t bit_mask) {
    write_u32(base, offset, read_u32(base, offset) | bit_mask);
}

using GetDevCapsFn = std::uint32_t(__stdcall*)(void*, void*);
using GetObjectInfoFn = std::uint32_t(__stdcall*)(
    void*, void*, std::uint32_t, std::uint32_t);

} // namespace

std::uint32_t __cdecl input_caps_success_unrecovered_0056fdf9(
    InputBufferDevice* device, void* output_21c, const void* capabilities_244) {
    auto* const out = static_cast<std::uint8_t*>(output_21c);
    const auto* const caps = static_cast<const std::uint8_t*>(capabilities_244);

    write_u32(out, 0x00u, read_u32(caps, 0x24u));
    std::strncpy(reinterpret_cast<char*>(out + 0x14u),
                 reinterpret_cast<const char*>(caps + 0x28u), 0x103u);
    std::strncpy(reinterpret_cast<char*>(out + 0x118u),
                 reinterpret_cast<const char*>(caps + 0x12cu), 0x103u);

    auto* const vtable = *reinterpret_cast<void* const* const*>(device);
    const auto get_dev_caps = reinterpret_cast<GetDevCapsFn>(vtable[3]);
    const auto get_object_info = reinterpret_cast<GetObjectInfoFn>(vtable[14]);

    std::uint8_t dev_caps[0x2cu]{};
    write_u32(dev_caps, 0x00u, 0x2cu);
    const std::uint32_t caps_hr = get_dev_caps(device, dev_caps);
    if (caps_hr != 0u) {
        return caps_hr;
    }

    const std::uint32_t dev_flags = read_u32(dev_caps, 0x04u);
    std::uint32_t out_flags = read_u32(out, 0x04u) & 0xfffffffcu;
    out_flags |= (dev_flags & 1u);
    out_flags |= (dev_flags >> 7u) & 2u;
    write_u32(out, 0x04u, out_flags);

    std::uint8_t obj_info[0x13cu]{};
    write_u32(obj_info, 0x00u, 0x13cu);

    const std::uint32_t button_count = read_u32(dev_caps, 0x10u);
    const std::uint32_t dev_kind = read_u32(out, 0x00u) & 0xffu;
    std::uint32_t found_buttons = 0u;
    for (std::uint32_t idx = 0u; found_buttons < button_count && idx < 0x20u; ++idx) {
        bool present = true;
        if (dev_kind == 2u) {
            present = (get_object_info(device, obj_info, idx + 0x0cu, 1u) == 0u);
        } else if (dev_kind == 4u) {
            present = (get_object_info(device, obj_info, idx + 0x30u, 1u) == 0u);
        }
        if (present) {
            or_u32(out, 0x0cu, 1u << idx);
            ++found_buttons;
        }
    }

    const std::uint32_t axis_count = read_u32(dev_caps, 0x0cu);
    std::uint32_t found_axes = 0u;
    for (std::uint32_t idx = 0u; found_axes < axis_count && idx < 8u; ++idx) {
        if (get_object_info(device, obj_info, input_axis_offsets_005dfa20[idx], 1u) == 0u) {
            or_u32(out, 0x08u, 1u << idx);
            ++found_axes;
        }
    }

    const std::uint32_t pov_count = read_u32(dev_caps, 0x14u);
    std::uint32_t found_povs = 0u;
    for (std::uint32_t idx = 0u; found_povs < pov_count && idx < 4u; ++idx) {
        if (get_object_info(device, obj_info, 0x20u + idx * 4u, 1u) == 0u) {
            or_u32(out, 0x10u, 1u << idx);
            ++found_povs;
        }
    }

    return caps_hr;
}

} // namespace porsche
