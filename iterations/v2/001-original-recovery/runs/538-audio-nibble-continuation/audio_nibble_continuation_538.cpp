// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// 0059c690..0059c888,505B,fullRET; no new data. Actual cdecl5 callback.
#include "audio_nibble_continuation_538.hpp"
#include <cstring>
namespace porsche {
namespace {
using U=std::uint32_t;using I=std::int32_t;
U word(U address){U value;std::memcpy(&value,reinterpret_cast<const void*>(address),4);return value;}
void store(U address,U value){std::memcpy(reinterpret_cast<void*>(address),&value,4);}
I integer(U value){return static_cast<I>(value);}
U offset(U position){return static_cast<U>(integer(position*15u)/28);}
void decode(U object){reinterpret_cast<void(__cdecl*)(U)>(word(object+0x38))(object+0xc);}
}
I __cdecl audio_nibble_loop_continue_0059c690(U object,U requested,U,U output,U){
    // Original frame: output esp+1c..8b; x87 writes histories atesp+14/18.
    // Keep that8B prefix plus112B output, uninitialized until decoder writes.
    U scratch[30];const U scratch_output=reinterpret_cast<U>(scratch)+8u;
    U remaining=requested;store(object+0x1c,output);
    while(integer(remaining)>0){
        const U carry=word(object+0x34);
        if(carry!=0){
            const U used=static_cast<U>(audio_nibble_drain_0059d5f0(carry,object+0x4c,remaining,object+0x1c));
            const U late_carry=word(object+0x34);remaining-=used;store(object+0x34,late_carry-used);
        }else{
            const U position=word(object+0x28),end=word(object+0x30);
            if(integer(position+27u)<integer(end)){
                store(object+0xc,28);const U base=word(object+0x20);
                store(object+0x18,base+offset(position));decode(object);
                store(object+0x28,word(object+0x28)+28u);remaining-=28u;
            }else{
                const U saved_output=word(object+0x1c),base=word(object+0x20);
                store(object+0xc,28);store(object+0x18,base+offset(position));store(object+0x1c,object+0x4c);decode(object);
                const U late_end=word(object+0x30),late_position=word(object+0x28),start=word(object+0x2c);
                const U first=word(object+0x3c);store(object+0x10,first);
                store(object+0x34,late_end-late_position+1u);
                const U second=word(object+0x40);store(object+0x14,second);
                const U aligned=static_cast<U>(integer(start)/28)*28u;
                const I remainder=integer(start)%28;store(object+0x28,aligned);
                if(remainder!=0){
                    store(object+0xc,28);const U late_base=word(object+0x20);
                    store(object+0x18,late_base+offset(aligned));store(object+0x1c,scratch_output);decode(object);
                    const U advanced=word(object+0x28)+28u,late_start=word(object+0x2c);store(object+0x28,advanced);
                    U extra=advanced-late_start,source=scratch_output+112u-extra*4u;
                    if(integer(extra)>0)do{
                        const U count=word(object+0x34),value=word(source);source+=4u;store(object+count*4u+0x4c,value);
                        const U late_count=word(object+0x34);store(object+0x34,late_count+1u);
                    }while(--extra!=0);
                }
                store(object+0x1c,saved_output);
            }
        }
    }
    store(object+0x1c,word(object+0x1c)+remaining*4u);
    if(integer(remaining)<0){
        U extra=0u-remaining;
        do{
            const U source=word(object+0x1c),count=word(object+0x34),value=word(source);
            store(object+count*4u+0x4c,value);
            const U late_output=word(object+0x1c),late_count=word(object+0x34);
            store(object+0x1c,late_output+4u);store(object+0x34,late_count+1u);
        }while(--extra!=0);
    }
    return 1;
}
}
