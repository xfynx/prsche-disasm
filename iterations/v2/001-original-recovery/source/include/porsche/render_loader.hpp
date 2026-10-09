#pragma once
#include <cstdint>

namespace porsche {
// Porsche.exe SHA256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
// Original global range 0x6bd910..0x6bd9b8, including four alias slots.
extern std::uint32_t render_thrash_exports_006bd910[43];
extern std::uint32_t render_library_handle_0069e5e8;
extern std::uint32_t render_cleanup_token_0069e5ec;
extern std::uint32_t render_driver_name_006a64b4;
extern std::uint32_t render_error_flag_005deb70;
extern std::uint32_t render_error_file_005deb74;
extern std::uint32_t render_error_line_005deb78;

// The original makes Win32 imports through its IAT. These typed recording
// boundaries let the native fixture compare calls without loading a DLL.
std::uint32_t __cdecl render_win_load_library_005b2050(const char* name);
std::uint32_t __cdecl render_win_get_proc_005b205c(std::uint32_t module,const char* name);
void __cdecl render_win_free_library_005b2088(std::uint32_t module);
std::uint32_t __cdecl render_win_get_module_005b2138(const char* name);
void __cdecl render_win_disable_thread_calls_005b21b4(std::uint32_t module);
std::uint32_t __cdecl render_win_last_error_005b213c();
void __cdecl render_loader_format_005a0fbf(char* out,const char* format,...);
void __cdecl render_loader_report_00565340(const char* message);
void __cdecl render_loader_directx_00574eb0(std::uint32_t result[2],const char* dll);
void __cdecl render_loader_reset_00594f00(std::uint32_t token);
void __cdecl render_loader_set_state_006bd97c(std::uint32_t proc,std::uint32_t key,std::uint32_t value);
const std::uint32_t* __cdecl render_loader_about_006bd934(std::uint32_t proc);

std::uint32_t __cdecl render_load_thrash_00574fa0(const char* driver_name);
}
