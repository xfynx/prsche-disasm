#include "porsche/formatter_original.hpp"
#include "porsche/formatter_parser.hpp"
#include "porsche/formatter_cleanup.hpp"

#include <cstdint>
#include <cstring>

namespace porsche {

// Test-only 108 adapter: the recovered wrapper's exact parser/decrement/clear
// sequence, using the shared 32-byte layout. tail_seed models bytes already
// present in the original stack slot; it is explicit to avoid C++ indeterminate
// reads and is never silently zero-filled.
std::int32_t __cdecl formatter_entry32_adapter_005a0fbf(
    char* output, const char* format, const std::uint32_t* raw_arguments,
    const std::uint8_t tail_seed[16], FormatterOriginalDescriptor32* final_descriptor) {
    FormatterOriginalDescriptor32 descriptor;
    descriptor.cursor = output;
    descriptor.remaining = 0x7fffffff;
    descriptor.base = output;
    descriptor.flags = 0x42;
    std::memcpy(descriptor.opaque_tail, tail_seed, sizeof(descriptor.opaque_tail));

    const std::int32_t result = formatter_parser_005a4371(
        &descriptor, reinterpret_cast<const unsigned char*>(format),
        const_cast<std::uint32_t*>(raw_arguments));
    std::uint32_t remaining_bits;
    std::memcpy(&remaining_bits, &descriptor.remaining, sizeof(remaining_bits));
    --remaining_bits;
    std::memcpy(&descriptor.remaining, &remaining_bits, sizeof(remaining_bits));
    if (descriptor.remaining < 0)
        (void)formatter_cleanup_005a4259(0, &descriptor);
    else
        *descriptor.cursor = 0;
    *final_descriptor = descriptor;
    return result;
}

} // namespace porsche
