# Original type-1 support geometry

Run 015 follow-up: [material-loader.md](material-loader.md) proves mt payload+0
as the source word; [support-plane.md](support-plane.md) records the restored
plane/gap/split helpers. Rust differential tests cover these separate modules.
The complete primitive loader, spatial insertion and live binding remain open.

2026-10-05, Porsche.exe SHA256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
Queries: `query-binary-index.py --binary Porsche.exe --address <VA> --disassemble`
for 0x473240, 0x4853c0, 0x485c50, 0x485780, 0x486090, 0x4750b0.
Full focused instructions: support-source.jsonl. Hash-checked manual decode
filled table targets not named functions by Ghidra.

## Geometry and leaf selection

Quad constructor 0x4853c0 stores table 0x5b4880, four vertex pointers at +0xc,
type byte +4 = 1, word argument at +0xa, and four color words. Triangle constructor
0x485c50 stores table 0x5b48b0, three vertex pointers, the same type/word and three
colors. Their slot +4 returns arithmetic center: four vertices times 0.25 for
quad (0x4855c0), three times original float 1/3 for triangle (0x485e40).
They compute orientation byte +8 by testing XZ edge cross products against center.

Point containment at slot +0xc is 0x485780 / 0x486090. For consecutive A/B and
query point P, compute `(Ax-Bx)*(Pz-Bz) - (Px-Bx)*(Az-Bz)`, store it as float,
then interpret its **bits as signed integer**. If orientation byte is set,
reject any positive integer; otherwise reject any negative integer. This differs
at signed zero from a generic float comparison. Y is not tested by containment.
No configurable edge epsilon appears here.

0x473240 obtains a spatial leaf, iterates its 8-byte records in order, invokes
containment, requires record type 1 and object word +0xa low nibble nonzero,
then selects strictly smaller `abs(center.y - query.y)`. The initial distance is
float bits 0x7e967699; equal distances keep the earlier entry. Selection is based
on center Y, not plane height at the query. Plane Y is computed by a later caller.
The cache/tree traversal and raw material-to-word conversion remain separate work.

`replay-support-polygons.py` executes the real constructors, predicates and the
selection loop at 0x47329f with a supplied leaf. All virtual calls use original
table pointers and code. There are no substituted calls or patched instructions.
36 polygon cases and 10 leaf-selection cases passed, including reversed winding,
boundary/just-outside points, two point heights, stacked supports, tie order,
low-nibble eligibility and record-type filtering.
Results: [Run 013](../../runs/013-original-support-query/README.md).

## Resource consumer trace

Caller 0x488090 invokes 0x4750b0 at 0x488201 / 0x48839f before submitting geometry
to the same spatial container as EDG. 0x4750b0 reads Base, pr, vt and df entries.
Tag constants checked at 0x5e5084..0x5e5098:
vt=0x76742020, nm=0x6e6d2020, uv=0x75762020, df=0x64662020,
Base=0x42617365, pr=0x70722020. The loader:

- skips a Base byte with mask 0x40 at 0x47515a..0x475164;
- reads polygon vertex count via 0x5a0b70 and material lookup using the low word
  at primitive+4 (0x475393..0x4753b6);
- loads vertex/color index arrays (0x4754dd..0x475538), indexes vertex triples with
  16-byte stride and packs colors (0x47554b..0x47559d);
- reads a word argument from linked material state (0x4753bd..0x4753c4);
- builds triangles or quads with that word and source vertex pointers at
  0x47566e/0x4756cb/0x47574a/0x475825; a conditional geometric test can split
  a four-vertex primitive into two triangles;
- appends these objects to the input pointer vector later spatially indexed.

No `RD*` article-name test appears in this traced constructor path. Mapping the
linked material state back to the raw mt payload and the spatial query still
needs source verification before replacing the current RD-triangle query.
Do not choose collision geometry by names or infer flag meanings from bit values.

## Quad split branch

At 0x47562d the material-derived word is checked for nonzero. If zero, keep the
quad. Otherwise 0x48a0a0 computes the absolute vertical deviation of vertex 3
from the plane of vertices 0/1/2. If this is strictly greater than original
float 0x5b2418 = 0.03999999910593033, construct triangles (0,1,2) and (0,2,3).
The plane helper 0x489f90 uses original normalization/protection; a portable
replacement must retain that helper's handling of nearly vertical/degenerate
inputs. The existing Rust module does not implement this loader branch yet.
Ten flat-first-three fixtures executed the original branch and both real helpers,
including zero properties and values below/equal/above the threshold. All passed.
