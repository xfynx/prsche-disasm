// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run701: eight recovered view teardown / route family bodies.
//
// Original body SHA-256 (raw PE bytes, verified by verify-v2-native-batch.py):
//   00465cf0 ffe435dd56f6a30d7b2114da36cc395b1d03433bcdaa37573f6b10c1d1efd719
//   00465e20 d12fb9910a896abaa66c7a5ae6b6dfdee0c47b2f7a6e55892d2b757e248071de
//   0047f190 da05e3ddfe84b58e20e551048b73e784caf71f4d361a9880d2d026137ccd958c
//   004b7140 ad66ed1056e820d21c2c48b121b0b876535c082f5039e4f37eba197c9df38988
//   00473100 9d667ff561079d6adca98d31acfbf8d44860df6dc58d413343994046d96755f3
//   00473190 588cd1c9befe29284d29577be8398189b6e398f27470b68fba903c3046e1991d
//   00538d80 de8e86aee4df948a1e0ec4a82c737c9af8cecce23845d4c9d6367bc0af4d06e9
//   00540420 b2c8ce219b82c9b7b52bb702804541ac5be5bedd4872f82fb2d892e199797ac6
#include "view_teardown_route_family_701.hpp"

#include <cstring>

namespace porsche {

// Unowned .bss cell at original VA 0x0062810c (loader zero).
void* render_secondary_object_0062810c = nullptr;

namespace {
using U = std::uint32_t;
using I = std::int32_t;
using B = std::uint8_t;

U load_dword(const void* base, std::size_t offset) {
    U value;
    std::memcpy(&value, static_cast<const B*>(base) + offset, sizeof value);
    return value;
}

void store_word16(void* base, std::size_t offset, std::uint16_t value) {
    std::memcpy(static_cast<B*>(base) + offset, &value, sizeof value);
}

void store_dword(void* base, std::size_t offset, U value) {
    std::memcpy(static_cast<B*>(base) + offset, &value, sizeof value);
}

// The original 0x005b245c constant is the raw dword 0xc0800000 (-4.0f).
constexpr U kRouteScaleBits = 0xc0800000u;

// Exact original FLD/FMUL/FSTP chain: three fields at source +0x37c,+0x380,
// +0x384 multiplied by the scale and stored at dst +0,+4,+8. Inline x87 is
// used so the x87 stack/tag/status state matches the original instructions.
void scale_fields(B* dst, const B* src, const float* scale) {
    __asm {
        mov eax, src
        mov edx, dst
        mov ecx, scale
        fld dword ptr [eax+892]      // +0x37c
        fmul dword ptr [ecx]
        fstp dword ptr [edx]
        fld dword ptr [eax+896]      // +0x380
        fmul dword ptr [ecx]
        fstp dword ptr [edx+4]
        fld dword ptr [eax+900]      // +0x384
        fmul dword ptr [ecx]
        fstp dword ptr [edx+8]
    }
}
} // namespace

// 00465cf0..00465d75 (133B). Only the low byte of the argument is consulted:
// bit 0 scales the fields of the first 0x10c-byte view slot, bit 1 the second.
// Each route object pointer is reloaded from the slot table every iteration.
void __cdecl view_route_counter_00465cf0(std::int32_t index) {
    const B bits = static_cast<B>(index);
    const U scale_bits = kRouteScaleBits;
    const float* const scale = reinterpret_cast<const float*>(&scale_bits);
    if ((bits & 1u) != 0u) {
        B* const route = reinterpret_cast<B*>(
            load_dword(view_slot_table_00627e80, 0u));
        scale_fields(view_slot_table_00627e80 + 0x08u, route, scale);
    }
    if ((bits & 2u) != 0u) {
        B* const route = reinterpret_cast<B*>(
            load_dword(view_slot_table_00627e80, 0x10cu));
        scale_fields(view_slot_table_00627e80 + 0x114u, route, scale);
    }
}

// 00465e20..00465e3d (29B). Destroys the secondary render object through its
// 0059f1c0 method and releases it through the canonical allocator, then keeps
// the global pointer non-null (the original never clears it).
void __cdecl view_teardown_probe_00465e20() {
    void* const object = render_secondary_object_0062810c;
    if (object != nullptr) {
        teardown_secondary_destroy_0059f1c0(object, nullptr);
        (void)application_release_0059f050(object);
    }
}

// 0047f190..0047f207 (119B). Walks the context table root at 0x00628bac:
// invokes 00514990 on every dword of the +0xa4 vector (begin..end), frees the
// begin..+8 span when non-empty, releases the vector and the root through the
// canonical allocator, then clears the root pointer. Both original paths
// clear the global.
void __cdecl view_teardown_finish_0047f190() {
    void* const root = startup_context_table_00628bac;
    if (root == nullptr) {
        startup_context_table_00628bac = nullptr;
        return;
    }
    B* const root_bytes = static_cast<B*>(root);
    void* vec = nullptr;
    std::memcpy(&vec, root_bytes + 0xa4u, sizeof vec);
    if (vec != nullptr) {
        B* const vec_bytes = static_cast<B*>(vec);
        const U begin = load_dword(vec_bytes, 0u);
        const U end = load_dword(vec_bytes, 4u);
        const U tail = load_dword(vec_bytes, 8u);
        for (U item = begin; item != end; item += 4u) {
            registry_item_noop_00514990(
                reinterpret_cast<void*>(static_cast<std::uintptr_t>(item)));
        }
        const I count = static_cast<I>(tail - begin) >> 2;
        if (count != 0) {
            application_context_member_destroy_block_00441200(
                reinterpret_cast<void*>(static_cast<std::uintptr_t>(begin)),
                static_cast<U>(count << 2));
        }
        (void)application_release_0059f050(vec);
    }
    (void)application_release_0059f050(root);
    startup_context_table_00628bac = nullptr;
}

// 004b7140..004b7150 (16B).
void __cdecl view_teardown_sync_004b7140() {
    startup_service_noop_00516950();
    render_teardown_state_0065b398 = 0u;
}

// 00473100..00473143 (67B, RET 4). Initializes a 0x30-byte frame service
// object. word[0] takes mode; ECX is zeroed before word[0x24] is written, so
// that field stays zero.
void __fastcall view_slot_service_00473100(void* self, void* unused_edx,
                                           std::uint32_t mode) {
    (void)unused_edx;
    B* const object = static_cast<B*>(self);
    store_word16(object, 0x00u, static_cast<std::uint16_t>(mode));
    object[0x02u] = 0u;
    store_dword(object, 0x04u, 0xffffffffu);
    object[0x08u] = 0u;
    object[0x09u] = 0u;
    object[0x0au] = 0u;
    store_word16(object, 0x24u, 0u);
    store_dword(object, 0x28u, 0u);
    store_dword(object, 0x2cu, 0u);
    store_dword(object, 0x14u, 0u);
    store_dword(object, 0x0cu, 0u);
    store_dword(object, 0x10u, 0x3f800000u);
    store_dword(object, 0x1cu, 0u);
    store_dword(object, 0x18u, 0u);
    store_dword(object, 0x20u, 0x3f800000u);
}

// 00473190..00473205 (117B, RET 4). Copies the observed service-object fields
// from source into self; the self==source case is a no-op in the original.
void __fastcall view_slot_snapshot_00473190(void* self, void* unused_edx,
                                            const void* source) {
    (void)unused_edx;
    B* const target = static_cast<B*>(self);
    const B* const from = static_cast<const B*>(source);
    if (target == from) {
        return;
    }
    std::uint16_t word;
    std::memcpy(&word, from + 0x00u, 2u);
    std::memcpy(target + 0x00u, &word, 2u);
    target[0x02u] = from[0x02u];
    target[0x08u] = from[0x08u];
    target[0x09u] = from[0x09u];
    target[0x0au] = from[0x0au];
    for (U field = 0u; field < 3u; ++field) {
        store_dword(target, 0x0cu + field * 4u, load_dword(from, 0x0cu + field * 4u));
    }
    for (U field = 0u; field < 3u; ++field) {
        store_dword(target, 0x18u + field * 4u, load_dword(from, 0x18u + field * 4u));
    }
    std::memcpy(&word, from + 0x24u, 2u);
    std::memcpy(target + 0x24u, &word, 2u);
    store_dword(target, 0x04u, load_dword(from, 0x04u));
    store_dword(target, 0x28u, load_dword(from, 0x28u));
    store_dword(target, 0x2cu, load_dword(from, 0x2cu));
}

// 00538d80..00538d94 (20B). Releases two sub-cells of the receiver.
void __fastcall view_teardown_release_00538d80(void* self, void* unused_edx) {
    (void)unused_edx;
    B* const base = static_cast<B*>(self);
    buffer_cell_release_00539eb0(base + 0x5cu, nullptr);
    buffer_cell_release_00539eb0(base, nullptr);
}

// 00540420..00540438 (24B). Deletes the movie service held at self+4 through
// its vtable slot zero (pushed argument 1), then clears the 0x0069ed0c global.
void __fastcall view_teardown_release_00540420(void* self, void* unused_edx) {
    (void)unused_edx;
    B* const base = static_cast<B*>(self);
    void* inner = nullptr;
    std::memcpy(&inner, base + 4u, sizeof inner);
    if (inner != nullptr) {
        void** const vtable = *reinterpret_cast<void***>(inner);
        const auto del =
            reinterpret_cast<void(__fastcall*)(void*, void*, U)>(vtable[0]);
        del(inner, nullptr, 1u);
    }
    game_setup_movie_service_0069ed0c = nullptr;
}

} // namespace porsche
