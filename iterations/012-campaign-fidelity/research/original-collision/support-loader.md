# Retained static support resource assembly

2026-10-06. Source: `Porsche.exe` SHA256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
Queries: `query-binary-index.py --binary Porsche.exe --address <VA>
--disassemble --limit 2000` for `0x43cd50`, `0x59f700`, `0x4510f0`,
`0x4750b0`, `0x4874a0`, `0x4876e0`, `0x4879d0`, `0x488090`, `0x473240`;
raw hash-checked ranges for unindexed group vtable targets `0x482970`
and `0x4781a0`. See [source](support-loader-source.jsonl) and
[group decode](support-loader-article-groups.txt). All current resource
inputs are read only.

## Consumer and retained owner

`0x4879e7..0x487a03` obtains the full `Arti` resource range. The
`0x478040` group's virtual callback at `0x4781a0` partitions it by Base
payload word zero bit `0x8000`: clear-bit articles increment group+0x18
and are stored in its ordinary article array at group+0x1c
(`0x47823a..0x478246`, `0x4784c5..0x4784d0`). The `0x482840`
group callback `0x482970` instead selects the set-bit articles and prepares
repeated library/prop instances. This is an original source filter; article
names and `RD*` prefixes play no role.

`0x471ba9` creates the scene owner stored at `0x628960`. Its setup allocates
the persistent spatial object at owner+0x24 (`0x487876..0x487881`), then
calls `0x4879d0` and `0x488090` (`0x487dad`). `0x488090` makes a temporary
spatial object for its first `0x4750b0` call at `0x488201` with caller flag 0
and destroys that object at `0x4882b4..0x4882c1`. Its second call at
`0x48839f` uses flag 1, then submits the resulting vector to owner+0x24
at `0x4883b8..0x4883bc`. Original support selection `0x47328b..0x47329c`
reads the same global owner+0x24. The port assembles this retained flag-1
path. Other object types can enter the original spatial object and remain
separate work; a polygon-only tree does not reproduce their partitioning.

## Static polygon fields and branches

`0x475152` reads the **current** Base+4 ordinal directly from payload
returned by `0x43c6d0`, then selects `Base+0x64+12*ordinal`. The initial
port uses each stored word, not a hardcoded zero; an explicit ordinal API
allows later scene state. The indexed Base consumers checked here and the
35 references to the Base tag in this module have not established a writer
before initial `0x4750b0`; this bounded absence is not a proof that runtime
LOD state never changes. All 16,591 shipped Base stored ordinals equal zero
and fall within their mask counts ([census](../../runs/018-original-support-runtime/support-loader-replay.json)).

`0x47ed90` matches Base+0x44 against ordered ANIM definitions and falls
back to the first record for an unmatched nonzero tag. The parser's
`collideType` 1/2 selects special cylinder/box construction at
`0x4751bd..0x475335`, bypassing ordinary primitives; 0/3 continue to
`0x47533a`. The ordinary branch uses inclusive first/last pr lookup at
`0x43cd50`; subsequent iterator advances in `0x4510f0` and
`0x475919..0x4759ce` accept only the next pr index strictly below the
upper bound. Flag 1 with material raw word satisfying
`raw & 0xffffff0f == 0` advances via `0x4510f0` without emitting the
current primitive.

For emitted polygons, `0x4754dd..0x475538` chooses first vt and df
descriptors and their original index rows. `0x47554b..0x47559d` reads raw
XYZ at vt index times 16, without applying the renderer's `tr` matrix, and
packs each df word as `(B>>3)<<10 | (G>>3)<<5 | (R>>3)`. The branch at
`0x4755ae..0x47580a` drops first-three vertices sharing both X and Z;
triangles also drop any identical XYZ pair. Quads follow the material word
and original plane-gap predicate: when splitting, constructors receive
triangles `(0,1,2)` and `(0,2,3)`. The port retains source article, pr,
polygon identities and packed colors with each type-1 polygon.

The bounded [replay](../../runs/018-original-support-runtime/support-loader-replay.json) executes the unchanged
degeneracy instructions on nine finite cases and records all outcomes in
[fixtures](../../runs/018-original-support-runtime/support-loader-fixtures.tsv). Six Rust tests pass, including
fixture comparison and assembly of all 15 shipped track CRPs. The corpus
contains 15,541 ordinary Base and 1,050 library-bit Base. All library-bit
articles have a nonzero special tag, and the original filter in the port
skips all 1,050. Alps emits 21,162 static support polygons under its stored
initial ordinal. Across the 15 tracks the Rust assembly emits 237,395
type-1 polygons; per-track counts are in [the census](../../runs/018-original-support-runtime/support-loader-census.tsv).
This is a resource and branch check, not an original
full-scene replay or vehicle playthrough.

## Reproduction and remaining boundary

```
py -3 scripts/research/replay-support-loader.py --run-dir iterations/012-campaign-fidelity/runs/018-original-support-runtime
. ./scripts/tool-env.ps1
cargo test --locked --manifest-path iterations/012-campaign-fidelity/Cargo.toml --target-dir local/builds/support-loader-agent -p nfs-assets --test original_support_loader
```

The retained original tree includes nonpolygon collider types and may
receive geometry from other scene groups. The current type-1 assembly
provides source-backed ordinary track polygons; full mixed-object tree,
later LOD mutation and original vehicle contact cadence still need direct
comparison. The loader rejects malformed channel bounds and nonfinite
geometry in place of original invalid memory access.
