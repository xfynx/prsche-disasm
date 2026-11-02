# Run498: bounded emulated original/C++ 3DNow comparison

Approved scope:0059bc40 accumulation and0059bb90 S16 conversion, no state.
Worker owns this run/local experiment only; coordinator owns integration/audit.
No production changes or native-hardware claim. Frozen490/492/495/497 untouched.

Evidence:497 proves installed Unicorn2.1.3 Athlon11 supports exact PF opcodes.
Raw extents159B+163B; index159B+160B excludes skipped3B PXOR at59bbc4.
Canonical486 declarations are cdecl4/cdecl3; raw eight consumer callsites and
post-call paths are to be captured. Empty FP tag/reset and subsequent x87 use
matter; unused volatile ECX/EAX residues must not force invented wrappers.

Implementation: ordinary C++ backward residual/block loops and unsigned32
addresses, private branch-free exact PF/MMX primitives, finalFEMMS. One minimal
import-free linked PE per/Od,/O2/variant; both original and compiled candidate
execute under the same Athlon11. Existing PE/COFF helpers are reused unchanged.

Readiness: exact arena/read-write order/FP-operation states and final FP state,
nonvolatile ABI, padded zero/negative counts, all16 byte alignments, overlaps,
all65536 S16 bits, exceptional FP bit products, CW/RC/depth/sticky/MXCSR seeds;
material mutations detected. Reject unexpected code/imports/faults/budget stops.
Hash compiler/emulator/source inputs, snapshots and outputs; preserve attempts.

Complete: emulated003 PASS and frozen. Per optimization1,042 cases/82,660 arena
events/55,929 PF-entry snapshots,9 mutations detected; both/Od and/O2 pass.
Zero imports/relocations, exact2 canonical COFF names/0undefineds,35 input pins.
319 indexed bytes/322 contiguous raw bytes,0state.001 was compiler C4799/WX;
002 was a harness-only by-value argument-copy overconstraint.003 corrects ABI
checks without candidate changes. README andvalidation.json own the handoff.
Next: coordinator extends acceptance audit for honest emulated proof, reviews
and integrates providers if accepted. No active worker assignment remains here.

Passed command (immutable attempt; do not rerun into003):
`py -3 iterations/v2/001-original-recovery/runs/498-audio-pcm-3dnow-cpp/compare.py --attempt 3`

Physical AMD conformance, unmasked faults, full producer/caller composition,
concurrency/live audio/gameplay remain open. Integration pending coordinator.
