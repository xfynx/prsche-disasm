// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 0048ff30..00490139, 522 bytes, sha256 83cecaa49d7aba951ea94886c3d3f5148acfa5324ca00cefcb268aa8dc6f6c85.
#include "shutdown_network_destroy_619.hpp"

namespace porsche {
namespace {

void clear_list_slot(void* self, std::uint32_t offset) {
    auto** const head_slot = reinterpret_cast<std::uint32_t**>(
        reinterpret_cast<std::uint8_t*>(self) + offset);
    std::uint32_t* head = *head_slot;
    std::uint32_t* edi = reinterpret_cast<std::uint32_t*>(
        static_cast<std::uintptr_t>(head[0]));
    if (edi != head) {
        do {
            std::uint32_t* const node = edi;
            edi = reinterpret_cast<std::uint32_t*>(
                static_cast<std::uintptr_t>(edi[0]));
            application_context_clear_004237d0(node, 0xcu, 0u);
            head = *head_slot;
        } while (edi != head);
    }
    std::uint32_t* const s0 = *head_slot;
    s0[0] = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(s0));
    std::uint32_t* const s1 = *head_slot;
    s1[1] = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(s1));
    std::uint32_t* const s2 = *head_slot;
    application_context_clear_004237d0(s2, 0xcu, 0u);
}

} // namespace

void __thiscall ShutdownNetwork311::destroy_0048ff30() {
    if (startup_network_00628c70 != nullptr) {
        missing_file_006afbe4 = nullptr;
        (void)network_lifecycle_reset_0048e9c0(this, nullptr);
        std::uint32_t* const lock_box = *reinterpret_cast<std::uint32_t* const*>(
            reinterpret_cast<const std::uint8_t*>(this) + 0x10u);
        if (lock_box != nullptr) {
            heap_lock_destroy_005322d0(
                reinterpret_cast<void*>(static_cast<std::uintptr_t>(lock_box[0])));
            (void)application_release_0059f050(lock_box);
        }
        (void)application_release_0059f050(*reinterpret_cast<void* const*>(
            reinterpret_cast<const std::uint8_t*>(this) + 0x18u));
        network_callbacks_drain_005603b0();
    }
    clear_list_slot(this, 0x264u);
    clear_list_slot(this, 0x260u);
    clear_list_slot(this, 0x25cu);
    clear_list_slot(this, 0x258u);
    clear_list_slot(this, 0x254u);
    clear_list_slot(this, 0x150u);
}

} // namespace porsche
