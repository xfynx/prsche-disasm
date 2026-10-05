# Original plane helper and conditional quad split

2026-10-05. Source: `Porsche.exe` SHA256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
Index query: `query-binary-index.py --binary Porsche.exe --address 0x489f90`
and `--address 0x48a0a0`, both with `--disassemble`; focused instructions
are in [support-plane-source.jsonl](support-plane-source.jsonl).
Hash-checked constant bytes are in `support-plane-constants.txt`; the two words
at `0x5b2bc0` form double bits `0x3f847ae147ae147b` (0.01), not two floats.

`0x489f90` consumes three packed XYZ float vertices. It stores `a = v1-v0`
and `b = v0-v2` as float vectors, calls the original cross helper `0x532880`
to produce `n = a × b` with float component stores, and computes its length via
`0x532b20`. If length is at least double `0.01` at `0x5b2bc0`, it scales each
normal component by `1/length` and stores float components. If length is below
`0.01`, it leaves X/Z as the raw cross components. It then replaces Y with float
bits `0x3f7ff972` (0.999899983) whenever this short-length path was taken or
the normalized Y is at least the same constant. A downward Y is not clamped.
Thus degenerate input becomes `(cross.x, 0.999899983, cross.z)`, while a vertical
nondegenerate plane can retain Y=0.

`0x48a0a0` copies four source XYZ pointers to contiguous stack vectors, calls
`0x489f90` on the first three, and returns the absolute vertical gap between
vertex 3 and the first-three plane at vertex 3's X/Z. It divides by the guarded
normal Y but has no separate zero-Y guard: the vertical case returned NaN in the
original x86 probe. The branch at `0x47562d` first checks the material-derived
word for nonzero. It splits into triangles `(0,1,2)` and `(0,2,3)` only when
the gap is strictly greater than float bits `0x3d23d70a` (0.0399999991).

`scripts/research/replay-support-plane.py` executes unchanged original bytes,
with real cross and length helpers, for 10 horizontal, reversed, sloped,
vertical, degenerate, small-normal, and shifted cases. The original float
outputs are in [Run 015](../../runs/015-original-support-loader/plane-replay.json).
The 10 split-branch results were previously executed in Run 013 and are copied
to `plane-split-fixtures.tsv` without recomputing expected outcomes. Rust keeps
this pure helper outside the game runtime. Material mapping is now proven in
[material-loader.md](material-loader.md); source primitive selection and complete
support loading still need their own source proof. The vertical non-finite gap
is represented as JSON null with its original float bits retained separately.
