# Run 074: unified application state arena

Run068 proves the original clear call at `004b6ab3..004b6abe`: it passes VA
`006573e8`, zero, and `0x3e24` bytes to `0053c290`. The span is exactly
`006573e8..0065b20b`; the exclusive end `0065b20c` is the separate
`argv_0065b20c[32]` object. `verify-v2-application-arena.py` executes the
original x86 fill and compares every native arena byte while checking original
prefix, adjacent argv, and suffix canaries.

`application_state.cpp` owns one `ApplicationStateArena` containing 3,977
`uint32_t` words. `application_globals.cpp` is the only owner of the recovered
field-reference symbols. FE data targets are references to actual arena words;
the generated FE include now declares those references instead of creating
second storage. FE table entries `RACE_TYPE` and `FEGAME_TYPE` are checked for
the expected arena addresses and their writes are observed through the arena.

The canonical FE aliases are the 34 aligned words at
`006573e8, 006573ec, 006573f0, 006573f4, 006573f8, 006573fc, 00657400,
00657404, 00657408, 0065740c, 00657414, 00657418, 00657420, 0065742c,
00657430, 00657434, 00657438, 0065743c, 00657440, 00657494, 00657840,
00657a24, 00657a28, 00657a2c, 00657a30, 00657a34, 00657c74, 00657c78,
00657c7c, 00657c80, 0065807c, 00658080, 00658084, 00658088`. Application
main also uses words `00657424`, `00657428`, `006577d8`, `006577dc`, and
`00657a60`, bytes `00657a64` and `00657e34`, plus a NUL-terminated string view
starting at `00657a84` whose capacity remains unknown.

Renderer aliases use the same arena storage: selector bytes at `00657a38`,
requested width/height at `00657a48/00657a4c`, selected display at
`00657a58`, requested mode at `00657a50`, signed settings at
`00657d5c/00657d60/00657d68/00657d6c/00657d70/00657d78/00657d80`, and the
settings word at `00657da4`. `render_display_requested_width/height` and
`render_width/height` have equal addresses. The signed settings use the
corresponding signed/unsigned integer alias rule, guarded by a compile-time
type check; byte and character access uses the word array's object
representation. No reference is created for opaque direct-address fields or
unmapped gaps.

The integrated arena currently has 55 mapped existing field owners/views. Five
additional typed observations remain observations only, with no C++ aliases:
`00657410` (float32) and `0065741c`, `00657498`, `006574b8`, `00657aa4`
(DWORD). They are not included in the 55 mapped owners and are not claimed as
aliased storage.

The production `application_main_fill_fe_arena_0053c290` adapter delegates to
the Run068 verified DWORD-pattern loop over the shared arena. It accepts only
the proven base and exact `0x3e24` span; other spans throw as unsupported.
The string views expose pointers into the arena and do not claim an extent for
`00657a84`. The x86 comparison proves the clear result and guard boundaries;
the native probe proves FE-table binding, cross-owner renderer/main writes,
byte/signed views, full-span clearing, and rejection of unsupported spans.

Run074 builds independently so shared application CMake wiring can be updated
after review:

```powershell
& 'local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' -S `
  iterations/v2/001-original-recovery/runs/074-application-arena `
  -B local/builds/v2/001-original-recovery/application-arena-074 -A Win32
& 'local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' --build `
  local/builds/v2/001-original-recovery/application-arena-074 --config Release
py -3 scripts/research/verify-v2-application-arena.py `
  --probe local/builds/v2/001-original-recovery/application-arena-074/bin/Release/application_arena_probe.exe `
  --report-dir local/builds/v2/run074-application-arena-check
```

The verifier reuses the immutable Run068 original-x86 oracle and writes
`verification.json` under the supplied report directory; the command above
keeps historic run artifacts unchanged. Shared CMake targets that compile any of
`fe_stream.cpp`, `application_main.cpp`, `render_startup.cpp`,
`render_display.cpp`, `render_mode.cpp`, or `render_settings.cpp` must also
compile `application_state.cpp` and `application_globals.cpp`; probe-only
fixtures must not reintroduce definitions for the in-arena references.
