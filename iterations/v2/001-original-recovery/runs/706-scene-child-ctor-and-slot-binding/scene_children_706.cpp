// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run706 recovery: 00469b50 (7B), 0044fb40 (230B) and the typed slot binding
// 004211d0. 00458c90/004522b0/00475c80 are evidence-excluded in evidence.json.
#include "scene_children_706.hpp"

#include "porsche/application_context_base.hpp"
#include "porsche/application_state.hpp"
#include "porsche/context_effects.hpp"
#include "porsche/formatter_entry.hpp"
#include "porsche/install_paths.hpp"

#include <cstdint>
#include <cstring>

namespace porsche {
namespace {

using U = std::uint32_t;

// Exact raw .rdata transported bytes (NUL included), per original PE.
const char key_backwards_fmt_005ceacc[19u] = "%s%s_backwards.key";
const char key_forward_fmt_005ceab8[17u] = "%s%s_forward.key";
const char key_old_version_fmt_005cea80[54u] =
    "Old version of keyframes detected (v. %d)...ignoring\n";
const char key_reader_name_005cea78[8u] = "RdrKeys";

U load32(const void* base, U offset) {
    U value = 0u;
    std::memcpy(&value, static_cast<const std::uint8_t*>(base) + offset, 4u);
    return value;
}

void store32(void* base, U offset, U value) {
    std::memcpy(static_cast<std::uint8_t*>(base) + offset, &value, 4u);
}

} // namespace

// Opaque callees: observed call-site ABI only; canonical providers are reused
// where one is accepted (005a0fbf/0059d9b0/0059ecb0/0059ecd0/004211d0).
// These must stay outside the anonymous namespace so the native fixture's
// controlled boundary definitions bind to the same decorated symbols.
void __cdecl scene_texture_alloc_report_005a177b(const char* format, U value);
void __fastcall scene_root_finish_0044fc30(void* self, void* unused_edx, U zero);
// Same decorated symbol as the accepted Run649 provider (do not redefine).
void* __cdecl resource_open_quiet_0059d9b0(const char* name, U flags);

// 00469b50..00469b56 (7B, __fastcall, ECX object): return [object + 0xc0].
std::uint32_t __fastcall scene_elem_kind_00469b50(void* object, void*) {
    return load32(object, 0xc0u);
}

// Typed binding for the accepted Run702 caller name. The original body at
// 004211d0 is already owned and proven as
// application_context_member_storage_004211d0 in context_effects.cpp; this is
// a pure forwarder, not a second definition of that body.
void* __cdecl scene_slot_object_004211d0(U size, U zero) {
    return application_context_member_storage_004211d0(size, zero);
}

// 0044fb40..0044fc25 (230B, __fastcall ECX object + stack root, RET 4).
// Selects the backwards/forward key format from the arena REVERSE word,
// resolves the key resource, reports/releases a stale element, and fills a
// fresh 0xc88-byte reader block before the 0044fc30 child and return.
void* __fastcall scene_root_constructor_0044fb40(void* self, void*, void* root) {
    std::uint8_t* const obj = static_cast<std::uint8_t*>(self);
    const char* const install = install_paths_table_0065b2a0[6u];

    store32(obj, 0u, 0u);
    obj[0x138u] = 0u;

    const char* const format =
        (application_state_006573e8.word(0x00657430u) != 0u)
            ? key_backwards_fmt_005ceacc
            : key_forward_fmt_005ceab8;
    char* const key = reinterpret_cast<char*>(obj + 0xc);
    (void)formatter_entry_005a0fbf(key, format, install,
                                   reinterpret_cast<U>(root));

    void* element = resource_open_quiet_0059d9b0(key, 0u);
    store32(obj, 0u, reinterpret_cast<U>(element));
    if (element != nullptr) {
        const U first = load32(element, 0u);
        if (first != 1u) {
            scene_texture_alloc_report_005a177b(key_old_version_fmt_005cea80,
                                                first);
            context_table_release_0059ecd0(element);
            store32(obj, 0u, 0u);
        }
    }

    if (load32(obj, 0u) == 0u) {
        void* const block = application_context_member_block_0059ecb0(
            0xc88u, 0u, reinterpret_cast<U>(key_reader_name_005cea78));
        std::uint8_t* const bytes = static_cast<std::uint8_t*>(block);
        for (U i = 0u; i < 0x190u; ++i) {
            store32(bytes, 8u + i * 8u, 0xffffffffu);
            store32(bytes, 0xcu + i * 8u, 0x43c80000u);
        }
        store32(bytes, 4u, 2u);
        store32(bytes, 8u, 0u);
        store32(bytes, 0xcu, 0x44160000u);
        store32(bytes, 0x10u, 0x186a0u);
        store32(bytes, 0x14u, 0x44160000u);
        store32(obj, 0u, reinterpret_cast<U>(block));
    }

    store32(reinterpret_cast<void*>(load32(obj, 0u)), 0u, 1u);
    store32(obj, 8u, 0u);
    store32(obj, 4u, 0u);
    scene_root_finish_0044fc30(self, nullptr, 0u);
    return self;
}

} // namespace porsche
