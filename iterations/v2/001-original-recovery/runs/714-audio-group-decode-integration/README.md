# Run714: audio group decode integration (713)

Fresh build001 compiles 414 C++ translation units / 8 projects; 104 unresolved
names / 111 references remain, no EXE. One name closes (`00590a80`) and one
child opens (`00599610` audio group process/reload). Shared audit PASS: 120
measured native cases / 10 detected mutations / 1,024 source pins. Registry
1167 adds one full body / 205B.

713/001 audio group decode `00590a80..00590b4c`: no new cells; reused
canonical `00599100` (Run451) and device-state `006b48c0` interiors
`0xe2`/`0x120`; `00599610` left as an unowned typed child.

```powershell
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/714-audio-group-decode-integration/build-config.json --phase configure --attempt 001
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/714-audio-group-decode-integration/build-config.json --phase build --attempt 001
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/714-audio-group-decode-integration/acceptance.json
```

Remaining boundaries (backlog owns the full list): `00599610`; evidence-excluded
heterogeneous packets; storage-gated `00562810`/`00563440` (run-273 proof);
fault/lifetime/RTTI domains, live devices and full-game acceptance.
