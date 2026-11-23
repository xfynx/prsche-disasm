// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 005331a0..005331eb (76B) and 00465df0..00465e15 (38B).
#include "input_effect_slot_render_misc_775.hpp"

namespace porsche {

void __cdecl input_slot_effect_cleanup_005331a0(std::int32_t slot_index) {
    if (input_directinput_0069cb08 == nullptr) {
        return;
    }
    if (input_slot_has_device_00532b50(slot_index) == 0u) {
        return;
    }
    if ((input_slots_006be040[slot_index].flags_04 & 1u) == 0u) {
        return;
    }
    input_slot_reset_ff_00533120(slot_index);
    input_slots_006be040[slot_index].flags_04 &= ~1u;
}

void __cdecl render_misc_00465df0() {
    void* const object = startup_network_allocate_0059ef90(0x4cu);
    if (object != nullptr) {
        render_secondary_object_0062810c = scene_stage_group_ctor_0059f070(object, nullptr);
    } else {
        render_secondary_object_0062810c = nullptr;
    }
}

} // namespace porsche
