# Run749 audio SCHl closure integration

The fresh Win32 build on Run747 compiles **438 translation units** across eight
projects, with no compiler or other linker diagnostics. Adding the frozen
Run744 header parser and Run748 `SCHl` parent closes the reachable
`audio_stream_service_chunk_schl_00566ea0` name with zero new unresolved names.
The measured frontier is **98 names / 106 references**. There is no game EXE.

The shared audit passes for Run744/002 and Run748/003: **62 original-x86/C++
comparisons**, **29 material mutations**, **1,082 source pins**, two REA
sessions, and 1,371 checked canonical COFF providers. Registry entries rise
from 1,232 to **1,237**: four Run744 header functions and the Run748 parent.
The five inclusive original body ranges have zero overlap with existing
registry and supplemental `body_ranges`. Neither packet owns new
`.data`/`.rdata`/`.bss` bytes.

The parser proof covers bounded valid headers and channel counts. The parent
proof covers mapped valid slot/chunk/list inputs, exact callback payload and
call order, and reuses Run744's original parser behavior. Voice start
`005612a0`, real notification callbacks, live playback/device behavior,
faults, concurrency, startup and gameplay remain open. The render conversion
frontier remains separate and partial in Run745.

```powershell
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/749-audio-schl-integration/build-config.json --phase configure --attempt 001
$env:MSBUILDDISABLENODEREUSE='1'
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/749-audio-schl-integration/build-config.json --phase build --attempt 001
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/749-audio-schl-integration/acceptance.json
```
