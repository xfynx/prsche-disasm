# Run 093 — startup movie and load-screen setup

This run reconstructs `004dd600` (`004dd600..004dd9f3`, 1,012 bytes) from
Porsche.exe SHA-256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
The recovered function is reached from `004b6a50` only when FE mode is enabled,
the setup loop has not started, and `0065743c` (`NOINTROMOVIES`) is zero. That
gate controls this optional intro/setup-video pass; the caller continues into
the mandatory game setup path when the flag is nonzero.

The direct caller reapplies mode `(640,480,0x10,2)`, formats and probes
`%searts-av.mad` using BSS pointer cell `0065b32c`, and, when present, builds a
resource object and calls `004dc850(stream,&stop,0,3,0)`. It then calls the
independent movie pass `004dd4a0`, reapplies the mode, and probes
`%sloadscrn.fsh` using BSS pointer cell `0065b334`. When the second resource is
present, it runs six layers of five relative-pointer tables. The loops yield
45 draw calls per layer with exact DWORD index steps, table offsets, argument
constants, render begin/end calls, and the recovered `00531f90` resource free.

`004dc850`, `004dd4a0`, path formatting, file/resource services, item rendering,
and unresolved display-slot calls remain typed boundaries. BSS cells
`0065b32c`, `0065b334`, and `0069ed0c` are external inputs; this run does not
define another owner for them. It reuses `render_display_reconfigure_00467fc0`,
`window_shutdown_prepare_00534550`, and `free_00531f90` by their recovered
interfaces. This proves complete local control flow and boundary arguments;
it does not reconstruct playback, CRP loading, draw effects, or the unknown
callee internals.

The verifier compares boundary order and arguments against the original x86
body over missing/present first and second resources, zero/nonzero media range,
wrapped length, and stop output cases. It fails on any unexpected original
call target.

```powershell
& 'local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' -S `
  iterations/v2/001-original-recovery/runs/093-game-setup `
  -B local/builds/v2/game-setup-093 -A Win32
& 'local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' --build `
  local/builds/v2/game-setup-093 --config Release
py -3 scripts/research/verify-v2-game-setup.py `
  --report-dir iterations/v2/001-original-recovery/runs/093-game-setup
```
