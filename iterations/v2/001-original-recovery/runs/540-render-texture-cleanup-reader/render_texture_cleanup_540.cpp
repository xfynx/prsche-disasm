// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Full554cc0/170B and56e290/24B;4RW/78RO. Normal slot domain in scope-evidence.json.
#include "render_texture_cleanup_540.hpp"
#include "porsche/fe_stream.hpp"
#include "porsche/files.hpp"
#include "porsche/shared_runtime_globals.hpp"
#include <cstring>
#include <intrin.h>
namespace porsche {
using U=std::uint32_t;using B=std::uint8_t;
U render_texture_count_006a3a40=0;
const char render_texture_cleanup_file_005bc294[30]="\\real\\patch3\\cmn\\dyntexture.c";
const char render_texture_cleanup_message_005bc2b4[48]="DTEX - DTEX_destroy error, texture not in list\n";
namespace {
U address(const void* p){return reinterpret_cast<U>(p);}
U get(const void* p,U offset){U v;std::memcpy(&v,reinterpret_cast<const void*>(address(p)+offset),4);return v;}
void put(void* p,U offset,U v){std::memcpy(reinterpret_cast<void*>(address(p)+offset),&v,4);}
}
U __cdecl render_descriptor_read_be_0056e290(const void* source,U count){
    const U value=get(source,0);
    return _byteswap_ulong(value)>>((32u-count*8u)&31u);
}
void __cdecl render_resource_texture_destroy_00554cc0(void* texture){
    const U slot=get(texture,4)*48u;
    U current=get(render_texture_slots_006a33f8,slot+0x24);
    if(current==address(texture)){
        put(render_texture_slots_006a33f8,slot+0x24,get(texture,0));
    }else{
        while(current){
            const U next=get(reinterpret_cast<void*>(current),0);
            if(next==address(texture))break;
            current=next;
        }
        if(!current||get(reinterpret_cast<void*>(current),0)!=address(texture)){
            diagnostic_file_005deb74_set(render_texture_cleanup_file_005bc294);
            shared_runtime_word_005deb78=0x6f1;
            diagnostic_handler_005debf0(render_texture_cleanup_message_005bc2b4);
            return;
        }
        put(reinterpret_cast<void*>(current),0,get(texture,0));
    }
    const U prior=get(render_texture_slots_006a33f8,slot),total=render_texture_count_006a3a40;
    put(render_texture_slots_006a33f8,slot,prior-1u);
    const U first=get(texture,0x14);
    render_texture_count_006a3a40=total-1u;
    if(first)(void)free_00531f90(reinterpret_cast<void*>(first));
    const U second=get(texture,0x1c);
    if(second)(void)free_00531f90(reinterpret_cast<void*>(second));
    (void)free_00531f90(texture);
}
}
