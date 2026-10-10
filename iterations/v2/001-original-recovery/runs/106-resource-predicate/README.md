# Run 106 — rooted and unrooted resource path predicate

This run recovers `0059dd00..0059ddc5` (198 bytes) from `Porsche.exe`, SHA-256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`. The
function takes one path pointer, uses cdecl caller cleanup, and returns the raw
32-bit result from its final predicate call.

When `file_roots_enabled_006af370` is zero, the body copies the input to its
260-byte local path buffer and calls `00561ba0`. When roots are enabled, it
formats `file_root_006af168 + input` through the canonical formatter, probes
that path through `file_exists_00561b80`, and calls `00561ba0(candidate)` if
the probe succeeds. If it misses, the function optionally formats and checks
`file_fallback_006af26c`; a successful fallback also goes to
`00561ba0(candidate)`. After both rooted paths miss it invokes the nullable
callback `missing_file_006afbe4(input, -2)` and returns zero. The unrooted and
successful rooted paths return the raw `00561ba0` value, including zero or a
negative value.

The function is deliberately compared against `0059dc30`. Rooted misses share
their fallback/diagnostic trace. At a rooted hit, `0059dd00` returns
`00561ba0(candidate)`, while `0059dc30` calls `00561b80(candidate)` again and
returns that raw value. With roots disabled, `0059dd00` calls `00561ba0(input)`
while `0059dc30` calls `00561b80(input)`. The device/resource service remains
an explicit unknown-effect boundary. The fixture records paths, raw returns,
probe order and callback arguments; it does not simulate filesystem or device
semantics. The fixed `005a0fbf` formatter call is tested only with paths that
fit the original local buffer.

Seven differential cases cover disabled roots, exact raw return propagation,
primary and fallback hit/miss, a successful file gate whose resource-service
return differs, the nullable callback path, and the explicit comparison to
`0059dc30`.

```powershell
& 'local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' -S `
  iterations/v2/001-original-recovery/runs/106-resource-predicate `
  -B local/builds/v2/resource-predicate-106 -A Win32
& 'local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' --build `
  local/builds/v2/resource-predicate-106 --config Release
py -3 scripts/research/verify-v2-resource-predicate.py `
  --probe local/builds/v2/resource-predicate-106/Release/resource_predicate_probe.exe `
  --report-dir iterations/v2/001-original-recovery/runs/106-resource-predicate
```
