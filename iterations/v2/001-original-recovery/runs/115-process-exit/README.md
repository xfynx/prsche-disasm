# Run 115 — CRT terminal adapter `005a246e`

Source: `Porsche.exe`, SHA-256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
The binary index records `005a246e..005a247e` as 17 bytes and labels it
noreturn. Its callers push one DWORD exit code. The assembly pushes two zero
policy DWORDs, forwards the caller code to `005a2490`, and adds 12 to ESP only
after that call returns. `00557370` is `PUSH 0; CALL 005a246e` followed by
padding; its zero code is therefore confirmed at the callsite. In production,
`005a2490` reaches imported `ExitProcess`, so the cleanup and the adapter do
not return.

The typed entry in `process_exit.cpp` calls the accepted `exit_shutdown.cpp`
implementation with `(code, 0, 0)`. That implementation reuses the accepted
exit registry and lock wrappers; it runs registered callbacks newest-first,
then the two static CRT callback ranges, sets the process-exit state, and
reaches the typed Win32 terminal boundary. `process_exit_005a246e` is
`[[noreturn]]`; the fixture's `ExitProcess` boundary throws a private signal
so the probe can observe terminal ordering without ending its host process.

The verifier executes the original wrapper and its full `005a2490` callee in
Unicorn. It records the actual `GetCurrentProcess`, `TerminateProcess`, lock,
registered callback, static callback, and `ExitProcess` edges. The native probe
links the recovered shutdown and registry bodies. API functions, synchronization,
and callback bodies remain explicit recording boundaries. In the
process-state-one cases the `TerminateProcess` hook returns deliberately so the
original's following shutdown sequence can be compared; it does not claim that
the real Win32 API returns after terminating a process.

```powershell
& 'local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' -S `
  iterations/v2/001-original-recovery/runs/115-process-exit `
  -B local/builds/v2/001-original-recovery/process-exit-115 -A Win32
& 'local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' --build `
  local/builds/v2/001-original-recovery/process-exit-115 --config Release
py -3 scripts/research/verify-v2-process-exit.py --report-dir `
  iterations/v2/001-original-recovery/runs/115-process-exit
```
