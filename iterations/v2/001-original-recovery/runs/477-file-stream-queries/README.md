# Run477: physical-file write and truncate

Recovered original C++ for00591fa0(408B) and005924d0(183B),591B total,
from Porsche.exe SHA256ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
Two existing frontier providers close without new original-code dependencies.
Canonical PhysicalFile/count in files.cpp and mutex array in file_disk.cpp are
reused; no original storage is added. New typed WriteFile/SetEndOfFile function
pointers provide platform transport and default to the exact Windows SDK calls.

Write retains signed complemented-handle validation, captured device selection,
initial signed position clamp, mapped-only count clamp and backwards-independent
forward heap-copy semantics. The accepted lock, heap dispatch/forward copy and
sleep bodies execute in the fixture. Sleep(0) occurs only after mapped copy;
successful WriteFile does not sleep. Pending3e5 retries Sleep(1); hard error
returns zero even after earlier progress. The bytes-written cell starts with
the encoded handle and retains its previous value across retries. Chunk size
only shrinks. Physical-table and mutex reloads follow original call boundaries.

Truncate calls SetEndOfFile before SetFilePointer, regardless of the former's
return, stores the seek result without changing size and returns the exact
SetEndOfFile BOOL bits. Mapped records return zero without either OS operation.

Native003 PASS:1,379 cases/9,332 events per optimization,2,758 cases/18,664 events
total at/Od and/O2;10/10 meaningful mutations detected by ordinary divergence,
not crashes or event limits. Comparisons cover return/cdecl ABI, both canonical
record tables, complete memory/disk arenas, last-error/mutex state and ordered
intermediate snapshots. Scenes cover invalid handles/slots/inactive records,
mapped/disk paths, short/zero/overreported writes, hard failure after progress,
pending retries, signed boundaries, overlap/misalignment and callback-time table,
device and mutex changes. Default SDK wrappers also pass INVALID_HANDLE_VALUE
failure checks; this is bounded API transport, not live filesystem acceptance.

Cached469/001 dossiers and the binary index supply navigation. Raw original
bodies/assembly and ownership evidence are in `original-evidence.json`.
ManifestReader verified the full472 compiler closure626 pins, including accepted
run-owned sources/headers. No canonical body overlap or pending473/475 state
overlap exists. No new REA session was needed.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/477-file-stream-queries/native-config.json --attempt 003
```

Receipt:`local/experiments/v2-file-stream-queries-477/003/receipt.json`,332 input
pins. Passed inputs are frozen. Attempt001 stopped at fixture link because
unused functions in complete canonical TUs still required definitions; fixture
fail-closed bindings resolved them. Attempt002 reached original execution but
its64-event fixture capacity could not hold63 one-byte writes;128 now covers
the bounded scripts. Both failed attempts preserve their original inputs under
`001/inputs` and`002/inputs`. Recovery algorithm did not change between attempts.

Coordinator owns registry/CMake/shared acceptance. Zero-block nonprogress,
unbounded scripts, inaccessible/NULL pointers, concurrency, real asynchronous
I/O, broader worker/file composition and startup/gameplay remain unverified.
Fixture-only unused-path bindings fail immediately if reached and never belong
in the game graph.
