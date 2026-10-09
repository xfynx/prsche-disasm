# Run 050 — named application instance

Original: `Porsche.exe`, SHA256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`. Index query: `rg '005655f0|004a5c30' research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/references.jsonl`. Caller `004a5c30` passes the static `Porsche` string at `005d1298` to `005655f0`; the original body `005655f0..0056567c` selects/stores the name, calls `CreateMutexA(NULL,1,name)`, saves the handle at `006a5c28`, and branches on `GetLastError()==183`. The duplicate-instance branch finds a window by the current class/title, restores and foregrounds it when found, then checks `005df9bc`.

The recovered function shares the canonical window-name storage `0069e5a8` and class-name override pointer `006afcc0`. `00557370` is verified as `PUSH 0; CALL 005a246e`; the leaf is an explicit terminal recording boundary. Exit-flag cases compare ordered calls and state through that boundary only. A fixture returns after recording so native testing can continue; this does not claim the original process-exit continuation. The surrounding path/relaunch behavior in `004a5c30` is outside this package.

The native x86 probe and Unicorn execution compare return value for nonterminal cases, current name contents, mutex handle, and ordered API calls for name selection, already-existing and new mutex errors, found/missing windows, and the terminal exit branch. API effects and the final exit callee remain controlled boundaries.

Build and compare:

```powershell
. .\scripts\tool-env.ps1
cmake -S iterations/v2/001-original-recovery/runs/050-application-instance -B local/builds/v2/001-original-recovery/application-instance-050 -G "Visual Studio 17 2022" -A Win32
cmake --build local/builds/v2/001-original-recovery/application-instance-050 --config Release --target application_instance_probe
py -3 scripts/research/verify-v2-application-instance.py
```
