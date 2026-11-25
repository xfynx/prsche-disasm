# Project roadmap

Recover the original Windows x86 game in C/C++, compile it and verify the original behavior through both careers. The [active iteration plan](iterations/v2/001-original-recovery/PLAN.md) owns the next tasks and commands. [STATUS.md](STATUS.md) owns the measured baseline.

## Milestones

1. Account for each original module by SHA, its functions, executable bytes, decompilation failures and unresolved edges. Recover original algorithms, layouts, compiler/CRT conventions and ABI from evidence. Prioritize reachable startup and linker dependencies.
2. Link the recovered Win32 game. Exercise startup, resource loading, display and shutdown. Compare menus, driving, AI, damage, audio, Quick Race, Evolution, Factory Driver, used-car purchases, progression and saves against the original. Track outstanding checks in the [validation backlog](docs/recovery-validation-backlog.md).
3. After full source recovery, consolidate accepted C/C++ by subsystem under one source tree. Migrate build paths through a manifest preserving SHA, addresses, proof hashes and immutable run history.
4. Map startup through menus, racing, results, saves and shutdown to source owners, resource consumers, threads and callbacks. Use the verified C/C++ baseline and architecture map for the Rust native/web port. The [012 prototype](iterations/012-campaign-fidelity/README.md) is paused.

## Report after every commit

Report the short commit ID, its measured change and the remaining work, including documentation-only commits. Use `py -3 scripts/research/recovery-progress.py` for corpus pseudo-C coverage, unclassified executable bytes and Porsche.exe indexed addresses registered, partial-only and still unregistered. Report extra registered addresses outside the index separately. Count unique addresses for the same module SHA.

Give the latest audited linker names/references, executable and gameplay status, and the next concrete blocker. Reuse existing receipts when inputs are unchanged. After a push, include branch/upstream alignment and any remaining local changes.

## Coordination

- **Codex / ChatGPT** uses Astra for orchestration and final acceptance, and Sol or lighter workers for bounded tasks.
- **Other providers** use a strong coordinator and the simplest adequate available workers. On opencode-go, prefer glm-5.3 and glm-5.3-flash respectively when available.

Resume uncommitted packets and parallelize independent work under the [recovery rules](AGENTS.md). Publish accepted batches and continue unless the user pauses recovery.
