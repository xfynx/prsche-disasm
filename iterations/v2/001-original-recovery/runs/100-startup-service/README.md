# Run 100 — shared startup no-op service leaf

This run recovers the complete one-byte function at `00516950` in `Porsche.exe`
SHA-256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
The binary-index body is the single instruction `C3 RET`, so it has no direct
callee, global access, state write, or argument cleanup.

The call/reference index records 91 incoming call edges and 57 data references.
The ASM contains 90 direct `CALL`s and one incoming tail `JMP` at `005229e0`
(the call index classifies that jump as a call edge). Eight direct callsites
have a pushed argument immediately before the call; later caller instructions
perform cleanup. These observations do not identify one source-level arity.
The native API is a `void __cdecl` no-op implemented as a naked return
adapter. Its machine code preserves every register and EFLAGS and leaves
caller-owned arguments in place, matching the bounded behavior visible here.
No role is assigned to the 57 data references without their consumers.

The differential probe calls the original function with zero, one, two, and
four caller-clean arguments. It compares EAX, EBX, ECX, EDX, ESI, EDI, EBP,
EFLAGS, caller stack delta, and argument bytes after return. This proves the
leaf semantics at `00516950`; it does not claim semantics for the many callers
or pointer-bearing data references. MSVC Release encodes the naked cdecl void
adapter as `C2 00 00` (`RET 0`), which has the same stack/register/flags effect
as the original `C3 RET` but is not a byte match. The report records the object
symbol, section bytes, and object hash; it makes no exact-byte claim.

```powershell
& 'local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' -S `
  iterations/v2/001-original-recovery/runs/100-startup-service `
  -B local/builds/v2/startup-service-100 -A Win32
& 'local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' --build `
  local/builds/v2/startup-service-100 --config Release
py -3 scripts/research/verify-v2-startup-service-516950.py `
  --probe local/builds/v2/startup-service-100/bin/Release/startup_service_516950_probe.exe `
  --object local/builds/v2/startup-service-100/startup_service_516950_probe.dir/Release/startup_service_516950.obj `
  --report-dir iterations/v2/001-original-recovery/runs/100-startup-service
```
