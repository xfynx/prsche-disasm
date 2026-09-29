# Run 005: original start and trigger contract

Started 2026-09-27. In progress; iteration remains OPEN.
Previous turn made verified progress: original arrow metadata/link selection,
unobstructed start frame, real first-gate/restart test (Run 004).

Checkpoint 2026-09-28: both agents stopped with usage-limit errors; no live
assignments. Their delivered evidence was preserved; runtime still matches
verified Run 004. Original resources read-only, frozen snapshots unchanged.

- `research/0m01-start-pose.md`: direct setup uses SCN center and second
  direction vector; no fixed longitudinal offset in that path. Later contact
  solver modifies XYZ, so final original position remains unverified.
- `research/trigger-car-diagonals.md`: recovered type/sequence dispatch,
  zero-vector direction bypass, speed comparisons, and shape-1 intersections
  with current car diagonals. Current inferred forward-entry restriction and
  point-sweep geometry differ from the EXE. Worker formulas/addresses saved
  explicitly; no original-fidelity claim from tests of the earlier model.

## Implementation checkpoint, 2026-09-28

Replaced point-sweep/rectangle/inferred direction with the recovered shape-1
two-diagonal predicate, ±3.5 height check, optional source heading/velocity dot
constraints and strict speed bounds. Recovered original speed producer:
max(|vx|,|vz|)+0.25*min(|vx|,|vz|). SCN type/sequence drive progression and End;
negative sequence values use the source signed-word behavior.

Vehicle dimensions come from the loaded visible model at driving scale, with
the current simulation pose/velocity. This is an explicit adapter: the exact
original bounds-object selection/body origin/contact correction remains open.
No model means no supported mission route. The +0x518 special resource flag is
not yet available to the loader; normal adapter uses false, its expanded-pair
math is tested separately. Full mission penalties/results are not proved.

- Workspace: 169 passed, 3 GPU ignored (`workspace-tests.log`).
- SCN tests passed after extra version/sequence assertions (`scn-tests.log`).
- Clippy `-D warnings`, fmt and UI state checks passed.
- Windows/WASM release build passed (`build-release.log`).
- Chromium: 21 checks passed, 0 errors/known failures (`browser-check.json`).
  First gate increments while the center is still before the source segment;
  its arrow switches, restart restores count 0/Arrow 1. Nearby End does not
  finish before waypoints. Existing career/Quick Race checks passed.
- Inspected `web-factory-arrow-waypoint.png`: car/road visible, next arrow active.
- Frozen 001–011 show no tracked changes; original data was only read.

No complete 0M01 playthrough or original visual comparison is claimed. Next:
selected bounds getter and body/model origin, then complete mission drive and
original penalties/results. Overall campaign/UI objective remains OPEN.
