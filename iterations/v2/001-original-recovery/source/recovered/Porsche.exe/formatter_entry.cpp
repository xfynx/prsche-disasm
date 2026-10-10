#include "porsche/formatter_entry.hpp"

#include <cstdarg>
#include <cstring>

namespace porsche {

std::int32_t __cdecl formatter_entry_raw_005a0fbf(
    char* output, const char* format, const std::uint32_t* raw_arguments) {
    FormatterDescriptor005a0fbf descriptor{};
    descriptor.cursor = output;
    descriptor.remaining = 0x7fffffff;
    descriptor.base = output;
    descriptor.flags = 0x42;

    const std::int32_t result =
        formatter_core_005a4371(&descriptor, format, raw_arguments);

    // Original DEC [EBP-1Ch] and JS, including 32-bit wraparound.
    std::uint32_t decremented;
    std::memcpy(&decremented, &descriptor.remaining, sizeof(decremented));
    --decremented;
    std::memcpy(&descriptor.remaining, &decremented, sizeof(decremented));
    if (descriptor.remaining < 0) {
        formatter_cleanup_005a4259(0, &descriptor);
    } else {
        // The core owns cursor movement; original clears *current cursor.
        *descriptor.cursor = 0;
    }
    return result;
}

std::int32_t __cdecl formatter_entry_005a0fbf(
    char* output, const char* format, ...) {
    va_list arguments;
    va_start(arguments, format);
    static_assert(sizeof(va_list) == sizeof(void*),
                  "raw x86 va_list must be one stack pointer");
    const auto* raw = reinterpret_cast<const std::uint32_t*>(arguments);
    const std::int32_t result =
        formatter_entry_raw_005a0fbf(output, format, raw);
    va_end(arguments);
    return result;
}

} // namespace porsche
