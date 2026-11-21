// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run736: scene blur program constructor (00468240..00468307, 200B) and setup
// (004685e0..00468628, 73B), newly exposed by accepted Run726 (00451490).
// Original body SHA-256 (raw PE bytes, verified by verify-v2-native-batch.py):
//   00468240 dc732d4efce9e922de566dd4fae040fb4875bd248bd0e6612a4f49b78ab373b9
//   004685e0 cef0694dda11c79da6caebc6fa6104028f97a8ec46884bd6b38971adcb3b906a
#include "scene_blur_program_736.hpp"

#include "porsche/application_alloc.hpp"
#include "porsche/render_startup.hpp"
#include "scene_blur_stage_726.hpp"

#include <cstdint>
#include <cstring>

namespace porsche {
namespace {

using U = std::uint32_t;
using I = std::int32_t;
using B = std::uint8_t;

// Raw vtable pointer stored at [node + 0] by 00468240 (+0x57), matching 0053f120 (Run711) and 0059f070.
constexpr U kBlurProgramNodeVtable_005b3c94 = 0x005b3c94u;

U address_of(const void* p) noexcept {
    return static_cast<U>(reinterpret_cast<std::uintptr_t>(p));
}

void* ptr_of(U value) noexcept {
    return reinterpret_cast<void*>(static_cast<std::uintptr_t>(value));
}

U load32(const void* base, U offset) noexcept {
    U value = 0u;
    std::memcpy(&value, static_cast<const B*>(base) + offset, 4u);
    return value;
}

I load_s8(const void* base, U offset) noexcept {
    const auto b = static_cast<std::int8_t>(static_cast<const B*>(base)[offset]);
    return static_cast<I>(b);
}

void store32(void* base, U offset, U value) noexcept {
    std::memcpy(static_cast<B*>(base) + offset, &value, 4u);
}

void store8(void* base, U offset, B value) noexcept {
    static_cast<B*>(base)[offset] = value;
}

} // namespace

void* __fastcall scene_blur_program_ctor_00468240(
    void* self, void*,
    std::uint32_t a, std::uint32_t b, std::uint32_t c,
    std::uint32_t d, std::uint32_t e) {
    store32(self, 0x14u, b);
    store8(self, 0x20u, 4u);
    store8(self, 0x24u, 4u);
    store32(self, 0x00u, 0u);
    store32(self, 0x08u, 0u);
    store8(self, 0x0cu, 0u);
    store8(self, 0x1cu, 0u);
    store8(self, 0x21u, 0xffu);
    store8(self, 0x1du, 1u);
    store8(self, 0x1eu, 2u);
    store8(self, 0x1fu, 3u);
    store8(self, 0x22u, 0xffu);
    store8(self, 0x23u, 0xffu);
    store8(self, 0x25u, 1u);
    store32(self, 0x18u, a);

    void* node = render_allocate_0059ef90(0x0cu);
    if (node != nullptr) {
        store32(node, 0x04u, 0u);
        store32(node, 0x08u, 0u);
        store32(node, 0x00u, kBlurProgramNodeVtable_005b3c94);
    } else {
        node = nullptr;
    }

    const U stride = static_cast<U>(load_s8(self, 0x24u));
    store32(self, 0x00u, address_of(node));
    const U extra = static_cast<U>(load_s8(self, 0x25u));
    const U array_bytes = (stride * c + extra) << 3u;
    void* const table = application_allocate_array_0059eff0(array_bytes);
    store32(self, 0x04u, address_of(table));

    void* const pass = scene_pass_create_0053f230(0x800eu, 0u, 0x20u);
    void* const owner = ptr_of(load32(self, 0x00u));
    scene_pass_append_0053f160(owner, nullptr, pass);

    const I slot0 = load_s8(self, 0x1cu);
    void* const table0 = ptr_of(load32(self, 0x04u));
    store32(table0, static_cast<U>(slot0 * 8 + 4), d);

    const I slot1 = load_s8(self, 0x1cu);
    void* const table1 = ptr_of(load32(self, 0x04u));
    store32(table1, static_cast<U>(slot1 * 8), e << 4u);

    store32(self, 0x08u, c);
    store32(self, 0x10u, e);
    return self;
}

void __fastcall scene_blur_program_setup_004685e0(
    void* self, void*,
    std::uint32_t a, std::uint32_t b, std::uint32_t c,
    std::uint32_t d, std::uint32_t e, std::uint32_t f) {
    scene_blur_program_stage_00468440(self, nullptr, a, b, c, d, e, f);
    void* const pass = scene_pass_create_0053f230(0u, 0u, 0x20u);
    void* const owner0 = ptr_of(load32(self, 0x00u));
    scene_pass_append_0053f160(owner0, nullptr, pass);
    void* const owner1 = ptr_of(load32(self, 0x00u));
    scene_pass_finalize_0053f2a0(owner1, nullptr);
}

} // namespace porsche
