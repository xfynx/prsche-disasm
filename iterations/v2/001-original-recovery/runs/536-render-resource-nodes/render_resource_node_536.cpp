// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Complete535bc0/365B,535ed0/224B,535d80/336B,5379d0/29B;6RW+4RO.
#include "render_resource_node_536.hpp"
#include "porsche/application_alloc.hpp"
#include "porsche/formatter_entry.hpp"
#include "porsche/render_display.hpp"
#include <cstring>
#include "../512-audio-nibble-decoders/nibble_memory_512.hpp"
namespace porsche {
using U=std::uint32_t;using B=std::uint8_t;
const U render_resource_node_table_005bb6d4[1]={reinterpret_cast<U>(&render_resource_node_destroy_00535d30)};
char render_resource_node_name_format_005de748[6]={'t','e','x','%','d',0};
namespace {
U word(const void* p){return reinterpret_cast<U>(p);}
U get(const void* p,U offset){U v;std::memcpy(&v,static_cast<const B*>(p)+offset,4);return v;}
void put(void* p,U offset,U v){std::memcpy(static_cast<B*>(p)+offset,&v,4);}
U dimension(const void* p,U offset){std::int16_t v;std::memcpy(&v,static_cast<const B*>(p)+offset,2);return static_cast<U>(static_cast<std::int32_t>(v));}
void* pixels(const void* p){return reinterpret_cast<void*>(word(p)+0x10u);}
void name_copy(void* self,const char* source){
    B* destination=static_cast<B*>(self)+0x24;
    B ch=static_cast<B>(*source);*destination++=ch;
    if(ch)for(U i=1;i<0x13;++i){ch=static_cast<B>(*++source);if(!ch)break;*destination++=ch;}
}
void name(void* self,void* parent,const char* source){
    char generated[20];
    if(!source){
        const U index=get(parent,0x10);put(parent,0x10,index+1);
        (void)formatter_entry_005a0fbf(generated,render_resource_node_name_format_005de748,static_cast<std::int32_t>(index));
        source=generated;
    }
    name_copy(self,source);
}
void reference(void* self){
    void* counter=startup_network_allocate_0059ef90(4);
    if(counter)put(counter,0,0);
    put(self,0x20,word(counter));
    // Original null allocation stores self+20=0 and then faults reading address0.
    // A separate scalar read preserves the original read-AV before its write.
    const U value=nibble512::read32(word(counter));put(counter,0,value+1);
}
void texture(void* self,void* parent,U flags,void* first_pixels,U second_pixels){
    const U first_format=get(self,0x14),height=get(self,0x10),second_format=get(self,0x18),width=get(self,0xc);
    put(self,0x1c,flags);static_cast<B*>(self)[0x37]=0;put(self,4,word(parent));
    void* allocated=render_display_texture_alloc_00554960(width,height,first_format,second_format,flags,reinterpret_cast<char*>(static_cast<B*>(self)+0x24));
    put(self,8,word(allocated));
    render_display_texture_copy_00554d70(allocated,first_pixels,second_pixels);
    alignas(4) B descriptor[24];
    // Keep the original unwritten local when the real query does not fill it.
    (void)render_resource_texture_query_00554de0(reinterpret_cast<void*>(get(self,8)),descriptor);
    put(self,0x14,get(descriptor,0x10));
    reference(self);
}
}
void* __fastcall render_resource_node_state_ctor_005379d0(void* self,void*){
    put(self,0,0);put(self,4,1);put(self,8,0);put(self,0xc,0);put(self,0x10,0);put(self,0x14,0);put(self,0x18,0);return self;
}
void* __fastcall render_resource_node_ctor_00535bc0(void* self,void*,const void* descriptor,void* parent,U flags,const char* source){
    (void)render_resource_node_state_ctor_005379d0(static_cast<B*>(self)+0x38,nullptr);
    put(self,0,word(render_resource_node_table_005bb6d4));
    put(self,0x14,render_resource_node_format_00556690(descriptor));
    void* palette=render_resource_node_palette_00537fb0(descriptor);
    const U second_format=palette?render_resource_node_format_00556690(palette):0;
    put(self,0x18,second_format);
    void* first_pixels=pixels(descriptor);const U second_pixels=palette?word(pixels(palette)):0;
    put(self,0xc,dimension(descriptor,4));put(self,0x10,dimension(descriptor,6));
    name(self,parent,source);texture(self,parent,flags,first_pixels,second_pixels);return self;
}
void* __fastcall render_resource_node_pair_ctor_00535d80(void* self,void*,const void* first,const void* second,void* parent,U flags,const char* source){
    (void)render_resource_node_state_ctor_005379d0(static_cast<B*>(self)+0x38,nullptr);
    put(self,0,word(render_resource_node_table_005bb6d4));
    put(self,0x14,render_resource_node_format_00556690(first));
    put(self,0x18,render_resource_node_format_00556690(second));
    put(self,0xc,dimension(first,4));put(self,0x10,dimension(first,6));
    void* first_pixels=pixels(first);const U second_pixels=word(pixels(second));
    name(self,parent,source);texture(self,parent,flags,first_pixels,second_pixels);return self;
}
void* __fastcall render_resource_node_empty_ctor_00535ed0(void* self,void*,void* parent,U flags,const char* source){
    (void)render_resource_node_state_ctor_005379d0(static_cast<B*>(self)+0x38,nullptr);
    put(self,0x18,0xffffffff);put(self,0x14,0xffffffff);put(self,0,word(render_resource_node_table_005bb6d4));
    put(self,8,0);put(self,0xc,0);put(self,0x10,0);put(self,4,word(parent));put(self,0x1c,flags);
    name(self,parent,source);static_cast<B*>(self)[0x37]=0;reference(self);return self;
}
}
