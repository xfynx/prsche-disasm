# Run 132 — formatter cleanup (005a4259)

This packet restores the original 280-byte `Porsche.exe` function at VA `005a4259` and its bounded 41-byte `005abf35` character-device query. Evidence is pinned to Porsche.exe SHA-256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`; the verifier reads the indexed function/call graph and hashes the actual original bodies. Indexed direct callers are `005a0fbf` (call at `005a1005`), `005a299e` (`005a29e3`), `005a2ca2` (`005a2cf8`), `005a2faf` (`005a2ff3`), `005a2fff` (`005a3044`), `005a37bd` (`005a3882`), and `005a4ab2` (`005a4acf`).

The x86 oracle compares 23 direct cleanup/emitter-bridge cases, including early flag exits, flag-1 cursor reset, special stream identity, direct and buffered writes, short/failing writes, auxiliary calls, zero buffer size, and prepare callbacks that mutate flags/base/cursor/buffer size. It checks the full 32-byte descriptor after each call, output bytes, callback order/arguments, caller stack, callee-saved registers, and the emitter's returned count pointer. Event IDs are prepare `1`, write `2`, and auxiliary operation `3`; observed prepare-then-write paths match `[1,2]`. The `+0x14` and `+0x1c` words are opaque and preserved. `+0x10` is the file identifier; `+0x18` is read as buffer size only on the `flags & 0x108` path.

The PE `.data` virtual range extends beyond its raw data. The oracle maps raw sections and explicitly seeds BSS handle-table state at `006c01e0`, the preceding signed-bank cell at `006c01dc`, and limit `006c02e0`; it does not treat file bytes at `VA - ImageBase` as BSS contents. The `SAR` at `005a4304` makes file identifiers `-32..-2` address bank `-1`; `-1` uses the dedicated invalid-handle record.

File-write `005a9e49`, auxiliary file operation `005a9ab8`, and descriptor preparation/allocation `005abef1` are typed recordable boundaries. Their arguments, invocation order, and selected return values are checked; file backend, allocation, and other external state effects remain unresolved. Native stream aliases must bind the canonical owners for `005e5508` and `005e5528`; this packet does not create those owners. This is not a real-game or complete CRT claim.

Reproduce the isolated Win32 MSVC build and differential report:

```powershell
& 'local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' -S iterations/v2/001-original-recovery/runs/132-formatter-cleanup -B local/builds/v2/formatter-cleanup-132 -A Win32
& 'local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' --build local/builds/v2/formatter-cleanup-132 --config Release
py -3 scripts/research/verify-v2-formatter-cleanup.py --probe local/builds/v2/formatter-cleanup-132/Release/formatter_cleanup_probe.exe --report-dir iterations/v2/001-original-recovery/runs/132-formatter-cleanup
```
