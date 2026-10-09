# Run 053 — CRT shutdown dispatch

Original: `Porsche.exe`, SHA256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`. Binary-index references for `005a2490` show the internal callback loop and imported `GetCurrentProcess`, `TerminateProcess`, and `ExitProcess` calls; exact instructions are in `research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm`.

`005a2490` takes the lock, conditionally tries `TerminateProcess` when `006afce8==1`, sets `006afce4=1` and only the low byte of `006afce0`, then—when its second argument is zero—runs registered callbacks in reverse order and the `005cb79c..005cb7a4` range. It always walks `005cb7a8..005cb7b0`. A nonzero third argument unlocks and returns; zero stores 1 to `006afce8` and calls terminal `ExitProcess(code)` without unlocking. The exact generic range walker `005a2547` is recovered alongside the dispatcher.

Seven x86/native cases compare the complete 64 KiB callback arena, registry pointers, exit globals, and ordered lock/API/callback events. They cover empty and populated lists, reverse order, null slots, skipped callback lists, byte truncation of the return flag, an existing process-exit state, and `ExitProcess`.

`GetCurrentProcess`, `TerminateProcess`, and terminal `ExitProcess` are deterministic platform boundaries; the `TerminateProcess` fixture returns failure so execution can follow the machine-code fallthrough. Static callbacks stored at `005cb7a0` and `005cb7ac` are called at their original addresses, but their bodies (`005a36d6` and `005ac147`) remain explicit boundaries. Underlying lock effects remain fixture boundaries through the already recovered wrappers `005a2535/005a253e`.

Build and compare:

```powershell
. .\scripts\tool-env.ps1
cmake -S iterations/v2/001-original-recovery/runs/053-crt-shutdown -B local/builds/v2/001-original-recovery/crt-shutdown-053 -G "Visual Studio 17 2022" -A Win32
cmake --build local/builds/v2/001-original-recovery/crt-shutdown-053 --config Release --target crt_shutdown_probe
py -3 scripts/research/verify-v2-crt-shutdown.py
```

Integration correction: the reverse walk uses unsigned x86 address arithmetic and reloads registry base after every callback (`005a24ec`). An eighth case mutates base from a callback, proving that cached-base traversal is incorrect. Empty registry traversal avoids undefined C++ before-begin pointer arithmetic.
