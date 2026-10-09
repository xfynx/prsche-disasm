#include "porsche/window_procedure.hpp"
#include <iostream>
#include <cstring>
namespace porsche {
static std::uint8_t configuration[0x474];
void* window_configuration_address_006b77a0=configuration;
static std::uint32_t handled,answer,fallback,callback_calls,default_calls;
static bool arguments_ok;
static std::uint32_t message_expected;
std::uint32_t __stdcall test_handler(void* config,void* hwnd,std::uint32_t message,
    std::uint32_t wp,std::int32_t lp,std::int32_t* out) {
    ++callback_calls;
    arguments_ok=arguments_ok && config==configuration && hwnd==reinterpret_cast<void*>(0x1234)
        && message==message_expected && wp==0x89abcdef && static_cast<std::uint32_t>(lp)==0xfedcba98
        && *out==0;
    *out=static_cast<std::int32_t>(answer);return handled;
}
std::int32_t __stdcall window_default_procedure(void* hwnd,std::uint32_t message,
    std::uint32_t wp,std::int32_t lp) {
    ++default_calls;arguments_ok=arguments_ok && hwnd==reinterpret_cast<void*>(0x1234)
        && message==message_expected && wp==0x89abcdef && static_cast<std::uint32_t>(lp)==0xfedcba98;
    return static_cast<std::int32_t>(fallback);
}
}
int main() {
    using namespace porsche;
    std::uint32_t kind,count,message;
    while(std::cin>>kind>>count>>message>>handled>>answer>>fallback) {
        if(count>128)return 2;
        callback_calls=default_calls=0;arguments_ok=true;message_expected=message;
        std::memset(window_handlers_0069e0e0,0xcc,sizeof(window_handlers_0069e0e0));
        window_handler_count_0069e570=count;
        for(std::uint32_t i=0;i<count;++i)window_handlers_0069e0e0[i]={i*3+1,&test_handler};
        std::uint32_t result;
        if(kind==0)result=static_cast<std::uint32_t>(window_procedure_0053aba0(
            reinterpret_cast<void*>(0x1234),message,0x89abcdef,static_cast<std::int32_t>(0xfedcba98)));
        else if(kind==1)result=static_cast<std::uint32_t>(window_message_compare_0053a7f0(&message,&answer));
        else {
            auto* row=static_cast<WindowHandlerEntry*>(original_binary_search_005a2f23(&message,
                window_handlers_0069e0e0,count,8,window_message_compare_0053a7f0));
            result=row?static_cast<std::uint32_t>(row-window_handlers_0069e0e0)+1:0;
        }
        std::cout<<result<<' '<<callback_calls<<' '<<default_calls<<' '<<arguments_ok<<'\n';
    }
}
