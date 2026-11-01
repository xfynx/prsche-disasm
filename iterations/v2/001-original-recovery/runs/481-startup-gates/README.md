# Run481: original startup gates and event drain

Original415dc0/40B,4b0fa0/55B and560030/19B recovered as C++,114B total.
New original data: two initialized0101 gate bytes and one loader-zeroDWORD,6B.
Full480 compiler closure640 pins has no competing owner. Canonical application
arena6573e8/selector657404 and frame-pump view6573e0 are reused by production.
Original switch table415de8 has five identical415de1 targets, so the source's
unsigned selector<=4 branch is exact, with no copied table needed at runtime.

Native001 passes first attempt:489 cases/2,044 events at each/Od+/O2,978/4,088
total and12 detected mutations. Raw original code includes relocated switch
entries and final tail JMP; preserved cdecl ABI, gate bytes/word, frame-state
canaries, endpoint argument/order and callback effects compare. Selectors cover
0..5 and signed/unsigned extremes. Drain tests vary initial flags, callback clear
points and sleep-time reactivation; event results include negative nonzero words.

The application arena source is real. Native frame-state view and pump/timer/
sleep/dequeue endpoints are controlled transport only; canonical game providers
remain unchanged. This does not establish whole scheduler/pump/event composition.
Production writes both gate bytes unconditionally; word606ae8 only changes for
0..4. The mandatory first timer, sleep10 after a clearing callback, final pump and
unconditional initial dequeue are preserved. No progress guard was added.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/481-startup-gates/native-config.json --attempt 001
```

Cached469 and raw index evidence are reused.434a90 is a5B tail JMP to unregistered
434aa0, whose indexed body is recorded in original-evidence.json; it is excluded,
not a zero-child recovery. Unbounded/reentrant callbacks, concurrent observation,
live window events/full startup/display/gameplay remain unverified. Inputs frozen.
