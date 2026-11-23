// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 004a4760..004a477e, 31 bytes, sha256 476ea9048eabfd1f90aaaa01c039b316d6b6ffcd457de8a71758f615a5dc8dcd.
// Original 004ae470..004ae4c8, 89 bytes, sha256 02a5743de6d5b886d83f4c38d8891ef1bc3d4cc72fc47b5b55b2fe139b32dd77.
// Original 004b04d0..004b04dc, 13 bytes, sha256 3bfa59a6c602f6ec073d35a5599b03ef6872461d7f24d0dc01f698275de31dbc.
// Original 004ad4d0..004ad4ed, 30 bytes, sha256 232e2142a120314b22bf10861432701cee51f221f0b51b9bcc67263047cf0142.
// Original 005610e0..00561107, 40 bytes, sha256 913902718ff1a2c1415748323aa5f987e439274d69064c72591cbe95c57aca37.
#include "sim_audio_teardown_leaves_783.hpp"

#include <cstring>

namespace porsche {

std::uint8_t sim_audio_callback_registered_00656ab0 = 0u;

namespace {

using U = std::uint32_t;
using I = std::int32_t;
using B = std::uint8_t;

inline U read_u32(U addr) noexcept {
    U value = 0u;
    std::memcpy(&value, reinterpret_cast<const void*>(static_cast<std::uintptr_t>(addr)), sizeof value);
    return value;
}

inline void write_u32(U addr, U value) noexcept {
    std::memcpy(reinterpret_cast<void*>(static_cast<std::uintptr_t>(addr)), &value, sizeof value);
}

inline void write_u8(U addr, B value) noexcept {
    std::memcpy(reinterpret_cast<void*>(static_cast<std::uintptr_t>(addr)), &value, sizeof value);
}

inline U va_from_ptr(const void* ptr) noexcept {
    return static_cast<U>(reinterpret_cast<std::uintptr_t>(ptr));
}

} // namespace

void __cdecl application_sim_boundary_004a4760() {
    if (startup_clock_initialized_00655a04 != 0u) {
        startup_clock_initialized_00655a04 = 0u;
        network_lifecycle_remove_callback_00560180(0x004a45d0u);
    }
}

void __cdecl application_sim_boundary_004ae470(
    std::int32_t first,
    std::uint32_t* second) {
    U root = audio_resource_query_root_00656ab4;
    if (root == 0u) {
        return;
    }
    write_u32(root + 0x08u, 0u);
    if (first <= 0) {
        return;
    }

    for (I i = 0; i < first; ++i) {
        const I candidate = static_cast<I>(second[i]);
        root = audio_resource_query_root_00656ab4;
        if (candidate >= 0 && candidate < static_cast<I>(read_u32(root + 0x04u))) {
            const U count = read_u32(root + 0x08u);
            write_u8(root + count + 0xe8u, static_cast<B>(candidate));
            root = audio_resource_query_root_00656ab4;
            write_u32(root + 0x08u, read_u32(root + 0x08u) + 1u);
        }
    }
}

std::int32_t __cdecl application_sim_boundary_004b04d0(
    std::int32_t first,
    std::int32_t second) {
    return second + first * 2 + 1;
}

void __cdecl application_sim_boundary_004ad4d0() {
    if (sim_audio_callback_registered_00656ab0 == 0u) {
        audio_device_register_callback_005610e0(0x004ac290u);
        sim_audio_callback_registered_00656ab0 = 1u;
    }
}

void __cdecl audio_device_register_callback_005610e0(std::uint32_t callback_va) {
    if (application_audio_device_state_006b48c0[0xdcu] != 0u) {
        const I count = static_cast<std::int8_t>(application_audio_device_state_006b48c0[0xe0u]);
        const U slot_va = va_from_ptr(&application_audio_device_state_006b48c0[0xf0u]) +
            static_cast<U>(count * 4);
        write_u32(slot_va, callback_va);
        application_audio_device_state_006b48c0[0xe0u] =
            static_cast<B>(application_audio_device_state_006b48c0[0xe0u] + 1u);
    }
}

} // namespace porsche
