#include "porsche/window_callback_bindings.hpp"
#include "porsche/window_handlers.hpp"
#include "porsche/window_keys.hpp"
#include "porsche/window_messages.hpp"

namespace porsche {
namespace {
constexpr WindowCallbackRelocation relocations[]={
    {0x0053b040,&window_handler_0053b040},
    {0x0053b050,&window_key_activation_0053b050},
    {0x0053b230,&window_handler_0053b230},
    {0x0053b260,&window_handler_0053b260},
    {0x0053b290,&window_handler_0053b290},
    {0x0053b2a0,&window_handler_0053b2a0},
    {0x0053b2e0,&window_handler_0053b2e0},
    {0x0053b360,&window_message_0053b360},
    {0x0053b3d0,&window_message_0053b3d0},
    {0x0053b450,&window_key_down_0053b450},
    {0x0053b6b0,&window_message_0053b6b0},
    {0x0053b710,&window_message_0053b710},
    {0x0053b770,&window_message_0053b770},
    {0x0053b7d0,&window_message_0053b7d0},
    {0x0053b870,&window_handler_0053b870},
    {0x0053b8b0,&window_handler_0053b8b0},
};
}

const WindowCallbackRelocation* window_callback_relocations(std::size_t* count) {
    if(count)*count=sizeof(relocations)/sizeof(relocations[0]);
    return relocations;
}

WindowHandler window_callback_resolve(std::uint32_t original_va) {
    for(const auto& entry:relocations)
        if(entry.original_va==original_va)return entry.native_callback;
    return nullptr;
}

bool window_callback_relocate_table(const std::uint32_t* pairs,std::size_t count,
    WindowHandlerEntry* output,std::size_t output_capacity,std::uint32_t* unresolved_va) {
    if(unresolved_va)*unresolved_va=0;
    if((count && (!pairs || !output)) || count>output_capacity)return false;
    for(std::size_t i=0;i<count;++i) {
        const auto guest_va=pairs[i*2+1];
        if(!window_callback_resolve(guest_va)) {
            if(unresolved_va)*unresolved_va=guest_va;
            return false;
        }
    }
    for(std::size_t i=0;i<count;++i)
        output[i]={pairs[i*2],window_callback_resolve(pairs[i*2+1])};
    return true;
}
}
