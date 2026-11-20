# Run703: audio bank finalize + period callback (004a6bc0, 005901b0)

Recovered two FULL original bodies in `audio_finalize_period_703.cpp/.hpp`:
- `004a6bc0..004a6c80` (193B, `audio_bank_finalize_004a6bc0`) — basename scan,
  bank open/size/allocate/copy/free chain on status 7, accepted status 8,
  diagnostic otherwise, and three dwords written to `application_audio_records_006564a0[kind]`.
- `005901b0..00590248` (153B, `audio_period_callback_005901b0`) — lock, optional
  DS property when flags low byte has 0x80, optional handler-slot update when 0x20
  (period 0 clears/resets; otherwise configure with device kind word and either
  device pointer or the 005e25b0 default target, then store original handler VAs),
  unlock.

Both declarations match the accepted Run697 externs byte for byte. New owned cells:
38B literal `005d141c` (no overlap with Run697's `005d1444`/`005d146c`),
12B loader-zero `006b16b0` slots and 4B opaque `005e25b0` cell. Canonical owners
reused: `application_audio_records_006564a0[8]`,
`application_audio_device_state_006b48c0` (provides `006b4a10`/`006b4a14`/`006b48da`).
All four batch targets were unowned in functions.json (no entry_va, no body_ranges
overlap).

## Native proof

```
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/703-audio-finalize-period-callback/native-config.json --attempt 005
```

Receipt: `local/experiments/v2-audio-finalize-period-callback-703/005/receipt.json`
— PASS at `/Od` and `/O2`; 1,728 cases per variant (3,456 total: 1,440 finalize
+ 288 period), 5,472 events per variant, 13/13 material
mutations detected, 234 input pins / 185 output pins / 62 receipts. Compared used
EAX, callee-saved ESP/EBP/EBX/ESI/EDI, ordered callee events (args and out-index),
and full record/device/slot/target state at every event and finally. Synthetic
callsite setup/RET, controlled endpoints and VA relocations are harness code only.
Attempts 001-004 are preserved setup failures (no hypothesis retried after a
semantic divergence).

## Excluded: 00562810 / 00563440

Both draw routines (~853B/897B) write a 1024-byte palette via `006bda20` and use
`006b3020` as a sampler buffer; run 273 flags `006bda20` as
`scalar_storage_proof_required` with no accepted owner for the table extent, and
`006b3020` has only navigation-level attribution. The indirect call target is an
internal original constant (`0x0058b22f`, fallback `0x0058adae`), so no callback is
invented, but the palette/sampler table ownership is unproved. Per the batch stop
rule these are excluded with evidence in `scope-evidence.json` — no body, array or
callback was invented for them.

## Boundaries

Bank kind >7 (original unchecked record-table overflow), unmapped upper flag
address bits, live file/device/DirectSound effects, real bank contents,
concurrency, full startup/gameplay and production CMake/registry integration are
out of scope. See `evidence.json` and `scope-evidence.json`.
