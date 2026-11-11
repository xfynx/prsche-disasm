# Run568: greedy transition and creator composition

Owner: creation (Sol/high). Start from accepted Run567; preserve prior proof
inputs and keep all changes in this run and local artifacts. Original game
files remain read-only. Shared integration and registry belong to coordinator.

Closeout 2026-11-11: planning/index-trace checkpoint only. No implementation,
native proof or integration is included. Worker mutations are frozen while the
coordinator reviews and publishes outstanding research; ownership is historical
until reassigned. Continue from the concrete census/ABI step below.

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

No implementation, native receipt or integration exists yet. Next: census the
567 source closure and registry, resolve canonical device/00580c10/00568200
ownership and child ABI, then select a bounded batch and pin evidence before code.
Do not retry 565 REA's interrupted approval;
use cached REA when present and raw PE/index otherwise. After two failed attempts
on one hypothesis, preserve artifacts and report the exact issue.
