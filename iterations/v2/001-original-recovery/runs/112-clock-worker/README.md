# Run 112 — clock worker 00565270

This packet restores original entry `00565270..0056533e` (207 bytes) from
`Porsche.exe`, SHA-256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
Run 110 found the omitted entry by searching writes to `006b7c40`; its manual
index row and complete disassembly establish the contiguous body and `RET`.
The caller `00565030` pushes this callback at `00565135` for bootstrap call
`0055f420` at `0056513a`. The thread-bootstrap integration remains separate.

The entry is `cdecl` with no stack arguments and returns zero in EAX. It samples
the imported `KERNEL32!GetTickCount` through IAT `005b2080`, creates an event
through the existing `file_auto_event_0055fb20`, waits through
`file_worker_wait_0055fb90`, and enters the loop only if the shared active word
`006a5c0c` remains nonzero after the wait. Each enabled iteration increments
`006b7c7c` and the canonical `current_tick_006b7c40`, computes an unsigned
wrapping tick delta, and adds `delta * 1193` to a 32-bit local accumulator.
The original signed `JLE accumulator, 0xffff` controls whether it adds `SAR 16`
to `006b7c44` and masks the local value to 16 bits. It then reads each of the
eight nullable callbacks at `006b7c20..006b7c3f` immediately before the call,
waits again, and rechecks the active word. Exit closes the event, clears its
handle at `006a5bfc`, clears canonical `timer_rate_005deb48`, and returns zero.

The new globals have separate exact owners: the callback array ends at exclusive
`006b7c40`; the existing `OriginalWindowConfiguration` ends at exclusive
`006b7c18`, leaving no overlap. The current-tick word and timer-rate word reuse
their existing owners. Other new DWORD/HANDLE owners are `006b7c44`, `006b7c7c`,
`006a5bfc`, and `006a5c0c`.

The differential fixture executes the original x86 entry and intercepts only
the imported tick source, existing event-helper calls, and fixture callbacks.
Wait boundaries control asynchronous updates to the active word; callback
fixtures can mutate later callback slots. Six cases cover immediate stop,
counter wrap, tick-count rollover, signed-carry behavior, a null event handle,
and same-pass callback-table mutation. The proof compares final owned state,
return EAX, callback order, wait/create/close order, callee-saved registers and
caller stack cleanup. It does not claim GetTickCount, OS event, callback, or
thread-bootstrap algorithms beyond their recorded boundaries. The pending
WM_CLOSE producer/terminal-path check remains open.

Build and verify this packet without modifying the common build:

```powershell
cmake -S iterations/v2/001-original-recovery/runs/112-clock-worker `
  -B local/builds/v2/clock-worker-112 -G "Visual Studio 17 2022" -A Win32
cmake --build local/builds/v2/clock-worker-112 --config Release
py -3 scripts/research/verify-v2-clock-worker.py `
  --probe local/builds/v2/clock-worker-112/bin/Release/clock_worker_probe.exe `
  --report-dir iterations/v2/001-original-recovery/runs/112-clock-worker
```
