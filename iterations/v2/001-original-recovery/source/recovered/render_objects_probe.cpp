#include "porsche/render_objects.hpp"
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

namespace {
std::string calls;
std::uint32_t clocks[2],clock_index;
void event(const char* name) {if (!calls.empty()) calls+=',';calls+=name;}
void put32(void* buffer,std::size_t offset,std::uint32_t value) {
    std::memcpy(static_cast<unsigned char*>(buffer)+offset,&value,4);
}
std::string hex(const void* buffer,std::size_t size) {
    constexpr char digits[]="0123456789abcdef";
    std::string result;result.reserve(size*2);
    const auto* bytes=static_cast<const unsigned char*>(buffer);
    for(std::size_t i=0;i<size;++i){result+=digits[bytes[i]>>4];result+=digits[bytes[i]&15];}
    return result;
}
}
namespace porsche {
RenderDisplay* render_display_00628130;
std::uint32_t render_display_clock_005deb1c;
void __cdecl render_core_first_004b76f0(RenderCore*) {event("first");}
void __cdecl render_display_member_00466380(void* member) {
    event(clock_index==0?"member14":"member34");
    std::memset(member,clock_index==0?0xa1:0xb2,0x20);
    ++clock_index;
}
std::uint32_t __cdecl render_clock_00555bc0() {
    event("clock");return clocks[(clock_index++)-2];
}
}
int main() {
    using namespace porsche;
    const char publisher[]="Electronic Arts",title[]="Need for Speed - Porsche Unleashed";
    std::uint32_t flags,first,second;unsigned seed;
    while(std::cin>>std::hex>>seed>>flags>>first>>second) {
        alignas(4) unsigned char raw[0x118],adapted[0x118];
        RenderDisplay display{};
        std::memset(raw,static_cast<int>(seed&255),sizeof(raw));
        std::memset(adapted,static_cast<int>(seed&255),sizeof(adapted));
        std::memset(display.bytes,static_cast<int>(seed&255),sizeof(display.bytes));
        clocks[0]=first;clocks[1]=second;clock_index=0;calls.clear();
        const auto* raw_return=render_construct_core_raw_00467700(raw,publisher,title);
        auto* native=render_construct_core_00467700(adapted,publisher,title);
        native->first_00();
        render_display_00628130=nullptr;render_display_clock_005deb1c=0xabcdef01;
        render_display_prefix_004677e0(&display,"name",7,flags,"800x600");
        // Canonicalize only process-local pointers; all other bytes remain literal.
        put32(raw,4,0x03200000);put32(raw,12,0x03200100);
        put32(adapted,0,0x005b3fbc);put32(adapted,4,0x03200000);put32(adapted,12,0x03200100);
        put32(display.bytes,0x54,0x03101014);
        std::cout<<"{\"core\":\""<<hex(raw,sizeof(raw))<<"\",\"adapter\":\""
                 <<hex(adapted,sizeof(adapted))<<"\",\"display\":\""
                 <<hex(display.bytes,sizeof(display.bytes))<<"\",\"raw_return\":"
                 <<(raw_return==raw)<<",\"adapter_return\":"<<(native==reinterpret_cast<RenderCore*>(adapted))
                 <<",\"global_display\":"<<(render_display_00628130==&display)
                 <<",\"global_clock\":"<<render_display_clock_005deb1c
                 <<",\"calls\":\""<<calls<<"\"}\n";
    }
}
