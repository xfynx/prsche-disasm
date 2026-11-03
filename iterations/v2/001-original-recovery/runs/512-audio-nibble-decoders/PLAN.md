# Run512: nibble decoder footprint inventory and bounded proposal

READY: native003 frozen/Od+/O2 PASS;14 new mutations detected,395 pins/473 outputs.
Two decoder leaves385B plus placement-only486 replacement and272B writable
physical windows. Per variant12,760 new cases +4,353 fresh486 regression cases/
31,368 events; total34,226 cases/62,736 events. Original486 source/header and all
passed inputs/layout attempts are immutable. Root owns explicit TU replacement/
game integration. No semantic capacity expansion or production guards.

Attempt001 exposed/O2 SSE intrinsic operand commutation/distinct NaN priority;
tiny ordered MULSS/ADDSS primitives inside ordinary C++ loops corrected it.
Baseline002 and full003 pass. COFF confirms.nibl$a832B/.nibl$b192B and native
PE RW.nibl1024B; new80B window +fixture-only192B output slack are distinct.
Actual adjacency, oldinitializer canaries and cross-boundary aliases are gated.
validation.json/coff.json/README.md are the frozen handoff. No further worker
implementation is required; full fault/3DNow writer/live composition stays open.

2026-11-04 recheck: scope-recheck-516.json verifies all367 old pins,42 cached
objects, layout outputs and reversible clone/header identity. Current516 closure
(284 roots/511 files) still has only the canonical486 low-table owner; neither
new physical window has an owner. No quota/tool limitation during this recheck.

Layout feasibility now PASS (local layout-005, layout-feasibility.json). A byte-
reversible placement-only clone of486 CPP puts its unchanged208-float symbol
in.nibl$a; byte-identical486 header is retained. Separate192B zero tail.nibl$b
is adjacent at exactly832 bytes in/Od and/O2; PE section is RW and Windows maps
it writable-copy(Protect8). Tail canaries survive all original/C++ initializers.
Fresh complete486 fixture passes4,353 cases/31,368 events per variant.42 unchanged
dependency objects were reused only after accepted486 receipt input/object hash
checks; the old11 semantic mutation proofs are retained, not rerun. Pilot took
3.8 seconds, no original486/game-graph edit or decoder implementation.

Cross-boundary byte aliasing passes through opaque U32 memory transport. A direct
named-object C++ probe folded assumptions at/O2 (retained layout-004); production
decoder code must use the project's raw-address primitives and verify actual
crossing aliases at/O2, not rely on C++ array-subscript access beyond208.

Proposed reviewed scope is now two new leaves385B plus a placement-only486 TU
replacement(0 new original-body count) and272B original writable physical windows:
80B high-read window including shared5e3b58 scratch,192B ordered low-tail window.
This supports all256 header byte reads without calling them sixteen semantic
predictors/rows or adding guards. New proof should batch the unchanged486 fixture
regression and two decoder cases/controls in one shared native runner; original
486 inputs stay immutable. Count<=0 uses the exact U32 ECX-residue address path
in mapped cases; arbitrary faulting addresses and full59cd70 writer composition
remain explicit boundaries. Coordinator approved this exact scope on2026-11-04.

Scope proposed before code:0059a5a0 x87(185B) and0059a660 SSE(200B), two closed
leaves385B. Bounded native proof now passes. Worker owns512/local only;
coordinator owns integration. Keep0059a7303DNow separate and unrecovered.

Original SHA:ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
Reuse504/scope-evidence.json for both complete indexed/raw bodies and the actual
constructor/process consumers; no duplicate dossier/disassembly report needed.
504 constructors select x87/SSE/3DNow by CPU flags. Actual597d28,59c4b3/4ff and
59c953 push object+0c, discard4, ignore volatile result: void cdecl1(state).

Two specific producer-domain hypotheses were checked and did not prove bounds:

1. Constructor/mixer selection constrains compressed headers. Raw597dc0,
   59c9f0,59c610 only store source/limit/CPU-selected callback.5984d0/59a3e0
   dispatch by format and pass input data;596b60/596f20 pass record pointers.
   Process597c40/59c890/59c3c0 computes source offsets and invokes the decoder
   without validating either header nibble. CPU selection flags constrain the
   implementation, not predictor/shift bytes.
2. Load/conversion validates payload bytes. Raw58e500->58e310 conversion
   dispatches format3/10 to597dc0 and immediately invokes its callback; no
   predictor/shift check occurs. Accepted451's599100 record decoder translates
   metadata and payload pointers but does not scan compressed block headers.
   These traced paths establish no global asset-validity guarantee. No further
   speculative validation assumption is made.

The earlier partial-domain proposal(high0..3/low0..12) is superseded by the
physical-window proposal, subject to actual new decoder proof. Mapped padded
state/input/output/table memory and masked FP exceptions remain proof bounds.
No asset-wide header validity claim or new production guard is required.

Initial coefficient views occupy32B at5e3b28..47 within the proposed80B owner:
A={00000000,3f700000,3fe60000,3fc40000},
B={00000000,00000000,bf500000,bf5c0000}, B is base+16. Preserve physical views
and aliases; no overlapping duplicate arrays. The adjacent48B have separately
proved raw bytes and a shared mutable scratch alias, as documented below;
neither window establishes a semantic predictor capacity.

Reuse486 audio_mixer_nibble_lookup_006b04c0[208], exactly832B ending exclusively
at6b0800. Its initializer proves13 rows, and no owner extends it to16 rows.
Predictor cells at5e3b28 are physically disjoint from this table. Current516
ownership is rechecked above. No new callbacks or direct function dependencies:
two new providers/385B,272B new physical storage plus placement-only486 replacement.

