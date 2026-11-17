# Run601 render display apply (`004b70d0`, `0056a680`)

Bounded native x86-vs-C++ recovery proof for `porsche::render_display_apply_004b70d0`
and `porsche::render_frame_timer_reset_0056a680` (`Porsche.exe` SHA-256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`):

- `004b70d0..004b713f` (112 bytes, sha256 `f66b33262c7e8c7359db1375edf07762afb70f3a097fc2a7f7c2e386538635d2`)
- `0056a680..0056a6a5` (38 bytes, sha256 `bc9d060f3142e5d9c77ac11fd7ab813c7024df413694c2aa55e4e8381aa28cd8`)

## Verification

- Attempt `001` (`local/experiments/v2-render-display-apply-601/001/receipt.json`): **PASS**
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/601-render-display-apply/native-config.json --attempt 001`
  - `/Od` and `/O2` both printed `render_display_apply_original_x86_vs_cpp=PASS cases=285 events=280`,
    comparing relocated original x86 against C++ for both `render_frame_timer_reset_0056a680`
    (5 cases) and `render_display_apply_004b70d0` (280 cases across varied `field7c`, `field74`,
    `current_tick_006b7c40`, `render_display_step_base_005e5184`,
    `render_display_texture_height_005deacc`, x87 precision/rounding/depth), verifying all
    14 globals, captured `0x00516950` stack args `(stack[1], stack[2], stack[3])`, ABI, and
    `FXSAVE`/MXCSR.
  - Mutation controls (`wrong-scale-x-constant`, `wrong-noop-third-arg`,
    `wrong-offset-y-sign`, `wrong-timer-tick-clear`) all exited `1` on `divergence`.

## Boundaries

Test-only providers stand in for `current_tick_006b7c40`,
`render_display_texture_height_005deacc`, `startup_service_noop_00516950` (capturing
`stack[1..3]` via `_AddressOfReturnAddress()`), and `audio_stream_ftol_005a0f98`
(exact x87 chop rounding); broader caller integration, arbitrary aliases, and
production CMake/registry wiring remain open.
