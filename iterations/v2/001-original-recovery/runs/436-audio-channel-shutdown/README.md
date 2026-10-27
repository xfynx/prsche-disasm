# Run436: canonical audio group shutdown

Original `005659f0..00565ace` (223B) is recovered as the signed cdecl1
`application_audio_stop_channel_005659f0`. The existing void caller uses a facade
that delegates once and discards the result; it adds zero original bodies.
Both actual Run433 COFF consumer contracts match the two production exports.

Native001 PASS: 160 cases per `/Od` and `/O2` (320 total), 17 detected mutations.
The complete indexed assembly equals SHA-checked raw PE bytes. Tests compare
outputs, exact final memory and call-time state hashes, and explicitly check
cdecl stack balance plus EBX/ESI/EDI/EBP. Canonical zero initialization and alias
addresses are asserted before reset. Existing device and Run434 lock/state owners
are reused without new storage.

The group recursion uses unsigned count `006b48d8` and reloads it after each child;
the channel scan uses signed count `006b49a4`, signed byte `record+0xe`, and table
reload after a matching stop. Header capture follows locking; the captured
header's unsigned word is read after channel calls. Clearing uses the group
table reloaded after release. Callback mutations cover those ordering/reload
distinctions, return failures, count changes and lock-depth wraparound.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/436-audio-channel-shutdown/native-config.json --attempt 001
```

Evidence: `original-index.json`, `ownership.json`, `coff.json`, `evidence.json`;
full logs and frozen receipt: `local/experiments/v2-audio-shutdown-436/001/`.
Production inputs are frozen. Root Run437 owns registry/build/shared acceptance.

Unrecovered `00590070` and `00565990`, and independent Run435 `00565d60`, are
controlled fixture endpoints here. No fixture providers enter production.
Negative-index acceptance is synthetic to test signed-byte transport; the real
validator's semantics are outside this body proof. Pointees must be valid local
memory; actual device behavior, concurrency, faults and gameplay remain open.
