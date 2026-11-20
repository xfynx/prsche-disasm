// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 005333a0..0053347a (219B) and 005334e0..005336f3 (532B).
#include "input_ff_frame_control_688.hpp"

#include <cstddef>

namespace porsche {

// Owned .rdata 005bf9d0..005bfa8f: the twelve contiguous 16-byte effect GUID
// blobs {13541C20..13541C2B-38E8...} in original image order (bytes extracted
// from the pinned PE). The first blob is {13541C20-38E8-11D0-9AD0-00A0C9A06E35}.
const std::uint8_t frame_control_effect_guids_005bf9d0[12][16] = {
    {0x20, 0x1c, 0x54, 0x13, 0x38, 0x8e, 0xd0, 0x11,
     0x9a, 0xd0, 0x00, 0xa0, 0xc9, 0xa0, 0x6e, 0x35},
    {0x21, 0x1c, 0x54, 0x13, 0x38, 0x8e, 0xd0, 0x11,
     0x9a, 0xd0, 0x00, 0xa0, 0xc9, 0xa0, 0x6e, 0x35},
    {0x22, 0x1c, 0x54, 0x13, 0x38, 0x8e, 0xd0, 0x11,
     0x9a, 0xd0, 0x00, 0xa0, 0xc9, 0xa0, 0x6e, 0x35},
    {0x23, 0x1c, 0x54, 0x13, 0x38, 0x8e, 0xd0, 0x11,
     0x9a, 0xd0, 0x00, 0xa0, 0xc9, 0xa0, 0x6e, 0x35},
    {0x24, 0x1c, 0x54, 0x13, 0x38, 0x8e, 0xd0, 0x11,
     0x9a, 0xd0, 0x00, 0xa0, 0xc9, 0xa0, 0x6e, 0x35},
    {0x25, 0x1c, 0x54, 0x13, 0x38, 0x8e, 0xd0, 0x11,
     0x9a, 0xd0, 0x00, 0xa0, 0xc9, 0xa0, 0x6e, 0x35},
    {0x26, 0x1c, 0x54, 0x13, 0x38, 0x8e, 0xd0, 0x11,
     0x9a, 0xd0, 0x00, 0xa0, 0xc9, 0xa0, 0x6e, 0x35},
    {0x27, 0x1c, 0x54, 0x13, 0x38, 0x8e, 0xd0, 0x11,
     0x9a, 0xd0, 0x00, 0xa0, 0xc9, 0xa0, 0x6e, 0x35},
    {0x28, 0x1c, 0x54, 0x13, 0x38, 0x8e, 0xd0, 0x11,
     0x9a, 0xd0, 0x00, 0xa0, 0xc9, 0xa0, 0x6e, 0x35},
    {0x29, 0x1c, 0x54, 0x13, 0x38, 0x8e, 0xd0, 0x11,
     0x9a, 0xd0, 0x00, 0xa0, 0xc9, 0xa0, 0x6e, 0x35},
    {0x2a, 0x1c, 0x54, 0x13, 0x38, 0x8e, 0xd0, 0x11,
     0x9a, 0xd0, 0x00, 0xa0, 0xc9, 0xa0, 0x6e, 0x35},
    {0x2b, 0x1c, 0x54, 0x13, 0x38, 0x8e, 0xd0, 0x11,
     0x9a, 0xd0, 0x00, 0xa0, 0xc9, 0xa0, 0x6e, 0x35},
};

// Owned .rdata 005bb3b0..005bb3cc: the 13-entry pointer table. Types 8 and 9
// both address the blob at 005bfa40; type 2 addresses the last blob
// 005bfa80. Only 005334e0 reads the table.
const void* const frame_control_effect_guid_table_005bb3b0[13] = {
    frame_control_effect_guids_005bf9d0[0],
    frame_control_effect_guids_005bf9d0[1],
    frame_control_effect_guids_005bf9d0[11],
    frame_control_effect_guids_005bf9d0[2],
    frame_control_effect_guids_005bf9d0[3],
    frame_control_effect_guids_005bf9d0[4],
    frame_control_effect_guids_005bf9d0[5],
    frame_control_effect_guids_005bf9d0[6],
    frame_control_effect_guids_005bf9d0[7],
    frame_control_effect_guids_005bf9d0[7],
    frame_control_effect_guids_005bf9d0[8],
    frame_control_effect_guids_005bf9d0[9],
    frame_control_effect_guids_005bf9d0[10],
};

// Owned zero-initialized .bss 0069cb10..0069dd0f (32 x 0x90 bytes).
FeEffectEntry frame_control_effects_0069cb10[32] = {};

namespace {

// The device object's vtable entries used here. The stdcall cleanup of the
// original CALL sites (no ADD ESP after CALL [EDX+0x18] / CALL [EBX+0x48])
// pins the convention; the interface identity behind the vtable stays an
// unproved boundary, so only the raw entry offsets are used.
using FeSetPropertyFn = std::uint32_t(__stdcall*)(void* device,
                                                  std::uint32_t block_id,
                                                  void* block);
using FeCreateEffectFn = std::uint32_t(__stdcall*)(void* device,
                                                   const void* guid,
                                                   void* descriptor,
                                                   void** out_effect,
                                                   void* outer);

const void* const* device_vtable_words(const InputDevice* device) {
    return reinterpret_cast<const void* const*>(device->vtable);
}

} // namespace

void __cdecl input_slot_set_ff_gain_005333a0(std::int32_t slot_index,
                                             std::int32_t gain) {
    if (input_slot_has_device_00532b50(slot_index) == 0u) {
        return;
    }
    if ((input_slots_006be040[slot_index].flags_04 & 1u) == 0u) {
        return;
    }
    FeGainProps props;
    props.size_00 = 0x14u;
    props.header_size_04 = 0x10u;
    props.object_08 = 0u;
    props.how_0c = 0u;
    if (gain > 100) {
        props.gain_10 = 10000u;
    } else if (gain < 0) {
        props.gain_10 = 0u;
    } else {
        props.gain_10 = static_cast<std::uint32_t>(gain) * 100u;
    }
    for (std::int32_t i = 0; i < 32; ++i) {
        if (frame_control_effects_0069cb10[i].input_slot_8c != -1) {
            frame_control_slot_unload_005337e0(i);
        }
    }
    auto* const device = input_slots_006be040[slot_index].device;
    reinterpret_cast<FeSetPropertyFn>(device_vtable_words(device)[6])(
        device, 7u, &props);
    for (std::int32_t i = 0; i < 32; ++i) {
        if (frame_control_effects_0069cb10[i].input_slot_8c != -1) {
            frame_control_slot_download_00533760(i);
        }
    }
}

std::int32_t __cdecl frame_control_slot_create_005334e0(
    std::int32_t slot_index, const FeEffectParams* params) {
    const std::int32_t record = frame_control_slot_find_free_00533730();
    if (record == -1) {
        return -1;
    }
    if (input_slot_has_device_00532b50(slot_index) == 0u) {
        return -1;
    }
    if ((input_slots_006be040[slot_index].flags_04 & 1u) == 0u) {
        return -1;
    }
    FeEffectEntry& entry = frame_control_effects_0069cb10[record];
    std::uint32_t duration = params->duration_34;
    if (duration == 0xffffffffu) {
        duration |= duration; // original 00533539..00533540 keeps -1 as-is
    }
    entry.duration_08 = duration;
    entry.gain_10 = params->gain_38 * 100u;
    entry.trigger_button_14 = (params->button_40 == 0xffffffffu)
                                  ? params->button_40
                                  : params->button_40 + 0x30u;
    entry.trigger_repeat_18 = params->repeat_44;
    entry.direction_78 = static_cast<std::int32_t>(
        static_cast<std::uint32_t>(params->direction_48) * 100u);
    std::uint32_t axes[2];
    if (params->axes_3c == 1u) {
        entry.axes_count_1c = 1u;
        entry.axes_20 = axes;
        axes[0] = 0u;
    } else if (params->axes_3c == 2u) {
        entry.axes_count_1c = 1u;
        entry.axes_20 = axes;
        axes[0] = 4u;
    } else {
        entry.axes_count_1c = 2u;
        entry.axes_20 = axes;
        axes[0] = 0u;
        axes[1] = 4u;
    }
    heap_copy_dispatch_005323e0(entry.type_specific_34, params->type_source_04,
                                0x30u);
    entry.size_00 = 0x34u;
    entry.flags_04 = 0x22u;
    entry.sample_period_0c = 0x7d0u;
    entry.directions_24 = &entry.direction_78;
    entry.type_params_30 = &entry.type_specific_34;
    entry.direction_7c = 0;
    entry.envelope_28 = nullptr;
    entry.field_80 = 0u;
    entry.type_84 = params->type_00;
    entry.input_slot_8c = slot_index;
    if (params->type_00 > 12u) {
        return -1;
    }
    // Switch table 005336f4 (13 dwords, raw PE): type 0 -> 4, type 1 -> 8,
    // types 2..6 -> 0x10, type 7 and types 9..12 -> 0x18, type 8 -> 0x30 with
    // direction 0x2328.
    switch (params->type_00) {
    case 0u:
        entry.type_bytes_2c = 4u;
        break;
    case 1u:
        entry.type_bytes_2c = 8u;
        break;
    case 2u:
    case 3u:
    case 4u:
    case 5u:
    case 6u:
        entry.type_bytes_2c = 0x10u;
        break;
    case 7u:
    case 9u:
    case 10u:
    case 11u:
    case 12u:
        entry.type_bytes_2c = 0x18u;
        break;
    case 8u:
        entry.type_bytes_2c = 0x30u;
        entry.direction_78 = 0x2328;
        break;
    }
    auto* const device = input_slots_006be040[slot_index].device;
    const auto created = reinterpret_cast<FeCreateEffectFn>(
        device_vtable_words(device)[0x48u / 4u])(
        device, frame_control_effect_guid_table_005bb3b0[params->type_00],
        &entry, &entry.effect_object_88, nullptr);
    if (created != 0u) {
        return -1;
    }
    frame_control_slot_unload_005337e0(record);
    return record;
}

} // namespace porsche
