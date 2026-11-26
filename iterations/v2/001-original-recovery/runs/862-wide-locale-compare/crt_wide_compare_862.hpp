#pragma once
#include <cstdint>
namespace porsche {
extern std::uint32_t crt_wide_collate_locale_006afd7c;
extern std::uint32_t crt_wide_collate_codepage_006afd94;
int __cdecl crt_wcsnicoll_005ad68c(const wchar_t*,const wchar_t*,std::uint32_t);
int __cdecl crt_wcsnicoll_default_005ae901(const wchar_t*,const wchar_t*,std::uint32_t);
int __cdecl crt_wcsnicoll_locale_005ae6b6(std::uint32_t,std::uint32_t,const wchar_t*,int,const wchar_t*,int,std::uint32_t);
}
