// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#include "audio_nibble_decoders_512.hpp"
#include "nibble_memory_512.hpp"
#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Exact original arithmetic requires MSVC x86
#endif
namespace porsche {
#pragma section(".niph$a",read,write)
__declspec(align(16)) __declspec(allocate(".niph$a")) std::uint8_t audio_nibble_read_window_005e3b28[80]={
0,0,0,0,0,0,112,63,0,0,230,63,0,0,196,63,
0,0,0,0,0,0,0,0,0,0,80,191,0,0,92,191,
0,0,0,0,0,0,0,0,156,252,127,55,156,252,127,55,
0,0,0,0,0,0,0,0,0,0,0,63,0,0,0,63,
0,0,0,64,0,0,0,64,0,0,64,64,0,0,64,64};
#pragma section(".nibl$b",read,write)
__declspec(align(16)) __declspec(allocate(".nibl$b")) std::uint8_t audio_nibble_read_tail_006b0800[192]{};
namespace {
using U=std::uint32_t;using I=std::int32_t;
using namespace nibble512;
U ptr(const void* p){return reinterpret_cast<U>(p);}
// Straight-line exact FP primitives. Coefficients remain extended on the x87
// stack throughout one block. All addressing/count/iteration stays in C++.
void coefficients(U a,U b){__asm {
 mov eax,b
 fld dword ptr [eax]
 mov eax,a
 fld dword ptr [eax]
}}
void release_coefficients(){__asm {fstp st(0)
 fstp st(0)} }
void predict(U output,U lookup){__asm {
 mov eax,output
 mov edx,lookup
 fld dword ptr [eax-4]
 fmul st(0),st(1)
 fld dword ptr [eax-8]
 fmul st(0),st(3)
 fxch st(1)
 fadd dword ptr [edx]
 faddp st(1),st(0)
}}
void store_prediction(U output){__asm {mov eax,output
 fstp dword ptr [eax]} }
// MSVC/O2 commutes intrinsic operands and changes distinct NaN payload priority.
// One-instruction primitives fix destination/source order using raw FLOAT32 bits.
U multiply(U left,U right){U result;__asm {
 movss xmm0,left
 mulss xmm0,right
 movss result,xmm0
}return result;}
U add(U left,U right){U result;__asm {
 movss xmm0,left
 addss xmm0,right
 movss result,xmm0
}return result;}
}
void __cdecl audio_nibble_decode_x87_0059a5a0(U state){
 U output=read32(state+16),history=read32(state+4),index=read32(state+8);
 write32(output-4,history);write32(output-8,index);
 U input=read32(state+12);
 while(static_cast<I>(read32(state))>0){
  write32(state,read32(state)-28u);
  U high=read8(input)>>4;
  const U base=ptr(audio_nibble_read_window_005e3b28);
  coefficients(base+high*4,base+16+high*4);
  U row=(read8(input)&15u)*64u;
  U nibble=read8(input+1)>>4;
  index=0xfffffff2u;output+=112;input+=15;
  do {
   U even=output+index*8;
   predict(even,ptr(audio_mixer_nibble_lookup_006b04c0)+row+nibble*4);
   // Original loads the low nibble BEFORE storing the even result.
   nibble=read8(input+index)&15u;
   store_prediction(even);
   predict(even+4,ptr(audio_mixer_nibble_lookup_006b04c0)+row+nibble*4);
   nibble=read8(input+index+1)>>4;
   store_prediction(even+4);
   ++index;
  }while(static_cast<I>(index)<0);
  release_coefficients();
 }
 // If no block ran, ECX is the incoming history2 bit-pattern, not zero.
 write32(state+4,read32(output+index*8-4));
 write32(state+8,read32(output+index*8-8));
 write32(state+16,output);
}
void __cdecl audio_nibble_decode_sse_0059a660(U state){
 U input=read32(state+12),output=read32(state+16);
 U latest=read32(state+4),older=read32(state+8),value=latest;
 while(static_cast<I>(read32(state))>0){
  write32(state,read32(state)-28u);
  U high=read8(input)>>4,row=(read8(input)&15u)*64u;
  U index=0xfffffff2u;input+=15;output+=112;
  do {
   const U a=ptr(audio_nibble_read_window_005e3b28)+high*4,b=a+16;
   value=multiply(value,read32(a));
   U nibble=read8(input+index)>>4;
   older=multiply(older,read32(b));
   value=add(value,read32(ptr(audio_mixer_nibble_lookup_006b04c0)+row+nibble*4));
   latest=multiply(latest,read32(b));
   value=add(value,older);
   write32(output+index*8,value);older=value;
   nibble=read8(input+index)&15u;
   value=multiply(value,read32(a));
   value=add(value,read32(ptr(audio_mixer_nibble_lookup_006b04c0)+row+nibble*4));
   value=add(value,latest);latest=value;
   write32(output+index*8+4,value);
   ++index;
  }while(static_cast<I>(index)<0);
 }
 write32(state+4,latest);write32(state+8,older);write32(state+16,output);
}
}
