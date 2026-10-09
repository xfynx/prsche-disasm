# Run 102 - recovered game EXE link frontier

This run makes a concrete Win32 GUI executable link attempt from the recovered
`Porsche.exe` entry path. Its native `WinMain@16` forwards the four host values
to `porsche::win_main_004b6710`, the recovered stdcall body in
`source/recovered/Porsche.exe/startup.cpp`; that body calls recovered cdecl
`app_main_004b6a50` from `application_main.cpp`. No engine/game boundary is
defined by the host or a fixture.

`porsche_original_game_link` is `EXCLUDE_FROM_ALL`. It links the common
`porsche_original`, `porsche_recovered_links`, `porsche_window_links`,
`win32_window_bindings`, and `porsche_platform_win32` targets, plus their Win32
system dependencies. Standalone configure adds the iteration CMake in a
private build tree; it does not write to the shared common build directory.
The target is not run, even if linking succeeds.

The expected result at this stage is a failed link with reachable unresolved
callers. `link-report.json` records every unique LNK2001/LNK2019 symbol, all
referencing objects/functions, and source closure hashes. It groups the current
unresolved frontier into VA-named original callables and semantic
service/vtable boundaries, and keeps the raw linker exit status. The complete
MSBuild transcript is saved under `local/reports/`.
Compiler errors and unrelated linker errors are reported separately, so a
compile failure cannot be presented as a completed link attempt. A successful
link would still prove only that this target resolved, not that the game runs.
MSVC's final `LNK1120` unresolved-count line is retained separately from
independent linker diagnostics because it summarizes the recorded LNK2001/2019
frontier.

```powershell
. ./scripts/tool-env.ps1
cmake -S iterations/v2/001-original-recovery/runs/102-original-game-link `
  -B local/builds/v2/original-game-link-102 `
  -G 'Visual Studio 17 2022' -A Win32
py -3 scripts/research/verify-v2-original-game-link.py `
  --build-dir local/builds/v2/original-game-link-102 `
  --report iterations/v2/001-original-recovery/runs/102-original-game-link/link-report.json `
  --log local/reports/v2-original-game-link-102-msbuild.log
```
