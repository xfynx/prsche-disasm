#include "porsche/window_shutdown.hpp"

#include "porsche/application_instance.hpp"
#include "porsche/window_scheduler.hpp"

#include <cstring>

namespace porsche {

void* window_shutdown_handle_0069dd18 = nullptr;
std::uint32_t window_shutdown_state_005de67c = 0;
std::uint32_t window_shutdown_state_005de6ac = 0;
std::uint32_t window_shutdown_config_005de620[12]{};
std::uint8_t& window_shutdown_mode_005de630 =
    reinterpret_cast<std::uint8_t*>(window_shutdown_config_005de620)[0x10];
std::uint32_t& window_shutdown_state_005de64c = window_shutdown_config_005de620[11];
std::uint8_t window_shutdown_source_005de65c = 0;
std::uint8_t window_shutdown_source_005de65d = 0;

// 00534430, the first operation reached by 00534550's null-input path.
void __cdecl window_shutdown_runtime_state_00534430() {
    const auto handle = window_shutdown_handle_0069dd18;
    if (!handle) return;
    (void)window_shutdown_close_handle_006bd92c(handle);

    window_shutdown_state_005de64c = 0;
    const auto mode = window_shutdown_mode_005de630;
    if (mode == 1) {
        window_shutdown_state_005de67c = 0;
        window_shutdown_handle_0069dd18 = nullptr;
        window_shutdown_display_callback_006bd9b0(0);
        return;
    }
    if (mode == 2) window_shutdown_state_005de6ac = 0;

    window_shutdown_handle_0069dd18 = nullptr;
    window_shutdown_display_callback_006bd9b0(0);
}

// The exact 00534550 caller supplies a null descriptor. 00534480 first runs
// 00534430, then 0053c290(dest=005de620, DWORD pattern=0, length=0x30), and
// patches two bytes from the adjacent original data fields.
std::uint32_t __cdecl window_shutdown_prepare_00534550() {
    window_shutdown_runtime_state_00534430();
    std::memset(window_shutdown_config_005de620, 0, sizeof(window_shutdown_config_005de620));
    reinterpret_cast<std::uint8_t*>(window_shutdown_config_005de620)[0x0c] =
        window_shutdown_source_005de65c;
    reinterpret_cast<std::uint8_t*>(window_shutdown_config_005de620)[0x0d] =
        window_shutdown_source_005de65d;
    return 1;
}

void __cdecl window_shutdown_process_exit_00557370() {
    application_instance_exit_005a246e(0);
}

std::uint32_t __cdecl window_shutdown_callback_0053bae0(
    std::uint32_t, std::uint32_t) {
    (void)window_shutdown_prepare_00534550();
    (void)window_scheduler_remove_005366a0(&window_shutdown_callback_0053bae0);
    // 00557370 is PUSH 0; CALL 005a246e. The final CRT termination body
    // remains the established explicit boundary in application_instance.
    window_shutdown_process_exit_00557370();
    return 0; // reached only by a returning fixture for the terminal boundary
}

}
