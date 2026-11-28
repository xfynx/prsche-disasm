# Recovery status

Updated 2026-11-28. The latest audited build is [Run891](iterations/v2/001-original-recovery/runs/891-scene-flare-and-driver-draw-integration/README.md).

## Original binary analysis

- **Corpus, 25 modules.** The automatic export produced pseudo-C for 36,583 of 36,587 indexed functions. Four exports failed. The listing leaves 3,199,385 executable-section bytes unclassified; those ranges can contain code, data or padding. [Corpus](research/v2/README.md)
- **Porsche.exe.** All 5,772 indexed functions have a pseudo-C export. There are 139,408 unclassified executable-section bytes. At 1,431 indexed entry addresses the registry records source recovery, including 266 with only partial status. **4,341 indexed addresses have no registry entry.** Another 167 registered addresses fall outside the automatic entry list. The registry contains 1,599 rows in total, including two records for one address. [Registry](iterations/v2/001-original-recovery/source/recovered/functions.json)

## Recovered game

Run891 compiled 518 translation units across eight projects, folding [Run885](iterations/v2/001-original-recovery/runs/885-scene-flare-ctor/README.md) (`0045d800` + 19 helpers; opens 4 flare effect boundaries `00459b50`/`0045adf0`/`0045b5a0`/`0045bf80`) and [Run890](iterations/v2/001-original-recovery/runs/890-splash-progress-driver-draw/README.md) (`0053d570` + 19 callees, `8B` writable + `180B` `.rdata`). The Win32 link has **35 unresolved names / 37 references**. The audit passed 340 native comparisons, 24 mutation controls, and 1,283 source pins. Startup and gameplay await a linked executable. [Shared audit](iterations/v2/001-original-recovery/runs/891-scene-flare-and-driver-draw-integration/validation.json)

The [active plan](iterations/v2/001-original-recovery/PLAN.md) records the network and camera-transform blockers. The [validation backlog](docs/recovery-validation-backlog.md) covers cross-subsystem and gameplay checks. The [previous status log](https://github.com/xfynx/prsche-disasm/blob/9bc538dcdaaa3915ac5d1e7e77dfd071d2056465/STATUS.md) preserves subsystem caveats, standalone proofs, external-port smoke results and earlier checkpoints.
