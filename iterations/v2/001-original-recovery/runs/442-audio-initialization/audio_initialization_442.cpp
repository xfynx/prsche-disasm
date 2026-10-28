// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Complete0058a4f0..0058a68a(411B),0058a690..0058a8a4(533B).
#include "audio_initialization_442.hpp"
#include <cstring>

namespace porsche {
std::uint8_t audio_backend_flag_summary_006b4883=0;
std::uint8_t audio_backend_flag_summary_006b4884=0;
std::uint8_t audio_backend_flag_summary_006b4885=0;
namespace {
std::uint8_t& byte(std::size_t offset) { return application_audio_device_state_006b48c0[offset]; }
std::uint16_t word(std::size_t offset) {
    std::uint16_t value;
    std::memcpy(&value,application_audio_device_state_006b48c0.data()+offset,2);
    return value;
}
void word(std::size_t offset,std::uint16_t value) {
    std::memcpy(application_audio_device_state_006b48c0.data()+offset,&value,2);
}
} // namespace

std::int32_t __cdecl application_audio_backend_initialize_0058a4f0() {
    std::uint32_t capacity_output;
    std::int32_t flag_output;
    const auto result=audio_probe_capabilities_0058e650(&capacity_output,&flag_output);
    if(result<0) return result;
    const auto capacity=static_cast<std::uint8_t>(capacity_output);
    const auto flag=static_cast<std::uint8_t>(flag_output);
    byte(0x09)=flag;
    byte(0x08)=capacity;
    byte(0x05)=capacity>4 ? 4 : 2;
    byte(0x23)=flag;
    byte(0x06)=0x80;
    word(0x00,0x2b11);
    word(0x02,0xbb80);
    byte(0x04)=1;
    byte(0x24)=0;
    byte(0x22)=1;
    byte(0x21)=10;
    byte(0x0a)=1;
    byte(0x0b)=0x24;
    if(capacity!=0) {
        byte(0x0a)=3;
        byte(0x0c)=0x91;
        byte(0x0d)=0x92;
    }
    byte(0x27)=1;
    byte(0x28)=0x24;
    byte(0x1d)=0x18;
    byte(0x1f)=0;
    word(0x1a,0x5622);
    byte(0x1c)=2;
    byte(0x25)=0;
    word(0x34,0);
    word(0x3c,0x4000);
    word(0x3e,0xc000);
    word(0x44,0x2aaa);
    word(0x46,0x8000);
    word(0x48,0xd555);
    word(0x4c,0x2000);
    word(0x4e,0x6000);
    word(0x50,0xa000);
    word(0x52,0xe000);
    word(0x54,0);
    word(0x5c,0x2000);
    word(0x5e,0xe000);
    word(0x64,0x2aaa);
    word(0x66,0x8000);
    word(0x68,0xd555);
    word(0x6c,0x1555);
    word(0x6e,0x6aaa);
    word(0x70,0x9555);
    word(0x72,0xeaaa);
    const auto features=audio_backend_cpu_features_00597070();
    byte(0xe3)=static_cast<std::uint8_t>(features);
    return 0;
}

void __cdecl application_audio_backend_apply_0058a690() {
    if(byte(0xdc)!=0) {
        for(std::size_t offset=0;offset<0x60;offset+=4) {
            std::uint32_t value;
            std::memcpy(&value,application_audio_device_state_006b48c0.data()+0x7c+offset,4);
            std::memcpy(application_audio_device_state_006b48c0.data()+0x14+offset,&value,4);
        }
        return;
    }
    audio_backend_flag_summary_006b4883=0;
    audio_backend_flag_summary_006b4884=0;
    audio_backend_flag_summary_006b4885=0;
    auto channels=byte(0x1c);
    if(channels<byte(0x04)) { channels=byte(0x04);byte(0x1c)=channels; }
    if(channels>byte(0x05)) { channels=byte(0x05);byte(0x1c)=channels; }
    const auto old_alternate=byte(0x24);
    if(old_alternate==0 && channels>2) byte(0x1c)=2;
    auto rate=word(0x1a);
    if(rate<word(0x00)) { rate=word(0x00);word(0x1a,rate); }
    if(rate>word(0x02)) word(0x1a,word(0x02));
    auto hardware=byte(0x1d);
    if(hardware>byte(0x06)) { hardware=byte(0x06);byte(0x1d)=hardware; }
    const auto capacity=byte(0x08);
    auto software=byte(0x1f);
    if(software>capacity) { software=capacity;byte(0x1f)=software; }
    if(byte(0x23)!=0 && byte(0x09)==0) byte(0x23)=0;
    if(old_alternate!=0 && capacity<=4) byte(0x24)=0;
    const auto total=static_cast<std::uint16_t>(hardware+software);
    word(0xe4,total);
    if(total>0x100u) {
        word(0xe4,0x100);
        byte(0x1f)=static_cast<std::uint8_t>(software-static_cast<std::uint8_t>(total));
    }
    std::uint32_t index=0;
    while(index<byte(0x27)) {
        if(byte(0x1f)==0 && (byte(0x28+index)&0x10u)!=0) byte(0x28+index)=0;
        const auto flags=byte(0x28+index);
        if((flags&0x10u)!=0) {
            audio_backend_flag_summary_006b4883=1;
            if((flags&1u)!=0) audio_backend_flag_summary_006b4885=1;
            else if((flags&2u)!=0) audio_backend_flag_summary_006b4884=1;
        }
        if(flags!=0) { ++index;continue; }
        byte(0x27)=static_cast<std::uint8_t>(byte(0x27)-1u);
        for(auto shift=index;shift<byte(0x27);++shift) byte(0x28+shift)=byte(0x29+shift);
        index=0;
    }
    if(audio_backend_flag_summary_006b4883==0) byte(0x1f)=0;
    if(byte(0x21)>200) byte(0x21)=200;
    else if(byte(0x21)<1) byte(0x21)=1;
    bool feature=false;
    if(byte(0x22)!=0) feature=(audio_backend_cpu_features_00597070()&2u)!=0;
    // Reload after callback: it can change the other bits of the canonical byte.
    if(feature) byte(0xe3)=static_cast<std::uint8_t>(byte(0xe3)|2u);
    else byte(0xe3)=static_cast<std::uint8_t>(byte(0xe3)&0xfdu);
}
} // namespace porsche
