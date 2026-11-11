#include <cstdint>
#include <cstring>
namespace porsche {
void __cdecl audio_service_split_004ad950(std::uint8_t* object) {
    std::uint32_t address;
    std::memcpy(&address, object, 4);
    auto* input = reinterpret_cast<std::uint8_t*>(address);
    std::uint32_t zero=0;
    std::memcpy(object+8,&zero,4);
    std::memcpy(object+12,&zero,4);
    std::memcpy(object+16,&zero,4);
    std::memcpy(object+20,&zero,4);
    std::uint32_t length=0, dash=0;
    std::uint8_t c=*input;
    while(c) {
        if(c==45) {
            if(dash) { ++input; address=reinterpret_cast<std::uint32_t>(input); std::memcpy(object+8,&address,4); break; }
            dash=1; length=0;
        } else if(length<31) { object[0x20+length]=c; ++length; }
        ++input; c=*input;
    }
    object[0x20+length]=0;
    address=reinterpret_cast<std::uint32_t>(object+0x20);
    std::memcpy(object+4,&address,4);
}
}
