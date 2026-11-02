// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Complete5398b0/532B,539b00/45B,5392d0/168B. No new original storage.
#include "render_matrix_506.hpp"
#include "render_surface_503.hpp"
#include "audio_fixed_vector_468.hpp"
#include <cstring>
namespace porsche {
namespace {
using U=std::uint32_t;using B=std::uint8_t;
U get(const void* p,U offset){U value;std::memcpy(&value,static_cast<const B*>(p)+offset,4);return value;}
void put(void* p,U offset,U value){std::memcpy(static_cast<B*>(p)+offset,&value,4);}
// One four-product arithmetic primitive; operand order and no intermediate spills
// match the original FLD/FMUL/FADDP sequence. Control and memory traversal are C++.
U dot4(U p0,U p1,U p2,U p3,U p4,U p5,U p6,U p7){U result;
    __asm {
        fld p0
        fmul p1
        fld p2
        fmul p3
        faddp st(1),st(0)
        fld p4
        fmul p5
        faddp st(1),st(0)
        fld p6
        fmul p7
        faddp st(1),st(0)
        fstp result
    }
    return result;
}
U negate_scaled(U value,U scale){U result;
    __asm fld value
    __asm fmul scale
    __asm fchs
    __asm fstp result
    return result;
}
void ratios(U near_word,U far_word,U& first,U& second){U a,b;
    // The denominator remains in ST(0/1), at incoming x87 precision, throughout.
    __asm {
        fld far_word
        fsub near_word
        fld dword ptr [_DAT_005b2624]
        fdiv st(0),st(1)
        fstp a
        fld near_word
        fdiv st(0),st(1)
        fchs
        fstp b
        fstp st(0)
    }
    first=a;second=b;
}
}
const void* __cdecl render_matrix_multiply_005398b0(const void* left,const void* right,void* output){
    // Sequential stores deliberately permit output to alias either input. Each
    // subsequent cell reloads the original operands from the current memory.
    put(output,0,dot4(get(left,0),get(right,0),get(right,32),get(left,8),get(left,4),get(right,16),get(left,12),get(right,48)));
    put(output,4,dot4(get(right,36),get(left,8),get(left,0),get(right,4),get(left,4),get(right,20),get(right,52),get(left,12)));
    put(output,8,dot4(get(left,0),get(right,8),get(right,40),get(left,8),get(left,4),get(right,24),get(right,56),get(left,12)));
    put(output,12,dot4(get(left,12),get(right,60),get(left,4),get(right,28),get(right,12),get(left,0),get(right,44),get(left,8)));
    put(output,16,dot4(get(left,20),get(right,16),get(left,28),get(right,48),get(right,32),get(left,24),get(left,16),get(right,0)));
    put(output,20,dot4(get(right,20),get(left,20),get(left,16),get(right,4),get(right,52),get(left,28),get(right,36),get(left,24)));
    put(output,24,dot4(get(left,20),get(right,24),get(right,56),get(left,28),get(right,40),get(left,24),get(left,16),get(right,8)));
    put(output,28,dot4(get(left,16),get(right,12),get(left,28),get(right,60),get(left,24),get(right,44),get(left,20),get(right,28)));
    put(output,32,dot4(get(left,36),get(right,16),get(left,44),get(right,48),get(right,32),get(left,40),get(left,32),get(right,0)));
    put(output,36,dot4(get(right,20),get(left,36),get(left,32),get(right,4),get(right,52),get(left,44),get(right,36),get(left,40)));
    put(output,40,dot4(get(left,36),get(right,24),get(right,56),get(left,44),get(right,40),get(left,40),get(left,32),get(right,8)));
    put(output,44,dot4(get(left,32),get(right,12),get(left,44),get(right,60),get(left,40),get(right,44),get(left,36),get(right,28)));
    put(output,48,dot4(get(left,52),get(right,16),get(left,60),get(right,48),get(right,32),get(left,56),get(left,48),get(right,0)));
    put(output,52,dot4(get(right,20),get(left,52),get(left,48),get(right,4),get(right,52),get(left,60),get(right,36),get(left,56)));
    put(output,56,dot4(get(left,52),get(right,24),get(right,56),get(left,60),get(right,40),get(left,56),get(left,48),get(right,8)));
    put(output,60,dot4(get(left,48),get(right,12),get(left,60),get(right,60),get(left,56),get(right,44),get(left,52),get(right,28)));
    return right;
}
void* __cdecl render_matrix_attach_00539b00(void* destination,const void* source){
    U temporary[16];
    (void)render_matrix_multiply_005398b0(source,destination,temporary);
    std::memcpy(destination,temporary,64);
    return destination;
}
void __cdecl render_display_transform_attach_00539b00(void* destination,void* source){(void)render_matrix_attach_00539b00(destination,source);}
U __cdecl render_surface_config_005392d0(void* surface,U scale,U near_word,U far_word){
    auto* matrix=static_cast<B*>(surface)+0x148;
    put(surface,0x220,1);
    render_matrix_identity_00539c90(matrix);
    put(matrix,0,get(surface,0x210));
    put(matrix,0x14,negate_scaled(scale,get(surface,0x214)));
    U inverse,near_ratio;ratios(near_word,far_word,inverse,near_ratio);
    put(matrix,0x30,get(surface,0x218));put(matrix,0x34,get(surface,0x21c));
    put(matrix,0x28,inverse);put(matrix,0x38,near_ratio);
    put(surface,0xe4,scale);
    const U count=get(surface,0x1d0)+1u;
    put(surface,0xec,near_word);put(surface,0xe8,far_word);
    put(surface,0xf0,0x3f800000);put(surface,0xf4,0);put(surface,0x1d0,count);
    return count;
}
void __cdecl render_display_surface_config_005392d0(void* surface,U scale,U near_word,U far_word){(void)render_surface_config_005392d0(surface,scale,near_word,far_word);}
}
