# Run071 — alternate renderer state initialization

Source: `Porsche.exe`, SHA256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`. Original-first lookup began at `research/binary-index/README.md`; the Porsche.exe Ghidra index bounds `0044f020..0044f190` (369 bytes), records its call from `0044ed1f`, and lists callees `00555bc0` and `00535b40` plus indirect IAT `006bd918`. References enumerate the state/global reads and writes. The immutable ASM and decompilation were checked over the full body.

`0x44f020` is a complete alternate initializer, reached when byte `0x619800` selects it in Run063's `0x44ed10`. It submits key `0x2e` and a binary32 value clamped to `0.25`, stores the clock result, clears the display clock and state fields, initializes the alternate state bytes/dwords, applies the `0x657d60` and `0x657d68` branches, and conditionally changes flag bits using `0x6197a8`. Canonical state, settings and time globals remain owned by Run063; this source defines none of them.

Boundaries: `0x6bd918` is an indirect two-DWORD stdcall renderer-state setter and `0x555bc0` is a direct cdecl clock call. Their effects are supplied by deterministic recording stubs in the isolated original/native comparison. `0x535b40` executes as original x86 and was separately recovered in Run063 as a low-byte store. The original function leaves a value in EAX that its caller ignores; this package verifies caller-visible complete state and stack effects. It does not establish the external APIs, actual clock, driver behavior, or a game launch.

The Unicorn oracle and isolated MSVC Win32 probe compare the complete `0x619790..0x619800` block, time globals, option byte, exact ordered boundary calls and cdecl stack delta over twelve fixtures, including x87 float-clamp edges and both branches of each setting/state condition. `verification.json` records original SHA, source hashes and fixture outputs.

```powershell
. ./scripts/tool-env.ps1
cmake -S iterations/v2/001-original-recovery/runs/071-render-state-init -B local/builds/v2/render-state-init-071 -G "Visual Studio 17 2022" -A Win32
cmake --build local/builds/v2/render-state-init-071 --config Release --target render_state_init_probe
py -3 scripts/research/verify-v2-render-state-init.py
```
