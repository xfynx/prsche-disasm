# Run845 — Vector transform trace

Run843 reports `porsche::transform_vectors_00532a40(int, float const*, void const*, float*)` unresolved from Run835's `view_slot_camera_transform_004618b0`. The known caller supplies count `1` and the matrix at `car0 + 0x364`. The [Run835 REA receipt](../835-entry-fe-service/rea/validation.json) covers `00532a40`, `00559a40`, `00559ab0` and `0055a930`. The binary index confirms the wrapper's caller and callee edges. Its `references.jsonl` records `005df36c → 005b10b8`; the target appears as a label and needs a supplementary noncontiguous CFG before registration.

`00532a40` saves the matrix pointer and the destination stride through `00559a40` and `00559ab0`, sets the stride to `12`, calls `0055a930` with mode `2`, and restores both values through the same setters. A null matrix or zero destination stride makes the corresponding setter invalidate cached mode `005df358` with `-1`. A non-null matrix sets dirty word `006a3b5c`. On a mode-2 cache refresh `0055a930` selects index `0` (null) or `2` (the PACODE target) according to matrix presence, and clears the secondary callback and forced-x87 flag. A cache hit keeps the stored callbacks. The dispatcher skips execution for nonpositive count or null source/destination and otherwise copies the four argument-shadow globals before the selected primary callback. PE data at `005df358` starts with `-1, 12, 32`, followed by the 32 primary and 8 secondary dispatch slots.

The PACODE selector tests forced x87, then the low byte of canonical `cpu_has_3dnow_005deb20`, then the low byte of canonical `shared_runtime_word_005deb1c` for SSE. The x87 route saves and sets single precision, masks exceptions, then clears exceptions and restores its control word. The SSE route rearranges and caches matrix words, loads MXCSR with `old | 0x9f80`, computes `((x*a + offset) + (y*b + z*c))` in packed lanes and restores MXCSR. The 3DNow route rearranges and caches matrix words in a different layout, uses `PFMUL`, `PFADD`, and `PFACC`, and enters and exits with `FEMMS`. The three routes jump to separate loops and use shared aligned scratch at `006a64d0` through `006a654b`. X87 and 3DNow read their offset vector from `006a6530`; SSE loads it into XMM7. Preserve the cache, stride reads, output order and FP state handling when implementing.

The original `Porsche.exe` SHA-256 is `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`. Raw PE ranges were checked with Capstone and SHA-256. The following ranges are inclusive.

```text
00532a40..00532a7e  ebdf4852a3cddf6860ce30c8fb95b918d67c5727da40fa81e24b4802629ff00e
00559a40..00559a68  976251b2907ddafe5945544aa5c986b4eb38004ebe8792170d3731e40e1fe5ec
00559ab0..00559acd  07ef2c25f7b476f457fa75f41e9eafedc8c9eeaf13dfdd94329fe363cf05af92
0055a930..0055aa9f  baef956eaafc478f8174c7536e03fc9a411b6f63b254487bb6b5450a460acf98
005b10b8..005b1111  bbf8f9430901c374908330079ea4bfd0fba5c50bb23c544dd41c71ba14543807
005b0dc0..005b0df2  65d023689bea571cf02c52cb7ba9e8984a5a611df8abf8937824c7bb55a066fc
005b0df3..005b0ecb  6225d29f082a21ebbb5e33b4052a4a1cef1d5a077ad461cc01fb3a9bc0ecc860
005b0ecc..005b0fcd  3ca331f278538c034d3e7fd40c50a80627f32e2bff40b9f45eb21dff4693fffe
005b1320..005b1395  250b77f91cca9f3ee1a07c36c465ed31322ba50dd3762a30ccea57795dcbf98a
005b1606..005b167f  5e51f0df72a2a3a97aa3f86978351e4f345960e0da168cfa30de7937a172112d
005b18e0..005b1946  d95f21f90cdeeb52469b168cd6b50523d897793c98e4e8140846fcff05ce0998
005df358..005df403  b6787546a3e0a4da09e0f2d76f567bba0d9b967d85f7f4b3a83441be31ea3fcb
```

Next, trace writers to the scratch and dispatch cells, and keep the general `0055a930` modes partial while proving the mode-2 path through both setters and all three CPU backends. The Run835 fixture's `transform_vectors_00532a40` is a recording boundary. Use the shared native runner for original x87/SSE, the retained 3DNow emulation route from Run545, and controls that detect wrong stride, cache invalidation, feature selection and FP operation order. This trace has no production provider, differential receipt or linker closure.

Run840 remains an unresolved handoff. The root plan names it in the Run839, Run841 and Run843 commits. The run directory and artifacts were absent from tracked and ignored paths, linked worktrees, refs, stash, reflog and all nine locally unreachable commits. No scope or ownership was found.
