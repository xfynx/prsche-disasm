# Run595 startup transfer end

## Goal and criteria
- Recover original `004691c0..004691ca` (11 bytes, sha256
  `611feffed93f6a3f80fa1c77d856e92f5bade0bf69e5531b2a4189e907913d90`) as
  `porsche::startup_sequence_transfer_004691c0` (`__cdecl`) and `00468100..00468107` (8 bytes, sha256
  `c7eb9fa091e6c7322d0fb94ea902913506561139a707ee74638bd57af08357e4`) as
  `porsche::render_display_transfer_end_00468100` (`__fastcall`), reusing canonical headers
  `porsche/startup_sequence.hpp`, `porsche/render_startup.hpp`, and
  `../572-startup-service-lifecycle/startup_lifecycle_572.hpp` without redefining external symbols.
- Pass `verify-v2-native-batch.py` at `/Od` and `/O2` with 3 neutral mutation controls.

## Verified facts
- Cached REA dossier (`local/experiments/v2-frontier-469-rea/001/function-004691c0.json`,
  evidence `ev_a08f18f7461bf74ccb0508d25b9d34962b5a212a70e02e05b86875cc549a2efb`) and PE bytes
  confirm `004691c0` executes `mov ecx, dword ptr [0x628130]; jmp 0x468100` and `00468100` executes
  `mov ecx, dword ptr [ecx + 0x74]; jmp 0x536050`.
- Attempt `001` (`local/experiments/v2-startup-transfer-end-595/001/receipt.json`) passed 512 cases
  (512 events) at `/Od` and `/O2` and detected all 3 mutation controls.

## Next step / boundaries
- Pinned proof inputs are frozen. Coordinator owns production CMake/registry integration for
  `startup_sequence_transfer_004691c0`; malformed pointers/faults remain open.
