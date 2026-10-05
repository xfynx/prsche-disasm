# Original support material source

2026-10-05. Module `Porsche.exe`, SHA256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
This resolves the material payload offset left open in Run 014.

## Index route and pointer identity

Queries with `query-binary-index.py --binary Porsche.exe --address <VA>
--disassemble` followed `0x4832b0`, `0x628bd4` (references), `0x483170`,
`0x4879d0`, `0x482840`, `0x478040`, `0x477ba0`, `0x489160`, `0x4876e0`,
`0x44a5e0`, `0x44a770`. The complete focused exports are in
`material-loader-source.jsonl`. The virtual target at `0x482970` is not an
indexed function; the hash-checked bounded decode and table are retained in
`material-loader-extra.txt`. That decode is navigation, not a claimed complete
function boundary. The identity proof below uses the indexed constructors and
loaders; it does not infer a class from neighboring functions.

At `0x4877bd`, scene loading constructs a material container with `0x44a5e0`,
stores it at scene+`0x0c` (`0x4877c9`), and passes the loaded CRP root to
`0x44a770` (`0x4877c6–0x4877cf`). In `0x4879d0`, this same scene+`0x0c`
becomes the constructor argument at `0x487a3f–0x487a45` to `0x482840`.
The constructor chain `0x482840 → 0x478040 → 0x477ba0 → 0x489160` forwards it
unchanged. `0x48919c–0x4891a0` stores that second base-constructor argument
at owner+`0x2c`.

The owner is stored at scene+`0x1c` (`0x487a4e`), passed to `0x483170`
(`0x487ab4–0x487ab8`), and saved at `[wrapper]` (`0x48318d–0x483193`).
That is the missing Run 014 identity: `0x4832d2 → 0x483070 → 0x474b90`
uses this exact owner, whose pointer remains at the derived bundle+4.
`0x539f30` returns it in the support consumer.

## Material array and raw payload

`0x44aa22–0x44aa90` searches CRP tag `mt` (`0x6d742020`), obtains indexed
entry IDs from the low 16 bits, and determines the largest index. It allocates
`maximum + 1` pointers (`0x44aa96–0x44aaa8`) and zeroes unassigned slots.
The maximum starts at zero, so an empty set still requests one slot.

In the entry loop, `0x44ab07–0x44ab14` resolves payload from entry+`0x0c`:
add the entry address only when entry flags bit 2 is set. This is the same
relative/absolute pointer contract as `0x43c6d0`; it does not add any offset
inside the `mt` payload. At `0x44abde`, the newly allocated material record
is assigned to `container[0][index]`. `0x44abe7–0x44abf4` copies that resolved
payload pointer to material record+`0x18`. Entries are assigned in input order,
so a repeated index replaces the earlier table pointer.

Thus `0x4753a5–0x4753c2` obtains:

`material = owner.materialContainer.pointerArray[primitive.wordAt4]`

`flags = u32(material.rawMtPayload + 0x00)`

This is the **first 32-bit word of mt data**, separate from cull flags at
`mt+0x0c` and render method name at `mt+0x10`. The full word controls quad split
(`!= 0`); constructors retain only its low 16 bits at polygon+`0x0a`.
Support selection later requires that retained word's low nibble to be nonzero.
The meaning of individual low-nibble values (including friction) is not inferred.

The branch `0x4753b6–0x4753d2` chooses the alternate-primitive path exactly
when caller flag is set and `(flags & 0xffffff0f) == 0`. The caller flag's mode
meaning and subsequent alternate resource selection remain separate work.

## Original execution and portable boundary

`replay-support-material.py` runs original payload resolution, material field
writes, owner/bundle constructors, getter, material consumer, and triangle
constructor. The harness supplies allocated buffers and resumes at documented
slice boundaries; renderer method lookup and allocation are excluded. No x86
instruction or callee is substituted. 208 cases passed with relative/absolute
entry pointers, indices 0/17, caller flag on/off, all 18 material-word values
found in the current tracks, and additional upper-bit/zero fixtures. A distinct
sentinel at mt+`0x0c` prevents confusing the two flag fields.

The read-only census covers 15 tracks / 3651 indexed mt entries. It records each
compressed/decompressed SHA, sparse table size/occupancy and histograms. 389 raw
entries have a nonzero low nibble; this counts material entries, not accepted
polygons or completed scene contacts. A Rust local-corpus test independently
parses all 15 tracks and compares the material tables to that census.

`original_support_material.rs` provides sparse table construction, raw-word
lookup and the exact alternate-primitive predicate. Invalid buffers/missing
indices return errors instead of invalid memory access; there is no invented
default material. The API accepts indexed mt entries, as verified for this
corpus. Renderer side effects and unindexed malformed records are outside it.
The module is not connected to live driving.

Next: trace the Base skip and primitive/vertex selection in `0x4750b0`, then
original spatial insertion (`0x484ae0`, child constructor `0x483bd0`). These
must preserve record order and polygon topology before scene queries can be
connected to the vehicle state.
