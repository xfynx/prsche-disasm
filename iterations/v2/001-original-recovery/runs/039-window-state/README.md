# Run039 — unified original window configuration storage

The original Porsche.exe SHA256 is `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`. Run029's `0x53ac20` evidence shows the width, height and fullscreen arguments stored at configuration offsets `+0x14`, `+0x18` and `+0x461`; it also establishes that `+0x458` aliases the active HWND. Run035 traces `0x53b8d0` updates to global addresses `0x6b7c08`, `0x6b7c0c` and `0x6b7c14`, corresponding to configuration offsets `+0x468`, `+0x46c` and `+0x474` from base `0x6b77a0`. The fullscreen field remains one byte.

`OriginalWindowConfiguration` is an aligned x86 view spanning `0x478` bytes from base `0x6b77a0`. It types only those seven confirmed fields. Every byte between them remains an opaque array; no meaning is assigned to untraced data. `window_create.cpp` owns the one storage object and the width/height/HWND/fullscreen/running references. `window_worker.cpp` binds its position references to that same storage. `window_state.cpp` owns the production configuration pointer; `worker_configuration_006b77a0` aliases `window_configuration_address_006b77a0`, so worker and WndProc consumers share its target. Isolated probes bind the pointer to the same fixture object or to a controlled alternate fixture.

The joint x86 fixture writes all seven fields through the configuration object and reads them through globals, then writes via globals and checks the struct fields. It checks reference addresses, pointer alias reassignment, opaque-byte preservation and executes the recovered worker against shared storage. `py -3 scripts/research/verify-v2-window-state.py` passes all six assertions.

Fresh post-change original-x86 regressions are kept separately so the earlier per-run evidence remains intact:

- `regressions/window-create-029.json`: 36 prefix cases and 6 full-consumer cases passed.
- `regressions/window-worker-035.json`: 6 cases passed, including signed `GetMessageA == -1` and fullscreen mutation after create/wait boundaries.
- `regressions/window-handlers-038.json`: 87 cases passed, including the `0x53a800` return value for mutation versus no-op cases.

The fixture build is MSVC Win32/x86. These layout and consumer comparisons do not establish a real game launch or the semantics of the opaque configuration bytes.

```powershell
. .\scripts\tool-env.ps1
cmake -S iterations/v2/001-original-recovery/runs/039-window-state -B local/builds/v2/window-state-039 -G "Visual Studio 17 2022" -A Win32
cmake --build local/builds/v2/window-state-039 --config Release --target window_state_probe
py -3 scripts/research/verify-v2-window-state.py
py -3 scripts/research/verify-v2-window-create.py --report iterations/v2/001-original-recovery/runs/039-window-state/regressions/window-create-029.json
py -3 scripts/research/verify-v2-window-worker.py --report iterations/v2/001-original-recovery/runs/039-window-state/regressions/window-worker-035.json
py -3 scripts/research/verify-v2-window-handlers.py --report iterations/v2/001-original-recovery/runs/039-window-state/regressions/window-handlers-038.json
```
