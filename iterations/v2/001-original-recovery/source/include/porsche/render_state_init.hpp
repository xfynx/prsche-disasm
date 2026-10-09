#pragma once

#include "porsche/render_mode.hpp"

namespace porsche {
// Porsche.exe SHA256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
// Original VA 0x0044f020; canonical state/settings storage belongs to Run063.
// The original caller ignores EAX; this recovered boundary exposes only its
// caller-visible state effects.
void __cdecl render_mode_update_alternate_0044f020();
}
