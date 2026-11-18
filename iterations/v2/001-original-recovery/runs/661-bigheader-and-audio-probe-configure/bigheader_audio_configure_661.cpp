// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 00568b50..00568b8f (64B), 00533d70..00533d96 (39B),
// 00562100..005622f2 (499B, supplement), 00562300..0056233e (63B),
// 0059df70..0059e03d (206B), and 004ae100..004ae2a6 (423B).
#include "bigheader_audio_configure_661.hpp"

#include <cstring>

namespace porsche {

static_assert(sizeof(void*) == 4u, "original x86 layout requires 32-bit pointers");

const char* audio_probe_viv_prefix_0065b314 = nullptr;

const char audio_probe_viv_fmt_005d1bf0[12] = "%szzz%s.viv";
const char audio_probe_buffer_name_005d1bfc[13] = "Music Buffer";
const char audio_probe_globals_name_005d1c0c[14] = "Music Globals";

const char file_load_bigheader_open_err_005bcde4[45] =
    "FILE_loadbigheader - unable to open file %s\n";
const char file_load_bigheader_mem_err_005bce14[59] =
    "FILE_loadbigheader - unable to reserve memory for file %s\n";
const char file_load_bigheader_hdr_err_005bce50[57] =
    "FILE_loadbigheader - invalid big file header in file %s\n";

namespace {

struct LocalStringRange661 {
    std::uint32_t begin;
    std::uint32_t current;
    std::uint32_t end;
};
static_assert(sizeof(LocalStringRange661) == 12u);

std::uint32_t addr32(const void* ptr) {
    return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(ptr));
}

void* ptr_of(std::uint32_t addr) {
    return reinterpret_cast<void*>(static_cast<std::uintptr_t>(addr));
}

std::uint32_t load32(const void* base, std::uint32_t offset) {
    std::uint32_t value = 0u;
    std::memcpy(&value, static_cast<const std::uint8_t*>(base) + offset, sizeof(value));
    return value;
}

void store32(void* base, std::uint32_t offset, std::uint32_t value) {
    std::memcpy(static_cast<std::uint8_t*>(base) + offset, &value, sizeof(value));
}

void report_bigheader_diag(std::uint32_t line, const char* format, const char* path) {
    diagnostic_file_005deb74_set("\\real\\cmn\\hlsfile.c");
    diagnostic_line_005deb78 = line;
    // Canonical cell is typed void(*)(const char*), while 00562100 pushes two args.
    __asm {
        mov eax, path
        push eax
        mov ecx, format
        push ecx
        call dword ptr [diagnostic_handler_005debf0]
        add esp, 8
    }
}

} // namespace

std::uint32_t __cdecl request_read_offset_00568b50(
    void* handle, std::uint32_t offset, void* buffer, std::int32_t size,
    std::uint32_t group, void* context) {
    const std::uint32_t dev = handle_device_005925d0(handle);
    FileOperation* const op = operation_allocate_005682a0(
        3u, static_cast<std::uint8_t>(group), context, dev);
    op->handle = addr32(handle);
    op->offset = offset;
    op->count = static_cast<std::uint32_t>(size);
    op->buffer = buffer;
    return operation_queue_00568200(op);
}

std::uint32_t __cdecl file_read_offset_00533d70(
    void* handle, std::uint32_t offset, void* buffer, std::int32_t size,
    std::uint32_t group) {
    return file_chunks_00533c20(
        handle, offset, buffer, size, group, request_read_offset_00568b50);
}

