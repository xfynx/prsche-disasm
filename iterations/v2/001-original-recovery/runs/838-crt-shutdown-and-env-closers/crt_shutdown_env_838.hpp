#pragma once

#include "porsche/formatter_original.hpp"

#include <cstdint>

namespace porsche {

extern std::int32_t crt_nstream_006c1520;
extern FormatterOriginalDescriptor32** crt_piob_006c0508;

extern std::uint32_t crt_env_initialized_006c1528;
extern char** crt_environ_006afcc8;
extern char** crt_initenv_006afccc;
extern wchar_t** crt_wenviron_006afcd0;
extern std::uint32_t crt_compare_use_mode_006b0028;

int __cdecl crt_flushall_005a76fd();
int __cdecl crt_flsall_005a7706(int flush_flag);
int __cdecl crt_fflush_nolock_005a7673(FormatterOriginalDescriptor32* stream);
int __cdecl crt_commit_005acbea(std::uint32_t file_id);
int __cdecl crt_fcloseall_005a9dc8();
int __cdecl crt_fclose_005a2024(FormatterOriginalDescriptor32* stream);
int __cdecl crt_fclose_lk_005a2055(FormatterOriginalDescriptor32* stream);
void __cdecl crt_freebuf_005a7648(FormatterOriginalDescriptor32* stream);
int __cdecl crt_close_005a7568(std::uint32_t file_id);
int __cdecl crt_close_lk_005a75c5(std::uint32_t file_id);

const char* __cdecl application_diagnostic_environment_inner_005a3071(const char* varname);
int __cdecl crt_mbtow_environ_005a9a4a();
int __cdecl crt_setenv_005aa28f(char* option, int update_os);
int __cdecl crt_findenv_005aa416(const char* name, int len);
char** __cdecl crt_copy_environ_005aa46e(char** env);
char* __cdecl crt_strdup_005ad832(const char* s);
const char* __cdecl crt_mbschr_005ad79b(const char* s, std::uint32_t c);
int __cdecl crt_mbsnbicoll_005a9a0b(const char* s1, const char* s2, std::uint32_t count);
int __cdecl crt_compare_string_a_005ad042(
    std::uint32_t locale,
    std::uint32_t cmp_flags,
    const char* s1,
    int count1,
    const char* s2,
    int count2,
    std::uint32_t code_page);

} // namespace porsche
