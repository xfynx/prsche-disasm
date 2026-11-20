// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run693: recovered bodies 004640b0 (564B), 00467740 (141B), 00468fb0 (236B).
//
// Original body SHA-256:
//   004640b0 14afbbc2ec3ef1ab4aba97bb216f197bb2ad658f03569ee6f9bd57b4c2bdb4c4
//   00467740 20ef52a859d751ea47f188295a3c4e7b5b737b1b7adda77dc5ab6554a711d9f9
//   00468fb0 3b7479d88e11277e59210d4b69afc8258fe2982bee5a325343696962509ec7fd
#include "application_view_lifecycle_693.hpp"

#include "porsche/application_alloc.hpp"
#include "porsche/application_main.hpp"
#include "porsche/application_state.hpp"
#include "porsche/formatter_search.hpp"
#include "render_buffer_523.hpp"
#include "porsche/render_display.hpp"
#include "porsche/render_mode.hpp"
#include "porsche/render_startup.hpp"
#include "porsche/splash_progress.hpp"
#include "porsche/startup_sequence.hpp"
#include "porsche/startup_service_516950.hpp"

#include <cstddef>
#include <cstring>

namespace porsche {

std::uint8_t view_slot_table_00627e80[0x218u] = {};
void* route_object_registry_table_005e8c00[9u] = {};
std::uint32_t view_setup_camera_005cf620[3u] = {0x00000000u, 0x3ecccccdu,
                                                0x3f666666u};
std::uint32_t view_route_flag_005cf584 = 1u;
std::uint8_t view_route_string_005cf5d8 = 2u;
char view_castle_string_005cf760[7u] = {'c', 'a', 's', 't', 'l', 'e', '\0'};
void* scene_buffer_0062814c = nullptr;
void* scene_transfer_state_0061976c = nullptr;
std::uint8_t scene_flag_00619800 = 0u;

namespace {
using U = std::uint32_t;
using B = std::uint8_t;

U load_dword(const void* base, std::size_t offset) {
    U value;
    std::memcpy(&value, static_cast<const B*>(base) + offset, sizeof value);
    return value;
}

void store_dword(void* base, std::size_t offset, U value) {
    std::memcpy(static_cast<B*>(base) + offset, &value, sizeof value);
}

void store_word16(void* base, std::size_t offset, std::uint16_t value) {
    std::memcpy(static_cast<B*>(base) + offset, &value, sizeof value);
}

void* pointer_of(U value) {
    return reinterpret_cast<void*>(static_cast<std::uintptr_t>(value));
}

U value_of(const void* pointer) {
    return static_cast<U>(reinterpret_cast<std::uintptr_t>(pointer));
}

// The original dispatches display-device slot zero and core slot one as
// this-in-ECX stdcall calls with one pushed argument (PUSH 1). The fastcall
// form transports ECX through the first argument and leaves the single stack
// argument, matching the callee's RET 4 stack cleanup.
using SlotCall = void (__fastcall*)(void* self, void* unused_edx,
                                    std::uint32_t argument);
} // namespace

// 004640b0..004642e3. Initializes the one or two 0x10c-byte view slots from
// the selected route object, then binds the projection pair and the route
// probe result. The original re-reads the state word, the registry cell and
// the route string byte every iteration; opaque callee calls sit between the
// re-reads, so each access is reissued.
void __cdecl application_main_function_004640b0() {
    // Original frame service object: 00473100 writes +0x00..+0x2f and
    // 00473190 later copies it into the slot tail at +0xdc..+0x10b.
    B service_object[0x30u];
    view_slot_service_00473100(service_object, nullptr, 0u);

    const U extra =
        (application_state_006573e8.word(0x00657404u) == 1u) ? 1u : 0u;
    std::int32_t index = 0;
    for (;;) {
        const U selected = application_state_006573e8.word(0x0065741cu);
        const B* const route_object =
            static_cast<const B*>(route_object_registry_table_005e8c00[selected]);
        B* const slot = view_slot_table_00627e80 +
                        static_cast<std::size_t>(index) * 0x10cu;
        const U route_pointer = value_of(route_object);

        store_dword(slot, 0x00u, route_pointer);
        store_dword(slot, 0x04u, route_pointer);
        for (U field = 0u; field < 3u; ++field) {
            store_dword(slot, 0x14u + field * 4u,
                        load_dword(route_object, 0x330u + field * 4u));
        }
        store_dword(slot, 0x20u, 0u);
        for (U field = 0u; field < 3u; ++field) {
            store_dword(slot, 0x24u + field * 4u,
                        load_dword(route_object, 0x330u + field * 4u));
        }
        store_dword(slot, 0x30u, 0u);
        store_dword(slot, 0x34u, 0u);
        store_dword(slot, 0x38u, 0x42160000u);
        store_dword(slot, 0x78u, 0x42160000u);
        store_dword(slot, 0x3cu, 0u);
        store_dword(slot, 0x40u, 0u);
        store_dword(slot, 0x58u, 0x42160000u);
        store_dword(slot, 0x5cu, 0x3f000000u);
        for (U field = 0u; field < 9u; ++field) {
            store_dword(slot, 0x7cu + field * 4u,
                        load_dword(route_object, 0x364u + field * 4u));
        }
        store_dword(slot, 0xa0u, 0u);
        for (U field = 0u; field < 3u; ++field) {
            store_dword(slot, 0xa4u + field * 4u,
                        load_dword(route_object, 0x330u + field * 4u));
        }
        for (U field = 0u; field < 3u; ++field) {
            store_dword(slot, 0xb0u + field * 4u,
                        load_dword(route_object, 0x330u + field * 4u));
        }
        store_word16(slot, 0xbcu, 0xeu);
        store_word16(slot, 0xbeu, 0u);
        slot[0xc0u] = static_cast<B>((extra << 7) | 0x20u);
        slot[0xc1u] = 0u;
        slot[0xc2u] = 0u;
        slot[0xc3u] &= 0xf0u;
        slot[0xcau] = view_route_string_005cf5d8;
        store_word16(slot, 0xc4u, 0u);
        store_word16(slot, 0xc6u, 0u);
        store_word16(slot, 0xc8u, 0u);
        store_dword(slot, 0xccu, 0x3f666666u);
        store_dword(slot, 0xd0u, 0u);
        slot[0xd4u] = 0xffu;
        store_dword(slot, 0xd8u, 0x40u);
        view_slot_snapshot_00473190(slot + 0xdcu, nullptr, service_object);

        ++index;
        view_route_counter_00465cf0(index);
        if (index > static_cast<std::int32_t>(extra)) {
            break;
        }
    }

    const U selected = application_state_006573e8.word(0x0065741cu);
    const B* const route_object =
        static_cast<const B*>(route_object_registry_table_005e8c00[selected]);
    for (U field = 0u; field < 3u; ++field) {
        view_setup_camera_005cf620[field] =
            load_dword(route_object, 0x10e8u + field * 4u);
    }
    for (U field = 0u; field < 3u; ++field) {
        store_dword(view_slot_table_00627e80, 0x4cu + field * 4u,
                    load_dword(route_object, 0x10f4u + field * 4u));
    }

    // 005ae3c0 is the canonical case-folded string compare
    // (formatter_search_compare_005ae3c0); the original compares the arena
    // name buffer at 0x00657444 against the "castle" route string.
    const std::int32_t probe = formatter_search_compare_005ae3c0(
        reinterpret_cast<const char*>(&application_state_006573e8.word(0x00657444u)),
        view_castle_string_005cf760);
    // Original NEG/SBB/NEG sequence: 1 when the probe result is non-zero.
    view_route_flag_005cf584 = (probe != 0) ? 1u : 0u;

    view_route_finish_00463c30();
    startup_service_noop_00516950();
}

// 00467740..004677cc. Tears down the display's slot state, releases the
// display-held objects and the display itself through the canonical
// allocator, clears the display global, and releases the core through its
// vtable slot one.
void __cdecl application_main_function_00467740() {
    view_teardown_sync_004b7140();
    view_teardown_probe_00465e20();

    RenderDisplay* const display = render_display_00628130;
    if (display != nullptr) {
        const U state_7c = load_dword(display->bytes, 0x7cu);
        if (state_7c != 0u) {
            view_teardown_release_00538d80(pointer_of(state_7c), nullptr);
            (void)application_release_0059f050(pointer_of(state_7c));
        }
        const U device = load_dword(display->bytes, 0x70u);
        if (device != 0u) {
            const U device_vtable =
                load_dword(pointer_of(device), 0u);
            const auto release =
                *reinterpret_cast<const SlotCall*>(
                    static_cast<std::uintptr_t>(device_vtable));
            release(pointer_of(device), nullptr, 1u);
        }
        const U state_6c = load_dword(display->bytes, 0x6cu);
        if (state_6c != 0u) {
            view_teardown_release_00540420(pointer_of(state_6c), nullptr);
            (void)application_release_0059f050(pointer_of(state_6c));
        }
        view_teardown_reset_00466500(display->bytes + 0x34u, nullptr);
        view_teardown_reset_00466500(display->bytes + 0x14u, nullptr);
        (void)application_release_0059f050(display);
    }

    render_display_00628130 = nullptr;
    view_teardown_finish_0047f190();

    const U core = value_of(render_core_0065b39c);
    if (core != 0u) {
        const U core_vtable = load_dword(pointer_of(core), 0u);
        const auto release =
            *reinterpret_cast<const SlotCall*>(
                static_cast<std::uintptr_t>(core_vtable) + 4u);
        release(pointer_of(core), nullptr, 1u);
    }
}

// 00468fb0..0046909b. Builds the 0x38-byte scene buffer from the display
// device payload, resets the scene stage chain in the original order, and
// transfers into 004521c0 as the original tail jump. The original
// dereferences the display global without a null check.
void __cdecl startup_sequence_call_00468fb0() {
    void* buffer = render_allocate_0059ef90(0x38u);
    if (buffer != nullptr) {
        buffer = render_driver_buffer_ctor_00537700(buffer, nullptr);
    }
    scene_buffer_0062814c = buffer;

    const U device =
        load_dword(render_display_00628130->bytes, 0x70u);
    const U payload = load_dword(pointer_of(device), 0x04u);
    std::memcpy(buffer, static_cast<const B*>(pointer_of(payload)), 0x38u);

    scene_flag_00619800 = 0u;
    render_mode_update_state_0044ed10();
    startup_service_noop_00516950();
    startup_sequence_service_00536080(
        pointer_of(load_dword(render_display_00628130->bytes, 0x74u)),
        nullptr);
    render_display_thr_cleanup_00555390();
    scene_reset_00467f40(render_display_00628130, nullptr);

    void* small = render_allocate_0059ef90(8u);
    if (small != nullptr) {
        small = scene_transfer_slot_0044b960(small, nullptr);
    }
    scene_transfer_state_0061976c = small;

    const U from = application_state_006573e8.word(0x00657a24u);
    const U to = application_state_006573e8.word(0x00657a30u);
    scene_route_select_00475d70(from, to);
    scene_route_root_0044fae0(&application_state_006573e8.word(0x00657444u));
    scene_stage_reset_00448b10();
    splash_progress_004a4a70(3);
    scene_stage_reset_0044f240();
    scene_stage_reset_00451490();
    scene_stage_reset_004552b0();
    scene_stage_reset_0043ed00();
    scene_stage_reset_00455f60();
    scene_route_bind_0045dbd0(&application_state_006573e8.word(0x00657444u),
                              0u);
    scene_stage_reset_00458b80();
    (void)scene_transfer_enter_004521c0();
}

} // namespace porsche
