// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Complete 004ad510 (172B), 004ad670 (78B), 004ad6c0 (43B).
#include "audio_resource_controls_478.hpp"
namespace porsche {
void* audio_channel_banks_00656aa8[2] = {};
std::uint32_t audio_resource_query_root_00656ab4 = 0;
namespace {
using U=std::uint32_t;using I=std::int32_t;using B=std::uint8_t;
U& cell(B* object,U offset){return *reinterpret_cast<U*>(object+offset);}
}
void __cdecl frame_services_boundary_004ad510(){
    for(U root=0;root<2;++root){
        auto* const object=reinterpret_cast<B*>(audio_channel_banks_00656aa8[root]);
        if(object==nullptr)continue;
        object[0x2d3]=object[0x2d2];
        if(static_cast<I>(cell(object,0x3c))>=0){
            audio_channel_stop_00565d60(cell(object,0x3c));
            cell(object,0x3c)=0xffffffffu;
        }
        if(static_cast<I>(cell(object,0x38))>=0){
            audio_channel_stop_00565d60(cell(object,0x38));
            cell(object,0x38)=0xffffffffu;
        }
        for(U index=0;index<32;++index){
            const U first=0x45c+12*index,second=0x5dc+12*index;
            if(cell(object,first)!=0xffffffffu)audio_channel_stop_00565d60(cell(object,first));
            if(cell(object,second)!=0xffffffffu)audio_channel_stop_00565d60(cell(object,second));
            cell(object,0x44+4*index)=0;
            cell(object,first)=0xffffffffu;
            cell(object,second)=0xffffffffu;
        }
    }
}
U __cdecl splash_progress_resource_begin_004ad670(){
    auto* const object=reinterpret_cast<B*>(audio_resource_query_root_00656ab4);
    if(object==nullptr)return 0;
    if(cell(object,0x88)==0)return 0;
    if(cell(object,0x1c)!=0)return 0;
    if(cell(object,0x14)!=2){
        if(cell(object,0x8c)==0)return 0;
        if(static_cast<I>(cell(object,0xa0))<=static_cast<I>(cell(object,0xa4)))return 0;
    }
    return cell(object,0x84);
}
U __cdecl splash_progress_resource_end_004ad6c0(){
    auto* const object=reinterpret_cast<B*>(audio_resource_query_root_00656ab4);
    if(object==nullptr)return 0;
    if(cell(object,0x88)==0)return 0;
    if(cell(object,0x8c)==0)return 0;
    return cell(object,0xa4);
}
}
// Existing callers declare signed 32-bit returns; the ABI and all EAX bits agree.
// These aliases provide the exact old frontier names without another algorithm.
#pragma comment(linker,"/alternatename:?splash_progress_resource_begin_004ad670@porsche@@YAHXZ=?splash_progress_resource_begin_004ad670@porsche@@YAIXZ")
#pragma comment(linker,"/alternatename:?splash_progress_resource_end_004ad6c0@porsche@@YAHXZ=?splash_progress_resource_end_004ad6c0@porsche@@YAIXZ")
