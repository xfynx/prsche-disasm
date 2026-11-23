// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run778: 0053f380..0053f425 (166B), 0053f980..0053fce1 (866B),
//         0053fd60..0053fd80 (33B), 00574ab0..00574aca (27B).
#include "scene_pass_compile_factory_778.hpp"

#include "porsche/render_startup.hpp"
#include "scene_stage_group_742.hpp"

#include <cstring>

namespace porsche {
namespace {

using U = std::uint32_t;
using U16 = std::uint16_t;
using B = std::uint8_t;
using QuerySlotsFn = void* (__thiscall*)(void*, U*);

constexpr U kPassVtable_005b6a34 = 0x005b6a34u;
constexpr U kPassVtable_005c0898 = 0x005c0898u;

enum class FactoryInitKind : B {
    Null = 0u,
    Inline = 1u,
    Std320 = 2u,
    Alt600 = 3u,
    CtorFd60 = 4u,
    Ctor4ab0 = 5u,
};

struct FactorySpec {
    FactoryInitKind init_kind;
    U alloc_bytes;
    U pass_kind;
    U vtable_va;
};

constexpr FactorySpec kFactoryTable[20] = {
    {FactoryInitKind::Inline,   0x030u, 0x00u, 0x005bbc60u}, // 0x00
    {FactoryInitKind::Inline,   0x030u, 0x01u, 0x005b6a34u}, // 0x01
    {FactoryInitKind::Std320,   0x030u, 0x01u, 0x005bbe10u}, // 0x02
    {FactoryInitKind::Inline,   0x030u, 0x02u, 0x005b69e4u}, // 0x03
    {FactoryInitKind::Std320,   0x030u, 0x03u, 0x005b6a0cu}, // 0x04
    {FactoryInitKind::CtorFd60, 0x030u, 0x01u, 0x005bbdecu}, // 0x05
    {FactoryInitKind::Std320,   0x030u, 0x05u, 0x005b3bf0u}, // 0x06
    {FactoryInitKind::Std320,   0x030u, 0x06u, 0x005bbdc8u}, // 0x07
    {FactoryInitKind::Std320,   0x030u, 0x07u, 0x005b69bcu}, // 0x08
    {FactoryInitKind::Std320,   0x810u, 0x08u, 0x005bbc84u}, // 0x09
    {FactoryInitKind::Std320,   0x030u, 0x09u, 0x005bbd14u}, // 0x0a
    {FactoryInitKind::Std320,   0x030u, 0x0au, 0x005bbd38u}, // 0x0b
    {FactoryInitKind::Std320,   0x030u, 0x05u, 0x005bbd5cu}, // 0x0c
    {FactoryInitKind::Std320,   0x030u, 0x01u, 0x005bbd80u}, // 0x0d
    {FactoryInitKind::Std320,   0x030u, 0x0cu, 0x005bbda4u}, // 0x0e
    {FactoryInitKind::Ctor4ab0, 0x030u, 0x02u, 0x005c0898u}, // 0x0f
    {FactoryInitKind::Std320,   0x030u, 0x0eu, 0x005bbcf0u}, // 0x10
    {FactoryInitKind::Null,     0x000u, 0x00u, 0x00000000u}, // 0x11
    {FactoryInitKind::Alt600,   0x030u, 0x00u, 0x005bbca8u}, // 0x12
    {FactoryInitKind::Std320,   0x030u, 0x10u, 0x005bbcccu}, // 0x13
};

U load32(const void* base, U offset) {
    U value = 0u;
    std::memcpy(&value, static_cast<const B*>(base) + offset, sizeof(value));
    return value;
}

void store32(void* base, U offset, U value) {
    std::memcpy(static_cast<B*>(base) + offset, &value, sizeof(value));
}

void store16(void* base, U offset, U16 value) {
    std::memcpy(static_cast<B*>(base) + offset, &value, sizeof(value));
}

void* load_ptr(const void* base, U offset) {
    void* ptr = nullptr;
    std::memcpy(&ptr, static_cast<const B*>(base) + offset, sizeof(ptr));
    return ptr;
}

void store_ptr(void* base, U offset, void* ptr) {
    std::memcpy(static_cast<B*>(base) + offset, &ptr, sizeof(ptr));
}

void* find_matching_pass(void* head, U want_kind, U want_subkind) {
    void* cur = head;
    while (cur != nullptr) {
        if (load32(cur, 0x0cu) == want_kind &&
            (want_subkind == 0u || want_subkind == load32(cur, 0x10u))) {
            return cur;
        }
        cur = load_ptr(cur, 0x04u);
    }
    return nullptr;
}

U16 find_parent_pass_index(void* parent_group, const void* target) {
    U index = 0u;
    void* cur = load_ptr(parent_group, 0x04u);
    while (cur != nullptr) {
        if (cur == target) {
            return static_cast<U16>(index);
        }
        cur = load_ptr(cur, 0x08u);
        ++index;
    }
    return static_cast<U16>(0xffffu);
}

} // namespace

void* __fastcall scene_pass_init_kind1_0053fd60(
    void* self, void* /*unused_edx*/, std::uint32_t subkind) {
    store32(self, 0x10u, subkind);
    store32(self, 0x0cu, 1u);
    store32(self, 0x24u, 0u);
    store32(self, 0x28u, 0u);
    store32(self, 0x00u, kPassVtable_005b6a34);
    return self;
}

void* __fastcall scene_pass_init_kind2_00574ab0(
    void* self, void* /*unused_edx*/, std::uint32_t subkind) {
    scene_pass_init_0053f320(self, nullptr, 2u, subkind);
    store32(self, 0x00u, kPassVtable_005c0898);
    return self;
}

void __fastcall scene_pass_compile_0053f380(void* self) {
    auto* count_ptr = reinterpret_cast<U*>(static_cast<B*>(self) + 0x2cu);
    const void* vtable = load_ptr(self, 0x00u);
    const auto query_slots = reinterpret_cast<QuerySlotsFn>(load_ptr(vtable, 0x0cu));
    const void* entries = query_slots(self, count_ptr);
    if (entries == nullptr) {
        return;
    }

    void* const indices = render_allocate_0059ef90(load32(self, 0x2cu) * 2u);
    store_ptr(self, 0x24u, indices);
    void* const passes = render_allocate_0059ef90(load32(self, 0x2cu) * 4u);
    store_ptr(self, 0x28u, passes);

    const U count = load32(self, 0x2cu);
    for (U i = 0u; i < count; ++i) {
        const auto* entry = static_cast<const B*>(entries) + i * 8u;
        const U want_kind = load32(entry, 0x00u);
        const U want_subkind = load32(entry, 0x04u);

        void* matched = find_matching_pass(load_ptr(self, 0x04u), want_kind, want_subkind);
        void** const pass_table = static_cast<void**>(load_ptr(self, 0x28u));
        pass_table[i] = matched;

        const U16 parent_idx = find_parent_pass_index(load_ptr(self, 0x20u), pass_table[i]);
        auto* index_table = static_cast<B*>(load_ptr(self, 0x24u));
        store16(index_table, i * 2u, parent_idx);
    }
}

void* __cdecl scene_pass_factory_default_0053f980(
    std::uint32_t kind, std::uint32_t subkind) {
    if (kind > 0x13u) {
        return nullptr;
    }
    const FactorySpec& spec = kFactoryTable[kind];
    if (spec.init_kind == FactoryInitKind::Null) {
        return nullptr;
    }
    void* const pass = render_allocate_0059ef90(spec.alloc_bytes);
    if (pass == nullptr) {
        return nullptr;
    }

    switch (spec.init_kind) {
    case FactoryInitKind::Inline:
        store32(pass, 0x0cu, spec.pass_kind);
        store32(pass, 0x10u, subkind);
        store32(pass, 0x24u, 0u);
        store32(pass, 0x28u, 0u);
        store32(pass, 0x00u, spec.vtable_va);
        return pass;
    case FactoryInitKind::Std320:
        scene_pass_init_0053f320(pass, nullptr, spec.pass_kind, subkind);
        store32(pass, 0x00u, spec.vtable_va);
        return pass;
    case FactoryInitKind::Alt600:
        scene_pass_init_alt_0053f600(pass, nullptr, subkind);
        store32(pass, 0x00u, spec.vtable_va);
        return pass;
    case FactoryInitKind::CtorFd60:
        scene_pass_init_kind1_0053fd60(pass, nullptr, subkind);
        store32(pass, 0x00u, spec.vtable_va);
        return pass;
    case FactoryInitKind::Ctor4ab0:
        return scene_pass_init_kind2_00574ab0(pass, nullptr, subkind);
    case FactoryInitKind::Null:
        return nullptr;
    }
    return nullptr;
}

} // namespace porsche
