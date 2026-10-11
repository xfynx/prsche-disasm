// Private Run 135 evidence only. Do not add to the common original library:
// 00525ec0's null-allocation EAX contract is not recovered.
#include "porsche/application_context_base.hpp"
#include "porsche/application_alloc.hpp"

#include <cstddef>
#include <cstdint>
#include <cstring>

namespace porsche {
namespace {
std::uint32_t load32(const void* object, std::size_t offset = 0) noexcept {
    std::uint32_t value;
    std::memcpy(&value, static_cast<const std::uint8_t*>(object) + offset, 4);
    return value;
}
void store32(void* object, std::size_t offset, std::uint32_t value) noexcept {
    std::memcpy(static_cast<std::uint8_t*>(object) + offset, &value, 4);
}
void* from32(std::uint32_t value) noexcept {
    return reinterpret_cast<void*>(static_cast<std::uintptr_t>(value));
}
std::uint32_t to32(const void* value) noexcept {
    return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(value));
}
}

std::uint32_t __fastcall application_context_base_destroy_00525ec0(
    ApplicationSetupContext* context, void* unused_edx) {
    (void)unused_edx;
    auto* const object = static_cast<void*>(context->bytes);
    auto* const allocation = from32(load32(object, 4));
    store32(object, 0, 0x005bb028u);
    // Partial: original preserves arbitrary incoming EAX here. This private
    // C++ fixture normalizes it to zero and claims no null-path return parity.
    if (!allocation) return 0;

    if (load32(allocation, 4) != 0) {
        auto* node = from32(load32(from32(load32(allocation, 0)), 4));
        while (node) {
            application_context_unlink_005262e0(
                allocation, nullptr, load32(node, 0x0c));
            const auto next = load32(node, 8);
            application_context_release_node_004e4560(
                static_cast<std::uint8_t*>(node) + 0x10, nullptr, 0);
            application_context_notify_node_004d7da0(node, 1);
            node = from32(next);
        }

        auto* sentinel = from32(load32(allocation, 0));
        store32(sentinel, 8, to32(sentinel));
        sentinel = from32(load32(allocation, 0));
        store32(sentinel, 4, 0);
        sentinel = from32(load32(allocation, 0));
        store32(sentinel, 0x0c, to32(sentinel));
        store32(allocation, 4, 0);
    }

    auto* const sentinel = from32(load32(allocation, 0));
    application_context_clear_004237d0(sentinel, 0x20, 0);
    return application_release_0059f050(allocation);
}
} // namespace porsche
