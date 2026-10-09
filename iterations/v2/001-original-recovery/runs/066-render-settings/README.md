# Run066 — renderer settings consumer

Source: `Porsche.exe`, SHA256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`. Original-first lookup starts at `research/binary-index/README.md`. In `ghidra/Porsche.exe-ddd748fdbe6d/functions.jsonl`, `0044e890` is bounded at `0044ebe5` (854 bytes); `calls.jsonl` records the caller from `0044ebf0` and config calls to `005a1e10`. `unresolved-calls.jsonl` records engine API slots `006bd934`, `006bd984`, `006bd97c`; the two config keys are indexed as `Trident Blade` at `005ce924` and `Voodoo` at `005ce91c`. The immutable disassembly and decompilation files provide the instruction and control-flow evidence; source hashes are saved in `verification.json`.

The recovered cdecl consumer updates Run063's canonical state block at `00619790..00619800`, reads the applied width/height/format globals, and reads global DWORD `00657da4` (producer semantics remain unresolved). It records original renderer state API calls in order, selects signed minimum from device offsets `+0x14/+0x20`, copies `+0x44` and `+0x70`, and follows the observed device-ID/type branches. No second renderer-state or applied-mode storage is defined. The isolated probe owns stand-in storage only for those canonical symbols.

Typed boundaries left outside this function are: `006bd934` current-device lookup (cdecl, no args); `006bd984` get state (stdcall, one DWORD); `006bd97c` set state (stdcall, two DWORDs); and `005a1e10` config lookup (cdecl, output pointer and string key). Device byte offsets are modeled only where this consumer reads them. Full `0044f020` alternate-state initialization, renderer API implementations, original configuration parser behavior, and live renderer startup remain open.

Differential verification executes original x86 in Unicorn against the isolated MSVC Win32 C++ probe. It compares the full Run063 state block, device config-output bytes, unchanged applied-mode globals, exact ordered boundary calls/arguments/returns, and cdecl stack cleanup across the device-type, identifier, config, and flag branches. This proves the bounded consumer with supplied boundary results; it does not prove the external APIs or live game launch.

```powershell
. ./scripts/tool-env.ps1
cmake -S iterations/v2/001-original-recovery/runs/066-render-settings -B local/builds/v2/render-settings-066 -G "Visual Studio 17 2022" -A Win32
cmake --build local/builds/v2/render-settings-066 --config Release --target render_settings_probe
py -3 scripts/research/verify-v2-render-settings.py
```
