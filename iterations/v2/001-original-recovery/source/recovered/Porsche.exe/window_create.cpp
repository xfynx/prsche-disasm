#include "porsche/window_create.hpp"

namespace porsche {
OriginalWindowConfiguration window_configuration_storage_006b77a0{};
std::uint32_t& window_running_006b7c14=window_configuration_storage_006b77a0.running_006b7c14;
std::uint32_t& window_width_006b77b4=window_configuration_storage_006b77a0.width_006b77b4;
std::uint32_t& window_height_006b77b8=window_configuration_storage_006b77a0.height_006b77b8;
std::uint8_t& window_fullscreen_006b7c01=window_configuration_storage_006b77a0.fullscreen_006b7c01;
void*& window_hwnd_006b7bf8=window_configuration_storage_006b77a0.hwnd_006b7bf8;
void* class_lock_0069e59c=nullptr;
std::uint32_t class_refcount_0069e594=0;
const char** class_name_override_006afcc0=nullptr;
std::uint32_t window_handlers_registered_0069e598=0;
void* window_input_lock_0069e564=nullptr;
std::uint32_t window_input_capacity_0069e560=0;
std::uint32_t window_input_read_0069e0d8=0;
std::uint32_t window_input_write_0069e568=0;
void* window_thread_handle_0069e574=nullptr;
std::uint32_t window_worker_state_006bd9e0[7]{};
std::uint32_t window_saved_parameter_0069e57c=0;
std::uint32_t window_saved_parameter_0069e580=0;

// 0053ac20..0053ad23. Deliberately ends at the beginning of the following
// renderer/input setup. It does not assert recovery of all 1056 bytes.
bool __cdecl window_register_prefix_0053ac20() {
    if (!class_lock_0069e59c) class_lock_0069e59c=window_lock_create_005321f0();
    const std::uint32_t previous=class_refcount_0069e594++;
    if (previous) return true;
    window_instance_006b7794=window_module_handle(nullptr);
    if (!window_class_name_0069e5a8)
        window_class_name_0069e5a8=class_name_override_006afcc0?*class_name_override_006afcc0:"DLL";
    OriginalWndClassA cls{};
    cls.style=0xb;
    cls.procedure=reinterpret_cast<void*>(&window_procedure_0053aba0);
    cls.instance=window_instance_006b7794;
    cls.icon=window_load_icon(cls.instance,reinterpret_cast<const char*>(0x7f00));
    cls.cursor=window_load_cursor(nullptr,reinterpret_cast<const char*>(0x7f00));
    cls.background=window_stock_object(4);
    cls.menu_name=window_class_name_0069e5a8;
    cls.class_name=window_class_name_0069e5a8;
    if (!window_register_class(&cls)) {
        class_error_file_005deb74=0x5bb8d4;
        class_error_line_005deb78=0x38f;
        window_register_diagnostic("GRAPH_init - FAILED WINDOWS CALL REGISTERCLASS (%d)",window_last_error());
        class_refcount_0069e594=0;
        return false;
    }
    return true;
}

}
