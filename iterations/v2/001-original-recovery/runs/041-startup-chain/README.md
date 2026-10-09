# Run041 ? shared window state and original startup integration

Original Porsche.exe SHA256: `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
Index navigation: `0053ac20|0053b8d0|0053a800|0055f420|004677e0|004b76f0|005679f0|00591820|00564e70` in the binary index, then callers/callees and the SHA-pinned instruction listing. Per-package README files retain precise addresses, layouts, arithmetic and call boundaries.

The common MSVC Win32 build now includes 37 comparison probes and one actual native window fixture. Accepted packages: Run032 complete display constructor, Run035 window worker, Run037 initial application/disk pools, Run038 handler registration and eight callbacks, Run039 unified window configuration, Run040 joint heap bootstrap/allocation, Run042 registry settings, Run043 keyboard/joystick startup, Run044 caller-owned thread startup. Registry: **150 full functions and 4 partial functions**, without double-counting the constructor or reused dependencies. Supplementary index: 20 bodies, 36,607 total indexed functions.

Configuration base `006b77a0` has one 0x478-byte storage object; confirmed fields and legacy globals alias it. Gaps remain opaque. Render requested width/height alias the existing startup globals. Pool storage already owned by files.cpp is reused. Keyboard state aliases the existing `0069e5a0` word. These changes prevent independent copies from silently diverging.

The production handler registrar calls an unresolved typed `005a112b` sort boundary. It does not substitute `std::sort`. The probe supplies host CRT qsort only for unique bounded startup message IDs; the oracle executes original qsort. Its algorithm and comparator call ordering are not reconstructed. Unknown OS/driver/game callees remain named boundaries.

Ten fresh package comparisons passed **719 cases**. Six build-dependent regressions passed **4,129 cases**, for **4,848** comparisons in this checkpoint. Reports are stored here, leaving older report snapshots intact. Run039's six layout/alias assertions also passed. Run040 executes actual page allocation ? primary heap commit ? heap initialization ? allocation/free sources, comparing the whole 64 KiB arena after every step; only the relocated callback pointer is normalized.

The freshly rebuilt `native_window_smoke.exe` was actually executed: visible HWND, 640x480 client, recovered WndProc, 39 default messages, clean destruction and exit 0. `native-window-result.json` pins its observed output and current source/executable hashes. This is the same bounded platform fixture as Run036, refreshed for the shared layout. Full window initialization/worker interaction, original main, renderer/game loop and visual fidelity remain unaccepted. No v2 game executable is claimed.

Run037's `005679f0` and `00591820` remain partial: repeated-init release, shutdown and allocation-failure behavior are outside the initial BSS-state proof. The other partial entries are input mode 6 and input-buffer caps failure.

Reproduce the common build:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File scripts/build-v2.ps1
py -3 scripts/research/verify-v2-window-create.py --probe local/builds/v2/001-original-recovery/bin/Release/window_create_probe.exe --report iterations/v2/001-original-recovery/runs/041-startup-chain/window-create/verification.json
py -3 scripts/research/verify-v2-window-procedure.py --probe local/builds/v2/001-original-recovery/bin/Release/window_procedure_probe.exe --report-dir iterations/v2/001-original-recovery/runs/041-startup-chain/window-procedure
py -3 scripts/research/verify-v2-application-bootstrap.py --probe local/builds/v2/001-original-recovery/bin/Release/application_bootstrap_probe.exe --report-dir iterations/v2/001-original-recovery/runs/041-startup-chain/application-bootstrap
py -3 scripts/research/inventory-v2.py --require-listing --require-decompile-attempts --write-verification
& ./local/builds/v2/001-original-recovery/bin/Release/native_window_smoke.exe
```

Other fresh reports use `verify-v2-{render-display,application-pool,startup-subsystems,window-thread-start,render-registry}.py --probe <common-bin>/<name>_probe.exe --report-dir <fresh-folder>`. Worker and handlers verifiers take `--report <fresh-folder>/verification.json`. Build-dependent input/callback/disk-open/input-buffer/resource-paths/render-startup verifiers take `--report-dir <fresh-folder>`. Separate native proof executables never supply fake symbols to a game target.

Next: integrate ready Run045/046/047, finish window positioning, renderer activation and single-instance startup. Then bind native callbacks/platform functions and recover the remaining original main chain. Owner of common CMake/registry/Win32 integration is the coordinator; active worker ownership is recorded in the iteration PLAN.
