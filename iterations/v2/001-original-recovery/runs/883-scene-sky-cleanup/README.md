# Scene sky cleanup

Run883 recovers complete indexed `00460220..0046028f` (112 bytes, cdecl RET0) and `00468960..0046897c` (29 bytes, ECX=self RET0) from the pinned original Porsche.exe. [evidence.json](evidence.json) records raw-body pins, global references, ownership and registry overlap checks.

The parent captures `00627e5c`, releases its +b8 allocation, processes all fourteen rows, releases the captured parent, then clears the global. Per-row releases at +38+4*i are unconditional, including null. After each release the row pointer is reloaded; present rows release their +4 allocation and invoke their object vtable slot zero with flags 1 before the row itself is released. The global remains visible throughout callbacks, and callback writes are overwritten by the final null store.

`scene_sky_cleanup_state_00627e5c` is the canonical new 4-byte loaderzero pointer owner; searching all run/source C++/headers found no prior owner. Allocator releases reuse `context_table_release_0059ecd0` and `application_release_0059f050`. No registered body overlaps either new function.

Native attempt **002 PASS**: 192 comparisons per optimization level (384 total) across null parent, fourteen-row sparse arrangements, null allocation releases, null/present objects, flags and exact callback order, preserved bytes, production initial global state, and callback global writes. All three material mutations were detected. Both original parent and original child execute in the oracle. Controlled allocator/vtable endpoints prove bounded transport; live heap/object teardown and startup remain open. Attempt001 preserved a fail-closed fixture relocation-offset check failure; corrected the first global relocation from offset1 to offset3.

```powershell
py scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/883-scene-sky-cleanup/native-config.json --attempt 2
```

Receipt: `local/experiments/v2-scene-sky-cleanup-883/002/receipt.json`. Use a fresh attempt for changed inputs. Header [scene_sky_cleanup_883.hpp](scene_sky_cleanup_883.hpp) exposes the two functions and canonical global. Shared registry/build acceptance belongs to the coordinator.
