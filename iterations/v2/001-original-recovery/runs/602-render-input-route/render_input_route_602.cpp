// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 00586cd0..00586d0e, 63 bytes, sha256 4652d9a2bcf3728612a4d51f475b8136e751fc40648f5102352dfdbc9517db52.
#include "render_input_route_602.hpp"

namespace porsche {

RenderInputHandler_602 render_input_handlers_006ad440[65] = {};
std::uint8_t render_input_low_map_006ad544[256] = {};
std::uint8_t render_input_high_map_006ad644[256] = {};

std::uint32_t __cdecl render_input_dispatch_00586cd0(std::uint32_t event) {
    const std::int32_t signed_event = static_cast<std::int32_t>(event);
    std::uint32_t slot = 0u;
    if (signed_event < 0x100) {
        slot = render_input_low_map_006ad544[signed_event];
    } else if (signed_event < 0x10000) {
        slot = render_input_high_map_006ad644[signed_event >> 8];
    } else {
        return event;
    }
    if (slot == 0u) {
        return event;
    }
    const RenderInputHandler_602 handler = render_input_handlers_006ad440[slot];
    if (handler != nullptr) {
        handler();
    }
    return 0u;
}

} // namespace porsche
