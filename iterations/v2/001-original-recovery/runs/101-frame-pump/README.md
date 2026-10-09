# Run 101 — frame pump `004b0d70`

This run restores the complete 318-byte, no-argument function `004b0d70` from
`Porsche.exe`, SHA-256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
The indexed caller set includes the repeated calls from `004b67b0`, plus
`004a4a70`, `004b0fa0`, and the startup/movie path at `004dda00`. The name
“frame pump” describes this recovered call pattern; the algorithm itself is
kept address-based.

The implementation preserves both flag gates. When byte `006573e1` is set and
`006573e2` is clear, it calls the existing `window_shutdown_prepare_00534550`
boundary and `004ab150`, copies `00655a08` to `006573d4`, sets the tick word to
one, conditionally calls `005693e0` when `006573e4` is nonzero, flushes, sets
display state `(0x6c, 1)`, and sets `006573e2`. It then returns if
`006573e0` is nonzero or `006573e2` is clear. Otherwise it clears bytes
`006573e1/2`, sets display state `(0x6c, 0)`, calls movie-object vtable slots
`+0x20` and `+0x1c` in order (passing the first result to the second), performs
three ordered window/clear/update/sync groups, conditionally calls
`00568f30` with the six original stack arguments, calls `005360a0` and
`005363a0`, flushes, selects window 2, calls `004ab200`, and restores the tick
word from `006573d4`.

The globals from `006573b8` through `006573e7` share one 0x30-byte backing
object. Known DWORD and byte views alias that storage; untouched bytes remain
opaque. `00655a08` is a separate DWORD. The x86/native cases compare every byte
in the 0x30-byte span, the tick word, and the ordered boundary trace, including
the six argument values at `00568f30` and the movie-slot return/input value.
The x86 oracle also checks ESI and return-stack restoration. Cases cover both
early gates, both `006573e4` branches, and the first-stage transition into the
second stage.

The internal behavior of `004ab150`, `004ab200`, `005693e0`, `00568f30`,
`005360a0`, `005363a0`, and dynamic movie vtable targets is not claimed here;
they are explicit recording boundaries in this probe. Production calls reuse
the existing display and shutdown APIs, and preserve the original boundary
arguments/order without modeling those services as no-ops.

```powershell
& 'local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' -S `
  iterations/v2/001-original-recovery/runs/101-frame-pump `
  -B local/builds/v2/frame-pump-101 -A Win32
& 'local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' --build `
  local/builds/v2/frame-pump-101 --config Release
py -3 scripts/research/verify-v2-frame-pump.py `
  --probe local/builds/v2/frame-pump-101/bin/Release/frame_pump_probe.exe `
  --report-dir iterations/v2/001-original-recovery/runs/101-frame-pump
```
