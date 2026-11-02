# Run505: stream-buffer delivery

Native001 PASS, frozen: two original bodies00561800(190B)/005618c0(50B),240B,
zero new state.9,538 cases/945 events at each/Od and/O2;19,076 cases/1,890 events
total,12 mutations detected,400 input pins. The agent hit quota after the runner
completed; coordinator recovered the finished PASS receipt and retained inputs.

Original SHA/assembly/producer and typed callbacks are in original-evidence.json.
Canonical501 owns the exact16 slots; acquire and acknowledge use original signed
16-bit cursors/counters and late record reloads without new index/member guards.
Acquire writes the output length before releasing the previous chunk; callbacks
can mutate record/slot/chunk fields before subsequent reads. Acknowledge retains
the original sign tests, captured used count and subtraction. No storage is copied
or duplicated. See source/evidence for the exact address/field calculations.

The native graph executes raw505 acquire/ack plus raw501 stream callback against
actual C++505/501/493/492/434 providers. Tests include pointer/record/length-out
aliases, signed16 wrap, capturedchunk/length, availability and return-pointer
reloads, output/header/counter/slot overlap, PCM decoding/EOF and x87/used ABI.
Runtime release and consumed callbacks are controlled endpoints, with original
cdecl1(chunk+8) and cdecl2(slot,count) proven from producer00561200 and actual
493570/566e10/566e40 targets. Those producer/callback algorithms are not recovered
by this packet; no guessed implementation enters the game graph.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/505-audio-stream-buffer-delivery/native-config.json --attempt 001
```

Receipt:local/experiments/v2-audio-stream-buffer-delivery-505/001/receipt.json.
First native attempt passed without revisions. Shared507 owns compiler/COFF/registry
acceptance. Full producer/decoder/release effects, invalid/unmapped pointers, huge
counts, lifetime faults, concurrency/live platform/startup/gameplay remain open.
