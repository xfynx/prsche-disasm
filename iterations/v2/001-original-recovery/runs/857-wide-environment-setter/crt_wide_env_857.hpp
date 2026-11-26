#pragma once

#include <cstdint>

namespace porsche {

extern wchar_t** crt_winitenv_006afcd4;

using CrtSetEnvironmentVariableW857 = int(__stdcall*)(const wchar_t*, const wchar_t*);
extern CrtSetEnvironmentVariableW857 crt_set_environment_variable_w_api_857;

int __cdecl crt_wsetenv_005aa039(wchar_t* option, int update_os);
int __cdecl crt_wfindenv_005aa1cc(const wchar_t* name, int length);
wchar_t** __cdecl crt_copy_wenviron_005aa228(wchar_t** env);
int __cdecl crt_mbtow_environ_wide_005ad5fb();
wchar_t* __cdecl crt_wcschr_005ad663(const wchar_t* text, std::uint32_t ch);
wchar_t* __cdecl crt_wcscpy_005ad5b9(wchar_t* destination, const wchar_t* source);
std::uint32_t __cdecl crt_wcslen_005ad5de(const wchar_t* text);
wchar_t* __cdecl crt_wcsdup_005ad76d(const wchar_t* text);

// Locale-sensitive helper remains the next exact boundary. It is not replaced
// by an ordinal or ASCII-only comparison.
int __cdecl crt_wcsnicoll_005ad68c(
    const wchar_t* left, const wchar_t* right, std::uint32_t count);

} // namespace porsche
