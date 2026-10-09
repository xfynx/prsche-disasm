# Run038 — original window handler table and short callbacks

Source: immutable `local/game/Porsche.exe`, SHA256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`. Original bytes are from `research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm`; the binary index is navigation, not the semantic proof. Run029 traces the startup consumer `0x53ac20`, which registers 27 message/key-handler pairs through `0x53a800` before starting worker `0x53b8d0`.

`0x53a800..0x53a8db` is the table mutation routine (`RET 8` ends at `0x53a8db`). It ensures shared lock `0x69e59c`, calls the game-pump wrapper `0x5322b0`, binary-searches the shared 8-byte `(message, callback)` rows at `0x69e0e0` with count `0x69e570`, and releases the lock through `0x5322c0`. Existing keys replace callbacks; a null callback marks the matching row `0x7fffffff`, sorts, then decrements count; a new non-null key appends/sorts only while count is below 128. Full-table insertion and missing-key removal leave the table unchanged. Search and comparison use the shared recovered `original_binary_search_005a2f23` and `window_message_compare_0053a7f0`. The original sort routine `0x5a112b` remains an explicit typed call boundary in production. Only the probe supplies host CRT qsort for unique bounded startup message IDs; its implementation and comparator-call ordering are not claimed as recovered. Valid startup entries are unique message IDs, so the observed table state matches the original on the tested cases.

The registration entry returns the original `EDI` result in `EAX`: 1 for replace/remove/insert, 0 when the request changes nothing. Its public ABI is `uint32_t __stdcall` with `RET 8`; the native x86 fixture compares this return as well as the table and lock state.

The eight callbacks recovered here all have six stdcall arguments and `RET 0x18`. Their exact consumer registrations in `0x53ac20` are:

| Message | Callback | Recovered behavior |
|---:|---:|---|
| `0x001c` | `0x53b040` | Copies argument 4 (`wParam`) to shared running state `0x6b7c14`; returns 0. |
| `0x0010` | `0x53b230` | Calls `PostQuitMessage(0)` when config is non-null and HWND equals shared HWND; returns 1. |
| `0x0466` | `0x53b260` | Sets worker message state `0x69e578` when config is non-null and HWND matches; returns 1. |
| `0x0002` | `0x53b290` | Returns 0 unconditionally. |
| `0x0112` | `0x53b2a0` | Returns 0 for SC_CLOSE/MINIMIZE/MAXIMIZE/KEYMENU; otherwise returns config byte `+0x461`. Original dereferences config in this latter branch without a null guard. |
| `0x001a` | `0x53b2e0` | On matching config/HWND with byte `+0x461`, queries SystemParametersInfo actions `0x10` and `0x54`, then conditionally restores via `0x11` and `0x56`; writes zero to result and returns 0. |
| `0x0014` | `0x53b870` | Returns 1 only when config is non-null, HWND equals the shared HWND and config DWORD `+0x458` equals HWND, and config byte `+0x461` is set. |
| `0x0218` | `0x53b8b0` | Writes `0x424d5144` to result and returns 1. |

The registration table shown above is a subset of Run029's complete 27 registration sites; remaining long callbacks are outside this run. `window_handler_register_0053a800` operates on the shared `WindowHandlerEntry[128]` and count declared by `window_procedure.hpp`; production copies of those globals were not introduced. `class_lock_0069e59c`, `window_hwnd_006b7bf8`, running and saved parameter globals also use their existing shared owners. The probe defines only fixture state and Win32/game-call boundaries.

`py -3 scripts/research/verify-v2-window-handlers.py` compares registration mutations and all eight handlers against execution of the original x86 image. It passed 87 cases, including replace/remove/insert/full capacity, lock creation, HWND/config/flag branches, four system-command values, SPI save/restore combinations and result writes. `verification.json` stores source/probe hashes and per-case outputs. `0x5321f0`, USER32 `PostQuitMessage`/`SystemParametersInfoA`, and the two USER32 calls beneath `0x5322b0/0x5322c0` are controlled boundaries; original search, comparator, qsort, and callback instructions execute from the x86 image. Game launch and real Win32 event behavior are not claimed.

Build/proof:

```powershell
. .\scripts\tool-env.ps1
cmake -S iterations/v2/001-original-recovery/runs/038-window-handlers -B local/builds/v2/window-handlers-038 -G "Visual Studio 17 2022" -A Win32
cmake --build local/builds/v2/window-handlers-038 --config Release --target window_handlers_probe
py -3 scripts/research/verify-v2-window-handlers.py
```
