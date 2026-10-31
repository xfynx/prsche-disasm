# Run473: original sample dispatch and voice completion

Original58fbc0/265B,598940/243B and58f650/108B:616B total. Canonical434/435/442/
458/462 state and actual435 voice stop are reused. New loader-zero counterDWORD
006aeff0 and strideWORD006b16ac add6B, proved unowned against626 source pins.
Initial ownership lookup caught442's006b4885 flag; its canonical owner is reused.

Native003 PASS:/Od+/O2 total3,338 cases/5,360 ordered events,16 detected mutations.
Raw original code is relocated with asserted patch counts and calls its raw child
code; recovered code calls its recovered children. Defined scenes cover signed
counts, block boundaries, timing-product wrap/28-bit mask,30000 reset, zero-progress
iterations, callback/table/count/stride/optional-buffer reloads and actual435 stop.
All observed state, calls and cdecl preserved ABI compare. Inactive private slots
remain opaque; normal/probed initialized lane counts are1..4. No guards were added.

The28-bit mask is0x0ffffff0, not0xfffffff0. Chunk loops subtract256 even after a
short final block. Temporary first pointer is captured once, endpoint reloads each
block; current format is read after callbacks. Voice completion checks everyfourth
wrapping counter tick, with signedWORD totals and table/count reloads. Explicit
controlled598760/59bce0 children are transport boundaries, not recovered PCM.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/473-audio-sample-dispatch/native-config.json --attempt 003
```

001 exceeded fixture event capacity for the100Hz finite-progress scene; reduce
that scene's requested length17 without changing the original algorithm.002
passed both native variants but a fourth-tick mutation exposed a missing tick2
case;003 adds it plus negative-availability probes. Failed input snapshots remain
under `local/experiments/v2-audio-sample-dispatch-473/failed-inputs/`. Production
algorithm source was unchanged across all attempts;003 inputs are frozen.

465REA002 parent and indexed/raw children are reused without another session.
Excess/growing initially uncopied lanes, unbounded/nonprogressing callbacks,
NULL/unmapped faults, full473+475+476 composition, live audio/concurrency and
startup/display/gameplay remain open. The lower real algorithms are separate
475/476 native packets, to be integrated by one shared474 build/audit.
