#include "porsche/application_alloc.hpp"
#include "porsche/application_instance.hpp"
#include "porsche/application_main.hpp"
#include "porsche/render_activate.hpp"
#include "porsche/render_display.hpp"
#include "porsche/render_driver_calls.hpp"
#include "porsche/render_mode.hpp"
#include "porsche/render_startup.hpp"
#include "porsche/render_window.hpp"
#include "porsche/startup_input.hpp"
#include "porsche/startup_services.hpp"
#include "porsche/startup_subsystems.hpp"
#include "porsche/window_runtime.hpp"
#include "porsche/render_event_route.hpp"
#include "porsche/fe_stream.hpp"
#include "porsche/file_wait.hpp"
#include "porsche/game_setup.hpp"
#include "porsche/engine_service_427a60.hpp"
#include "porsche/frame_pump.hpp"
#include "porsche/frame_services.hpp"
#include "porsche/startup_sequence.hpp"
#include "porsche/splash_progress.hpp"
#include "porsche/startup_service_56a490.hpp"
#include "porsche/startup_service_516950.hpp"
#include "porsche/resource_predicate.hpp"
#include "porsche/resource_leaf.hpp"
#include "porsche/resource_dispatch.hpp"
#include "porsche/formatter_entry.hpp"
#include "porsche/heap.hpp"
#include "porsche/render_startup.hpp"
#include "porsche/render_display.hpp"
#include "porsche/render_loader.hpp"
#include "porsche/game_setup.hpp"
#include "porsche/splash_progress.hpp"
#include "porsche/startup_services.hpp"
#include <cstdarg>
#include "porsche/window_shutdown.hpp"
#include "porsche/heap.hpp"
#include <cstring>

namespace {
void formatter_forward_va(char* out, const char* format, va_list args) {
    static_assert(sizeof(va_list) == sizeof(void*),
                  "the original x86 variadic ABI is a stack pointer");
    (void)porsche::formatter_entry_raw_005a0fbf(
        out, format, reinterpret_cast<const std::uint32_t*>(args));
}
}

