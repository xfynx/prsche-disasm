# Run700 scene-reset leaf chain

Bounded native x86-vs-C++ recovery for two scene-stage reset leaves newly exposed by the integrated Run693 view lifecycle (`Porsche.exe` SHA-256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`):

- `porsche::scene_stage_reset_00458b80` (`00458b80..00458ba5`, 38B, `__cdecl`, sha256 `5f7024df69e4e24bea2fed2dabca34ba7fce328375c3c03623099688d65719c2`): allocates a 0x10-byte stage object via canonical `0059ef90`, constructs it through `00458c90` (`this` in ECX), publishes the returned pointer at `0x00627e08`, and writes zero on allocation failure.
- `porsche::scene_reset_00467f40` (`00467f40..00467f8c`, 77B, `thiscall`/`__fastcall(self,unused_edx)`, ECX/EDX unused, sha256 `5ccc6766cf272339e922c9f87b794b28a1e8ee8b1917ee69daad8a0e85b9731b`): resets the texture pool via canonical `0053c3d0`, reserves `0x1800000` via canonical `00553fc0`, reports success/failure through `005a177b` with the exact original `.rdata` strings at `0x005cf848`/`0x005cf81c`, then installs callback literal `0x004677d0` through `005556a0`. No original global is written.

Definitions match the accepted 693 extern declarations exactly; no owned cell is redefined. Canonical providers `0059ef90`/`0053c3d0`/`00553fc0` are reused; new owned cells are only `0x00627e08` (4B) and two 42B raw `.rdata` strings, verified against the pinned PE before relocation.

## Verification

- Receipt: `local/experiments/v2-scene-reset-leaf-chain-700/003/receipt.json` (sha256 `9c29029b9a4d6e80dba9b163969313756ab1f4971c71eafba6f420e9272185c6`).
- Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/700-scene-reset-leaf-chain/native-config.json --attempt 003`
- PASS at `/Od` and `/O2`, `/W4` 0 warnings, marker `scene_reset_leaf_original_x86_vs_cpp=PASS cases=6`; 8/8 material `wrong-*` mutations detected. Comparisons cover inputs, ordered intermediate event log, owned-global/stage-buffer outputs, ABI (ESP/EBP/nonvolatile preservation, EAX), and raw string witnesses. Attempts 001/002 are preserved harness-fix receipts (namespace-qualified stubs; 2 absolute-relocation sites).

## Ownership and exclusions

All eight target entry VAs are unowned in `source/recovered/functions.json`, including every `body_ranges` interval; no supplement file exists. The other six bodies are excluded with concrete evidence in `scope-evidence.json`:

- `0043ed00`, `00455f60`: capture `CL` from caller-stack slot `[ESP+0x13]` (high byte of entry ECX for these cdecl void bodies). Raw `004211d0` disassembly confirms the callee never writes that slot; fixing it would invent behavior. `005322b0/005322c0` also carry conflicting accepted ABI declarations.
- `00448b10`: 8-iteration stack-string/sprintf loop with unproven global owners (`0x5ccb84`, `0x5cdeac`, `0x65b30c`, `0x613e04..0x613e20`).
- `0044f240`: x87 table rewrite over >0x8000 bytes with raw constants/RNG and unproven table ownership.
- `00451490`, `004552b0`: large multi-constructor bodies with broad unproven global matrices (up to 8KB).

## Boundaries

Real `00458c90`/`005a177b`/`005556a0` bodies, live texture-pool state, the real allocator, full `00468fb0` composition, the six excluded bodies and production CMake/registry integration remain open. Synthetic callsite setup and RET are harness code only. No source consolidation, registry, plan, shared manifest or `local/game` change was made.
