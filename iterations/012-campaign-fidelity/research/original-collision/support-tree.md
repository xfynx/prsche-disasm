# Original dynamic type-1 support tree and full cached query

2026-10-05, Run 017. `Porsche.exe` SHA256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
Queries: `query-binary-index.py --binary Porsche.exe --address VA --disassemble
--limit 2000`; insert `0x484ae0`, split `0x483df0`, predicate `0x484320`, child
`0x483bd0`, query `0x473240`, plus every executed allocator/vector callee.
Source functions/instructions: [support-tree-source.jsonl](support-tree-source.jsonl).
Actual type-1 callbacks are traced in [support-bounds.md](support-bounds.md).

## Confirmed algorithm

Insertion first checks `0x484320`: inclusive center acceptance, otherwise
AABB with strict minimum-vs-upper and inclusive maximum-vs-lower comparisons.
If rejected, the tree remains unchanged. The root additionally asks for object
bounds, but that branch neither inserts nor corrects a position.

A leaf allocates a record vector if null and appends the original type byte
and object pointer. Source reserves 50 eight-byte records initially. Above
48 records it invokes split `0x483df0`; the latter stops **exactly** at packed
level 12. Original scene setup supplies half extent 8192 and 15 table entries.
The Rust constructor bounds root levels to 0..12 as a valid-arena constraint.

Existing-child insertion and redistribution visit slots **2,0,1,3**. Child
creation precedes that child's own node/object predicate, so empty allocated
children must be retained. The child-region center/AABB checks use inclusive
upper boundaries, unlike the subsequent node predicate. A spanning polygon
may enter several leaves; duplicate insertion is preserved in record order.
The fourth insertion branch uses tail recursion; the port keeps the same
result with a recursive call.

Redistribution processes parent records in their original order and recursively
inserts them. Only after all records are processed does the parent vector get
freed and its pointer cleared. The port keeps `None` distinct from an allocated
empty vector, and maintains child-pointer slot order independently of creation
order. Modern arena indices and Vec allocation preserve these game semantics;
allocation failure and native pointer layout are outside this bounded port.

Full query starts at `0x473240`: cached node containment and record-pointer
presence, otherwise actual tree traversal `0x484500`, then type/flag/polygon
containment and closest center-Y selection. The supplied synthetic scene uses
the same tree just built by insertion. This is not the earlier supplied-leaf
probe: insertion, splitting, cache updates and record selection now run together.

## Original x86 replay

[replay-support-tree.py](../../../../scripts/research/replay-support-tree.py)
executes all game, object, vector and allocator instructions unchanged.
Prepared heap metadata follows `0x5697f0` / `0x5320b0`; the runtime allocator
table at `0x5e4700` uses original callbacks `0x531f70` / `0x531f90`. Source
startup `0x59e9d0` assigns that table. Raw table bytes/hash are preserved in
[support-tree-allocator-constants.txt](support-tree-allocator-constants.txt).
Allocation, pool refill, vector reallocation/copy/free and recursive splitting
execute original code. The heap is a bounded four-MiB supplied arena; startup
and heap creation are not themselves replayed.

Only **imported Win32 EnterCriticalSection/LeaveCriticalSection** are modeled
for one thread. The harness resolves their IAT slots `0x5b2078`/`0x5b206c` to
platform endpoints, tracks lock count, recursion and owner, and verifies balanced
state after each case. These are platform services, not replaced game callees.
Concurrent Windows lock behavior is not tested. No original instruction is
patched, and no geometric or allocation callback is stubbed.

Original polygon constructors retain vt pointers: each test polygon owns a
stable separate vertex buffer. An initial harness reused scratch storage;
that was corrected before capture/acceptance. Original record padding above
the type byte is unspecified; the fixture checks the consumed low type byte
and exact object pointer/order, not uninitialized padding.

Eight scenarios produce **36 full tree snapshots** and **72 full cached support
queries**. They cover 48→49 splitting, descent to level 12, vector growth to
60 terminal records, triangles/quads, spanning polygons, shared edges, outside
root geometry and forward/reverse insertion order. Rust matches every packed
node, child-presence mask, nullable record vector, ordered record ID, selected
polygon and updated cached node. Existing query/contact fixtures still pass.

Callback summation order is now reused in SupportPolygon center queries;
constructor winding retains its own original per-axis order. All portable
geometry/query inputs are bounded and finite. Unordered/NaN callback semantics,
other object types, dynamic resource mutation and allocation failure remain
outside this API. x87 intermediates use the existing f64 approximation between
source f32 stores; matching these fixtures does not prove every possible float.

## Remaining integration boundary

The modules now compose **type-1 polygons → built tree → full cached selection**.
The actual resource loader, special/alternate colliders, Base ordinal producer,
color/degeneracy/full polygon assembly and live vehicle state/cadence are still
open. This checkpoint changes no driving behavior and does not close 012.
Next concrete loader range: `0x475543..0x47591e`, then the original special table
consumers at `0x47ed90`. No road-name heuristic is authorized by this tree proof.