std::int32_t __cdecl file_load_bigheader_callback_00562100(
    std::uint32_t group, void* opaque_context) {
    const auto* const context = static_cast<const ResourceAtomicContext*>(opaque_context);
    const char* const saved_path = context->path;
    void* handle = opaque_context;
    if (!file_open_00533b90(saved_path, 1u, group, &handle)) {
        if (context->callback_diagnostic_flag != 0u) {
            report_bigheader_diag(0x21du, file_load_bigheader_open_err_005bcde4, saved_path);
        }
        return 0;
    }

    const std::uint32_t alloc_flags = context->opaque_08;
    void* buf = allocate_00531ca0(saved_path, 0xa90, alloc_flags);
    if (buf == nullptr) {
        if (context->callback_diagnostic_flag != 0u) {
            report_bigheader_diag(0x215u, file_load_bigheader_mem_err_005bce14, saved_path);
        }
        (void)close_00533da0(handle, group - 1u);
        return 0;
    }

    const std::uint32_t nested_group = group - 1u;
    (void)read_00533bf0(handle, 0u, buf, 0xa90u, nested_group);
    if (audio_resource_kind_00566520(addr32(buf)) == 0u) {
        if (context->callback_diagnostic_flag != 0u) {
            report_bigheader_diag(0x1f0u, file_load_bigheader_hdr_err_005bce50, saved_path);
        }
        (void)free_00531f90(buf);
        (void)close_00533da0(handle, nested_group);
        return 0;
    }

    const std::uint32_t total_size = audio_resource_size_00566560(addr32(buf));
    if (total_size > 0xa90u) {
        void* const dst = allocate_00531ca0(
            saved_path, static_cast<std::int32_t>(total_size), alloc_flags);
        if (dst == nullptr) {
            if (context->callback_diagnostic_flag != 0u) {
                report_bigheader_diag(0x208u, file_load_bigheader_mem_err_005bce14, saved_path);
            }
            (void)free_00531f90(buf);
            (void)close_00533da0(handle, nested_group);
            return 0;
        }
        heap_copy_dispatch_005323e0(dst, buf, 0xa90u);
        (void)free_00531f90(buf);
        buf = dst;
        (void)read_00533bf0(
            handle,
            0xa90u,
            static_cast<std::uint8_t*>(dst) + 0xa90u,
            total_size - 0xa90u,
            nested_group);
    }

    (void)close_00533da0(handle, nested_group);
    std::int32_t result = 0;
    const std::uint32_t raw_ptr = addr32(buf);
    std::memcpy(&result, &raw_ptr, sizeof(result));
    return result;
}

void* __cdecl file_load_bigheader_quiet_00562300(
    const char* path, std::uint32_t flags) {
    ResourceAtomicContext context;
    context.path = path;
    context.opaque_08 = flags;
    const std::uint32_t group = resource_leaf_group_005df770;
    context.callback_diagnostic_flag = 0u;
    const std::uint32_t device = file_device_name_00568e90(path);
    const std::int32_t result = resource_leaf_atomic_dispatch_00568d50(
        file_load_bigheader_callback_00562100, device, group, &context);
    return ptr_of(static_cast<std::uint32_t>(result));
}

void* __cdecl resource_load_bigheader_quiet_0059df70(
    const char* name, std::uint32_t flags) {
    char path[260];
    if (file_roots_enabled_006af370 == 0) {
        const char* source = name;
        char* target = path;
        do {
            *target++ = *source;
        } while (*source++ != '\0');
        return file_load_bigheader_quiet_00562300(path, flags);
    }

    // Porsche.exe 005cc588 is the null-terminated literal "%s%s".
    formatter_entry_005a0fbf(path, "%s%s", file_root_006af168, name);
    if (file_exists_00561b80(path) != 0) {
        return file_load_bigheader_quiet_00562300(path, flags);
    }

    if (file_fallback_006af26c[0] != '\0') {
        formatter_entry_005a0fbf(path, "%s%s", file_fallback_006af26c, name);
        if (file_exists_00561b80(path) != 0) {
            return file_load_bigheader_quiet_00562300(path, flags);
        }
    }

    // Reload callback after the earlier calls: they may change the cell.
    if (missing_file_006afbe4 != nullptr) {
        missing_file_006afbe4(name, -2);
    }
    return nullptr;
}

