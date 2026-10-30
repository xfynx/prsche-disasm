#include "audio_groups_448.hpp"
#include <cstring>
#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Original opaque-stack transport requires MSVC x86
#endif
namespace porsche {
using U=std::uint32_t;using I=std::int32_t;
namespace {
template<class T> T get(U address){T value;std::memcpy(&value,reinterpret_cast<const void*>(address),sizeof(value));return value;}
void put(U address,U value){std::memcpy(reinterpret_cast<void*>(address),&value,4);}
U state_word(U offset){U value;std::memcpy(&value,application_audio_device_state_006b48c0.data()+offset,4);return value;}
U group_at(I index){return state_word(0x144)+static_cast<U>(index)*12u;}
}
// 00590070..005900a9: signed index, unsigned low16 count, byte+8 busy.
I __cdecl application_audio_validate_channel_00590070(I index){
    if(index<0 || index>=static_cast<I>(state_word(0x18)&0xffffu))return -8;
    const U group=group_at(index);
    if(get<U>(group)==0)return -8;
    return get<std::uint8_t>(group+8)!=0 ? -18 : 0;
}
// 00590170..005901ae: negative mapped indices intentionally retain x86 wrap.
U __cdecl audio_group_select_00590170(U header,I item){
    if(item>=static_cast<I>(get<std::uint16_t>(header+6)))return 0;
    const U slot=header+static_cast<U>(item)*4u+(get<std::uint8_t>(header+4)==4?0x14u:0x0cu);
    const U relative=get<U>(slot);
    return relative ? slot+relative : 0;
}
// 00590000..0059006d: captured header survives callbacks; table flag reloads.
I __cdecl audio_group_release_item_00590000(I group,I item,U* scratch){
    const U header=get<U>(group_at(group));
    const U resource=audio_group_select_00590170(header,item);
    if(resource==0)return -8;
    audio_group_release_resources_00590b50(resource,scratch);
    if(get<std::uint8_t>(group_at(group)+10)!=0){
        const U slot=header+static_cast<U>(item)*4u+(get<std::uint8_t>(header+4)==4?0x14u:0x0cu);
        put(slot,0);
    }
    return 0;
}
// Modern core for the original00565990 stack adapter; adds no original body.
extern "C" I __cdecl audio_group_release_core_448(I group,I count,U* scratch){
    for(I item=0;item<count;++item)audio_group_release_item_00590000(group,item,scratch);
    return 0;
}
// 00565990..005659ec: 0x800 bytes, 256 even DWORD sentinels only. Keeping the
// original backing position exposes the same opaque odd words to child code.
__declspec(naked) I __cdecl application_audio_release_group_00565990(I,U){
    __asm {
        sub esp,800h
        mov eax,esp
        mov ecx,100h
    initialize_even:
        mov dword ptr [eax],0ffffffffh
        add eax,8
        dec ecx
        jnz initialize_even
        mov eax,esp
        push eax
        push dword ptr [esp+80ch]
        push dword ptr [esp+80ch]
        call audio_group_release_core_448
        add esp,0ch
        add esp,800h
        ret
    }
}
// Modern core for00590b50's original184B backing. The child producer owns the
// decoded fields; no record clear, invented count limit or decoder is supplied.
extern "C" I __cdecl audio_group_resources_core_448(U* cursor,std::uint8_t* record,U* payload,U* scratch){
    const U item=*cursor;
    *cursor=item+((get<std::uint8_t>(item+3)&2u)!=0?8u:4u);
    I more;
    do {
        more=audio_group_decode_00599100(cursor,record);
        audio_group_process_005996d0(record,scratch);
        if(static_cast<std::int8_t>(record[0x17])<=0)continue;
        I callbacks=static_cast<std::int8_t>(application_audio_device_state_006b48c0[0xe2]);
        while(static_cast<std::int8_t>(record[0x17])>0){
            const I entry=static_cast<std::int8_t>(record[0x17])-1;
            record[0x17]=static_cast<std::uint8_t>(entry);
            payload[0]=2;
            payload[1]=get<U>(reinterpret_cast<U>(record)+0x34u+static_cast<U>(entry)*4u);
            payload[2]=get<U>(reinterpret_cast<U>(record)+0x44u+static_cast<U>(entry)*4u);
            if(callbacks>0){
                I index=0;
                do {
                    using Callback=void(__cdecl*)(U*);
                    const auto function=reinterpret_cast<Callback>(state_word(0x120u+static_cast<U>(index)*4u));
                    function(payload);
                    callbacks=static_cast<std::int8_t>(application_audio_device_state_006b48c0[0xe2]);
                    ++index;
                }while(index<callbacks);
            }
        }
    }while(more!=0);
    return 0;
}
// 00590b50..00590c12: retain stack-backed decoded/payload regions and the
// original mutable argument cell; child effects and opaque bytes stay visible.
__declspec(naked) I __cdecl audio_group_release_resources_00590b50(U,U*){
    __asm {
        sub esp,0b8h
        push ebx
        push ebp
        push esi
        push edi
        lea eax,[esp+24h]
        lea ecx,[esp+10h]
        lea edx,[esp+0cch]
        push dword ptr [esp+0d0h]
        push ecx
        push eax
        push edx
        call audio_group_resources_core_448
        add esp,10h
        pop edi
        pop esi
        pop ebp
        pop ebx
        add esp,0b8h
        ret
    }
}
}
