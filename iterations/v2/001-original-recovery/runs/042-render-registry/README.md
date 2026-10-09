# Run042 — render core registry consumers

Original: `Porsche.exe` SHA256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`. Index query: `rg '004b7220|004b7240|004b7340|004b7150|004b76f0|005d6f28|005d7064' research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d -g '*.jsonl'`. The manually absent core-first entry was traced directly in `disassembly.asm` at `004b76f0..004b77c9`; its slot+8 target is `004b7150`. `004b7220`, `004b7240`, `004b7340`, and `004b7150` use their indexed function bodies and the shared default table at `005d6f28`.

The first routine opens the two legacy product aliases under `HKLM\SOFTWARE\<company>\<product>`; an existing alias sets byte `core+0x110` and returns 1. Otherwise it opens the title path, creates it only when that open failed, and dispatches vtable slot+8 only after successful create. It sets the flag and returns whether the title open succeeded. The original virtual default writer emits nine table rows via `RegSetValueExA`; text and numeric getters query, write the selected default after a failed query, then query again. Text copies the returned byte count when `<256`, otherwise writes the original `.data` fallback byte `0xd1` at `0x5e8e50`. Close uses the stored key then clears the flag.

The table rows and types are decoded from the binary: `Thrash Driver`=`dx`, `D3D Device`=0, `Thrash Resolution`=`640x480`, `Hardware Acceleration`=1, `Triple Buffer`=0, `Language`=`English`, `Primary Address`=`porsche-entry.earacing.com`, and both version strings=`0.0`. String byte sizes exclude the NUL; DWORD sizes are four. Unresolved behavior remains at typed Advapi32 API boundaries. The fixture intercepts those calls and compares ordered inputs, call results, core/output bytes and returns with the original x86 entries; it does not modify the host registry.

Reproduce with Win32 MSVC:

```powershell
. ./scripts/tool-env.ps1
cmake -S iterations/v2/001-original-recovery/runs/042-render-registry -B local/builds/v2/001-original-recovery/render-registry-042 -G 'Visual Studio 17 2022' -A Win32
cmake --build local/builds/v2/001-original-recovery/render-registry-042 --config Release --target render_registry_probe
py -3 scripts/research/verify-v2-render-registry.py
```

`verification.json` records x86/native equality, source provenance and explicit function coverage. It covers the five named registry functions and vtable default writer only; complete render initialization and live Windows registry integration are not claimed.
