# Run 751: Audio Voice Start (`005612a0`)

## Result

Recovered the reachable `audio_stream_voice_start_005612a0` parent
(`005612a0..005615b6`, 791 bytes) and its complete local loudest-channel helper
`00561180..005611c3` (68 bytes). The parent preserves the original cdecl4 ABI,
lock/reset/iteration flow, 0x70-byte voice initialization, retry cleanup and
signed return behavior. Registry plus supplement `body_ranges` have zero overlap.

The eight backend calls resolve to Run719 `0058a970`, controlled `0058a4b0`,
controlled `005898f0`, controlled `00589f40`, Run608 `00589df0`, Run610
`00589d70`, controlled `005897c0`, and Run439 `00589c00`. State and locking
reuse Run434; stream slots reuse Run501. `005897c0` is intentionally typed as
returning signed EAX: its original epilogue propagates `00589fe0` and this parent
branches on that value, despite the decompiler's `void` label.

## Evidence and verification

- Porsche.exe SHA-256: `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
- Parent body SHA-256: `435636867e37abd80dd7d9b12a31f2554792b7691869be6bacbf4f849a11a7b5`;
  helper: `94a3e5e43cf5983e8f31aebd1183ea0fc5368b3497ed58c4a3ce432c30971251`.
- REA `002`: six complete dossiers, audit PASS. `001` preserves `spawn EPERM`.
- Native `005`: `/Od` and `/O2` PASS, 8 cases / 69 events each, 14/14
  mutations detected. It compares full mapped state, calls/order/arguments,
  return, nonvolatile registers, ESP and x87/MXCSR.
- Native `003` is preserved: its base comparison passed but one mutation exposed
  the missing voice-slot-zero boundary case, added in the final proof.

```powershell
py -3 scripts/research/audit-v2-rea-session.py --config iterations/v2/001-original-recovery/runs/751-audio-voice-start/rea-queries.json --attempt 002
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/751-audio-voice-start/native-config.json --attempt 005
```

## Boundary

The four unowned backend bodies (`0058a4b0`, `005898f0`, `00589f40`,
`005897c0`) remain controlled typed endpoints. Accepted children are reused as
canonical ownership but controlled in this parent comparison. Live playback,
device faults, invalid pointers and concurrency remain open. This is standalone
proof only; shared build/registry integration and executable status are unchanged.
