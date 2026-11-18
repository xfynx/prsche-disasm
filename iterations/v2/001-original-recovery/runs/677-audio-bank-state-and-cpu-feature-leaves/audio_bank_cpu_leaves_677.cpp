// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 00565b30..00565b52, 35 bytes, sha256 297d8c891b6e9fd4ebef2db3520f38c0fe843da5dc68a71f469087e7dadc2ac6.
// Original 00565ad0..00565b20, 81 bytes, sha256 c2e8154b16d4023e71d92a8b9a4021c9d867d7a62a24f2271abde91f21a74cbb.
// Original 00590140..00590168, 41 bytes, sha256 222ec12d808a6793fc0860627e39148a68ed6ffd13739b3d9d5e85cedec334d3.
// Original 00574e50..00574e6a, 27 bytes, sha256 18e33bf91423f5dfb61fd2a98e186b00d3238bac0b972ae91502cd938f3d4e11.
// Original 00574e6b..00574e88, 30 bytes, sha256 94884ce50dbc7092c39645556b3790b037a2928ce21c7d92a5eb782b89ab9cf1.
// Original 00574e89..00574eaa, 34 bytes, sha256 0d48bd62ae5b5922c48e5b19bf9752f1a4ac480194bb37e1d4db0b1712194b0e.
#include "audio_bank_cpu_leaves_677.hpp"

#include <cstring>
#include <intrin.h>

namespace porsche {

namespace {

inline void* ptr_from_va(std::uint32_t addr) noexcept {
    return reinterpret_cast<void*>(static_cast<std::uintptr_t>(addr));
}

inline std::uint32_t va_from_ptr(const void* ptr) noexcept {
    return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(ptr));
}

inline std::uint16_t read_u16_ptr(const void* ptr) noexcept {
    std::uint16_t value = 0u;
    std::memcpy(&value, ptr, sizeof value);
    return value;
}

inline std::uint32_t read_u32_ptr(const void* ptr) noexcept {
    std::uint32_t value = 0u;
    std::memcpy(&value, ptr, sizeof value);
    return value;
}

inline std::uint32_t read_va_u32(std::uint32_t addr) noexcept {
    return read_u32_ptr(ptr_from_va(addr));
}

inline void write_va_u32(std::uint32_t addr, std::uint32_t value) noexcept {
    std::memcpy(ptr_from_va(addr), &value, sizeof value);
}

} // namespace

std::int32_t __cdecl audio_bank_get_size_00565b30(std::int32_t bank_index) {
    if (application_audio_device_state_006b48c0[0xdcu] == 0u) {
        return -10;
    }
    const std::uint32_t table_va =
        read_u32_ptr(application_audio_device_state_006b48c0.data() + 0x144u);
    const std::uint32_t entry_va = table_va + static_cast<std::uint32_t>(bank_index) * 12u;
    const std::uint32_t bank_ptr_va = read_va_u32(entry_va);
    return static_cast<std::int32_t>(read_va_u32(bank_ptr_va + 8u));
}

std::int32_t __cdecl audio_bank_copy_00565ad0(void* dst_buffer, std::int32_t bank_index) {
    if (application_audio_device_state_006b48c0[0xdcu] == 0u) {
        return -10;
    }
    const std::int32_t byte_size = audio_bank_get_size_00565b30(bank_index);
    if (byte_size < 0) {
        return byte_size;
    }
    const std::uint32_t table_va =
        read_u32_ptr(application_audio_device_state_006b48c0.data() + 0x144u);
    const std::uint32_t entry_va = table_va + static_cast<std::uint32_t>(bank_index) * 12u;
    const std::uint32_t src_va = read_va_u32(entry_va);
    if (byte_size > 0) {
        std::memcpy(dst_buffer, ptr_from_va(src_va), static_cast<std::size_t>(byte_size));
    }
    write_va_u32(entry_va, va_from_ptr(dst_buffer));
    return 0;
}

std::int32_t __cdecl audio_bank_find_free_slot_00590140() {
    const std::uint16_t slot_count =
        read_u16_ptr(application_audio_device_state_006b48c0.data() + 0x18u);
    if (slot_count == 0u) {
        return -9;
    }
    const std::uint32_t table_va =
        read_u32_ptr(application_audio_device_state_006b48c0.data() + 0x144u);
    for (std::uint32_t i = 0u; i < static_cast<std::uint32_t>(slot_count); ++i) {
        if (read_va_u32(table_va + i * 12u) == 0u) {
            return static_cast<std::int32_t>(i);
        }
    }
    return -9;
}

std::uint32_t __cdecl cpu_check_cpuid_support_00574e50() {
#if defined(_MSC_VER) && defined(_M_IX86)
    const std::uint32_t original_flags = __readeflags();
    __writeeflags(original_flags ^ 0x00200000u);
    const std::uint32_t updated_flags = __readeflags();
    const std::uint32_t diff = updated_flags ^ original_flags;
    __writeeflags(original_flags);
    return diff;
#else
#error "cpu_check_cpuid_support_00574e50 requires MSVC x86"
#endif
}

void __cdecl cpu_query_cpuid_00574e6b(std::uint32_t* out_regs, std::uint32_t leaf) {
#if defined(_MSC_VER) && defined(_M_IX86)
    int regs[4] = {};
    __cpuid(regs, static_cast<int>(leaf));
    // Original writes EAX, EBX, EDX, ECX into out_regs[0..3].
    out_regs[0] = static_cast<std::uint32_t>(regs[0]);
    out_regs[1] = static_cast<std::uint32_t>(regs[1]);
    out_regs[2] = static_cast<std::uint32_t>(regs[3]);
    out_regs[3] = static_cast<std::uint32_t>(regs[2]);
#else
#error "cpu_query_cpuid_00574e6b requires MSVC x86"
#endif
}

std::uint32_t __cdecl cpu_check_div_flags_00574e89() {
#if defined(_MSC_VER) && defined(_M_IX86)
    std::uint32_t result = 0u;
    __asm {
        xor eax, eax
        sahf
        mov eax, 5
        mov ebx, 2
        div bl
        lahf
        cmp ah, 2
        mov eax, 0
        jne done
        mov eax, 1
    done:
        mov result, eax
    }
    return result;
#else
#error "cpu_check_div_flags_00574e89 requires MSVC x86"
#endif
}

} // namespace porsche
