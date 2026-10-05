# Original Base and primitive readers

2026-10-05, Run 016 inside 012. Module: `Porsche.exe`, SHA256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.

Index queries: `query-binary-index.py --binary Porsche.exe --address ADDRESS
--disassemble --limit 2000`, addresses `0x4750b0`, `0x5a0b70`, `0x5a0b80`,
`0x5a0bc0`, `0x5a0c50`. Full indexed instructions and callers are preserved in
[support-assembly-source.jsonl](support-assembly-source.jsonl). Raw constants
at `0x5e5084` (28 bytes), `0x5e5138` (60 bytes), and the previously unindexed
vtable target `0x477d40` (107 bytes) are in
[support-assembly-constants.txt](support-assembly-constants.txt).

## Confirmed consumers

`0x475152..0x475164` reads CURRENT ordinal `u32(Base+4)` and computes the
selected record address `Base+0x64+12*ordinal`. Base byte zero bit `0x40`
skips the article. The count at Base+12 is not used to choose this record.
The record's unsigned word +8 selects vt/df resources (`0x475170`).

Special collider lookup (`0x4751a4` onward) precedes the static branch. Only
after falling into `0x47533a` does record byte zero gate static primitives.
`0x475347..0x47534b` read unsigned words +6/+4 as the end/start pr IDs passed
to `0x43cd50`. This port reads these fields; range lookup and special-collider
selection remain separate, unimplemented behavior.

`0x477d40..0x477daa` initializes per-article lookup caches, including seven
channel pointer pairs. It does **not** assign Base+4. No policy for choosing
the ordinal has been inferred from that initializer or raw zero values.

The primitive type is the sign-extended low word, independent of its high
word. Original tables for types 0..4 are:

- Vertex counts: `0,3,2,3,4` at `0x5e5138`.
- Polygon index steps: `0,1,2,3,4` at `0x5e514c`.
- Count shifts: `0,0,1,-1,2` at `0x5e5160`.

`0x5a0b80` uses unsigned `remaining=totalIndices-vertexCount` with wraparound.
A nonnegative shift returns `(remaining>>shift)+1`; a negative shift returns
`floor(remaining/3)+1` using the original multiply-high constant `0xaaaaaaab`.
Returning the source count does not authorize iterating malformed input.

`0x5a0c50` walks `u32(pr+0x28)` descriptors at pr+0x30, stride 16. It matches
descriptor kind `u16(+0xa)` through the tag table for kinds below 256, or
`(kind<<16)|0x2020` otherwise. The seven proven named entries are vt, nm, uv,
df, Base, pr, ef. It selects the requested matching occurrence, returning
null if absent. The Rust reader rejects unproven table entries 7..255.

`0x5a0bc0` reads a supplied polygon index, base index, and row word:

- Row `0xffff`: generate `base + step*polygon + i` with 32-bit wraparound.
- Otherwise: read `rowOffset=u32(pr+0x34+8*(row+2*descriptorCount))`;
  read vertexCount unsigned bytes at
  `pr+48+16*descriptorCount+8*rowCount+rowOffset+step*polygon`, adding base.

The support consumer (`0x4754dd..0x475538`) chooses occurrence zero of vt and
df, then shifts descriptor byte offsets right by four and two respectively.
No alternating strip winding is applied: type 1 stays `012,123,234`.
Quads retain four indices; triangulation is a later loader branch.
These rules are independent of the current renderer's mesh decoder.

## Verification and limits

[replay-support-assembly.py](../../../../scripts/research/replay-support-assembly.py)
executes unmodified original instructions with supplied resource buffers.
317 primitive payload cases produce 2536 checked helper results; 200 are
synthetic, 117 are first/middle/last polygons from sampled real pr records
across all 15 tracks. Synthetic cases include descriptor occurrences,
unmatched/custom tags, generated/indexed rows, high type bits, and unsigned
count/index wraparound. Raw inputs and original outputs are in Run 016 TSVs.

60 Base cases execute the address/flags slice and isolated static-path field
consumers. They include 45 synthetic cases and the first Base of each track.
The later static path is deliberately prepared without running the preceding
special-collider lookup. This proves its field reads, not that every article
takes that path. The harness does not patch instructions or stub any call.

Rust compares the captured outputs and independently decodes all 74,300 pr
records and 16,591 Base entries across 15 tracks, matching the census and
decoding first/last source polygon channels in every pr. This census is not
an original-x86 replay of every polygon. Game files are read only.

The port validates buffer bounds instead of reproducing invalid original
memory access. Missing support channels are errors, not invented fallbacks.
Still open: Base ordinal producer, exact resource range selection, special
collider/config consumers `0x47ed90`, alternate primitive `0x4510f0`, color
packing/degeneracy branches `0x475543..0x47591e`, full assembly, tree insertion,
and live vehicle-state/cadence binding. No gameplay behavior changed.
