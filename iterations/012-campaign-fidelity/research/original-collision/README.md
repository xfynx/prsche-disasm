# Porsche.exe EDG object trace (2026-10-04)

Module: `Porsche.exe`, SHA-256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`. Addresses are virtual addresses. Source: `research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d` and focused `scripts/research/query-binary-index.py --disassemble` queries. Selected instruction evidence is in [disassembly.txt](disassembly.txt).

Confirmed from the indexed instructions:

- `%s.edg` at `0x5d05fc` is referenced by `FUN_00488090` at `0x4880a2`; `0x4880e3` calls `FUN_00487e80`. The call chain into it is `0x4876e0` -> `0x4879d0` (`0x487dad`) -> `0x488090`.
- `FUN_00487e80` opens the named file (`0x487e8b`), obtains its size (`0x487ea5`), allocates a `0x2c`-byte object per parsed entry (`0x487ef3`), calls `FUN_00485100` at `0x487f1a`, and appends returned pointers to a vector. The record count arithmetic at `0x487eac` is consistent with 28-byte entries, but that divisor should be confirmed independently before treating it as a format guarantee.
- `FUN_00485100` copies two four-dword coordinate groups into object offsets `+0xc` and `+0x1c`, stores a word at `+8`, sets byte `+4` to `2`, and places pointer `0x5b484c` at offset zero. It conditionally adjusts/copies one coordinate group at `0x4851c8..0x4851e5`; the precise invariant and constant values are not established here.
- `FUN_00488090` calls `FUN_00488590` at `0x4882a6` during load. `FUN_00488590` tests the low nibble of a traversed object's `+0xa` field (`0x4885f7`, `0x488642`), compares pairs via `FUN_00488440` (`0x48864e`), can construct further `FUN_00485100` objects (`0x488710`), removes duplicates when three compared floats match (`0x488785..0x4887e1`), and appends pointers to a vector (`0x48881e..0x488836`). These observations support a geometry processing step, not collision response.
- `0x4879d0` continues with `FUN_00488a60` and `FUN_004888b0` after EDG loading. The inspected disassembly of those functions shows other asset and pointer-vector processing, without a demonstrated vehicle velocity or rotation update.

At the loader-only stage, blocking entries, one-sided behavior, flags and the
vehicle consumer were unproven. The follow-up below establishes the consumer
and a bounded response law; flags and the full contact contract remain open.

The original gap at table target `0x485210` was resolved by the manual decode below.

## Manual range follow-up (same module/hash)

The indexed references identify table targets as LAB labels, not functions.
`scripts/research/inspect-pe-range.py` now provides a bounded raw decode with
inventory/hash/section checks; it does not invent Ghidra function boundaries.
Reproducible commands and bytes-as-instructions: [method-table.txt](method-table.txt).

The six consecutive table slots at 0x5b484c contain 0x485210, 0x4852b0,
0x485340, 0x508000, 0x4852f0, 0x4853b0. Confirmed operations:

- 0x485210 checks the caller flag, replaces the table and links memory back
  into an allocator list. This is a deletion/release path, not vehicle response.
- 0x4852b0 writes midpoint XYZ of the two coordinate groups; 0x5b23f0 is 0.5.
- 0x485340 writes min/max X and Z of the endpoints, not Y in this region.
- 0x4853b0 returns `object + 0xc + (index << 4)` (endpoint accessor).
- 0x4852f0 copies endpoint XYZ to two packed triples and calls 0x489cc0
  at 0x48532d, with a null third argument.

[contact-dispatch.jsonl](contact-dispatch.jsonl) contains the indexed full decode
of 0x489cc0 (104 instructions). It forms an XZ determinant, rejects determinant
equal to zero, checks two segment parameters against 0 and 1, and returns a bool.
An optional output pointer receives a 3D interpolated intersection; the EDG method
passes null, so it asks only for the predicate. Constants 0x5b23f8=0, 0x5b24a8=1
were read from the same hash-checked binary. This is a geometric segment test,
not an impulse law; no vehicle velocity/rotation writes occur here.

Follow-up 2026-10-05: [contact-query.md](contact-query.md) connects slot +0x10 to
the vehicle query and [response.md](response.md) records the state writes and
64 executable original-x86 comparisons. Current next steps are angular response
and complete query acceptance, as detailed there. Direct callers of
0x489cc0 also include 0x464500, 0x46ffa0, 0x4706c0, 0x473e00 and 0x488b50;
do not label them physical collisions merely because they use the same geometry.
