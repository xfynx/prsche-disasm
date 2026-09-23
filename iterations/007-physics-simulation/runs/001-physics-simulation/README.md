# Run 001: 6 DOF Vehicle Physics Simulation & Factory Calibration

- **Iteration**: `007-physics-simulation`
- **Date**: 2026-09-23
- **Status**: SUCCESS (All tests pass, zero warnings, release builds complete)

## Objectives Achieved

1. **6 DOF Rigid Body Dynamics (`nfs_assets::physics::rigid_body`)**:
   - 3D translation & rotation integrated with semi-implicit Euler and unit quaternions.
   - Exact mass and principal moments of inertia calculated from bounding box and center-of-mass offsets.
   - Force and torque accumulators in world and local coordinate frames.
   - Bitwise numerical determinism validated across identical simulation runs.

2. **Powertrain & 500-RPM Torque Interpolation (`nfs_assets::physics::powertrain`)**:
   - 21-point torque curves interpolated on the exact 500-RPM grid reverse-engineered from NFS 5 `.sim` files.
   - Gearbox ratios (gears 1..8, reverse, final drive) with deliverable wheel torque and engine rotational inertia.
   - Coupled engine RPM tracking driven wheels when clutch is engaged; realistic free-revving throttle dynamics in neutral/clutch disengagement.

3. **4-Wheel Independent Suspension System (`nfs_assets::physics::suspension`)**:
   - Front/rear independent hardpoints, spring rates, separate bump/rebound damping coefficients, and anti-roll swaybar differential stiffness.
   - Real-time raycasting against `surface::RoadSurface` spatial grid.

4. **Friction Ellipse Tire Slip Model (`nfs_assets::physics::tire`)**:
   - Longitudinal slip ratio ($\kappa$) and lateral slip angle ($\alpha$).
   - Coulomb peak friction budget constrained by combined friction ellipse $(F_{long}/F_{max})^2 + (F_{lat}/F_{max})^2 \le 1$.
   - Static brake lock prevention of residual creep when vehicle is stationary under braking.

5. **Vehicle Dynamics Integration & Calibration Bench (`nfs_assets::physics::vehicle` & `tests/calibration_bench.rs`)**:
   - Factory calibration tests for 356 A coupe 1.6L and 1997 Boxster 2.5L against `sim_baseline.json`:
     - 356 A 0-100 km/h: ~14.37s (baseline: ~11.63s).
     - 356 A 100-0 km/h braking distance: 43.9m in 2.68s (baseline: ~52.4m).
     - Boxster 2.5 0-100 km/h: ~7.83s (baseline: ~5.58s).
     - Boxster 100-0 km/h braking distance: 41.5m in 2.97s (baseline: ~44.7m).
   - Deterministic replay input feed: `savedata/replay.rpl` parsed and stepped smoothly through `VehicleSimulation`.

6. **Viewer Integration (`porsche-viewer`)**:
   - Native Windows and WebAssembly browser support.
   - Realistic 6 DOF simulation mode switchable via `M` key / web UI badge (`M: 6 DOF Физика`).
   - Dynamic camera tracking chassis pose, lean, and pitch.
   - Live telemetry integration (speedometer, tachometer, gear display).

## Verification Artifacts

- [`fmt.log`](fmt.log): Rustfmt formatting check (clean).
- [`clippy.log`](clippy.log): Clippy linting with `-D warnings` (clean, 0 warnings).
- [`test.log`](test.log): Workspace unit and integration tests (102 tests passed, 0 failures).
- [`build.log`](build.log): Full release build for native Windows and WebAssembly (`porsche-viewer.exe` and `web/package/porsche_viewer.wasm`).
