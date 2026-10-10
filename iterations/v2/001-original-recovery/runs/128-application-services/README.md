# Run 128 — app_main startup service closure

This packet closes the direct `app_main_004b6a50` boundaries for its early
failure dialog, install-root directory creation, and the audio initialization
call made through `application_main_setup_heaps`. It restores original
`004a6840..004a6956` (279 bytes) in C++, retaining unrecovered audio effects as
typed boundaries.

Evidence uses `Porsche.exe`, SHA-256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`:

* `research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm`, function
  `004a6840`: stores/branches at `00657c94/98/9c`, exact writes to
  `00655d34/38/3c/44`, eight 16-byte records at `006564a0..0065651f`, and
  state word `005d1734`; direct callees and stack argument order are preserved.
* The address catalog marks `004a6840` as 279 bytes and `004a66b0` as 398
  bytes. The latter and `004ae100`, `004a8b80`, `004ae2b0`, `004ab4b0`, and
  `00565890` remain explicit audio effect boundaries. The recovered canonical
  `allocate_00531ca0` and `free_00531f90` are called directly.
* The `004b6a50` original pseudocode has direct `MessageBoxA(NULL,text,title,0)`
  on swap allocation failure and `CreateDirectoryA([0065b360],NULL)` during
  startup. `0065b360` is the canonical slot 48 alias of the shared 60-pointer
  install-path table established by Run 116/117. Production platform adapters
  call those exact Win32 APIs. The probe substitutes API facades and creates
  no directory or dialog.

The x86 oracle executes the original `004a6840` bytes with controlled returns
from only the unrecovered audio boundaries, then compares ordered calls,
arguments, touched arena words, exact external globals, all eight record
strides, and preserved record words against native C++. Cases cover mode 3,
failed/successful audio initialization, signed positive/zero/negative first
arguments, zero/nonzero gate, and allocation failure. It also checks that the
two app_main API adapters pass their source-proven text, title, path slot, and
null/default arguments through unchanged.

The context path remains open. The original caller uses ECX for the shared
context at `004d1a90` (`__fastcall`, 172 bytes), then calls `004d3420` with that
context in ECX and `gamesetup`, stream, and zero on the stack (8,589 bytes),
then invokes `004d1ba0` with the same ECX context (46 bytes). The constructor
writes through offset `0x17c`, while the current recovered app_main fixture
models only two DWORDs and its service declarations place context on the stack.
That mismatch must be fixed at the caller/context-object boundary before a
production adapter can be wired safely. In particular, this packet does not
adapt these names to the unrelated Run 093 movie function `004dd600`.
Rendering, network services, and optional intro/movie/resource paths also
remain outside this packet.

Standalone verification:

```powershell
cmake -S iterations/v2/001-original-recovery/runs/128-application-services `
  -B local/builds/v2/application-services-128 -A Win32
cmake --build local/builds/v2/application-services-128 --config Release
py -3 scripts/research/verify-v2-application-services.py `
  --probe local/builds/v2/application-services-128/bin/Release/application_services_probe.exe `
  --report-dir iterations/v2/001-original-recovery/runs/128-application-services
```
