# Run 130: auxiliary-event stop and thread wait integration

This fixture joins the recovered lifecycle stop entry `0053c170` (an anonymous
entry in the indexed `0053c1d0` function row) to recovered thread wait
`0055fa10`. It executes the original x86 bytes in Unicorn and the production
C++ translation with the same controlled thread-table and API state.

The cases cover a registered non-self thread detached by its first wait, a
registered self thread (signal and identity check, with no wait), and an
already-unregistered thread (no wait). The comparison checks event order,
thread-table membership state, stop/lock/event state, stack cleanup and
callee-saved registers. Original helper bodies `0055f980` and `0055f9b0` are
hashed in the verifier because the C++ wait implementation inlines their
registration predicate.

Win32 event signaling, current-thread lookup, timed waiting, heap-lock
operations, and the thread-handle field accessor are explicit controlled
fixture boundaries. Thread creation and CRT exit registration are outside
the executed entries. This is a lifecycle integration proof, not a live OS
thread or GUI run.

Build with the x86 MSVC toolchain from this directory. Run the oracle check
from the repository root:

```powershell
py -3 scripts/research/verify-v2-event-thread-integration.py `
  --probe local/builds/v2/event-thread-integration-130/bin/Release/event_thread_integration_probe.exe `
  --report-dir iterations/v2/001-original-recovery/runs/130-event-thread-integration
```
