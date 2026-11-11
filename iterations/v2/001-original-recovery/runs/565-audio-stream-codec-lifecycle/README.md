# Run565: bounded stream-handle access

Integrated through [Run567](../567-audio-codec-control-integration/README.md),
retaining one full validator and three partial entries. Parent semantics remain bounded.

Shared native attempt 002 and its read-only receipt audit pass: **7,392
comparisons, 3,332 events and eight detecting mutation controls**, combined
across `/Od` and `/O2`. The ready handoff marks the 0056b380 validator full and
0056b4c0, 0056c840 and 005912e0 partial. Integration is a separate operation.

Original Porsche.exe SHA256:
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
The binary index and raw PE identify the four bodies (45, 122, 80 and 58 bytes;
305 total). `scope-evidence.json` records their raw bytes, callers and the 563
ownership census: 314 source roots, 572 source/header files, 773 effective
pins and no target/registered-body overlap. Recensus a later intake closure.

The validator checks the original `STRM` word and preserves the order of both
output writes, including mapped aliases and unaligned addresses. The greedy
setter preserves signed threshold comparisons and forwards transitions to real
but still unresolved 0056b540. The frame getter preserves wrapping subtraction.
The 005912e0 wrapper checks the active byte and uses canonical 00566d60 lookup
on its first **integer word** before forwarding the selected object's +4. The
original creator 005673d0 passes its codec-result bits as that word: no pointer
conversion or assumed slot equivalence is introduced here.

The fixture composes raw and compiled packet bodies with the actual canonical
561 lookup/state and controlled diagnostic and 0056b540 endpoints. It compares
memory, event order/arguments, consumed returns, ABI and x87 state at 144 FP
configurations. The original file label and both diagnostic messages are read
from PE bytes and checked before host relocation. The two host message arrays
contain 90 original bytes including terminators; the file-label VA remains raw
metadata. Fixture endpoints never enter the game.

Limits: actual creator-to-wrapper composition and real codec-result production
are not established; 561 creator remains partial. The frame subtraction values
are narrow despite native and mutation coverage. Real 0056b540, arbitrary
invalid pointers, wider aliases, concurrent calls, live audio and startup are
open. Full codec create/destroy/reset and service callbacks are outside the packet.

The batched REA attempt 001 failed before analysis with sandbox `spawn EPERM`;
the attempt 002 escalation was interrupted before launch. This packet used raw
PE/index plus pre-existing Ghidra pseudocode and does not claim an REA audit.
Native attempt 001 compiled but failed link because a reduced set omitted
dependencies of canonical owner objects; zero cases ran. A diagnostic link
with frozen 561 Od objects passed before the complete shared attempt 002.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/565-audio-stream-codec-lifecycle/native-config.json --attempt 002
py -3 iterations/v2/001-original-recovery/runs/565-audio-stream-codec-lifecycle/finalize.py
```

The first command identifies the completed immutable attempt; do not rerun it
with that number. The second audits its pinned receipt without executing native
code. Original game assets were only read.
