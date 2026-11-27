// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
#pragma once

#include <cstdint>

namespace porsche {

extern const std::uint16_t crt_ctype_table_005e52d8[257];
extern const std::uint16_t* crt_pctype_ptr_005e52d4;

extern std::uint32_t crt_string_type_use_mode_006b0050;
extern std::uint32_t crt_compare_w_use_mode_006b0058;
extern std::uint32_t crt_lcmap_use_mode_006b0064;

int __cdecl crt_wcsnicoll_default_005ae901(
    const wchar_t* left, const wchar_t* right, std::uint32_t count);
int __cdecl crt_wcsnicoll_locale_005ae6b6(
    std::uint32_t locale, std::uint32_t cmp_flags,
    const wchar_t* s1, int count1,
    const wchar_t* s2, int count2,
    std::uint32_t code_page);

std::uint16_t __cdecl crt_towlower_lk_005aea71(std::uint16_t ch);
int __cdecl crt_iswctype_lk_005aecef(std::uint16_t ch, std::uint16_t mask);
int __cdecl crt_get_string_type_w_005ae1f7(
    std::uint32_t info_type, const wchar_t* src, int src_count,
    std::uint16_t* char_type, std::uint32_t code_page, std::uint32_t lcid);
int __cdecl crt_lc_map_string_w_005aeae6(
    std::uint32_t locale, std::uint32_t map_flags,
    const wchar_t* src, int src_count,
    wchar_t* dst, int dst_count,
    std::uint32_t code_page);
int __cdecl crt_wcsnlen_005ae8d1(const wchar_t* s, int max_count);

} // namespace porsche
