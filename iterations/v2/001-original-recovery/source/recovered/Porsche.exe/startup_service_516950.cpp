#include "porsche/startup_service_516950.hpp"

namespace porsche {

// 00516950: C3 RET. This exact leaf preserves all GPRs and EFLAGS and only
// consumes the return address; caller-owned arguments remain on the stack.
__declspec(naked) void __cdecl startup_service_noop_00516950() {
    __asm ret
}

} // namespace porsche
