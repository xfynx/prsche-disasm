#include "porsche/application_instance.hpp"
#include "porsche/window_create.hpp"
#include "porsche/window_runtime.hpp"

namespace porsche {
void* application_instance_mutex_006a5c28=nullptr;
std::uint32_t application_instance_exit_requested_005df9bc=0;

std::uint32_t __cdecl application_instance_check_005655f0(const char* name) {
    auto* selected_name=window_class_name_0069e5a8;
    if (!selected_name) {
        if (name) {
            selected_name=const_cast<char*>(name);
            window_class_name_0069e5a8=selected_name;
        } else {
            selected_name=const_cast<char*>(*class_name_override_006afcc0);
            window_class_name_0069e5a8=selected_name;
        }
    }
    if (!name) name=selected_name;

    application_instance_mutex_006a5c28=
        application_instance_create_mutex(nullptr,1,name);
    const auto last_error=application_instance_get_last_error();
    if(last_error!=183)return 0;

    auto* window=application_instance_find_window(nullptr,window_class_name_0069e5a8);
    if(window) {
        application_instance_show_window(window,9);
        application_instance_set_foreground_window(window);
    }
    if(application_instance_exit_requested_005df9bc) {
        // Original 00557370 executes PUSH 0; CALL 005a246e. The call is
        // terminal in the game; a returning fixture only records the boundary.
        application_instance_exit_005a246e(0);
        return 0;
    }
    return 1;
}
}
