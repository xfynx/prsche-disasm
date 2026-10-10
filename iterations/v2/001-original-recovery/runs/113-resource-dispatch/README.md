# Run 113 — FILESYS atomic dispatcher and callback

This run recovers `00568d50..00568e46` (247 bytes) and
`00561be0..00561c55` (118 bytes) from `Porsche.exe`, SHA-256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
The dispatcher is cdecl with four arguments `(callback, signed device index,
priority/group, context)`; it returns the callback's raw EAX. The callback is
cdecl `(group, context)` and returns size or zero.

The dispatcher checks the device table, validates the signed range `[0,31]`,
starts an uninitialized device, takes its lock, rejects a requested signed
priority greater than the current `field6c`, or temporarily installs the new
priority while invoking the callback. On success it restores `field6c`, signals
the device's queued event, then releases the lock. Diagnostics retain original
source and line values and format arguments. The callback calls file open with
mode `1`; on success it returns size for `group-1` after closing with the same
group. Open failure emits the original optional diagnostic and returns zero.

The native bodies call canonical recovered helpers for device startup, lock,
event, open, size, and close. The differential fixture hooks those service
boundaries to record calls and provide explicit outcomes; it does not emulate
disk, worker-thread, lock, or OS event effects. Eight cases cover successful and
failed open, priority rejection, signed device bounds, uninitialized devices,
and the null-table diagnostic path. Unicorn executes both original function
bodies and compares return values, event order, device state, stack cleanup,
and callee-saved registers.

```powershell
& 'local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' -S `
  iterations/v2/001-original-recovery/runs/113-resource-dispatch `
  -B local/builds/v2/resource-dispatch-113 -A Win32
& 'local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' --build `
  local/builds/v2/resource-dispatch-113 --config Release
py -3 scripts/research/verify-v2-resource-dispatch.py `
  --probe local/builds/v2/resource-dispatch-113/Release/resource_dispatch_probe.exe `
  --report-dir iterations/v2/001-original-recovery/runs/113-resource-dispatch
```
