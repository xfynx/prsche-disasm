#include "audio_record_decoder_451.hpp"
#include <cstring>
#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Original opaque-stack transport requires MSVC x86
#endif
namespace porsche {
using U=std::uint32_t;using I=std::int32_t;using B=std::uint8_t;using W=std::uint16_t;
// Raw005e3498..9f: one duration/value pair. See original-evidence.json.
const U audio_record_default_005e3498[2]={0x7fffffff,127};
namespace {
template<class T> T get(const void* p){T x;std::memcpy(&x,p,sizeof x);return x;}
template<class T> void put(void* p,T x){std::memcpy(p,&x,sizeof x);}
B* address(U x){return reinterpret_cast<B*>(x);}
U ptr(const void* p){return reinterpret_cast<U>(p);}
}
//0059bd90..0059bdee: unsigned32 accumulation, signed correction only1..3.
I __cdecl audio_integer_read_0059bd90(const void* bytes,U count){
    const B* p=static_cast<const B*>(bytes);U value=0;
    for(U n=count;n!=0;--n)value=(value<<8)+*p++;
    if(count==1 && static_cast<I>(value)>0x7f)value-=0x100u;
    else if(count==2 && static_cast<I>(value)>0x7fff)value-=0x10000u;
    else if(count==3 && static_cast<I>(value)>0x7fffff)value-=0x1000000u;
    return static_cast<I>(value);
}
//00599760..005997f6: retained cells and reload order are observable on aliasing.
I __cdecl audio_token_read_00599760(void* state){
    B* s=static_cast<B*>(state);U cursor=get<U>(s);
    while(*address(cursor)==0xfc){cursor=get<U>(s)+1;put<U>(s,cursor);}
    cursor=get<U>(s);put<U>(s+4,*address(cursor));
    if(get<U>(s+4)==0xff)return 0;
    U payload=cursor+1;const U id=get<U>(s+4);put<U>(s,payload);
    if(id==0xfd || id==0xfe)return 1;
    put<U>(s+16,*address(payload));
    if(get<U>(s+16)==0xff){
        const I length=audio_integer_read_0059bd90(address(payload+1),4);
        payload+=4;put<U>(s+16,static_cast<U>(length));put<U>(s,payload);
    }
    payload=get<U>(s)+1;const U length=get<U>(s+16);
    put<U>(s,payload);put<U>(s+12,payload);
    if(length<=4)put<U>(s+8,static_cast<U>(audio_integer_read_0059bd90(address(payload),length)));
    put<U>(s,payload+get<U>(s+16));return 1;
}
// Modern core, zero added original bodies. frame is the original retained
//0x464-byte allocation after four saved registers. Unwritten cells stay opaque.
extern "C" I __cdecl audio_record_decoder_core_451(U* cursor,B* record,B* frame){
    const U start=*cursor;put<U>(frame+0x10,start);put<U>(record+0xa0,start);
    std::memset(frame+0x344,0,0x26*4);std::memset(frame+0x3dc,0,0x22*4);
    for(U i=0;i<4;++i){put<U>(record+0x78+4*i,0);put<W>(record+0x88+2*i,0);}
    put<U>(frame+0x44,0xffffffffu);
    put<U>(frame+0xd4,0xffffffffu);
    put<U>(frame+0xd8,0xffffffffu);
    put<U>(frame+0x28,0);
    put<U>(frame+0x2c,0x7fu);
    put<U>(frame+0x30,0);
    put<U>(frame+0x34,0x7fu);
    put<U>(frame+0x3c,0);
    put<U>(frame+0x40,0x3c);
    put<U>(frame+0x48,1);
    put<U>(frame+0x4c,0);
    put<U>(frame+0x54,0x40);
    put<U>(frame+0x58,0);
    put<U>(frame+0x5c,0x7fu);
    put<U>(frame+0x60,0);
    put<U>(frame+0x64,0);
    put<U>(frame+0x68,0);
    put<U>(frame+0x6c,0);
    put<U>(frame+0x70,0);
    put<U>(frame+0x80,0);
    put<U>(frame+0x88,ptr(audio_record_default_005e3498));
    put<U>(frame+0x94,0x7fu);
    put<U>(frame+0x98,0);
    put<U>(frame+0x9c,0);
    put<U>(frame+0xa0,0);
    put<U>(frame+0xa4,0);
    put<U>(frame+0xa8,0);
    put<U>(frame+0xac,0);
    put<U>(frame+0xb0,0);
    put<U>(frame+0xb4,0);
    put<U>(frame+0xb8,1);
    put<U>(frame+0xbc,0);
    put<U>(frame+0xc4,1);
    put<U>(frame+0xcc,0x5622);
    put<U>(frame+0xd0,0);
    put<U>(frame+0xdc,0);
    put<U>(frame+0xe0,0);
    put<U>(frame+0x10c,0);
    put<U>(frame+0x110,0);
    put<U>(frame+0x12c,0);
    put<U>(frame+0x130,0);
    put<U>(frame+0x134,0);
    put<U>(frame+0x138,0);
    put<U>(frame+0x13c,0xa);
    put<U>(frame+0xec,0);
    put<U>(frame+0x140,0);
    record[0x17]=0;I more=0;
    while(audio_token_read_00599760(frame+0x10)!=0){
        const U id=get<U>(frame+0x14),value=get<U>(frame+0x18),payload=get<U>(frame+0x1c);
        if(static_cast<I>(id)<0x26){
            put<U>(frame+0x24+id*4,value);put<U>(frame+0x344+id*4,payload);
            if(id==0x14){
                I index=static_cast<std::int8_t>(record[0x17]);put<U>(address(ptr(record)+0x34+static_cast<U>(index)*4),payload);
                index=static_cast<std::int8_t>(record[0x17]);put<U>(address(ptr(record)+0x44+static_cast<U>(index)*4),get<U>(frame+0x20));
                record[0x17]=static_cast<B>(record[0x17]+1);
            }
        }else if(static_cast<I>(id)>=0x80 && static_cast<I>(id)<0xa2){
            put<U>(frame+0xbc+(id-0x80)*4,value);put<U>(frame+0x3dc+(id-0x80)*4,payload);
            if(id>=0x98 && id<=0x9b){put<U>(record+0x78+(id-0x98)*4,payload);put<W>(record+0x88+(id-0x98)*2,get<W>(frame+0x20));}
        }else if(id==0xfe){more=1;break;}
    }
    put<B>(record+0x8,static_cast<B>(get<B>(frame+0x28))); // 005993b8
    put<B>(record+0x9,static_cast<B>(get<B>(frame+0x2c))); // 005993bf
    put<B>(record+0xb,static_cast<B>(get<B>(frame+0x34))); // 005993c6
    put<B>(record+0xc,static_cast<B>(get<B>(frame+0x3c))); // 005993cd
    put<B>(record+0xe,static_cast<B>(get<B>(frame+0x44))); // 005993d4
    put<B>(record+0xf,static_cast<B>(get<B>(frame+0x48))); // 005993db
    put<B>(record+0xa,static_cast<B>(get<B>(frame+0x30))); // 005993e2
    put<B>(record+0x11,static_cast<B>(get<B>(frame+0x54))); // 005993e9
    put<B>(record+0x12,static_cast<B>(get<B>(frame+0x58))); // 005993f0
    put<B>(record+0xd,static_cast<B>(get<B>(frame+0x40))); // 005993f8
    put<B>(record+0x15,static_cast<B>(get<B>(frame+0x60))); // 005993ff
    put<W>(record+0x4,static_cast<W>(get<W>(frame+0x64))); // 00599409
    put<B>(record+0x10,static_cast<B>(get<B>(frame+0x4c))); // 00599411
    put<B>(record+0x14,static_cast<B>(get<B>(frame+0x5c))); // 00599421
    put<U>(record+0x20,static_cast<U>((get<U>(frame+0x38c)+get<U>(frame+0x6c)))); // 00599429
    put<W>(record+0x6,static_cast<W>(get<W>(frame+0x68))); // 00599433
    put<B>(record+0x16,static_cast<B>(get<B>(frame+0x70))); // 00599444
    put<U>(record+0x24,static_cast<U>((get<U>(frame+0x3a0)+get<U>(frame+0x80)))); // 0059944e
    put<B>(record+0x19,static_cast<B>(get<B>(frame+0x94))); // 00599458
    put<U>(record+0x28,static_cast<U>((get<U>(frame+0x3a8)+get<U>(frame+0x88)))); // 0059946b
    put<B>(record+0x1a,static_cast<B>(get<B>(frame+0x9c))); // 00599475
    put<U>(record+0x2c,static_cast<U>((get<U>(frame+0x3b8)+get<U>(frame+0x98)))); // 00599488
    put<B>(record+0x1b,static_cast<B>(get<B>(frame+0xa0))); // 0059949b
    put<U>(record+0x30,static_cast<U>((get<U>(frame+0x3c4)+get<U>(frame+0xa4)))); // 005994a5
    put<B>(record+0x1c,static_cast<B>(get<B>(frame+0xa8))); // 005994b0
    put<W>(record+0x54,static_cast<W>(get<W>(frame+0xac))); // 005994bb
    put<B>(record+0x1d,static_cast<B>(get<B>(frame+0xb0))); // 005994c6
    put<W>(record+0,static_cast<W>(get<W>(frame+0xb4))); // 005994d0
    put<B>(record+0x1e,static_cast<B>(get<B>(frame+0xb8))); // 005994da
    put<B>(record+0x2,static_cast<B>(get<B>(frame+0xbc))); // 005994e4
    put<B>(record+0x3,static_cast<B>(get<B>(frame+0xc4))); // 005994ef
    put<B>(record+0x13,static_cast<B>(get<B>(frame+0x13c))); // 005994f9
    put<W>(record+0x56,static_cast<W>(get<W>(frame+0xcc))); // 00599503
    put<U>(record+0x58,static_cast<U>(get<U>(frame+0xd0))); // 0059950e
    put<U>(record+0x5c,static_cast<U>(get<U>(frame+0xd4))); // 00599511
    put<U>(record+0x60,static_cast<U>(get<U>(frame+0xd8))); // 0059951b
    put<U>(record+0x64,static_cast<U>(get<U>(frame+0x404))); // 00599525
    put<U>(record+0x68,static_cast<U>(get<U>(frame+0xdc))); // 0059952f
    put<U>(record+0x70,static_cast<U>(get<U>(frame+0x10c))); // 00599540
    put<U>(record+0x6c,static_cast<U>(get<U>(frame+0xe0))); // 0059954a
    put<U>(record+0x90,static_cast<U>(get<U>(frame+0x12c))); // 00599554
    put<U>(record+0x74,static_cast<U>(get<U>(frame+0x110))); // 00599561
    put<U>(record+0x98,static_cast<U>(get<U>(frame+0x134))); // 0059956b
    put<U>(record+0x94,static_cast<U>(get<U>(frame+0x130))); // 00599578
    put<B>(record+0x18,static_cast<B>(get<B>(frame+0xec))); // 00599587
    put<U>(record+0x9c,static_cast<U>(get<U>(frame+0x138))); // 0059958a
    const U flags=get<U>(frame+0x140);
    if(flags!=0 && record[0x18]==0){
        record[0x18]=0;
        if(flags&1)record[0x18]=1;
        if(flags&2)record[0x18]|=2;
        if(flags&0x80)record[0x18]|=0x20;
        if(flags&0x40)record[0x18]|=0x40;
    }
    *cursor=get<U>(frame+0x10);return more;
}
__declspec(naked) I __cdecl audio_group_decode_00599100(U*,void*){
    __asm {
        sub esp,464h
        push ebx
        push ebp
        push esi
        push edi
        mov eax,esp
        mov ecx,dword ptr [esp+47ch]
        mov edx,dword ptr [esp+478h]
        push eax
        push ecx
        push edx
        call audio_record_decoder_core_451
        add esp,0ch
        pop edi
        pop esi
        pop ebp
        pop ebx
        add esp,464h
        ret
    }
}
}
