# Run 026 — render object constructors

Source: `Porsche.exe` SHA256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
Index query: `00467470` caller → `00467700`/`004677e0` in
`research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/functions.jsonl`,
`calls.jsonl`, `references.jsonl`, then full VA ranges in
`research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm`.

## Confirmed and implemented

`0x467700..0x46771f` (32 bytes) is the complete core constructor. It writes
publisher pointer at +4, title pointer at +0xc, zero byte at +0x110, and
vtable pointer `0x5b3fbc` at +0, then returns `this` with `RET 8`. The PE
vtable slot zero contains `0x4b76f0` (raw words at `0x5b3fbc`). The
`render_construct_core_raw_00467700` body preserves these exact original
bytes; `render_construct_core_00467700` subsequently substitutes a native
MSVC vtable for the existing `RenderCore::first_00` call in the consumer.
That bridge forwards to an explicit, unresolved `0x4b76f0` boundary. The
original vtable pointer and native pointer are distinct by necessity.

`0x4677e0..0x467849` is the exact **prefix only** of the 1761-byte display
constructor. Its object fields are compared across all 0x80 bytes. Explicit
dependencies are two thiscall member constructors `0x466380` on +0x14 and
+0x34, and two calls of `0x555bc0`. The prefix writes +0=0,
+4=`0x3e19999a`, +8=`0x442f0000`, +0x10=0, +0x54=`this+0x14`,
+0x58=first `0x555bc0` return, +0x5c=0, +0x60=low byte of third
constructor argument, +0x64=0, +0x68=1, +0x6c/+0x70/+0x74=0;
it stores `this` at global `0x628130`, calls `0x555bc0` again and clears
global `0x5deb1c`. The next original instruction calls `GetDesktopWindow`.

## Display dependencies and next trace

`0x46784f..0x46786d` uses USER32 `GetDesktopWindow`, `GetWindowDC`,
`ReleaseDC` and GDI32 `GetDeviceCaps(hdc,12)`. Values below 8 format the
256-colour error string at `0x5cf8bc`, call USER32 `MessageBoxA` with title
`0x5cf8a4`, then call `0x557370`; this failure path is not yet ported.
The success path creates a driver at +0x70 via `0x557100` or `0x556a90`
after allocation; its virtual slot +4 at `0x46793c` gates startup. Later
the constructor allocates a +0x7c object and uses many THRASH calls.

The indirect table is traced to `0x574fa0`: it calls `LoadLibraryA` with
the caller's driver name (and a fallback name), then `GetProcAddress` for
`_THRASH_*@N` exports. In particular `0x6bd984` is `_THRASH_getstate@4`,
`0x6bd97c` is `_THRASH_setstate@8`, `0x6bd9a8` is
`_THRASH_drawquad@16`, and `0x6bd9b0` is `_THRASH_window@4`.
Evidence: loader instructions `0x575000/0x57503f/0x5750d7/0x57520d/
0x575220`, strings at `0x5c0b08..0x5c0dbc`, and constructor calls
`0x467c1d..0x467ea0`. The `0x594dxx` table-copy path and the actual
driver library selection remain to be traced; the table names alone do not
prove which driver is loaded. Next trace is `0x557100`/`0x556a90` and their
virtual startup slot, then the selected THRASH DLL's `_THRASH_window@4`.

Verification commands (MSVC 19.44, Win32 Release):

    . ./scripts/tool-env.ps1
    cmake -S iterations/v2/001-original-recovery/runs/026-render-objects -B local/builds/v2/render-objects-026 -G 'Visual Studio 17 2022' -A Win32
    cmake --build local/builds/v2/render-objects-026 --config Release --target render_objects_probe
    py -3 scripts/research/verify-v2-render-objects.py --probe local/builds/v2/render-objects-026/bin/Release/render_objects_probe.exe

32/32 valid cases matched. `verification.json` pins source/probe hashes and
fixture outputs; `source-functions.jsonl` pins complete original function
body hashes. The fixture compares complete core object state, display prefix object
state, globals, returns and ordered boundary calls against Unicorn executing
the original PE. `0x466380`, `0x555bc0` and `0x4b76f0` remain recording
boundaries, so this is not a full constructor or actual window proof.
