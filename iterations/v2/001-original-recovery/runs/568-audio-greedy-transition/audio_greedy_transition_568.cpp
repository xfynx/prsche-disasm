// Porsche.exe SHA256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// 0056b540/110B and 005681b0/68B; original-address metadata is not a host pointer.
#include "audio_greedy_transition_568.hpp"
#include "../565-audio-stream-codec-lifecycle/audio_codec_access_565.hpp"
#include "porsche/files.hpp"
#include "porsche/shared_runtime_globals.hpp"
#include <cstring>
#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Original x86 ABI and address wrapping required
#endif
namespace porsche {
namespace {
using U=std::uint32_t;
U word(U p){U v;std::memcpy(&v,reinterpret_cast<const void*>(p),4);return v;}
void put(U p,U v){std::memcpy(reinterpret_cast<void*>(p),&v,4);}
const char invalid_message[]="STREAM_setgreedystate - invalid stream handle\n";
}
void __cdecl file_operation_set_group_005681b0(U id,U group){
    const U base=static_cast<U>(reinterpret_cast<std::uintptr_t>(devices_006a5c7c));
    const U device=base+(id&31u)*0x70u;
    if(device==0)return;
    auto* list=reinterpret_cast<IoList*>(device+0x24u);
    auto* node=io_take_00580c10(list,operation_matches_00567bf0,id);
    if(node){
        reinterpret_cast<FileOperation*>(node)->group=static_cast<std::uint8_t>(group);
        (void)operation_queue_00568200(reinterpret_cast<FileOperation*>(node));
    }
}
void __cdecl audio_stream_greedy_transition_0056b540(U handle,U state){
    U object,original;
    if(audio_stream_handle_validate_0056b380(handle,&object,&original)){
        class_error_file_005deb74=0x005bd978;class_error_line_005deb78=0x550;
        diagnostic_handler_005debf0(invalid_message);return;
    }
    put(object+0x38,state);
    if(state&&word(object+0x28)==1)
        file_operation_set_group_005681b0(word(object+0x168),word(object+0x30));
}
}
