#pragma once
#include <cstdint>

namespace porsche {
// Porsche.exe SHA256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
extern void* application_instance_mutex_006a5c28;
extern std::uint32_t application_instance_exit_requested_005df9bc;

// 005655f0: selects/stores the mutex name, creates the named mutex, and on
// ERROR_ALREADY_EXISTS foregrounds a matching window before the exit check.
std::uint32_t __cdecl application_instance_check_005655f0(const char* name);

// Exact API/terminal boundaries. 00557370 is a two-instruction adapter to
// 005a246e(0); that final callee is not recovered here.
void* __cdecl application_instance_create_mutex(void* security_attributes,
    std::uint32_t initial_owner, const char* name);
std::uint32_t __cdecl application_instance_get_last_error();
void* __cdecl application_instance_find_window(const char* class_name,const char* title);
std::int32_t __cdecl application_instance_show_window(void* window,std::int32_t command);
std::int32_t __cdecl application_instance_set_foreground_window(void* window);
void __cdecl application_instance_exit_005a246e(std::uint32_t code);
}
