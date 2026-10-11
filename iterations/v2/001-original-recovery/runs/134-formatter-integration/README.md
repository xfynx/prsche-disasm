# Run 134 — connected formatter integration

This isolated Win32 x86 fixture links the actual recovered native bodies from Runs 108, 119, 124, and 132: the variadic/raw entry, output/raw-argument helpers, the 1,825-byte table-driven parser, and cleanup `005a4259`. The production entry reaches the parser through the typed `formatter_parser_entry_bridge.cpp`. A separate test-only adapter seeds opaque descriptor tail bytes for deterministic full-state comparison; it is not linked into production.

The original Unicorn side executes the real `005a0fbf` entry through its original parser/helper callees for ten bounded literal, integer, width/precision, string, `%n`, and malformed-format cases; each is also run through the linked native `formatter_entry_raw_005a0fbf`, with output, return, and `%n` state compared. A direct original parser case starts with one remaining byte and format `AB`, so `005a4371 -> 005a4ab2 -> 005a4259` writes `B` through the typed backend recorder after emitting `A`; the observed external-call order is `[prepare, write]`. A separate original `005a4ab2` bridge case checks the helper's returned count pointer and cleanup state. Only file-write, auxiliary-file, and descriptor-preparation effects are hooked.

The wrapper reserves 32 bytes but writes only offsets `+0..+0xc`; cleanup loads `+0x10` before its flags checks, though values are unused on early exits. The test adapter receives a deterministic stack-tail seed so its cleanup-visible bytes are defined. The actual wrapper is also linked and run on bounded cases that do not consume its uninitialized tail; no zero initialization is inferred for the original stack bytes.

The production patch has a small but necessary compile/link closure: alias
`FormatterDescriptor005a0fbf` to `FormatterOriginalDescriptor32`, keep the
wrapper's descriptor uninitialized and assign only its four original prefix
fields, and use the cleanup header's `int32 __cdecl(uint32,
FormatterOriginalDescriptor32*)` declaration. `formatter_entry_probe.cpp` has
the only existing mock definition of the old `void` cleanup declaration; its
recorder must return an ignored `int32` and must continue inspecting only the
known prefix. The parser bridge in
`local/experiments/formatter-descriptor-132/parser-entry-bridge.patch` records
the binding from the Run108 core symbol to Run124's parser. Run134 compiles the
complete production path: `formatter_entry.cpp`,
`formatter_parser_entry_bridge.cpp`, `formatter_original.cpp`,
`formatter_parser.cpp`, and `formatter_cleanup.cpp`. The test-only adapter
remains additional evidence for explicitly seeded tail bytes.

File write `005a9e49`, auxiliary operation `005a9ab8`, descriptor
preparation/allocation `005abef1`, float/wide callbacks, and unsigned divide /
remainder remain explicit external boundaries. Their fixture recorders are
not production definitions. The cleanup stream identity cells
`005e5508`/`005e5528` are declared as descriptor pointers, but no canonical
production owners/bindings were found in the source tree; keep them unresolved
until the existing stream owners are identified. The `005abf35` handle-table
helper is not listed as executed: the exercised descriptor is non-special, so
the original short-circuit skips that call. No duplicate storage or successful
backend effects are inferred. Locale and game-launch behavior are not claimed.

```powershell
& 'local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' -S iterations/v2/001-original-recovery/runs/134-formatter-integration -B local/builds/v2/formatter-integration-134 -A Win32
& 'local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' --build local/builds/v2/formatter-integration-134 --config Release
py -3 scripts/research/verify-v2-formatter-integration.py --probe local/builds/v2/formatter-integration-134/Release/formatter_integration_probe.exe --report-dir iterations/v2/001-original-recovery/runs/134-formatter-integration
```

The updated Run108 recorder fixture was also compiled and differentially
checked after its cleanup return type changed to `int32` (7/7); its report is
kept under the local build directory, not mixed into this run:

```powershell
& 'local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' -S iterations/v2/001-original-recovery/runs/108-formatter-entry -B local/builds/v2/formatter-entry-108-closure-check -A Win32
& 'local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' --build local/builds/v2/formatter-entry-108-closure-check --config Release
py -3 scripts/research/verify-v2-formatter-entry.py --probe local/builds/v2/formatter-entry-108-closure-check/Release/formatter_entry_probe.exe --report-dir local/builds/v2/formatter-entry-108-closure-check/report
```

Root integration136 additionally compiles Run137's exact unsigned divide,
remainder and strlen bodies with platform/formatter_runtime_links.cpp. The
native direct-call seams bind to these recovered leaves; unsigned arithmetic
is no longer supplied by fixture recorders. Original005a67b0/005a6820 execute
in the same composed oracle. Float/wide and file backend effects remain open.
