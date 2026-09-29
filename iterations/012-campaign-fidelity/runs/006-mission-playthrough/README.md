# Run 006: complete 0M01 route and result flow

Started 2026-09-28. In progress; no agents assigned (prior usage limits).
Previous turn made progress: recovered trigger predicate wired into runtime,
169 Rust tests and 21 browser checks passed (Run 005).

Use an isolated Chromium profile and real keyboard input to traverse all six
source gates. Do not change timer, vehicle pose, physics or reward data in the
probe. Save failed attempts and distinguish controller errors from game errors.
Full original-fidelity/UI objective remains open.

## Source-surface failure and repair

Attempt 1 passed gate 1 at 3.42 s, then fell after leaving the Start sector:
at 4.27 s position was [1.45, -5.57, -102.99]. Timeout at 32.02 s,
one gate passed; zero JavaScript errors. See attempt-1/route-check.json.

`static-inventory.log` and `material-inventory.log` record the original static
CRP primitives before batching. mt53 spans all 42 flat pad sectors (140
triangles), including MESH18 at the fall location; mt54 is the outer sloping
rim. Selecting only MESH04 missed the rest and also selected a same-named
building, article 52. The loader now selects Skidpad source mt53/mt54 primitives
by the source-ID map, in addition to the existing RD* candidates. No synthetic
floor, friction meaning, or proven original collision-consumer claim is added.

Regression samples the route from Start through all six source gate centers,
including lateral offsets, checks the recorded fall location, excludes the
same-named building and verifies no rectangular floor outside the circular pad.
169 Rust tests passed, 3 GPU ignored; Clippy passed; Windows/WASM release built.
Logs: workspace-tests.log, surface-test.log, clippy.log, build-release.log.
Attempt 2 verifies the surface repair with real keyboard input: gates 1–4 at
3.42/6.91/12.21/18.72 s. No fall, zero JS errors, zero cone hits. It fails to
finish: the controller loses the return turn and times out at 32.01 s with
four gates. The profile is unchanged. The result screenshot was inspected:
failure speech/badge and retry/continue are visible, but not original UI fidelity.
Do not count this as a complete mission pass.

Reproduce (from root; Node may need its full installed path):
```
node iterations/012-campaign-fidelity/web/verify-factory-route.cjs C:/Users/steew/AppData/Local/ms-playwright-go/1.57.0/package iterations/012-campaign-fidelity/runs/006-mission-playthrough/attempt-3
```
Next: capture wheel/body orientation and controls during the return turn to
distinguish controller overshoot from physical rollover/yaw instability. Keep
the actual SCN goals/time limit/physics intact; preserve previous attempts.

Remaining: full mission completion, original bounds/contact fidelity, penalties
and result UI. Code inspection found that the result speech/sound is chosen
before the Rust cone-penalty evaluation; investigate after the driving probe.

## Return-turn diagnosis

Attempt 3 adds read-only wheel contact/forces, body up and actual steer angle.
It reproduces the failure: at 22.8 s the body up.y is -0.58, then reaches -1
(upside down), while the controller keeps trying to turn. This is a rollover,
not merely a mistaken target or missing pad surface.

Found reversed anti-roll forces in suspension.rs: the more compressed side
lost support, adding roll torque in the direction of the tilt. A static paired
test (bar on/off, both tilt signs) failed before the correction: roll -0.035 rad
received an additional -927.74 Nm. Reversed the four axle-side signs. The test
now requires a restoring torque and unchanged total vertical force; passed.
This repairs the reconstructed solver, not proof of original EXE physics.

170 workspace tests passed, 3 GPU ignored; Clippy passed; release Windows/WASM
built (workspace-anti-roll.log, clippy-anti-roll.log, build-anti-roll.log).
Attempt 4 uses the same keyboard controller/targets as 3 to isolate this change.
It still rolls over (now after gate 2), so the sign correction alone does not
resolve the driving failure. Do not report it as the complete cause/fix.

## Suspension contact geometry, 2026-09-29

Found a second independently reproducible error: suspension "raycast" projected
the vertical mount-to-ground vector onto body up instead of intersecting the
local down ray with the ground. At roll this shortens the measured distance,
increases compression incorrectly, and even allows inverted wheel contacts.
The tilted static fixture failed before the repair (ray-before.log).

RoadSurface now intersects the finite suspension ray with actual indexed source
triangles, considering cells crossed by the ray, front-side approach, limited
reach and penetration recovery. The flat CPU fixture uses the same ray/plane
distance. Tests cover tilt, inverted rejection, a ray entering a neighboring
cell where the vertical query misses, finite triangle boundaries, slopes and
penetration recovery. No synthetic game floor or pose correction was added.

172 workspace tests passed, 3 GPU ignored; Clippy passed; Windows/WASM built
(workspace-ray.log, clippy-ray.log, build-ray.log). Attempt 5 retains the same
controller and source mission to measure the effect. Original solver fidelity
and full mission completion remain separate open requirements.
Attempt 5 still rolls after gate 2. Once upside down it now loses tyre support
and falls: chassis-ground collision is not implemented. This is not a new hole
in the pad. The two mathematical fixes are verified individually but do NOT
constitute stable mission physics or a successful full playthrough.

Read-only SIM audit found a more fundamental input mismatch: all 86 installed
files have raw 0x10c in [1,2] and 0x110 in [1,2.5]; Boxster has 1/1.
The loader in EXE does multiply both by 0.001 (0x49c922..0x49c946, constant
0x5b3060), but our parser calls them front/rear track widths. Suspension clamps
the resulting 0.001 m to 1 m, so runtime uses unsupported narrow axle geometry.
The original meaning and geometry source must be recovered, not guessed.
Disassembly: sim-loader.asm and sim-derived.asm (next entry 0x49cb50).

Current next action: trace original 0x10c/0x110 consumers and wheel geometry;
repair SIM/model integration from that evidence, then repeat the mission.
UI penalty-result ordering remains pending. Overall iteration remains OPEN.
