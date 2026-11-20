# Run708 scene texture callback leaf

- `porsche::scene_texture_callback_005556a0` (`005556a0..005556a9`, 10B, `__cdecl`, `ret 0`, sha256 `e2213ec12450612a229790db591f3bd5af47df349e8ddcf000fe7f99922900c8`): stores its argument into the loader-zero cell at `0x006a3a50` (canonical `render_texture_notify_callback_006a3a50`, Run575). No other state is read or written.

Ownership decisions:
- `005556a0`: newly owned here (function body only; the target cell is reused from Run575).
- `005a177b`: already defined in the game graph as `formatter_stdio_printf_005a177b` (`formatter_stdio.cpp`). Reused as canonical provider; not redefined. Run700's `scene_texture_alloc_report_005a177b` name is an alias view.
- `005a134b`: MSVC CRT `__RTDynamicCast` primitive (external), not game code; excluded from recovery. Run702 treats it as an opaque callee.

Native proof: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/708-scene-texture-callback-leaf/native-config.json --attempt 001` -> `local/experiments/v2-scene-texture-callback-leaf-708/001/receipt.json`, PASS, 4 cases, 2/2 mutations detected, both `/Od` and `/O2`.

Remaining boundaries: alias symbol availability for `scene_texture_alloc_report_005a177b` and `formatter_compare_005a134b` in the production link, live texture-pool state, and production CMake/registry integration remain open.