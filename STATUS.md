# Recovery status

Updated 2026-11-25. Recovery is paused at [Run846](iterations/v2/001-original-recovery/runs/846-audio-period-device-state/README.md).

## Original binary analysis

- **Corpus, 25 modules.** The automatic export produced pseudo-C for 36,583 of 36,587 indexed functions. Four exports failed. The listing leaves 3,199,385 executable-section bytes unclassified; those ranges can contain code, data or padding. [Corpus](research/v2/README.md)
- **Porsche.exe.** All 5,772 indexed functions have a pseudo-C export. There are 139,408 unclassified executable-section bytes. At 1,328 indexed entry addresses the registry records source recovery, including 266 with only partial status. **4,444 indexed addresses have no registry entry.** Another 144 registered addresses fall outside the automatic entry list. The registry contains 1,473 rows in total, including two records for one address. [Registry](iterations/v2/001-original-recovery/source/recovered/functions.json)

## Recovered game

Run846 compiled 489 translation units across eight projects. The Win32 link still has **36 unresolved names / 39 references**. There is no game executable for startup, visual or gameplay acceptance. The audio period setter closed one linker name, passed 2,560 original-x86 comparisons and detected both mutations. [Shared audit](iterations/v2/001-original-recovery/runs/846-audio-period-device-state/validation.json)

The [active plan](iterations/v2/001-original-recovery/PLAN.md) records the network and camera-transform blockers. The [validation backlog](docs/recovery-validation-backlog.md) covers cross-subsystem and gameplay checks. The [previous status log](https://github.com/xfynx/prsche-disasm/blob/9bc538dcdaaa3915ac5d1e7e77dfd071d2056465/STATUS.md) preserves subsystem caveats, standalone proofs, external-port smoke results and earlier checkpoints.
