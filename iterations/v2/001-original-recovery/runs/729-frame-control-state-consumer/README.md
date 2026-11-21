# Run729 frame control state consumer

Original `00412030..0041208a`, 91B, `__cdecl void()`. Replaces
`400-frame-loop-clusters/00412030.cpp` (unregistered in `functions.json`) so
production code reads the canonical 308-byte (`0x134`) loader-zero
`frame_control_ff_state_005e9408` owner defined in
`695-ff-effect-initialize/ff_effect_initialize_695.cpp` (`+0x04` enable flag,
`+0x08` row index, `+0x18 + index * 8` four signed 16-bit slot entries read and
reloaded per call in order `+4, +2, +0, +6` into `005338d0`). Adds zero new
data bytes (`new_data_bytes: 0`).

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/729-frame-control-state-consumer/native-config.json --attempt 002
```

- Attempt `001` is preserved (failed at fixture setup on callsite offset `0x53`
  instead of `0x52` for `00412082`).
- Attempt `002` (`local/experiments/v2-frame-control-state-consumer-729/002/receipt.json`):
  `PASS`, 2,304 native comparisons per `/Od` and `/O2` (`4,608` total), `7/7`
  material mutations detected (`gate`, `index`, `row-base`, `field-offset`,
  `call-order`, `signed-word`, `drop-fourth`), `ABI=PASS`, `owner695=PASS`.
- Boundaries: rows `0..31` only; controlled release endpoint mutates current
  index and table; live device behavior, out-of-range faults and full startup
  remain open.
