// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "../676-startup-input-slot-and-math-leaves/startup_input_slot_math_676.hpp"
#include "../680-input-ff-slot-and-render-leaves/input_ff_slot_render_680.hpp"
#include "porsche/heap.hpp"
#include "porsche/input_state.hpp"

namespace porsche {

// One 0x90-byte force-effect record of the .bss array 0069cb10..0069dd0f.
// The record doubles as the original 0x34-byte effect descriptor passed to the
// device vtable entry at +0x48; +0x78..+0x87 holds the direction storage and
// bookkeeping, +0x88 the created effect object, +0x8c the owning input slot
// (-1 marks the record free).
struct FeEffectEntry {
    std::uint32_t size_00;              // descriptor size, always 0x34
    std::uint32_t flags_04;             // descriptor flags, always 0x22
    std::uint32_t duration_08;          // from params +0x34
    std::uint32_t sample_period_0c;     // always 0x7d0
    std::uint32_t gain_10;              // params +0x38 * 100
    std::uint32_t trigger_button_14;    // params +0x40, -1 kept, otherwise +0x30
    std::uint32_t trigger_repeat_18;    // params +0x44
    std::uint32_t axes_count_1c;        // 1 or 2, chosen by params +0x3c
    void* axes_20;                      // stack storage of axis ids
    void* directions_24;                // points at directions_78
    void* envelope_28;                  // always 0
    std::uint32_t type_bytes_2c;        // type-specific size from the switch
    void* type_params_30;               // points at type_specific_34
    std::uint8_t type_specific_34[0x30];
    std::uint8_t spare_64[0x14];
    std::int32_t direction_78;          // params +0x48 * 100, 0x2328 for type 8
    std::int32_t direction_7c;          // always 0
    std::uint32_t field_80;             // always 0
    std::uint32_t type_84;              // params +0x00
    void* effect_object_88;             // written by the +0x48 vtable entry
    std::int32_t input_slot_8c;         // owning input slot, -1 = free
};
static_assert(sizeof(FeEffectEntry) == 0x90u);
static_assert(offsetof(FeEffectEntry, type_specific_34) == 0x34u &&
              offsetof(FeEffectEntry, direction_78) == 0x78u &&
              offsetof(FeEffectEntry, effect_object_88) == 0x88u &&
              offsetof(FeEffectEntry, input_slot_8c) == 0x8cu);

// Effect request record built by the caller on its stack; only the fields
// below are read by 005334e0.
struct FeEffectParams {
    std::uint32_t type_00;              // effect type 0..12, selects guid/size
    std::uint8_t type_source_04[0x30];  // copied to type_specific_34
    std::uint32_t duration_34;
    std::uint32_t gain_38;
    std::uint32_t axes_3c;              // 1 -> {0}, 2 -> {4}, else {0, 4}
    std::uint32_t button_40;            // -1 kept, otherwise +0x30
    std::uint32_t repeat_44;
    std::uint32_t direction_48;
};
static_assert(sizeof(FeEffectParams) == 0x4cu);

// Gain request block built on the stack by 005333a0 and handed to the device
// vtable entry at +0x18.
struct FeGainProps {
    std::uint32_t size_00;              // 0x14
    std::uint32_t header_size_04;       // 0x10
    std::uint32_t object_08;            // 0
    std::uint32_t how_0c;               // 0 (device-wide)
    std::uint32_t gain_10;              // 0..10000
};

// Owned .rdata: twelve 16-byte effect GUIDs 005bf9d0..005bfa8f and the
// 13-entry pointer table 005bb3b0..005bb3cc (types 8 and 9 share one blob).
// 005334e0 is the only reader of both.
extern const std::uint8_t frame_control_effect_guids_005bf9d0[12][16];
extern const void* const frame_control_effect_guid_table_005bb3b0[13];

// Owned zero-initialized .bss effect array 0069cb10..0069dd0f (32 x 0x90).
extern FeEffectEntry frame_control_effects_0069cb10[32];

// Original 005333a0..0053347a (219B, __cdecl, ret 0; void).
// Unloads every loaded effect, sends the clamped gain block through the
// device vtable entry at +0x18 (stdcall, three 32-bit arguments), then
// re-downloads every loaded effect.
void __cdecl input_slot_set_ff_gain_005333a0(std::int32_t slot_index,
                                             std::int32_t gain);

// Original 005334e0..005336f3 (532B, __cdecl, ret 0; returns the claimed
// effect-record index 0..31 or -1).
std::int32_t __cdecl frame_control_slot_create_005334e0(
    std::int32_t slot_index, const FeEffectParams* params);

} // namespace porsche
