# Run055 — native Win32 core bindings

The platform library forwards the existing typed imports to real Win32: page allocation, events, waits, threads, handle duplication, sleep, and critical sections. It does not replace original algorithms. Import/ABI evidence is retained in Runs006/009/010/014/025 and the corrected IAT index for Porsche.exe SHA256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.

The native fixture executes recovered file_events.cpp and file_pages.cpp against these bindings: auto/manual event behavior, wait selection/timeout, last-error preservation, rounded real page allocation/release, a suspended Win32 worker and duplicated handle, recursive locks and protected publication. Its worker callback is test infrastructure. It does not execute original thread startup or the game, and is not an original-x86 differential proof. No new recovered-function count is attached to these infrastructure adapters.

```powershell
. ./scripts/tool-env.ps1
cmake -S iterations/v2/001-original-recovery/runs/055-native-platform -B local/builds/v2/native-platform-055 -G 'Visual Studio 17 2022' -A Win32
cmake --build local/builds/v2/native-platform-055 --config Release --target native_core_smoke
& ./local/builds/v2/native-platform-055/bin/Release/native_core_smoke.exe
```

The next integration uses the same platform library with recovered thread startup/shutdown and callback registry, retaining unresolved game boundaries explicitly. The fixture is separate from comparison probes so real OS effects do not replace their deterministic boundaries.
