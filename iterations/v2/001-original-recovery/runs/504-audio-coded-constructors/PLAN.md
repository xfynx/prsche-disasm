# Run504: coded-audio constructors and closed ADPCM setup

Quota handoff: approved scope, unvalidated C++/header/fixture-body drafts exist.
No complete native fixture/config, PASS receipt or game integration exists. Resume
from these files; do not regenerate accepted prior proof. Previous worker owned this run and
`local/experiments/v2-audio-coded-constructors-504`. Coordinator owns acceptance,
registry/build/root plans/commit. Existing493/498/501 proof stays frozen.

Proposed coherent native cohort:10 bodies840B and48 data bytes:

- Six486 frontier constructors557B:597f20(65),59c360(90),597dc0(93),
  59c9f0(91),59c610(118),59b830(100). All are void cdecl2(object,params).
- Stateless position getters597db0(8),597e20(11), U32 cdecl1(object).
- Closed ADPCM header/setup59a800(190), void cdecl2(data,state), and its bit
  reader59a8c0(74), U32 cdecl2(state,bits). No decoder algorithm is pulled in.

Original Porsche.exe SHA256:
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
The index locates597dc0/597f20 and both ADPCM helpers. Four remaining constructors
and two getters are omitted as functions but have complete raw bodies/RET/CFG;
add a run-local supplement before native acceptance, not guessed prototypes.
469's117 dossiers were checked: no relevant cache hit and no repeated REA needed.

ABI evidence before binding:

- Real5985ca and59a4a2 push params then object, call the486 constructor table,
  discard8 bytes and ignore EAX. No new calling convention is inferred.
- 597dc0 writes getter597db0 toparams+1c;597f20 writes597e20 there.5985d0/d6
  transports that cell to the mixer record+38. Real599a00 loads that target,
  pushes record+3c object, CALL ECX at599a1d, discards4 and returns EAX.
  This proves both getters' used U32 cdecl1 contract through a real consumer.
- All six process pointers occupy object+4. Accepted475's original5987d2
  chain dispatches cdecl5(object,count,input,output,opaque) and tests signed EAX.
  Constructor bodies plus real dispatcher prove I32 cdecl5 for six typed child
  callbacks; stored code pointers alone are not the evidence.
- Nibble decoder targets59a5a0(x87),59a660(SSE),59a730(3DNow) are selected by
  flags: bit4 wins, else bit2, else x87. Real597d28,59c4b3/59c4ff and59c953
  push object+0c, call the selected field(+9c/+34/+38), discard4, and ignore
  volatile return state. Their prologues read the same one stack argument.
  Contract is void cdecl1(state). They stay unresolved; no native3DNow run.
- ADPCM constructor597f31 and real stream process59c280 push state then data,
  discard8 and ignore EAX. Reader returns are consumed as header fields/scales.

Exact data and ownership:

- 005e34a0..005e34c3: nine DWORD cells/36B in writable.data, raw
  `0,1,3,7,15,31,63,127,255`. Sole indexed address consumer is59a8cd.
  All16 indexed direct reader calls in59a800/59a910/59abe0 push constant
  bitcounts from{1,4,5,6,8}; the highest read is5e34c0. Next distinct label is
  5e34c4, a separate decoder coefficient table. Own only these36 bytes;
  never infer a33-cell mask table or include the next coefficient arena.
  Reader proof can cover0..8 cells; out-of-range bitcounts remain outside
  the bounded mapped-data domain. Do not add a production guard/formula.
- Three readonly DWORD FLOAT32 cells/12B:5b2608 raw00000041(8.0F),5b27b4
  raw6f12833a(0.0010000000474974513F),5c1804 rawb81e853f(1.0399999618530273F).
  Assert compiled raw bits before fixture resets; do not regenerate constants.
- Accepted491267 TU roots plus pending493/501 produce269 roots/482 closure
  files. No data/address owner is present for these48 bytes or four helpers.
  Six constructor hits are only existing486 declarations/address use. Registry
  indexed-body/exact-entry overlap check finds none for the10 candidate bodies.
- Reuse493 channel owner589710/member589740,501 lookup59c130 and sole stream
  slot owner006b7cc0[16]. Reuse434 canonical channel state. Constructors add
  no global/arena ownership; all other writes are to caller-provided objects.

Ordinary C++ recovery shape:

1. Recover reader's exact load/store/refill order with raw U32 address arithmetic.
   It reads the real mask cell, shifts, stores remaining bits/payload, and if
   signed remaining<8 reads exactly one byte and advances the pointer once.
   No inferred refill loop or count guard. Preserve state/source alias behavior.
2. Recover ADPCM setup as C++ header calls,63 coefficient steps and exact sparse
   clears. Fixed private x87 primitives retain unsigned64 FILD, FLOAT32 store
   boundaries and a live extended factor for the63-step recurrence. No foreign
   call occurs while factor ST0 is live. No double/float recurrence substitute.
   State writes end atstate+67f; preserve the separate holes/ranges.
3. Recover six constructors and two getters with exact instruction load/store
   order, including params/object aliasing.597dc0 writes params+1c early; nibble
   stream59c610 stores its callback before reading params5;59c360/resampler
   capture params5 first. Stream member/limit/flags reads differ and must not be
   normalized into a guessed common constructor helper.

Remaining production frontier:9 typed names after this cohort (all new callback
bodies remain unimplemented):

- I32 cdecl5 audio_adpcm_process_00597e30 and audio_adpcm_stream_process_0059c1e0.
- I32 cdecl5 audio_nibble_process_00597c40, audio_nibble_loop_process_0059c890
  and audio_nibble_stream_process_0059c3c0.
- I32 cdecl5 audio_resampler_stream_process_0059b690.
- void cdecl1 audio_nibble_decode_x87_0059a5a0,
  audio_nibble_decode_sse_0059a660 and audio_nibble_decode_3dnow_0059a730.

Native proof plan: reuse493 fixture/shared native-batch runner with raw bodies
and new cases. Run/Od and/O2 once per ready cohort. Assert raw table/scalars,
transport code pointers only after raw operand identity, execute actual493/501
owner/member/lookup in composition, and use fail-closed typed callback endpoints.
Exercise all constructor flag selectors, nonzero opaque bytes, object/params
aliases, callback-state reloads; all byte header combinations in compact batches,
reader0..8 bitcounts/refill boundaries/source aliases, recurrence rounding and
x87 PC24/53/64/RC/depth including masked overflow. Compare memory, intermediate
state, call order, used returns and nonvolatile ABI. Mutations must catch ordering,
selector precedence, masks/refill, FLOAT32 rounding/recurrence and sparse clears.
Do not execute nibble/3DNow process bodies or claim full producer composition.

Inspection: `py -3 iterations/v2/001-original-recovery/runs/504-audio-coded-constructors/inspect.py`
created immutableinspection-002 andscope-evidence.json,25 raw navigation bodies,
registry/source closure and data hashes. It rejects an existing output directory.
Scope approved:10 bodies840B/48B. Next finish the shared fixture/config, supplement
omitted entries, run original/Od/O2 comparisons and mutations; only then intake. Physical faults/unmasked FP, lifetimes/concurrency/live audio/gameplay
and all deferred decoder/process algorithms remain open.
