// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Nine original bodies711B; ordinary C++ control/address/data operations.
#include "audio_pcm_constructors_493.hpp"
#include <cstring>
namespace porsche {
namespace {
using U=std::uint32_t;using I=std::int32_t;using B=std::uint8_t;
U word(U address){U x;std::memcpy(&x,reinterpret_cast<const void*>(address),4);return x;}
void store(U address,U x){std::memcpy(reinterpret_cast<void*>(address),&x,4);}
I signed_word(U address){std::int16_t x;std::memcpy(&x,reinterpret_cast<const void*>(address),2);return x;}
U parameter(const U* params,U index){return word(reinterpret_cast<U>(params)+index*4u);}
template<class T>U address(T function){return reinterpret_cast<U>(function);}
U lookup(U index){return word(reinterpret_cast<U>(audio_mixer_pcm8_lookup_006b00c0)+index*4u);}
void decode(U count,U data,U position,U wide,U output){
    if(wide!=0)reinterpret_cast<void(__cdecl*)(U,U,U)>(audio_mixer_decode_s16_006b17d8)(count,data+position*2u,output);
    else audio_pcm_decode_u8_0059a520(count,data+position,output);
}
}
I __cdecl audio_pcm_channel_owner_00589710(U channel){
    const U base=audio_backend_channels_006b4a00;
    const I owner=signed_word(base+channel*112u+0x1c);
    return owner==-1?static_cast<I>(channel):owner;
}
U __cdecl audio_pcm_channel_member_00589740(U channel){
    const U base=audio_backend_channels_006b4a00;
    const I owner=signed_word(base+channel*112u+0x1c);
    if(owner==-1)return 0;
    const U members=base+static_cast<U>(owner)*112u+6u;
    for(U index=1;index<4;++index)if(static_cast<U>(signed_word(members+(index-1u)*2u))==channel)return index;
    return 0;
}
U __cdecl audio_pcm_position_00597b50(U object){return word(object+0x10);}
void __cdecl audio_mixer_construct_pcm_00597c10(U object,U* params){
    const U data=parameter(params,0);
    store(object+4,address(&audio_pcm_process_00597b60));store(object+0xc,data);
    const U limit=parameter(params,3);store(object+0x14,limit);
    const U wide=parameter(params,4);store(object+0x10,0);store(object+0x18,wide);
    store(reinterpret_cast<U>(params)+0x1c,address(&audio_pcm_position_00597b50));
}
void __cdecl audio_mixer_construct_pcm_loop_0059cc30(U object,U* params){
    const U data=parameter(params,0);
    store(object+4,address(&audio_pcm_loop_process_0059cba0));store(object+0xc,data);
    const U start=parameter(params,1);store(object+0x14,start);
    const U end=parameter(params,2),wide=parameter(params,4);
    store(object+0x10,0);store(object+0x18,end);store(object+0x1c,wide);
}
void __cdecl audio_mixer_construct_pcm_stream_0059cb50(U object,U* params){
    const U channel=parameter(params,5);
    store(object+4,address(&audio_pcm_stream_process_0059ca50));
    const I owner=audio_pcm_channel_owner_00589710(channel);
    const I index=audio_pcm_stream_find_0059c130(owner);
    store(object+0x18,static_cast<U>(index));
    const U member=audio_pcm_channel_member_00589740(channel);
    const B wide=*reinterpret_cast<const B*>(reinterpret_cast<U>(params)+0x10);
    reinterpret_cast<B*>(object)[0x21]=static_cast<B>(member);
    store(object+0xc,0);store(object+0x10,0xffffffffu);store(object+0x14,0);
    reinterpret_cast<B*>(object)[0x20]=wide;store(object+0x1c,0);
}
void __cdecl audio_pcm_decode_u8_0059a520(U count,U source,U output){
    U remaining=count;
    while((remaining&3u)!=0){
        const U index=remaining-1u;
        const B byte=*reinterpret_cast<const B*>(source+index);
        store(output+index*4u,lookup(byte));
        --remaining;if(remaining==0)return;
    }
    do{
        const U index=remaining-4u;
        const B a=*reinterpret_cast<const B*>(source+index),b=*reinterpret_cast<const B*>(source+index+1u);
        const U first=lookup(a),second=lookup(b);
        const B c=*reinterpret_cast<const B*>(source+index+2u),d=*reinterpret_cast<const B*>(source+index+3u);
        store(output+index*4u,first);store(output+(index+1u)*4u,second);
        const U third=lookup(c),fourth=lookup(d);
        store(output+(index+2u)*4u,third);store(output+(index+3u)*4u,fourth);
        remaining-=4u;
    }while(static_cast<I>(remaining)>0);
}
I __cdecl audio_pcm_process_00597b60(U object,U count,U,U output,U){
    const U position=word(object+0x10),limit=word(object+0x14);
    if(position>=limit)return -1;
    const U advanced=position+count;store(object+0x10,advanced);
    const U wide=word(object+0x18),data=word(object+0xc);
    if(advanced<limit)decode(count,data,position,wide,output);
    else{
        const U available=limit-position;
        decode(available,data,position,wide,output);
        application_audio_backend_configure_0058fef0(output+available*4u,(count-available)*4u);
    }
    return 1;
}
I __cdecl audio_pcm_loop_process_0059cba0(U object,U count,U,U output,U){
    U remaining=count;
    while(static_cast<I>(remaining)>0){
        const U position=word(object+0x10);
        U block=word(object+0x18)-position+1u;
        if(static_cast<I>(remaining)<static_cast<I>(block))block=remaining;
        const U wide=word(object+0x1c),data=word(object+0xc);
        decode(block,data,position,wide,output);
        remaining-=block;
        const U end=word(object+0x18),advanced=position+block;
        store(object+0x10,advanced);
        if(advanced>end)store(object+0x10,word(object+0x14));
        output+=block*4u;
    }
    return 1;
}
}
