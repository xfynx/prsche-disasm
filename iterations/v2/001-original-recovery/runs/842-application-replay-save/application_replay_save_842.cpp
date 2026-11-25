// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
// Original 00413fd0..0041405d (142B), 0059e170..0059e1af (64B),
// 00562460..005624a6 (71B), and 00562390..00562451 (194B, supplement).
#include "application_replay_save_842.hpp"

#include <algorithm>
#include <cstdint>

namespace porsche {

static_assert(sizeof(void*) == 4u, "original x86 layout requires 32-bit pointers");

const char replay_default_filename_005cc68c[11] = "replay.rpl";
const char replay_final_gametick_fmt_005cc678[19] = "FINAL GAMETICK=%d\n";
const char file_save_source_005bcd00[20] = "\\real\\cmn\\hlsfile.c";
const char file_save_write_err_005bceb0[40] = "FILE_save - failure writing to file %s\n";
const char file_save_open_err_005bce8c[36] = "FILE_save - unable to open file %s\n";

std::int32_t __cdecl file_save_callback_00562390(std::uint32_t group, void* opaque_context) {
    auto* context = static_cast<ResourceAtomicContext*>(opaque_context);
    const char* path = context->path;
    void* handle = nullptr;
    if (!file_open_00533b90(path, 6u, group, &handle)) {
        if (context->callback_diagnostic_flag != 0u) {
            diagnostic_file_005deb74_set(file_save_source_005bcd00);
            diagnostic_line_005deb78 = 0x274u;
            reinterpret_cast<void(__cdecl*)(const char*, const char*)>(diagnostic_handler_005debf0)(
                file_save_open_err_005bce8c, path);
        }
        return 0;
    }

    const std::int32_t size = static_cast<std::int32_t>(context->opaque_08);
    void* const buffer = reinterpret_cast<void*>(static_cast<std::uintptr_t>(context->opaque_04));
    const std::uint32_t sub_group = group - 1u;
    const std::uint32_t written = file_read_offset_00533d70(handle, 0u, buffer, size, sub_group);
    (void)close_00533da0(handle, sub_group);

    const std::int32_t ok = (written == static_cast<std::uint32_t>(size)) ? 1 : 0;
    if (ok == 0 && context->callback_diagnostic_flag != 0u) {
        diagnostic_file_005deb74_set(file_save_source_005bcd00);
        diagnostic_line_005deb78 = 0x26eu;
        reinterpret_cast<void(__cdecl*)(const char*, const char*)>(diagnostic_handler_005debf0)(
            file_save_write_err_005bceb0, path);
    }
    return ok;
}

void __cdecl file_save_00562460(const char* path, void* buffer, std::int32_t size) {
    ResourceAtomicContext context{};
    context.path = path;
    context.opaque_04 = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(buffer));
    context.opaque_08 = static_cast<std::uint32_t>(size);
    context.callback_diagnostic_flag = 0u;
    const std::uint32_t group = resource_leaf_group_005df770;
    const std::uint32_t device = file_device_name_00568e90(path);
    (void)resource_leaf_atomic_dispatch_00568d50(
        file_save_callback_00562390, device, group, &context);
}

void __cdecl resource_save_0059e170(const char* name, const void* buffer, std::int32_t size) {
    char path[260]{};
    (void)formatter_entry_005a0fbf(path, "%s%s", file_root_006af168, name);
    file_save_00562460(path, const_cast<void*>(buffer), size);
}

void __cdecl application_sim_boundary_00413fd0() {
    if (global_005e99f4 == 0u) {
        replay_saved_word_00606a80 = startup_sequence_word_00606ac4;
    }
    std::copy_n(
        application_state_006573e8.words().data(),
        application_state_word_count,
        replay_snapshot_005e9a20);
    replay_snapshot_005e9a20[15] = 2u;
    replay_tail_word_005ed844 = replay_saved_word_00606a80;

    char path[256]{};
    (void)formatter_entry_005a0fbf(
        path, "%s%s", engine_service_root_0065b360, replay_default_filename_005cc68c);
    (void)formatter_stdio_printf_005a177b(
        replay_final_gametick_fmt_005cc678, replay_saved_word_00606a80);
    resource_save_0059e170(path, replay_snapshot_005e9a20, 0x1ce28);
}

} // namespace porsche
