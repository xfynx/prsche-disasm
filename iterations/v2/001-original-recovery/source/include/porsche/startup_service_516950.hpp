#pragma once

namespace porsche {

// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
// The complete body at 00516950 is a single RET byte. Callers clean any
// arguments themselves; the machine-code adapter is compatible with the
// observed no-argument and caller-clean argument call sites.
void __cdecl startup_service_noop_00516950();

} // namespace porsche
