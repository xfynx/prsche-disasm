# Run073 — joint renderer mode/settings/state proof

Original: `Porsche.exe`, SHA256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`. The joint proof compiles the existing production translation units `render_mode.cpp` (Run063), `render_settings.cpp` (Run066), and `render_state_init.cpp` (Run071) without changing their headers, definitions, or canonical global owners. It executes query `0x44e720`, commit `0x44ebf0` (which calls `0x44e890`), then `0x44ed10`, which selects the ordinary updater or `0x44f020` from state byte `0x619800`. The internal `0x535b40` is also executed as the actual original/C++ function.

Original-first index navigation began at `research/binary-index/README.md`, then checked the Porsche.exe `functions.jsonl`, `calls.jsonl`, `references.jsonl`, and `unresolved-calls.jsonl` entries for `0044e720`, `0044ebf0`, `0044e890`, `0044ed10`, `0044f020`, and `00535b40`. Exact function ranges, callsites and global references were compared with the immutable disassembly/decompilation corpus. The source SHA is recorded in the generated verification report.

The Unicorn oracle and native Win32 fixture compare all ten mode-query words, the full `0x619790..0x619800` state block, applied mode and time/option globals, settings globals, config output bytes, and the ordered external call trace. Fixtures cover fullscreen fallback, table-backed driver modes, format-15 normalization, device-ID/type/config branches, and both normal and alternate state update paths. Only unresolved driver/API/config/clock boundaries use deterministic typed recorders; the recovered consumers and `0x535b40` are executed directly.

The probe owns isolated backing for canonical renderer globals and synthetic device/driver memory; production state/settings globals remain defined once by their existing owners. `verification.json` contains source/header dependency hashes, the probe hash, inputs, full outputs, and boundary traces. This proves these joint call paths under supplied boundary results, not the external API implementations or live game startup.

```powershell
. ./scripts/tool-env.ps1
cmake -S iterations/v2/001-original-recovery/runs/073-render-state-integration -B local/builds/v2/render-state-integration-073 -G "Visual Studio 17 2022" -A Win32
cmake --build local/builds/v2/render-state-integration-073 --config Release --target render_state_integration_probe
py -3 scripts/research/verify-v2-render-state-integration.py
```
