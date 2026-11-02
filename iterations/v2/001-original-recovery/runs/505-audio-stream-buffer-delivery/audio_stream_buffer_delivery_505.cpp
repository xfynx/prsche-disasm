// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// 00561800(190B),005618c0(50B), no new state.
#include "audio_stream_buffer_delivery_505.hpp"
#include <cstring>
namespace porsche {
namespace {
using U=std::uint32_t;using I=std::int32_t;using S=std::uint16_t;
U word(U p){U v;std::memcpy(&v,reinterpret_cast<const void*>(p),4);return v;}
S half(U p){S v;std::memcpy(&v,reinterpret_cast<const void*>(p),2);return v;}
I signed_half(U p){std::int16_t v;std::memcpy(&v,reinterpret_cast<const void*>(p),2);return v;}
void store(U p,U v){std::memcpy(reinterpret_cast<void*>(p),&v,4);}
void store_half(U p,S v){std::memcpy(reinterpret_cast<void*>(p),&v,2);}
U chunk_at(U record,I cursor){return record+(static_cast<U>(cursor)+3u)*24u;}
}
U __cdecl audio_stream_acquire_00561800(U index,U member,U* length){
    const U record=audio_stream_slots_006b7cc0[index];
    const U cursor=record+8u+member*2u,available=record+0x10u+member*2u;
    if(half(available)==0)return 0;
    store_half(cursor,static_cast<S>(half(cursor)+1u));
    if(signed_half(cursor)>=signed_half(record+0x18))store_half(cursor,0);
    const U chunk=chunk_at(record,signed_half(cursor));
    const U size=word(chunk+4u);
    store(reinterpret_cast<U>(length),size);
    if(member==static_cast<U>(signed_half(record+0x1a))){
        const I previous=signed_half(record+0x1c);
        if(previous>=0){
            const U previous_chunk=chunk_at(record,previous),callback=word(record+0x2c);
            if(callback!=0)reinterpret_cast<void(__cdecl*)(U)>(callback)(word(previous_chunk+8u));
        }
        store_half(record+0x1c,static_cast<S>(half(record+0x1c)+1u));
        if(signed_half(record+0x1c)>=signed_half(record+0x18))store_half(record+0x1c,0);
        store(record+0x20,word(record+0x20)-size);
        store(record+0x24,word(record+0x24)+size);
    }
    store_half(available,static_cast<S>(half(available)-1u));
    return word(chunk+member*4u+8u);
}
void __cdecl audio_stream_acknowledge_005618c0(U index,U member,U count){
    const U record=audio_stream_slots_006b7cc0[index];
    if(member!=static_cast<U>(signed_half(record+0x1a)))return;
    store(record+0x24,word(record+0x24)-count);
    const U callback=word(record+0x30);
    if(callback!=0)reinterpret_cast<void(__cdecl*)(U,U)>(callback)(index,count);
}
}
