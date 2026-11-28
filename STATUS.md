# Recovery status

Updated 2026-11-28. The latest audited build is [Run894](iterations/v2/001-original-recovery/runs/894-session-extension-service-integration/README.md).

## Original binary analysis

- **Corpus, 25 modules.** The automatic export produced pseudo-C for 36,583 of 36,587 indexed functions. Four exports failed. The listing leaves 3,199,385 executable-section bytes unclassified; those ranges can contain code, data or padding. [Corpus](research/v2/README.md)
- **Porsche.exe.** All 5,772 indexed functions have a pseudo-C export. There are 139,408 unclassified executable-section bytes. At 1,445 indexed entry addresses the registry records source recovery, including 266 with only partial status. **4,327 indexed addresses have no registry entry.** Another 169 registered addresses fall outside the automatic entry list. The registry contains 1,615 rows in total, including two records for one address. [Registry](iterations/v2/001-original-recovery/source/recovered/functions.json)

## Recovered game

Run894 compiled 519 translation units across eight projects, folding [Run889](iterations/v2/001-original-recovery/runs/889-session-extension-service/README.md) (`00406520` + 15 ctors/dtors/slot2, `8B` `.bss` + mode/vtable `.rdata`; retains 5 tick/reset boundaries + `00514990`). The Win32 link has **40 unresolved names / 42 references**. The audit passed 248 native comparisons, 8 mutation controls, and 1,286 source pins. Startup and gameplay await a linked executable. [Shared audit](iterations/v2/001-original-recovery/runs/894-session-extension-service-integration/validation.json)

The [active plan](iterations/v2/001-original-recovery/PLAN.md) records the network and camera-transform blockers. The [validation backlog](docs/recovery-validation-backlog.md) covers cross-subsystem and gameplay checks. The [previous status log](https://github.com/xfynx/prsche-disasm/blob/9bc538dcdaaa3915ac5d1e7e77dfd071d2056465/STATUS.md) preserves subsystem caveats, standalone proofs, external-port smoke results and earlier checkpoints.
