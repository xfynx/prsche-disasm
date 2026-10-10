#include "porsche/application_context.hpp"

#include "porsche/application_alloc.hpp"
#include "porsche/application_heap_init.hpp"

#include <cstring>

namespace porsche {
namespace {
constexpr std::uint32_t kContextVtable = 0x005b683c;

void store_u32(ApplicationSetupContext* context, std::size_t offset,
    std::uint32_t value) {
    std::memcpy(context->bytes + offset, &value, sizeof(value));
}
void store_u8(ApplicationSetupContext* context, std::size_t offset,
    std::uint8_t value) {
    context->bytes[offset] = value;
}
std::uint32_t load_u32(const ApplicationSetupContext* context,
    std::size_t offset) {
    std::uint32_t value;
    std::memcpy(&value, context->bytes + offset, sizeof(value));
    return value;
}
void* load_pointer(const ApplicationSetupContext* context, std::size_t offset) {
    const auto raw = load_u32(context, offset);
    return reinterpret_cast<void*>(static_cast<std::uintptr_t>(raw));
}
} // namespace

// Original 004d1a90: __thiscall, ECX=context, no stack arguments.
// Writes are intentionally sparse; all untouched bytes remain caller-owned.
ApplicationSetupContext* __fastcall application_setup_context_construct_004d1a90(
    ApplicationSetupContext* context,void* unused_edx) {
    (void)unused_edx;
    application_context_base_construct_00525e20(context,nullptr);

    store_u32(context, 0xd4, 0);
    store_u32(context, 0xe0, 0);
    store_u32(context, 0xe4, 0);
    store_u32(context, 0xe8, 0);
    store_u32(context, 0xf8, 0);
    store_u32(context, 0xfc, 0);
    store_u32(context, 0x100, 0);
    store_u32(context, 0x104, 0);
    store_u32(context, 0x108, 0);
    store_u32(context, 0x170, 0);
    store_u8(context, 0x174, 0);
    store_u8(context, 0x17c, 0);
    store_u32(context, 0, kContextVtable);

    auto* member = startup_network_allocate_0059ef90(0x2c);
    if (member) application_context_member_construct_005294c0(member,nullptr);
    store_u32(context, 0xd4, static_cast<std::uint32_t>(
        reinterpret_cast<std::uintptr_t>(member)));

    // The original SCASB/REP copies the NUL terminator too and has no bound.
    // The source object's true extent is unresolved (Run 081); do not infer it
    // from the distinct 32-byte declaration used by another consumer.
    const auto length = std::strlen(application_object_heap_name_005e8e50) + 1;
    std::memcpy(context->bytes + 0x10c,
        application_object_heap_name_005e8e50, length);
    return context;
}

// Original 004d1ba0: __thiscall, ECX=context, no stack arguments.
std::uint32_t __fastcall application_setup_context_destroy_004d1ba0(
    ApplicationSetupContext* context,void* unused_edx) {
    (void)unused_edx;
    const auto member = load_pointer(context, 0xd4);
    store_u32(context, 0, kContextVtable);
    if (member) {
        application_context_member_destroy_005295b0(member,nullptr);
        application_release_0059f050(member);
    }
    return application_context_base_destroy_00525ec0(context,nullptr);
}

} // namespace porsche
