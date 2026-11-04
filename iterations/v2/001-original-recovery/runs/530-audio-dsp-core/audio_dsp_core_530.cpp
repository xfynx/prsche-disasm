// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// 00597360(510B),00597180(289B),005972b0(167B).
#include "audio_dsp_core_530.hpp"
#include "../382-rectangle/rectangle.hpp"
#include "../511-render-surface-init/render_surface_init_511.hpp"
#include <cstring>
#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Original live x87 intermediates require MSVC x86
#endif
extern float _DAT_005b24a8;
namespace porsche {
std::uint32_t audio_stream_metric_history_006af164=0;
const float audio_stream_metric_five_005b2400=5.0f;
const double audio_stream_metric_threshold_005b2da8=0.4;
const double audio_stream_metric_hysteresis_005b49a0=0.3;
namespace {
using U=std::uint32_t;using I=std::int32_t;using B=std::uint8_t;
U word(U p){U v;std::memcpy(&v,reinterpret_cast<const void*>(p),4);return v;}
void store(U p,U v){std::memcpy(reinterpret_cast<void*>(p),&v,4);}
void load(U p){__asm {mov eax,p
    fld dword ptr [eax]}}
U compare_zero(){U flags;__asm {fcom rectangle_zero_005b23f8
    fnstsw ax
    movzx eax,ah
    mov flags,eax}return flags;}
void replace_zero(){__asm {fstp st(0)
    fld rectangle_zero_005b23f8}}
void gain(U p){__asm {fsqrt
    mov eax,p
    fstp dword ptr [eax]}}
void negative(U input,U output){__asm {mov eax,input
    mov ecx,output
    fld dword ptr [eax]
    fchs
    fstp dword ptr [ecx]}}
void subtract_product(U first,U second,U output){__asm {mov eax,first
    mov ecx,second
    mov edx,output
    fld dword ptr [eax]
    fmul dword ptr [ecx]
    fsubr dword ptr [edx]
    fstp dword ptr [edx]}}
void ratio(U output,U temporary,U coefficient){__asm {mov eax,output
    mov ecx,temporary
    mov edx,coefficient
    fld dword ptr [eax]
    fdiv st(0),st(1)
    fst dword ptr [ecx]
    fst dword ptr [eax]
    fld dword ptr [ecx]
    fstp dword ptr [edx]}}
void add_product(U first,U second,U third,U output){__asm {mov eax,first
    mov ecx,second
    mov edx,third
    fld dword ptr [eax]
    fmul dword ptr [ecx]
    fadd dword ptr [edx]
    mov eax,output
    fstp dword ptr [eax]}}
void update_error(){__asm {fld st(0)
    fmul st(0),st(1)
    fsubr _DAT_005b24a8
    fmulp st(2),st(0)
    fstp st(0)}}
void filter_load(U input,U frame){__asm {mov eax,input
    mov ecx,frame
    fld dword ptr [eax]
    fst dword ptr [ecx+20h]
    fstp dword ptr [ecx+0ch]}}
void filter_step(U coefficient,U frame,U index){__asm {mov eax,coefficient
    mov ecx,frame
    mov edx,index
    fld dword ptr [eax]
    fmul dword ptr [ecx+edx+34h]
    fadd dword ptr [ecx+edx+0ch]
    fstp dword ptr [ecx+edx+10h]
    fld dword ptr [eax]
    fmul dword ptr [ecx+edx+0ch]
    fadd dword ptr [ecx+edx+34h]
    fstp dword ptr [ecx+edx+24h]}}
bool select_peak(U input){U flags;__asm {mov ecx,input
    fcom dword ptr [ecx]
    fnstsw ax
    movzx eax,ah
    mov flags,eax}if(flags&1u){__asm {fstp st(0)
        mov ecx,input
        fld dword ptr [ecx]}return true;}return false;}
// Straight-line FP stages preserve the original extended stack across C++
// integer/index work; no algorithm control or loops are hidden in assembly.
void metric_curve_first(U frame,U selected){__asm {mov edx,frame
    mov ecx,selected
    fld dword ptr [edx+ecx*4+20h]
    fld dword ptr [edx+ecx*4+28h]
    fld st(1)
    fmul render_surface_half_005b23f0
    fsub st(0),st(3)
    fld st(1)
    fmul render_surface_half_005b23f0
    faddp st(1),st(0)
    fild dword ptr [edx+4]
    fld st(0)
    fadd st(0),st(0)
    fld _DAT_005b24a8
    fsub st(0),st(1)
    fmul st(0),st(4)
    fmul render_surface_half_005b23f0
    fxch st(1)
    fadd _DAT_005b24a8
    fmul st(0),st(5)
    fmul render_surface_half_005b23f0
    fsubp st(1),st(0)
    fxch st(1)
    fmul st(0),st(5)
    fadd st(0),st(0)
    faddp st(1),st(0)
    fstp dword ptr [edx+0ch]
    fld st(0)
    fadd st(0),st(0)
    fdivr dword ptr [edx+0ch]
    fchs
    fstp dword ptr [edx+4]}}
void metric_curve_second(U frame){__asm {mov edx,frame
    fild dword ptr [edx+8]
    fmul st(0),st(2)
    fild dword ptr [edx+10h]
    fmul st(0),st(4)
    faddp st(1),st(0)
    fmul render_surface_half_005b23f0
    fild dword ptr [edx+14h]
    fsubr _DAT_005b24a8
    fmul st(0),st(5)
    faddp st(1),st(0)
    fld dword ptr [edx+4]
    fmul st(0),st(2)
    fadd dword ptr [edx+0ch]
    fmul dword ptr [edx+4]
    faddp st(1),st(0)
    fstp st(4)
    fstp st(0)
    fstp st(0)
    fstp st(0)
    fld dword ptr [edx+4]
    fmul audio_stream_metric_five_005b2400
    fstp dword ptr [edx+4]
    fdiv dword ptr [edx+24h]}}
U threshold(){U flags;__asm {fcom audio_stream_metric_threshold_005b2da8
    fnstsw ax
    movzx eax,ah
    mov flags,eax}return flags;}
U hysteresis(){U flags;__asm {fcomp audio_stream_metric_hysteresis_005b49a0
    fnstsw ax
    movzx eax,ah
    mov flags,eax}return flags;}
void pop(){__asm fstp st(0)}
void load_store(U source,U destination){__asm {mov eax,source
    mov edx,destination
    fld dword ptr [eax]
    fstp dword ptr [edx]}}
}
void __cdecl audio_stream_coefficients_00597180(U input,I order,U output,U gain_output){
    alignas(4) B local[108];const U frame=reinterpret_cast<U>(local);U temporary;
    if(order>=0){const U bytes=static_cast<U>(order)*4u+4u;std::memset(local+0x40,0,bytes);std::memset(local+0x14,0,bytes);}
    load(input);
    for(I index=1;index<=order;++index){
        const U offset=static_cast<U>(index)*4u;
        negative(input+offset,output+offset);
        for(U j=0;j+1u<static_cast<U>(index);++j){
            const U source=frame+0x44+j*4u;
            // The MOV precedes the subtract/store, including aliased output.
            const U bits=word(source);
            store(frame+0x18+j*4u,bits);
            subtract_product(input+offset-4u-j*4u,source,output+offset);
        }
        if(compare_zero()&0x40u){replace_zero();gain(gain_output);return;}
        ratio(output+offset,reinterpret_cast<U>(&temporary),frame+0x40+offset);
        for(U j=0;j+1u<static_cast<U>(index);++j)
            add_product(reinterpret_cast<U>(&temporary),frame+0x14+offset-4u-j*4u,frame+0x18+j*4u,frame+0x44+j*4u);
        update_error();
    }
    if(compare_zero()&1u)replace_zero();
    gain(gain_output);
}
void __cdecl audio_stream_predict_filter_005972b0(U samples,U coefficients){
    // Original 60-byte local workspace; all15 DWORDs are explicitly zeroed.
    alignas(4) B local[72];std::memset(local+12,0,60);const U frame=reinterpret_cast<U>(local);
    for(U index=0;index<48;++index){
        filter_load(samples,frame);
        for(U step=0;step<4;++step){
            filter_step(coefficients+4u+step*4u,frame,step*4u);
            store(frame+0x34+step*4u,word(frame+0x20+step*4u));
        }
        store(samples,word(frame+0x1c));samples+=4u;
    }
}
void __cdecl audio_stream_metric_00597360(U input,U output){
    alignas(4) B local[968];const U frame=reinterpret_cast<U>(local);
    for(U index=0;index<48;++index)store(frame+0xa8+index*4u,word(input+index*20u));
    audio_stream_correlate_00597120(frame+0xa8,48,4,frame+0x24);
    audio_stream_coefficients_00597180(frame+0x24,4,frame+0x10,frame+8);
    audio_stream_predict_filter_005972b0(frame+0xa8,frame+0x10);
    audio_stream_correlate_00597120(frame+0xa8,48,33,frame+0x24);
    load(reinterpret_cast<U>(&rectangle_zero_005b23f8));
    store(frame+4,0);U selected=0;
    for(U lag=5;lag<=32;++lag)if(select_peak(frame+0x24+lag*4u))selected=lag;
    store(frame+4,selected);
    metric_curve_first(frame,selected);
    // Original POP ESI shifts the scratch offsets by4; +8 already contains
    // selected*(selected-1). The curve must retain this integer separately.
    store(frame+8,selected*(selected-1u));
    store(frame+0x10,selected*(selected+1u));
    store(frame+0x14,selected*selected);
    const U history=audio_stream_metric_history_006af164;
    metric_curve_second(frame);
    bool clear=false;
    if(threshold()&1u){
        if(history==3u)clear=(hysteresis()&1u)!=0;
        else {pop();clear=true;}
    }else pop();
    if(clear){store(output,0);audio_stream_metric_history_006af164=(history&1u)*2u;}
    else {load_store(frame+4,output);audio_stream_metric_history_006af164=(history&1u)*2u+1u;}
}
}
