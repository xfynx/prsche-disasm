#include "porsche/window_callback_bindings.hpp"
#include "porsche/window_handlers.hpp"
#include "porsche/window_keys.hpp"
#include "porsche/window_messages.hpp"
#include <cstdint>
#include <iostream>
#include <vector>

namespace porsche {
#define CALLBACK_STUB(name,ret) std::uint32_t __stdcall name(void*,void*,std::uint32_t,std::uint32_t,std::int32_t,std::int32_t*){return ret;}
CALLBACK_STUB(window_handler_0053b040,0x40)
CALLBACK_STUB(window_key_activation_0053b050,0x50)
CALLBACK_STUB(window_handler_0053b230,0x230)
CALLBACK_STUB(window_handler_0053b260,0x260)
CALLBACK_STUB(window_handler_0053b290,0x290)
CALLBACK_STUB(window_handler_0053b2a0,0x2a0)
CALLBACK_STUB(window_handler_0053b2e0,0x2e0)
CALLBACK_STUB(window_message_0053b360,0x360)
CALLBACK_STUB(window_message_0053b3d0,0x3d0)
CALLBACK_STUB(window_key_down_0053b450,0x450)
CALLBACK_STUB(window_message_0053b6b0,0x6b0)
CALLBACK_STUB(window_message_0053b710,0x710)
CALLBACK_STUB(window_message_0053b770,0x770)
CALLBACK_STUB(window_message_0053b7d0,0x7d0)
CALLBACK_STUB(window_handler_0053b870,0x870)
CALLBACK_STUB(window_handler_0053b8b0,0x8b0)
#undef CALLBACK_STUB
}

int main() {
    std::size_t count=0;
    if(!(std::cin>>count) || count>128)return 2;
    std::vector<std::uint32_t> pairs(count*2);
    for(auto& v:pairs)if(!(std::cin>>v))return 3;
    std::vector<porsche::WindowHandlerEntry> output(count);
    std::uint32_t unresolved=0;
    const bool ok=porsche::window_callback_relocate_table(
        pairs.data(),count,output.data(),output.size(),&unresolved);
    std::cout<<"R "<<(ok?1:0)<<' '<<unresolved<<' '<<count<<'\n';
    if(ok)for(std::size_t i=0;i<count;++i)
        std::cout<<"E "<<output[i].message<<' '<<pairs[i*2+1]<<' '
          <<static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(output[i].handler))<<'\n';
    std::size_t bindings_count=0;
    const auto* bindings=porsche::window_callback_relocations(&bindings_count);
    std::cout<<"B "<<bindings_count<<'\n';
    for(std::size_t i=0;i<bindings_count;++i)
        std::cout<<"M "<<bindings[i].original_va<<' '
          <<static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(bindings[i].native_callback))<<'\n';
    std::cout<<"U "<<(porsche::window_callback_resolve(0x0053ffffu)?1:0)<<'\n';
    const std::uint32_t unknown_pair[]={0x777u,0x0053ffffu};
    porsche::WindowHandlerEntry sentinel{0xabcdu,porsche::window_callback_resolve(0x0053b040u)};
    std::uint32_t unknown_va=0;
    const bool unknown_ok=porsche::window_callback_relocate_table(
        unknown_pair,1,&sentinel,1,&unknown_va);
    const bool unchanged=sentinel.message==0xabcdu &&
        sentinel.handler==porsche::window_callback_resolve(0x0053b040u);
    const auto unknown_value=unknown_va;
    std::uint32_t capacity_unresolved=0xeeeeeeeeu;
    const bool capacity_ok=porsche::window_callback_relocate_table(
        pairs.data(),1,output.data(),0,&capacity_unresolved);
    std::cout<<"T "<<(unknown_ok?1:0)<<' '<<unknown_value<<' '
      <<(unchanged?1:0)<<' '<<(capacity_ok?1:0)<<' '
      <<capacity_unresolved<<'\n';
}
