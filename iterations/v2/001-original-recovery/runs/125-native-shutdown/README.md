# Run125 — native CRT shutdown imports

Index query: `005a2490`, then its IAT calls and Porsche.exe imports. Pinned
module SHA256 is `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
Original `005a24a5` calls `KERNEL32!GetCurrentProcess` through `005b2094`;
`005a24ac` passes that handle and the original code to `TerminateProcess`
through `005b216c`. The normal exit at `005a252d` calls `ExitProcess` through
`005b21a8` with the same exit code.

`win32_shutdown.cpp` supplies these three OS bindings using the existing
canonical cdecl declarations in `exit_shutdown.hpp`. The recovered original
`005a2490` continues to own callback order, registry locks and state changes.
This packet adds no recovered original-function count.

The native probe runs only in disposable child processes. It checks actual
ExitProcess and TerminateProcess-of-self behavior for zero and nonzero DWORD
codes, including a high-bit code, and records GetCurrentProcess's pseudo
handle. These platform checks complement Run115's original-x86 shutdown
oracle; they do not prove full startup, CRT callbacks, game exit or WM_CLOSE.

Build the standalone Win32 target with CMake and run:

```powershell
py -3 scripts/research/verify-v2-native-shutdown.py --probe local/builds/v2/native-shutdown-125/bin/Release/native_shutdown_probe.exe --report-dir iterations/v2/001-original-recovery/runs/125-native-shutdown
```

Common integration belongs to Run121. All broader acceptance remains in
[validation backlog](../../../../../docs/recovery-validation-backlog.md).
