# Run592 context base destroy

## Goal and criteria
- Recover original `00525ec0..00525f3b` (124 bytes, sha256
  `8c3fc02650c45d6a5a6290e2d0c2780d0a5f0eacdcf6df97db96cf5df900fb54`) as naked
  `__fastcall porsche::application_context_base_destroy_00525ec0(ApplicationSetupContext*, void*)`,
  reusing `"porsche/application_context_base.hpp"` and `"porsche/application_alloc.hpp"`
  without redefining external symbols.
- Pass `verify-v2-native-batch.py --attempt 001` at `/Od` and `/O2` with 4 material
  mutation controls.

## Verified facts
- Cached REA dossier (`local/experiments/v2-frontier-469-rea/001/function-00525ec0.json`,
  evidence `ev_61d22ef238a7ddd4a7a17b8555f61cb27db03d6a847ed13012d64072a8694d20`) and
  PE bytes confirm base vtable write `0x005bb028`, incoming `EAX` preservation on
  `[ecx+4] == 0`, count-zero skip of loop/reset, live `[esi+8]` reload after `005262e0`,
  live `[edi]` reloads across sentinel reset/clear, and `0059f050` return forwarding.
- Native `001` (`local/experiments/v2-context-base-destroy-592/001/receipt.json`) passed
  12 cases (52 events) at `/Od` and `/O2` and detected all 4 mutation controls
  (`omit-vtable-store`, `fallthrough-zero-count`, `wrong-member-offset`, `wrong-notify-flag`).

## Next step / boundaries
- Pinned proof inputs are frozen. Production CMake/registry integration and unrecovered
  callee/caller semantics remain outside Run592.
