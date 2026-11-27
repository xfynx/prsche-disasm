// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#include "world_list_reset_870.hpp"
#include "porsche/application_alloc.hpp"
#include <cstring>
namespace porsche {
std::uint32_t session_world_list_00628b74 = 0;
namespace {
std::uint32_t read(const void* p) { std::uint32_t v; std::memcpy(&v,p,4); return v; }
}
void __cdecl session_world_list_reset_00479dd0() {
    auto* world = reinterpret_cast<unsigned char*>(session_world_list_00628b74);
    std::uint32_t index = 0, offset = 0;
    if (read(world + 0x18) == 0) return;
    do {
        auto* row = reinterpret_cast<unsigned char*>(read(world + 0x30)) + offset;
        auto* list = reinterpret_cast<unsigned char*>(read(row + 0x38));
        if (list) {
            const auto count = read(list - 4);
            // DEC/JS uses the sign of count-1, including wraparound at INT_MIN.
            if (((count - 1) & 0x80000000u) == 0) {
                auto* cursor = list + count * 0x14;
                for (auto remaining = count; remaining != 0; --remaining) {
                    cursor -= 0x14;
                    application_release_0059f050(reinterpret_cast<void*>(read(cursor + 8)));
                    application_release_0059f050(reinterpret_cast<void*>(read(cursor + 4)));
                }
            }
            application_release_0059f050(list - 4);
        }
        const auto value = read(row + 0x34);
        std::uint32_t zero=0; std::memcpy(row+0x38,&zero,4);
        session_world_row_reset_00478d90(row,nullptr,row,row+0xc,row+0x18,value);
        ++index; offset += 0x50;
    } while (index < read(world + 0x18));
}
}
