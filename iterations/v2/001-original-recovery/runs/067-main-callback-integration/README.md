# Run067 — original main and native window callback linkage

Original Porsche.exe SHA-256: `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
Index queries: `004b6a50`, `0044e720/0044ebf0/0044ed10/00535b40`, `0053ac20/0053a800/0053aba0` and every callback in the original 27-entry registration sequence. Call/reference indexes locate consumers; the immutable ASM and per-package reports provide the ABI, state and control-flow evidence.

The common MSVC Win32 build passed: **54 comparison probes and three native fixtures**. Registry: **193 full functions and four partial functions**. Five added bodies are full main and four mode/state helpers. Run058,063,064,065 are integrated; later workers remain excluded. No game executable or renderer/gameplay acceptance is claimed.

Main now preserves its original allocation checks, FE/startup, setup re-entry, network branches, tick loop and shutdown. Fifteen controlled original-x86 comparisons pass. Its many unknown subsystem consumers remain typed boundaries. The contiguous `6573e8..65b20b` clear is explicitly unimplemented pending shared arena integration. The original DWORD read at `004b6b68` is represented by a DWORD `00657a60`; a `0x100` test distinguishes it from a byte read. String `00657a84` has no asserted production extent; the fixture's scratch capacity is not original layout evidence.

The original window initializer resolves all static callback VAs to native C++ pointers before registration. The resolver covers **27 registrations / 16 unique callbacks**, rejects unknown VAs, and never stores guest literals as executable pointers. The initializer differential normalizes native callback pointers back to original VAs for comparison; its callback leaves exit if accidentally invoked. A separate joint probe links the actual registrar, WndProc and all actual recovered callback bodies. Its six representative messages and 81 ordered registration-boundary calls match original x86, including the sorted table, state and all 256 key-state bytes. Win32/game services and the bounded qsort fixture remain explicit external boundaries.

Fresh main/mode/initializer/joint dispatch comparisons: **131 cases**. Six build-dependent regressions: **4,129 cases**. Total: **4,260**, plus resolver layout/unknown-address assertions. Older package reports remain historical; current registry references the fresh reports here.

The generated address catalog had lagged the supplementary index. It is regenerated to **36,618 entries / 31 supplementary bodies**, and inventory verification now checks every module's exact address set before sealing a manifest.

`link-frontier.json` records the actual COFF library inspection, including the separate real Win32 platform library. There are no duplicate project definitions. Undefined symbols include platform/CRT services, data, explicit unknown consumers and 35 known original addresses requiring adapter review. These are not a count of missing algorithms; identical addresses alone do not establish ABI compatibility. This is a symbol inventory, not a whole-game link attempt.

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File scripts/build-v2.ps1
py -3 scripts/research/verify-v2-application-main.py --probe local/builds/v2/001-original-recovery/bin/Release/application_main_probe.exe --report-dir iterations/v2/001-original-recovery/runs/067-main-callback-integration/application-main
py -3 scripts/research/verify-v2-window-create.py --probe local/builds/v2/001-original-recovery/bin/Release/window_create_probe.exe --report iterations/v2/001-original-recovery/runs/067-main-callback-integration/window-create/verification.json
py -3 scripts/research/verify-v2-render-mode.py --probe local/builds/v2/001-original-recovery/bin/Release/render_mode_probe.exe --report iterations/v2/001-original-recovery/runs/067-main-callback-integration/render-mode/verification.json
py -3 scripts/research/verify-v2-window-callback-bindings.py --probe local/builds/v2/001-original-recovery/bin/Release/window_callback_bindings_probe.exe --report iterations/v2/001-original-recovery/runs/067-main-callback-integration/window-callback-bindings/verification.json
py -3 scripts/research/verify-v2-window-callback-integration.py --probe local/builds/v2/001-original-recovery/bin/Release/window_callback_integration_probe.exe --report iterations/v2/001-original-recovery/runs/067-main-callback-integration/window-callback-integration/verification.json
. ./scripts/tool-env.ps1
py -3 scripts/research/audit-v2-link-frontier.py --report iterations/v2/001-original-recovery/runs/067-main-callback-integration/link-frontier.json
py -3 scripts/research/inventory-v2.py --require-listing --require-decompile-attempts
py -3 scripts/research/structure-v2.py
py -3 scripts/research/inventory-v2.py --require-listing --require-decompile-attempts --write-verification
```

Regression scripts input-state, fe-callbacks, disk-open, input-buffer, resource-paths and render-startup take `--report-dir <fresh-folder>`.
Next owners: coordinator handles link adapters and integration; heap_init_recovery traces Run068 shared application state/fill; render_mode_completion builds joint renderer state proof (Run073), with Run066/071 ready; window_worker_recovery closes window callee links (Run072), with Run069 queue and Run070 native Win32 bindings ready for integration.
