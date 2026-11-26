// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
#include "session_reset_gate_856.hpp"

namespace porsche {

const void* session_reset_payload_005e66b0 = nullptr;
SessionResetObject0040e3b0* session_reset_object_005e752c = nullptr;

void __cdecl frame_reset_service_004030b0() {
    const void* const payload = session_reset_payload_005e66b0;
    if (payload != nullptr && global_00657414 != 0u) {
        session_reset_children_0040e3b0(session_reset_object_005e752c, nullptr, payload);
    }
}

} // namespace porsche
