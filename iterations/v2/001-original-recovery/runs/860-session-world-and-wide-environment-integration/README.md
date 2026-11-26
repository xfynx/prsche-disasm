# Session reset, world cleanup and wide environment

[Build 002](build-002.json) compiled 497 Win32 translation units across eight projects. The [audit](validation.json) passed 162 native comparisons and ten mutation controls with 1,233 source pins. The link still has **38 unresolved names / 40 references**. Startup and gameplay await a linked executable.

- [Run856](../856-session-reset-gate/README.md) binds the reset gate to the original ECX receiver and callee-popped payload. The records routine at `0040e3b0` is now reachable.
- [Run857](../857-wide-environment-setter/README.md) recovers the wide environment setter and seven table, conversion and string helpers. The locale-sensitive comparison at `005ad68c` remains open.
- [Run858](../858-world-cleanup/README.md) recovers world cleanup using the existing world pointer, logger and allocator. Its destructor at `00487590` is unresolved.

Build 001 exposed a report error. For the C-linkage fastcall destructor, the linker prints its decorated name directly before the quoted C++ caller. The original parser counted the caller as unresolved. The corrected parser and [acceptance inputs](acceptance.json) cross-check the three new names with compiled objects.
