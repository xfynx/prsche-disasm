// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 005550e0/434B, 005552a0/40B and 00554f60/212B.
#include "render_texture_scheduler_575.hpp"
#include "texture_process_575.hpp"
#include "../543-render-slot-reset/render_slot_reset_543.hpp"
#include "porsche/files.hpp"
#include "porsche/render_loader.hpp"
#include "porsche/shared_runtime_globals.hpp"
#include <cstring>
#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Original x86 ABI and wrap semantics required
#endif
namespace porsche {
namespace {
using U=std::uint32_t;
using I=std::int32_t;
U load(U p){
    U value;
    std::memcpy(&value,reinterpret_cast<const void*>(p),4);
    return value;
}
void store(U p,U value){std::memcpy(reinterpret_cast<void*>(p),&value,4);}
U address(const void* p){return reinterpret_cast<U>(p);}
U slot(U index){return address(render_texture_slots_006a33f8)+index*48u;}
// Adjacent original strings 005bc2ec..005bc363, preserving their 80-byte spacing.
const char messages[]="[DTEX] Error - trying to upload a texture thats already uploaded.\n Texture %s.\n\0D3D Error - Not enough texture memory.\n";
static_assert(sizeof(messages)==120);
}
I __cdecl render_texture_prepare_00554f60(U node){
    if(load(node+0x10u)!=0){
        diagnostic_file_005deb74_set(render_texture_cleanup_file_005bc294);
        shared_runtime_word_005deb78=0x8b5;
        reinterpret_cast<void (__cdecl*)(const char*,...)>(diagnostic_handler_005debf0)(messages,reinterpret_cast<const char*>(node+0x30u));
    }
    U record=slot(load(node+4u));
    const U width=load(record+0x10u),a=load(record+8u),b=load(record+0xcu),flags=load(record+4u);
    using Create=U (__stdcall*)(U,U,U,U,U);
    const U texture=reinterpret_cast<Create>(render_thrash_exports_006bd910[22])(width,width,a,b,flags);
    store(node+0x10u,texture);
    if(!texture)return 0;
    render_texture_notify_00555040(reinterpret_cast<void*>(node),nullptr);
    const U captured=load(node+0x2cu);
    const U palette=(captured&8u)?load(node+0x1cu):0;
    using Upload=void (__stdcall*)(U,U,U);
    reinterpret_cast<Upload>(render_thrash_exports_006bd910[12])(load(node+0x10u),load(node+0x18u),palette);
    record=slot(load(node+4u));
    store(node+0x2cu,captured|2u);
    const U previous=load(record+0x28u);
    if(previous)store(previous+0xcu,node);
    else store(record+0x2cu,node);
    store(record+0x28u,node);
    store(node+8u,previous);
    store(node+0xcu,0);
    return static_cast<I>(node);
}
I __cdecl render_texture_score_005552a0(U node,I level){
    if(level<0||level>=3)return 1;
    const U index=load(node+4u);
    return static_cast<I>(load(slot(index)+0x18u+static_cast<U>(level)*4u));
}
I __cdecl render_texture_scheduler_005550e0(){
    U current[32],done[32];
    U finished=0,rounds=0,failed=0,level=0xffffffffu;
    if(render_texture_dirty_006a3a48!=0)return -1;
    I count=static_cast<I>(render_texture_slot_count_006a3a44);
    U i=0;
    if(count>0){
        // The original clears the full status prefix before reading any heads.
        for(U n=0;static_cast<I>(n)<count;++n)done[n]=0;
        for(;static_cast<I>(i)<count;++i)current[i]=load(slot(i)+0x24u);
    }
    for(U n=i;n<32;++n)done[n]=1;
    for(;i<32;++i)current[i]=0;
    if(count>0){
        do{
            U index=0;
            bool no_progress=true;
            if(count>0){
                do{
                    if(done[index]==0){
                        const U node=current[index];
                        if(node==0){
                            done[index]=1;
                            ++finished;
                        }
                        else {
                            const I score=render_texture_score_005552a0(node,static_cast<I>(level));
                            if(score>static_cast<I>(rounds)){
                                const I result=render_texture_prepare_00554f60(node);
                                current[index]=load(node);
                                if(result==0)++failed;
                                no_progress=false;
                                if(result==0){
                                    count=static_cast<I>(render_texture_slot_count_006a3a44);
                                    done[index]=1;
                                    ++finished;
                                }else{
                                    count=static_cast<I>(render_texture_slot_count_006a3a44);
                                }
                            }else{
                                count=static_cast<I>(render_texture_slot_count_006a3a44);
                            }
                        }
                    }
                    ++index;
                }while(static_cast<I>(index)<count);
            }
            ++rounds;
            if(no_progress){
                rounds=0;
                ++level;
            }
        }while(static_cast<I>(finished)<count);
    }
    render_texture_dirty_006a3a48=1;
    if(static_cast<I>(failed)>=count&&count>0){
        U index=0;
        do{
            const U node=load(slot(index)+0x24u);
            if(node&&load(node+0x10u)==0){
                diagnostic_file_005deb74_set(render_texture_cleanup_file_005bc294);
                shared_runtime_word_005deb78=0x991;
                diagnostic_handler_005debf0(messages+80);
                count=static_cast<I>(render_texture_slot_count_006a3a44);
            }
            ++index;
        }while(static_cast<I>(index)<count);
    }
    return static_cast<I>(level);
}
// Existing game callers use a void cdecl link name; the original integer result
// is retained by the separate core and is not promoted to an unproved facade ABI.
void __cdecl render_display_texture_update_005550e0(){(void)render_texture_scheduler_005550e0();}
}