Raw state is20B: signed count+0, FLOAT32 histories+4/+8, input+0c, output+10.
Each positive iteration subtracts28 and consumes15 compressed bytes, produces28
FLOAT32 outputs; count can end negative. Input pointer is captured but never
stored back. Preserve U32 address/count arithmetic and exact alias order:

- x87 writes histories to output[-1]/[-2] before reading state.input/count;
  loads A/B once per block; rereads rounded output/history memory for each pair;
  reads the low nibble before the first output store and the next compressed
  high nibble before the second output store, including
  one byte beyond the last15B block. Keep the exact FADD/FADDP order and retained
  extended coefficients through private straight-line primitives.
- SSE loads histories before count; reloads A/B from memory inside each pair,
  computes the second B product before the first output store, then rereads the
  compressed low nibble after that store. Ordinary C++ loops plus scalar SSE
  ordered primitives retain these ordering/NaN/rounding differences, not unify the
  two algorithms or replace them with a host-float recurrence.
- x87 nonpositive entry has an additional raw boundary: ECX still holds incoming
  history2 bits when59a640 reads output+ECX*8-4/-8. Do not add a zero guard or
  silently use output[-1/-2]. Native proof may include specifically mapped cases
  with history2 bits0/80000000/small raw indexes; general faulting cases remain
  unresolved. SSE nonpositive entry just writes captured histories/output back.

Native proof proposal: shared native-batch runner and nearby504/492 fixture shell;
raw operands checked before transport, canonical486 table executed/reused. Compare
both/Od and/O2 whole memory, FP control/status/used state and preserved ABI across
all256 headers, block/residual counts, NaNs/subnormals/infinities, x87
PC/RC/depth, SSE MXCSR RC/FTZ/DAZ, input/output/state/predictor/lookup aliases and
lookahead order. Mutations target cached-vs-reloaded coefficients, compressed-byte
load/store ordering, FP association/F32 boundaries, history/store direction and
unwanted count guards. Keep source unintegrated until this proof passes;
no game/native3DNow/complete decoder-composition claim.

Exact next external-domain trace: capture format3/10 data pointer and sample count
at original58e617->58e310 or596c2a->5984d0 with a known original asset; enumerate
15B block headers for that bounded resource and trace where the pointer originated
before declaring asset-wide validity. The current record/constructor path alone
does not prove it. Asset validity remains a separate trace, not a blocker for
the physical-read proposal. Next step is coordinator integration/audit;
no broad table copy, framework or original-resource edits are needed.

## Physical-read alternative, after the two producer hypotheses

- High nibble: A reads5e3b28+4*h, B reads5e3b38+4*h for h0..15. Their union is
  exactly5e3b28..5e3b77,80B. The existing32B proposal is followed by48B of
  file-backed writable.data, not relocatable pointer fields. Adjacent raw48B:
  00000000000000009cfc7f379cfc7f3700000000000000000000003f0000003f00000040000000400000404000004040.
  The original preferred-base PE has zero relocation targets inside this union.
- Those48B are not an immutable coefficient extension. Unrecovered3DNow
  59cd70 loads a DWORD through its argument pointer and writes5e3b58 at59cd89,
  59cdcb,59cdfe,59cf43. It reads the overlapping unaligned DWORD5e3b5a and
  packed FLOAT32 pairs at5e3b50/60/68/70. High reads can therefore observe a
  live packed input scratch value. Preserve one writable physical window and
  future writer aliases; never duplicate it as a separate constant table.
- Low nibble: canonical486 owns6b04c0..6b07ff,832B. Rows13/14/15 physically
  read6b0800..083f/0840..087f/0880..08bf,192B. This entire tail is loader-zero
  writable.data beyond the PE file-backed prefix, with no relocation targets.
  The only indexed/relocated reference into it is486 initializer's exclusive
  end-address comparison6b0800. No indexed access/write to the192B was found.
  Arbitrary indirect stores remain an explicit unresolved boundary.
- All36 relocation-based references to the full two footprints are in.text;
  there is no relocated pointer object inside or pointing from.data to them.
  physical-views.json retains exact bytes, sections, xrefs and writer instructions.
  Current514 ownership still finds only the canonical486208-float table, no
  owner for the80B high-read window or192B tail.

Conditional alternative: preserve all256 header byte reads with canonical486 plus
one80B original writable read window and one192B original zero-tail window,272B
new storage total. Name them physical windows, not sixteen predictors/rows. This
requires shared scratch aliases for future59cd70. Layout feasibility now proves
ordered486/tail adjacency and raw cross-boundary transport; actual decoder
alias proofs remain required. No decoder implementation or all-header acceptance
follows from the inventory/layout pilot alone.

Actual caller count assignments (raw contexts retained in physical-views.json):

- 597d14 writes EBX before597d28, the signed minimum of requested remainder and
  clamped available samples; there is no strict-positive check at the call.
- 59c49f writes EDI before59c4b3. Under non-overflow positive remaining data/
  request it is a positive28-sample block multiple, using floor(data/28) and
  ceil(request/28); arbitrary signed-overflow states remain unproved.
- 59c4e7 writes exactly28 before59c4ff: this call's count is provably positive.
- 59c93f writes max(0,min(request-leftovers,loop_start-position-27)) before
  59c953. It explicitly permits zero. For example initial loop_start=position=0,
  leftovers=0, request=1 reaches this zero assignment; no universal positive
  caller contract can justify removing the decoder's nonpositive path.
