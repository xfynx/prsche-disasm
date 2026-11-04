// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// 00597c40(363B),0059c3c0(579B),0059c890(344B),0059d5f0(94B);0data.
#include "audio_nibble_process_534.hpp"
#include <cstring>
namespace porsche {
namespace {
using U=std::uint32_t;using I=std::int32_t;using B=std::uint8_t;
U word(U p){U v;std::memcpy(&v,reinterpret_cast<const void*>(p),4);return v;}
void store(U p,U v){std::memcpy(reinterpret_cast<void*>(p),&v,4);}
U byte(U p){return *reinterpret_cast<const B*>(p);}
void store_byte(U p,U v){*reinterpret_cast<B*>(p)=static_cast<B>(v);}
I signed_byte(U p){return static_cast<signed char>(byte(p));}
I signed_half(U p){std::int16_t v;std::memcpy(&v,reinterpret_cast<const void*>(p),2);return v;}
I integer(U v){return static_cast<I>(v);}
// Original LEA wraps15*position before signed magic division by28.
U offset(U position){return static_cast<U>(integer(position*15u)/28);}
void decode(U object,U slot){reinterpret_cast<void(__cdecl*)(U)>(word(object+slot))(object+0xc);}
void copy_out(U object,U source,U count){
    if(integer(count)>0)do{const U output=word(object+0x1c),value=word(source);source+=4u;store(output,value);--count;store(object+0x1c,output+4u);}while(count!=0);
}
U compact_tail(U object,U local,U residual){
    U carry=0;
    if(integer(residual)<0){
        U displacement=residual*4u;carry=0u-residual;U destination=object+local;
        do{const U output=word(object+0x1c);displacement+=4u;destination+=4u;const U value=word(output+displacement-4u);store(destination-4u,value);}while(integer(displacement)<0);
    }
    return carry;
}
// Two original FILD/FSTP operations; histories are signed16, not normalized.
void history(I first,I second,U object){__asm {
    fild first
    mov ecx,object
    fstp dword ptr [ecx+10h]
    fild second
    fstp dword ptr [ecx+14h]
}}
}
I __cdecl audio_nibble_drain_0059d5f0(U available,U buffer,U requested,U output_slot){
    U output=word(output_slot),count=requested;
    if(integer(available)<integer(requested))count=available;
    U copied=0;
    if(integer(count)>0){for(U index=0;index<count;++index)store(output+index*4u,word(buffer+index*4u));output+=count*4u;copied=count;}
    if(integer(copied)<integer(available)){
        U source=buffer+copied*4u,destination=buffer,left=available-copied;
        do{const U value=word(source);source+=4u;store(destination,value);destination+=4u;}while(--left!=0);
    }
    store(output_slot,output);return integer(count);
}
I __cdecl audio_nibble_process_00597c40(U object,U requested,U,U output,U){
    const U position=word(object+0x28),limit=word(object+0x24);
    if(integer(position)>=integer(limit))return -1;
    const U carry=word(object+0x2c);store(object+0x1c,output);
    if(integer(requested)<=integer(carry)){
        const U copied=integer(requested)>0?requested:0u;copy_out(object,object+0x30,requested);
        U index=copied,remaining=0;
        if(integer(index)<integer(word(object+0x2c))){
            U source=object+0x30+index*4u,destination=object+0x30;
            do{const U value=word(source);++remaining;store(destination,value);const U late=word(object+0x2c);destination+=4u;++index;source+=4u;if(integer(index)>=integer(late))break;}while(true);
        }
        store(object+0x2c,remaining);return 1;
    }
    copy_out(object,object+0x30,carry);
    const U remaining=requested-word(object+0x2c);
    U available=limit-position;if(integer(available)<0)available=0;
    U amount=remaining;if(integer(remaining)>=integer(available))amount=available;
    store(object+0xc,amount);store(object+0x18,word(object+0x20)+offset(position));
    decode(object,0x9c);
    const U residual=word(object+0xc),new_position=word(object+0x28)+amount-residual;
    store(object+0x28,new_position);
    if(available==amount){
        U silence=remaining+word(object+0x24)-new_position-amount;
        if(integer(silence)>0){U destination=word(object+0x1c);do{store(destination,0);destination+=4u;}while(--silence!=0);store(object+0x1c,destination);}
        return 1;
    }
    store(object+0x2c,compact_tail(object,0x30,residual));return 1;
}
I __cdecl audio_nibble_loop_process_0059c890(U object,U requested,U input,U output,U){
    U carry=word(object+0x34);store(object+0x1c,output);
    if(integer(requested)<=integer(carry)){
        U index=integer(requested)>0?requested:0u;copy_out(object,object+0x4c,requested);U remaining=0;
        if(integer(index)<integer(carry)){
            U source=object+0x4c+index*4u,destination=object+0x4c;
            do{const U value=word(source);++remaining;store(destination,value);carry=word(object+0x34);destination+=4u;++index;source+=4u;if(integer(index)>=integer(carry))break;}while(true);
        }
        store(object+0x34,remaining);return 1;
    }
    copy_out(object,object+0x4c,carry);
    const U position=word(object+0x28),remaining=requested-carry;
    const U available=word(object+0x2c)-position-27u;
    U amount=remaining;if(integer(remaining)>=integer(available))amount=available;if(integer(amount)<0)amount=0;
    store(object+0xc,amount);store(object+0x18,word(object+0x20)+offset(position));decode(object,0x38);
    const U residual=word(object+0xc);store(object+0x28,word(object+0x28)+amount-residual);
    const U buffered=compact_tail(object,0x4c,residual),destination=word(object+0x1c)-buffered*4u;
    store(object+0x34,buffered);store(object+0x1c,destination);
    const U late_position=word(object+0x28),late_remaining=remaining-amount;
    if(integer(word(object+0x2c)-late_position)<28){
        store(object+0x3c,word(object+0x10));store(object+0x40,word(object+0x14));
        store(object+4,reinterpret_cast<U>(&audio_nibble_loop_continue_0059c690));
        if(integer(late_remaining)>0)(void)audio_nibble_loop_continue_0059c690(object,late_remaining,input,destination,static_cast<U>(signed_half(object+0xa)));
    }
    return 1;
}
I __cdecl audio_nibble_stream_process_0059c3c0(U object,U requested,U,U output,U){
    store(object+0x1c,output);
    const U pending=word(object+0x30);
    if(pending!=0){audio_stream_acknowledge_005618c0(word(object+0x2c),byte(object+0x39),pending);store(object+0x30,0);}
    U remaining=requested;
    while(integer(remaining)>0){
        const U buffered=byte(object+0x38);
        if(buffered!=0){
            const U used=static_cast<U>(audio_nibble_drain_0059d5f0(static_cast<U>(signed_byte(object+0x38)),object+0x3c,remaining,object+0x1c));
            const U late=byte(object+0x38),processed=word(object+0x30);
            remaining-=used;store_byte(object+0x38,late-used);store(object+0x30,processed+used);
        }else{
            const U position=word(object+0x28),limit=word(object+0x24);
            if(integer(position+27u)<integer(limit)){
                U amount=static_cast<U>(integer(limit-position)/28)*28u;
                if(integer(remaining)<integer(amount))amount=static_cast<U>(integer(remaining+27u)/28)*28u;
                store(object+0xc,amount);store(object+0x18,word(object+0x20)+offset(position));decode(object,0x34);
                const U late_position=word(object+0x28),processed=word(object+0x30);
                remaining-=amount;store(object+0x28,late_position+amount);store(object+0x30,processed+amount);
            }else{
                if(integer(position)<integer(limit)){
                    store(object+0xc,28);store(object+0x18,word(object+0x20)+offset(position));decode(object,0x34);
                    const U advanced=word(object+0x28)+28u,late_limit=word(object+0x24),destination=word(object+0x1c);
                    store(object+0x28,advanced);const U extra=advanced-late_limit;
                    remaining+=extra-28u;store(object+0x1c,destination-extra*4u);
                    store(object+0x30,word(object+0x30)+28u-extra);
                }
                const U data=audio_stream_acquire_00561800(word(object+0x2c),byte(object+0x39),reinterpret_cast<U*>(object+0x24));
                store(object+0x20,data);
                if(data!=0){
                    const I first=signed_half(data),second=signed_half(data+2);
                    store(object+0x20,data+4u);store(object+0x28,0);history(first,second,object);
                }else{
                    if(integer(remaining)>0){
                        if(word(object+0x30)!=0){U destination=word(object+0x1c),left=(remaining*4u)>>2;if(left!=0)do{store(destination,0);destination+=4u;}while(--left!=0);}
                        store(object+0x1c,word(object+0x1c)+remaining*4u);remaining=0;
                    }
                    break;
                }
            }
        }
    }
    store(object+0x1c,word(object+0x1c)+remaining*4u);
    if(integer(remaining)<0){
        const U buffered=0u-remaining;
        const U destination=object+0x3c+static_cast<U>(signed_byte(object+0x38))*4u;
        (void)audio_stream_copy_forward_00598a50(destination,word(object+0x1c),buffered*4u);
        const U prior=byte(object+0x38),processed=word(object+0x30);
        store_byte(object+0x38,prior+buffered);store(object+0x30,processed-buffered);
    }
    return integer(word(object+0x30));
}
}
