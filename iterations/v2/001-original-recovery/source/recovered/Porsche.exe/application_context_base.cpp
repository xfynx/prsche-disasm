#include "porsche/application_context_base.hpp"

#include "porsche/application_alloc.hpp"

#include <cstddef>
#include <cstdint>
#include <cstring>

namespace porsche {
namespace {
constexpr std::uint32_t kBaseVtable = 0x005bb028u;
constexpr std::uint32_t kMemberVtable = 0x005bb150u;

std::uint32_t load32(const void* object, std::size_t offset = 0) noexcept {
    std::uint32_t value;
    std::memcpy(&value, static_cast<const std::uint8_t*>(object) + offset,
        sizeof(value));
    return value;
}

void store32(void* object, std::size_t offset, std::uint32_t value) noexcept {
    std::memcpy(static_cast<std::uint8_t*>(object) + offset, &value,
        sizeof(value));
}

void store8(void* object, std::size_t offset, std::uint8_t value) noexcept {
    static_cast<std::uint8_t*>(object)[offset] = value;
}

void* from32(std::uint32_t value) noexcept {
    return reinterpret_cast<void*>(static_cast<std::uintptr_t>(value));
}

std::uint32_t to32(const void* value) noexcept {
    return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(value));
}

void finalize_ranges_005299f0(const void* first, const void* second) {
    std::uint32_t first_copy[4];
    std::uint32_t second_copy[4];
    ApplicationContextRange16 first_value{}, second_value{};
    application_context_copy_range_005299d0(first_copy, nullptr, first);
    application_context_copy_range_005299d0(second_copy, nullptr, second);
    // 005299f0 lays out its cdecl call as (second copy, first copy, zero).
    std::memcpy(first_value.words, second_copy, sizeof(second_copy));
    std::memcpy(second_value.words, first_copy, sizeof(first_copy));
    application_context_compare_ranges_00529c20(
        first_value, second_value, 0);
}

} // namespace

ApplicationSetupContext* __fastcall application_context_base_construct_00525e20(
    ApplicationSetupContext* context, void* unused_edx) {
    (void)unused_edx;
    auto* const object = static_cast<void*>(context->bytes);
    store32(object, 0xd0, 0);
    store32(object, 0, kBaseVtable);

    auto* const allocation = startup_network_allocate_0059ef90(0x0c);
    if (!allocation) {
        store32(object, 4, 0);
        return context;
    }

    store32(allocation, 0, 0);
    auto* const manager = application_context_heap_state_005e4fe8();
    auto* const lock_slot = static_cast<std::uint8_t*>(manager) + 0x28;
    heap_enter_005322b0(from32(load32(lock_slot)));

    auto* const head_slot = lock_slot + 0x18;
    if (load32(head_slot) == 0)
        (void)application_context_new_head_0059eeb0(3, 0);

    auto* const sentinel = from32(load32(head_slot));
    const auto next = load32(sentinel, 4);
    store32(head_slot, 0, next);
    const auto lock = from32(load32(lock_slot));
    heap_leave_005322c0(lock);

    // The saved ECX is read at [ESP+0x17] after stack adjustment; that is
    // its most significant byte (the context pointer's high byte).
    store32(allocation, 0, to32(sentinel));
    store32(allocation, 4, 0);
    store8(allocation, 8, static_cast<std::uint8_t>(to32(context) >> 24));
    store8(sentinel, 0, 0);
    store32(sentinel, 4, 0);
    store32(sentinel, 8, to32(sentinel));
    store32(sentinel, 0x0c, to32(sentinel));
    store32(object, 4, to32(allocation));
    return context;
}

void __fastcall application_context_range_link_00529a20(
    void* object, void* unused_edx, const std::uint32_t* first) {
    (void)unused_edx;
    const auto raw = to32(first);
    store32(object, 0x0c, raw);
    const auto block = load32(first);
    store32(object, 4, block);
    store32(object, 8, block + 0x200u);
}

void __stdcall application_context_initialize_blocks_00529a40(
    std::uint32_t* first, std::uint32_t* last) {
    auto current = to32(first);
    const auto end = to32(last);
    while (current < end) {
        const auto heap = application_context_heap_selector_005e4fec();
        const auto block = application_context_member_block_0059ecb0(
            0x200, heap, 0x005cbdb4u);
        store32(from32(current), 0, to32(block));
        current += 4;
    }
}

void* __fastcall application_context_copy_range_005299d0(
    void* destination, void* unused_edx, const void* source) {
    (void)unused_edx;
    for (std::size_t offset = 0; offset != 0x10; offset += 4)
        store32(destination, offset, load32(source, offset));
    return destination;
}

void* __fastcall application_context_member_construct_005294c0(
    void* member, void* unused_edx) {
    (void)unused_edx;
    store32(member, 8, 0);
    store8(member, 0x0c, 0);
    store32(member, 0x24, 0);
    store32(member, 0x28, 2);
    store32(member, 0, kMemberVtable);

    auto* const storage = startup_network_allocate_0059ef90(0x28);
    if (!storage) {
        store32(member, 4, 0);
    } else {
        store32(storage, 0, 0);
        store32(storage, 4, 8);
        for (std::size_t offset = 8; offset != 0x28; offset += 4)
            store32(storage, offset, 0);

        auto* const array = static_cast<std::uint32_t*>(
            application_context_member_storage_004211d0(0x20, 0));
        store32(storage, 0, to32(array));
        const auto count = load32(storage, 4);
        const auto last_slot = to32(array) + ((count - 1u) >> 1u) * 4u;
        application_context_initialize_blocks_00529a40(
            reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(last_slot)),
            reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(last_slot + 4u)));
        application_context_range_link_00529a20(
            static_cast<std::uint8_t*>(storage) + 8, nullptr,
            reinterpret_cast<const std::uint32_t*>(static_cast<std::uintptr_t>(last_slot)));
        application_context_range_link_00529a20(
            static_cast<std::uint8_t*>(storage) + 0x18, nullptr,
            reinterpret_cast<const std::uint32_t*>(static_cast<std::uintptr_t>(last_slot)));
        store32(storage, 8, load32(storage, 0x0c));
        store32(storage, 0x18, load32(storage, 0x1c));
        store32(member, 4, to32(storage));
    }

    store32(member, 0x10, 0);
    store32(member, 0x14, 0);
    store32(member, 0x18, 0);
    store32(member, 0x1c, 0);
    store32(member, 0x20, 0);
    return member;
}

void __fastcall application_context_member_destroy_005295b0(
    void* member, void* unused_edx) {
    (void)unused_edx;
    auto* const storage = from32(load32(member, 4));
    store32(member, 0, kMemberVtable);
    if (!storage) return;

    finalize_ranges_005299f0(static_cast<std::uint8_t*>(storage) + 0x18,
        static_cast<std::uint8_t*>(storage) + 8);

    if (load32(storage, 0) != 0) {
        auto current = load32(storage, 0x14);
        const auto end = load32(storage, 0x24) + 4u;
        while (current < end) {
            const auto block = from32(load32(from32(current)));
            application_context_member_destroy_block_00441200(block, 0x200);
            current += 4;
        }
        const auto count = load32(storage, 4);
        if (count != 0)
            application_context_clear_004237d0(
                from32(load32(storage)), count * 4u, 0);
    }
    (void)application_release_0059f050(storage);
}

} // namespace porsche
