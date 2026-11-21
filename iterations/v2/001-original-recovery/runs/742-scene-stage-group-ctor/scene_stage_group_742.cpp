// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run742: scene stage group constructor (0059f070..0059f1b8, 329B) and its four
// unrecovered leaf callees:
//   0053f320..0053f340 (33B)  scene_pass_init_0053f320
//   0053f600..0053f61c (29B)  scene_pass_init_alt_0053f600
//   00537a20..00537a29 (10B)  scene_mode_set_c_00537a20
//   00537a60..00537a69 (10B)  scene_mode_set_10_00537a60
// Original body SHA-256 (raw PE bytes, verified by verify-v2-native-batch.py):
//   0059f070 d6100404302257b268c0bd5ce24df4b385d6a20514d9d0326b8192dca4d2ef72
//   0053f320 7d6c96b85f8e9102367a85962504449050bafd02acbc63a7f8d919477a7c5bb3
//   0053f600 5fed9abffcc597f9a84b8a5f6366bfb93ae86aabb39ca043bc5ec55573aad843
//   00537a20 0a5b1a6d212e0caedbf2d98dea5a75fa8dba9f19919dae6658f37365af35e72f
//   00537a60 b994e2bd1bc262c5b463fca225534224134549b75fddcc1f700f38a59510b90e
#include "scene_stage_group_742.hpp"

#include "porsche/render_startup.hpp"
#include "scene_blur_stage_726.hpp"
#include "scene_pass_children_737.hpp"
#include "scene_stage_stack_core_721.hpp"

#include <cstdint>
#include <cstring>

namespace porsche {
namespace {

using U = std::uint32_t;
using B = std::uint8_t;

// Raw vtable addresses stored directly by the original constructors (matching Run711/Run736).
constexpr U kGroupVtable_005b3c94 = 0x005b3c94u;
constexpr U kPassBaseVtable_005bbc3c = 0x005bbc3cu;
constexpr U kPassAltVtable_005bbc60 = 0x005bbc60u;

U address_of(const void* p) noexcept {
    return static_cast<U>(reinterpret_cast<std::uintptr_t>(p));
}

void store32(void* base, U offset, U value) noexcept {
    std::memcpy(static_cast<B*>(base) + offset, &value, 4u);
}

void append_pass_entry(void* group, U kind, U subkind, U vtable_va) {
    void* pass = render_allocate_0059ef90(0x30u);
    if (pass != nullptr) {
        scene_pass_init_0053f320(pass, nullptr, kind, subkind);
        store32(pass, 0x00u, vtable_va);
    } else {
        pass = nullptr;
    }
    scene_pass_append_0053f160(group, nullptr, pass);
}

} // namespace

void* __fastcall scene_pass_init_0053f320(
    void* self, void*, U kind, U subkind) {
    store32(self, 0x0cu, kind);
    store32(self, 0x00u, kPassBaseVtable_005bbc3c);
    store32(self, 0x10u, subkind);
    store32(self, 0x24u, 0u);
    store32(self, 0x28u, 0u);
    return self;
}

void* __fastcall scene_pass_init_alt_0053f600(
    void* self, void*, U subkind) {
    store32(self, 0x0cu, 0u);
    store32(self, 0x10u, subkind);
    store32(self, 0x24u, 0u);
    store32(self, 0x28u, 0u);
    store32(self, 0x00u, kPassAltVtable_005bbc60);
    return self;
}

void __fastcall scene_mode_set_c_00537a20(void* self, void*, U value) {
    store32(self, 0x0cu, value);
}

void __fastcall scene_mode_set_10_00537a60(void* self, void*, U value) {
    store32(self, 0x10u, value);
}

void* __fastcall scene_stage_group_ctor_0059f070(void* self, void*) {
    void* const mode = static_cast<B*>(self) + 0x0cu;
    store32(self, 0x04u, 0u);
    store32(self, 0x08u, 0u);
    store32(self, 0x00u, kGroupVtable_005b3c94);
    scene_mode_ctor_005379f0(mode, nullptr);

    append_pass_entry(self, 1u, 7u, 0x005b6a34u);
    append_pass_entry(self, 5u, 0u, 0x005b3bf0u);
    append_pass_entry(self, 2u, 0u, 0x005b69e4u);
    append_pass_entry(self, 3u, 0u, 0x005b6a0cu);
    append_pass_entry(self, 7u, 0u, 0x005b69bcu);

    void* const alt_raw = render_allocate_0059ef90(0x30u);
    void* const alt_pass = (alt_raw != nullptr)
        ? scene_pass_init_alt_0053f600(alt_raw, nullptr, 0u)
        : nullptr;
    scene_pass_append_0053f160(self, nullptr, alt_pass);

    scene_pass_finalize_0053f2a0(self, nullptr);
    scene_mode_set_c_00537a20(mode, nullptr, 0u);
    scene_mode_set_10_00537a60(mode, nullptr, 0u);
    store32(self, 0x48u, address_of(mode));
    return self;
}

} // namespace porsche
