# Original C/C++ recovery handoff

[Run894](runs/894-session-extension-service-integration/README.md) (`519` TUs, **40 unresolved / 42 refs**, registry `1,615`) is the accepted shared build (`Run891` + `Run889`). See [current status](../../../STATUS.md) for the measured corpus, registry and linker frontier. The coordinator owns registry updates, shared builds and publication.

## Next dependencies

- [Session reset](runs/851-session-reset/README.md) binds all ten direct callees. [Run873](runs/873-session-scene-and-world-reset-integration/README.md) recovered world-row and scene-record reset. [Run877](runs/877-route-keyframes-and-emitter-integration/README.md) closes both route getters and the emitter reset. [Run884](runs/884-scene-route-binding-and-sky-integration/README.md) binds both scene-route callers, sky and texture reload, and flare teardown. [Run885](runs/885-scene-flare-ctor/README.md) (integrated in [Run891](runs/891-scene-flare-and-driver-draw-integration/README.md)) closed `0045d800` flare construction, leaving the 4 flare effect ctors (`00459b50`, `0045adf0`, `0045b5a0`, `0045bf80`) open. [Run889](runs/889-session-extension-service/README.md) (integrated in [Run894](runs/894-session-extension-service-integration/README.md)) closed extension creation `00406520`, retaining 5 vtable tick/reset boundaries (`00405690`, `004058a0`, `00406020`, `00403e40`, `00403990`) + `00514990`. Per-player initialization `00410730` and world destruction `00487590` remain open.
- [Run848, camera transform](runs/848-camera-transform/README.md). The wrapper and both setters now compile. The remaining dispatch at `0055a930` selects CPU-specific kernels. Trace cache and scratch writers and compare each reachable path using [Run845](runs/845-transform-vectors-trace/README.md).
- [Run847, network callback](runs/847-network-context/README.md) has standalone proof. Establish the service and receive callbacks, shared registry extents and descriptor ownership before admitting the [transport initializers](runs/844-network-option-queries/README.md).
- [Run857](runs/857-wide-environment-setter/README.md) recovered the wide setter and seven helpers. [Run862](runs/862-wide-locale-compare/README.md) recovers locale selection and locking. [Run886](runs/886-wide-locale-compare-engines/README.md) closed both `005ae901` and `005ae6b6` engines in [Run888](runs/888-wide-locale-and-row-converter-integration/README.md).

Run772 is archived locally in `local/experiments/v2-run772-exploration/` (two extraction scripts and two dumps). The IAT script reuses the first slot address for each DLL, so the dump cannot establish slot ownership. [Run806](runs/806-input-caps-query/README.md) recovered the input-capability continuation and [Run809](runs/809-scene-reset-and-input-caps-integration/README.md) integrated it. For later CRT shutdown work see [Run838](runs/838-crt-shutdown-and-env-closers/README.md) and [Run841](runs/841-entry-fe-service-and-crt-shutdown-integration/README.md). Run840 was named in earlier plans but its scope and artifacts could not be located.

## Acceptance and commands

Keep a SHA-addressed listing and decompilation outcome for each original function and account for unclassified bytes and unresolved edges. Prove new C/C++ behavior against original x86, check ABI and state ownership including overlapping ranges, then build and audit one frozen batch. Keep narrower domains partial. Use the [recovery procedure](../../../.agents/skills/porsche-recovery/SKILL.md) for a new packet and fresh attempt IDs.

From the repository root, these read or audit existing results. The shared audit needs the matching local build and native receipts.

```powershell
py -3 scripts/research/recovery-progress.py
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/884-scene-route-binding-and-sky-integration/acceptance.json
```

[Run history](runs/) contains per-batch proofs, commands and known limits. The [full handoff through Run846](https://github.com/xfynx/prsche-disasm/blob/9bc538dcdaaa3915ac5d1e7e77dfd071d2056465/iterations/v2/001-original-recovery/PLAN.md) preserves prior assignments, hypotheses, exact verification commands and the compiler/ABI research trail.
