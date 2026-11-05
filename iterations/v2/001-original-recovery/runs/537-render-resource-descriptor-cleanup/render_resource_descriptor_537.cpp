// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Complete535d30/75B,556690/183B,537fb0/136B,554de0/80B.
#include "render_resource_descriptor_537.hpp"
#include "render_descriptor.hpp"
#include "porsche/application_alloc.hpp"
#include "porsche/shared_runtime_globals.hpp"
#include "porsche/files.hpp"
#include "nibble_memory_512.hpp"
#include <cstring>
namespace porsche {
using U=std::uint32_t;using B=std::uint8_t;
B render_texture_slots_006a33f8[32*48]{};
const char render_palette_message_005bb81c[41]="SHAPE_clut - INVALID SHAPE TYPE ($%02x)\n";
const char render_palette_file_005bb848[19]="\\real\\pc\\shpclut.c";
namespace {
U address(const void* p){return reinterpret_cast<U>(p);}
U get(const void* p,U offset){U v;std::memcpy(&v,reinterpret_cast<const void*>(address(p)+offset),4);return v;}
void put(void* p,U offset,U v){std::memcpy(reinterpret_cast<void*>(address(p)+offset),&v,4);}
}
void* __fastcall render_resource_node_destroy_00535d30(void* self,void*,U flags){
    void* counter=reinterpret_cast<void*>(get(self,0x20));
    put(self,0,address(render_resource_node_table_005bb6d4));
    const U prior=nibble512::read32(address(counter));put(counter,0,prior-1);
    counter=reinterpret_cast<void*>(get(self,0x20));
    if(nibble512::read32(address(counter))==0){
        void* texture=reinterpret_cast<void*>(get(self,8));
        if(texture)render_resource_texture_destroy_00554cc0(texture);
        (void)application_release_0059f050(reinterpret_cast<void*>(get(self,0x20)));
    }
    if(flags&1)(void)application_release_0059f050(self);
    return self;
}
U __cdecl render_resource_node_format_00556690(const void* descriptor){
    U format=0;if(!descriptor)return format;
    switch(get(descriptor,0)&0xff){
    case 1:case 0x2d:case 0x40:case 0x7a:format=1;break;
    case 2:case 0x23:case 0x29:case 0x41:case 0x7b:format=2;break;
    case 3:case 0x42:case 0x7e:format=3;break;
    case 4:case 0x43:case 0x7f:format=5;break;
    case 5:case 0x20:case 0x7d:format=6;break;
    case 0x21:case 0x2a:case 0x78:format=4;break;
    case 0x24:return 0;case 0x6d:format=7;break;
    case 0xf8:
        if(render_descriptor_read_be_0056e290(reinterpret_cast<const void*>(address(descriptor)+0x10),2)==0x18fb)format=12;
        [[fallthrough]];
    case 0xfd:
        if(render_descriptor_read_be_0056e290(reinterpret_cast<const void*>(address(descriptor)+0x10),2)==0x1afb)format=13;
        if(!format)return 0;break;
    default:return 0;
    }
    if(get(descriptor,0xc)&0x2000)format|=0x80000000;
    return format;
}
void* __cdecl render_resource_node_palette_00537fb0(const void* descriptor){
    U cursor=address(descriptor);if(!cursor)return nullptr;
    if(!render_descriptor_bits_00537f90(descriptor)){
        const U type=get(descriptor,0)&0xff;
        diagnostic_file_005deb74_set(render_palette_file_005bb848);
        shared_runtime_word_005deb78=0x45;
        reinterpret_cast<void (__cdecl*)(const char*,...)>(diagnostic_handler_005debf0)(render_palette_message_005bb81c,type);
    }
    do {
        const U header=get(reinterpret_cast<const void*>(cursor),0);
        switch(header&0xff){case 0x22:case 0x24:case 0x23:case 0x29:case 0x2a:case 0x2c:case 0x2d:case 0x2e:return reinterpret_cast<void*>(cursor);}
        if(!(header&0xffffff00))return nullptr;
        cursor+=static_cast<U>(static_cast<std::int32_t>(header)>>8);
    }while(cursor);
    return nullptr;
}
U __cdecl render_resource_texture_query_00554de0(void* texture,void* output){
    if(!texture)return 0;
    put(output,0,get(texture,0x20));put(output,4,get(texture,0x14));put(output,8,get(texture,0x18));
    const U auxiliary=static_cast<B*>(texture)[0x2c]&8?get(texture,0x1c):0;
    put(output,0xc,auxiliary);
    const U slot=get(texture,4),flags=get(texture,0x24);
    put(output,0x14,flags);
    put(output,0x10,get(render_texture_slots_006a33f8,slot*48+8));
    return 1;
}
}
