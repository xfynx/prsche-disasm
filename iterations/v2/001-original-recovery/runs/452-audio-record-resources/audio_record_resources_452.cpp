// Porsche.exe SHA256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Complete originals005996d0(55B),0058f820(57B),0058f7e0(55B),0058f290(43B).
#include "audio_record_resources_452.hpp"
#include <cstring>
namespace porsche {
std::uint32_t audio_resource_map_count_006b48a0=0;
std::uint32_t audio_resource_map_006b48a4=0;
alignas(4) std::uint8_t audio_resource_slots_006ad7b8[0x1800]={};
namespace {
using U=std::uint32_t;
U read(U at){U value;std::memcpy(&value,reinterpret_cast<const void*>(at),4);return value;}
void write(U at,U value){std::memcpy(reinterpret_cast<void*>(at),&value,4);}
}
U __cdecl audio_resource_find_0058f820(U key){
    const U base=audio_resource_map_006b48a4;
    if(base==0)return 0;
    const U count=audio_resource_map_count_006b48a0&0xffffu;
    for(U index=0;index<count;++index){
        const U row=base+index*8u;
        if(read(row)==key)return row;
    }
    return 0;
}
U __cdecl audio_resource_erase_0058f7e0(U key){
    const U count=audio_resource_map_count_006b48a0&0xffffu;
    const U base=audio_resource_map_006b48a4;
    U index=0;
    for(;index<count;++index){
        if(read(base+index*8u)==key){write(base+index*8u,0);break;}
    }
    return index;
}
std::int32_t __cdecl audio_resource_release_slot_0058f290(U slot){
    const U row=reinterpret_cast<U>(audio_resource_slots_006ad7b8)+slot*24u;
    if(audio_ds_device_006ad760!=0){
        const U object=read(row+4);
        using Release=U(__stdcall*)(U);
        reinterpret_cast<Release>(read(read(object)+8))(object);
    }
    write(row,0);
    return 0;
}
std::int32_t __cdecl audio_record_remove_005996d0(void* record){
    const U key=read(reinterpret_cast<U>(record)+0xa0u);
    const U row=audio_resource_find_0058f820(key);
    if(row!=0){
        const U handle=read(row+4);
        if(handle!=0){
            audio_resource_erase_0058f7e0(key);
            return audio_resource_release_slot_0058f290(handle);
        }
    }
    return 0;
}
void __cdecl audio_group_process_005996d0(void* record,U*){
    static_cast<void>(audio_record_remove_005996d0(record));
}
}
