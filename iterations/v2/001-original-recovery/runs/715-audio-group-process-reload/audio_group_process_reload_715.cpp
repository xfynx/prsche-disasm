// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 00599610..005996c5 (182 bytes); body SHA-256 and relocation offsets
// are pinned in native-config.json / scope-evidence.json.
#include "audio_group_process_reload_715.hpp"

#include <cstring>

namespace porsche {
namespace {

inline std::uint32_t read_u32(const std::uint8_t* p) noexcept {
    std::uint32_t v = 0u;
    std::memcpy(&v, p, 4u);
    return v;
}

inline std::uint16_t read_u16(const std::uint8_t* p) noexcept {
    std::uint16_t v = 0u;
    std::memcpy(&v, p, 2u);
    return v;
}

inline void write_u32(std::uint8_t* p, std::uint32_t v) noexcept {
    std::memcpy(p, &v, 4u);
}

} // namespace

// Original 00599610. The signed byte at record[3] builds a table of
// ctx+offset pointers from the DWORDs at record+0x68. The first worker call
// receives the address of the incoming argument slot, zeroed once; the loop
// re-calls it until it returns zero. When the worker's low bit is set and
// record[3] is exactly one, the slot key at record+0xa0 feeds the allocator,
// six scalar record fields feed the configure call, and the result is stored
// at allocator_result+4; a zero result erases the key. The original returns
// a constant 8 and never reads the third argument.
std::int32_t __cdecl audio_group_process_reload_00599610(void* record,
                                                          const void* ctx,
                                                          void* scratch) {
    (void)scratch;
    std::uint8_t* const r = static_cast<std::uint8_t*>(record);
    const std::uint8_t* const ctx_bytes = static_cast<const std::uint8_t*>(ctx);

    alignas(4) std::uint32_t pointers[8u];
    std::int32_t remaining = static_cast<std::int32_t>(static_cast<std::int8_t>(r[3u]));
    if (remaining > 0) {
        std::uint32_t* q = pointers;
        const std::uint8_t* p = r + 0x68u;
        do {
            const std::uint32_t offset = read_u32(p);
            *q = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(ctx_bytes) + offset);
            p += 4u;
            ++q;
            --remaining;
        } while (remaining != 0);
    }

    std::uint32_t out_slot;
    out_slot = 0u;
    std::uint32_t step = audio_group_step_0058a970(&out_slot, record);
    if (step == 0u) {
        return 8;
    }
    const std::uint32_t pointer0 = pointers[0u];
    for (;;) {
        if ((step & 1u) != 0u && r[3u] == 1u) {
            const std::uint32_t key = read_u32(r + 0xa0u);
            void* const slot = audio_group_slot_0058f7a0(key);
            const std::uint32_t at58 = read_u32(r + 0x58u);
            const std::uint32_t at5c = read_u32(r + 0x5cu);
            const std::uint32_t at60 = read_u32(r + 0x60u);
            const std::uint32_t word56 = static_cast<std::uint32_t>(read_u16(r + 0x56u));
            const std::uint32_t byte13 = static_cast<std::uint32_t>(r[0x13u]);
            const std::uint32_t configured = audio_group_configure_0058f220(
                byte13, word56, at58, at5c, at60, pointer0);
            write_u32(static_cast<std::uint8_t*>(slot) + 4u, configured);
            if (configured == 0u) {
                audio_resource_erase_0058f7e0(key);
            }
        }
        step = audio_group_step_0058a970(&out_slot, record);
        if (step == 0u) {
            break;
        }
    }
    return 8;
}

} // namespace porsche
