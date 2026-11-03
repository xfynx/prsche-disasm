// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Complete538da0/732B and556d00/27B. Four readonly bytes; no new writable owner.
#include "render_surface_init_511.hpp"
#include "rectangle.hpp"
#include "porsche/game_setup.hpp"
#include <cstring>
#include <initializer_list>
namespace porsche {
extern std::uint32_t render_display_texture_width_005deac8,render_display_texture_height_005deacc;
const float render_surface_half_005b23f0=0.5f;
namespace {
using U=std::uint32_t;using B=std::uint8_t;
struct E{B bytes[10];}; // Explicit x87 extended values; never converted by C++ arithmetic.
U get(const void* p,U o){U v;std::memcpy(&v,static_cast<const B*>(p)+o,4);return v;}
void put(void* p,U o,U v){std::memcpy(static_cast<B*>(p)+o,&v,4);}
E extended(U bits){E result;__asm {fld bits} __asm {fstp tbyte ptr result} return result;}
U word(const E& value){U result;__asm {mov eax,value} __asm {fld tbyte ptr [eax]} __asm {fstp result} return result;}
E add_words(U a,U b){E result;__asm {fld a} __asm {fadd b} __asm {fstp tbyte ptr result} return result;}
U add_store(U a,U b){U result;__asm {fld a} __asm {fadd b} __asm {fstp result} return result;}
E sub_words(U a,U b){E result;__asm {fld a} __asm {fsub b} __asm {fstp tbyte ptr result} return result;}
E add_word(const E& a,U b){E result;__asm {mov eax,a} __asm {fld tbyte ptr [eax]} __asm {fadd b} __asm {fstp tbyte ptr result} return result;}
U sub_store(const E& a,U b){U result;__asm {mov eax,a} __asm {fld tbyte ptr [eax]} __asm {fsub b} __asm {fstp result} return result;}
E half(const E& a){E result;__asm {mov eax,a} __asm {fld tbyte ptr [eax]} __asm {fmul render_surface_half_005b23f0} __asm {fstp tbyte ptr result} return result;}
E sub_ext(const E& a,const E& b){E result;__asm {mov eax,b} __asm {fld tbyte ptr [eax]} __asm {mov eax,a} __asm {fld tbyte ptr [eax]} __asm {fsubrp st(1),st(0)} __asm {fstp tbyte ptr result} return result;}
U ratio(U numerator,const E& denominator){U result;__asm {mov eax,denominator} __asm {fld tbyte ptr [eax]} __asm {fld numerator} __asm {fdiv st(0),st(1)} __asm {fstp result} __asm {fstp st(0)} return result;}
U ratio_words(U numerator,U denominator){U result;__asm {fld numerator} __asm {fdiv denominator} __asm {fstp result} return result;}
U offset_x(const E& delta,const E& width){U result;__asm {mov eax,width} __asm {fld tbyte ptr [eax]} __asm {mov eax,delta} __asm {fld tbyte ptr [eax]} __asm {fadd st(0),st(0)} __asm {fdivrp st(1),st(0)} __asm {fstp result} return result;}
U offset_y(U delta,U height){U result;__asm {fld delta} __asm {fadd st(0),st(0)} __asm {fdiv height} __asm {fstp result} return result;}
U compare_words(U a,U b){unsigned short status;__asm {fld a} __asm {fcomp b} __asm {fnstsw status} return status;}
U compare_ext(const E& a,U b){unsigned short status;__asm {mov eax,a} __asm {fld tbyte ptr [eax]} __asm {fcomp b} __asm {fnstsw status} return status;}
U compare_area(const E& width,U height){unsigned short status;__asm {mov eax,width} __asm {fld tbyte ptr [eax]} __asm {fmul height} __asm {fcomp rectangle_zero_005b23f8} __asm {fnstsw status} return status;}
bool negative(U a){return (compare_words(a,0)&0x100u)!=0;}
bool greater(U status){return (status&0x4100u)==0;}
U signed_float(U value){U result;__asm {fild value} __asm {fstp result} return result;}
void bounds(U* width,U* height){
    void* const resource=game_setup_movie_service_0069ed0c;
    const U driver=get(resource,0),vtable=get(reinterpret_cast<void*>(driver),0);
    // Generic original thiscall virtual transport: ECXreceiver, outputW/outputH,
    // callee RET8. No function-identity substitution or convenience null guard.
    __asm {push height}
    __asm {push width}
    __asm {mov ecx,driver}
    __asm {mov eax,vtable}
    __asm {call dword ptr [eax+18h]}
}
}
U __stdcall render_surface_bounds_00556d00(U* width,U* height){
    *width=signed_float(render_display_texture_width_005deac8);
    *height=signed_float(render_display_texture_height_005deacc);
    return reinterpret_cast<U>(width);
}
void __cdecl render_surface_init_bits_00538da0(void* surface,U width,U height,U x,U y,U opaque1e8,U opaque1ec){
    U limits[2]; // The virtual producer owns both outputs; no invented initial bits.
    bounds(limits,limits+1);
    U left=x,top=y,right=add_store(width,x);
    E bottom=add_words(height,y);
    if(negative(left))left=0;
    if(negative(top))top=0;
    if(negative(right))right=0;
    if((compare_ext(bottom,0)&0x100u)!=0)bottom=extended(0);
    if(greater(compare_words(left,limits[0])))left=limits[0];
    if(greater(compare_words(top,limits[1])))top=limits[1];
    if(greater(compare_words(right,limits[0])))right=limits[0];
    if(greater(compare_ext(bottom,limits[1])))bottom=extended(limits[1]);
    const U clipped_height=sub_store(bottom,top);
    const E clipped_width=sub_words(right,left);
    const bool empty=(compare_area(clipped_width,clipped_height)&0x4000u)!=0;
    put(surface,0x1e8,opaque1e8);
    if(empty){
        for(U o:{0x1d8u,0x1dcu,0x1f0u,0x1f4u,0x1e0u,0x1e4u})put(surface,o,0);
        put(surface,0x1ec,opaque1ec);
        for(U o:{0x1f8u,0x1fcu})put(surface,o,0);
        for(U o:{0x214u,0x210u,0x204u,0x200u})put(surface,o,0x3f800000);
        for(U o:{0x21cu,0x218u,0x20cu,0x208u})put(surface,o,0);
        return;
    }
    put(surface,0x1d8,word(clipped_width));put(surface,0x1dc,clipped_height);
    const E half_width=half(clipped_width);
    put(surface,0x1f0,word(half_width));put(surface,0x1e0,left);put(surface,0x1e4,top);put(surface,0x1ec,opaque1ec);
    const U half_height=word(half(extended(clipped_height)));
    put(surface,0x1f4,half_height);
    const E center_x=add_word(half_width,left);
    put(surface,0x1f8,word(center_x));
    const U center_y=add_store(half_height,top);
    put(surface,0x1fc,center_y);
    bool adjusted=(compare_ext(clipped_width,width)&0x4000u)==0;
    if(!adjusted)adjusted=(compare_words(clipped_height,height)&0x4000u)==0;
    if(!adjusted){
        for(U o:{0x214u,0x210u,0x204u,0x200u})put(surface,o,0x3f800000);
        for(U o:{0x21cu,0x218u,0x20cu,0x208u})put(surface,o,0);
        return;
    }
    const E delta_x=sub_ext(add_word(half(extended(width)),x),center_x);
    const U delta_y=sub_store(add_word(half(extended(height)),y),center_y);
    const U scale_x=ratio(width,clipped_width),scale_y=ratio_words(height,clipped_height);
    put(surface,0x210,scale_x);put(surface,0x200,scale_x);put(surface,0x214,scale_y);put(surface,0x204,scale_y);
    const U adjust_x=offset_x(delta_x,clipped_width),adjust_y=offset_y(delta_y,clipped_height);
    put(surface,0x218,adjust_x);put(surface,0x208,adjust_x);put(surface,0x21c,adjust_y);put(surface,0x20c,adjust_y);
}
void __cdecl render_display_surface_init_00538da0(void* surface,float width,float height,U x,U y,U opaque1e8,U opaque1ec){
    U w,h;std::memcpy(&w,&width,4);std::memcpy(&h,&height,4);
    render_surface_init_bits_00538da0(surface,w,h,x,y,opaque1e8,opaque1ec);
}
}
