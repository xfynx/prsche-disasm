# Run 121 — timer, formatter-helper, and auxiliary-signal integration

Acceptance, 2026-10-11: full MSVC Win32 ALL_BUILD passed, 107 reachable
projects / 203 TUs; 93 comparison/alias probes, four native OS targets and
three nongUI link fixtures. All seven native/link checks passed. Nine fresh
original-x86 reports cover 4152 comparisons, plus four composed cases.
The registry contains 243 full functions and six partial consumers.

Run125's three real KERNEL32 shutdown bindings are also linked through the
existing Run055 platform target; six disposable-child tests passed. They
add no original-function count. The game-link proof now derives its compiled
source closure from the excluded target's actual ProjectReference graph,
including appended platform translation units.

Real game-link: zero compiler errors, 245 unresolved symbols / 264 references
(Run117: 248 / 267), no runnable game EXE. Full timer scheduling and WM_CLOSE
remain in the [validation backlog](../../../../../docs/recovery-validation-backlog.md).

Run 121 links the accepted Run118 timer functions, Run119 formatter helpers,
and Run122 auxiliary event signal into the common x86 build. Its integration
probe exercises the recovered timer producer tail and proves ordered signaling
through the same recovered `0055fb30` file-event adapter. It separately checks
the bounded formatter span helper. The packet makes no call-edge claim between
timer diagnostics and formatting.

The source image is `Porsche.exe`, SHA-256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
Run118's three functions have nine original-x86 cases; Run119's six helpers
have eleven; Run122's auxiliary signal has three. The Run121 verifier refreshes
those component proofs into its own report folder, then checks three composed
native cases and a span-helper case against the component-proven algorithms.
Historical reports under Runs118/119/122 are not overwritten.

The common production sources use the existing timer/thread/event/rate owners:
`timer_setup.cpp` owns the timer state and persistent 28-byte record at
`006b7c60`; `clock_worker.cpp` owns the event and active cells; `file_events.cpp`
owns `timer_rate_005deb48`; `auxiliary_wait.cpp` owns its BSS event cell
`0069e5dc`. The new timer platform bridge binds the five recovered timer
boundary signatures directly to WinMM and the `winmm` library. Its auxiliary
bridge calls recovered `0053c270`, which reaches canonical `0055fb30`.

The three composed cases verify worker-event then auxiliary-event order,
auxiliary-only signaling, and the timer saved-clock suppression with a null
auxiliary handle. The final case writes `A, NUL, 0xff` through the recovered
Run119 span helper and checks the remaining capacity, count, and all 16 opaque
descriptor-tail bytes.

Important boundaries remain explicit. Timer setup's diagnostic callback at
`005debf0` is unknown; the composed probe does not invoke that path, and its
link-only diagnostic fixture is not part of production. Run119's 32-byte
descriptor tail is preserved as opaque state; the cleanup call at `005a4259`
is not connected to Run108's 16-byte descriptor or to a guessed adapter. The
1,825-byte parser `005a4371` is not linked or simulated. WinMM outcomes are
controlled only in the component oracle fixtures; the composed timer-tail
cases do not schedule a live timer or create host threads. The end-to-end
WM_CLOSE producer remains unverified.

Common build targets added by this packet are `timer_setup_probe`,
`formatter_original_probe`, `auxiliary_wait_probe`, and
`startup_timing_integration_probe`. The integration report pins all compiled
translation units, quoted headers, component verifiers, packet CMake/README,
and the original module SHA.

Run the common build once from the repository root, then refresh Run121 reports
with the common probe binaries:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File scripts/build-v2.ps1 *> local/reports/v2-common-build-121.log
py -3 scripts/research/verify-v2-formatter-timer-integration.py `
  --probe local/builds/v2/001-original-recovery/bin/Release/startup_timing_integration_probe.exe `
  --timer-probe local/builds/v2/001-original-recovery/bin/Release/timer_setup_probe.exe `
  --formatter-probe local/builds/v2/001-original-recovery/bin/Release/formatter_original_probe.exe `
  --auxiliary-probe local/builds/v2/001-original-recovery/bin/Release/auxiliary_wait_probe.exe `
  --report-dir iterations/v2/001-original-recovery/runs/121-formatter-timer-integration/common-proof
```
