# Run711: scene root finish + secondary destroy children

Native proof PASS for the two previously-unowned typed children newly exposed
by the integrated Run706/Run707 callers. Original PE SHA-256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`;
body ranges cross-checked against the catalog `body_ranges` and all owned
`source/recovered/functions.json` entries (1161 entries, zero overlaps).

| VA | bytes | decision | accepted caller |
|----|-------|----------|-----------------|
| `0044fc30` | 121 | full body | `scene_root_constructor_0044fb40` (Run706) |
| `0053f120` | 59 | full body | `teardown_secondary_destroy_0059f1c0` (Run707) |

`scene_root_finish_0044fc30` reproduces the REVERSE-arena signed keyframe bound
search: forward mode starts at `count-1` and steps down on signed `>=`/`<=`
comparisons of `[table+idx*8]` and `[table+idx*8+8]`; reverse mode starts at 0,
compares `[table+idx*8+8]`/`[table+idx*8+0x10]` and steps up while the next
index is below `count-2`. Every probed index is stored to `[self+4]`. The
caller stack dword is the search value and the body returns with `RET 4`.

`secondary_destroy_body_0053f120` stores the raw vtable address `0x005b3c94`
into `[self]`, walks `[self+4]` -> `[node+8]` siblings, calls the `[vtable+4]`
slot of a non-null `[node+4]` child, reloads `[node+8]` after that call, and
finally calls the slot of the last sibling with ECX=node and one stack dword 1
(callee `RET 4`). ESI is preserved across the walk.

Ownership decisions:
- Both VAs are absent as `entry_va`/`body_ranges` in `functions.json`; the
  catalog marks them automatic-pseudo-c/unrecovered. The two symbols were only
  declared extern by the accepted Run706/Run707 callers; this TU supplies the
  two previously-unowned definitions and does not redefine owned cells.
- Reused canonical provider: `application_state_006573e8` word `0x00657430`.
  No new owned `.data`/`.rdata`/`.bss`, no invented keyframe arrays and no
  invented callbacks. `0x005b3c94` is existing raw vtable data, verified in
  the injected original body before controlled transport.
- No body was excluded in this packet: both targets are single complete
  terminal-RET bodies with pinned raw bytes and bounded native domains.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/711-scene-root-finish-and-secondary-destroy/native-config.json --attempt 004
```

Receipt:
`local/experiments/v2-scene-root-finish-secondary-destroy-711/004/receipt.json`
(status PASS, `/Od` + `/O2`, 210 cases per variant = 420 measured
original-x86/C++ comparisons, 13/13 material mutation controls detected,
234 source/tool/PE pins). Snapshots compare the full receiver and bound-table
bytes, arena word, ordered tagged vtable calls with their stack argument, raw
vtable-immediate check, and nonvolatile/stack ABI. Failed attempts 001 (fixed
vtable page unavailable), 002 (double caller stack cleanup) and 003 (C++ did
not dereference `[vtable+4]`) are preserved; each was corrected without
changing the recovered original algorithm.

## Boundaries

PARTIAL only in the sense of controlled native endpoints: real keyframe
resources, live virtual destructors/vtable and allocator state are not live.
Null-receiver faults, unmasked FP, fault/lifetime/concurrency domains and
production CMake/registry integration remain open. No full-game,
startup/display/gameplay acceptance is claimed. No CMake, manifest, plan,
registry or shared-script changes were made by this batch.
