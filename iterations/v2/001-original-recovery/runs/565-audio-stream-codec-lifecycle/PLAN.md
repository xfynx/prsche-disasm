# Run565: codec access (bounded proof ready)

Scope: trace the five new Run563 frontier targets 0056aff0 (564 bytes),
0056b3b0 (175), 0056c840 (80), 0056c420 (280) and 005912e0 (58), then select
only a coherent subset with proved original state, ABI and dependency ownership.
The Run561 SHA-pinned scope census has the raw bodies and indexed calls;
Porsche.exe SHA256 is ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.

Indexed 005912e0 checks the canonical active byte, calls canonical 00566d60
outer-slot lookup on its first word, then calls 0056b4c0 with the looked-up
object's +4 and the second word. The original 005673d0 call forwards its codec
result bits as that first word. Keep this identity; do not infer or substitute
a pointer. Run561 creator is already PARTIAL with a controlled endpoint.
Other indexed direct calls: 0056c840 uses 0056b380 and the canonical writable
diagnostic callback; 0056c420 uses 0056b380, 0056c140, 0056bd10, 0056c380 and
that diagnostic callback. Source-label VA 005bd978 remains raw metadata; the
00565340 diagnostic's pointer-consuming path is not proved;
0056b3b0 calls reset, validation, lock/thread and allocation children;
0056aff0 calls accepted 0056afc0, validation/diagnostic and lock creation.
These call lists are navigation, not proof of their semantics or safe ABI.

`rea-queries.json` requests these five plus five relevant children in one
isolated session. REA attempt001 failed before analysis with sandbox spawn EPERM.
An escalated attempt002 request remained pending and was interrupted; the 002
directory does not exist, so no second session was started. Do not duplicate a
pending approval request. Search existing REA dossier caches and continue raw
PE/index/ownership tracing while the environment boundary is unresolved.

Current Run563 census: 314 compiled roots / 572 source/header files / 773
effective pins; no registered body overlaps across the five targets and
0056b380/0056b4c0/0056b540. No prior REA query manifest covers those targets.
Raw original and existing Ghidra pseudocode support a narrower four-body
candidate: 0056b380/0056b4c0/0056c840/005912e0, 305 bytes. `scope-evidence.json`
records raw PE/index/caller evidence and ownership census. New source retains
the validator's output-write order, signed threshold comparisons and original
outer-index bits; real 0056b540 remains a controlled frontier, as do diagnostics.

`prepare.py` builds one shared runner fixture with raw PE strings checked before
host relocation, canonical 561 lookup/state, mapped aliases, FPU/ABI observation
and eight mutations. Attempt001 compiled but failed link (39 support-object
references), with zero native cases. The fixture now reuses the frozen 561
support closure, with fail-closed fixture-only endpoints. Diagnostic preflight
001 passed 3,696 comparisons / 1,666 events using current fixture/source and 561
Od objects, but is not a pinned shared proof. Shared native attempt002 passed:
`py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/565-audio-stream-codec-lifecycle/native-config.json --attempt 002`.
Od/O2 total 7,392 cases / 3,332 events and eight controls; the read-only shared
receipt audit passed. `ready.json` freezes one full and three partial entries;
README.md records scope and limitations. Do not change passed proof inputs.
Original `local/game` remains read-only. Integration and current-closure audit
belong to the coordinator; no game EXE or startup is claimed.

Actual 005673d0 -> 005912e0 composition, including real creator and codec-result
identity, is not in this packet's fixture; keep it an explicit follow-up and do
not upgrade 561 partial. Full create/destroy/reset and 00566e10/00566e40/00567270
are deferred until their resource and codec closure is separately evidenced.
No guessed formats, clamps or pointer conversion.