void __cdecl application_audio_probe_configure_004ae100(
    std::int32_t first, std::uint32_t second, std::uint32_t config_va) {
    if (*static_cast<const volatile std::uint32_t*>(&audio_resource_query_root_00656ab4) != 0u) {
        return;
    }

    void* const root = allocate_00531ca0(audio_probe_globals_name_005d1c0c, 0x1b4, 0u);
    audio_resource_query_root_00656ab4 = addr32(root);
    if (root == nullptr) {
        return;
    }

    audio_resource_query_root_reset_004adf50();

    const std::uint32_t estimate = application_audio_stream_estimate_005678c0(
        1u, static_cast<std::uint32_t>(first / 1024));
    const std::uint32_t buf_bytes_u = estimate + static_cast<std::uint32_t>(first);
    std::int32_t buf_bytes = 0;
    std::memcpy(&buf_bytes, &buf_bytes_u, sizeof(buf_bytes));
    void* const music_buf = allocate_00531ca0(audio_probe_buffer_name_005d1bfc, buf_bytes, 0u);
    const auto root_for_buf =
        *static_cast<const volatile std::uint32_t*>(&audio_resource_query_root_00656ab4);
    store32(ptr_of(root_for_buf), 0x6cu, addr32(music_buf));

    application_audio_transition_configure_004ae010(
        static_cast<std::uint32_t>(first), second);

    LocalStringRange661 local_str{0u, 0u, 0u};
    game_setup_object_init_raw_00403520(&local_str, nullptr, 8u);
    *static_cast<std::uint8_t*>(ptr_of(local_str.current)) = 0u;

    char viv_name[260];
    const char* const viv_prefix =
        *static_cast<const char* const volatile*>(&audio_probe_viv_prefix_0065b314);
    formatter_entry_005a0fbf(
        viv_name,
        audio_probe_viv_fmt_005d1bf0,
        viv_prefix,
        static_cast<const char*>(ptr_of(config_va)));
    game_setup_resource_open_0059e440(viv_name, &local_str);

    const auto root_for_name =
        *static_cast<const volatile std::uint32_t*>(&audio_resource_query_root_00656ab4);
    const char* const resolved_path = static_cast<const char*>(ptr_of(local_str.begin));
    std::memcpy(
        static_cast<std::uint8_t*>(ptr_of(root_for_name)) + 0xa8u,
        resolved_path,
        std::strlen(resolved_path) + 1u);

    void* const bigheader = resource_load_bigheader_quiet_0059df70(viv_name, 0u);
    const auto root_for_hdr =
        *static_cast<const volatile std::uint32_t*>(&audio_resource_query_root_00656ab4);
    store32(ptr_of(root_for_hdr), 0x88u, addr32(bigheader));

    const auto root_for_off =
        *static_cast<const volatile std::uint32_t*>(&audio_resource_query_root_00656ab4);
    const std::uint32_t hdr_va = load32(ptr_of(root_for_off), 0x88u);
    if (hdr_va != 0u) {
        const std::uint32_t data_off = audio_resource_data_offset_00566880(hdr_va);
        const auto root_for_store =
            *static_cast<const volatile std::uint32_t*>(&audio_resource_query_root_00656ab4);
        store32(ptr_of(root_for_store), 0x04u, data_off);
    }

    const std::uint32_t str_bytes = local_str.end - local_str.begin;
    if (local_str.begin != 0u && str_bytes != 0u) {
        if (str_bytes > 0x100u) {
            context_table_release_0059ecd0(ptr_of(local_str.begin));
        } else {
            auto* const pool = static_cast<std::uint8_t*>(
                application_context_heap_state_005e4fe8()) + 0x28u;
            heap_enter_005322b0(ptr_of(load32(pool, 0x00u)));
            const std::uint32_t head_off = (((str_bytes - 1u) >> 3u) * 4u) + 0x0cu;
            store32(ptr_of(local_str.begin), 0x04u, load32(pool, head_off));
            store32(pool, head_off, local_str.begin);
            heap_leave_005322c0(ptr_of(load32(pool, 0x00u)));
        }
    }
}

} // namespace porsche
