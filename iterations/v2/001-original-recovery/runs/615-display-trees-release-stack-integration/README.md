# Run615 render display member trees and splash release stack integration

Shared acceptance passes for frozen613002 (`613001` preserved) and614001 on612.
Three PARTIAL originals (`0044b1d0` 119B, `00466380` 372B and `0048d550` 322B,
813 code bytes total) integrate with zero new writable `.data` or `.rdata`.
Build001 compiles347 TUs across8 projects with unchanged inputs, zero compiler
or other linker errors and104 unresolved names/109 references. Two real
dependencies (`render_display_member_00466380` and
`splash_progress_release_stack_0048d550`) close; no new unresolved name enters.
There is no recovered game EXE. Registry945 preserves partial parent domains.

Native comparisons pass1340 measured cases (1140 in613002 + 200 in614001) and8
material controls (4 in613 + 4 in614) atOd/O2. Canonical render allocation
(`289`), context identity/heap state (`330`/`331`/`512`), heap lock/copy
(`289`), FE record word count (`336`) and startup network (`311`) owners are
reused without duplication. Shared audit verifies858 source pins and947
canonical providers.

Broader aliases/faults/lifetimes, SEH unwind paths, oversized packets, startup
and gameplay remain open. Next independent packets are616 (`00568f30`) and617
(`00568900`).

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/613-render-display-member-trees/native-config.json --attempt 002
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/614-splash-release-stack/native-config.json --attempt 001
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/615-display-trees-release-stack-integration/build-config.json --phase configure --attempt 001
$env:MSBUILDDISABLENODEREUSE='1'
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/615-display-trees-release-stack-integration/build-config.json --phase build --attempt 001
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/615-display-trees-release-stack-integration/acceptance.json
```

Commands identify preserved attempts; passed source/config/fixture inputs are frozen.
