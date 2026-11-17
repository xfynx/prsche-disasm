// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 00565340..005654bc, 381 bytes, sha256 33d1703a90eedbf8824059487bb2a994f3450a56a838fd58ac036a0e11e24672.
#include "diagnostic_abort_handler_626.hpp"

#include <cstdarg>
#include <cstring>

#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Original x86 naked forwarding and raw varargs layout required for 00565340.
#endif

namespace porsche {

std::uint32_t diagnostic_abort_active_006a5c24 = 0u;
std::uint32_t diagnostic_abort_finish_005deb6c = 0u;
std::uint32_t diagnostic_abort_has_location_005deb84 = 0u;
std::uint32_t diagnostic_abort_cleanup_005deb8c = 0u;
std::uint32_t diagnostic_abort_hook_005deb90 = 0u;
std::uint32_t diagnostic_abort_filter_005deb94 = 0u;

const char diagnostic_indent_fmt_005bd4c4[5] = "  %s";
const char diagnostic_abort_title_005bd4cc[14] = "Abort Message";
const char diagnostic_abort_file_line_fmt_005bd4dc[30] = "Abort from file \"%s\", line %d";
const char diagnostic_newline_005d0b1c[2] = "\n";

void __cdecl diagnostic_report_varargs_00565340(const char* format, ...);

void __cdecl diagnostic_report_varargs_00565340(const char* format, ...) {
    if (diagnostic_abort_active_006a5c24 != 0u) {
        return;
    }
    diagnostic_abort_active_006a5c24 = 1u;

    char message[512];
    if (format != nullptr) {
        std::va_list args;
        va_start(args, format);
        static_assert(sizeof(args) == sizeof(void*), "Original x86 raw varargs");
        (void)application_diagnostic_mono_vsprintf_005a299e(
            message, format, reinterpret_cast<const std::uint32_t*>(args));
        va_end(args);
    } else {
        message[0] = '\0';
    }

    if (diagnostic_abort_filter_005deb94 != 0u) {
        const std::int32_t res = reinterpret_cast<std::int32_t(__cdecl*)(char*)>(
            static_cast<std::uintptr_t>(diagnostic_abort_filter_005deb94))(message);
        if (res == 0) {
            diagnostic_abort_active_006a5c24 = 0u;
            return;
        }
    }

    char title[128];
    if (diagnostic_abort_has_location_005deb84 != 0u && shared_runtime_word_005deb74 != 0u) {
        render_loader_format_005a0fbf(
            title,
            diagnostic_abort_file_line_fmt_005bd4dc,
            reinterpret_cast<const char*>(static_cast<std::uintptr_t>(shared_runtime_word_005deb74)),
            shared_runtime_word_005deb78);
    } else {
        std::memcpy(title, diagnostic_abort_title_005bd4cc, sizeof diagnostic_abort_title_005bd4cc);
    }

    std::uint32_t lock_handle = 0u;
    if (diagnostic_abort_cleanup_005deb8c != 0u) {
        lock_handle = reinterpret_cast<std::uint32_t(__cdecl*)()>(
            static_cast<std::uintptr_t>(diagnostic_abort_cleanup_005deb8c))();
    }
    if (diagnostic_abort_hook_005deb90 != 0u) {
        reinterpret_cast<void(__cdecl*)()>(
            static_cast<std::uintptr_t>(diagnostic_abort_hook_005deb90))();
    }

    (void)render_window_show_cursor(1);
    render_message_box_005b2270(0u, message, title, 0x11011u);

    if (texture_create_errors_005deb80 != 0u && diagnostic_abort_finish_005deb6c != 0u) {
        render_texture_diagnostic_0055ec50(2u, title);
        render_texture_diagnostic_0055ec50(2u, diagnostic_newline_005d0b1c);
        render_texture_diagnostic_0055ec50(2u, diagnostic_indent_fmt_005bd4c4, message);
        reinterpret_cast<void(__cdecl*)()>(
            static_cast<std::uintptr_t>(diagnostic_abort_finish_005deb6c))();
    }

    if (lock_handle != 0u) {
        heap_leave_005322c0(reinterpret_cast<void*>(static_cast<std::uintptr_t>(lock_handle)));
    }
    if (file_current_thread_0055f780(0u) != 0) {
        application_instance_exit_005a246e(0u);
    }
    exit_shutdown_exit_process(0u);
}

__declspec(naked) void __cdecl file_diagnostic_00565340(const char*) {
    __asm jmp diagnostic_report_varargs_00565340
}

__declspec(naked) void __cdecl render_loader_report_00565340(const char*) {
    __asm jmp diagnostic_report_varargs_00565340
}

__declspec(naked) void __cdecl window_scheduler_diagnostic_00565340(const char*) {
    __asm jmp diagnostic_report_varargs_00565340
}

} // namespace porsche
