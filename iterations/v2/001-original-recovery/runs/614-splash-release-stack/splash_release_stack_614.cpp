// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 0048d550..0048d691, 322 bytes, sha256 8f8080be41157bdfca4d2fc4acd538761b8e2178617eef084a3d16d4128ad02d.
#include "splash_release_stack_614.hpp"

namespace porsche {

void __cdecl splash_progress_release_stack_0048d550(void* stack) {
    auto* net = static_cast<std::uint8_t*>(startup_network_00628c70);
    if (net == nullptr) {
        return;
    }
    if (*reinterpret_cast<void* const*>(net + 0x08u) == nullptr) {
        return;
    }
    if (net[0xbfu] != 0u) {
        return;
    }
    auto* cur = static_cast<const std::uint32_t*>(stack);
    if (*cur == 0u) {
        return;
    }
    using TransportSendSlot0_614 = void (__fastcall *)(void* self, void* edx, std::uint32_t zero, const void* data, std::uint32_t bytes);
    for (;;) {
        if (net != nullptr) {
            void* const transport = *reinterpret_cast<void* const*>(net + 0x08u);
            if (transport != nullptr && net[0xbfu] == 0u) {
                const std::uint32_t byte_len = static_cast<std::uint32_t>(fe_record_words_004b4cd0(cur)) << 2u;
                net = static_cast<std::uint8_t*>(startup_network_00628c70);
                const std::int32_t used = *reinterpret_cast<const std::int32_t*>(net + 0x250u);
                if (static_cast<std::int32_t>(used + byte_len) > 0xf0) {
                    if (net != nullptr) {
                        void* const t2 = *reinterpret_cast<void* const*>(net + 0x08u);
                        if (t2 != nullptr && net[0xbfu] == 0u && used > 4) {
                            const auto* const vtbl = *reinterpret_cast<const TransportSendSlot0_614* const*>(t2);
                            vtbl[0](t2, nullptr, 0u, net + 0x160u, static_cast<std::uint32_t>(used));
                            auto* const net_after_send = static_cast<std::uint8_t*>(startup_network_00628c70);
                            *reinterpret_cast<std::uint32_t*>(net_after_send + 0x250u) = 4u;
                            net = static_cast<std::uint8_t*>(startup_network_00628c70);
                        }
                    }
                }
                const std::uint32_t off = *reinterpret_cast<const std::uint32_t*>(net + 0x250u);
                heap_copy_dispatch_005323e0(net + 0x160u + off, cur, byte_len);
                net = static_cast<std::uint8_t*>(startup_network_00628c70);
                *reinterpret_cast<std::uint32_t*>(net + 0x250u) += byte_len;
                net = static_cast<std::uint8_t*>(startup_network_00628c70);
            }
            if (net != nullptr) {
                void* const t3 = *reinterpret_cast<void* const*>(net + 0x08u);
                if (t3 != nullptr && net[0xbfu] == 0u) {
                    const std::int32_t used2 = *reinterpret_cast<const std::int32_t*>(net + 0x250u);
                    if (used2 > 4) {
                        const auto* const vtbl = *reinterpret_cast<const TransportSendSlot0_614* const*>(t3);
                        vtbl[0](t3, nullptr, 0u, net + 0x160u, static_cast<std::uint32_t>(used2));
                        net = static_cast<std::uint8_t*>(startup_network_00628c70);
                        *reinterpret_cast<std::uint32_t*>(net + 0x250u) = 4u;
                    }
                }
            }
        }
        const std::int32_t words = fe_record_words_004b4cd0(cur);
        cur += words;
        if (*cur == 0u) {
            break;
        }
        net = static_cast<std::uint8_t*>(startup_network_00628c70);
    }
}

} // namespace porsche
