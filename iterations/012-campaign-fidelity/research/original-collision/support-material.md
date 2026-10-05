# Support polygon material word: bounded original trace

Run 015 follow-up: the raw offset is now proven to be **mt payload+0x00**.
The completed owner/loader identity and original replay are documented in
[material-loader.md](material-loader.md). The sections below retain Run 014's
bounded findings and previous unresolved steps as history.

Source: `local/game/Porsche.exe`, SHA-256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`. Navigation: `research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d`, `query-binary-index.py --binary Porsche.exe --address <VA> --disassemble`, then a hash-verified Capstone scan of `.text` for writes to `+0x18`/`+0x2c`. Selected address/instruction records are in `support-material-source.jsonl`.

**Confirmed consumer:** `0x4753a0` calls `0x539f30`, which is exactly `mov eax,[ecx+4]; ret`. `0x4753a5` reads `[eax+0x2c]`, `0x4753b1` dereferences it as a pointer to the material array, and `0x4753a8–0x4753b3` selects `array[primitive[+4] & 0xffff]`. `0x4753bf–0x4753c4` then loads `flags = *(*(material+0x18))` as a full 32-bit word. `0x4753ca` gates on `flags & 0xffffff0f`; the same word is later forwarded to support polygon constructors and quad-split logic (see `support-polygons.md`). This proves the in-memory consumer path, **not** the raw `mt` payload offset.

**Unresolved mapping:** The index has no direct material-tag string/reference to this consumer. Two bounded routes were checked: (1) source strings/RTTI near `0x5cde27`/`0x5ce408` did not point to an indexed material constructor; (2) candidate `0x44797c` does write an object `+0x18`, but its producer is `0x44b020`/`0x44d380` and no identity link to the array at `[resource+0x2c]` was established. It cannot be cited as the setter for this material entry. The third-party `local/references/LibOpenNFS/lib/CrpLib/Material.cpp` documents a `0x138`-byte `mt` record and changes byte `+0x0c` in `SetCull`, but it does not establish that the original executable's `flags` word comes from that byte. No raw `mt` offset or bit meaning is proven.

Next precise trace: identify the writer of the pointer array stored at `[resource+0x2c]` (resource from `0x539f30`), then follow construction of one array entry and its `+0x18` pointer to the exact raw `mt` read/copy. The `0x442b97/0x442beb/0x442c9e` writes to `+0x2c` are indexed candidates, but their enclosing `0x442790` code uses a different local object and has no proven pointer identity with this resource; check that identity before deriving any offset.

## Pointer identity follow-up

The `ecx` given to `0x539f30` at `0x4753a0` is the same `this` received by `0x4750b0`: `0x4750bd` saves it at stack `+0x14` before four pushes, and `0x4750dd`/`0x4753a0` reload the resulting stack `+0x24`. At `0x4881d5–0x488201` (and again `0x488373–0x48839f`), the caller passes a candidate object's `+0x14` pointer through `__RTDynamicCast` (`0x5a134b`) with source RTTI descriptor `0x5cfef0` (`PCollidableBundle`) and target `0x5cff18` (`PCollideArticleBundle`); the successful cast result in `eax` becomes this `ecx` for `0x4750b0`. The `+0x2c` table belongs to the cast object's **owner** returned by `0x539f30`, not directly to the cast object.

The RTTI complete-object locator at `0x5c4c30` precedes vtable `0x5b4674` for `PCollideArticleBundle`. `0x474b90` sets that vtable at `0x474ba1` after `0x474ac0` writes constructor argument `arg0` to object `+4` at `0x474ac6`. One creation path is `0x483070`: `0x48309f–0x4830ab` allocates a 12-byte castable object, calls `0x474b90` with outer `esi`, and stores the result at outer `+0xc`. `0x4832b0` calls `0x483070` with its `[wrapper]` pointer as `ecx` (`0x4832cf–0x4832d5`). This proves how the class's `+4` owner pointer is initialized on that path. It does **not** yet identify where this outer owner's `+0x2c` material table is populated. Other `0x539f30` consumers `0x43cdd0` and `0x445520` use the accessor on matrix-like state; adjacency or a shared generic getter is not evidence of material ownership.

Revised next address: follow the outer pointer passed as `esi` into `0x474b90` at `0x48309f`, or `[wrapper]` into `0x483070` at `0x4832cf`, to its constructor/writer of outer `+0x2c`; then follow the table's material entry `+0x18` pointer to a raw `mt` read. Do not infer that `0x442b97` writes this same outer object without an identity link.

## Focused writer check and boundary

The `+0x2c` writes at `0x475049`, `0x475abe`, `0x477f6a`, and `0x477fbd` do not establish the owner table setter. At `0x474ff1`, `0x475049` takes its destination `esi` from a stack argument and writes alongside geometry floats. `0x475abe` zeroes a field in a separately initialized large structure. At `0x477f6a`/`0x477fbd`, `esi = [ebp+0x30] + index*0x40` addresses a cache entry, whose `+0x2c` is updated as a tag. None has a demonstrated identity with the owner returned by `0x539f30` at `0x4753a0`.

The next exact source point is the constructor or resource-loading writer for the outer object supplied as `[wrapper]` at `0x4832d2`, then passed to `0x483070` at `0x4832d5` and stored in the derived bundle's `+4` at `0x474ac6`. Its `+0x2c` pointer-array writer remains unknown. Accordingly the raw `mt` offset for the support `flags` word remains unknown.
