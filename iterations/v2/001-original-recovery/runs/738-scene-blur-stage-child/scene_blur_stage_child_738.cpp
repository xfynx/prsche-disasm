// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// 00468440..004685d0, 401B, body SHA-256
// 7f6d301f75f9b2b83b9f1d659d3bbdcbf04f3ac5c5c1ed827faab40e1391dd66.
#include "scene_blur_stage_child_738.hpp"

#include "startup_text_fallbacks_650.hpp"

#include <cstdint>
#include <cstring>

namespace porsche {
namespace {

using U = std::uint32_t;
using I = std::int32_t;
using B = std::uint8_t;

U address_of(const void* p) noexcept {
    return static_cast<U>(reinterpret_cast<std::uintptr_t>(p));
}

void* ptr_of(U value) noexcept {
    return reinterpret_cast<void*>(static_cast<std::uintptr_t>(value));
}

U load32(const void* base, U offset) noexcept {
    U value = 0u;
    std::memcpy(&value, static_cast<const B*>(base) + offset, sizeof value);
    return value;
}

I load_s8(const void* base, U offset) noexcept {
    return static_cast<I>(static_cast<std::int8_t>(static_cast<const B*>(base)[offset]));
}

void store32(void* base, U offset, U value) noexcept {
    std::memcpy(static_cast<B*>(base) + offset, &value, sizeof value);
}

U row_offset(void* self, U index, U slot_offset) noexcept {
    const U stride = static_cast<U>(load_s8(self, 0x24u));
    const U slot = static_cast<U>(load_s8(self, slot_offset));
    return (stride * index + slot) << 3u;
}

void write_row(void* self, U index, U slot_offset, U first, U second) noexcept {
    void* const table0 = ptr_of(load32(self, 0x04u));
    store32(table0, row_offset(self, index, slot_offset) + 0x04u, second);
    void* const table1 = ptr_of(load32(self, 0x04u));
    store32(table1, row_offset(self, index, slot_offset), first);
}

void append_pass(void* self, U kind) {
    void* const pass = scene_pass_create_0053f230(kind, 0u, 0x20u);
    void* const owner = ptr_of(load32(self, 0x00u));
    scene_pass_append_0053f160(owner, nullptr, pass);
}

} // namespace

void __fastcall scene_blur_program_stage_00468440(
    void* self, void*, U index, void* source,
    U slot_1f_value, U slot_1d_value, U slot_20_value, U enabled) {
    append_pass(self, 3u);
    write_row(self, index, 0x1du, load32(self, 0x10u) << 3u, slot_1d_value);

    append_pass(self, 4u);
    write_row(self, index, 0x1eu, 0x54u, address_of(source));

    if (source != nullptr) {
        U state[7];
        std::memcpy(state, static_cast<const B*>(source) + 0x38u, sizeof state);
        scene_blur_state_flag_00537a70(state, nullptr, (enabled & 0xffu) == 0u ? 1u : 0u);
        scene_blur_state_one_00537a40(state, nullptr, 1u);
        const auto* const quality = reinterpret_cast<const B*>(
            startup_text_quality_mask_ptr_0044dfe0(1u));
        scene_blur_state_quality_00537a30(state, nullptr, quality[0] == 0x10u ? 1u : 0u);
        scene_blur_state_commit_00536470(source, nullptr, state);
    }

    append_pass(self, 8u);
    write_row(self, index, 0x1fu, 0x18u, slot_1f_value);

    append_pass(self, 6u);
    write_row(self, index, 0x20u, load32(self, 0x10u) << 2u, slot_20_value);
}

} // namespace porsche
