#include "porsche/exit_shutdown.hpp"

#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <iostream>

int main(int argc, char** argv) {
    if (argc != 3) return 125;
    const auto code = static_cast<std::uint32_t>(std::strtoul(argv[2], nullptr, 0));
    if (std::strcmp(argv[1], "exit") == 0) {
        std::cout << "exit\n" << std::flush;
        porsche::exit_shutdown_exit_process(code);
    } else if (std::strcmp(argv[1], "terminate-self") == 0) {
        void* process = porsche::exit_shutdown_get_current_process();
        std::cout << "handle:" << reinterpret_cast<std::uintptr_t>(process)
                  << '\n' << std::flush;
        (void)porsche::exit_shutdown_terminate_process(process, code);
    }
    return 126; // The tested successful terminal calls must never reach here.
}
