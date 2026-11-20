// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "../400-frame-loop-clusters/frame_loop_clusters_400.hpp"
#include "../676-startup-input-slot-and-math-leaves/startup_input_slot_math_676.hpp"
#include "../683-input-ff-slot-callers-and-render-leaves/input_ff_render_leaves_683.hpp"
#include "../688-frame-control-create-and-gain/input_ff_frame_control_688.hpp"
#include "porsche/input_state.hpp"

namespace porsche {

// Owned zero-initialized .bss block 005e9408..005e953b (0x134 bytes). It
// supplies the physical storage for the frontier names declared by Run400
// (005e940c enabled, 005e9410 index, 005e9420[4] word table) and extends the
// word table to its full original 32-entry / 0x100-byte extent. Single-storage
// reconciliation with those Run400 extern names is an integration boundary;
// this TU allocates the block exactly once.
extern std::uint8_t frame_control_ff_state_005e9408[0x134];

// Opaque BSS configuration cells read by 00411d20. Each is a 4-byte loader-zero
// cell with no prior owner in the manifest closure; writers are unindexed.
extern std::uint32_t ff_init_gain_00657bc8;
extern std::uint32_t ff_init_config_00657be8;
extern std::uint32_t ff_init_config_00657c08;
extern std::uint32_t ff_init_config_00657c28;
extern std::uint32_t ff_init_config_00657c48;

// Original 00411d20..00412020 (769B, __cdecl, ret 0; void). Selects the first
// force-feedback-capable input device, creates four effects through the
// accepted 005334e0 provider, stores their word results in the frame-control
// table and applies the configured gain through the accepted 005333a0 provider.
void __cdecl ff_effect_initialize_00411d20();

} // namespace porsche
