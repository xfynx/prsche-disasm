# Run735 scene, audio service and render fill integration

The shared Win32 build on Run730 compiles **428 translation units** in eight
projects with no compiler or other linker diagnostics. It closes four reachable
names (`00567270`, `00537e00`, `0044f240`, `00562680`) and exposes four typed
children (`00567060`, `00566ea0`, `005612a0`, `00571630`). The measured frontier
remains **97 unresolved names / 104 references**. There is no game EXE.

The read-only shared audit passes for frozen Run732/003, Run733/006 and
Run734/003: **4,836 original-x86/C++ comparisons**, **44 material mutations**,
**1,060 source pins**, 428 compiler inputs, two new REA sessions, and 1,341
checked canonical COFF providers. Registry entries rise from 1,186 to 1,211:
2 Run732 bodies, 11 Run733 bodies, and 12 Run734 bodies. The ten span-fill
callbacks (nine absent from the main index) retain complete raw body evidence in
Run734's `original-index-supplement.json`; all 25 ranges passed the registry
overlap check, including earlier supplemental `body_ranges`.

Run732 owns 4B `.rdata`, 4B initialized `.data`, and 9,260B loader-zero
noise tables; Run733 owns two original readonly strings (79B); Run734 owns
120B initialized fill state/tables and 4B loader-zero color. The native
packets prove only their stated bounded domains. Run734's fill behavior stays
PARTIAL while software shape transfer `00571630` is open. The three audio
children use controlled endpoints in Run733; live device, concurrency,
playback, full startup and gameplay are unaccepted.

Build attempts `001` and `002` are preserved: sandboxed MSBuild stopped before
compilation without compiler/linker diagnostics. Elevated attempt `003`
completed the full compile and linker frontier check. Configure attempt `001`
passed. The build and audit commands are:

```powershell
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/735-scene-audio-render-integration/build-config.json --phase configure --attempt 001
$env:MSBUILDDISABLENODEREUSE='1'
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/735-scene-audio-render-integration/build-config.json --phase build --attempt 003
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/735-scene-audio-render-integration/acceptance.json
```

Next: integrate frozen Run736 in a new shared batch, then recover the newly
reachable children on the shortest path to a linked game executable.
