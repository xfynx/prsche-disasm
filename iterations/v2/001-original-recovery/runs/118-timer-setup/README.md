# Run 118: multimedia timer setup

This packet restores the bounded original timer cluster in `Porsche.exe`
(`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`):

- `00564eb0..00564f76`, 199 bytes: five-argument stdcall multimedia callback,
  `RET 0x14`;
- `00564fa0..00565022`, 131 bytes: zero-argument cdecl cleanup;
- `00565030..0056526d`, 574 bytes: one-argument cdecl setup.

The call-site evidence is `004a5410..004a5444`: it pushes interval `0x80`
before calling `00565030`. The setup derives `0x03e80000 / interval`, clears
the Run112 carry and iteration owners, calls the actual `WINMM!timeGetDevCaps`
IAT (`005b2340`), and writes period `1` to the two local capability words.
`timeBeginPeriod`, `timeSetEvent`, `timeKillEvent`, and `timeEndPeriod` are at
`005b233c`, `005b2348`, `005b2344`, and `005b234c`. The exact WinMM IAT names
were checked against `research/binary-index/static/imports.jsonl`.

The callback performs the original 16.16 phase accumulation and signed
`delta - 1` comparisons. It chooses `timeSetEvent` delay from that comparison,
uses the existing Run112 `clock_worker_active_006a5c0c` and
`clock_worker_event_006a5bfc`, and writes the canonical file-event timer rate
`timer_rate_005deb48`. `0055fb30` is the recovered `SetEvent` wrapper, reused
through `file_event_signal_0055fb30`; it is not a wait API. The new timer state
owners are only the unique words at `006a5bf8`, `006a5c00`, `006a5c04`,
`006a5c08`, `006a5c10`, `006a5c1c`, and `006a5c20`.

The setup calls the existing recovered `window_thread_start_0055f420` with the
original callback, stack, priority, unused value, and persistent output record
at `006b7c60` (28 bytes, ending before `clock_worker_iterations_006b7c7c`).
`ThreadRecord` is the existing canonical layout. The oracle and native fixture
assert the pointer identity, seed all seven DWORDs, and model successful
thread-start writes to every field; failure leaves the record unchanged. Its
asynchronous thread body remains the Run112 worker. The oracle fixture
intercepts thread start, CRT exit registration (`00557380`), the diagnostic
function pointer at `005debf0`, and call entry to `0053c270`; it records calls
without modelling those callees. Production keeps `0053c270` as the explicit
`timer_auxiliary_wait_boundary` pending canonical integration. `GetTickCount`,
`SleepEx`, `SetEvent`, and all five WinMM functions are controlled import
boundaries. This proof does not claim OS timer scheduling or a live threaded
timer run.

Nine differential cases cover successful setup with `0x80`, rejected input
with the original `%d` diagnostic argument, capability failure, thread
creation failure, `timeBeginPeriod` failure, zero `timeSetEvent` result,
existing-active cleanup including the timer-ID poll, the signed slow-clock
correction path, and cleanup where `window_idle_0055f740` clears the event
handle while the timer ID remains nonzero. The final case checks the original
loop's live re-test of both globals after each idle call. The verifier compares the three original function bodies
against production C++ with Unicorn x86, including owned globals, ordered
boundary calls, callee-saved registers, and caller stack cleanup. It checks
the indexed ranges and original PE SHA before running.

Build and run the isolated fixture without editing common CMake:

```powershell
. .\scripts\tool-env.ps1
cmake -S iterations/v2/001-original-recovery/runs/118-timer-setup `
  -B local/builds/v2/timer-setup-118 -G "Visual Studio 17 2022" -A Win32
cmake --build local/builds/v2/timer-setup-118 --config Release
py -3 scripts/research/verify-v2-timer-setup.py `
  --probe local/builds/v2/timer-setup-118/bin/Release/timer_setup_probe.exe `
  --report-dir iterations/v2/001-original-recovery/runs/118-timer-setup
```

The pending end-to-end WM_CLOSE producer and a live timer-driven worker remain
unverified; Run118 covers setup, callback arithmetic, and cleanup under
controlled API outcomes only.
