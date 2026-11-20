# Run706: scene child constructor / slot binding leaves

Native proof PASS for three accepted-caller children of the integrated Run704
scene bodies. Original PE SHA-256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`;
body ranges cross-checked against the catalog `body_ranges` and
`source/recovered/functions.json` (including interior entries).

| VA | bytes | decision | accepted caller |
|----|-------|----------|-----------------|
| `00469b50` | 7 | full body | `entry_fe_call_0046d890` (Run702) |
| `0044fb40` | 230 | full body | `scene_route_root_0044fae0` (Run702) |
| `004211d0` | 142 | typed binding only | `scene_transfer_slot_0044b960` (Run702) |

`scene_elem_kind_00469b50` is `return *(uint32*)(self+0xc0)`. `scene_root_constructor_0044fb40`
selects the backwards/forward key format from the arena REVERSE word, resolves
the key resource, reports/releases a stale element, fills a fresh `0xc88`-byte
reader block (`0x190` dword pairs, `0x44160000`/`0x186a0` header constants), runs
`0044fc30`, returns `self`. Four exact raw `.rdata` strings are transported
(`005ceacc`/`005ceab8`/`005cea80`/`005cea78`).

Ownership decisions:
- `004211d0` is **already owned** and proven as
  `application_context_member_storage_004211d0` in
  `source/recovered/Porsche.exe/context_effects.cpp` (registry
  `entry_va 004211d0`, native-differential-verified). The new
  `scene_slot_object_004211d0` symbol is a pure forwarder closing the accepted
  Run702 name; no second original body is defined.
- Reused canonical providers: `005a0fbf` (`formatter_entry_005a0fbf`),
  `0059d9b0` (`resource_open_quiet_0059d9b0`, Run649),
  `0059ecb0`/`0059ecd0`/`004211d0` (`context_effects.cpp`),
  `install_paths_table_0065b2a0[6]` and `application_state_006573e8`.
- RTTI cells `005cf908`/`005cf928` are typed `extern const uint8_t[8]` data
  (raw bytes `f8185c0000000000`), never constructed.
- No new owned `.data`/`.bss`; the six excluded bodies stay unresolved by design.

Excluded with evidence (`evidence.json`):
- `00458c90` (906B): heterogeneous x87/table constructor with three `0x8858`
  allocations, two string lookups, four global inputs and a catalog warning.
- `004522b0` (487B): array-building constructor with `0xc/0x8c` records, range
  copy, reallocation and `00452120`/`004524a0` children.
- `00475c80` (226B): fixed `0x108`-byte copy to `0x00628a20` overlaps the owned
  Run649 cell `startup_night_shape_enabled_00628a28` and unowned tail cells;
  cross-run data ownership must be settled first. Catalog warning.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/706-scene-child-ctor-and-slot-binding/native-config.json --attempt 017
```

Receipt: `local/experiments/v2-scene-child-ctor-slot-binding-706/017/receipt.json`
(status PASS, `/Od` + `/O2`, 31 cases per variant = 62 measured original-x86/C++
comparisons, 9/9 material mutation controls detected, 233 source pins). Snapshot
compares inputs, event/call order, used returns, self object bytes, the full
`0xc88` allocation block, manager state, arena word and nonvolatile/stack ABI.

Remaining boundaries: controlled native key-resource/heap/diagnostic endpoints
are not live loaders or a live heap manager; stale-element diagnostics and real
`0044fc30` child are outside this proof. The three excluded bodies, fault/
lifetime/alias domains, live devices and full-game acceptance stay open. No
CMake/manifest/plan/registry edits were made by this batch.
