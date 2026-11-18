// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 005620c0..005620fe (63B), 0059dea0..0059df6d (206B),
// and 0059fd90..0059fdbd (46B).
#include "bigheader_loud_startup_diag_670.hpp"

#include <cstdarg>

namespace porsche {

static_assert(sizeof(void*) == 4u, "original x86 layout requires 32-bit pointers");

void* __cdecl file_load_bigheader_005620c0(
    const char* path, std::uint32_t flags) {
    ResourceAtomicContext context;
    context.path = path;
    context.opaque_08 = flags;
    const std::uint32_t group = resource_leaf_group_005df770;
    context.callback_diagnostic_flag = 1u;
    const std::uint32_t device = file_device_name_00568e90(path);
    const std::int32_t result = resource_leaf_atomic_dispatch_00568d50(
        file_load_bigheader_callback_00562100, device, group, &context);
    return reinterpret_cast<void*>(static_cast<std::uintptr_t>(
        static_cast<std::uint32_t>(result)));
}

void* __cdecl resource_load_bigheader_0059dea0(
    const char* name, std::uint32_t flags) {
    char path[260];
    if (file_roots_enabled_006af370 == 0) {
        const char* source = name;
        char* target = path;
        do {
            *target++ = *source;
        } while (*source++ != '\0');
        return file_load_bigheader_005620c0(path, flags);
    }

    // Porsche.exe 005cc588 is the null-terminated literal "%s%s".
    formatter_entry_005a0fbf(path, "%s%s", file_root_006af168, name);
    if (file_exists_00561b80(path) != 0) {
        return file_load_bigheader_005620c0(path, flags);
    }

    if (file_fallback_006af26c[0] != '\0') {
        formatter_entry_005a0fbf(path, "%s%s", file_fallback_006af26c, name);
        if (file_exists_00561b80(path) != 0) {
            return file_load_bigheader_005620c0(path, flags);
        }
    }

    // Reload callback after the earlier calls: they may change the cell.
    if (missing_file_006afbe4 != nullptr) {
        missing_file_006afbe4(name, -2);
    }
    return nullptr;
}

void __cdecl startup_diagnostic_format_0059fd90(const char* format, ...) {
    char buffer[1024];
    std::va_list arguments;
    va_start(arguments, format);
    static_assert(sizeof(arguments) == sizeof(void*), "Original x86 raw varargs");
    (void)application_diagnostic_mono_vsprintf_005a299e(
        buffer, format, reinterpret_cast<const std::uint32_t*>(arguments));
    va_end(arguments);
    startup_diagnostic_sink_0059fc20(buffer);
}

} // namespace porsche
