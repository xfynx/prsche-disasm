# Original C/C++ recovery handoff

[Run868](runs/868-player-history-integration/README.md) is the accepted shared build. See [current status](../../../STATUS.md) for the measured corpus, registry and linker frontier. The coordinator owns registry updates, shared builds and publication.

## Next dependencies

- [Session reset](runs/851-session-reset/README.md) now binds nine of ten callees. [Run859](runs/859-session-records/README.md) closes the record parser and comparator. [Run861](runs/861-frame-reset-service/README.md) and [Run864](runs/864-session-extension-pool/README.md) expose per-player initialization at `00410730` and extension creation at `00406520`. [Run867](runs/867-player-history-reset/README.md) closes player history initialization. The last direct callee, `004690a0`, invokes world and scene services before configuring the selected player. [World cleanup](runs/858-world-cleanup/README.md) reaches destructor `00487590`. Recover its child calls and fields.
- [Run848, camera transform](runs/848-camera-transform/README.md). The wrapper and both setters now compile. The remaining dispatch at `0055a930` selects CPU-specific kernels. Trace cache and scratch writers and compare each reachable path using [Run845](runs/845-transform-vectors-trace/README.md).
- [Run847, network callback](runs/847-network-context/README.md) has standalone proof. Establish the service and receive callbacks, shared registry extents and descriptor ownership before admitting the [transport initializers](runs/844-network-option-queries/README.md).
- [Run857](runs/857-wide-environment-setter/README.md) recovered the wide setter and seven helpers. [Run862](runs/862-wide-locale-compare/README.md) recovers locale selection and locking. Bind the default engine at `005ae901` and localized engine at `005ae6b6`.

Run772 is archived locally in `local/experiments/v2-run772-exploration/` (two extraction scripts and two dumps). The IAT script reuses the first slot address for each DLL, so the dump cannot establish slot ownership. [Run806](runs/806-input-caps-query/README.md) recovered the input-capability continuation and [Run809](runs/809-scene-reset-and-input-caps-integration/README.md) integrated it. For later CRT shutdown work see [Run838](runs/838-crt-shutdown-and-env-closers/README.md) and [Run841](runs/841-entry-fe-service-and-crt-shutdown-integration/README.md). Run840 was named in earlier plans but its scope and artifacts could not be located.

## Acceptance and commands

Keep a SHA-addressed listing and decompilation outcome for each original function and account for unclassified bytes and unresolved edges. Prove new C/C++ behavior against original x86, check ABI and state ownership including overlapping ranges, then build and audit one frozen batch. Keep narrower domains partial. Use the [recovery procedure](../../../.agents/skills/porsche-recovery/SKILL.md) for a new packet and fresh attempt IDs.

From the repository root, these read or audit existing results. The shared audit needs the matching local build and native receipts.

```powershell
py -3 scripts/research/recovery-progress.py
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/868-player-history-integration/acceptance.json
```

[Run history](runs/) contains per-batch proofs, commands and known limits. The [full handoff through Run846](https://github.com/xfynx/prsche-disasm/blob/9bc538dcdaaa3915ac5d1e7e77dfd071d2056465/iterations/v2/001-original-recovery/PLAN.md) preserves prior assignments, hypotheses, exact verification commands and the compiler/ABI research trail.
