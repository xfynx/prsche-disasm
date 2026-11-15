// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// 00554960/363B and 00554d70/107B. Original x86 words and effect order.
#include "render_texture_transfer_577.hpp"
#include "texture_children_577.hpp"
#include "../546-render-resource-allocation/render_resource_allocation_546.hpp"
#include "porsche/render_display.hpp"
#include "porsche/render_loader.hpp"
#include <cstring>
#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Original x86 pointer and wrap semantics required.
#endif
namespace porsche {
const std::uint32_t* render_texture_driver_info_006a3a54=nullptr;
namespace {
using U=std::uint32_t;using B=std::uint8_t;
U address(const void* p){return reinterpret_cast<U>(p);}
U load(U p){U value;std::memcpy(&value,reinterpret_cast<const void*>(p),4);return value;}
void put(U p,U value){std::memcpy(reinterpret_cast<void*>(p),&value,4);}
U slot(U index){return address(render_texture_slots_006a33f8)+index*48u;}
}
void* __cdecl render_display_texture_alloc_00554960(U width,U height,U format,U palette_format,U flags,const char* name){
    render_texture_driver_info_006a3a54=render_loader_about_006bd934(render_thrash_exports_006bd910[9]);
    if(!width||width!=height||(width&(width-1u)))return nullptr;
    void* texture=render_texture_node_00554b90(name);
    const U node=address(texture);
    // Original copies one byte at a time before its node-null test.
    for(U i=0;i<8;++i){
        const B value=*reinterpret_cast<const B*>(address(name)+i);
        *reinterpret_cast<volatile B*>(node+0x30u+i)=value;
        if(!value)break;
    }
    if(!texture)return nullptr;
    put(node+0x24u,format);
    put(node+0x28u,palette_format);
    (void)render_texture_select_00554820(&format,&palette_format);
    format&=0xfffff0ffu;
    palette_format&=0xfffff0ffu;
    U index=render_texture_slot_00554bd0(width,format,palette_format,flags);
    put(node+4u,index);
    void* bytes=render_texture_bytes_00554b20(load(slot(index)+0x14u)+0x13u,name);
    const U buffer=address(bytes);
    put(node+0x14u,buffer);
    put(node+0x18u,buffer+0x10u);
    render_texture_header_00554ad0(bytes,width,height,format,flags&0xffu);
    index=load(node+4u);
    U record=slot(index);
    const U selected_format=load(record+8u);
    if(selected_format==1||selected_format==2)
        put(node+0x1cu,address(render_texture_bytes_00554b20(0x400,name)));
    else
        put(node+0x1cu,0);
    const U info=address(render_texture_driver_info_006a3a54);
    const U previous_flags=load(node+0x2cu);
    put(node+0x10u,0);
    const U driver_flags=(load(info+0xcu)>>4)&4u;
    const U previous_head=load(record+0x24u);
    put(record+0x24u,node);
    put(node,previous_head);
    put(node+0x2cu,driver_flags|(previous_flags&0xfffffff0u));
    const U serial=load(record);
    put(node+0x20u,serial);
    put(record,serial+1u);
    ++render_texture_count_006a3a40;
    return texture;
}
void __cdecl render_display_texture_copy_00554d70(void* texture,void* pixels,U source_palette){
    const U node=address(texture);
    if(pixels){
        const U record=slot(load(node+4u));
        const U palette=load(node+0x1cu);
        const U bytes=load(record+0x14u);
        const U destination=load(node+0x18u);
        const U output_format=load(record+8u);
        const U output_palette=load(record+0xcu);
        const U input_palette=load(node+0x28u);
        const U input_format=load(node+0x24u);
        render_texture_convert_005556b0(input_format,input_palette,output_format,output_palette,address(pixels),destination,source_palette,palette,bytes);
        if(source_palette&&palette)put(node+0x2cu,load(node+0x2cu)|8u);
    }
    put(node+0x2cu,(load(node+0x2cu)&0xfffffffdu)|1u);
}
}
