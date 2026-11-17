# Run599 render misc cleanup

## Goal and criteria
- Recover original `00449b40..00449b67` (40 bytes) as `porsche::render_misc_00449b40` and
  `0053f0b0..0053f112` (99 bytes) as `porsche::render_cleanup_register_0053f0b0` (`__cdecl`),
  owning loader-zero `render_identity_lut_00618e74` (`0x00618e74`),
  `render_identity_lut_ptr_00619758` (`0x00619758`), and `render_cleanup_head_0069ebb0`
  (`0x0069ebb0`), reusing `porsche/render_startup.hpp`.
- Pass `verify-v2-native-batch.py` at `/Od` and `/O2` with 4 material mutation controls.

## Verified facts
- Cached REA dossier (`local/experiments/v2-frontier-469-rea/001/function-00449b40.json`,
  evidence `ev_53ff3aa3cd4ddf01eb26967549388a8d89995d3878165eeb2cf6251802fd15cd`) and PE bytes
  confirm `00449b40` passes `0x00449b70` to `0053f0b0`, fills `0x00618e74[0..255]` with `0..255`,
  and stores `&0x00618e74[0]` into `0x00619758`.
- PE bytes and catalog entry (`functions.jsonl`) confirm `0053f0b0` allocates 8-byte nodes via
  `0059ef90`, prepends to `0x0069ebb0`, and when `head == nullptr` allocates a sentinel node
  with callback `0x0053f980` (falling back to `esi->next = nullptr` if sentinel allocation fails).
- Attempt `001` (`local/experiments/v2-render-misc-cleanup-599/001/receipt.json`) passed 36 cases
  (48 events) at `/Od` and `/O2` and detected all 4 mutation controls.

## Next step / boundaries
- Pinned proof inputs are frozen. Coordinator owns production CMake/registry integration for
  `00449b40`/`0053f0b0` and their 3 owned globals (`0x00618e74`, `0x00619758`, `0x0069ebb0`).
- First-allocation null pointer fault, callback execution, and arbitrary alias checks remain open.
