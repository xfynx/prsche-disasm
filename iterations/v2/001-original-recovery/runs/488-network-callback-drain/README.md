# Run488: callback cleanup, dispatch and enumeration

Recovered eight original C++ bodies,582B total, from Porsche.exe
SHA256ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39:
00560380(38B),005603b0(98B),00560490(148B),00586e40(38B),005602f0(21B),
00560310(33B),00580e60(50B),00580dc0(156B). The callback frontier left by485
now has its actual body and a closed direct-original helper graph.

`original-index.json` was generated before implementation. It supplements the
omitted005602f0/00560310 entries with complete raw bodies through RET, actual
callers and cdecl argument transport. It also records all eight body hashes,
instructions and ownership checks. The new DWORD006a5b2c is4B of proved loader
zero-fill. Full483 ManifestReader643-pin closure plus pending485/486 checks
found no owner. Canonical485 flag/lists, thread lock, scheduler state and existing
heap/list/audio ownership are reused; no other original storage is added.

Cleanup tests the initialization flag once, drains006b7d20 before006b7d00 and
disposes both list locks without resetting the flag. Drain repeatedly obtains
each head through the accepted locked getter; real node callbacks must provide
progress. No new production guard hides nonprogress.

Dispatch reads only raw-proved fields. It gates on node, node+0x14 and the
descriptor pointer at node+0x08, then invokes descriptor+0x14 as
`uint32 __cdecl(void* node)`. Afterward it reloads
the descriptor and its+0x10 field, updates the unsigned pending counter and removes
the poll callback on transition to zero. Thread-lock arguments are reloaded at
the original boundaries. Optional queue+0x34 is disposed/freed through its captured
pointer, then cleared after both effects. Thread identity and timed callbacks run
even when the initial dispatch gates fail; the exact callback return is retained.

Poll enumerates006b7d20 with the proved two-argument cdecl visitor and opaque0.
That visitor conditionally invokes descriptor+0x10 with one node argument when
node+0x28 is nonzero, ignores that callback's return and always returns1.
Enumeration captures its inner lock and pre-call flags, preserves/restores the
original bit0 semantics, reads next after callbacks and returns the visited
count on abort or0xffffffff otherwise. Its outer wrapper reloads the list lock.
Unknown node/provider fields remain opaque; no object model or default callback
semantics are invented.

Native003 PASS at/Od and/O2:1,867 cases/13,507 events each,3,734 cases/27,014
events total;15/15 mutations detected through ordinary differential divergence.
All327 input pins match. Comparisons cover cdecl ABI/used returns, complete mapped
node/provider/queue/heap/lock state and ordered intermediate calls/state. Original
bodies call each other in the raw slab; canonical accepted providers are shared
with the C++ side. Only known poll/visitor code-pointer identities are normalized.

The fixture executes actual accepted route/dispose, heap-free/lock, thread-identity,
auxiliary-removal and timed-callback implementations. Controlled platform and node
callbacks exercise descriptor/queue changes, unsigned counter edges, lock reloads,
provider returns, head progress, next-pointer changes, abort flags and distinct
node+0x14/+0x28 gates. Lists contain0..2 nodes each; heap blocks are mapped seeded
non-coalescing blocks. This reuses unchanged child proof rather than re-proving
all allocator and scheduler domains.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/488-network-callback-drain/native-config.json --attempt 003
```

Receipt:`local/experiments/v2-network-callback-drain-488/003/receipt.json`.
Passed inputs are frozen. Attempt001 stopped at fixture link on dead owning-TU
dependencies, before original execution; unused fixture bindings fail closed.
Attempt002 passed positives and two mutations, then Windows CreateProcess740
rejected a mutation filename containing`dispatch`. A byte-identical renamed EXE
ran and detected divergence;`002/filename-diagnostic.json` records the hashes and
result. Attempt003 changes only two mutation labels to`node`. Both failed attempts
preserve their original inputs under`001/inputs` and`002/inputs`. No recovery
algorithm changed after the first attempt.

Coordinator owns registry/CMake/shared acceptance and measured frontier changes.
Real producers/callback progress, node/provider lifetime faults, auxiliary shutdown
after the final subscriber, lazy thread initialization, concurrency, live platform
effects and full startup/gameplay remain outside this bounded proof.
