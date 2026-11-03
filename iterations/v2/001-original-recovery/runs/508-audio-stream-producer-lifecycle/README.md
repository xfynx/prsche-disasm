# Run508: original stream producer and lifecycle

Native002 PASS, frozen:8 original C++ bodies397B plus4B sparse state. `/Od`
and `/O2` each pass2,078 cases/4,525 events; all11 mutations are detected.
Total4,156 cases/9,050 events. Production source was unchanged after001.

Porsche.exe SHA256:
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
Bodies:00561200(150B),00561730(145B),005617d0(44B),00561b50(46B), plus
00589790/005897a0/005897b0/00561720(3B each). The last four are actual
closed original zero-return/no-effect helpers, with proved caller contracts.
Existing void lifecycle declarations remain: every indexed cancel/release/stop
caller discards incidental EAX. No new facade or guessed provider is added.

Producer is I32 cdecl4(release callback,consumed callback,buffer,bytes). It
checks the canonical initialized byte, finds the first free exact501 slot,
uses the actual zero-prefix/attach leaves, publishes the record and writes
only the original capacity/pointer/callback/handle fields. Unsigned capacity
division and low16 storage preserve wrapped inputs; opaque record bytes remain
unchanged. Cancel captures the record before locking, uses actual434/435 channel
stop, invokes the record-held release callback, reloads member count afterward
and frees its captured-count voice list using actual438 pool release. Release
clears the selected501 slot. Stop uses actual485 callback removal, invokes its
real typed backend frontier, then clears the sparse output pointer.

The only new state is006b7ca0's4B output pointer. Full507 ownership scan covers
277 TUs/496 source/header files, with no missing quoted include, registered
indexed body overlap or prior006b7ca0 owner. The independent PE section record
in `original-transport-supplement.json` proves loader-zero initialization in
the .data virtual tail. Adjacent ring fields and501's64B table are not copied.
Canonical initialized byte/lock/count/channel arena,501 slots,434/435 stop,
438 pool and485 unregister are reused directly.

Callback-c0 transport is established by original00589550 EDI=006b49b0 and
00589555 FF17 CALL[EDI], without argument pushes, followed by signed count
reload and4B advancement. Native comparison executes those SHA-checked FF17
bytes in a labelled synthetic saved-EDI/RET wrapper and compares typed cdecl0
host invocation. Only FF17 is original; wrapper instructions are harness code.
Both the registered callback identity and backend effect remain real frontiers.

The fixture compares the raw508 cohort alone and producer->original501/raw505
buffer delivery->cancel/release with actual501/505/493/492/434 dependencies.
Record consumption fields are controlled access-ready inputs; unrecovered
5612a0 configuration/publication is not inferred. Cases check first/full/last
free slot, unsigned capacity neighbors, producer aliases into actual canonical
slots/app arena, gate changes under locks, captured records, release mutations,
pool frees, callback removal/stop ordering, pointer clearing, opaque bytes,
used ABI and x87 state. Each side independently seeds the complete app arena
with0x69 before overrides, plus nonzero opaque record/pool bytes. This is fixture
input, not a new production initializer.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/508-audio-stream-producer-lifecycle/native-config.json --attempt 2
```

Receipt: `local/experiments/v2-audio-stream-producer-lifecycle-508/002/receipt.json`.
Passed source/config/fixture inputs are immutable.001 ended at fixture link:
the actual485 TU exposed two dead start dependencies, now fail-closed fixture
endpoints.002 also corrects per-side opaque app-arena reseeding. Original001
inputs are preserved in `local/experiments/v2-audio-stream-producer-lifecycle-508/input-snapshots-001/`.
No production algorithm changed, and passed505/501 inputs were preserved.

Exactly two new named frontiers remain:0058ad60 void cdecl0 backend stop and
005619b0 void cdecl0 registered callback. Record release/consumed target semantics
from505 remain runtime boundaries. Next trace those actual backend/ring providers
and5612a0 record configuration/publication. Full producer initialization/lifetime,
real callback implementations, inaccessible memory/unmasked faults, concurrency
and live audio/game acceptance remain open. Coordinator owns common integration.
