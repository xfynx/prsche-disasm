# Run448: original audio group validation/release

Five original bodies/519B:00590070,00565990,00590000,00590170,00590b50.
Native003 compares the real outer chain at `/Od` and `/O2`:29,118 cases,
233,082 observed events and17 detected mutations. Canonical device storage is
reused;619 registered entry/body ranges have no overlap with these candidates.
REA447 attempt003 supplies all five original dossiers; no new REA run is needed.

Validation uses the signed index, low16 unsigned group count and busy byte+8.
Selection keeps signed indices and relative32 arithmetic, including mapped
negative indices. Item release retains the captured header across callbacks,
reloads the group table for flag+10, then reloads the captured header's kind.
The composed proof exercises actual selector/resource/release bodies, table and
header changes, callback order, signed counts and intermediate/final state.

The release scratch is0x800=2048B: only256 even DWORDs becomeffffffff; odd words
stay opaque and the same backing persists across child calls. The resource
adapter retains the original184B frame,164B decoded backing,12B payload plus8B
padding and mutable argument cell. Proof writes/reads decoded+a0 and checks
cursor/record/payload address relationships. C++ implements the original branch
logic; two internal stack adapters add zero original-function counts.

The lower599100/5996d0 bodies remain unresolved typed cdecl endpoints. Fixture
producers initialize the fields consumed here; callbacks are controlled cdecl
one-pointer endpoints observing the producer-owned12B payload. No subscriber,
decoder, malformed-record guard or expanded payload structure is invented.
Positive decoded counts0..4, negative signed bytes and mapped callback slots are
bounded proof inputs, not new production limits. Actual lower-body/subscriber
composition, the436 parent, invalid memory, concurrency and live game acceptance
remain open. Run450 owns integration and shared acceptance.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/448-audio-groups/native-config.json --attempt 003
```

Receipt: `local/experiments/v2-audio-groups-448/003/receipt.json`.
001 retained passing main variants, then its deliberately unbounded count
mutation was stopped and replaced by a bounded mutation.002 passed16 controls;
its exact config/fixture are archived locally.003 adds the required decoded+a0
backing test and offset mutation after tracing the actual child read. Production
is unchanged between all attempts. No old run, game build or commit was changed.
