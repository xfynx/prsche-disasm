// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run702 recovered bodies (raw .text SHA-256 pinned in native-config.json):
//   0046d960 54213dbe...b7343   0046d890 e16de0f6...eba4af9
//   004659e0 22bb432b...e6fd6   00475d70 66dea846...9a0588
//   0044fae0 a2dc0696...f377    004521c0 e601b9ef...fc56f8
//   0044b960 1578ddef...8893
#include "entry_fe_scene_leaves_702.hpp"

#include "porsche/application_state.hpp"
#include "porsche/render_startup.hpp"

#include <cstddef>
#include <cstring>

namespace porsche {

// Newly owned loader-zero cells (no prior owner in the manifest closure).
void* scene_route_root_object_0061bc38 = nullptr;
void* scene_transfer_object_0061bcc0 = nullptr;
std::uint32_t entry_fe_flag_word_006280e0 = 0u;
std::uint32_t entry_fe_flag_word_006280e4 = 0u;
std::uint32_t entry_fe_frame_word_00606ad4 = 0u;
std::uint32_t* scene_elem_vector_00628168 = nullptr;
std::uint32_t* scene_elem_count_vector_00628178 = nullptr;

namespace {

using U = std::uint32_t;
using I = std::int32_t;
using B = std::uint8_t;

B load_byte(const void* base, std::size_t offset) {
    return *(static_cast<const B*>(base) + offset);
}

void store_byte(void* base, std::size_t offset, B value) {
    *(static_cast<B*>(base) + offset) = value;
}

U load_dword(const void* base, std::size_t offset) {
    U value = 0u;
    std::memcpy(&value, static_cast<const B*>(base) + offset, sizeof value);
    return value;
}

void store_dword(void* base, std::size_t offset, U value) {
    std::memcpy(static_cast<B*>(base) + offset, &value, sizeof value);
}

U vector_count(const U* header) {
    return static_cast<U>(static_cast<I>(header[1] - header[0]) >> 2);
}

} // namespace

// 0046d960..0046d970 (17B, __cdecl int, ret 0). Element count of the vector
// header at 0x00628178, read as (end - begin) >> 2 with an arithmetic shift.
std::int32_t __cdecl entry_fe_call_0046d960() {
    return static_cast<I>(vector_count(scene_elem_count_vector_00628178));
}

// 0046d890..0046d952 (195B, __cdecl unsigned, ret 0). Two passes over the
// scene-element vector at 0x00628168: pass one returns the first index whose
// RTTI probe yields kind 1 or 2 while the arena flag is set; pass two returns
// the first index the RTTI probe rejects. Both passes reload the header.
std::uint32_t __cdecl entry_fe_call_0046d890() {
    const U* header = scene_elem_vector_00628168;
    U index = 0u;
    U count = vector_count(header);
    while (index < count) {
        const U element = load_dword(reinterpret_cast<const void*>(header[0]),
                                     index * 4u);
        const U object = formatter_compare_005a134b(
            element, 0u, rtti_scene_elem_005cf908, rtti_camera_elem_005cf928, 0u);
        if (object != 0u) {
            const U first_kind =
                scene_elem_kind_00469b50(reinterpret_cast<void*>(object), nullptr);
            if (first_kind == 1u &&
                application_state_006573e8.word(0x00657430u) == 0u) {
                return index;
            }
            const U second_kind =
                scene_elem_kind_00469b50(reinterpret_cast<void*>(object), nullptr);
            if (second_kind == 2u &&
                application_state_006573e8.word(0x00657430u) != 0u) {
                return index;
            }
        }
        ++index;
        count = vector_count(header);
    }

    index = 0u;
    count = vector_count(header);
    while (index < count) {
        const U element = load_dword(reinterpret_cast<const void*>(header[0]),
                                     index * 4u);
        const U object = formatter_compare_005a134b(
            element, 0u, rtti_scene_elem_005cf908, rtti_camera_elem_005cf928, 0u);
        if (object != 0u) {
            return index;
        }
        ++index;
        count = vector_count(header);
    }
    return 0u;
}

// 004659e0..00465a53 (116B, __cdecl void, ret 0). Clears the nine frame/entry
// state words, then tests bit zero of slot byte 0x627f40 + 0x10c*first before
// issuing the two-argument service call.
void __cdecl entry_fe_call_004659e0(std::uint32_t first, std::uint32_t second) {
    frame_reset_word_006280f0 = 0u;
    entry_fe_flag_word_006280e0 = 0u;
    entry_fe_flag_word_006280e4 = 0u;
    entry_fe_frame_word_00606ad4 = 0u;
    frame_reset_word_006280ec = 0u;
    frame_reset_word_006280e8 = 0u;
    frame_reset_word_00628100 = 0u;
    frame_reset_word_006280fc = 0u;
    frame_reset_word_006280f8 = 0u;
    const std::size_t byte_index = 0xc0u + 0x10cu * static_cast<std::size_t>(first);
    if ((load_byte(view_slot_table_00627e80, byte_index) & 1u) == 0u) {
        entry_fe_service_00465790(first, second);
    }
}

// 00475d70..00475dab (60B, __cdecl void, ret 0). Builds the local {0,1,2,3}
// selector array and dispatches the entry at index (to + 2*from).
void __cdecl scene_route_select_00475d70(std::uint32_t from, std::uint32_t to) {
    const U selector[4u] = {0u, 1u, 2u, 3u};
    const U index = to + from * 2u;
    scene_route_dispatch_00475c80(selector[index]);
}

// 0044fae0..0044fb0d (46B, __cdecl void, ret 0). Allocates the 0x13c-byte
// route object and publishes the constructor's return in 0x0061bc38.
void __cdecl scene_route_root_0044fae0(void* root) {
    void* const object = render_allocate_0059ef90(0x13cu);
    if (object != nullptr) {
        scene_route_root_object_0061bc38 =
            scene_root_constructor_0044fb40(object, nullptr, root);
    } else {
        scene_route_root_object_0061bc38 = nullptr;
    }
}

// 004521c0..004521e8 (41B, __cdecl void, ret 0). Allocates the 0x328-byte
// transfer stage and publishes the constructor's return in 0x0061bcc0.
void __cdecl scene_transfer_enter_004521c0() {
    void* const object = render_allocate_0059ef90(0x328u);
    if (object != nullptr) {
        scene_transfer_object_0061bcc0 =
            scene_stage_constructor_004522b0(object, nullptr);
    } else {
        scene_transfer_object_0061bcc0 = nullptr;
    }
}

// 0044b960..0044b9f5 (150B, __fastcall void*, ret 0). Builds two 0xc-byte
// slot headers in ECX->[0]/[4]. The original reads the high byte of the saved
// ECX register (byte 3 of the self pointer) for header byte +8; the compiled
// form computes that byte directly from the argument.
void* __fastcall scene_transfer_slot_0044b960(void* self, void* unused_edx) {
    (void)unused_edx;
    U* const out = static_cast<U*>(self);
    const B high = static_cast<B>(reinterpret_cast<std::uintptr_t>(self) >> 24);

    void* first = render_allocate_0059ef90(0xcu);
    if (first != nullptr) {
        void* const sub = scene_slot_object_004211d0(0x58u, 0u);
        store_dword(first, 0u, static_cast<U>(reinterpret_cast<std::uintptr_t>(sub)));
        store_dword(first, 4u, 0u);
        store_byte(first, 8u, high);
        store_byte(sub, 0u, 0u);
        store_dword(sub, 4u, 0u);
        store_dword(sub, 8u, static_cast<U>(reinterpret_cast<std::uintptr_t>(sub)));
        store_dword(sub, 0xcu, static_cast<U>(reinterpret_cast<std::uintptr_t>(sub)));
        out[0] = static_cast<U>(reinterpret_cast<std::uintptr_t>(first));
    } else {
        out[0] = 0u;
    }

    void* second = render_allocate_0059ef90(0xcu);
    if (second != nullptr) {
        void* const sub = scene_slot_object_004211d0(0x1cu, 0u);
        store_dword(second, 0u, static_cast<U>(reinterpret_cast<std::uintptr_t>(sub)));
        store_dword(second, 4u, 0u);
        store_byte(second, 8u, high);
        store_byte(sub, 0u, 0u);
        store_dword(sub, 4u, 0u);
        store_dword(sub, 8u, static_cast<U>(reinterpret_cast<std::uintptr_t>(sub)));
        store_dword(sub, 0xcu, static_cast<U>(reinterpret_cast<std::uintptr_t>(sub)));
        out[1] = static_cast<U>(reinterpret_cast<std::uintptr_t>(second));
    } else {
        out[1] = 0u;
    }
    return self;
}

} // namespace porsche
