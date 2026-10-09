# Run063 — renderer mode selection and state update

Source corpus: `Porsche.exe` SHA256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`. Index navigation started at `research/binary-index/README.md` and the Ghidra function/reference/unresolved-call tables for VAs `0044e720`, `0044ebf0`, and `0044ed10`; function bodies and callsites were then checked in the immutable `research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm` and `decompiled.c`.

Index evidence: `functions.jsonl` bounds the three bodies at `0044e720..0044e772`, `0044ebf0..0044ec79`, and `0044ed10..0044f009`. `calls.jsonl` links `0044ec71 -> 0044e890`, `0044ed1f -> 0044f020`, and `0044ed66 -> 00555bc0`; `unresolved-calls.jsonl` records indirect driver calls at `0044e755` and `0044ec1e`, plus IAT slot `006bd918` at `0044ed60`. `references.jsonl` records the read of `006197a6` at `0044eebf` and `00535b40` writing `0069dd1d` at `00535b44`. ASM confirms the ten-word copy, state switch, float conversion, and call cleanup used by the implementation and differential probe.

This package recovers the three complete assigned function bodies. `0x44e720` queries a ten-DWORD mode record at stride `0x28`; fullscreen writes only words 0, 1, 2, and 5. The non-fullscreen path calls driver vtable slot `+0x24` with `this` in ECX and no stack arguments, then copies ten words from driver `+8`. `0x44ebf0` commits mode index, width, height, and format to the canonical renderer globals; format 15 is normalized to 16. It then invokes the original `0x44e890` engine settings consumer through a typed boundary. `0x44ed10` implements the original float clamp, reads the four-entry table at `0x5ce90c`, and updates the state bytes and dwords. Its option-one condition reads state byte `0x6197a6`. The `0x535b40` callee is also recovered as a low-byte write to `0x69dd1d`.

The state block `0x619790..0x619800` has one owner here. Existing display pointer, applied-mode globals, and clock are references to owners in the accepted startup/display/activation sources; this package introduces no duplicate aliases. Remaining explicit boundaries are the driver virtual call, `0x44e890`, alternate state updater `0x44f020`, clock `0x555bc0`, and the two-DWORD stdcall state API reached through IAT slot `0x6bd918`. Their behavior is outside this recovery boundary.

Verification differentially executes original x86 against the isolated MSVC Win32 C++ probe. It checks full mode-query output including untouched sentinels, canonical commit globals, state-block bytes, boundary counts, and cdecl caller stack cleanup. The Unicorn image redirects out-of-scope callees to typed recording stubs; the state API stub models its stdcall argument cleanup. This is a bounded function proof and does not establish actual driver behavior or a live game launch. `verification.json` records fixtures and normalized source hashes.

```powershell
. ./scripts/tool-env.ps1
cmake -S iterations/v2/001-original-recovery/runs/063-render-mode -B local/builds/v2/render-mode-063 -G "Visual Studio 17 2022" -A Win32
cmake --build local/builds/v2/render-mode-063 --config Release --target render_mode_probe
py -3 scripts/research/verify-v2-render-mode.py
```
