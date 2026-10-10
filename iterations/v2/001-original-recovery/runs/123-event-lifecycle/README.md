# Run 123: auxiliary event callback lifecycle

This packet restores the event callback lifecycle in the frozen original
`Porsche.exe` (`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`).
It uses the indexed rows at `0053bfe0`, `0053c060`, and `0053c1d0`; the inline
worker at `0053c0f0` and stop callback at `0053c170` have no standalone index
rows and are recorded below as SHA-pinned anonymous entries. Run126 adds both separately callable entries to the supplementary index.
The stop callback shares bytes with automatic0053c1d0 and adds no instruction coverage.

Index and caller review established these roles and edges:

- `0053bfe0` adds a callback to the first null slot, suppresses duplicates,
  and leaves the eight-slot table unchanged when full. If its lock is null, it
  first calls `0053c060`. Callers include `005601d0` at `0056026c` and
  `00587de0` at `00587c24`.
- `0053c060` registers `0053c170` with CRT exit registration, creates and
  enters the lock, then starts the no-argument worker `0053c0f0` through
  `0055f420`, passing the persistent record at `006bd9c0`. On failure it
  destroys and clears the lock before setting the original diagnostic file,
  line, and message.
- `0053c0f0` creates an auto-reset event into the Run122-owned cell
  `0069e5dc`, waits on that cell, invokes callbacks up to the first null slot while holding
  the lock, and tests the live stop word after the callback pass. On exit it
  closes the current event handle and clears the shared cell.
- `0053c1d0` removes the first matching callback by shifting later entries
  left. If the table is empty afterward, it tail-jumps to `0053c170`, even
  when the requested callback was absent. `0053c170` sets the stop word,
  signals the event, checks whether the caller is the worker thread, waits via
  `0055fa10` only when needed, destroys the lock, and clears the lock cell.

The newly owned cells are the callback table at `0069e5b4`, lock at
`0069e5d4`, stop DWORD at `0069e5d8`, and thread record at `006bd9c0`. The
event cell at `0069e5dc` is reused from Run122, without a duplicate definition.
`0055fa10(ThreadRecord*, timeout)` now uses canonical Run127 thread wait.
The component fixture controls its result; Run130 executes the connected body. Thread creation, event APIs, lock APIs,
CRT registration, and diagnostics are also controlled fixture boundaries;
this proof does not claim actual scheduling or a live event thread.

The verifier hashes the indexed bodies and these omitted anonymous entries:

- `0053c0f0..0053c167`: 120 bytes, worker body passed as a literal to
  `0055f420` at `0053c08f`.
- `0053c170..0053c1c6`: 87 bytes, shutdown callback passed to
  `00557380` at `0053c060` and tail-jump target of `0053c1d0` at `0053c25c`.

Build and verify using the isolated x86 target:

```powershell
. .\scripts\tool-env.ps1
cmake -S iterations/v2/001-original-recovery/runs/123-event-lifecycle `
  -B local/builds/v2/event-lifecycle-123 -G "Visual Studio 17 2022" -A Win32
cmake --build local/builds/v2/event-lifecycle-123 --config Release
py -3 scripts/research/verify-v2-event-lifecycle.py `
  --probe local/builds/v2/event-lifecycle-123/bin/Release/event_lifecycle_probe.exe `
  --report-dir iterations/v2/001-original-recovery/runs/123-event-lifecycle
```

The differential proof executes the original x86 bodies and the recovered C++
for 21 controlled scenarios. It checks table contents, stop/event/lock state,
thread-record writes, diagnostic state, ordered boundary/callback traces,
callee-saved registers, and caller stack behavior.

Root review corrected the first-null exit at0053c127; three added worker cases
cover an interior gap, a null first slot and a full eight-callback table.
