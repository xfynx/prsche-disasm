# Run613 render display member trees

## Goal and criteria
- Recover original `00466380` (372B) and `0044b1d0` (119B) from `Porsche.exe` (`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`).
- Reuse canonical headers (`porsche/render_objects.hpp`, `porsche/render_startup.hpp`, `porsche/context_services.hpp`, `porsche/application_context_base.hpp`, `porsche/context_effects.hpp`, `porsche/heap.hpp`) with zero new `.data` bytes.
- Pass `verify-v2-native-batch.py` at `/Od` and `/O2` with 4 material mutation controls.

## Verified facts
- Binary index (`functions.jsonl`, `references.jsonl`), PE bytes, and cached REA (`local/experiments/v2-frontier-469-rea/001/function-00466380.json`) confirm both bodies and all call/data relocations.
- `0044b1d0` (`__fastcall`, `ret 8`) zeros `tree[0x00]`, locks `(mgr + 0x28)[0]`, refills slot `3` via `__cdecl 0059eeb0(3, 0)` (`application_context_new_head_0059eeb0`) when `(mgr + 0x28)[0x18] == nullptr`, pops one free-list node, unlocks, sets `tree[0x00] = node`, `tree[0x04] = 0`, `tree[0x08] = *flag_ptr`, `node[0x00] = 0`, `head[0x04] = 0`, `head[0x08] = head`, `head[0x0c] = head`, and returns `self`.
- `00466380` (`__fastcall`, `ret`) pushes incoming `ECX` (`self`) and uses stack bytes `+2` (`local_a`) and `+3` (`local_b`) to initialize 8 12-byte trees stored at offsets `0x00, 0x14, 0x0c, 0x08, 0x04, 0x18, 0x1c, 0x10` of `self`.
- Attempt `002` (`local/experiments/v2-render-display-member-trees-613/002/receipt.json`) passed 570 cases (20962 events) at `/Od` and `/O2` and detected all 4 mutation controls (`wrong-pool-slot-arg`, `wrong-tree-flag-copy`, `wrong-node-sentinel-link`, `wrong-member-offset-order`).

## Next step / boundaries
- Pinned proof inputs are frozen. Coordinator owns production CMake/registry integration for `00466380` and `0044b1d0`.
- Null `self`/`flag_ptr`/heap-state pointers, pool refill failure, and production integration remain open.
