# Run434: canonical audio lock, pool and channel helpers

Twelve complete original bodies / 451 bytes, reusing the recovered421/422
algorithms with corrected physical state bindings. Native003 passes570
cases/sequences at each of `/Od` and `/O2`; all16 pinned mutations fail with
the expected differential marker. Production sources, fixture and config are frozen.
Integration belongs to the coordinator's next shared build/audit.

The existing `ApplicationAudioDeviceStateStorage` in
`source/recovered/Porsche.exe/application_audio_device.cpp` remains the physical
owner. Four reference views use offsets `df` (byte lock depth), `e4` (signed
word count), `140` (table VA) and `158` (pool VA) from its `006b48c0` data view.
Only `alignas(4)`24-byte critical-section storage at `006b1800` is newly owned.
The trusted intake audit records the canonical backing span and original PE
loader zero-fill evidence. No duplicate physical scalar cells are introduced.

Proof links that actual canonical-owner TU and tests its complete396-byte initial
state, all four reference addresses, CS zero state and alignment before any
fixture reset. Differential snapshots retain the entire canonical span, opaque
bytes, CS bytes, pool/table memory, return values and endpoint traces. All47
historical base cases are retained;11 additional cases cover canonical pool/zero
overlap, slot aliases of count/table/group, signed extrema and wrapped slot
increment. Another512 cases sweep all256 byte depths through lock and unlock.
Historical counter-order, wrapped multiply, exact-active-byte and table/count
reload cases remain. The slot increment explicitly wraps unsigned32 arithmetic
before signed interpretation, matching x86 without C++ signed-overflow undefined
behavior. Pool publication order is checked with an overlapping canonical pointer.

The shared runner verifies all451 raw PE bytes by SHA before relocation. Existing
checked absolute-operand/relocation sites and original-to-original lock calls are
reused. `ownership.json` records all12 original VAs, symbols, byte counts/hashes,
trusted audit hash and canonical fields. `coff.json` records actual production
objects at both optimization levels. `evidence.json` pins the final receipt,
sources, config, fixture and mutation outcomes; the receipt owns dependency
closure, compiler/linker inputs, execution logs and full input/output hashes.
Sources/config were UTF-8 LF before proof.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/434-audio-canonical-bindings/native-config.json --attempt 3
```

The immutable receipt is `local/experiments/v2-audio-canonical-434/003/receipt.json`.
Attempts001/002 preserve a missing uncalled owner-link dependency and a nonunique
mutation anchor; neither is accepted proof. Six unused canonical-owner function
dependencies fail closed if invoked. Historical421/422 files and their Od-only
receipts remain unchanged; their two drifted heap-header hashes are not reused
as current proof. Final003 compiler dependency closure uses current headers.

Full421 closes six current names/seven references and exposes real child
`audio_channel_stop_00565d60`; that function is a controlled fixture endpoint and
stays unresolved in production. Run400 is never imported. The422 leaves are
connected subsystem candidates, currently without a caller in accepted413's
graph. `0058a8b0` and conflicting `005659f0` ABI remain separate work.
Critical-section effects are recording hooks; live Win32/device/concurrency,
pool allocation, unconstrained invalid pointers and original division faults
remain outside this bounded proof. No playable-game or live-audio claim.
