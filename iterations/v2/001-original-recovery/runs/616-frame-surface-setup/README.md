# Run616 frame surface setup (`00568f30`)

Bounded native x86-vs-C++ recovery proof for:
- `porsche::frame_pump_boundary_00568f30` (`00568f30..00569073`, 324B, sha256 `5e6b1d75fd6acadf6f6d18a792fc14c961c3e15f768f610d53e1c32a8642c40e`)

Reuses canonical declarations (`porsche/frame_pump.hpp`, `porsche/render_loader.hpp`, `../585-frame-interface-release/frame_interface_release_585.hpp`) and owns 7 loader-zero `.data` DWORDs (`0x006a5c84..0x006a5c9f`, 28 bytes).

## Verification

- Attempt `001` (`local/experiments/v2-frame-surface-setup-616/001/receipt.json`): **PASS**
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/616-frame-surface-setup/native-config.json --attempt 001`
  - `/Od` and `/O2` compiled cleanly (`/W4`) and compared relocated original x86 against C++ across `a5 != 0` early returns, `about[0x7c/4] != 7`, `GetState == 0`, null `dd_ptr`, `EnumModesSlot9` (`vtbl[9]`) with `dd_ptr` reload and zero/nonzero `second` results, and `CreateSurfaceSlot6` (`vtbl[6]`) across all 124 bytes (`31` DWORDs) of `ddsd`.
  - Mutation controls (`wrong-surface-state-final`, `wrong-about-magic-seven`, `wrong-ddsd-fourcc`, `wrong-ddsd-caps`) all exited `1` on `divergence`.

## Boundaries

Bounded test domain uses test-only storage and providers for `frame_pump_boundary_005693e0`, `render_thrash_exports_006bd910`, `frame_interface_*_006a5ca0..a8`, and DirectDraw-like `vtbl[9]`/`vtbl[6]`. Literal `callback_va` (`0x00569080`) is verified by value without execution; null `dd_ptr` with nonzero `frame_interface_second_006a5ca4` and production CMake/registry integration remain open.
