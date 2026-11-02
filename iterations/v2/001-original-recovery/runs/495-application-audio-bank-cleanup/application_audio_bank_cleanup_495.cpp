// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
// Complete004acb80..004acc0c /141B. Canonical478 bank cells and435 stop reused.
#include "application_audio_bank_cleanup_495.hpp"
#include "../478-audio-resource-controls/audio_resource_controls_478.hpp"
#include <cstring>
namespace porsche {
namespace {
using U=std::uint32_t;using B=std::uint8_t;
U read(const B* object,U offset){U value;std::memcpy(&value,object+offset,4);return value;}
void write(B* object,U offset,U value){std::memcpy(object+offset,&value,4);}
}
void __cdecl application_main_function_004acb80(){
    for(U root=0;root<2;++root){
        auto* const object=static_cast<B*>(audio_channel_banks_00656aa8[root]);
        if(!object)continue;
        const B previous=object[0x2d2];
        object[0x40]=0;
        object[0x2d3]=previous;
        write(object,0x38,0xffffffffu);
        write(object,0x3c,0xffffffffu);
        for(U index=0;index<32;++index){
            const U first=0x45c+index*12u,second=0x5dc+index*12u;
            if(read(object,first)!=0xffffffffu)audio_channel_stop_00565d60(read(object,first));
            if(read(object,second)!=0xffffffffu)audio_channel_stop_00565d60(read(object,second));
            write(object,0x44+index*4u,0);
            write(object,first,0xffffffffu);
            write(object,second,0xffffffffu);
        }
    }
}
}
