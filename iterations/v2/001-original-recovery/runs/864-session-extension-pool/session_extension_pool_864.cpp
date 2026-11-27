#include "session_extension_pool_864.hpp"
namespace porsche {
std::uint32_t session_extension_flags_005e7484[10];
std::uint32_t session_extension_count_005e747c;
std::uint8_t session_extension_records_005e6e38[10][0xa0];
void __cdecl session_extension_clear_0040b490() {
    for (auto& flag : session_extension_flags_005e7484) flag = 0;
    session_extension_count_005e747c = 0;
}
void __cdecl session_extension_clear_0040b4b0() {
    session_extension_clear_0040b490();
}
void* __cdecl session_extension_allocate_0040b530(std::uint32_t ignored_size) {
    (void)ignored_size;
    for (unsigned i = 0; i < 10; ++i) {
        if (session_extension_flags_005e7484[i] == 0) {
            session_extension_flags_005e7484[i] = 1;
            return session_extension_records_005e6e38[i];
        }
    }
    return nullptr;
}
void __cdecl session_extension_release_0040b570(void* pointer) {
    for (unsigned i = 0; i < 10; ++i) {
        if (pointer == session_extension_records_005e6e38[i]) {
            session_extension_flags_005e7484[i] = 0;
            return;
        }
    }
}
void __cdecl frame_reset_service_00406710() {
    session_extension_clear_0040b4b0();
    session_extension_service_00406520();
}
}
