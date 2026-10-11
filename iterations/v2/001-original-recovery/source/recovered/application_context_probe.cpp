#include "porsche/application_context.hpp"
#include "porsche/application_alloc.hpp"
#include "porsche/application_heap_init.hpp"

#include <cstdint>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

namespace porsche {
char application_object_heap_name_005e8e50[32]{};
namespace {
alignas(4) std::uint8_t member_storage[0x2c]{};
std::vector<std::string> calls;
bool allocate_member = true;
void event(const char* name) { calls.emplace_back(name); }
}
void* __cdecl startup_network_allocate_0059ef90(std::uint32_t bytes) {
    if (bytes != 0x2c) return nullptr;
    event("0059ef90");
    return allocate_member ? member_storage : nullptr;
}
std::uint32_t __cdecl application_release_0059f050(void* member) {
    event(member == member_storage ? "0059f050:member" : "0059f050:other");
    return 1;
}
ApplicationSetupContext* __fastcall application_context_base_construct_00525e20(ApplicationSetupContext* context,void*) { event("00525e20"); return context; }
void* __fastcall application_context_member_construct_005294c0(void* member,void*) { event("005294c0"); return member; }
void __fastcall application_context_member_destroy_005295b0(void*,void*) { event("005295b0"); }
std::uint32_t __fastcall application_context_base_destroy_00525ec0(ApplicationSetupContext*,void*) { event("00525ec0"); return 0xb16b00b5; }
} // namespace porsche

static std::string hex(const std::uint8_t* bytes, std::size_t size) {
    static constexpr char digits[] = "0123456789abcdef";
    std::string out(size * 2, '0');
    for (std::size_t i=0;i<size;++i) {
        out[2*i]=digits[bytes[i]>>4]; out[2*i+1]=digits[bytes[i]&15];
    }
    return out;
}

int main() {
    using namespace porsche;
    unsigned mode;
    while (std::cin >> mode) {
        calls.clear(); allocate_member = mode == 1 || mode == 2;
        std::memset(application_object_heap_name_005e8e50, 0,
            sizeof(application_object_heap_name_005e8e50));
        if (mode == 1) std::memcpy(application_object_heap_name_005e8e50,"A",2);
        if (mode == 2 || mode == 3) std::memcpy(application_object_heap_name_005e8e50,"0123456789abcdef",17);
        ApplicationSetupContext context;
        for (std::size_t i=0;i<sizeof(context.bytes);++i)
            context.bytes[i]=static_cast<std::uint8_t>((i*37+0x53)&0xff);
        const auto ctor_result=application_setup_context_construct_004d1a90(&context,nullptr);
        const auto after_ctor=hex(context.bytes,sizeof(context.bytes));
        const auto dtor_result=application_setup_context_destroy_004d1ba0(&context,nullptr);
        std::cout << "{\"after_ctor\":\"" << after_ctor
            << "\",\"after_dtor\":\"" << hex(context.bytes,sizeof(context.bytes))
            << "\",\"ctor_result_ok\":" << (ctor_result==&context?"true":"false")
            << ",\"dtor_eax_forwarded\":" << (dtor_result==0xb16b00b5?"true":"false")
            << ",\"calls\":[";
        for(std::size_t i=0;i<calls.size();++i)
            std::cout << (i?",":"") << "\"" << calls[i] << "\"";
        std::cout << "]}\n";
    }
}
