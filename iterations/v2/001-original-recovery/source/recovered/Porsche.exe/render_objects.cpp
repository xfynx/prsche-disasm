#include "porsche/render_objects.hpp"
#include <cstring>
#include <new>

namespace porsche {
namespace {
constexpr std::uint32_t original_core_vtable=0x005b3fbc;
struct NativeCore final : RenderCore {
    std::uint8_t remaining[0x114];
    void __thiscall first_00() override {render_core_first_004b76f0(this);}
};
static_assert(sizeof(NativeCore)==0x118);
void write32(void* base,std::size_t offset,std::uint32_t value) {
    std::memcpy(static_cast<std::uint8_t*>(base)+offset,&value,4);
}
}

void* __cdecl render_construct_core_raw_00467700(void* object,
    const char* publisher,const char* title) {
    // 0x467700..0x46771f: EAX=ECX on return, RET 8.
    write32(object,4,static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(publisher)));
    write32(object,12,static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(title)));
    static_cast<std::uint8_t*>(object)[0x110]=0;
    write32(object,0,original_core_vtable);
    return object;
}

RenderCore* __cdecl render_construct_core_00467700(void* object,
    const char* publisher,const char* title) {
    render_construct_core_raw_00467700(object,publisher,title);
    // Native MSVC virtual dispatch requires a native vptr. This bridge changes
    // only +0 and has no claim of matching the original pointer bytes.
    return new (object) NativeCore;
}

void __cdecl render_display_prefix_004677e0(RenderDisplay* object,
    const char*,std::uint32_t,std::uint32_t flags,const char*) {
    auto* bytes=object->bytes;
    write32(bytes,0,0);                         // 0x4677f1
    write32(bytes,4,0x3e19999a);                // 0x4677f5
    write32(bytes,8,0x442f0000);                // 0x4677fc
    write32(bytes,0x10,0);                      // 0x467803
    render_display_member_00466380(bytes+0x14);// 0x467806
    render_display_member_00466380(bytes+0x34);// 0x46780e
    write32(bytes,0x54,static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(bytes+0x14)));
    write32(bytes,0x58,render_clock_00555bc0());
    write32(bytes,0x5c,0);
    bytes[0x60]=static_cast<std::uint8_t>(flags);
    write32(bytes,0x64,0);
    write32(bytes,0x68,1);
    write32(bytes,0x6c,0);
    write32(bytes,0x70,0);
    write32(bytes,0x74,0);
    render_display_00628130=object;             // 0x46783e
    render_clock_00555bc0();                    // 0x467844
    render_display_clock_005deb1c=0;           // 0x467849
}
}
