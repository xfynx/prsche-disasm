# Run750 render conversion child evidence

Evidence-only packet for children below unresolved
`render_shape_convert_type_00534d40`. The original is `Porsche.exe`, SHA-256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
REA attempt `002` and its read-only audit pass for `00571330` (107B),
`005713a0` (121B), and `00571470` (19B); exact ranges and hashes are in
`validation.json`. Attempt `001` is preserved.

```powershell
py -3 scripts/research/audit-v2-rea-session.py --config iterations/v2/001-original-recovery/runs/750-render-convert-child-chain/rea-queries.json --attempt 002
```

There is no recovered C++ source, native comparison, registry entry, or game
integration in this packet. Next: establish the children's ABI and state
ownership from assembly and canonical consumers, compare bounded original x86
with C++ at `/Od` and `/O2`, then compose the proved children through
`00534d40`. Preserve the Run745 callback-VA boundary separately.
