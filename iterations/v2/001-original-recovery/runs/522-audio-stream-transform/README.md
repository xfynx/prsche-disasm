# Run522: stream transform and exact conversion

Native001 PASS, frozen:3 originals516B/8B readonly, no mutable state. `/Od` and
`/O2` each pass3,718 cases/8,004 events;11 mutations detected. Total7,436 cases/
16,008 events. Bodies:597660(390B),5a0f98(39B),597120(87B).

C++ owns160/240-sample loops, signed correlation loops, history moves and packing.
Small exact x87 primitives retain original operation/store order. __ftol consumes
ST0, saves/restores CW, forces chop, FISTP-qword and returns EDX:EAX. Masked NaN,
range, PC/RC/depth and full64-bit results are compared; no modern cast substitute.
96B local layout and input/output/scratch aliases are checked. Packing writes13B;
byte13 stays opaque, while the unchanged519 caller still returns14.

`original-evidence.json` owns raw constants/ABI and520 ownership. Current524
ownership is refreshed in `current-owner-524.json`;512 retains the same readonly
256F symbol/ABI used by the unchanged486 scalar proof. No stale486 TU enters game.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/522-audio-stream-transform/native-config.json --attempt 1
```

Receipt: `local/experiments/v2-audio-stream-transform-522/001/receipt.json`.
Frontiers:597360 cdecl2 metric and597180 cdecl4 coefficients. Their algorithms,
scratch initializer, full producer/lifetime, unmasked faults/concurrency/live audio
remain open. Old splash private casts are untouched and not repaired by this batch.
