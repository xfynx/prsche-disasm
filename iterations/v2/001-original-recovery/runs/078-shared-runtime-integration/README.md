# Run078 — shared runtime and original window startup integration

2026-10-10. Original `Porsche.exe` SHA-256:
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.

Accepted: **200 full C++ functions + 4 partial consumers**. The common MSVC
Win32 build now contains 63 comparison/alias probes, 3 native OS fixtures and
3 non-GUI link fixtures. All 54 fresh comparison/alias reports passed;
10,175 bounded original-x86 comparisons include the separate arena proofs.
These are regression and scoped equivalence evidence, not whole-game parity.

Seven new full consumers: renderer settings `0044e890`, alternate state init
`0044f020`, event queue `0053a9e0/0053aa60`, keyboard toggles `005739b0`, and
scheduler registration/removal `005365e0/005366a0`. Index queries were these
addresses, their callers/callees, and referenced globals; original ASM,
ABI and boundary arithmetic are documented in Runs066/069/071/079/082.
Run073 jointly executes the actual renderer mode/settings/state consumers.

The application BSS span `006573e8..0065b20b` now has one 3,977-DWORD backing.
55 existing aliases share storage; five further typed observations remain
unaliased, and gaps/unknown string extent remain explicit. FE table targets
bind at static initialization to the real arena. Main's clear executes the
restored bounded fill adapter, with original x86 fill executed in its oracle.
Full DWORD-pattern fill, tails and adjacent argv canaries are checked in068/074.

Canonical runtime DWORDs `005deb1c/005deb74/005deb78` replace duplicate owners.
Pointer diagnostic access uses bit-preserving getter/setter helpers. The
zero-fill string object `005e8e50` still has unresolved extent/escape questions;
Run081 records evidence and does not pretend it is fixed.

The original thread callback is zero-argument cdecl. A typed void thunk
connects it to the thread bootstrap; paint-lock names share the actual thread
lock cell. Win32 window bindings and ABI-checked recovered callee adapters
are built with the production source. `native_window_chain.exe` resolves
16 unique callbacks used by 27 registrations; it does not start a GUI.
The initial wrong count assertion and its corrected successful check are
both retained in `window-link-checks*.json`.

Actual native observations on2026-10-10: core event/page/lock checks passed;
original thread init/start/trampoline/unregister/shutdown passed; the narrow
Run036 window fixture created and destroyed a visible640x480 window with
39 default messages. JSON records preserve executable and dependency hashes.
This window fixture is separate from the full Run077 startup chain.

Validation:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File scripts/build-v2.ps1
py -3 scripts/research/refresh-v2-proofs.py --report-root <fresh-run> --jobs 4 --update-registry
. ./scripts/tool-env.ps1
py -3 scripts/research/audit-v2-link-frontier.py --report <fresh-run>/link-frontier.json
py -3 scripts/research/inventory-v2.py --require-listing --require-decompile-attempts
py -3 scripts/research/structure-v2.py
py -3 scripts/research/inventory-v2.py --require-listing --require-decompile-attempts --write-verification
```

MSBuild project fanout failed silently inside the sandbox; the approved native
build passed. ALL_BUILD now builds the graph in one invocation with four jobs.
Fresh verifier CLI and transitive-include hashes preserve historical reports.
`acceptance.json`, `refresh-result.json` and per-report source/probe hashes
record exact scoped checks. Link audit:964 defined,291 unresolved names and
no duplicate project definitions; categories are not missing-algorithm counts.

Next: connect082 scheduler to077 and recover original shutdown callback
`0053bae0`, including its `00534550` and process-exit consumers. Then run the
full original window startup/message/close chain. Fullscreen helpers
`00565560/00573980`, position removal `0053a8e0`, exit cleanup `00558350`, input
translation/game routes and many main/renderer callees remain explicit.
There is no launched v2 game or accepted original visual/gameplay result.