namespace porsche {
void __cdecl application_main_function_004dd600() {
    game_setup_004dd600();
}
void __cdecl application_main_function_004b67b0() {
    startup_sequence_004b67b0();
}
void __cdecl application_main_function_004a4a70(std::uint32_t phase_word) {
    std::int32_t phase;
    std::memcpy(&phase,&phase_word,sizeof(phase));
    splash_progress_004a4a70(phase);
}
void __cdecl startup_sequence_call_0056a490() {
    startup_service_release_0056a490();
}
void __cdecl startup_sequence_call_00516950() {
    startup_service_noop_00516950();
}
void __cdecl startup_sequence_call_00427a60() {
    engine_service_00427a60();
}
void __cdecl startup_sequence_call_004b0d70() {
    frame_pump_004b0d70();
}
void __cdecl splash_progress_frame_begin_004b0d70() {
    frame_pump_004b0d70();
}
void __cdecl splash_progress_pump_005366e0(std::uint32_t argument) {
    (void)timed_callbacks_005366e0(argument);
}
void __cdecl splash_progress_enter_lock_005322b0(void* lock) {
    heap_enter_005322b0(lock);
}
void __cdecl splash_progress_leave_lock_005322c0(void* lock) {
    heap_leave_005322c0(lock);
}
void __cdecl splash_progress_free_00531f90(void* allocation) {
    (void)free_00531f90(allocation);
}
void __cdecl splash_progress_driver_frame_end_00534550() {
    (void)window_shutdown_prepare_00534550();
}
// Link names retained by independently recovered callers to canonical bodies.
// No original algorithm is reimplemented here. Run075 records ABI evidence.
void* __cdecl render_allocate_0059ef90(std::uint32_t bytes) {
    return startup_network_allocate_0059ef90(bytes);
}
void* __cdecl render_display_allocate_0059ef90(std::uint32_t bytes) {
    return startup_network_allocate_0059ef90(bytes);
}
void* __cdecl render_display_buffer_alloc_00531ca0(const char* source,
    std::uint32_t bytes,std::uint32_t heap) {
    return allocate_00531ca0(source,static_cast<std::int32_t>(bytes),heap);
}
std::uint32_t __cdecl render_activate_video_mode_005376c0(std::uint32_t width,
    std::uint32_t height,std::uint32_t mode,std::uint32_t transition,std::uint32_t one) {
    return render_display_video_mode_005376c0(width,height,mode,transition,one);
}
void __cdecl render_window_query_mode_info_0044e720(std::uint32_t index,
    std::uint32_t* record) {
    render_mode_query_0044e720(index,record);
}
void __cdecl render_window_commit_mode_0044ebf0(std::uint32_t index) {
    render_mode_commit_0044ebf0(index);
}
void __cdecl render_window_time_update_0044ed10() {
    render_mode_update_state_0044ed10();
}
void __cdecl render_window_video_base_00537600(std::uint32_t a,std::uint32_t b,
    std::uint32_t c,std::uint32_t width,std::uint32_t height,std::uint32_t f) {
    render_display_video_base_00537600(a,b,c,width,height,f);
}
void __cdecl startup_event_0055fcf0() {
    (void)startup_input_initialize_0055fcf0();
}
void __cdecl startup_name_005655f0(const char* name) {
    (void)application_instance_check_005655f0(name);
}
void __cdecl startup_subsystem_00564e70() {
    (void)startup_keyboard_detect_00564e70();
}
void __cdecl startup_subsystem_00564ab0() {
    startup_joystick_enumerate_00564ab0();
}
// This original thunk reads no arguments; its caller cleans the ignored DWORD.
void __cdecl startup_subsystem_00564850(std::uint32_t) {
    startup_joystick_thunk_00564850();
}
// Original 005367b0 returns zero without reading any caller arguments.
void __cdecl startup_subsystem_005367b0(std::uint32_t,std::uint32_t,std::uint32_t) {
    (void)render_event_default_callback_005367b0(0);
}
void __cdecl application_main_function_005366e0(std::uint32_t argument) {
    (void)timed_callbacks_005366e0(argument);
}
std::uint32_t __cdecl file_pump_005366e0(std::uint32_t argument) {
    return timed_callbacks_005366e0(argument);
}
std::uint32_t __cdecl frame_pump_boundary_004ab150() {
    return frame_services_004ab150();
}
std::uint32_t __cdecl frame_pump_boundary_004ab200() {
    return frame_services_004ab200();
}
std::int32_t __cdecl engine_service_file_exists_0059dd00(const char* path) {
    return resource_predicate_0059dd00(path);
}
std::int32_t __cdecl resource_predicate_unrooted_00561ba0(const char* path) {
    return resource_leaf_00561ba0(path);
}

// The eleven source spellings in Run 104 are caller-side declarations for
// this single original variadic entry. These adapters preserve each call's
// original stack-word order and declared variadic types; none formats on host.
void __cdecl heap_format_005a0fbf(char* out, const char* format,
                                  const char* name) {
    (void)formatter_entry_005a0fbf(out, format, name);
}
void __cdecl render_format_005a0fbf(char* out, const char* format,
                                   std::uint32_t width,
                                   std::uint32_t height) {
    (void)formatter_entry_005a0fbf(out, format, width, height);
}
void __cdecl resource_format_drive_005a0fbf(char* out, const char* format,
                                            std::int32_t drive) {
    (void)formatter_entry_005a0fbf(out, format, drive);
}
void __cdecl resource_format_path_005a0fbf(char* out, const char* format,
    const char* first, const char* second) {
    (void)formatter_entry_005a0fbf(out, format, first, second);
}
void __cdecl startup_drive_format_005a0fbf(char* out, const char* format,
                                           std::int32_t drive) {
    (void)formatter_entry_005a0fbf(out, format, drive);
}
void __cdecl startup_command_format_005a0fbf(char* out, const char* format,
                                             const char* command) {
    (void)formatter_entry_005a0fbf(out, format, command);
}
void __cdecl file_format_005a0fbf(char* out, const char* format,
                                  const char* first, const char* second) {
    (void)formatter_entry_005a0fbf(out, format, first, second);
}
void __cdecl render_format_depth_005a0fbf(char* out, std::int32_t depth) {
    // Original caller pushes depth as one vararg and the indexed format string
    // at 005cf8bc contains no conversion: "Please set your display to 256 colors or higher.\n".
    (void)formatter_entry_005a0fbf(
        out, "Please set your display to 256 colors or higher.\n", depth);
}
void __cdecl render_loader_format_005a0fbf(char* out, const char* format, ...) {
    va_list args;
    va_start(args, format);
    formatter_forward_va(out, format, args);
    va_end(args);
}
void __cdecl game_setup_string_005a0fbf(char* out, const char* format,
                                        const char* base, char* scratch) {
    (void)formatter_entry_005a0fbf(out, format, base, scratch);
}
void __cdecl splash_progress_format_005a0fbf(char* out, const char* format, ...) {
    va_list args;
    va_start(args, format);
    formatter_forward_va(out, format, args);
    va_end(args);
}
void __cdecl render_depth_failure_00557370() {
    window_shutdown_process_exit_00557370();
}
}
