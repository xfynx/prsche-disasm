#include "porsche/window_procedure.hpp"
#include <cstring>

namespace porsche {
WindowHandlerEntry window_handlers_0069e0e0[128];
std::uint32_t window_handler_count_0069e570;

std::int32_t __cdecl window_message_compare_0053a7f0(const void* a,const void* b) {
    std::uint32_t x,y;std::memcpy(&x,a,4);std::memcpy(&y,b,4);
    return static_cast<std::int32_t>(x-y); // original SUB, including wraparound
}

// Exact lower-middle selection and unsigned x86 pointer bounds from 005a2f23.
// Inputs must describe a valid original 32-bit array and readable comparator.
void* __cdecl original_binary_search_005a2f23(const void* key,void* base,
    std::uint32_t count,std::uint32_t width,SearchCompare compare) {
    auto low=static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(base));
    auto high=low+(count-1)*width;
    while(low<=high) {
        const auto half=count>>1;
        if(!half) {
            if(!count)return nullptr;
            return compare(key,reinterpret_cast<void*>(low))?nullptr:reinterpret_cast<void*>(low);
        }
        const auto middle=low+((count&1)?half:half-1)*width;
        const auto result=compare(key,reinterpret_cast<void*>(middle));
        if(!result)return reinterpret_cast<void*>(middle);
        if(result<0) {high=middle-width;count=(count&1)?half:half-1;}
        else {low=middle+width;count=half;}
    }
    return nullptr;
}

std::int32_t __stdcall window_procedure_0053aba0(void* hwnd,std::uint32_t message,
    std::uint32_t wparam,std::int32_t lparam) {
    std::int32_t result=0;
    auto* entry=static_cast<WindowHandlerEntry*>(original_binary_search_005a2f23(
        &message,window_handlers_0069e0e0,window_handler_count_0069e570,8,
        window_message_compare_0053a7f0));
    if(entry && entry->handler(window_configuration_address_006b77a0,hwnd,message,
        wparam,lparam,&result))return result;
    return window_default_procedure(hwnd,message,wparam,lparam);
}
}
