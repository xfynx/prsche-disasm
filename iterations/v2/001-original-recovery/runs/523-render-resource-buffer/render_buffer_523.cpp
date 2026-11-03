// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Full537700/86B,537760/197B,540480/17B,5404e0/17B;0new original state.
#include "render_buffer_523.hpp"
#include "porsche/render_loader.hpp"
#include "porsche/render_settings.hpp"
#include <cstring>
namespace porsche { namespace {
using U=std::uint32_t;using B=std::uint8_t;
U get(const void* p,U offset){U v;std::memcpy(&v,static_cast<const B*>(p)+offset,4);return v;}
void put(void* p,U offset,U v){std::memcpy(static_cast<B*>(p)+offset,&v,4);}
// Exact final FLD/FST32/MOV/FSTP32 boundary: even identical input/output bits
// retain x87 NaN quieting, stack overflow/exception and rounding effects.
U spill_restore(void* self){U spill;
    __asm {mov eax,self}
    __asm {fld dword ptr [eax+34h]}
    __asm {fst dword ptr spill}
    __asm {mov edx,spill}
    __asm {fstp dword ptr [eax+34h]}
    return spill;
}
}
U __cdecl render_buffer_state_00540480(U key,U value){return render_settings_set_state_006bd97c(key,value);}
U __cdecl render_buffer_state_alias_005404e0(U key,U value){using Set=U(__stdcall*)(U,U);
    return reinterpret_cast<Set>(render_thrash_exports_006bd910[2])(key,value);
}
U __fastcall render_driver_buffer_apply_00537760(void* self,void*){
    (void)render_buffer_state_00540480(0x28,get(self,4));
    (void)render_buffer_state_00540480(4,get(self,8));
    (void)render_buffer_state_00540480(9,get(self,0x14));
    (void)render_buffer_state_00540480(0x15,get(self,0x18));
    (void)render_buffer_state_alias_005404e0(0xe,get(self,0x1c));
    (void)render_buffer_state_alias_005404e0(0x16,get(self,0x20));
    (void)render_buffer_state_alias_005404e0(0x17,get(self,0x24));
    (void)render_buffer_state_00540480(0xf,get(self,0x28));
    (void)render_buffer_state_00540480(0x3c,get(self,0x2c));
    // 5377dc..e6 loads EAX=self+30, MOV ECX,EAX, CMP ECX,EAX, JE5377fe.
    // The5404a0/deferred5dedf4 block is unreachable for every register value.
    (void)render_buffer_state_00540480(0x39,get(self,0xc));
    const U bits=spill_restore(self);
    return render_buffer_state_alias_005404e0(0x43,bits);
}
void* __fastcall render_driver_buffer_ctor_00537700(void* self,void*){
    put(self,0x28,0);put(self,0x10,1);put(self,8,1);put(self,0xc,1);
    put(self,0,0);put(self,4,3);put(self,0x14,0);put(self,0x18,0);
    put(self,0x1c,0);put(self,0x20,0);put(self,0x24,0x3f7fff00);
    put(self,0x28,0xffffffff);put(self,0x2c,0);put(self,0x30,0);put(self,0x34,0x3f800000);
    (void)render_driver_buffer_apply_00537760(self,nullptr);
    render_resource_flush_states_00535b00();
    return self;
}
}
