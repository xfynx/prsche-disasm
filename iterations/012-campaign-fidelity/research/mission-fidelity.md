# Factory Driver 0M01: scene and start evidence (2026-09-25)

## Confirmed resources

- `local/game/FEData/Data/nfs5.fac`, record 0 (240 bytes): code `0M01`, track ID 13 (`skidpad` in `nfs5.trk`), time limit 32 s. Briefing string 3001 names the Boxster and driving around cones. The FAC record has no proven world-space car spawn or SCN filename field.
- `local/game/GameData/Track/skidpad_st1.scn` (SHA-256 `b51e443e2fb2e27d3927c3752a85554f1ab417ee207c6bedca7ef9cd79348c2`) contains cone geometry and named `Start`, waypoint, and `End` triggers. `Start` center is source `(-6.844955, 0, 147.240662)`, direction `(0, 0, -1)`; scene conversion negates Z, giving `(-6.844955, 0, -147.240662)` and forward `+Z`. `End` center is source `(-6.805335, 0, 144.493317)`. The UI currently selects this SCN for `0M01` by filename convention; an executable linkage to this exact file remains unproven.
- `skidpad0.lsp` (SHA-256 `35c53b7b75aff8e6b01e6a8806848e8ebec8749e936a07c2ffc61bf6d1ff99a9`) begins near source `(223.3966, 0)`. Its generic grid slot is unrelated to the named mission `Start` trigger.
- The SCN Start center has no support from `RD*` articles. It lies on the flat static `skidpad.crp` article `MESH04`, index 4, primitive 0, triangle 0, height 0. Its four accepted triangles span scene X `[-11.91, 75.08]`, Z `[-196.73, -112.55]`. This exact source geometry is now included in the Skidpad support query.

## Current implementation and limits

- The selected SCN's `Start` center and direction are carried through the scene loader. Factory mission reset places the car there, projects onto static support, and raises the simulation body by its computed resting height. This is a source-backed course anchor, **not a proven exact original car staging position or offset**. Other modes retain their prior start selection.
- The SCN records waypoint trigger indexes 1–5, then `End` index 6. Each record supplies a center, two segment endpoints, and an additional numeric field (1.0 for waypoints; 8.5 for End) interpreted here as the short side of a rectangle. The implementation requires forward entry through these rectangles in source order. Forward direction is inferred from successive trigger centers. This is a **reconstruction hypothesis** for mission progress, not a recovered EXE contract for trigger volume or vehicle shape.
- Factory mission simulation now ignores generic LSP lap completion. `0M01` is the only supported scenario route, and only when `skidpad_st1.scn` was selected. The route reaches success after ordered waypoint→End traversal within 32 s; exceeding the time limit ends it as a failure. Other missions expose goal support as false and cannot receive a fabricated generic-lap victory. Browser glue must call `configure_mission_code(code)` after `configure_mission(...)`, then `restart_race()`, and must award only when `get_mission_goal_supported()` and `get_mission_goal_reached()` are true.
- SCN cone instances are visible, but their collision shapes, penalties, and progression rules have not been proven from executable behavior.

## Narrow checks

Before the route change, `cargo test -p nfs-formats scn::tests` passed (2 tests) and `cargo test -p nfs-assets local_skidpad_loads_with_scenario_and_sky` passed after adding sourced MESH04 support. Route tests cover ordered entry, early End, reverse entry, side miss, and reset. Rust checks for the route change are pending while the shared target is in use elsewhere.
