# Run710: audio bank open tail + reverb finalize/query (Run705 typed children)

Three full original bodies newly exposed by the integrated Run705 audio TU are
recovered in one production TU with declarations matching
`runs/705-audio-bank-open-period-config/audio_bank_period_705.hpp` exactly:

- `005900b0` (133B) `audio_bank_open_tail`: fills the first dword of every
  8-byte group of a 2048B stack scratch with `-1`, loops over the zero-extended
  word count at `a+6`, calls accepted `00590170` group select, and passes each
  non-null source with `b` and the scratch to the unowned decoder `00590a80`.
  Default EAX return 7; any decoder result other than 7 yields 8. The decoder
  is a new typed child; its 205B algorithm is not invented here.
- `00598a70` (29B) `audio_reverb_finalize`: writes `0x7d0` to counter
  `006b1680`, then zeroes 1024B of the newly owned `006b0a80` mix buffer via
  accepted `0058fef0` backend configure.
- `00598cd0` (50B) `audio_reverb_query`: signed-dword times float product via
  live ST0 into accepted `__ftol` `005a0f98`; returns the smallest prime
  >= `max(trunc(product), 2)`.

Newly owned loader-zero `.data`: `006b0a80..006b0e80` (1024B) and
`006b1680` (4B). Run705 reverb storage `006b08c0..006b0a6c` is untouched.
Raw PE bytes, SHA, caller/callee and `body_ranges` overlap evidence (1161
registry entries) are in `scope-evidence.json`/`evidence.json`.

## Proof

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/710-audio-reverb-typed-children/native-config.json --attempt 007
```

Receipt PASS: `local/experiments/v2-audio-reverb-typed-children-710/007/receipt.json`.
119 measured cases / 255 events per variant at `/Od` and `/O2`; 13/13 material
mutation controls detected; 182 input pins, 185 output pins. Attempts 001-006
are preserved harness failures (compile errors, wrong signed-count hypothesis,
stale mutation anchors and one semantically ineffective clamp mutation), not
semantic divergences of the accepted bodies.

## Boundaries

Item counts bounded to 0..8, 16 select/decode scenarios, 6 finalize seeds and
28 query products (truncations about -10..127) at x87 PC modes 0..3. Original
x86 is executed from raw PE bytes with exact relocations; controlled fixture
shims stand in for unowned `00590a80` and canonical callees. Interleaved
uninitialized scratch dwords are explicitly excluded. Live decoder/backend,
NaN/Inf and extreme x87, faults, concurrency, full game integration and
CMake/registry acceptance remain open; no graph integration is claimed.
