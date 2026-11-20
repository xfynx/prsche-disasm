# Run705: audio bank open + period configure/reset (typed children of Run703)

Three full original bodies exposed by the accepted Run703 audio finalize/period
callback are recovered in one TU and proven against the immutable original:

- `00565b60` (71B) `audio_bank_open`: inactive-system early return -10, bank
  slot allocation through owned Run677 `00590140`, callback VA store at device
  +0x130, out-index write, 12-byte bank-table entry fill and the two-argument
  open tail `005900b0` (unowned typed boundary, controlled fixture return).
- `00598d10` (354B) `audio_period_configure`: reset, three count words, eleven
  36-byte reverb slots with x87 coefficients, owned Run451 integer read / Run438
  allocate, unowned `00598cd0`/`00598a70` typed boundaries. Exact 32-bit float
  stores are matched with pinned raw `.rdata` constants and inline x87 asm.
- `00598e80` (40B) `audio_period_reset`: 11-slot pointer walk at 36-byte stride
  from 006b08ec, owned Run438 release for each non-null field, clear only those.

Declarations match `runs/703-audio-finalize-period-callback/audio_finalize_period_703.hpp`
exactly. No owned cells are redefined: device state 006b48c0, Run677/451/438/221
providers are reused; only the unowned loader-zero reverb storage 006b08c0..006b0a6c
is added. Raw PE/SHA and ownership (including `body_ranges`) are in
`scope-evidence.json`; `pe_read.py` is the pinned raw-PE reader helper.

## Proof

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/705-audio-bank-open-period-config/native-config.json --attempt 006
```

Receipt PASS: `local/experiments/v2-audio-bank-open-period-config-705/006/receipt.json`.
32 measured cases / 119 callee events at both `/Od` and `/O2`; 13 material
mutation controls all detected; 233 input pins, 185 output pins. Attempts 001-005
are preserved harness failures (compile/relocation/fault/ineffective-mutation),
not semantic divergences.

## Boundaries

Bank index bounded to 0..7 by owned slot state; reverb table bounded to 3 count
words / 11 slots and seeded record bytes. Opaque callee semantics
(005900b0/00598cd0/00598a70), wild upper flag/address bits, bank index >7, live
backend/device effects, x87 control-word/PC exceptions and full startup/gameplay
remain open. No CMake/registry/manifest change: this is a native-proof batch;
game-graph integration is a later shared step.
