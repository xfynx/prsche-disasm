#pragma once
#include <cstdint>
namespace porsche {
extern std::uint32_t session_extension_flags_005e7484[10];
extern std::uint32_t session_extension_count_005e747c;
extern std::uint8_t session_extension_records_005e6e38[10][0xa0];
void __cdecl session_extension_clear_0040b490();
void __cdecl session_extension_clear_0040b4b0();
void* __cdecl session_extension_allocate_0040b530(std::uint32_t ignored_size);
void __cdecl session_extension_release_0040b570(void* pointer);
void __cdecl session_extension_service_00406520();
void __cdecl frame_reset_service_00406710();
}
