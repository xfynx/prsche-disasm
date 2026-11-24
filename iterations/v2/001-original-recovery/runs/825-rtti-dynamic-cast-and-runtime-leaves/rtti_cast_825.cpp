// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#include "rtti_cast_825.hpp"

#include "porsche/application_alloc.hpp"
#include "porsche/formatter_bootstrap.hpp"
#include "porsche/formatter_runtime.hpp"
#include "porsche/rtti.hpp"

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>

#include <cstddef>
#include <cstring>

namespace porsche {

namespace {

std::uint32_t read_u32(const void* ptr, std::size_t offset) {
    std::uint32_t value = 0u;
    std::memcpy(&value, static_cast<const std::uint8_t*>(ptr) + offset, sizeof(value));
    return value;
}

const void* const kExceptionVtable_005c1a88[2] = {nullptr, nullptr};
const void* const kBadCastVtable_005c1960[2] = {nullptr, nullptr};
const void* const kNonRttiVtable_005c1924[2] = {nullptr, nullptr};
const std::uint32_t kBadCastThrowInfo_005c9ad0[4] = {0u, 0u, 0u, 0u};
const std::uint32_t kNonRttiThrowInfo_005c9a90[4] = {0u, 0u, 0u, 0u};

bool try_rtti_lookup(
    std::uint32_t element,
    std::uint32_t vf_delta,
    const RttiTypePrefix* src_type,
    const RttiTypePrefix* dst_type,
    std::uint32_t* out_result) {
    __try {
        void* const raw_elem = reinterpret_cast<void*>(static_cast<std::uintptr_t>(element));
        void* const complete = rtti_complete_object_005a14b3(raw_elem);
        const std::uint32_t vptr = read_u32(raw_elem, 0u);
        const std::uint32_t col_addr = read_u32(
            reinterpret_cast<const void*>(static_cast<std::uintptr_t>(vptr - 4u)), 0u);
        const auto* col = reinterpret_cast<const RttiCompleteObjectLocator*>(
            static_cast<std::uintptr_t>(col_addr));
        const std::uint32_t adjusted = element - vf_delta;
        const std::uint32_t complete_addr =
            static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(complete));
        const std::uint32_t offset = adjusted - complete_addr;
        const std::uint32_t hierarchy_addr = read_u32(col, 0x10u);
        const std::uint32_t attributes = read_u32(
            reinterpret_cast<const void*>(static_cast<std::uintptr_t>(hierarchy_addr)), 4u);
        const RttiBaseDescriptor* base = nullptr;
        if ((attributes & 1u) == 0u) {
            base = rtti_find_single_005a14cd(complete, col, src_type, offset, dst_type);
        } else if ((attributes & 2u) == 0u) {
            base = rtti_find_multiple_005a1527(complete, col, src_type, offset, dst_type);
        } else {
            base = rtti_find_virtual_005a1620(complete, col, src_type, offset, dst_type);
        }
        if (base != nullptr) {
            const auto* pmd = reinterpret_cast<const RttiPmd*>(
                reinterpret_cast<const std::uint8_t*>(base) + 8);
            *out_result = complete_addr + rtti_pmd_offset_005a1758(complete, pmd);
        } else {
            *out_result = 0u;
        }
        return true;
    } __except (GetExceptionCode() == 0xC0000005u
                    ? EXCEPTION_EXECUTE_HANDLER
                    : EXCEPTION_CONTINUE_SEARCH) {
        return false;
    }
}

} // namespace

void* __fastcall rtti_exception_ctor_005a5088(
    RttiStdException* self, void* /*unused_edx*/, const char* const* message_ptr) {
    self->vtable = kExceptionVtable_005c1a88;
    const char* const message = *message_ptr;
    const std::uint32_t length = formatter_strlen_005a6730(message);
    auto* const buffer = static_cast<char*>(startup_network_allocate_0059ef90(length + 1u));
    self->what = buffer;
    if (buffer != nullptr) {
        formatter_error_copy_005aa4e0(buffer, message);
    }
    self->do_free = 1u;
    return self;
}

void* __fastcall rtti_bad_cast_ctor_005a1462(
    RttiStdException* self, void* /*unused_edx*/, const char* const* message_ptr) {
    rtti_exception_ctor_005a5088(self, nullptr, message_ptr);
    self->vtable = kBadCastVtable_005c1960;
    return self;
}

void* __fastcall rtti_non_rtti_object_005a12f9(
    RttiStdException* self, void* /*unused_edx*/, const char* message) {
    const char* local_message = message;
    rtti_exception_ctor_005a5088(self, nullptr, &local_message);
    self->vtable = kNonRttiVtable_005c1924;
    return self;
}

void __stdcall rtti_cxx_throw_005a5304(
    void* exception_object, const void* throw_info) {
    ULONG_PTR params[3] = {
        static_cast<ULONG_PTR>(0x19930520u),
        reinterpret_cast<ULONG_PTR>(exception_object),
        reinterpret_cast<ULONG_PTR>(throw_info)
    };
    RaiseException(0xE06D7363u, 1u, 3u, params);
}

std::uint32_t __cdecl formatter_compare_005a134b(
    std::uint32_t element,
    std::uint32_t arg1,
    const void* scene_rtti,
    const void* camera_rtti,
    std::uint32_t arg4) {
    if (element == 0u) {
        return 0u;
    }
    std::uint32_t result = 0u;
    if (!try_rtti_lookup(
            element,
            arg1,
            static_cast<const RttiTypePrefix*>(scene_rtti),
            static_cast<const RttiTypePrefix*>(camera_rtti),
            &result)) {
        RttiStdException ex{};
        rtti_non_rtti_object_005a12f9(&ex, nullptr, "Access violation - no RTTI data!");
        rtti_cxx_throw_005a5304(&ex, kNonRttiThrowInfo_005c9a90);
        return 0u;
    }
    if (result != 0u || arg4 == 0u) {
        return result;
    }
    RttiStdException ex{};
    const char* message = "Bad dynamic_cast!";
    rtti_bad_cast_ctor_005a1462(&ex, nullptr, &message);
    rtti_cxx_throw_005a5304(&ex, kBadCastThrowInfo_005c9ad0);
    return 0u;
}

} // namespace porsche
