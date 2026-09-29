# Run 003: Factory input and scenario diagnostics

Started 2026-09-26; integration checkpoint 2026-09-27. Iteration 012 remains OPEN.

Investigate intermittent 0M01 reverse→forward failure with recorded keys/focus,
actual viewer input, pose and scenario state. Independent read-only investigation
identifies the source geometry occluding the start camera. No arbitrary spawn
offset or hidden geometry is accepted as a fidelity fix.

## Reproduced before the wheel fix

- `input-baseline`: 2/4 attempts failed returning from reverse. `KeyW`, focus=true,
  visible document and actual `viewer.update_car(dt, 1, 0, false)` exclude lost input.
- `before-wheel-fix`: another 2/4 failed after adding read-only wheel telemetry.
  At failure all wheels contact; body vz≈-0.935 m/s. Front omega≈-4.61 rad/s and
  longitudinal force≈+2299 N, rear omega≈+6.34 and force≈-3223 N. Wheel rotation
  alternates signs under braking, maintaining backward ground motion.
- A tire regression fails before the fix: omega=-2, brake=10000, dt=1/240 produces
  omega=+32.72222. Braking alone injects rotation instead of stopping at zero.
  An airborne wheel with drive=0 also receives no effective braking in the old code.
- Camera occluder independently identified as SCN `L A` / ARW1, CRP article 207
  `arrow`; original scale/visibility/spawn semantics are still being investigated.
  See `../../research/0m01-occlusion.md`.

## Tire fix and narrow acceptance

`Tire::integrate_rotation` now applies external torque, then dissipates angular
momentum by at most the brake impulse; the brake cannot cross zero and create
opposite rotation. Grounded and airborne tires use the same rule. New tests cover
both signs, 240/480/960 Hz, modest braking, and drive torque exceeding the brake.
SIM and coefficients are unchanged. Original Boxster/356A braking remains
43.3/54.7 m from 100 km/h in the calibration test.

After the fix, `factory-check.json`: 8/8 complete forward→reverse→forward cycles
passed, no page errors. `factory-trace-1..8.json` contain keys/focus/actual input,
pose/velocities and per-wheel contact/omega/load/force. The root failure PNGs are
historical; baseline copies above preserve the failed version. A full browser and
workspace acceptance is recorded below.

## SCN integration and original behavior evidence

The v4 GEOM consumer at EXE 0x46a644..0x46a7e9 proves that parameter 7 is a
signed 16-bit scale percentage. The parser retains version/raw parameters and
the loader applies that scale to all three basis axes, preserving translation.
Tests cover version layouts, signed truncation, and original Skidpad arrows
41/49/55/42/100 percent. Version 5 float parameters are preserved, but its
separate-axis scale is not yet applied.

The camera occluder is L A / ARW1, article 207 `arrow`, whose scale is 100%.
Its size therefore remains unchanged. Further EXE tracing proves that
`animdefs.txt` supplies `triggerable`, all such instances are initially hidden,
and trigger links select individual geometry. This behavior is not yet wired
into runtime; first-frame activation, exact spawn and camera remain unresolved.
Evidence: [occlusion](../../research/0m01-occlusion.md) and
[activation](../../research/0m01-arrow-activation.md).

## Integration checks

- Rust workspace: 162 passed, 3 GPU ignored; `workspace-tests.log`.
- Clippy with `-D warnings`, rustfmt check and UI state tests passed.
- Release Windows and WASM builds passed; `build-release.log`.
- Full Chromium: 20 checks passed, no JS errors, no known failures; `browser-check.json`.
  Includes 0M01 and Quick Race held S/W transitions, source SIM application,
  damaged SIM rejection, career navigation, laps/grid/restart/profile isolation.
- Inspected `web-factory-mission-drive.png`: L A still occludes the camera.
  Visual/original-fidelity acceptance remains OPEN; passing checks do not close it.
- Frozen snapshots 001–011 have no tracked changes. No original game data was written.

Commands from the repository root are maintained in `../../PLAN.md`. Next:
trace 0x4108a7–0x4108c2 before implementing first active arrow selection, then
wire animdefs metadata and ordered SCN trigger links into scenario runtime.
