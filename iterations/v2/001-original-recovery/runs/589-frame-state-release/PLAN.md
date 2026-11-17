# Run589 frame state release

## Goal and criteria
- Recover original `005363a0..00536451` (178 bytes, sha256
  `4317a6d2d78522e8b3b4a2b34d39961d5a73ce36fb94972a7510fdae7c7a03bf`) as
  `porsche::startup_lifecycle_apply_raw_005363a0` (`__fastcall`) and
  `porsche::frame_pump_boundary_005363a0` (`__cdecl`), reusing `527`/`570`/`572`
  canonical headers without redefining external symbols in production `.cpp`.
- Pass `verify-v2-native-batch.py --attempt 001` at `/Od` and `/O2` with material
  mutation controls.

## Verified facts
- Cached REA dossier (`local/experiments/v2-frontier-469-rea/001/function-005363a0.json`,
  evidence `ev_8b8e774c39beabcbb433e7f71aba20f33cbabaacfd5ed35c86a3d6a503a4dd33`) and
  PE bytes confirm two 7-callback flush passes over `005de6bc`/`005de72c`, gate check on
  `005de6b8`/`0069dd1e`, and ordered `00555440` releases with live reload of `[receiver+12]`.
- Native `001` (`local/experiments/v2-frame-state-release-589/001/receipt.json`) passed
  3,024 cases (45,792 events) at `/Od` and `/O2` and detected all 4 mutation controls
  (`omit-second-loop-pass`, `wrong-record-stride`, `skip-active-gate`, `omit-second-slot-reload`).

## Next step / boundaries
- Pinned proof inputs are frozen. Production integration (`CMakeLists.txt`, registry,
  build/audit) and callers (`004b0d70`, `00536a60`) remain outside Run589.
