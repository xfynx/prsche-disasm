# Run 103 — FSH startup resource service

This run reconstructs `00427a60..00427ab0` (81 bytes) from `Porsche.exe`, SHA-256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`. Its
sole indexed incoming call is the ordered startup sequence at `004b67d1`.

The body reads the BSS pointer cell `0065b360`, formats `"%s%s.fsh"` with
`"pic16"` into a 100-byte stack buffer, then calls file-exists `0059dd00`,
resource-open `0059d8e0(path, 0)`, consumer `0048cb50(0, resource, exists)`,
and free `00531f90(resource)`, in that order. It has no branch. The final
`ADD ESP, 0x2c` releases the caller-owned arguments for all five cdecl calls;
the function itself takes no arguments and returns void.

The BSS cell has no recovered production owner in this source tree. The header
declares an external `const char*` owner so production integration can bind the
existing storage without a duplicate definition. The standalone fixture owns
only its test cell. File-exists `0059dd00` and consumer `0048cb50` remain
explicit typed effect boundaries; this run does not claim their internal
algorithms. Resource-open and free boundaries are checked for exact argument
order and pointer flow. Three cases vary the root string, signed existence
result, and null/non-null resource pointer.

The Unicorn oracle hooks only those five direct callees, applies their declared
return values, records their arguments/order, and verifies caller stack
restoration plus preservation of the enclosing function's callee-saved
registers. The native probe compares the same call trace and stack delta.
The formatter implementation at `005a0fbf` is still external; the fixture
emulates only this fixed format for prefixes that fit the original 100-byte
local buffer. Longer-path overflow behavior is outside this proof.

```powershell
& 'local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' -S `
  iterations/v2/001-original-recovery/runs/103-engine-service `
  -B local/builds/v2/engine-service-103 -A Win32
& 'local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' --build `
  local/builds/v2/engine-service-103 --config Release
py -3 scripts/research/verify-v2-engine-service-427a60.py `
  --probe local/builds/v2/engine-service-103/Release/engine_service_427a60_probe.exe `
  --report-dir iterations/v2/001-original-recovery/runs/103-engine-service
```
