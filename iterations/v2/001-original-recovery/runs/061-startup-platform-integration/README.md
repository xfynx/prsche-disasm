# Run061 — startup, input, renderer routing and native platform integration

Original Porsche.exe SHA-256: `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
Index queries followed `53ac20/53b050/53b450`, `55fcf0`, `467fc0/468030`, `537600/5728b0`, `5a2400/5a2490` and `55f1c0` through callers, callees and the immutable instruction listing. Precise ranges, layouts, ABIs and unresolved consumers are retained in Run045–060 package READMEs.

The common MSVC Win32 build includes **50 comparison probes and three native fixtures**. The accepted registry has **188 full functions and four partial functions**: 38 new full bodies, without double-counting reused helpers, FE inline code, or covered-but-unimplemented boundaries. Supplementary index: 31 SHA-checked bodies, 36,618 indexed functions overall. Run058 main and Run063 mode selection are pending and excluded.

Accepted packages: window mouse/paint/key messages and keyboard hook; DirectInput initialization/release; the main FE apply/advance/free fragment using the recovered FE producer; positioning and cleanup; renderer activation/window response/mode selection caller and shared mouse/settings route; single-instance checking; original CRT callback registration/shutdown; original thread shutdown. A consumer comparison does not restore the external driver, CRT or game callees.

Fresh comparisons from the common binaries passed **1,549 cases** across 13 packages. Six build-dependent regression suites passed **4,129 cases**, for **5,678** current comparisons. The keyboard verifier now records the same SHA-pinned source dependency closure as the other packages. Compiled translation units, quoted transitive headers and included data are pinned by `v2_source_dependencies.py`.

The CRT shutdown reverse walker reloads its lower bound after each callback, as original `005a24ec` does. A callback-mutation case verifies this behavior; integer-address arithmetic preserves the original wrap/unsigned compare without constructing a pointer before an array. Window resize was traced with live ESP and RET8 cleanup: the adjusted rectangle points to the initialized local rectangle, not undefined stack contents.

Run055 and Run057 retain actual observed native x86 execution results: real Win32 pages/events/locks/threads, then recovered thread init → both start forms → trampoline → unregister → shutdown. The latter fixture still supplies recording exit-registration and memory-fill boundaries. Run041 retains the actual native window result. These are bounded fixtures, not game launch or visual fidelity acceptance. No v2 game executable is claimed.

Reproduce:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File scripts/build-v2.ps1
py -3 scripts/research/verify-v2-window-keys.py --probe local/builds/v2/001-original-recovery/bin/Release/window_keys_probe.exe --report iterations/v2/001-original-recovery/runs/061-startup-platform-integration/window-keys/verification.json
py -3 scripts/research/inventory-v2.py --require-listing --require-decompile-attempts --write-verification
```

Other packages use `verify-v2-{window-messages,window-position,render-activate,render-window,thread-shutdown,render-driver-calls,render-event-route}.py --probe <common-bin>/<unit>_probe.exe --report <fresh-dir>/verification.json`. Startup-input, application-fe, application-instance, exit-registry and crt-shutdown use `--report-dir <fresh-dir>`. The six regression scripts are input-state, fe-callbacks, disk-open, input-buffer, resource-paths and render-startup; all take `--report-dir`.

Next owners: coordinator integrates the next verified packages and links real boundaries; heap_init_recovery finishes Run058 main; render_mode_completion finishes Run063; window_worker_recovery traces native callback relocation in Run064. Main's contiguous `6573e8..65b20b` initialization remains an explicit boundary until shared arena layout is reconstructed. Remaining window-init/game/renderer consumers must be recovered before a game launch.
