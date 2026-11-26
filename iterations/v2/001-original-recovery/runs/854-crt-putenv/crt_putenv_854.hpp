#pragma once

#include <cstdint>

namespace porsche {

int __cdecl crt_putenv_005a38c7(const char* entry);
int __cdecl crt_putenv_inner_005a38e8(const char* entry);

// Typed original boundary. The narrow environment owner is recovered in
// Run838; the matching wide environment setter remains a later batch.
int __cdecl crt_wsetenv_005aa039(wchar_t* option, int update_os);

} // namespace porsche
