# Run561: stream creation and lifecycle (unfinished)

Status: native 003 and shared receipt audit PASS; bounded ready set is 1 full and
7 partial entries. Run563 shared game integration audit now passes; full gameplay
acceptance remains open. Preserve the 559
proof unchanged; see README.md and ready.json for the final handoff.

Porsche.exe SHA256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
The binary-index query `--address 0x5673d0 --disassemble` and the pinned raw
instructions/callers in `scope-evidence.json` identify eight candidate bodies:
005673d0, 00567690, 00567740, 00566d60, 005673b0, 00566d40, 0058ff50,
0058ff70 (909 bytes). The draft census found no registered body overlap and
the 80-byte slots/map extent is PE loader-zero; verify ownership and aliases
again if the shared source closure changes. This is navigation and static
evidence, not behavior acceptance.

`prepare.py` emits the candidate source, instruction mapping, fixture and config.
Its sixteen mutation anchors now match exactly once; two earlier addresses were
corrected. Attempt 001 was stopped during compilation, before execution, after
four wrong fixture slab offsets were found. They were corrected and bounded
stop/reset scenes added before attempt 002. Attempt 002 compiled all 44 source
TUs at both settings, then fixture dependency probing failed before link or
native execution: `audio_platform_sleep_455` had the wrong calling convention
and two range-for variables lacked declarations. The fixture source now fixes
those three errors; attempt 003 subsequently compiled and verified the frozen
inputs within the stated domains. Run563 subsequently passed shared integration.

The raw creator scans sixteen slots, calls the existing 508 constructor, maps
its successful inner index to the outer slot, physically copies all 28 descriptor
bytes and publishes the slot before reset. Preserve the two opaque descriptor
bytes; this does not upgrade the 556 partial parent. Original callback register
uses a signed byte as a physical array index, and unregister uses signed count;
do not silently clamp them or assume arbitrary corrupt states fit the current
canonical device backing. The scan/count loops use signed pointer comparison;
record the actual mapped address domain in the native proof.

The shared 559/556 scaffold supplies controlled codec/callback endpoints, actual
508 and 559 providers, production zero check, raw relocation checks, state
snapshots and bounded scenes, including inner-slot exhaustion, reset buffers,
two voice pool releases, last/non-last stop, sixteen-slot shutdown, signed slot
address assertion and 144 FP configurations. Attempt 002 used
`py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/561-audio-stream-creation/native-config.json --attempt 002`.
This attempt has zero native cases/mutations and no link. A diagnostic fixture
compile/link using the 002 Od objects then detected a trace-reset stack overflow;
replacing its large temporary with zero-fill fixed it. The local preflight 003
passed 1,781 native comparisons and 1,084 events. This diagnostic is not a shared
proof: it did not establish current-input pins, O2, mutations or integration.
Shared attempt 003 passed Od and O2 baseline execution (1,781 comparisons and
1,084 events each) and all 16 mutation controls. Shared read-only receipt audit
passed. Avoid overwriting any attempt; callback/alias and live producer domains
still require review. The stop fixture does not establish two live slots, and the
shutdown coverage is one populated configuration.
Do not claim proof or add providers to the game until the receipt and shared
integration audit pass. Actual callbacks, live audio, corrupt pointers, faults,
concurrency and full parent composition remain open.
