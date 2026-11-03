# Run506: original matrix multiplication and surface configuration

Native001 PASS at `/Od` and `/O2`:278,272 cases per variant,556,544 comparisons
total. All12 mutations detected. Passed production/header/config/fixture/scope
inputs are frozen. Three complete originals/745B, zero new original storage:
005398b0/532B multiply,00539b00/45B wrapper,005392d0/168B configuration.

scope.json records binary-index queries, SHA-pinned raw bodies/instructions,
16 exact multiplication operand schedules, ABI and original scalar provenance.
Run469 dossiers and503/496 tracing are reused. There is no new REA session.

Multiplication is ordinary C++memory traversal and sequential output stores.
Every output cell reloads its inputs, preserving exact/partial output aliases
with either input. Its bounded four-product x87 primitive retains each cell's
original FLD/FMUL operand orientation and product/addition order without
intermediate float32 spills. This includes the differing schedules among cells;
an algebraically equivalent uniform dot-product order is not substituted.
The wrapper computes multiply(source,destination,temporary64B), then copies
that complete temporary into the destination. Both original EAX pointer returns
and the caller's void used-effects facade are compared.

Configuration runs the actual accepted503 identity, performs its original field,
counter and dirty writes in ordinary C++, and uses bounded arithmetic primitives
for the negative scaled value and two ratios. The latter retains the extended
denominator in x87 registers across both divisions. It references the actual
readonly global::_DAT_005b2624 owner in468; its loaded word is compared to raw
BF800000 in the pinned original before relocation and its mapped protection is
checked. No new scalar owner or literal-backed replacement is introduced.
The used core returns the original incremented counter; the existing void facade
discards it. Unmasked FP-fault timing and concurrent intermediate stores remain
outside the proof domain.

The oracle composes the complete original multiply/wrapper/config bodies and
original503 identity. The compiled graph links actual503 and468 source TUs,
plus canonical game_setup_globals needed by the complete503 TU. Uncalled503
constructor dependencies fail closed; no fixture provider enters the game graph.

The main sweep crosses PC24/53/64, all4 rounding modes and incoming x87 depths0..6
with24 finite/cancellation/special-bit patterns and4 unaligned receiver offsets.
Multiplication covers16 disjoint/exact/partial alias layouts. Wrapper/config core
and void facades are compared. Cases include signed zero, subnormals, infinities,
qNaNs/sNaNs and raw payloads, counter wrap, all1024 arena/guard bytes, ESP/EBP/
EBX/ESI/EDI, used EAX and x87 control/status/tag plus every occupied80-bit value.
Another2048 deterministic finite configuration triples exercise ratio rounding.
Empty x87 register contents and FIP/FDP instruction/data addresses are excluded.

Mutations detect reversed operand loading, changed addition order, premature
float32 spills, cached input across alias writes, wrong source offset/product
orientation and configuration scale/sign/scalar/field/counter defects. Concrete
witnesses include a cached-source alias changing670F0E27 to5909B881 and a spilled
denominator changingBF7FFFFF toBF800000 at PC53/downward rounding. Reversed first
operands also change x87 status29 to2B on a mapped partial-alias case.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/506-render-matrix-config/native-config.json --attempt 1
```

Receipt: local/experiments/v2-render-matrix-config-506/001/receipt.json.
coff.json records strong/undefined providers and rechecked213 input pins/209
outputs. Integration adds render_matrix_506.cpp and this include directory;
503/468 sources remain their existing canonical owners. Coordinator owns common
registry/CMake/build/audit. No accepted earlier input is edited.

The six-argument538da0 bounds/init body remains deferred. Null/unmapped memory,
unmasked FP faults, concurrency, real device/subsystem composition and live
startup/display/gameplay are not established by this bounded native packet.
