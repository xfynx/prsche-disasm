# Run504: coded-audio constructors and closed ADPCM setup

Native003 PASS, frozen:10 original C++ bodies840B and48 data bytes. /Od and
/O2 each pass2,480 cases/657 controlled callback events;13 material mutations
are detected. Total4,960 cases/1,314 events,405 input pins and497 output hashes.
No game integration, decoder implementation or live-audio acceptance is claimed.

Bodies: constructors597f20(65B),59c360(90B),597dc0(93B),59c9f0(91B),
59c610(118B),59b830(100B); position getters597db0(8B),597e20(11B);
ADPCM header/setup59a800(190B) and bit reader59a8c0(74B). Public control,
addressing, refill, constructor operations and loops are ordinary C++. Four
small private x87 primitives preserve unsigned64 FILD, extended factor state
and original FLOAT32 stores across the63-step recurrence. Recovered algorithms
contain no whole-function ASM or host-float approximation. No3DNow instruction
executes in this packet.

Porsche.exe SHA256:
ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
The run-local index supplement closes four omitted constructor entries and
two getter entries with complete raw bytes/RET/CFG. Existing469 dossiers were
checked and contained none of these descendants; no REA session was repeated.

Exact writable data is only5e34a0..5e34c3: nine DWORD masks36B,
0,1,3,7,15,31,63,127,255. All16 indexed direct reader calls use bitcounts
from{1,4,5,6,8};5e34c4 starts a separate decoder table. No33-cell capacity or
broad arena is inferred. Readonly scalars12B are5b2608 raw00000041(8.0F),
5b27b4 raw6f12833a(0.001F),5c1804 rawb81e853f(1.04F). Raw compiled values are
asserted before fixture resets or controlled scalar perturbations.

Fresh507 ownership checks277 accepted TU roots/497 closure files with no
candidate body overlap or existing owner for the48 bytes. Actual493 channel
owner/member helpers and501 bank lookup/sole64B slot owner execute in the native
graph. None is duplicated. Raw operands/calls are verified before35 pointer
relocations. Constructor cdecl2, used getter cdecl1, process I32 cdecl5 and
nibble decoder void cdecl1 contracts come from the real consumers recorded in
PLAN and raw evidence, not just address-taking.

Tests compare complete arena/data/table/channel/slot state, used returns,
callback argument transport, nonvolatile ABI and x87 control/status/tag/register
payloads. They cover object/parameter aliases, positive owner/member/slot lookup
composition, selector precedence, every mapped mask index0..8 and refill
boundaries, source/state/mask-table aliases, all1,024 coefficient seed pairs,
header width/flag values, sparse clears, PC24/53/64, all rounding modes and
depths0/1/3/6/7 including masked overflow. Controlled readonly scalar perturbations
exercise signaling/quiet NaNs, infinity and a negative subnormal.

    py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/504-audio-coded-constructors/native-config.json --attempt 3

Receipt: local/experiments/v2-audio-coded-constructors-504/003/receipt.json;
summary [validation.json](validation.json), COFF [coff.json](coff.json).
The passed command identifies immutable003; it rejects an existing directory.
001 passed both baselines but stopped at a nonunique mutation anchor.002 exposed
linker folding of identical decoder endpoints, hiding the selector mutation.
003 uses distinct fail-closed decoder endpoints and asserts their identities;
the selector mutation now fails. Candidate source needed no algorithm revision.
Unpinned preparation helpers/draft template remain local, outside the deliverable.

Nine real typed providers remain unresolved: six process callbacks597e30,
59c1e0,597c40,59c890,59c3c0,59b690 and three nibble decoders59a5a0/59a660/
59a730. Fixture process endpoints prove bounded ABI transport only; decoder
endpoints fail closed and never execute. Full producers/decoder semantics,
out-of-range bit requests, unmapped/lifetime faults, unmasked exceptions,
concurrency, live audio and gameplay remain open. Coordinator owns integration.
