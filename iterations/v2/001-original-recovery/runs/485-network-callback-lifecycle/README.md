# Run485: callback-list startup and lifecycle removal

Recovered original C++ for00560340(61B) and00561110(101B),162B total,
from Porsche.exe SHA256ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
Two current providers close; the real address-taken callback00560380 remains a
typed unresolved provider. The cached zero-direct-child heuristic missed this
registration edge. No raw original VA or production callback stub is supplied.

Startup tests the DWORD flag once, initializes list006b7d20 before006b7d00,
registers the actual native callback pointer, then writes flag1. It preserves
this order even when lock allocation or CRT registration fails or a controlled
child changes the flag. New original state is exactly60B: zero-filled DWORD
006a5b28 and two28B IoLists at006b7d00/006b7d20. The four-byte gaps after each
list are unowned. Raw PE section headers prove all60 bytes are loader zero-fill.

Lifecycle removal uses the canonical audio lock and existing device storage:
006b49a0 is a **signed BYTE**, despite the cached pseudocode's inferred DWORD;
the DWORD callback table starts at006b49b0. The first match is removed, count
decreases by one, following entries move forward, and the unused final entry
remains untouched. The count reload after every compaction store is retained.
The byte/count/table are views into the existing application_audio_device_state
backing; no audio storage or speculative capacity guard is added.

Native002 PASS at/Od and/O2:7,408 cases/14,640 events each,14,816 cases/29,280
events total;9/9 meaningful mutations detected through ordinary state/call
divergence. Tests compare complete lists, the full canonical audio block,
registry buffers/pointers and ordered intermediate snapshots, plus cdecl ABI.
They execute accepted io_init, thread_exit_register, exit-registry insertion and
canonical audio lock/unlock bodies. Heap-lock allocation and CRT lock/allocation
endpoints are controlled; the registered cleanup callback is never executed.

The240 startup scenes cover zero/nonzero/high-bit flags, child flag/list edits,
null locks, registry growth/failure and exact callback identity. The6,912 positive
count scenes cover0..35, absent/first/middle/last/duplicate/zero matches, lock-time
edits and nesting-byte wrap. Another256 scenes cover every signed-negative byte
count at two lock depths. The35-entry limit is only the mapped test domain that
fits established canonical backing, **not a proved original table capacity**.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/485-network-callback-lifecycle/native-config.json --attempt 002
```

Receipt:`local/experiments/v2-network-callback-lifecycle-485/002/receipt.json`.
All266 input pins match; passed inputs are frozen. Attempt001 stopped at fixture
link on dead owning-TU dependencies, before original execution. Its original
inputs are preserved under`001/inputs`; fixture-only unused functions now fail
closed. Link-only unrelated file cells are outside the tested path and game graph.
No recovered algorithm changed between attempts.

`original-evidence.json` owns raw assembly/body hashes, cached469 references,
the full480 ManifestReader640-pin ownership check and pending481 checks. Existing
new-state declarations do not overlap. No additional REA session was needed.

The next callback trace is00560380(38B): it calls accepted005806c0 and unregistered
005603b0(98B drain). That drain calls accepted00580b20 and unregistered00560490
(148B resource release), which adds an indirect node callback,006a5b2c state and
further scheduler/resource edges. This graph is deliberately left unfinished.
Real producers, cleanup execution, positive counts beyond the mapped domain,
concurrency, unmapped faults and startup/gameplay remain unverified. Coordinator
owns registry/CMake/shared integration and the resulting frontier measurement.
