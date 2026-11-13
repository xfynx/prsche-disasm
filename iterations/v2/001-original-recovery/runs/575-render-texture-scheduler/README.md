# Run575: bounded texture scheduler and lifecycle

Shared native attempt 001 and read-only receipt audit pass: **808 scenes,
1,032 raw/core/facade comparisons, 2,898 recorded events and ten detecting
mutation controls**, across `/Od` and `/O2`. All five original entries remain
partial. The shared game integration is separate and is not yet accepted.

Porsche.exe SHA256:
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
`scope-evidence.json` pins the 574 build/registry census: 319 roots, 581
source/header files, 787 effective pins and no target/registered-body overlaps.
The indexed raw bodies are 005550e0/434B, 005552a0/40B, 00554f60/212B,
00555040/150B and 005554b0/275B (1,111 bytes). The cached Run469 REA dossier
for 005550e0 is hash-pinned in the native proof; remaining original instruction
and child evidence comes from the binary index and raw PE.

The scheduler retains its two 32-word stack arrays, original two-phase status
clearing/head snapshot and subsequent status/head tail fills. Counts are not
clamped: mapped test scenes cover 0..32, not out-of-range stack corruption.
Count/slot/dirty owners remain canonical. The original integer return is tested
through `render_texture_scheduler_005550e0`; the existing void linker facade
is separately tested for state, call order and ABI. Four indexed direct callers
overwrite EAX or call another function before observing it; indirect uses and
the incidental facade return remain open.

The source retains original dynamic stdcall driver callbacks, table/node reloads,
flags captured across upload, and the single writable cdecl callback slot
006a3a50. `message-ownership.json` pins the 120 contiguous original message
bytes at 005bc2ec (80 plus 40) and the callback's four-byte PE loader-zero tail;
the complete 574 source closure has no prior owner for either. The existing 540
source-file label is reused; fixture-owned 537/540 data views and controlled
driver/diagnostic endpoints are limited to the test executable.

The native fixture composes original scheduler -> prepare -> notify and original
572 release -> process -> notify against the corresponding compiled functions.
It compares callback order and parameters, all four written descriptor words,
nullness, used integer returns, memory, stack/nonvolatile ABI and one seeded full
x87/MXCSR state. Callback effects include index/tail changes; driver effects
include field/flags and export-slot changes. Descriptor stack pointer identity
is normalized only at the controlled callback seam. No live driver, arbitrary
stack-descriptor alias, corrupt pointer, concurrency or startup acceptance is
claimed. Earlier partial parents and dependencies remain partial.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/575-render-texture-scheduler/native-config.json --attempt 001
py -3 iterations/v2/001-original-recovery/runs/575-render-texture-scheduler/finalize.py
```

The first command identifies the immutable completed attempt; do not rerun it
with that number. The second audits pinned inputs and outputs without executing
native code. Diagnostic preflight binaries are not acceptance evidence.
