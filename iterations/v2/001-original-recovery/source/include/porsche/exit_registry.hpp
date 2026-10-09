#pragma once
#include <cstdint>

namespace porsche {
// Original CRT registry globals: allocated base and one-past-last callback.
extern std::uint32_t* exit_registry_next_006c1530;
extern std::uint32_t* exit_registry_base_006c1534;

void __cdecl exit_registry_initialize_005a2412();
void* __cdecl exit_registry_append_005a2382(void(__cdecl* callback)());
std::int32_t __cdecl exit_registry_register_005a2400(void(__cdecl* callback)());
void __cdecl exit_registry_lock_enter_005a2535();
void __cdecl exit_registry_lock_leave_005a253e();

// Typed CRT and critical-section boundaries retained outside this recovery.
void* __cdecl exit_registry_malloc_005a3be5(std::uint32_t bytes);
void __cdecl exit_registry_fatal_005a2e22(std::uint32_t message_id);
std::uint32_t __cdecl exit_registry_allocation_size_005a8161(const void* allocation);
void* __cdecl exit_registry_reallocate_005a8029(void* allocation,std::uint32_t bytes);
void __cdecl exit_registry_lock_api_005a4ba4(std::uint32_t lock_id);
void __cdecl exit_registry_unlock_api_005a4c05(std::uint32_t lock_id);

// Link adapter for the accepted application-pool caller, which ignores the
// original 005a2400 integer result.
void __cdecl application_callback_registry_insert_005a2400(void(__cdecl* callback)());
}
