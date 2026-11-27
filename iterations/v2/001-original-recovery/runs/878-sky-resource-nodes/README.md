# Sky resource nodes

Run878 recovers `00460a50` (96 bytes) and `00460cd0` (98 bytes) from Porsche.exe SHA256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`. Both use ECX=self, one stack archive argument, and RET4. Public names and child ABI declarations are in [scene_sky_878.hpp](scene_sky_878.hpp).

The constructor stores the archive, clears the 40 chunk/node pointer pairs while preserving name bytes and other state, allocates an 84-byte empty resource node, and reads the canonical display parent only after allocation succeeds. Update processes entries whose old chunk pointer is nonnull, replaces each with the name lookup result, and reloads existing nodes even when that result is null. The type is `0x534b5920`, mode 1. Existing allocator, Run536 empty constructor, Run786 lookup and display owner are reused; `0044d9a0` is the genuine child owned by Run880. No new global state.

Native attempt **002 PASS**: 192 whole-object and child-trace comparisons at each of `/Od` and `/O2` (384 total), with all three mutations detected. Controlled child endpoints cover allocation failure/success, sparse/full slots, lookup null/non-null, names, argument order and untouched object bytes. These establish parent transport, not live resource loading or rendering. Attempt001 is preserved: fixture-only STL vector dependency failed linking; fixed-size trace storage removed it.

```powershell
py scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/878-sky-resource-nodes/native-config.json --attempt 2
```

Receipt: `local/experiments/v2-sky-resource-nodes-878/002/receipt.json`. The attempted command is immutable; use a fresh attempt number for changed inputs. [evidence.json](evidence.json) records index ranges, calculations, ownership and ABI. Shared build/registry acceptance belongs to the coordinator; startup and gameplay remain open.
