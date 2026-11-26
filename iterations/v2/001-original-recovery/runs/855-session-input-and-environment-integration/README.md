# Session input reset and CRT environment integration

[Build 001](build-001.json) compiles 494 Win32 translation units in eight projects.
The [shared audit](validation.json) passed 776 original comparisons and eight
mutations with 1,226 source pins. The Win32 link has **38 unresolved names /
40 references**. No game executable was produced.

[Run853](../853-session-input-reset/README.md) closes two session-reset
callees using the existing FF state, player table and input ABI. The fixture
covers live count changes during virtual release within the nine-slot table.
[Run854](../854-crt-putenv/README.md) closes the narrow environment setter
and its inner routine. It exposes one new link dependency, the wide setter
at `005aa039`. Its live OS behavior remains open. Four indexed addresses
entered the registry. See [acceptance inputs](acceptance.json).
