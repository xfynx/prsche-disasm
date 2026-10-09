# Run 085 — window exit cleanup `00558350`

Source: `Porsche.exe`, SHA-256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
The binary index reports 107 bytes at `00558350..005583ba`; the only indexed
caller is the WM-close branch at `0053ba72`. It supplies the configuration
pointer after checking its `+0x10` word, then destroys the HWND after cleanup.

The recovered function is cdecl with one pointer argument. A null pointer uses
the canonical configuration at `006b77a0`; a zero `+0` word returns directly.
Otherwise it enters the shared lock at `006a57d8`, calls `00557990`, invokes
the object vtable slot `+8` with stdcall stack cleanup, optionally calls
`00531f90` for the `+0x10` pointer, clears dwords at `+0x10`, `+4`, `+0x24`,
and `+0`, then leaves the lock. The lock is the existing thread-start lock
owner; this run adds no duplicate storage.

The x86 Unicorn verifier and isolated MSVC Win32 probe compare the four
observed configuration words and ordered boundary calls for empty state,
nonempty state without an allocation, and null-argument fallback with an
allocation. `00557990` and the virtual method are explicit unknown-effect
boundaries: the fixture records call/argument order but does not claim their
internal effects. The heap free and lock implementations remain separately
recovered functions; their call interfaces are observed here. This does not
prove whole-heap behavior, driver/IAT behavior, or game launch.

```powershell
. ./scripts/tool-env.ps1
cmake -S iterations/v2/001-original-recovery/runs/085-window-exit-cleanup `
  -B local/builds/v2/001-original-recovery/window-exit-cleanup-085 `
  -G 'Visual Studio 17 2022' -A Win32
cmake --build local/builds/v2/001-original-recovery/window-exit-cleanup-085 `
  --config Release
py -3 scripts/research/verify-v2-window-exit-cleanup.py
```
