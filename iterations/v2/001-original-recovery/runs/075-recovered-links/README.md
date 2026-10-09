# Run075 — canonical callee links for recovered callers

Original Porsche.exe SHA256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
The Run067 COFF audit identified callers whose external link names still refer to original addresses with verified C++ bodies. `adapters.json` records 16 caller names, canonical bodies, argument/return contracts, accepted callee proofs and indexed original callsites. The implementation invokes those bodies directly; it adds no game algorithm or approximated service.

The original assembly confirms `005367b0` is exactly `XOR EAX,EAX; RET`, and `00564850` jumps to `00564ab0`; neither reads the extra caller stack arguments. Both sides are cdecl, so callers retain stack cleanup. Ignored EAX values remain ignored. The allocation size conversion preserves the original 32-bit pattern under MSVC x86. Known addresses with incomplete internal branches, including `00532e10` and invalid-path branch `0059d650`, are deliberately not aliased back into their own entries.

The isolated static-library build checks the typed declarations and x86 ABI. This run does not claim a joint original-x86 runtime proof or whole-game link; existing independent consumer/callee reports remain the semantic evidence. Composition proofs are separate.

```powershell
. ./scripts/tool-env.ps1
cmake -S iterations/v2/001-original-recovery/runs/075-recovered-links -B local/builds/v2/recovered-links-075 -G "Visual Studio 17 2022" -A Win32
cmake --build local/builds/v2/recovered-links-075 --config Release
```
