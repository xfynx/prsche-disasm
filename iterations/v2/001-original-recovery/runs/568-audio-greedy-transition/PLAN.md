# Run568: greedy transition and creator composition

Owner: creation (Sol/high). Start from accepted Run567; preserve prior proof
inputs and keep all changes in this run and local artifacts. Original game
files remain read-only. Shared integration and registry belong to coordinator.

Resumed 2026-11-11 after accepted workspace closeout. Worker owns this run and
local artifacts only; concurrent Run569 owns its independent continuation.

The Porsche.exe binary index query `--address 0x56b540 --disassemble` identifies
110 bytes at 0056b540..0056b5ad, module SHA256
ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
It calls accepted handle validator 0056b380; failure sets original source-label
VA 005bd978 / line 0x550 and invokes the writable diagnostic callback with
message at 005bdb24. Success writes the full second argument to object +38;
when nonzero and +28 equals 1, it forwards +168 and +30 to 005681b0. The raw
file-label is metadata only; actual 00565340 pointer-consumer proof remains open.

First establish canonical 567 source/data ownership, raw message bytes, child
005681b0 ABI and callers; reuse the 565 native oracle/fixture. Original caller
0056b4c0 and its outer wrapper are available for composition. Investigate adding
actual 561 creator -> 565 wrapper composition only when the real codec-result
transport can be tested without guessed producer semantics; preserve the raw
index bits, existing 561 partial and opaque descriptor bytes.

Indexed child 005681b0 is a 68-byte cdecl2 body: it uses the first word's low
five bits, computes `canonical_device_base + 0x70*index` with original wrapping,
checks the resulting address (not merely the base) for zero, calls 00580c10, and
when nonzero writes the second argument's low byte at +0x11 before 00568200.
No current source declaration or owner was found by address. Its actual queue
composition and argument domains remain unproved.

`scope-evidence.json` pins the 567 build and registry: 316 source roots, 575
source/header files and 778 effective pins; no overlapping registered bodies
for 0056b540 or 005681b0. Canonical owner `files.cpp` defines devices_006a5c7c,
operation_matches_00567bf0 and operation_queue_00568200; `io_lists.cpp` owns
io_take_00580c10. Both child functions have existing native proofs. The predicate
is a real typed function pointer, not a raw original VA transport.

Draft 0056b540/005681b0 C++ preserves the wrapped computed-address zero test,
the full transition word and the low group-byte write. It uses canonical
predicate/device/list/queue owners. The native fixture checks original diagnostic
bytes and composes raw 565 caller -> raw 568 bodies against compiled equivalents,
using actual list/queue implementations and controlled lock/event boundaries.
Shared attempt001 passed both 1,126-case baselines but failed its group-byte
mutation: the fixture had seeded the completed list, while the original uses
the queued list at +0x24. Zero accepted receipt. After correcting the scene,
diagnostic preflight passed 1,126 cases / 2,290 events; separate diagnostics
detected group-byte, lookup-id and wrapped-zero mutations. These preflights reuse
565 Od objects and are not pinned shared proof. Attempt002 is running:
`py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/568-audio-greedy-transition/native-config.json --attempt 002`.
It checked seven mutations and one seeded full FP state; no broad FP matrix.
Native002/read-only audit now PASS2252 comparisons/4580 events/7 controls.
Run573 shared intake passes; both entries remain partial. Preserve frozen inputs.
Do not retry 565 REA's interrupted approval;
use cached REA when present and raw PE/index otherwise. After two failed attempts
on one hypothesis, preserve artifacts and report the exact issue.
