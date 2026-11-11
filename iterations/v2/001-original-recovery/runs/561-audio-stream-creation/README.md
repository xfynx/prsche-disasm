# Run561: bounded stream creation and lifecycle

Integrated with the original full/partial classifications through
[Run563](../563-audio-stream-creation-integration/README.md). Its shared audit
checks the current closure and production ownership; no full-game acceptance is implied.

Native attempt 003 and the read-only shared receipt audit pass: **3,562
comparisons, 2,168 events and 16 detecting mutation controls**, combined across
`/Od` and `/O2`. This is bounded function evidence; shared game integration and
the original executable's startup are separate checks. `ready.json` conservatively
lists lookup 00566d60 as full and the other seven entries as partial.

The indexed Porsche.exe SHA256 is
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
The scope and source mapping record eight original instruction bodies, 909 bytes:
005673d0, 00567690, 00567740, 00566d60, 005673b0, 00566d40, 0058ff50 and
0058ff70. The new canonical storage is the 64-byte slot region and 16-byte map
at 006b7740..006b778f, proved loader-zero in the original PE. `scope-evidence.json`
records the original index, bytes, call graph and ownership census through the
557 plus 559 source closure; the later 560 closure requires its own check.

The fixture uses real existing 508 constructor/release, 559 size and 434/438
state and pool algorithms, with controlled unowned codec and callback endpoints.
It compares returns, state snapshots, child events, stack/nonvolatile ABI and
FPU state. Scenarios include a full outer table, exhausted inner slots, descriptor
copy, signed lookup boundaries, callback table registration/removal, stop/reset,
two pool releases and populated 16-slot shutdown. Seven scenario families cover
144 x87 configurations; shutdown has one populated configuration. Original
descriptor bytes 22/23 are copied physically and remain opaque; this does not
upgrade the 556 partial parent.

Important limits: creator numeric inputs and alias layouts are narrow; the
signed pointer scan is tested only with the explicitly asserted low-address
mapping. Registration/removal's signed callback index is tested within the
mapped table, not arbitrary corrupt counts that reach other owners. The stop
fixture does not establish a true two-live-slot case. Shutdown has only one
populated scene. Actual codec/callback algorithms, invalid pointers, concurrency,
live audio and game startup remain open. No fixture endpoint is a game provider.

Attempt 001 was deliberately interrupted during compilation after wrong oracle
slab offsets were found; no cases ran. Attempt 002 compiled all source TUs but
failed fixture compilation; no link or cases ran. The compiler defects and an
independently found fixture stack-temporary overflow were corrected before 003.
Diagnostic preflight is not a replacement for 003 or its audit.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/561-audio-stream-creation/native-config.json --attempt 003
py -3 iterations/v2/001-original-recovery/runs/561-audio-stream-creation/finalize.py
```

The first command identifies an immutable, already completed attempt and should
not be rerun with the same number. `finalize.py` audits its pinned receipt,
compiler inputs and outputs without re-executing native code, and writes the
bounded ready/COFF handoff. The original game files were read only.
