// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Complete originals00597010..00597062(83B),00589c00..00589d14(277B).
#include "voice_cleanup_439.hpp"
#include <cstring>

namespace porsche {
namespace {
template<class T> T load(std::uint32_t address) {
    T value;
    std::memcpy(&value,reinterpret_cast<const void*>(address),sizeof(value));
    return value;
}
template<class T> void store(std::uint32_t address,T value) {
    std::memcpy(reinterpret_cast<void*>(address),&value,sizeof(value));
}
std::uint32_t retirement_time() {
    std::uint32_t value;
    std::memcpy(&value,application_audio_device_state_006b48c0.data()+0xe8,4);
    return value;
}
void retire(std::uint32_t channel) {
    store<std::uint8_t>(channel+0x0fu,0);
    store<std::uint8_t>(channel+0x1eu,0);
    // The load follows both byte stores. Channel storage can alias this owner.
    const auto time=retirement_time();
    store<std::uint32_t>(channel+0x20u,time);
}
} // namespace

void __cdecl audio_backend_voice_release_00597010(void* voice_data) {
    const std::uint32_t table=audio_backend_voice_table_006b489c;
    const auto index=load<std::int16_t>(reinterpret_cast<std::uint32_t>(voice_data)+2u);
    const std::uint32_t voice=table+static_cast<std::uint32_t>(index)*0xf8u;
    if(load<std::uint32_t>(voice+0xc4u)==0) return;
    do {
        const auto node=load<std::uint32_t>(voice+0xc4u);
        const auto next=load<std::uint32_t>(node);
        if(node!=voice+0x2cu && node!=voice+0x64u)
            (void)audio_backend_pool_release_0058ac30(node);
        store<std::uint32_t>(voice+0xc4u,next);
    } while(load<std::uint32_t>(voice+0xc4u)!=0);
}

void __cdecl audio_backend_voice_finalize_00589c00(std::uint32_t voice_slot) {
    const std::uint32_t channel=audio_backend_channels_006b4a00+voice_slot*0x70u;
    const std::uint32_t group=load<std::uint8_t>(channel+0x1eu);
    if(group==0) { retire(channel); return; }
    std::int32_t matches=0;
    std::uint32_t flagged_slot=0xffffffffu;
    const auto count=audio_backend_channel_count_006b49a4;
    if(count>0) {
        std::uint32_t record=audio_backend_channels_006b4a00;
        for(std::int32_t slot=0;slot<count;++slot,record+=0x70u) {
            if(load<std::uint8_t>(record+0x1eu)==group &&
               load<std::int32_t>(record)>=0 && load<std::uint8_t>(record+0x0fu)!=0) {
                ++matches;
                if(load<std::uint8_t>(record+0x1bu)!=0)
                    flagged_slot=static_cast<std::uint32_t>(slot);
            }
        }
    }
    if(matches==1) { retire(channel); return; }
    // Sentinel -1 intentionally addresses the preceding record; the original
    // reads its active byte even when count<=0 or no flagged match exists.
    const auto other=audio_backend_channels_006b4a00+flagged_slot*0x70u;
    const auto active=load<std::uint8_t>(other+0x0fu);
    if(active==2 && voice_slot!=flagged_slot && matches==2) {
        retire(channel);
        retire(other);
    } else if(active==1 && voice_slot==flagged_slot) {
        store<std::uint8_t>(other+0x0fu,2);
    } else {
        retire(channel);
    }
}
} // namespace porsche
