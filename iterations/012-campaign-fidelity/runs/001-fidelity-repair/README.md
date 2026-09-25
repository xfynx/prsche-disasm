# Run 001: campaign fidelity repair

Started 2026-09-25; checkpoint updated 2026-09-26. Iteration remains OPEN.
The work continued without native Computer Use. Automated checks pass; visual fidelity does not.

## Changes

- Contact damping now uses mount velocity; a RoadSurface miss does not invent a y=0 floor.
  Corrected front/rear axle arms for the intended rear static weight bias. Held S brakes to
  a full stop before reverse, with W providing the symmetric transition back to forward.
- Calibration checks horizontal speed, pitch, contact and height throughout braking.
  Local SIM lookup now uses the manifest-rooted game path and reports real versus fallback data.
- 0M01 reset uses the sourced SCN Start and MESH04 pad. An ordered waypoint 1–5 → End route
  replaces generic LSP completion for Factory; timeout ends the attempt, unsupported goals
  cannot award progression. Route semantics remain a reconstruction pending original/EXE evidence.
- Evolution opens its tournament selection and excludes Factory portrait/map imagery.
  Factory briefing uses a partial 640x480 layout from LAY. Original rooms/fonts/layers remain missing.
- scripts/extract-fe-ui.ps1 reproducibly writes 119 PNGs to local/derived/fe-ui; the local helper
  serves them at /assets/. No game resources are committed. Duplicate FSH IDs keep the last source
  entry as in the inherited extractor, with the selection logged.
- Root README/PLAN/STATUS, roadmap, launch/build defaults and CI now point to active 012.

## Verification

- workspace-test.log: 151 tests passed (68 assets unit + 6 assets integration, 35 formats,
  21 game, 21 viewer); 3 GPU tests ignored. Optional corpus tests may skip absent resources;
  this count is not proof of complete resource/behavior coverage.
- calibration-real.log: installed 356Acoupe16.sim and boxster25.sim were parsed. Braking from
  100 km/h: 356 54.7 m / 3.92 s; Boxster 43.3 m / 3.08 s. Upright/contact/height checks passed.
  Historical physics.log, test.log and braking-diagnostic.log preserve earlier findings/failures;
  the former 26.2 m value was a false stop while the car had pitched nearly vertical.
- clippy-final.log: workspace/all-targets -D warnings passed. cargo fmt --all -- --check passed.
- UI state tests, verifier syntax, and scripts/test_iterations.py passed.
- extract-ui.log: 119 PNG files regenerated successfully.
- build-release.log: Windows executable and WASM release package built successfully.
- browser-check.json: Chromium 143.0.7499.4, 14 checks, zero page/console errors. Real keyboard
  input checked left/right for sim and arcade, held S to reverse and W back to forward, menus/HUD,
  catalog changes, career separation and SCN Start/support with no instant victory. This does not
  establish a correct full 0M01 playthrough or visual fidelity.

## Visual inspection: NOT accepted

The coordinator inspected web-factory-briefing.png and web-factory-mission-drive.png.
The briefing has a neutral placeholder background and replacement typography, so is not 1:1.
The initial mission frame is heavily occluded by black/yellow scene geometry in front of the
camera. The exact source object and original staging offset/camera still need investigation.
The automated verifier missed that obstruction; passing telemetry checks do not override it.
Canyon checks establish successful loading/finite altitude, not a complete contact audit.

## Exact commands and continuation

Run from the repository root. The tool environment adds Cargo and the installed Node runtime.

```powershell
. ./scripts/tool-env.ps1
cargo test --locked --manifest-path iterations/012-campaign-fidelity/Cargo.toml --target-dir local/builds/012-campaign-fidelity/.cargo-target --workspace
cargo test --locked --manifest-path iterations/012-campaign-fidelity/Cargo.toml --target-dir local/builds/012-campaign-fidelity/.cargo-target -p nfs-assets --test calibration_bench -- --nocapture
cargo fmt --manifest-path iterations/012-campaign-fidelity/Cargo.toml --all -- --check
cargo clippy --locked --manifest-path iterations/012-campaign-fidelity/Cargo.toml --target-dir local/builds/012-campaign-fidelity/.cargo-target --workspace --all-targets -- -D warnings
node iterations/012-campaign-fidelity/web/ui.test.mjs
./scripts/extract-fe-ui.ps1
./scripts/build.ps1 -Iteration 012-campaign-fidelity -Config release -Target all
& 'C:/Users/steew/AppData/Local/ms-playwright-go/1.57.0/node.exe' iterations/012-campaign-fidelity/web/verify-browser.cjs C:/Users/steew/AppData/Local/ms-playwright-go/1.57.0/package auto iterations/012-campaign-fidelity/runs/001-fidelity-repair
```

All agent assignments are finished. T01–T04 remain partial. Continue from the active PLAN:
original reference captures, occluded start camera and exact spawn, runtime car_sim integration
(the current renderer still substitutes model tables), original UI rooms/fonts and mission rules.

Computer Use configuration had stale SKY pipe environment overrides removed, but the running MCP
kept the old environment. Backup: ~/.codex/config.toml.backup-computer-use-20260925-034039.
Fresh-process native access is not verified. See docs/computer-use-recovery.md after reconnecting.
