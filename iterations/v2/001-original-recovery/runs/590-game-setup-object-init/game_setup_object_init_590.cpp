// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 00403520..004035d7, 184 bytes (__fastcall ECX=object, stack bytes, RET 4).
#include "game_setup_object_init_590.hpp"
#include <cstring>

namespace {
using U = std::uint32_t;
static_assert(sizeof(void*) == 4, "x86 pointer width required");

U load32(const void* base, U offset) {
    U value;
    std::memcpy(&value, static_cast<const std::uint8_t*>(base) + offset, sizeof value);
    return value;
}

void store32(void* base, U offset, U value) {
    std::memcpy(static_cast<std::uint8_t*>(base) + offset, &value, sizeof value);
}

void* from32(U address) {
    return reinterpret_cast<void*>(static_cast<std::uintptr_t>(address));
}

U to32(const void* pointer) {
    return static_cast<U>(reinterpret_cast<std::uintptr_t>(pointer));
}
} // namespace

namespace porsche {
void __fastcall game_setup_object_init_raw_00403520(
    void* object, void* unused_edx, std::uint32_t bytes) {
    (void)unused_edx;
    if (bytes > 0xfffffffeu) {
        return;
    }
    if (bytes == 0u) {
        store32(object, 0u, 0u);
        store32(object, 4u, 0u);
        store32(object, 8u, 0u);
        return;
    }

    void* const state = from32(to32(application_context_heap_state_005e4fe8()) + 0x28u);
    if (bytes > 0x100u) {
        const U heap = application_context_heap_selector_005e4fec();
        const U block = to32(application_context_member_block_0059ecb0(
            bytes, heap, 0x005cbdb4u));
        store32(object, 0u, block);
        store32(object, 4u, block);
        store32(object, 8u, block + bytes);
        return;
    }

    heap_enter_005322b0(from32(load32(state, 0u)));
    const U kind = (bytes - 1u) >> 3u;
    const U offset = kind * 4u + 0xcu;
    if (load32(state, offset) == 0u) {
        application_context_new_head_0059eeb0(kind, 0u);
    }
    const U block = load32(state, offset);
    store32(state, offset, load32(from32(block), 4u));
    heap_leave_005322c0(from32(load32(state, 0u)));
    store32(object, 0u, block);
    store32(object, 4u, block);
    store32(object, 8u, block + bytes);
}

void __cdecl game_setup_object_init_00403520(void* object, std::uint32_t bytes) {
    game_setup_object_init_raw_00403520(object, nullptr, bytes);
}
} // namespace porsche
