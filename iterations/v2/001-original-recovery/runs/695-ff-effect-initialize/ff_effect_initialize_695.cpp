// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 00411d20..00412020: 769 bytes, __cdecl, ret 0, void.
#include "ff_effect_initialize_695.hpp"

#include <cstddef>
#include <cstring>

namespace porsche {

// Single physical allocation of the 0x134-byte state block (loader zero).
std::uint8_t frame_control_ff_state_005e9408[0x134] = {};

std::uint32_t ff_init_gain_00657bc8 = 0u;
std::uint32_t ff_init_config_00657be8 = 0u;
std::uint32_t ff_init_config_00657c08 = 0u;
std::uint32_t ff_init_config_00657c28 = 0u;
std::uint32_t ff_init_config_00657c48 = 0u;

namespace {

constexpr std::size_t kDeviceOff = 0x00;   // 005e9408
constexpr std::size_t kEnabledOff = 0x04;  // 005e940c
constexpr std::size_t kIndexOff = 0x08;    // 005e9410
constexpr std::size_t kTableOff = 0x18;    // 005e9420 - 005e9408

inline std::uint32_t* u32_at(std::size_t off) {
    return reinterpret_cast<std::uint32_t*>(frame_control_ff_state_005e9408 + off);
}

inline FrameControlIndexTuple_400* word_table() {
    return reinterpret_cast<FrameControlIndexTuple_400*>(
        frame_control_ff_state_005e9408 + kTableOff);
}

inline void store_result_word(std::uint32_t slot, std::size_t index,
                              std::int32_t value) {
    reinterpret_cast<std::int16_t*>(&word_table()[slot])[index] =
        static_cast<std::int16_t>(value);
}

// 00411d20 leaves part of type_source_04 unwritten for effect types 0/3/4;
// the original then hands the whole 0x30-byte block to 005334e0. The native
// harness seeds the call stack deterministically with 0xcc on both sides, so
// this fill models that explicitly opaque region rather than inventing zero.
inline void seed_opaque_params(FeEffectParams& p) {
    std::memset(&p, 0xcc, sizeof p);
}

inline void set_source(FeEffectParams& p, std::size_t dword_index,
                       std::uint32_t value) {
    std::memcpy(p.type_source_04 + dword_index * 4u, &value, 4u);
}

// Original idiom: EDX = ((caps0 & 0xff00) - 0x600); NEG/SBB gives 0 when the
// subtraction is zero else -1; & 0xffffffa6; + 0x5a -> 0x5a or 0 (mod 2^32).
std::uint32_t effect_direction(const void* device) {
    const std::uint32_t caps0 = *static_cast<const std::uint32_t*>(device);
    const std::uint32_t diff = (caps0 & 0xff00u) - 0x600u;
    const std::uint32_t flag = (diff == 0u) ? 0u : 0xffffffffu;
    return (flag & 0xffffffa6u) + 0x5au;
}

} // namespace

void __cdecl ff_effect_initialize_00411d20() {
    input_zero_memory_00532ff0(frame_control_ff_state_005e9408, 0x134u);
    std::uint32_t* const words = reinterpret_cast<std::uint32_t*>(word_table());
    for (std::int32_t i = 0; i < 0x40; ++i) {
        words[i] = 0xffffffffu;
    }
    *u32_at(kEnabledOff) = 0u;

    if (!fe_input_any_attached_004116d0()) {
        return;
    }

    // First attached device with both FF capability bits at +4 that can be
    // enabled; the original keeps scanning after a successful claim (the last
    // matching slot wins), so the loop is not cut short here.
    for (std::int32_t slot = 0; slot < 32; ++slot) {
        if (!fe_input_device_attached_00411710(slot)) {
            continue;
        }
        void* const device = fe_input_getstate_00532e10(
            static_cast<std::uint32_t>(slot), 2u);
        if (device == nullptr) {
            continue;
        }
        const std::uint32_t caps = *reinterpret_cast<const std::uint32_t*>(
            static_cast<const std::uint8_t*>(device) + 4u);
        if ((caps & 2u) == 0u || (caps & 1u) == 0u) {
            continue;
        }
        if (input_slot_enable_ff_005330a0(slot) == 0u) {
            continue;
        }
        *u32_at(kIndexOff) = static_cast<std::uint32_t>(slot);
        *reinterpret_cast<void**>(frame_control_ff_state_005e9408 + kDeviceOff) = device;
        *u32_at(kEnabledOff) = 1u;
    }

    if (*u32_at(kEnabledOff) == 0u) {
        return;
    }

    const std::uint32_t selected = *u32_at(kIndexOff);
    // Effect 0: type 0, gain from 00657c28; only type-source dword 0 is written
    // by the original (the remaining 0x2c bytes are opaque stack).
    {
        void* const selected_device = fe_input_getstate_00532e10(selected, 2u);
        const std::uint32_t direction = effect_direction(selected_device);
        FeEffectParams p;
        seed_opaque_params(p);
        p.type_00 = 0u;
        set_source(p, 0u, 10000u);
        p.duration_34 = 0xffffffffu;
        p.gain_38 = ff_init_config_00657c28;
        p.axes_3c = 3u;
        p.button_40 = 0xffffffffu;
        p.repeat_44 = 0u;
        p.direction_48 = direction;
        store_result_word(selected, 0u,
            frame_control_slot_create_005334e0(static_cast<std::int32_t>(selected), &p));
    }

    // Effect 1: type 3, 0x72e4 period, gain from 00657be8.
    {
        void* const selected_device = fe_input_getstate_00532e10(selected, 2u);
        const std::uint32_t direction = effect_direction(selected_device);
        FeEffectParams p;
        seed_opaque_params(p);
        p.type_00 = 3u;
        set_source(p, 0u, 10000u);
        set_source(p, 1u, 0u);
        set_source(p, 2u, 0u);
        set_source(p, 3u, 0x72e4u);
        p.duration_34 = 0xffffffffu;
        p.gain_38 = ff_init_config_00657be8;
        p.axes_3c = 3u;
        p.button_40 = 0xffffffffu;
        p.repeat_44 = 0u;
        p.direction_48 = direction;
        store_result_word(selected, 1u,
            frame_control_slot_create_005334e0(static_cast<std::int32_t>(selected), &p));
    }

    // Effect 2: type 4, 0x186a0 period, gain from 00657c08.
    {
        void* const selected_device = fe_input_getstate_00532e10(selected, 2u);
        const std::uint32_t direction = effect_direction(selected_device);
        FeEffectParams p;
        seed_opaque_params(p);
        p.type_00 = 4u;
        set_source(p, 0u, 2000u);
        set_source(p, 1u, 0u);
        set_source(p, 2u, 0u);
        set_source(p, 3u, 100000u);
        p.duration_34 = 0xffffffffu;
        p.gain_38 = ff_init_config_00657c08;
        p.axes_3c = 3u;
        p.button_40 = 0xffffffffu;
        p.repeat_44 = 0u;
        p.direction_48 = direction;
        store_result_word(selected, 2u,
            frame_control_slot_create_005334e0(static_cast<std::int32_t>(selected), &p));
    }

    // Effect 3: type 9, fully specified 0x30-byte source block, gain 100 and
    // repeat from 00657c48.
    {
        void* const selected_device = fe_input_getstate_00532e10(selected, 2u);
        const std::uint32_t direction = effect_direction(selected_device);
        FeEffectParams p;
        seed_opaque_params(p);
        p.type_00 = 9u;
        set_source(p, 0u, 0u);
        set_source(p, 1u, 10000u);
        set_source(p, 2u, 10000u);
        set_source(p, 3u, 10000u);
        set_source(p, 4u, 10000u);
        set_source(p, 5u, 0u);
        set_source(p, 6u, 5000u);
        set_source(p, 7u, 10000u);
        set_source(p, 8u, 10000u);
        set_source(p, 9u, 10000u);
        set_source(p, 10u, 10000u);
        set_source(p, 11u, 0u);
        p.duration_34 = 0xffffffffu;
        p.gain_38 = 100u;
        p.axes_3c = 3u;
        p.button_40 = 0xffffffffu;
        p.repeat_44 = ff_init_config_00657c48;
        p.direction_48 = direction;
        store_result_word(selected, 3u,
            frame_control_slot_create_005334e0(static_cast<std::int32_t>(selected), &p));
    }

    if (*u32_at(kEnabledOff) == 0u) {
        return;
    }
    input_slot_set_ff_gain_005333a0(static_cast<std::int32_t>(selected),
                                    static_cast<std::int32_t>(ff_init_gain_00657bc8));
}

} // namespace porsche
