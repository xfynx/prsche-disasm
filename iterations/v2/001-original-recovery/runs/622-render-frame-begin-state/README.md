# Run622 render frame begin state (`00534540`, `00535a90`)

Bounded native x86-vs-C++ recovery proof for:
- `porsche::game_setup_draw_begin_00534540` and `porsche::splash_progress_driver_frame_begin_00534540` (`00534540..0053454b`, 12B, sha256 `a24b8810ee0261f826f3539727ca897e3f3fd094c494fa4cb88eabb9bfbc4c15`), owning the 44B `.data` block `render_frame_begin_descriptor_005de680` (`005de680..005de6ab`, sha256 `220c387157e14d3be6c2715c7a6a737fbc0e32f0d1f11763ea4db572f1b5f69c`)
- `porsche::render_resource_texture_state_00535a90` (`00535a90..00535af7`, 104B, sha256 `79cb8e354813241bd94bcf84855d3a7f8039c7b1a1a30680c164a5931d39c174`, 0B new data)

Reuses canonical declarations (`porsche/game_setup.hpp`, `porsche/splash_progress.hpp`, `porsche/window_shutdown.hpp`, `porsche/render_settings.hpp`, `render_descriptor.hpp`, `render_state_flush_527.hpp`, `render_resource_533.hpp`).

## Verification

- Attempt `001` (`local/experiments/v2-render-frame-begin-state-622/001/receipt.json`): **PASS**
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/622-render-frame-begin-state/native-config.json --attempt 001`
  - `/Od` and `/O2` both compiled cleanly (`/W4`) and printed `render_frame_begin_state_original_x86_vs_cpp=PASS cases=1800 events=1800`, comparing relocated original x86 against C++ for `00534540` (both `game_setup_draw_begin_00534540` and `splash_progress_driver_frame_begin_00534540`, including untouched initial 44B `.data` `005de680..005de6ab` and 12th-DWORD `005de6ac` staging) and `00535a90` (`fallback == 0` passthrough and `fallback != 0` across `stage` in `0..1`, record `[+11/+12/+13]` combinations, key masking, and full 32-bit `EAX` return).
  - Mutation controls (`wrong-tail-sync`, `wrong-fallback-bypass`, `wrong-key-mask`, `wrong-stage-stride`, `wrong-record-offset`) all exited `1` on `divergence`.

## Boundaries

- `00535a90` remains `PARTIAL` outside `stage` in `0..1`: out-of-range and negative `(key >> 16)` stage values index past `render_state_flush_records_005de6bc[0..27]` and remain outside this bounded proof domain.
- Bounded test domain uses test-only storage and providers for `window_shutdown_state_005de6ac`, `render_descriptor_bind_00534480`, `render_state_flush_records_005de6bc`, `render_resource_texture_fallback_0069dd1c`, and `render_settings_set_state_006bd97c`. Production CMake/registry integration remains open.
