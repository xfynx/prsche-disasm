// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// 597e30/232B,59c1e0/378B,59b690/404B; original caller glue, no codec math/data.
#include "audio_codec_process_550.hpp"
#include <cstring>
namespace porsche {
namespace {
using U=std::uint32_t;using I=std::int32_t;using B=std::uint8_t;
U word(U p){U v;std::memcpy(&v,reinterpret_cast<const void*>(p),4);return v;}
U half(U p){std::uint16_t v;std::memcpy(&v,reinterpret_cast<const void*>(p),2);return v;}
U byte(U p){return *reinterpret_cast<const B*>(p);}
void store(U p,U v){std::memcpy(reinterpret_cast<void*>(p),&v,4);}
void shalf(U p,U v){const auto w=static_cast<std::uint16_t>(v);std::memcpy(reinterpret_cast<void*>(p),&w,2);}
U minimum(U a,U b){return static_cast<I>(a)<static_cast<I>(b)?a:b;}
// The original resampler body contains forward REP MOVSD/STOSD. These loops
// preserve wrapping byte-count reduction and overlap order; no host memcpy.
void copy_words(U destination,U source,U bytes){for(U n=bytes>>2;n!=0;--n){store(destination,word(source));source+=4;destination+=4;}}
void zero_words(U destination,U bytes){for(U n=bytes>>2;n!=0;--n){store(destination,0);destination+=4;}}
}
I __cdecl audio_adpcm_process_00597e30(U object,U requested,U,U output,U){
    const U position=word(object+0xd54),limit=word(object+0xd4c);
    if(position>=limit)return -1;
    const U advanced=position+requested;store(object+0xd54,advanced);
    U overflow=advanced-limit,remaining=requested;
    if(static_cast<I>(overflow)>0)remaining-=overflow;else overflow=0;
    const U prior=word(object+0xd50);U count=minimum(remaining,prior);
    (void)audio_stream_copy_forward_00598a50(output,object+(0x353u-prior)*4u,count*4u);
    U late=word(object+0xd50);remaining-=count;output+=count*4u;store(object+0xd50,late-count);
    while(static_cast<I>(remaining)>0){
        audio_adpcm_decode_0059a910(object+0xc,0);
        store(object+0xd50,0x1b0);count=minimum(remaining,0x1b0);
        (void)audio_stream_copy_forward_00598a50(output,object+0x68c,count*4u);
        late=word(object+0xd50);remaining-=count;output+=count*4u;store(object+0xd50,late-count);
    }
    if(static_cast<I>(overflow)>0){U left=overflow;do{store(output,0);output+=4u;}while(--left!=0);}
    return 1;
}
I __cdecl audio_adpcm_stream_process_0059c1e0(U object,U requested,U,U output,U){
    const U pending=word(object+0xd58);
    if(pending){audio_stream_acknowledge_005618c0(word(object+0xd54),byte(object+0xd60),pending);store(object+0xd58,0);}
    U remaining=requested;
    while(static_cast<I>(remaining)>0){
        if(static_cast<I>(half(object+0xd5c))>=static_cast<I>(word(object+0xd50))){
            const U data=audio_stream_acquire_00561800(word(object+0xd54),byte(object+0xd60),reinterpret_cast<U*>(object+0xd50));
            store(object+0xd4c,data);shalf(object+0xd5c,0);
            if(!data){const U processed=word(object+0xd58);if(processed)application_audio_backend_configure_0058fef0(output,remaining*4u);store(object+0xd50,0);return static_cast<I>(processed);}
            if(byte(data)){shalf(object+0xd5e,0);audio_adpcm_initialize_0059a800(data+1,object+0xc);}
            else{store(object+0x14,8);store(object+0x10,byte(data+1));store(object+0xc,data+2);}
        }
        if(half(object+0xd5e)==0){audio_adpcm_decode_0059a910(object+0xc,0);shalf(object+0xd5e,0x1b0);}
        U count=minimum(remaining,word(object+0xd50)-half(object+0xd5c));
        const U buffered=half(object+0xd5e);count=minimum(count,buffered);
        (void)audio_stream_copy_forward_00598a50(output,object+(0x353u-buffered)*4u,count*4u);
        const U processed=word(object+0xd58);
        shalf(object+0xd5c,half(object+0xd5c)+count);shalf(object+0xd5e,half(object+0xd5e)-count);
        remaining-=count;output+=count*4u;store(object+0xd58,processed+count);
    }
    return static_cast<I>(word(object+0xd58));
}
I __cdecl audio_resampler_stream_process_0059b690(U object,U requested,U,U output,U){
    const U pending=word(object+0xe4);
    if(pending){audio_stream_acknowledge_005618c0(word(object+0xe0),byte(object+0xec),pending);store(object+0xe4,0);}
    U remaining=requested;
    while(static_cast<I>(remaining)>0){
        if(static_cast<I>(half(object+0xe8))>=static_cast<I>(word(object+0xdc))){
            const U data=audio_stream_acquire_00561800(word(object+0xe0),byte(object+0xec),reinterpret_cast<U*>(object+0xdc));
            store(object+0xd8,data);
            if(!data){const U processed=word(object+0xe4);if(processed)zero_words(output,remaining*4u);store(object+0xdc,0);shalf(object+0xe8,0);return static_cast<I>(processed);}
            shalf(object+0xe8,0);
        }
        if(half(object+0xea)==0){audio_resampler_decode_00597810(word(object+0xd8),object+0xf0,object+0x10);shalf(object+0xea,0xa0);}
        U count=minimum(remaining,word(object+0xdc)-half(object+0xe8));
        const U buffered=half(object+0xea);count=minimum(count,buffered);
        copy_words(output,object+(0xdcu-buffered)*4u,count*4u);
        const U position=half(object+0xe8);remaining-=count;shalf(object+0xe8,position+count);shalf(object+0xea,buffered-count);
        output+=count*4u;store(object+0xe4,word(object+0xe4)+count);
    }
    return static_cast<I>(word(object+0xe4));
}
}
