# Run020 — linked thread and lock bootstrap differential

Porsche.exe SHA256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`. The source call graph and flag-write order are recorded in [Run018 evidence](../018-lock-bootstrap/evidence.json). Index queries: `0055f320`, `0055f3b0`, `005321f0`, `00532250`, `0056e5f0`; original instructions are in `research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm`.

The `bootstrap_probe.cpp` fixture links the actual recovered `file_threads.cpp`, `file_pages.cpp`, and `heap_locks.cpp` through `porsche_original`. The Python comparator executes the same five original x86 functions in Unicorn. Boundaries record typed Win32 `GetSystemInfo`, `VirtualAlloc`, critical-section initialization, thread identity and handle duplication, plus fill and exit registration. The fixture covers initial bootstrap, count 0/1/100, repeated and already initialized calls, preexisting pool/table, exit registration, and selected allocation failures.

The Win32/x86 `bootstrap_probe` and original Unicorn execution match on 27 cases and reach all five functions. [verification.json](verification.json) records 13 source/header dependency hashes and `binary_matched: false`. Run `py -3 scripts/research/verify-v2-thread-bootstrap.py` to repeat the comparison of BSS globals at each boundary, final globals, three arena snapshots, and ordered boundary calls. Real scheduler and critical-section contention remain outside this fixture.

Integration checkpoint: 103 fully verified functions, 2 partial consumers
(532e10 mode6 and 56fdb0 capabilities failure); partials excluded from full count.
Physical open1672 and input-property37 cases passed. 17 MSVC targets built.
Current input1026/FEcallbacks1320 regressions in this run preserve historical
reports and record current build hashes. Next tasks follow app startup4b6a50
through4a5c30/4a5410/59d650/467470 toward the first original window.

    py -3 scripts/research/inventory-v2.py --require-listing --require-decompile-attempts
    py -3 scripts/research/structure-v2.py
    py -3 scripts/research/trace-v2-startup.py
    py -3 scripts/research/inventory-v2.py --require-listing --require-decompile-attempts --write-verification
