// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Complete 00539b30 (68B), 00539b80 (69B), 00539f40 (15B), 00466e80 (9B).
#include "render_display_484.hpp"
#include <cstring>
#include <initializer_list>
namespace porsche {
namespace {
using U=std::uint32_t;using B=std::uint8_t;
void store(void* p,U offset,U value){std::memcpy(static_cast<B*>(p)+offset,&value,4);}
U load(const void* p,U offset){U value;std::memcpy(&value,static_cast<const B*>(p)+offset,4);return value;}
}
void __cdecl render_display_transform_compose_00539b30(void* matrix,U x,U y,U z,U w){
    store(matrix,0,x);
    for(U offset:{4u,8u,12u,16u})store(matrix,offset,0);
    store(matrix,20,y);
    for(U offset:{24u,28u,32u,36u,44u,48u,52u,56u})store(matrix,offset,0);
    store(matrix,40,z);store(matrix,60,w);
}
void __cdecl render_display_transform_init_00539b80(void* matrix,U x,U y,U z){
    for(U offset:{4u,8u,12u,16u,24u,28u,32u,36u,44u})store(matrix,offset,0);
    store(matrix,48,x);store(matrix,52,y);
    store(matrix,0,0x3f800000);store(matrix,20,0x3f800000);store(matrix,40,0x3f800000);
    store(matrix,56,z);store(matrix,60,0x3f800000);
}
void* __cdecl render_display_surface_transform_00539f40(void* object){
    const U count=load(object,16);
    static_cast<B*>(object)[24]=1;
    store(object,16,count+1u);
    return reinterpret_cast<void*>(load(object,4));
}
void __cdecl render_display_local_transform_00466e80(void* object,U value){store(object,0,value);}
}
