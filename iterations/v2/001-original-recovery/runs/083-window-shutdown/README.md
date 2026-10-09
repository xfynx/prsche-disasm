# Run 083 — scheduled window shutdown callback

This run reconstructs the timer callback at `0053bae0` and the exact null-input
cleanup path it reaches through `00534550 -> 00534480 -> 00534430` in the
original `Porsche.exe` SHA-256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
The binary index records `00534430` as 80 bytes (`00534430..0053447f`),
`00534480` as 169 bytes (`..00534528`), `00534550` as 9 bytes
(`..00534558`), and `00557370` as 7 bytes (`..00557376`); `005a246e` is
indexed noreturn. The disassembly gives `0053bae0..0053baf9` as the 26-byte
callback body even though it has no separate function record in the metadata.
The original callback has two cdecl DWORD arguments because `005366e0` pushes
callback context and elapsed time; `0053bae0` reads neither. It calls the
cleanup path, removes its own callback using `005366a0`, then reaches
`00557370 -> 005a246e(0)`. The final process termination body remains a
terminal boundary.

For this caller, `00534480` receives null. After `00534430`, it fills exactly
48 bytes at `005de620` with the DWORD pattern zero using `0053c290`, copies the
two original `.data` bytes at `005de65c/65d` to `005de62c/2d`, and returns one.
The original file-backed 48-byte destination is initially zero; the adjacent
source bytes at `005de65c/65d` are `00 00` (the next byte at `005de660` is `01`). The non-null `00534480` branches are explicitly
outside this run.

`00534430` returns immediately when `0069dd18` is null. Otherwise it closes
that handle through the stdcall target stored at `006bd92c`, clears
`005de64c`, reads the mode byte at `005de630`, clears
`005de67c` for mode 1 or `005de6ac` for mode 2, clears the handle, and invokes
the stdcall target stored at `006bd9b0` with zero. Stack provenance proves
callee cleanup: after that call, `00534478` restores the saved ESI and `0053447f`
returns to its caller. The close and display targets remain typed recording
boundaries. The callback table is the existing
16-entry scheduler state; the fixture links the accepted Run082 removal
implementation.

The verifier compares state, timer slots, boundary arguments and event order
against original x86 through the terminal exit call. It varies mode, handle,
post-close mode changes, all three `0053c290` fill dispatches, duplicate timer
entries and both ignored callback arguments. No game launch is performed.
The next concrete consumer is the non-null `00534480` branch, which enters
`00534360` and can reach allocator `00535950`; that distinct setup path remains
open.

```powershell
& 'local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' -S `
  iterations/v2/001-original-recovery/runs/083-window-shutdown `
  -B local/builds/v2/001-original-recovery/window-shutdown-083 -A Win32
& 'local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' --build `
  local/builds/v2/001-original-recovery/window-shutdown-083 --config Release
py -3 scripts/research/verify-v2-window-shutdown.py
```
