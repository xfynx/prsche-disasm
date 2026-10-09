#include "porsche/shared_runtime_globals.hpp"

#include <cstdint>
#include <iostream>

static_assert(sizeof(void*) == 4, "Run080 proves the original Win32 storage ABI");

namespace {
bool same_storage(const void* a, const void* b) {
    return a == b;
}
}

int main() {
    using namespace porsche;
    const bool address_1c = same_storage(&copy_flag_005deb1c,
                                         &render_display_clock_005deb1c);
    const bool address_74_app = same_storage(&shared_runtime_word_005deb74,
                                              &application_diagnostic_source_005deb74);
    const bool address_74_render = same_storage(&shared_runtime_word_005deb74,
                                                 &render_error_file_005deb74);
    const bool address_74_window = same_storage(&shared_runtime_word_005deb74,
                                                 &class_error_file_005deb74);
    const bool address_78 = same_storage(&application_diagnostic_line_005deb78,
        &diagnostic_line_005deb78) &&
        same_storage(&shared_runtime_word_005deb78,&render_error_line_005deb78) &&
        same_storage(&shared_runtime_word_005deb78,&class_error_line_005deb78);
    const bool null_source_preserved = diagnostic_file_005deb74() == nullptr;

    copy_flag_005deb1c = 0x12345678u;
    const bool write_1c_heap_to_render = render_display_clock_005deb1c == 0x12345678u;
    render_display_clock_005deb1c = 0x87654321u;
    const bool write_1c_render_to_heap = copy_flag_005deb1c == 0x87654321u;

    application_diagnostic_source_005deb74 = 0x005cdf04u;
    const bool write_74_app_to_all =
        reinterpret_cast<std::uintptr_t>(diagnostic_file_005deb74()) == 0x005cdf04u &&
        render_error_file_005deb74 == 0x005cdf04u && class_error_file_005deb74 == 0x005cdf04u;
    diagnostic_file_005deb74_set(reinterpret_cast<const char*>(
        static_cast<std::uintptr_t>(0x005bb8d4u)));
    const bool write_74_file_to_all = shared_runtime_word_005deb74 == 0x005bb8d4u &&
        render_error_file_005deb74 == 0x005bb8d4u && class_error_file_005deb74 == 0x005bb8d4u;
    render_error_file_005deb74 = 0x005df934u;
    const bool write_74_render_to_all =
        reinterpret_cast<std::uintptr_t>(diagnostic_file_005deb74()) == 0x005df934u &&
        application_diagnostic_source_005deb74 == 0x005df934u &&
        class_error_file_005deb74 == 0x005df934u;

    application_diagnostic_line_005deb78 = 0xa0u;
    const bool write_78_app_to_all = diagnostic_line_005deb78 == 0xa0u &&
        render_error_line_005deb78 == 0xa0u && class_error_line_005deb78 == 0xa0u;
    class_error_line_005deb78 = 0x38fu;
    const bool write_78_window_to_all = shared_runtime_word_005deb78 == 0x38fu &&
        application_diagnostic_line_005deb78 == 0x38fu &&
        diagnostic_line_005deb78 == 0x38fu && render_error_line_005deb78 == 0x38fu;

    const bool all = address_1c && address_74_app && address_74_render &&
        address_74_window && address_78 && write_1c_heap_to_render && write_1c_render_to_heap &&
        write_74_app_to_all && write_74_file_to_all && write_74_render_to_all &&
        write_78_app_to_all && write_78_window_to_all && null_source_preserved;
    std::cout << "{\"x86\":" << (sizeof(void*) == 4 ? "true" : "false")
              << ",\"address_005deb1c\":" << (address_1c ? "true" : "false")
              << ",\"address_005deb74_numeric_aliases\":"
              << ((address_74_app && address_74_render && address_74_window) ? "true" : "false")
              << ",\"address_005deb78_all\":" << (address_78 ? "true" : "false")
              << ",\"null_source_preserved\":" << (null_source_preserved ? "true" : "false")
              << ",\"writes_visible\":" << ((write_1c_heap_to_render && write_1c_render_to_heap &&
                  write_74_app_to_all && write_74_file_to_all && write_74_render_to_all &&
                  write_78_app_to_all && write_78_window_to_all) ? "true" : "false")
              << "}\n";
    return all ? 0 : 1;
}
