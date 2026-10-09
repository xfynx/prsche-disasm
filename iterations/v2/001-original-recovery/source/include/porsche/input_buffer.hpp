#pragma once
#include <cstdint>

namespace porsche {
struct InputBufferProperty {
    std::uint32_t size_00;
    std::uint32_t header_size_04;
    std::uint32_t object_08;
    std::uint32_t how_0c;
    std::uint32_t value_10;
};
static_assert(sizeof(InputBufferProperty) == 0x14);
using InputGetProperty = std::uint32_t (__stdcall*)(void*, std::uint32_t, InputBufferProperty*);
using InputGetCapabilities = std::uint32_t (__stdcall*)(void*, void*);
struct InputBufferVtable {
    void* other_00[5];
    InputGetProperty get_property_14;
    void* other_18[9];
    InputGetCapabilities get_capabilities_3c;
};
static_assert(sizeof(InputBufferVtable) == 0x40);
struct InputBufferDevice { InputBufferVtable* vtable; };

std::uint32_t __cdecl input_property_mode8_0056fff0(InputBufferDevice* device);
// Only the capabilities-failure exit is recovered; success must cross the
// explicit probe boundary until the 0x56fdf9..0x56ff7e loops are traced.
std::uint32_t __cdecl input_caps_0056fdb0(InputBufferDevice* device, void* output_21c);
std::uint32_t __cdecl input_caps_success_unrecovered_0056fdf9(
    InputBufferDevice* device, void* output_21c, const void* capabilities_244);
}
