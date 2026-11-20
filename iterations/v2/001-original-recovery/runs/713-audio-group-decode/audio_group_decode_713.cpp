// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 00590a80..00590b4c (205 bytes). Body SHA-256 and relocations are
// pinned in native-config.json / scope-evidence.json.
#include "audio_group_decode_713.hpp"

#include "porsche/application_audio_device.hpp"

#include <cstring>

namespace porsche {
namespace {

inline std::uint32_t read_u32(const void* p) noexcept {
    std::uint32_t v = 0u;
    std::memcpy(&v, p, 4u);
    return v;
}

inline std::int8_t signed_byte(std::uint8_t v) noexcept {
    return static_cast<std::int8_t>(v);
}

} // namespace

// Original 00590a80. The source flag byte at source[3] selects a 4- or 8-byte
// header advance; that value replaces the first argument cell and is advanced
// in place by the canonical record decoder. A stack record and payload survive
// every child call; only the offsets named by the original x86 are interpreted.
// The final result is the return of the reload child (original MOV EAX,8), and
// the outer loop repeats while the decoder's "more" flag is non-zero.
std::int32_t __cdecl audio_group_decode_00590a80(const void* source,
                                                 const void* ctx,
                                                 void* scratch) {
    const std::uint8_t* const bytes = static_cast<const std::uint8_t*>(source);
    const std::uint32_t advance = (bytes[3u] & 0x2u) != 0u ? 8u : 4u;
    std::uint32_t cursor = static_cast<std::uint32_t>(
        reinterpret_cast<std::uintptr_t>(bytes) + advance);

    alignas(4) std::uint8_t record[0xa4u];
    alignas(4) std::uint32_t payload[3u];
    std::int32_t result = 0u;

    for (;;) {
        const std::int32_t more = audio_group_decode_00599100(&cursor, record);
        result = audio_group_process_reload_00599610(record, ctx, scratch);

        std::int8_t count = signed_byte(record[0x17u]);
        if (count > 0) {
            do {
                --count;
                const std::uint32_t slot =
                    static_cast<std::uint32_t>(static_cast<std::int32_t>(count)) * 4u;
                payload[0u] = 0u;
                payload[1u] = read_u32(record + 0x34u + slot);
                payload[2u] = read_u32(record + 0x44u + slot);

                std::int8_t callbacks = signed_byte(
                    application_audio_device_state_006b48c0[0xe2u]);
                if (callbacks > 0) {
                    std::int32_t index = 0;
                    do {
                        const std::uint32_t fn = read_u32(
                            application_audio_device_state_006b48c0.data() +
                            0x120u + static_cast<std::uint32_t>(index) * 4u);
                        reinterpret_cast<void (__cdecl*)(std::uint32_t*)>(fn)(
                            payload);
                        callbacks = signed_byte(
                            application_audio_device_state_006b48c0[0xe2u]);
                        ++index;
                    } while (index < callbacks);
                }
            } while (count > 0);
        }

        if (more == 0) {
            break;
        }
    }
    return result;
}

} // namespace porsche
