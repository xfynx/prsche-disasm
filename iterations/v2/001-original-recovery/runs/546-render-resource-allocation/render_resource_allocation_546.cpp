// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Six complete originals608B; raw provenance/data/ABI in scope-evidence.json.
#include "render_resource_allocation_546.hpp"
#include "render_descriptor.hpp"
#include "porsche/heap.hpp"
#include "porsche/file_device.hpp"
#include "porsche/process_exit.hpp"
#include <cstring>
namespace porsche {
using U=std::uint32_t;using S=std::int32_t;using B=std::uint8_t;
U render_texture_preferred_bytes_005df2c4=0xc00000;
#ifdef _MSC_VER
// A separate4B owner also permits native page protection to prove the original
// read beyond the32 admitted records without a C++ array overrun.
#pragma section(".r546s",read,write)
__declspec(allocate(".r546s"))
#endif
volatile U render_texture_width_sentinel_006a3a08=0;
const U render_texture_format_bits_005df16c[14]={0,4,8,16,16,24,32,16,8,16,16,16,4,8};
const char render_texture_heap_name_005bbfdc[5]="DTEX";
const char render_texture_capacity_message_005bc208[138]="[DTEXTURE] dtexture.c Error too many different texture types used\n Try using more textures of the same width/mipmap levels/ pixel format\n";
namespace {
U get(const void* p,U o){U v;std::memcpy(&v,static_cast<const B*>(p)+o,4);return v;}
void put(void* p,U o,U v){std::memcpy(static_cast<B*>(p)+o,&v,4);}
void put16(void* p,U o,U v){const auto w=static_cast<std::uint16_t>(v);std::memcpy(static_cast<B*>(p)+o,&w,2);}
U width_at(U index){return index==32?render_texture_width_sentinel_006a3a08:get(render_texture_slots_006a33f8,index*48+0x10);}
U signed_divide(U value,U divisor){return static_cast<U>(static_cast<S>(value)/static_cast<S>(divisor));}
}
int __cdecl render_display_texture_reserve_00553fc0(U bytes){
    if(!bytes){render_texture_preferred_bytes_005df2c4=0xc00000;return 0;}
    if(render_texture_arena_006a3a5c)render_texture_reset_00555390();
    void* arena=platform_virtual_alloc(nullptr,bytes,0x1000,4);
    render_texture_arena_006a3a5c=reinterpret_cast<U>(arena);
    if(!arena)return 0;
    render_texture_preferred_bytes_005df2c4=bytes;
    const U id=application_heap_slot_00569a70();
    const U size=render_texture_preferred_bytes_005df2c4;
    arena=reinterpret_cast<void*>(render_texture_arena_006a3a5c);
    render_texture_heap_id_006a3a60=id;
    (void)heap_init_005697f0(id,render_texture_heap_name_005bbfdc,arena,static_cast<S>(size),0x40,0x40,0,0,0,0,0,nullptr);
    return 1;
}
int __cdecl render_texture_lazy_reserve_00554b50(){
    U bytes=render_texture_preferred_bytes_005df2c4;
    if(!bytes)bytes=0xc00000;
    int result=render_display_texture_reserve_00553fc0(bytes);
    while(!result&&static_cast<S>(bytes)>0x80000){bytes-=0x40000;result=render_display_texture_reserve_00553fc0(bytes);}
    render_texture_preferred_bytes_005df2c4=bytes;
    return result;
}
void* __cdecl render_texture_bytes_00554b20(U bytes,const char* name){
    if(!render_texture_arena_006a3a5c&&!render_texture_lazy_reserve_00554b50())return nullptr;
    return allocate_00531ca0(name,static_cast<S>(bytes),render_texture_heap_id_006a3a60);
}
void* __cdecl render_texture_node_00554b90(const char* name){
    if(!render_texture_arena_006a3a5c&&!render_texture_lazy_reserve_00554b50())return nullptr;
    void* result=allocate_00531ca0(name,56,render_texture_heap_id_006a3a60|0x10);
    heap_fill_0053c290(result,0,56);
    return result;
}
void __cdecl render_texture_header_00554ad0(void* output,U width,U height,U format,U flags){
    const U translated=render_descriptor_format_00556880(format)&0xff;
    volatile U previous=get(output,0);(void)previous;
    put(output,0,translated);put16(output,4,width);put16(output,6,height);
    put16(output,8,0);put16(output,0xa,0);
    const U old_flags=get(output,0xc);
    put(output,0xc,(old_flags&0xa000)|(flags<<28));
}
U __cdecl render_texture_slot_00554bd0(U width,U formatA,U formatB,U flags){
    U index=0,found=0xffffffff;
    if(static_cast<S>(width_at(0))>0){
        for(;;){
            if(index>=32)break;
            const U o=index*48;
            if(get(render_texture_slots_006a33f8,o+0x10)==width&&get(render_texture_slots_006a33f8,o+8)==formatA&&get(render_texture_slots_006a33f8,o+0xc)==formatB&&get(render_texture_slots_006a33f8,o+4)==flags)found=index;
            ++index;
            if(static_cast<S>(width_at(index))<=0)break;
        }
        if(found!=0xffffffff)return found;
        if(static_cast<S>(index)>=32){render_texture_diagnostic_0055ec50(6,render_texture_capacity_message_005bc208);process_exit_005a246e(0xffffffff);}
    }
    ++render_texture_slot_count_006a3a44;
    const U o=index*48;
    U size=render_texture_format_bits_005df16c[formatA]*width*width;
    put(render_texture_slots_006a33f8,o+0x10,width);put(render_texture_slots_006a33f8,o+8,formatA);
    put(render_texture_slots_006a33f8,o+0xc,formatB);
    size=signed_divide(size,8);put(render_texture_slots_006a33f8,o+4,flags);put(render_texture_slots_006a33f8,o+0x14,size);
    U levels=flags&0xff,total=size;
    if(levels){do{size=signed_divide(size,4);total+=size;}while(--levels);put(render_texture_slots_006a33f8,o+0x14,total);}
    return index;
}
}
