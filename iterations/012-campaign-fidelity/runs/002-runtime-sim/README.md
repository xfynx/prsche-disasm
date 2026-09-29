# Run 002: original SIM runtime integration

Started 2026-09-26. Implementation checkpoint; iteration remains OPEN.

Computer Use recheck: importing `@oai/sky` succeeded, but `sky.list_apps()`
returned `spawn EPERM`. The separate `cua.getState()` returned empty app/browser
inventories. No original-game screenshots or native visual acceptance obtained.

## Changes

- Web career/free driving and the new Quick Race load the selected original SIM
  after the car model. Career/Quick Race reject missing, ambiguous or damaged SIMs.
  Exact SIM selection supports server files and user-selected files. A damaged-SIM
  browser case must keep the briefing open; retry with valid data must work.
- Corrected the starter JS profile's nonexistent `356road11` reference. Corrected
  Boxster catalog/0M01 to `boxster25`, backed by nfs5.car record 60
  (`1997Boxster25 / Boxster / Boxster25`). Other unproven mappings remain open.
- Quick Race: available track and catalog car/SIM pairs, 1/3/5 laps (sprint 1),
  0/3 opponents, fresh grid/countdown, restart, and no career rewards/profile changes.
  This is a testable standalone mode, not proof of original Quick Race rules/UI.
- Direction changes use horizontal motion, so vertical settling of a pitched car
  cannot keep reverse engaged after the ground motion has stopped. The new regression
  failed before the fix. Original Boxster held S/W passes at 30/60/120 Hz.
- AI kinematic yaw now matches its steering direction; lookahead on an open route
  clamps to its endpoint instead of wrapping to the start. Convergence tests cover
  tracks to the left/right and approaching a sprint endpoint.
- Fixed the 15-track audit's progress measurement: `find_closest_waypoint().1` is
  distance OFF the course. The old >50 m check rewarded leaving the route. It now
  uses `distance_along_course`; the threshold was not weakened. Earlier audit passes
  therefore do not establish correct AI path following.

## Verification

- `workspace-test.log`: 157 passed, 3 GPU ignored, including corrected installed
  15-track audit. Optional original-resource tests may skip when files are absent.
- `physics-final.log`: 11 vehicle tests passed before the final workspace run.
- `clippy.log`: workspace/all-targets `-D warnings` passed. Rustfmt and JS/UI checks passed.
- `build-release.log`: Windows and WASM release builds completed. Existing native
  PDB output-name collision/linker warning remains; it is not a compile failure.
- `browser-check.json`: final browser results; the full Chromium headless mode
  successfully exposes WebGPU here. It avoids OS focus changes during held-key tests.
  Final result: 19 checks passed, 0 JS/console errors, **1 known failure** in 0M01
  reverse→forward; verifier exits 1. An earlier headless run passed all 20, so this
  remains intermittent and cannot be attributed solely to OS focus.
  Cases cover SIM mass/name, corrupt-file rejection/retry, Factory→Quick Race state
  reset, original 356 A/Boxster, solo/three AI, laps, restart, unchanged profile and S/W.
- `web-quick-race-setup.png`, `web-quick-race-solo.png`, `web-quick-race-grid.png`:
  inspected setup and driving images. Layout/start are usable; no original-game
  visual fidelity or complete AI race finish is claimed.

Historical failures in this run are retained: `factory-reverse-failure.*`,
`factory-controls.json`, `browser-failure.json`, `web-failure.png`, and
`ai-steer-contract-failure.log`. Visible-browser runs failed on held input/changed
selection. A headless run passed, but the final headless run reproduced the mission
control failure; focus is not a sufficient explanation. The AI audit failure led to
the incorrect-metric discovery. `factory-controls.json` is the latest open failure.

## Remaining gaps and next work

Original mission rules, obstructed 0M01 camera and UI fidelity remain open. SCN
Start is a trigger center, not a proven spawn offset. FAC missions are still manually
cataloged; only reconstructed 0M01 goals run. Recover one mission end-to-end from
SCN/FAC/EXE before expanding the existing approximations.

AI still uses generic kinematics/profiles, not original AIS/AI CSV/BIN. Sprint
finish/stop semantics and campaign participant counts are unresolved; three AI is
an implementation limit, not an original-game rule. The old Evolution research note
also disagrees with the TRN parser and requires renewed source/consumer verification.

SIM drive flags, parts modifiers and some braking/aerodynamic/steering parameters
remain unused or hardcoded. Native CLI still uses model-table physics. SIM parsing
and the new web hookup do not amount to a faithful original physics engine.

## Repeat from repository root

```powershell
. ./scripts/tool-env.ps1
cargo test --locked --manifest-path iterations/012-campaign-fidelity/Cargo.toml --target-dir local/builds/012-campaign-fidelity/.cargo-target --workspace
cargo clippy --locked --manifest-path iterations/012-campaign-fidelity/Cargo.toml --target-dir local/builds/012-campaign-fidelity/.cargo-target --workspace --all-targets -- -D warnings
cargo fmt --manifest-path iterations/012-campaign-fidelity/Cargo.toml --all -- --check
node iterations/012-campaign-fidelity/web/ui.test.mjs
./scripts/build.ps1 -Iteration 012-campaign-fidelity -Config release -Target all
node iterations/012-campaign-fidelity/web/verify-browser.cjs C:/Users/steew/AppData/Local/ms-playwright-go/1.57.0/package auto iterations/012-campaign-fidelity/runs/002-runtime-sim
```
