# Run 117 — install-table and terminal-exit integration

Accepted checks, 2026-10-11: common MSVC Win32 ALL_BUILD passed with 103
reachable projects and 194 compiled TUs. All seven native OS/link fixtures
passed. There are 27 fresh bounded original-x86 reports / 4864 comparisons,
plus seven composed table/alias checks. The registry contains 233 full and
six partial recoveries. Run120 verifies three BSS cells and 56 indexed
consumers; it adds no recovered-function count.

The real game-link attempt has zero compiler errors and 248 unresolved
symbols / 267 references (Run111: 250 / 271); no game EXE launches. New exit
bindings expose further genuine CRT dependencies, so symbol-count change
alone understates this packet's connected code.

The first common build exposed inconsistent `noreturn` redeclarations and a
signed-argument mismatch in the integration fixture's shutdown boundary.
These were corrected; the final build and fresh component proofs passed.
The refresh helper now locates required probe arguments from pinned probe
TUs when no default EXE is embedded in a verifier. The engine-service probe
uses the same common output directory as the other refreshable targets.

[Validation backlog](../../../../../docs/recovery-validation-backlog.md)
was reviewed. Resource startup, movie-service initialization, live timer
scheduling, WM_CLOSE, actual game launch and visual acceptance remain open.
Next intake is Run121: isolated original timer118, formatter helpers119 and
auxiliary signal122; these are not part of this common checkpoint.

Run 117 gives the install-path producer one canonical 60-pointer owner and
integrates the already recovered CRT exit path. It compares the composed
native calls and state with the original x86 routines. It does not claim that
the game launches or that resource archives, heap internals, or callback bodies
are recovered.

The original module is `Porsche.exe`, SHA-256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`. Run 116
proves `004b6ff0`, `004b7070`, and `00556640`; Run 115 proves the complete
`005a246e` to CRT shutdown path. The Run 117 verifier refreshes both component
proofs under its own report directory and composes the actual common owner and
startup/exit bridge in `install_paths_integration_probe`.

`install_paths_storage.cpp` is the sole production owner for blob cell
`0065b29c` and table cells `0065b2a0..0065b38f`. Five existing C++ references
now point to their original slots, with no independent pointer copies:

| View | Original cell | Slot | Value in original `install.txt` |
| --- | ---: | ---: | --- |
| `game_setup_earts_base_0065b32c` | `0065b32c` | 35 | `.` plus `\FeData\movies\` |
| `game_setup_load_base_0065b334` | `0065b334` | 37 | `.` plus `\FEData\art\` |
| `engine_service_root_0065b360` | `0065b360` | 48 | `.` plus `\SaveData\` |
| `splash_progress_alternate_base_0065b350` | `0065b350` | 44 | `.` plus `\FEData\trackart\` |
| `render_display_name_0065b304` | `0065b304` | 25 | `.` plus `\drivers\` |

The slots follow `(cell - 0065b2a0) / 4`. Integration tests check reference
address identity, writes through each view, all 60 resulting table cells,
selected loaded values, and cleanup's preserve-on-free behavior. The original
startup bridge `004a5410 -> 004b6ff0` invokes the producer and discards its
return. No cleanup caller is added. The three existing source-level
`005a246e` spellings call the same `process_exit_005a246e` implementation and
are checked with distinct exit codes.

The checked-in game fixture `local/game/install.txt` has 1,226 raw bytes and
SHA-256
`30e603756352a84c00d6d6b85a37e8dd19a375b544b318be88a1081a56bf1aae`.
Its text dependency hash is separately normalized from CRLF to LF by
`v2_source_dependencies.py`; Run 117 records both hashes and asserts that the
normalized source pin matches. The original parser yields 49 entries.

Resource open at `0059d8e0` and free at `00531f90` are typed recording
boundaries. The alias integration fixture records the exact `005a2490(code,0,0)`
call and raises a controlled terminal signal. Its typed boundary matches the
canonical signed second argument. The separate Run115 component proof executes
the actual shutdown/registry bodies with a controlled `ExitProcess` boundary. The size leaf reads the DWORD at `blob-12`. Malformed, unterminated,
or more-than-60-row files remain outside the claimed input domain; Run 116
documents the original parser's unbounded behavior and allocator-padding
dependent final `EAX` cases.

The affected standalone probes now use fixture-local table owners and
references at the same five slots. Production builds use the sole canonical
owner. `application_main_globals.cpp` from Run 120 is also compiled into the
common target as an independent owner of three unrelated exact BSS DWORDs; it
does not participate in the install-table alias set.

Common targets are `porsche_original`, `porsche_recovered_links`,
`process_exit_probe`, `install_paths_probe`, and
`install_paths_integration_probe`. Fresh Run 117 reports are written under
`runs/117-install-integration/`; reports from Runs 115 and 116 are unchanged.
The integration report pins the compiled translation units, quoted headers,
verifier, packet README/CMake, and original text fixture.

Reproduce the isolated target and integrated checks from the repository root:

```powershell
& 'local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' -S `
  iterations/v2/001-original-recovery/runs/117-install-integration `
  -B local/builds/v2/001-original-recovery/install-integration-117 -A Win32
& 'local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' --build `
  local/builds/v2/001-original-recovery/install-integration-117 --config Release
py -3 scripts/research/verify-v2-install-integration.py `
  --probe local/builds/v2/001-original-recovery/install-integration-117/bin/Release/install_paths_integration_probe.exe `
  --install-probe local/builds/v2/001-original-recovery/install-integration-117/bin/Release/install_paths_probe.exe `
  --exit-probe local/builds/v2/001-original-recovery/install-integration-117/bin/Release/process_exit_probe.exe `
  --report-dir iterations/v2/001-original-recovery/runs/117-install-integration/path-table-integration
```
