// Porsche.exe SHA256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Full0058f5b0(30B) and0058e500(329B); canonical443/452 state reused.
#include "audio_slot_create_722.hpp"
#include <cstring>
namespace porsche {
namespace {
using U=std::uint32_t;using I=std::int32_t;using B=std::uint8_t;
U read(const void* p){U x;std::memcpy(&x,p,4);return x;}
void word(B* p,U v){const auto w=static_cast<std::uint16_t>(v);std::memcpy(p,&w,2);}
void dword(B* p,U v){std::memcpy(p,&v,4);}
template<class F>F method(U object,U off){return reinterpret_cast<F>(read(reinterpret_cast<const void*>(read(reinterpret_cast<const void*>(object))+off)));}
}
I __cdecl audio_resource_free_slot_0058f5b0(){
    for(U slot=1u;slot<256u;++slot){
        if(read(audio_resource_slots_006ad7b8+slot*24u)==0u)return static_cast<I>(slot);
    }
    return 0;
}
I __cdecl audio_resource_create_slot_0058e500(U slot){
    B* const row=audio_resource_slots_006ad7b8+slot*24u;
    const U source=read(row);
    if(source==0u)return 0;
    const U count=read(row+8u);
    const U bits=row[0x17]==8u?16u:slot;
    U length=count;
    if(static_cast<I>(read(row+0x10u))>0)length=read(row+0x10u)-read(row+0xcu)+1u;
    const U bytes_per_sample=static_cast<U>(static_cast<I>(bits)>>3);
    const U bytes=bytes_per_sample*length;
    B wave[18];word(wave,1u);word(wave+2u,1u);
    std::uint16_t rate;std::memcpy(&rate,row+0x14u,2u);
    dword(wave+4u,rate);dword(wave+8u,static_cast<U>(rate)*bytes_per_sample);
    word(wave+12u,bytes_per_sample);word(wave+14u,bits);word(wave+16u,0u);
    U descriptor[9]={};descriptor[0]=0x24u;descriptor[1]=0x480b0u;descriptor[2]=bytes;descriptor[4]=reinterpret_cast<U>(wave);
    using Create=I(__stdcall*)(U,const void*,void*,U);
    const U device=audio_ds_device_006ad760;
    if(method<Create>(device,0xcu)(device,descriptor,row+4u,0u)!=0)return 0;
    U output;U output_bytes; // Only read after successful Lock, whose endpoint must write them.
    using Lock=I(__stdcall*)(U,U,U,U*,U*,U,U,U);
    const U object=read(row+4u);
    if(method<Lock>(object,0x2cu)(object,0u,bytes,&output,&output_bytes,0u,0u,0u)==0){
        (void)audio_resource_copy_0058e310(source,static_cast<std::int8_t>(row[0x16]),
            static_cast<I>(read(row+0xcu)),static_cast<I>(read(row+0x10u)),count,
            reinterpret_cast<void*>(output),static_cast<std::int8_t>(row[0x17]));
        using Unlock=I(__stdcall*)(U,U,U,U,U);
        const U current=read(row+4u);
        if(method<Unlock>(current,0x4cu)(current,output,bytes,0u,0u)!=0)return 0;
    }
    return static_cast<I>(slot);
}
}
