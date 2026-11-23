// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run753 replacement for accepted Run494 render_resource_494.cpp.
// Complete 0053c3d0/30B, 00533f80/50B and 005338d0/53B.
#include "../494-render-resource-leaves/render_resource_494.hpp"
#include "../688-frame-control-create-and-gain/input_ff_frame_control_688.hpp"
#include "porsche/window_shutdown.hpp"
#include "porsche/heap.hpp"

#include <cstring>

namespace porsche {
namespace {
using U = std::uint32_t;
using B = std::uint8_t;
U load(const void* p, U offset) {
    U value;
    std::memcpy(&value, static_cast<const B*>(p) + offset, 4);
    return value;
}
void store(void* p, U offset, U value) {
    std::memcpy(static_cast<B*>(p) + offset, &value, 4);
}
}

// No frame_control_slot_fields_494 storage is defined here. The original
// +0x80/+0x88/+0x8c cells are the corresponding Run688 FeEffectEntry fields.

U __cdecl render_resource_total_phys_0053c3d0() {
    U status[8]; // Original initializes only dwLength; the API owns the rest.
    status[0] = 32;
    render_resource_global_memory_status_005b2140(status);
    return status[2];
}
void __cdecl render_display_texture_reset_0053c3d0() {
    (void)render_resource_total_phys_0053c3d0();
}
U __cdecl render_resource_release_texture_00533f80(void* texture) {
    const U buffer = load(texture, 0x28);
    if (buffer != 0 && buffer == window_shutdown_config_005de620[10]) {
        window_shutdown_prepare_00534550();
    }
    auto* const bytes = static_cast<B*>(texture);
    bytes[0x0c] = 0;
    bytes[0x0d] = 0;
    store(texture, 0, 0x57494e6b);
    return free_00531f90(texture);
}
void __cdecl render_display_release_texture_00533f80(void* texture) {
    (void)render_resource_release_texture_00533f80(texture);
}
void __cdecl splash_progress_release_texture_00533f80(U texture) {
    (void)render_resource_release_texture_00533f80(reinterpret_cast<void*>(texture));
}
void __cdecl frame_control_slot_release_005338d0(std::int32_t slot) {
    if (slot < 0 || slot >= 32) {
        return;
    }
    FeEffectEntry& entry = frame_control_effects_0069cb10[slot];
    if (entry.input_slot_8c == -1) {
        return;
    }
    void* const effect = entry.effect_object_88;
    const U vtable = load(effect, 0);
    // Original indirect stdcall transport leaves ECX equal to the vtable.
    __asm {
        mov ecx, vtable
        push effect
        call dword ptr [ecx + 20h]
    }
    entry.field_80 = 0;
}
} // namespace porsche
