# Original support spatial query

Source: `Porsche.exe`, SHA256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
Index queries: `--address 0x484450`, `0x484500`, `0x628be8`, `0x483800`,
`0x473240`, each with `--binary Porsche.exe --disassemble` where applicable.
The `0x628be8` references identify initialization at `0x483861/0x48386f`.
These globals reside in zero-initialized memory, not file-backed PE bytes.
Complete focused index/function/instruction exports: `spatial-source.jsonl`.

## Grid and packed node coordinates

`0x48384a–0x48387f` stores the supplied float half extent at `0x628c30`,
stores twice that extent as float at `0x628be8`, and fills successive widths
by multiplying the previous stored float by `0.5` (`0x5b23f0`). The caller's
depth controls how many entries are written. Node first dword packs level
in bits 28–31, X index in bits 0–13, and Z index in bits 14–27.
The replay starts with a fresh zero-initialized PE for each initialization;
untouched widths therefore remain zero. `SpatialGrid::new` represents that
fresh initialization. Reinitializing the original global table in place would
leave unused entries unchanged; that lifecycle is not yet a runtime API.

`0x484450` validates a cached node in XZ only. Its width is the global table
entry for that level. Lower X is `indexX * width - halfExtent`, retained on
the x87 stack. Lower Z uses the same formula but is stored as float first
at `0x4844a7`. Both intervals include their lower and upper endpoints.
The portable implementation must preserve that asymmetric float store.

## Point traversal

`0x484500` immediately returns the supplied root if all four root child
pointers are null (`0x484500–0x484526`). Otherwise it calculates the root
center as `(index + 0.5) * width - halfExtent` for each axis.

Inside the traversal, a nonnull record-vector pointer at node+`0x14` stops
the search, even if that vector is empty or children exist. The original
does not reread each child's packed coordinate word. Instead, each descent
moves each center by signed `width * 0.25` (`0x5b2468`) and halves the width.
Strict `<` selects the negative half; equality selects the positive half.
The pointer slots are:

- node+`0x04`: negative X, positive Z;
- node+`0x08`: positive X, positive Z;
- node+`0x0c`: negative X, negative Z;
- node+`0x10`: positive X, negative Z.

If the selected child is null, `0x4845fd–0x484609` returns the **original
root**, not the last internal node. There is no check that the query lies
inside the root bounds. Supplied root/tree pointers must be valid; invalid
original memory is not modeled as a gameplay outcome.

## Cached support selection

`0x473260–0x473289` retains owner+`0x2c` only when the cached node passes
`0x484450` and its record-vector pointer is nonnull. It increments the
cache-hit profiling counter at `0x6289f0`. Otherwise `0x47328b–0x47329c`
queries the root from `[globalScene+0x24]` and replaces the cached pointer.
The portable cache helper returns the chosen node and hit/miss, excluding
profiling counters. Polygon iteration remains in `original_support.rs`.

Inclusive cached bounds and strict traversal halves make history observable:
at X=0 or Z=0, the negative-side cached leaf can remain eligible while a
fresh search chooses the positive side. Replacing the cache with a fresh
query every frame would change this original behavior.

## Differential evidence and limits

`replay-spatial-support.py` executes unchanged original instructions in
Unicorn 2.1.3. The harness supplies synthetic node arenas and nonnull empty
record vectors. It runs the actual width-initialization slice, entire bounds
and traversal functions, and entire `0x473240` selector, including its real
bounds/traversal calls. No instruction or callee is patched/stubbed. A hook
stops width initialization before allocation-dependent node initialization.

Run 014 records 12 width initializations, 112 bounds checks, 112 tree queries,
and 336 cached selections. Cases include unequal float extents, nonzero packed
origins/levels, two-level descent, missing children, empty child vectors,
internal vectors, outside-root points, and exact shared boundaries. TSVs
contain original outputs for Rust differential tests. Inputs are finite.
Portable f64 intermediates approximate the original 80-bit x87 stack;
passing this bounded corpus does not prove all exceptional float cases.

Scene loading/tree insertion, populated mixed-type vectors, car-state mapping,
simulation cadence, and gameplay/native/web acceptance remain separate tasks.
Next insertion functions to trace are `0x484ae0` (recursive population) and
`0x483bd0` (child packed-coordinate construction); the loader's plane/split
helpers are `0x489f90` / `0x48a0a0`.
This module is not wired into VehicleSimulation. The runtime build is still
`fa56d05`; no driving improvement is claimed by these probes.
