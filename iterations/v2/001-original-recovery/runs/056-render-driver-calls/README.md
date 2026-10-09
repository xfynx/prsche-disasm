# Run056 — THRASH video dispatch and renderer configuration staging

Original: immutable `local/game/Porsche.exe`, SHA256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`. Binary-index navigation: `research/binary-index/README.md`; `rg '00537600|005376c0|005726f0|00572990|00572a00|005728b0' research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d`. Original bodies and callsites are in `research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm` and `decompiled.c`.

`0x5376c0` is a cdecl five-word adapter returning the selection result from `0x572a00`. That consumer dispatches through the canonical loader export slot at VA `0x6bd934` (`render_thrash_exports_006bd910`), reads the returned about record's count at `+0x3c` and mode-record pointer at `+0x40`, then compares 1-based records with stride `0x28`. `0x572990` reproduces the original signed threshold checks and format-score weighting; `0x572a00` selects the first exact match or the lowest signed score, returning 0 when no record matches. `render_loader_about_006bd934` remains the explicit function-pointer adapter boundary.

`0x537600` is a cdecl six-word void adapter. It stores the six original words to `0x69e094`, `0x69e08c`, `0x69e090`, `0x69e070`, `0x69e074`, and `0x69e06c`; then it forwards words 1, 2, 4, and 5 to `0x5726f0`. That routine stores them at `0x6a643c`, `0x6a6438`, `0x6a6430`, and `0x6a6434`, and calls `0x5728b0` with the pre-existing values at `0x6a6448`, `0x6a6444`, `0x6a6440`, and a literal zero. The body at `0x5728b0` is outside this package and remains a typed four-argument cdecl boundary. All newly owned globals are declared once in `render_driver_calls.hpp`.

The isolated MSVC Win32 probe differentially executes the original x86 wrappers, mode selector/comparator and configuration stores. Eleven fixtures cover empty/matching/nearest mode sets, exact results, signed limits and score overflow behavior, all six stored wrapper words, forwarded dimensions, downstream argument order and caller stack cleanup. This proves the recovered bodies through the explicit `0x5728b0` boundary; it does not prove renderer/window behavior behind that boundary or a game launch.

```powershell
. ./scripts/tool-env.ps1
cmake -S iterations/v2/001-original-recovery/runs/056-render-driver-calls -B local/builds/v2/render-driver-calls-056 -G "Visual Studio 17 2022" -A Win32
cmake --build local/builds/v2/render-driver-calls-056 --config Release --target render_driver_calls_probe
py -3 scripts/research/verify-v2-render-driver-calls.py
```
