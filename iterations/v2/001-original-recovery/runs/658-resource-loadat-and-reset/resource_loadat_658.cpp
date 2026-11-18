// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 00561e90..00561f19 (138B), 00561e40..00561e86 (71B, supplement),
// 00561f20..00561f66 (71B), 0059db50..0059dc29 (218B),
// 00566880..005668bd (62B), and 004adf50..004ae00b (188B).
#include "resource_loadat_658.hpp"

#include <cstring>

namespace porsche {

static_assert(sizeof(void*) == 4u, "original x86 layout requires 32-bit pointers");

const char file_loadat_open_err_005bcd90[38] = "FILE_loadat - unable to open file %s\n";

namespace {

void diagnostic_open_error(const char* path) {
    diagnostic_file_005deb74_set("\\real\\cmn\\hlsfile.c");
    diagnostic_line_005deb78 = 0x12fu;
    const char* const format = file_loadat_open_err_005bcd90;
    // Canonical cell is typed void(*)(const char*), while 00561e90 pushes two args.
    __asm {
        mov eax, path
        push eax
        mov ecx, format
        push ecx
        call dword ptr [diagnostic_handler_005debf0]
        add esp, 8
    }
}

std::uint32_t file_loadat_with_flag(
    const char* path,
    void* buffer,
    std::uint32_t max_bytes,
    std::uint32_t diagnostic_flag) {
    ResourceAtomicContext context;
    context.path = path;
    context.opaque_04 = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(buffer));
    context.opaque_08 = max_bytes;
    const std::uint32_t group = resource_leaf_group_005df770;
    context.callback_diagnostic_flag = diagnostic_flag;
    const std::uint32_t device = file_device_name_00568e90(path);
    const std::int32_t result = resource_leaf_atomic_dispatch_00568d50(
        file_loadat_callback_00561e90, device, group, &context);
    std::uint32_t word = 0u;
    std::memcpy(&word, &result, sizeof(word));
    return word;
}

} // namespace

std::int32_t __cdecl file_loadat_callback_00561e90(
    std::uint32_t group, void* opaque_context) {
    const auto* const context = static_cast<const ResourceAtomicContext*>(opaque_context);
    std::int32_t max_bytes = 0;
    std::memcpy(&max_bytes, &context->opaque_08, sizeof(max_bytes));
    if (max_bytes <= 0) {
        max_bytes = 0x7fffffff;
    }

    const char* const saved_path = context->path;
    // The original passes &opaque_context to file_open_00533b90 as &handle.
    void* handle = opaque_context;
    if (!file_open_00533b90(saved_path, 1u, group, &handle)) {
        if (context->callback_diagnostic_flag != 0u) {
            diagnostic_open_error(saved_path);
        }
        return 0;
    }

    void* const buffer = reinterpret_cast<void*>(static_cast<std::uintptr_t>(context->opaque_04));
    const std::uint32_t nested_group = group - 1u;
    const std::uint32_t count = read_00533bf0(
        handle, 0u, buffer, static_cast<std::uint32_t>(max_bytes), nested_group);
    (void)close_00533da0(handle, nested_group);
    std::int32_t result = 0;
    std::memcpy(&result, &count, sizeof(result));
    return result;
}

std::uint32_t __cdecl file_loadat_00561e40(
    const char* path, void* buffer, std::uint32_t max_bytes) {
    return file_loadat_with_flag(path, buffer, max_bytes, 1u);
}

std::uint32_t __cdecl file_loadat_quiet_00561f20(
    const char* path, void* buffer, std::uint32_t max_bytes) {
    return file_loadat_with_flag(path, buffer, max_bytes, 0u);
}

std::uint32_t __cdecl resource_loadat_quiet_0059db50(
    const char* name, void* buffer, std::uint32_t max_bytes) {
    char path[260];
    if (file_roots_enabled_006af370 == 0) {
        const char* source = name;
        char* target = path;
        do {
            *target++ = *source;
        } while (*source++ != '\0');
        return file_loadat_quiet_00561f20(path, buffer, max_bytes);
    }

    // Porsche.exe 005cc588 is the null-terminated literal "%s%s".
    formatter_entry_005a0fbf(path, "%s%s", file_root_006af168, name);
    if (file_exists_00561b80(path) != 0) {
        return file_loadat_quiet_00561f20(path, buffer, max_bytes);
    }

    if (file_fallback_006af26c[0] != '\0') {
        formatter_entry_005a0fbf(path, "%s%s", file_fallback_006af26c, name);
        if (file_exists_00561b80(path) != 0) {
            return file_loadat_quiet_00561f20(path, buffer, max_bytes);
        }
    }

    // Reload callback after the earlier calls: they may change the cell.
    if (missing_file_006afbe4 != nullptr) {
        missing_file_006afbe4(name, -2);
    }
    return 0u;
}

std::uint32_t __cdecl audio_resource_data_offset_00566880(std::uint32_t source) {
    const std::uint32_t kind = audio_resource_kind_00566520(source);
    if (kind == 1u) {
        return render_descriptor_read_be_0056e290(
            reinterpret_cast<const void*>(static_cast<std::uintptr_t>(source + 4u)), 2u);
    }
    if (kind == 2u) {
        return render_descriptor_read_be_0056e290(
            reinterpret_cast<const void*>(static_cast<std::uintptr_t>(source + 8u)), 4u);
    }
    return 0u;
}

void __cdecl audio_resource_query_root_reset_004adf50() {
    auto write_at = [](std::uint32_t offset, std::uint32_t value) {
        const auto base =
            *static_cast<const volatile std::uint32_t*>(&audio_resource_query_root_00656ab4);
        std::memcpy(
            reinterpret_cast<void*>(static_cast<std::uintptr_t>(base + offset)),
            &value,
            sizeof(value));
    };
    write_at(0x88u, 0u);
    write_at(0x6cu, 0u);
    write_at(0x70u, 0xffffffffu);
    write_at(0x78u, 0u);
    write_at(0x7cu, 0u);
    write_at(0x04u, 0u);
    write_at(0x00u, 0u);
    write_at(0x20u, 0u);
    write_at(0x08u, 0u);
    write_at(0x10u, 0u);
    write_at(0x18u, 0u);
    write_at(0x28u, 0u);
    write_at(0x14u, 0u);
    write_at(0x0cu, 0xffffffffu);
    write_at(0x1cu, 0u);
    write_at(0x80u, 0u);

    const std::uint32_t tail =
        *static_cast<const volatile std::uint32_t*>(&audio_resource_query_root_00656ab4) + 0x168u;
    const std::uint32_t zero = 0u;
    static constexpr std::uint32_t kTailOffsets[] = {
        0x08u, 0x24u, 0x0cu, 0x10u, 0x14u, 0x18u, 0x20u};
    for (const std::uint32_t rel : kTailOffsets) {
        std::memcpy(
            reinterpret_cast<void*>(static_cast<std::uintptr_t>(tail + rel)),
            &zero,
            sizeof(zero));
    }
}

} // namespace porsche
