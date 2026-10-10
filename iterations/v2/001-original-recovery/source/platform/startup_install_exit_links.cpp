#include "porsche/application_instance.hpp"
#include "porsche/install_paths.hpp"
#include "porsche/process_exit.hpp"
#include "porsche/render_display.hpp"
#include "porsche/startup_services.hpp"

#include <cstdint>

namespace porsche {

[[noreturn]] void __cdecl startup_exit_005a246e(std::uint32_t code) {
    process_exit_005a246e(code);
}

[[noreturn]] void __cdecl render_driver_failure_005a246e(std::uint32_t code) {
    process_exit_005a246e(code);
}

[[noreturn]] void __cdecl application_instance_exit_005a246e(
    std::uint32_t code) {
    process_exit_005a246e(code);
}

// Original 004a5410 invokes this zero-argument initializer and ignores EAX.
void __cdecl startup_subsystem_004b6ff0() {
    (void)install_paths_load_004b6ff0();
}

} // namespace porsche
