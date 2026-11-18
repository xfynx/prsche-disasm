// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "../494-render-resource-leaves/render_resource_494.hpp"
#include "porsche/fe_callbacks.hpp"
#include "porsche/heap.hpp"
#include "porsche/input_state.hpp"

namespace porsche {

// Owned zero-initialized .data/.bss scalar at 005e8e5c..005e8e5f (4B).
extern std::int32_t fe_input_device_count_005e8e5c;

// Original 00532b50..00532b7d (46B, __cdecl, ret 0; returns 0 or 1 in EAX).
std::uint32_t __cdecl input_slot_has_device_00532b50(std::int32_t index);

// Original 00533160..00533199 (58B, __cdecl, ret 0; returns HRESULT in EAX).
std::uint32_t __cdecl input_device_ff_command_00533160(
    InputDevice* device, std::uint32_t command);

// Original 00533480..005334d1 (82B, __cdecl, ret 0; void).
void __cdecl input_slot_stop_ff_00533480(std::int32_t index);

// Original 00532ff0..00533004 (21B, __cdecl, ret 0; void).
void __cdecl input_zero_memory_00532ff0(void* destination, std::uint32_t bytes);

// Original 004116d0..0041170d (62B, __cdecl, ret 0; returns bool in AL).
bool __cdecl fe_input_any_attached_004116d0();

// Original 00411710..00411752 (67B, __cdecl, ret 0; returns bool in AL).
bool __cdecl fe_input_device_attached_00411710(std::int32_t device_index);

} // namespace porsche
