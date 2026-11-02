// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Complete540390/136B,538d10/102B,539e50/89B,539c90/55B.
#include "render_surface_503.hpp"
#include "porsche/application_alloc.hpp"
#include "porsche/game_setup.hpp"
#include <cstring>
namespace porsche {
extern std::uint32_t render_display_callback1_0069ecfc,render_display_callback2_0069ed00;
std::uint32_t render_resource_cells_0069ecc0[13]{};
std::uint32_t render_resource_option_0069ed04{};
std::uint32_t render_resource_callback1_0069ed10{},render_resource_callback2_0069ed14{};
namespace {
using U=std::uint32_t;using B=std::uint8_t;
U get(const void* p,U offset){U v;std::memcpy(&v,static_cast<const B*>(p)+offset,4);return v;}
void put(void* p,U offset,U value){std::memcpy(static_cast<B*>(p)+offset,&value,4);}
U word(const void* p){return reinterpret_cast<U>(p);}
}
void* __cdecl render_display_resource_ctor_00540390(void* object,U optional_source){
    put(object,0,0);put(object,4,0);
    if(optional_source)render_resource_option_0069ed04=get(reinterpret_cast<void*>(optional_source),12);
    const U callback2=render_display_callback2_0069ed00;
    for(U& value:render_resource_cells_0069ecc0)value=0;
    const U callback1=render_display_callback1_0069ecfc;
    render_resource_callback2_0069ed14=callback2;
    render_resource_callback1_0069ed10=callback1;
    game_setup_movie_service_0069ed0c=object;
    return object;
}
void __cdecl render_matrix_identity_00539c90(void* matrix){
    for(U i=0;i<16;++i)put(matrix,i*4,(i==0||i==5||i==10||i==15)?0x3f800000u:0u);
}
void* __cdecl render_transform_stack_ctor_00539e50(void* object,U capacity){
    put(object,0,0);put(object,4,0);put(object,8,0);put(object,12,0);
    put(object,12,capacity<1u?1u:capacity);
    void* const matrix=startup_network_allocate_0059ef90(get(object,12)<<6);
    put(object,0,word(matrix));put(object,8,0);put(object,4,word(matrix));
    render_matrix_identity_00539c90(matrix);
    put(object,20,0);put(object,16,1);static_cast<B*>(object)[24]=1;
    return object;
}
void* __cdecl render_display_surface_ctor_00538d10(void* object,U driver){
    auto* p=static_cast<B*>(object);
    render_transform_stack_ctor_00539e50(p,0x28);
    render_transform_stack_ctor_00539e50(p+0x5c,0x28);
    put(object,0xb8,0x3f);
    render_matrix_identity_00539c90(p+0x108);
    render_matrix_identity_00539c90(p+0x148);
    render_matrix_identity_00539c90(p+0x188);
    put(object,0x1d0,0);put(object,0x1d4,0xffffffff);
    put(object,0x1c8,driver);put(reinterpret_cast<void*>(driver),0x14,word(object));
    return object;
}
}
