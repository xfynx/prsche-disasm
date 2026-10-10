#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "porsche/application_services.hpp"

namespace porsche {

std::int32_t __cdecl application_service_message_box_api(
    const char* text, const char* title) {
    return ::MessageBoxA(nullptr, text, title, 0);
}

std::int32_t __cdecl application_service_create_directory_api(
    const char* path) {
    return ::CreateDirectoryA(path, nullptr) ? 1 : 0;
}

} // namespace porsche
