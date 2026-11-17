# Run 638 render seed PRNG (`00538040`, `.data 005de910..005de927`)

Bounded native x86-vs-C++ recovery packet for Porsche.exe (`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`) leaf PRNG:
- `render_seed_prng_next_00538040` (`00538040..00538100`, 193B, `__cdecl(void)` returning `uint32_t` in `EAX`, sha256 `a3c4b3764536d7f285c16f5cd5ad470a2bdf7baef3a67215206d1ff359172c13`).
- `render_seed_prng_state_005de910` (`.data 005de910..005de927`, 24B, 6 contiguous `uint32_t` words initialized to `[0xf22d0e56, 0x883126e9, 0xc624dd2f, 0x0702c49c, 0x9e353f7d, 0x6fdf3b64]`, sha256 `13eb516294955f2da4796105e1ecbea3780d3effefe20f5d2ae69aabcad79bde`).

## Index & Ownership

- `calls.jsonl`: `95` `UNCONDITIONAL_CALL` sites across `37` functions call `00538040` (including `004ae4d0` at `004ae65a`, `004ae6ca`, `004ae716`, `004ae739`, and `005561d0` at `005561d3`), consuming `EAX`.
- `references.jsonl`: only `00538040` (R/W) and unrecovered seed writer `00538110` (W) access `005de910..005de927`.
- Neither `00538040` nor `005de910..005de927` was previously owned in `iterations/v2/001-original-recovery/`.

## Verification

- Attempt `001`: **PASS** (`local/experiments/v2-render-seed-prng-638/001/receipt.json`)
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/638-render-seed-prng/native-config.json --attempt 001`
  - `/Od` and `/O2` compiled cleanly and passed `render_seed_prng_original_x86_vs_cpp=PASS cases=67`.
  - All 7 material mutations (`wrong-s4-s5-carry`, `wrong-s3-carry`, `wrong-s2-carry`, `wrong-s1-carry`, `wrong-s5-zero-cascade-guard`, `wrong-s1-to-s0-cascade`, `wrong-return-state-word`) exited `1` on `divergence`.

## Boundaries (PARTIAL)

Bounded native x86-vs-C++ proof for `00538040` and `.data` `005de910..005de927` across 67 test cases (production initial sequence, seeded sequences, carry/borrow edges, and `s5 == 0` increment cascade). Companion seed writer `00538110`, caller integration (`004ae4d0` and 36 other callers), concurrent access, and production CMake/registry integration remain open.
