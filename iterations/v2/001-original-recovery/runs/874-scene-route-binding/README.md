# Run874 scene route binding

Recovered original Porsche.exe `0045dbd0..0045dcf9` (298 bytes), SHA-256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
The Run850/869 cdecl `scene_route_bind_0045dbd0(void*, uint32_t)` symbol remains
in namespace `porsche`. Only the low mode byte selects initial construction or
update; upper bytes do not affect control flow.

The binder frees the old archive on updates, formats the route sky resource with
install-path slot 6, tries the quiet opener, then formats and opens the default
resource on failure. Initial binding allocates 0x238 bytes and constructs the sky.
Update calls the existing sky object and destroys/releases the old flare before
clearing its cell. Both paths allocate 100 bytes and construct the replacement
flare. Null returns and original intermediate global writes are preserved.

Run786 owns the flare and sky pointer cells. This packet owns only the new
loader-zero archive pointer `scene_route_archive_00627e50`. The registry has no
entry or recorded body-range overlap with the binder. `scope-evidence.json`
records code, strings, canonical state and loader-zero provenance.

Native attempt **004 passed 4,608 original-x86 comparisons at /Od and /O2**
(9,216 total), with three material controls: upper-mode-byte misuse, wrong
install-path slot, and wrong sky allocation size. The full original 298-byte body
is relocated with raw operand checks. Exact raw PE format bytes are independently
SHA-pinned before relocation. Ordered endpoint logs include globals at each
callback, object/argument transport, both allocation failures, fallback failures,
null old state, two base paths and three route strings. Production BSS is checked
before reset. Receipt: `local/experiments/v2-scene-route-binding-874/004/receipt.json`.

Attempt 001 failed fixture linking due to unavailable std::string exception
support. Fixed-array logs replaced that fixture dependency. Attempt 002 hit
OSError22 hashing a freshly linked executable; no semantic run occurred. Attempt
003 passed both optimized runs and the mode mutation, then rejected a nonunique
slot-mutation anchor. All failed attempts remain immutable.

Reproduce:

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/874-scene-route-binding/native-config.json --attempt 5
```

The fixture controls child/resource/allocator endpoints; their real algorithms
are independent obligations. Paths stay within the original 256-byte scratch
buffer. Live resource loading, sky/flare rendering, faults and gameplay remain
open. Coordinator owns CMake/registry integration and shared acceptance.
