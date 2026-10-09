# Run 082 — timed callback slot registration/removal

This run reconstructs original x86 functions `005365e0` and `005366a0` from
`Porsche.exe` SHA-256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
The index identifies `005365e0` as 184 bytes and `005366a0` as 58 bytes.

The worker's idle path at `0053ba46` calls `005365e0(callback=0053bae0,
period=1, initial_delay=10)`. The recovered scheduler scans the shared 16-slot
table at `0069dd20` in 16-byte steps, replaces matching callbacks, or selects
an available slot after skipping the current registration depth's number of
empty slots. It writes callback, period, `current_tick + initial_delay`, and
zero to the four dwords. The last duplicate callback found wins. Scalar
`0069de20` is temporarily incremented and restored on success and error.

`005366a0` scans the same slots from the beginning, clears only the callback
dword in the first matching slot, and returns that slot's address. If no match
exists, it returns the one-past-table address. Production uses the existing
`TimedCallbackSlot` array and current-tick global from `window_runtime`; the
new translation unit owns only the distinct scalar at `0069de20`.

If registration finds no candidate slot, the original writes diagnostic
source `005bb6d8` and line `0x63`, then calls the function pointer stored at
`005debf0` with message address `005bb6ec`. That diagnostic routine remains an
explicit typed boundary. The differential fixture records this call and
returns as the original caller expects; it does not fake a successful slot.
The verifier covers duplicate replacement, depth-skipped holes, full-table
errors, tick wrap, removal at several indices, and no-match removal, comparing
all slot/state words and return values against original x86 execution.

```powershell
& 'local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' -S `
  iterations/v2/001-original-recovery/runs/082-window-scheduler `
  -B local/builds/v2/001-original-recovery/window-scheduler-082 -A Win32
& 'local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' --build `
  local/builds/v2/001-original-recovery/window-scheduler-082 --config Release
py -3 scripts/research/verify-v2-window-scheduler.py
```
