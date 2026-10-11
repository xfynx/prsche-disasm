#pragma once

#include <cstddef>
#include <cstdint>

namespace porsche {

// Caller-owned storage observed at app_main+0x18.  The original routines use
// byte/DWORD views within this exact 0x180-byte stack span.
struct alignas(4) ApplicationSetupContext {
    std::uint8_t bytes[0x180];
};
static_assert(sizeof(ApplicationSetupContext) == 0x180);

ApplicationSetupContext* __fastcall application_setup_context_construct_004d1a90(
    ApplicationSetupContext* context,void* unused_edx);
std::uint32_t __fastcall application_setup_context_destroy_004d1ba0(
    ApplicationSetupContext* context,void* unused_edx);

// Original callees outside this recovered block. These are typed boundaries,
// not assumed no-op implementations.
ApplicationSetupContext* __fastcall application_context_base_construct_00525e20(
    ApplicationSetupContext* context,void* unused_edx);
void* __fastcall application_context_member_construct_005294c0(void* member,void* unused_edx);
void __fastcall application_context_member_destroy_005295b0(void* member,void* unused_edx);
std::uint32_t __fastcall application_context_base_destroy_00525ec0(
    ApplicationSetupContext* context,void* unused_edx);

} // namespace porsche
