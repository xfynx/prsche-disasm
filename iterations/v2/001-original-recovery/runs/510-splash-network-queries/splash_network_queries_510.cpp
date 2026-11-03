// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
// Four original queries195B; canonical network root, one new loader-zero DWORD.
#include "splash_network_queries_510.hpp"
#include "porsche/splash_progress.hpp"
#include "porsche/startup_services.hpp"
#include <cstring>
namespace porsche {
namespace {
using U=std::uint32_t;using B=std::uint8_t;
U read(const void* p,U off){U value;std::memcpy(&value,static_cast<const B*>(p)+off,4);return value;}
std::uint16_t word(const void* p){std::uint16_t value;std::memcpy(&value,p,2);return value;}
void* pointer(U address){return reinterpret_cast<void*>(address);}
}
U splash_render_format_00691e50=0;
std::int32_t __cdecl splash_progress_find_item_0048d720(std::int32_t key){
    const auto* root=static_cast<const B*>(startup_network_00628c70);
    if(!root||read(root,8)==0||root[0xbf]!=0)return 0;
    const void* head=pointer(read(root,0x260));
    for(void* node=pointer(read(head,0));node!=head;node=pointer(read(node,0))){
        const U item=read(node,8);
        if(read(pointer(item),0x4c)==static_cast<U>(key))return static_cast<std::int32_t>(item);
    }
    return 0;
}
std::uint8_t __fastcall splash_progress_item_visible_00490390(void* item){
    const auto* root=static_cast<const B*>(startup_network_00628c70);
    if(!root||read(root,8)==0||root[0xbf]!=0||root[0xbe]==0||static_cast<std::int32_t>(read(root,0xdc))<0)return 0;
    const U shift=read(item,0x40)&31u;
    return static_cast<std::uint8_t>((static_cast<U>(root[0xe5])&(1u<<shift))!=0);
}
void* __fastcall network_item_data_004903f0(void* item,void*,std::int16_t key){
    const void* head=pointer(read(item,0x5c));
    for(void* node=pointer(read(head,0));node!=head;node=pointer(read(node,0))){
        void* data=pointer(read(node,8));
        if(word(data)==static_cast<std::uint16_t>(key))return data;
    }
    return nullptr;
}
void* __cdecl splash_progress_item_data_004903f0(void* item,std::int16_t key){
    return network_item_data_004903f0(item,nullptr,key);
}
U __cdecl splash_progress_render_format_005032d0(){return splash_render_format_00691e50;}
}
