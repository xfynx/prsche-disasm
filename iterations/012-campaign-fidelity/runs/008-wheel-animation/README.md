# Run 008 — model wheel geometry, animation and first mission

Started 2026-09-30 after published checkpoint cb07500. Updated 2026-10-03.
All implementation handoffs are complete; coordinator owns acceptance/publication.

Selected CRP Base domains 13/14, part metadata 10/77 and 10/78 identify actual
front/rear wheel articles in Boxster and 356a/b. Same-domain shadows have 11/186
or 11/187 and must remain outside rotating wheel groups. The source tr pivot
becomes body coordinates [-X,Y,Z]; wheel mesh membership survives loading.
Boxster track widths from these pivots: 1.3825873/1.4817582 m, wheelbase 2.4233546 m.
These are model measurements, not a claim that the EXE uses identical physics.

Vehicle adapter takes wheel X/Z and tire radius from the selected model;
vertical hardpoints and solver constants remain reconstructed. Telemetry wheel
matrices now locate the tire center rather than the contact patch. Source model
wheel vertices include billboard corners: rolling radius uses max absolute
local Y/Z, not their diagonal. Six local asset tests passed, including Boxster
pivots, physics integration and settled wheel centers above the road.

Shared native/browser rendering now separates the chassis and four wheel groups.
Player wheels use steering, signed rotation and suspension telemetry; AI wheels
use controller steering and traveled distance. Body origin and chassis contact
bounds follow visible source geometry, excluding wheel groups and shadow geometry.

Chassis contacts resolve against finite road triangles each physics substep.
Normal/friction impulses support an inverted or rolled car; a present but empty
surface never becomes a global y=0 floor. Tests cover a rotating roof impact at
20 m/s, settled roof/side support, road edge and upper/lower bridge separation.

Vehicle pairs use swept yaw boxes with height separation and two-body momentum
response, including player/AI and AI/AI. AI retains impact velocity across its
next controller step; restart clears it. Source bounds are used, but envelopes,
friction/restitution and AI kinematics remain reconstructed, not recovered EXE law.
Body deformation and angular response to car-car impacts are not implemented.

Factory result UI now evaluates penalties before selecting success/failure text,
sound and rewards. Unit tests include raw time inside the limit but penalized
time outside it; this is UI consistency, not proof of original penalty rules.

## Verification

- Workspace: 184 Rust tests passed, 3 GPU tests ignored (`workspace.log`).
- Final swept-overlap fix: 8 collision tests passed (`collision-final.log`),
  including one additional regression after that workspace run.
- Clippy, Rustfmt, UI state tests and Windows/WASM release build passed.
- `regression/browser-check.json`: 21 Chromium checks passed, no JS errors.
- `wheels/wheel-check.json`: actual wheel meshes, source pivots, spin and front
  steering verified through the final GPU matrices. `wheels-side.png` inspected.
- `contacts/contact-check.json`: real-keyboard Quick Race vehicle contact and
  restart verified; `car-contact.png` inspected. Contact law has CPU regressions.
- `attempt-1` and `attempt-2`: both reach 5/6 gates without rollover or floor
  penetration, then time out at the original 32-second limit. The second changes
  only keyboard driving, braking before the hairpin. Mission success remains open.

## Reproduce

```powershell
./scripts/build.ps1 -Iteration 012-campaign-fidelity -Config release -Target all
./scripts/launch-viewer.ps1 -Iteration 012-campaign-fidelity -Mode desktop
node iterations/012-campaign-fidelity/web/ui.test.mjs
node iterations/012-campaign-fidelity/web/verify-factory-route.cjs <playwright-package> <output> wheels
node iterations/012-campaign-fidelity/web/verify-factory-route.cjs <playwright-package> <output> contacts
node iterations/012-campaign-fidelity/web/verify-factory-route.cjs <playwright-package> <output>
```

Next: consult Run 009 indexes before further handling/mission changes; recover
the relevant original consumers and complete 0M01 within its unchanged rules.
