// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

namespace porsche {

struct RttiStdException {
    const void* vtable;
    const char* what;
    std::uint32_t do_free;
};
static_assert(sizeof(RttiStdException) == 12, "original x86 exception layout");

void* __fastcall rtti_exception_ctor_005a5088(
    RttiStdException* self, void* unused_edx, const char* const* message_ptr);
void* __fastcall rtti_bad_cast_ctor_005a1462(
    RttiStdException* self, void* unused_edx, const char* const* message_ptr);
void* __fastcall rtti_non_rtti_object_005a12f9(
    RttiStdException* self, void* unused_edx, const char* message);
void __stdcall rtti_cxx_throw_005a5304(
    void* exception_object, const void* throw_info);

std::uint32_t __cdecl formatter_compare_005a134b(
    std::uint32_t element,
    std::uint32_t arg1,
    const void* scene_rtti,
    const void* camera_rtti,
    std::uint32_t arg4);

} // namespace porsche
