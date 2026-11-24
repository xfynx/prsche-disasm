# Run836 — RTTI Cast & Network RTTI Integration

PASS (`build-001`, 2026-11-25): folds `825/010` (`456B`, 5 RTTI/cast functions + `bindings.cmake` attaching `rtti.cpp`) and `830/001` (`bindings.cmake` aliasing `network_rtti_005c5190`/`d8`/`28` -> `rtti.cpp`, `60B` `.rdata`): **484 TUs / 8 projects**, **47 unresolved / 53 refs**, `1,200` pins, `84` comparisons, `16` mutations, `2` REA sessions, no EXE. Closes `5`, `0` new.
Artifacts: [build-config.json](build-config.json), [acceptance.json](acceptance.json), [validation.json](validation.json).
