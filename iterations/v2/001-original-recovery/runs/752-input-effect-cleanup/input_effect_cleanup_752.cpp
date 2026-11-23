// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 00533050..0053309a (75B).
#include "input_effect_cleanup_752.hpp"

#include "../676-startup-input-slot-and-math-leaves/startup_input_slot_math_676.hpp"
#include "../688-frame-control-create-and-gain/input_ff_frame_control_688.hpp"

#include <cstddef>

namespace porsche {

std::uint32_t input_effects_initialized_0069dd10 = 0u;

namespace {

using EffectReleaseFn = std::uint32_t(__stdcall*)(void* effect);

struct EffectObject {
    void** vtable;
};

static_assert(sizeof(void*) == 4u, "original x86 layout requires 32-bit pointers");
static_assert(offsetof(FeEffectEntry, effect_object_88) == 0x88u);
static_assert(offsetof(FeEffectEntry, input_slot_8c) == 0x8cu);

} // namespace

void __cdecl input_effect_cleanup_00533050() {
    if (input_effects_initialized_0069dd10 == 0u) {
        return;
    }

    for (std::int32_t i = 0; i < 32; ++i) {
        FeEffectEntry& entry = frame_control_effects_0069cb10[i];
        if (entry.input_slot_8c != -1) {
            auto* const effect = static_cast<EffectObject*>(entry.effect_object_88);
            reinterpret_cast<EffectReleaseFn>(effect->vtable[2])(effect);
        }
    }

    for (std::int32_t i = 0; i < 32; ++i) {
        if (input_slot_has_device_00532b50(i) != 0u) {
            input_slot_effect_cleanup_005331a0(i);
        }
    }
}

} // namespace porsche
