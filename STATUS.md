# Recovery status

Updated 2026-11-27. The latest audited build is [Run865](iterations/v2/001-original-recovery/runs/865-player-dispatch-and-extension-pool-integration/README.md).

## Original binary analysis

- **Corpus, 25 modules.** The automatic export produced pseudo-C for 36,583 of 36,587 indexed functions. Four exports failed. The listing leaves 3,199,385 executable-section bytes unclassified; those ranges can contain code, data or padding. [Corpus](research/v2/README.md)
- **Porsche.exe.** All 5,772 indexed functions have a pseudo-C export. There are 139,408 unclassified executable-section bytes. At 1,357 indexed entry addresses the registry records source recovery, including 266 with only partial status. **4,415 indexed addresses have no registry entry.** Another 145 registered addresses fall outside the automatic entry list. The registry contains 1,503 rows in total, including two records for one address. [Registry](iterations/v2/001-original-recovery/source/recovered/functions.json)

## Recovered game

Run865 compiled 501 translation units across eight projects. The Win32 linker reports **38 unresolved names / 40 references**. The player dispatcher and extension-pool reset now reach their per-player and extension constructors. The audit passed 53,268 comparisons and eleven mutation controls. Startup and gameplay await a linked executable. [Shared audit](iterations/v2/001-original-recovery/runs/865-player-dispatch-and-extension-pool-integration/validation.json)

The [active plan](iterations/v2/001-original-recovery/PLAN.md) records the network and camera-transform blockers. The [validation backlog](docs/recovery-validation-backlog.md) covers cross-subsystem and gameplay checks. The [previous status log](https://github.com/xfynx/prsche-disasm/blob/9bc538dcdaaa3915ac5d1e7e77dfd071d2056465/STATUS.md) preserves subsystem caveats, standalone proofs, external-port smoke results and earlier checkpoints.
