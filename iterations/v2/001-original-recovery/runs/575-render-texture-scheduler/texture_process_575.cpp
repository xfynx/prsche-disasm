// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
// 00555040/150B and 005554b0/275B. Original x86 addresses and ABI only.
#include "texture_process_575.hpp"
#include "../537-render-resource-descriptor-cleanup/render_resource_descriptor_537.hpp"
#include "../543-render-slot-reset/render_slot_reset_543.hpp"
#include "porsche/render_display.hpp"
#include "porsche/render_loader.hpp"
#include <cstring>
#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Original x86 address and ABI semantics require MSVC x86.
#endif
namespace porsche {
using U=std::uint32_t;using B=std::uint8_t;
TextureNotifyCallback575 render_texture_notify_callback_006a3a50=nullptr;
namespace {
U address(const void* p){return reinterpret_cast<U>(p);}
U read(U p){U v;std::memcpy(&v,reinterpret_cast<const void*>(p),4);return v;}
void write(U p,U v){std::memcpy(reinterpret_cast<void*>(p),&v,4);}
U slot(U index){return address(render_texture_slots_006a33f8)+index*48u;}
void descriptor(TextureNotifyDescriptor575& d,U texture){
    const U index=read(texture+4);
    d.texture=texture;
    d.slot_value=read(slot(index)+0x10);
    d.texture_value=read(texture+0x24);
    d.payload=texture+0x30;
}
}
void __cdecl render_texture_notify_00555040(void* first,void* second){
    const auto callback=render_texture_notify_callback_006a3a50;
    if(!callback)return;
    TextureNotifyDescriptor575 a,b;
    if(first)descriptor(a,address(first));
    if(second)descriptor(b,address(second));
    callback(first?&a:nullptr,second?&b:nullptr);
}
void __cdecl render_texture_process_005554b0(void* texture){
    const U object=address(texture);
    if(!object||!render_texture_dirty_006a3a48)return;
    if(read(object+0x10)==0){
        U record=slot(read(object+4));
        render_texture_notify_00555040(texture,reinterpret_cast<void*>(read(record+0x2c)));
        record=slot(read(object+4));
        U tail=read(record+0x2c);
        write(object+0x10,read(tail+0x10));
        write(tail+0x10,0);
        const U previous=read(tail+0x0c);
        if(previous){
            write(previous+8,0);
            write(record+0x2c,previous);
            const U head=read(record+0x28);
            write(record+0x28,object);
            const U flags=read(object+0x2c);
            write(object+8,head);
            write(head+0x0c,object);
            write(object+0x0c,0);
            write(object+0x2c,flags&0xfffffffdu);
        }else{
            write(record+0x28,object);
            write(record+0x2c,object);
            const U flags=read(object+0x2c);
            write(object+8,0);
            write(object+0x0c,0);
            write(object+0x2c,flags&0xfffffffdu);
        }
    }else{
        const U next=read(object+0x0c);
        if(next){
            const U previous=read(object+8);
            write(next+8,previous);
            if(previous)write(previous+0x0c,next);
            else write(slot(read(object+4))+0x2c,next);
            const U record=slot(read(object+4));
            const U head=read(record+0x28);
            write(object+8,head);
            write(head+0x0c,object);
            write(record+0x28,object);
            write(object+0x0c,0);
        }
    }
    const U flags=read(object+0x2c);
    if(!(flags&2u)){
        render_display_set_texture_006bd954(0);
        const U third=(flags&8u)?read(object+0x1c):0;
        const U second=read(object+0x18);
        const U first=read(object+0x10);
        using Upload=void (__stdcall*)(U,U,U);
        reinterpret_cast<Upload>(static_cast<std::uintptr_t>(render_thrash_exports_006bd910[12]))(first,second,third);
        write(object+0x2c,flags|2u);
    }
}
}
