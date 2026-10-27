# Run438: original audio pool allocation and release

Three complete original bodies/476B:0058aa60(38B),0058aae0(335B),0058ac30(103B).
Native001 passes3,529 sequences/28,894 intermediate states at each of `/Od` and
`/O2`:7,058 sequences/57,788 states total, actual cdecl stack/register probes and
16 detected mutations. Sources, header, fixture/config and passed proof are frozen.
Shared game integration belongs to the coordinator.

`application_audio_backend_allocate_0058aae0(uint32)->uint32` rounds the request
with wrapped32 arithmetic, searches the original negative-count descriptor table,
clamps each gap through0058aa60 and moves metadata in the original direction.
Signed comparisons, header store/read order, captured versus reloaded pool pointer
and the historical low-water cursor are preserved. `audio_backend_pool_release_0058ac30`
returns signed0/-8 and retains descriptor-search/removal ordering. No defensive
guards or replacement allocator are introduced.

All three actual0058aa60 callers reload its second pointed word and ignore EAX.
Its public contract is therefore `void cdecl(const uint32*,uint32*)`; no scalar
return is invented. The accepted lifecycle consumer requires the old void
`application_audio_backend_release_0058ac30` name. Its one-call facade discards
the canonical signed body's result and adds no original body. Native facade
cases include duplicate descriptor offsets; its double-call mutation is detected.
Actual437 device/lifecycle COFF objects confirm both required consumer names.

The original allocator calls raw original clamp code; production calls the
recovered clamp. Sequences also compose raw original/configure434 and its accepted
C++ body. Every intermediate snapshot includes the entire pool arena, canonical
device block, CS bytes, used returns and ABI. Tests cover ordinary allocate/free
sequences, gap selection and metadata shifts, full/exact/zero requests, rounded
and signed extrema, cursor extrema, same-pointer/header/canonical aliases,
metadata that overwrites the global pool view, and finite crafted positive-count
layouts. The interior branch retains its pre-move pool pointer exactly as the
original0058abeb->0058abf3 jump requires.

No physical storage is added. The unchanged434 pool reference aliases the actual
canonical device-owner TU. Complete production initial state and reference address
are checked before fixture reset. `ownership.json` references437's build and its
effective shared manifest plus delta, verifies current hashes and records the
complete source/header closure query. It does not treat the old manifest base
alone as current proof.

`coff.json` records actual production objects at both optimizations and accepted
consumer objects. `evidence.json` pins receipt/source/config/fixture/ownership/COFF,
476 raw PE bytes and exact index spans/callers. All input/output hashes were
rechecked after the shared native runner passed. One conservative C4701 warning
remains: every zero-count/interior/tail path assigns `offset` before use, as source
inspection and both optimization proofs confirm; no source was changed afterward.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/438-audio-pool-allocator/native-config.json --attempt 1
```

Receipt: `local/experiments/v2-audio-pool-438/001/receipt.json`. No failed native
attempts. Local438 prepare/freeze helpers only assemble this packet.

Boundaries remain explicit: invalid/unmapped pointers, unbounded malformed negative
counts, faulting/infinite metadata walks and concurrency are outside tested memory
domains. The exercised crafted layouts establish exact finite alias behavior,
not general malformed-pool acceptance. Live device behavior, create-device startup
composition and full-game/display acceptance remain open.
