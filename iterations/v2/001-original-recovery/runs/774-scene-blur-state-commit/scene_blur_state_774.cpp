// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run774: 00537a30..00537a38 (9B), 00537a40..00537a49 (10B),
//         00537a70..00537a7c (13B), 00536470..00536505 (150B).
#include "scene_blur_state_774.hpp"

#include "porsche/game_setup.hpp"
#include "render_state_flush_527.hpp"

#include <cstring>

namespace porsche {
namespace {

using U = std::uint32_t;
using B = std::uint8_t;
using StateFlushCallback = U(__cdecl*)(U, U);

U load32(const void* base, U offset) {
    U value = 0u;
    std::memcpy(&value, static_cast<const B*>(base) + offset, sizeof(value));
    return value;
}

void store32(void* base, U offset, U value) {
    std::memcpy(static_cast<B*>(base) + offset, &value, sizeof(value));
}

void* load_ptr(const void* base, U offset) {
    void* ptr = nullptr;
    std::memcpy(&ptr, static_cast<const B*>(base) + offset, sizeof(ptr));
    return ptr;
}

void flush_state_bank(const B* committed, U pair_base_index) {
    for (U i = 0u; i < 7u; ++i) {
        const U value = load32(committed, i * 4u);
        const U record_index = pair_base_index + i * 2u;
        if (value != render_state_flush_records_005de6bc[record_index + 1u]) {
            render_state_flush_records_005de6bc[record_index + 1u] = value;
            const auto callback = reinterpret_cast<StateFlushCallback>(
                render_state_flush_callbacks_005de72c[i]);
            (void)callback(render_state_flush_records_005de6bc[record_index], value);
        }
    }
}

} // namespace

void __fastcall scene_blur_state_quality_00537a30(
    void* self, void* /*unused_edx*/, std::uint32_t value) {
    store32(self, 0x00u, value);
}

void __fastcall scene_blur_state_one_00537a40(
    void* self, void* /*unused_edx*/, std::uint32_t value) {
    store32(self, 0x04u, value);
}

void __fastcall scene_blur_state_flag_00537a70(
    void* self, void* /*unused_edx*/, std::uint32_t value) {
    store32(self, 0x14u, value);
    store32(self, 0x18u, value);
}

void __fastcall scene_blur_state_commit_00536470(
    void* self, void* /*unused_edx*/, const void* state_28_bytes) {
    auto* committed = static_cast<B*>(self) + 0x38u;
    std::memcpy(committed, state_28_bytes, 28u);
    const void* service_sub = load_ptr(game_setup_movie_service_0069ed0c, 0x04u);
    if (load_ptr(service_sub, 0x08u) == self) {
        flush_state_bank(committed, 0u);
    } else if (load_ptr(service_sub, 0x0cu) == self) {
        flush_state_bank(committed, 14u);
    }
}

} // namespace porsche
