# Original type-1 support center, bounds and node/object overlap

2026-10-05. Source: `Porsche.exe` SHA256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
Queries: `query-binary-index.py --binary Porsche.exe --address <VA>
--disassemble --limit 300` and `inspect-pe-range.py --binary Porsche.exe
--address <VA> --size <bytes>` for 0x484320, 0x4855c0, 0x485630,
0x485e40, 0x485ea0, 0x5b2468, 0x5b2680. Full index results and
hash-checked raw instructions: [support-bounds-source.jsonl](support-bounds-source.jsonl).
The callbacks are table references at 0x5b4884/88 for quads and
0x5b48b4/b8 for triangles. `0x484ae0` calls `0x484320` twice; the latter
dispatches to these callbacks through object vtable +4/+8. The index names
some callback entries as labels; raw decode and actual x86 replay cover them.

The +4 callback returns the arithmetic vertex center. Quad 0x4855c0 sums
vertices in the order 1, 0, 2, 3 and multiplies by float 0.25 at 0x5b2468.
Triangle 0x485e40 sums 1, 0, 2 and multiplies by float bits `0x3eaaaaab`
at 0x5b2680. x87 retains extended intermediate precision until the output
float store. The +8 callbacks 0x485630/0x485ea0 write X/Z minima and maxima
to two caller buffers; they do **not** write either Y component. The original
code has distinct x87 compare branches for initial and later vertices, so
NaN and signed-zero behavior is outside this finite-vertex port.

`0x484320` decodes node level/X/Z from its packed word, reads level width at
0x628be8 and half extent at 0x628c30, then constructs X/Z cell lower and
upper floats. It first accepts when the object center X/Z is inside the cell,
including all four edges. Otherwise it calls +8 and accepts exactly when
`object_min_x < cell_max_x`, `object_min_z < cell_max_z`,
`object_max_x >= cell_min_x`, and `object_max_z >= cell_min_z`. Y is ignored.
The asymmetric strict/inclusive comparisons matter at cell boundaries.

[replay-support-bounds.py](../../../../scripts/research/replay-support-bounds.py)
executes original constructors and unmodified callbacks/predicate in Unicorn.
The harness supplies vertex pointers, a packed node, width and half extent;
it does not execute resource loading or insertion. 38 center/bounds cases
and 304 node/object cases include triangles/quads, varied coordinates,
center acceptance, edge touching, degeneracy and seeded finite samples.
Original outputs are in `runs/017-original-support-insertion/bounds-*`.
`original_support_bounds.rs` independently matches all replay outputs;
its two Rust tests pass. The module is now exported through `physics/mod.rs`
and reused by [support-tree.md](support-tree.md), still outside the game runtime.
Source callbacks for non-type-1 objects and nonfinite floats remain open.

```powershell
py -3 scripts/research/replay-support-bounds.py --run-dir iterations/012-campaign-fidelity/runs/017-original-support-insertion --source-output iterations/012-campaign-fidelity/research/original-collision/support-bounds-source.jsonl
. ./scripts/tool-env.ps1
cargo test --locked --manifest-path iterations/012-campaign-fidelity/Cargo.toml --target-dir local/builds/012-campaign-fidelity/.cargo-target -p nfs-assets --test original_support_bounds
```
