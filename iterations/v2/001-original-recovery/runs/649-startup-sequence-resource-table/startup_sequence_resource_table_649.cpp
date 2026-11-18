// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 00561e00..00561e3e (63B), 0059d9b0..0059da7d (206B),
// 00452590..00452655 (198B), 004690d0..004690e0 (17B), and loader-zero .data BSS.
#include "startup_sequence_resource_table_649.hpp"

#include <cstring>

namespace porsche {

static_assert(sizeof(void*) == 4u, "original x86 layout requires 32-bit pointers");

std::uint16_t startup_night_shape_enabled_00628a28 = 0u;
const char* startup_resource_prefix_0065b30c = nullptr;
void* startup_night_shape_buffer_0061c164 = nullptr;
void* startup_night_shape_data_0061e1cc = nullptr;
void* startup_context_table_owner_00613e04 = nullptr;
std::uint32_t startup_head_state_a_0061bcc8 = 0u;
std::uint32_t startup_head_state_b_0061e180 = 0u;
void* startup_head_table_entry_0061e1d4 = nullptr;
std::uint8_t startup_sequence_flag_00619760 = 0u;

void* __cdecl file_open_quiet_00561e00(const char* path, std::uint32_t flags) {
    ResourceAtomicContext context; // +04 is deliberately uninitialized/unread.
    context.path = path;
    context.opaque_08 = flags;
    const std::uint32_t group = resource_leaf_group_005df770;
    context.callback_diagnostic_flag = 0u;
    const std::uint32_t device = file_device_name_00568e90(path);
    const std::int32_t result = resource_leaf_atomic_dispatch_00568d50(
        resource_open_callback_00561ce0, device, group, &context);
    std::uint32_t word = 0u;
    std::memcpy(&word, &result, sizeof(word));
    return reinterpret_cast<void*>(static_cast<std::uintptr_t>(word));
}

void* __cdecl resource_open_quiet_0059d9b0(const char* name, std::uint32_t flags) {
    char path[260];
    if (file_roots_enabled_006af370 == 0) {
        const char* source = name;
        char* target = path;
        do {
            *target++ = *source;
        } while (*source++ != '\0');
        return file_open_quiet_00561e00(path, flags);
    }

    // Porsche.exe 005cc588 is the null-terminated literal "%s%s".
    formatter_entry_005a0fbf(path, "%s%s", file_root_006af168, name);
    if (file_exists_00561b80(path) != 0) {
        return file_open_quiet_00561e00(path, flags);
    }

    if (file_fallback_006af26c[0] != '\0') {
        formatter_entry_005a0fbf(path, "%s%s", file_fallback_006af26c, name);
        if (file_exists_00561b80(path) != 0) {
            return file_open_quiet_00561e00(path, flags);
        }
    }

    // Reload callback after the earlier calls: they may change the cell.
    if (missing_file_006afbe4 != nullptr) {
        missing_file_006afbe4(name, -2);
    }
    return nullptr;
}

void __cdecl startup_sequence_resource_table_setup_00452590() {
    if (startup_night_shape_enabled_00628a28 != 0u) {
        char path[256];
        formatter_entry_005a0fbf(path, "%snight.psh", startup_resource_prefix_0065b30c);
        const std::int32_t alloc_size = resource_predicate_0059dd00(path);
        startup_night_shape_buffer_0061c164 = allocate_00531ca0("night.psh", alloc_size, 0u);
        void* const loaded = resource_open_quiet_0059d9b0(path, 0u);
        const std::int32_t copy_size = resource_predicate_0059dd00(path);
        render_copy_bytes_005563b0(
            loaded,
            startup_night_shape_buffer_0061c164,
            static_cast<std::uint32_t>(copy_size));
        (void)free_00531f90(loaded);
        void* const entry = shape_find_entry_0053c640(
            startup_night_shape_buffer_0061c164, "nght");
        startup_night_shape_data_0061e1cc = reinterpret_cast<void*>(
            reinterpret_cast<std::uintptr_t>(entry) + 0x10u);
    }
    startup_head_state_a_0061bcc8 = 0u;
    startup_head_state_b_0061e180 = 0u;
    startup_head_table_entry_0061e1d4 = startup_context_table_lookup_0044d320(
        startup_context_table_owner_00613e04,
        nullptr,
        0u,
        0x44414548u);
}

void __cdecl startup_sequence_call_004690d0() {
    startup_sequence_resource_table_setup_00452590();
    startup_sequence_flag_00619760 = 1u;
    startup_context_table_init_0047f040();
}

} // namespace porsche
