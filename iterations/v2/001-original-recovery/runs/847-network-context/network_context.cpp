#include "network_context.hpp"

#include "porsche/event_lifecycle.hpp"
#include "porsche/formatter_bootstrap.hpp"
#include "porsche/heap.hpp"

#include <cstring>

namespace porsche {
namespace {
using Byte = unsigned char;
using StartTransport = std::uint32_t (__cdecl*)();
using Receive = void (__cdecl*)(void*, const void*);
using OpenTransport = void* (__cdecl*)(std::uint32_t, void*, Receive);
using ReadAddress = std::uint32_t (__cdecl*)(void*, void*);
static_assert(sizeof(void*) == 4);

template<typename T>
T read(const Byte* source) {
    T result;
    std::memcpy(&result, source, sizeof(result));
    return result;
}

template<typename T>
void write(Byte* destination, T value) {
    std::memcpy(destination, &value, sizeof(value));
}
}

std::uint32_t __cdecl network_shared_context_create_00587bf0(
    void* context, const void* identity, const void*, std::uint32_t endpoint,
    const char* name, const char* short_name) {
    auto* object = static_cast<Byte*>(context);
    if (network_shared_context_count_006ad748++ == 0) {
        auto* descriptor = read<Byte*>(object + 0x0c);
        if (!read<StartTransport>(descriptor + 0x14)()) return 0;
        heap_enter_005322b0(thread_start_lock_006a57d8);
        auxiliary_event_callback_add_0053bfe0(network_shared_context_service_00587cc0);
        heap_leave_005322c0(thread_start_lock_006a57d8);
    }

    auto* descriptor = read<Byte*>(object + 0x0c);
    write<void*>(object + 0x10, nullptr);
    auto* handle = read<OpenTransport>(descriptor + 0x1c)(
        endpoint, object, network_shared_context_receive_00582320);
    write(object + 0x10, handle);
    if (!handle) return 0;

    descriptor = read<Byte*>(object + 0x0c);
    read<ReadAddress>(descriptor + 0x44)(handle, object + 0x38);
    write<std::uint32_t>(object + 0xa4, 1);
    heap_copy_dispatch_005323e0(object + 0x94, identity, 0x10);
    formatter_error_copy_n_005a28a0(reinterpret_cast<char*>(object + 0x4c), name, 0x33);
    formatter_error_copy_n_005a28a0(reinterpret_cast<char*>(object + 0x80), short_name, 0x13);
    return 250;
}

} // namespace porsche
