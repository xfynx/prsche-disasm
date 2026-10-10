# Run 109 — resource-service leaf

This run recovers `00561ba0..00561bd6` (55 bytes) from `Porsche.exe`, SHA-256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`. It is
one path-pointer argument, cdecl/caller-clean, and returns the raw EAX from the
final dispatcher call.

The body stores the incoming path pointer in a 16-byte stack context, writes
`1` at context offset `0x0c`, and leaves offsets `0x04` and `0x08` opaque. It
calls the existing typed `file_device_name_00568e90(path)` service, then calls
`00568d50` with `(callback=00561be0, device, [005df770], context)`. The
context's first field is the path pointer and its `+0x0c` field is `1`. The
path-pointer word left at the dispatcher callsite is not an argument to the
four-argument cdecl ABI. The leaf does not call
`file_exists_00561b80`; that function routes through `00533f00`, so the two
VAs are not aliases.

`00568d50` is an unrecovered 247-byte FILESYS atomic dispatcher and
`00561be0` is a separate unrecovered callback body. Both remain typed external
boundaries. The isolated fixture records the callback token, route, device,
group, path and initialized context flag; it does not invoke the callback
or emulate FILESYS/device effects. `005df770` has no canonical production owner
in the current source tree, so this package declares its external typed symbol;
the probe supplies its fixture definition.

The Unicorn comparison hooks both external service boundaries and checks their
exact argument order, context writes, raw return, callee-saved registers, and
caller cleanup across three route/group/result cases. It also executes
`00561b80` under a distinct `00533f00` boundary to show the existing file
predicate has different calls and effects.

```powershell
& 'local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' -S `
  iterations/v2/001-original-recovery/runs/109-resource-leaf `
  -B local/builds/v2/resource-leaf-109 -A Win32
& 'local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' --build `
  local/builds/v2/resource-leaf-109 --config Release
py -3 scripts/research/verify-v2-resource-leaf.py `
  --probe local/builds/v2/resource-leaf-109/Release/resource_leaf_probe.exe `
  --report-dir iterations/v2/001-original-recovery/runs/109-resource-leaf
```
