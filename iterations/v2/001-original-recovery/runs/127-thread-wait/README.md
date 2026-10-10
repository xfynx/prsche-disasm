# Run 127: original thread wait at `0055fa10`

This packet restores the 128-byte cdecl function `0055fa10` from the pinned
`Porsche.exe` SHA256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
The index gives range `0055fa10..0055fa8f`. The routine accepts a
`ThreadRecord*` and timeout ticks and returns a DWORD in EAX; the caller cleans
its two arguments.

Caller edges are `0053c1a5`, `0055bee4`, `0055c03c`, `0055d21d`, `0055da05`,
`0055e9d9`, and `005835f5`. Each passes a thread record and timeout; `0053c1a5`
passes the `006bd9c0` record and zero timeout. There is no existing owner for
`0055fa10`. The existing `window_thread_wait_0055fb30` symbol is a platform
link alias for the SetEvent wrapper at a different VA and does not cover this
wait function.

The original first obtains `ThreadRecord.handle` through canonical
`0055f730`. A missing handle returns zero. For nonzero timeout, it calls the
existing timed-event helper `0055fbb0(handle, timeout)` once, ignores that
helper's result, then checks whether the record remains registered. It returns
one when the record has been unregistered and zero when it remains registered.
For zero timeout it checks registration first, then repeatedly performs a
timed event wait with a period derived from the signed DWORD at `005deb48` and
rechecks registration. The original calculates the period using
`IMUL 0x51eb851f`, arithmetic shift, sign correction, and add. A zero rate
therefore produces zero polling ticks; the existing `0055fbb0` helper applies
its own rate fallback.

The live-record query is the bounded inline behavior of `0055f980` and its
helper `0055f9b0`: signed slot bounds against the existing thread capacity,
table-lock enter, compare the slot cell serial with the record serial, unlock,
then reread the returned cell serial. The implementation reuses canonical
`ThreadRecord`, `ThreadEntry`, table pointer/capacity/lock owners, the
`0055f730` handle accessor, `0055fbb0` timed wait, and heap-lock APIs. It adds
no storage owners. The verifier executes original `0055f980`/`0055f9b0` bodies
inside the original oracle and compares them with this C++ predicate.

Sixteen differential cases cover null handles, active and stale registrations,
serial mismatch, signed slot bounds, one-shot timeouts and ignored wait results,
zero-timeout polling, unregistration during the wait, zero/low/typical and
signed-boundary timer-rate values, and exact lock trace order. Win32 waiting itself is a
controlled boundary through the already recovered `0055fbb0`; this proof does
not claim real scheduler timing.

```powershell
. .\scripts\tool-env.ps1
cmake -S iterations/v2/001-original-recovery/runs/127-thread-wait `
  -B local/builds/v2/thread-wait-127 -G "Visual Studio 17 2022" -A Win32
cmake --build local/builds/v2/thread-wait-127 --config Release
py -3 scripts/research/verify-v2-thread-wait.py `
  --probe local/builds/v2/thread-wait-127/bin/Release/thread_wait_probe.exe `
  --report-dir iterations/v2/001-original-recovery/runs/127-thread-wait
```
