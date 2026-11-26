// Original Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
#include "crt_wide_compare_862.hpp"
#include "porsche/exit_registry.hpp"
#include "porsche/formatter_lowio.hpp"
#include "porsche/formatter_text.hpp"
namespace porsche {
std::uint32_t crt_wide_collate_locale_006afd7c=0u;
std::uint32_t crt_wide_collate_codepage_006afd94=0u;
int __cdecl crt_wcsnicoll_005ad68c(const wchar_t* left,const wchar_t* right,std::uint32_t count) {
    if(count==0u)return 0;
    std::uint32_t locale=crt_wide_collate_locale_006afd7c;
    if(locale==0u)return crt_wcsnicoll_default_005ae901(left,right,count);
    formatter_text_increment_005b2258(&formatter_text_locale_readers_006c02e8);
    const bool writer=formatter_text_locale_writer_006c02e4!=0u;
    if(writer){
        formatter_text_decrement_005b2254(&formatter_text_locale_readers_006c02e8);
        exit_registry_lock_api_005a4ba4(19u);
    }
    locale=crt_wide_collate_locale_006afd7c;
    if(locale==0u){
        if(writer)exit_registry_unlock_api_005a4c05(19u);
        else formatter_text_decrement_005b2254(&formatter_text_locale_readers_006c02e8);
        return crt_wcsnicoll_default_005ae901(left,right,count);
    }
    const int compared=crt_wcsnicoll_locale_005ae6b6(locale,0x1001u,left,
        static_cast<int>(count),right,static_cast<int>(count),crt_wide_collate_codepage_006afd94);
    if(writer)exit_registry_unlock_api_005a4c05(19u);
    else formatter_text_decrement_005b2254(&formatter_text_locale_readers_006c02e8);
    if(compared==0){
        *formatter_lowio_errno_005a669e()=22;
        return 0x7fffffff;
    }
    return compared-2;
}
}
