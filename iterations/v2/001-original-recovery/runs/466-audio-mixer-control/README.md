# Run466: mixer counter feedback and voice-effect control

Two original bodies/422B:0058fcd0(209B),0058f6c0(213B). Native001 passes at
`/Od` and `/O2`:244 cases/1,174 intermediate events and16 detected mutations.
No new original state or lower algorithm dependency is introduced.465 REA002
already supplies both dossiers; canonical462/455/435/434 owners are reused.

Counter feedback preserves unsigned rebasing, signed ring/min/cap comparisons,
32-bit wrap, exact3000 threshold and signed remainder10. Voice processing keeps
record/data/callback-cell captures throughout the inner loop, reloading callback
and data values per call, current buffers after callbacks, table/count between
active voices and the current table for actual accepted435 stop. Its loop tests
signed wrapping(request-256), which differs from request>256 for negative overflow.
No request/count guard or convenient saturation is added.

Cases include configured starts8/16, negative signed counts, positive/negative/
wrapped requests, callback/table/count/object/buffer mutation, actual435 stop,
and an actual constructed461 filter through the original five-argument transport
(the known filter ignores the extra fifth argument). Full tables/device/stream/
buffers/effect state, events and ABI are compared. Controlled query/processor/stop
callbacks are finite fixture inputs; untouched accepted provider proof is reused.
Raw original bytes/branches and653 registry ranges were inspected before proof.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/466-audio-mixer-control/native-config.json --attempt 001
```

Receipt:`local/experiments/v2-audio-mixer-control-466/001/receipt.json`.
All production/native inputs are UTF-8 LF and frozen. Actual producer callbacks,
full worker/mixer/lifecycle composition, invalid/unbounded memory and concurrency,
live audio and whole-game startup remain open.467 owns shared integration/audit.
