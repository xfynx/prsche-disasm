# Run 129 — app_main setup context

This packet fixes the caller/storage/ABI defect in `app_main_004b6a50` and
recovers the bounded context constructor `004d1a90` and destructor `004d1ba0`.
The original is `Porsche.exe`, SHA-256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.

At `004b6a50`, the caller reserves `0x188` stack bytes. The constructor call
uses `LEA ECX,[ESP+0x18]`; from the entry-frame base this places the object at
`entry ESP-0x180`, within the reserved bytes and leaving exactly `0x180` bytes
to the top of the frame. After three pushes, the caller uses `[ESP+0x24]` to
pass the same address to `004d3420`. It then calls `004d1ba0` with that same
ECX. The restored storage is a `0x180` byte backing object; it is deliberately
not zero-filled.

`004d1a90` calls base constructor `00525e20`, writes the original sparse field
set, stores vtable `0x005b683c`, allocates `0x2c` through existing
`0059ef90`, conditionally calls member constructor `005294c0`, stores the
member pointer at `+0xd4`, and copies the NUL-terminated string at `005e8e50`
to `+0x10c`. The copy is unbounded in the original. `004d1ba0` writes the
vtable, conditionally calls `005295b0` and existing `0059f050` for the member,
then calls base destructor `00525ec0`. Constructor EAX is the context pointer;
the caller ignores it. Destructor leaves the base-destructor EAX unchanged;
the caller ignores that too.

The main caller proof now executes the original constructor/destructor bytes
in its x86 oracle and checks the setup call's ECX context, exact
`gamesetup`/stream/zero stack arguments, vtable, initialized byte, order, and
all prior 15 main cases. The setup parser/consumer `004d3420` remains an
explicit typed boundary (8,589 bytes); its behavior is not claimed. The adapter
uses `__fastcall` with a reserved unused EDX parameter so native MSVC puts the
context in ECX and the three proven arguments on the stack. The original body
does not consume incoming EDX before its first explicit EDX use at `004d35b9`.

The standalone context oracle compares the complete `0x180` bytes after
constructor and destructor against original x86 for four canary-seeded cases:
null and non-null member allocation, empty and non-empty source text, and
preservation of every untouched byte including `+0x17d..+0x17f`. The `+0xd4`
pointer is checked as relocated null/non-null identity. Calls to
`00525e20`, `005294c0`, `005295b0`, and `00525ec0` are controlled typed
boundaries; the proof does not claim their internals. The dtor proof verifies
that its EAX forwards the controlled base-dtor EAX.

The source string owner at `005e8e50` remains unresolved: Run 081 documented
overlapping `application_object_heap_name_005e8e50[32]` and
`file_null_name_005e8e50[1]` source declarations over the same original BSS
address, with no proven extent. This packet reuses the existing application
heap symbol and does not claim or create a 32-byte original bound. That alias
and extent debt, as well as the full `004d3420` setup parser, must remain open
in the validation backlog.

Commands used:

```powershell
& './local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' -S iterations/v2/001-original-recovery/runs/129-application-context -B local/builds/v2/application-context-129 -A Win32
& './local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' --build local/builds/v2/application-context-129 --config Release
py -3 scripts/research/verify-v2-application-context.py --probe local/builds/v2/application-context-129/bin/Release/application_context_probe.exe --report-dir iterations/v2/001-original-recovery/runs/129-application-context

& './local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' -S iterations/v2/001-original-recovery/runs/058-application-main -B local/builds/v2/application-main-129 -A Win32
& './local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' --build local/builds/v2/application-main-129 --config Release
py -3 scripts/research/verify-v2-application-main.py --probe local/builds/v2/application-main-129/bin/Release/application_main_probe.exe --report-dir iterations/v2/001-original-recovery/runs/129-application-context/application-main-refresh
```

Results: both native MSVC Win32 probes built. The context proof passed 4/4
full-span comparisons; the refreshed main proof passed 15/15 cases. These are
original-x86 differential checks, not a game-launch proof.
