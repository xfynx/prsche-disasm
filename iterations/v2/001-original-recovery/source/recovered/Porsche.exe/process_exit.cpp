#include "porsche/process_exit.hpp"
#include "porsche/exit_shutdown.hpp"

namespace porsche {
[[noreturn]] void __cdecl process_exit_005a246e(std::uint32_t code) {
    exit_shutdown_execute_005a2490(code, 0, 0);
    // The recovered OS boundary must not return. Test fixtures signal this
    // terminal edge with a controlled exception before execution reaches here.
#if defined(_MSC_VER)
    __assume(0);
#else
    for (;;) {}
#endif
}
}
