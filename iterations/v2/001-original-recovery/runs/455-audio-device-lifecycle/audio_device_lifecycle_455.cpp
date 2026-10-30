// Porsche.exe SHA256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original five bodies, 448B. Start includes its discontiguous0058f560 tail.
#include "audio_device_lifecycle_455.hpp"
#include <cstring>
#pragma comment(linker,"/alternatename:?audio_device_exit_callback_00565890@porsche@@YAXXZ=?application_audio_probe_measure_00565890@porsche@@YAHXZ")
namespace porsche {
volatile std::uint8_t audio_thread_running_006b4880=0;
volatile std::uint8_t audio_thread_requested_006b4881=0;
std::uint8_t audio_device_exit_registered_006b4882=0;
AudioDeviceBufferStorage455 audio_device_buffers_006b4888{};
std::uint32_t (&audio_device_raw_buffers_006b4888)[2]=audio_device_buffers_006b4888.raw;
std::uint32_t (&audio_device_aligned_buffers_006b4890)[2]=audio_device_buffers_006b4888.aligned;
std::uint32_t audio_device_callback_006b4898=0;
void __cdecl audio_thread_start_0058e4a0() {
    audio_thread_running_006b4880=1;
    audio_thread_requested_006b4881=1;
    std::uint32_t thread_id; // CreateThread failure leaves this local opaque.
    void* handle=platform_create_thread(nullptr,0,audio_thread_worker_0058f880,nullptr,0,&thread_id);
    (void)platform_thread_priority(handle,15);
}
void __cdecl audio_thread_wait_0058e4d0() {
    const auto running=audio_thread_running_006b4880;
    audio_thread_requested_006b4881=0;
    if(running!=0) {
        do { audio_platform_sleep_455(0); } while(audio_thread_running_006b4880!=0);
    }
}
std::int32_t __cdecl audio_device_stop_lower_0058f5a0() {
    audio_thread_wait_0058e4d0();
    (void)audio_device_release_ds_0058f1f0();
    return 0;
}
std::int32_t __cdecl application_audio_backend_start_device_0058fdb0() {
    const std::uint16_t count=0x100;
    std::memcpy(&audio_resource_map_count_006b48a0,&count,2);
    const auto descriptors=application_audio_device_state_006b48c0[0x27];
    for(std::uint32_t index=0;index<descriptors;++index) {
        if((application_audio_device_state_006b48c0[0x28+index]&1u)!=0) {
            audio_resource_map_006b48a4=application_audio_backend_allocate_0058aae0(0x800);
            break;
        }
        audio_resource_map_006b48a4=0;
    }
    const auto bytes=static_cast<std::uint32_t>(static_cast<std::int32_t>(audio_backend_channel_count_006b49a4))*248u;
    audio_backend_voice_table_006b489c=application_audio_backend_allocate_0058aae0(bytes);
    // Reload count after allocation, as the original does.
    const auto zero_bytes=static_cast<std::uint32_t>(static_cast<std::int32_t>(audio_backend_channel_count_006b49a4))*248u;
    application_audio_backend_configure_0058fef0(audio_backend_voice_table_006b489c,zero_bytes);
    if(audio_backend_flag_summary_006b4884!=0) {
        for(std::uint32_t index=0;index<2;++index) {
            const auto address=application_audio_backend_allocate_0058aae0(0x2020);
            audio_device_raw_buffers_006b4888[index]=address;
            auto aligned=address+8u;
            audio_device_aligned_buffers_006b4890[index]=aligned;
            while((aligned&15u)!=0) {
                aligned=audio_device_aligned_buffers_006b4890[index]+4u;
                audio_device_aligned_buffers_006b4890[index]=aligned;
            }
        }
    }
    if(audio_device_exit_registered_006b4882==0) {
        (void)exit_registry_register_005a2400(audio_device_exit_callback_00565890);
        audio_device_exit_registered_006b4882=1;
    }
    const auto result=audio_device_initialize_ds_0058ebe0();
    if(result>=0) audio_thread_start_0058e4a0();
    return result;
}
void __cdecl application_audio_backend_stop_device_0058fe80() {
    const auto callback=audio_device_callback_006b4898;
    if(callback!=0) reinterpret_cast<void(__cdecl*)(std::uint32_t,std::uint32_t)>(callback)(0xa0,0);
    (void)audio_device_stop_lower_0058f5a0();
    (void)audio_backend_pool_release_0058ac30(audio_backend_voice_table_006b489c);
    const auto map=audio_resource_map_006b48a4;
    if(map!=0) (void)audio_backend_pool_release_0058ac30(map);
    if(audio_backend_flag_summary_006b4884!=0) {
        for(std::uint32_t index=0;index<2;++index) {
            const auto address=audio_device_raw_buffers_006b4888[index];
            if(address!=0) (void)audio_backend_pool_release_0058ac30(address);
        }
    }
}
}
