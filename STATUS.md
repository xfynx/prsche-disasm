# Recovery status

Updated 2026-11-28. The latest audited build is [Run888](iterations/v2/001-original-recovery/runs/888-wide-locale-and-row-converter-integration/README.md).

## Original binary analysis

- **Corpus, 25 modules.** The automatic export produced pseudo-C for 36,583 of 36,587 indexed functions. Four exports failed. The listing leaves 3,199,385 executable-section bytes unclassified; those ranges can contain code, data or padding. [Corpus](research/v2/README.md)
- **Porsche.exe.** All 5,772 indexed functions have a pseudo-C export. There are 139,408 unclassified executable-section bytes. At 1,406 indexed entry addresses the registry records source recovery, including 266 with only partial status. **4,366 indexed addresses have no registry entry.** Another 152 registered addresses fall outside the automatic entry list. The registry contains 1,559 rows in total, including two records for one address. [Registry](iterations/v2/001-original-recovery/source/recovered/functions.json)

## Recovered game

Run888 compiled 516 translation units across eight projects, folding [Run886](iterations/v2/001-original-recovery/runs/886-wide-locale-compare-engines/README.md) (`005ae901`, `005ae6b6`) and [Run887](iterations/v2/001-original-recovery/runs/887-render-row-converter-and-leaves/README.md) (`00534b90` + 18 leaves) with `0` new unresolved symbols. The Win32 link has **33 unresolved names / 35 references**. The audit passed 1,828 native comparisons, 20 mutation controls, and 1,278 source pins (`518B` `.rdata`, `1,040B` writable `.data`/`.bss`). Startup and gameplay await a linked executable. [Shared audit](iterations/v2/001-original-recovery/runs/888-wide-locale-and-row-converter-integration/validation.json)

The [active plan](iterations/v2/001-original-recovery/PLAN.md) records the network and camera-transform blockers. The [validation backlog](docs/recovery-validation-backlog.md) covers cross-subsystem and gameplay checks. The [previous status log](https://github.com/xfynx/prsche-disasm/blob/9bc538dcdaaa3915ac5d1e7e77dfd071d2056465/STATUS.md) preserves subsystem caveats, standalone proofs, external-port smoke results and earlier checkpoints.
