#include "porsche/resource_dispatch.hpp"

#include "porsche/files.hpp"
#include "porsche/shared_runtime_globals.hpp"

#include <cstdint>
#include <cstring>

namespace porsche {
namespace {
constexpr const char* kFileSource = "\\real\\pc\\nfile.c";
constexpr const char* kHlsFileSource = "\\real\\cmn\\hlsfile.c";

std::int32_t signed_word(std::uint32_t value) noexcept {
    std::int32_t result;
    std::memcpy(&result, &value, sizeof(result));
    return result;
}

void diagnostic(const char* file, std::uint32_t line,
                const char* format) {
    diagnostic_file_005deb74_set(file);
    diagnostic_line_005deb78 = line;
    diagnostic_handler_005debf0(format);
}

void diagnostic(const char* file, std::uint32_t line,
                const char* format, std::int32_t first) {
    diagnostic_file_005deb74_set(file);
    diagnostic_line_005deb78 = line;
    reinterpret_cast<void (__cdecl*)(const char*, ...)>(
        diagnostic_handler_005debf0)(format, first);
}

void diagnostic(const char* file, std::uint32_t line,
                const char* format, std::int32_t first,
                std::int32_t second) {
    diagnostic_file_005deb74_set(file);
    diagnostic_line_005deb78 = line;
    reinterpret_cast<void (__cdecl*)(const char*, ...)>(
        diagnostic_handler_005debf0)(format, first, second);
}

void diagnostic(const char* file, std::uint32_t line,
                const char* format, const char* path) {
    diagnostic_file_005deb74_set(file);
    diagnostic_line_005deb78 = line;
    reinterpret_cast<void (__cdecl*)(const char*, ...)>(
        diagnostic_handler_005debf0)(format, path);
}
} // namespace

std::int32_t __cdecl resource_leaf_atomic_dispatch_00568d50(
    ResourceLeafAtomicCallback callback, std::uint32_t device_index,
    std::uint32_t group, void* context) {
    if (devices_006a5c7c == nullptr) {
        diagnostic(kFileSource, 0x771,
            "FILESYS_atomic - FILE SYSTEM NOT INITIALIZED, CALL FILESYS_init().\n");
    }

    const std::int32_t signed_index = signed_word(device_index);
    if (signed_index < 0 || signed_index > 0x1f) {
        diagnostic(kFileSource, 0x78b,
            "FILESYS_atomic - CALLED WITH ILLEGAL FILE DEVICE (%d).\n",
            signed_index);
        return 0;
    }

    // The original reloads the global table after the diagnostic call above.
    FileDevice* const table = devices_006a5c7c;
    FileDevice* const device = table + device_index;
    if (device->initialized == 0)
        file_start_device_00568390(device_index);

    void* const lock = device->lock;
    heap_enter_005322b0(lock);
    const std::uint32_t old_group = device->field6c;
    std::int32_t result = 0;
    if (signed_word(old_group) < signed_word(group)) {
        diagnostic(kFileSource, 0x786,
            "FILESYS_atomic - CALLED AT PRIORITY (%d) LOWER THAN CURRENT DEVICE PRIORITY (%d).\n",
            signed_word(group), signed_word(old_group));
    } else {
        device->field6c = group;
        result = callback(group, context);
        void* const event = device->queued_event;
        device->field6c = old_group;
        file_event_signal_0055fb30(event);
    }
    heap_leave_005322c0(lock);
    return result;
}

std::int32_t __cdecl resource_leaf_callback_00561be0(
    std::uint32_t group, void* opaque_context) {
    const auto* context = static_cast<const ResourceAtomicContext*>(opaque_context);
    void* handle = nullptr;
    if (!file_open_00533b90(context->path, 1, group, &handle)) {
        if (context->callback_diagnostic_flag != 0) {
            diagnostic(kHlsFileSource, 0x74,
                "FILE_size - unable to open file %s\n", context->path);
        }
        return 0;
    }

    const std::uint32_t nested_group = group - 1u;
    const std::int32_t size = size_00533de0(handle, nested_group);
    close_00533da0(handle, nested_group);
    return size;
}

} // namespace porsche
