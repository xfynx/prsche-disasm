# Run 019: mixed scene and original contact preparation

2026-10-06. Porsche.exe SHA256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
Addresses are VA. Index entry point: `research/binary-index/README.md`.
Queries: `query-binary-index.py --binary Porsche.exe --address <VA>
--disassemble --limit <N>` for 0x487e80, 0x488090, 0x488590, 0x488440,
0x485100, 0x4740d0, 0x484630, 0x495020, 0x494000, 0x494480,
0x499730, 0x499a70, 0x49b510, 0x410730, 0x49ba30.
Raw callback/table/constant queries used `inspect-pe-range.py` at 0x4852b0,
0x489cc0, 0x5328d0, 0x489f10, 0x5b484c, 0x5b242c, 0x5b24a8.
Saved exports and differential fixtures are in
[Run 019](../../runs/019-original-contact-runtime/README.md).

## Direct EDG load, not mandatory generation

0x4880e3 calls 0x487e80; **0x4880ed jumps to 0x4882c4 on success**.
0x487e9b..a3 returns false when opening the file fails. After reading the
28-byte records it returns true at 0x488085, including an empty opened file.
Thus the temporary flag-0 tree and 0x488590 are the missing-file fallback,
not a required rewrite of each successfully loaded EDG file. Earlier working
hypothesis that every raw EDG needs clipping was rejected by this branch.
0x488590 generates edges between shared polygon vertices in its tree; it
does not accept a raw edge vector as its geometry input.

0x487ecb..0x487f1a reads both XYZ endpoints, copies the first record byte to
the constructed object's word, then calls 0x485100. Constructor adjustment
must be preserved: if either XZ span exceeds 100 (0x5b242c), replace A with B
and set B.x to B.x+1 (0x5b24a8). No endpoint sort or flag interpretation.
The original 0x4852f0 predicate calls 0x489cc0 in XZ, inclusive at endpoints;
parallel lines fail. Query directions are f32 stores, edge directions remain
in x87 registers. Finite inputs and f64 intermediates form the portable bound.

Insertion order: retained flag-1 vector at 0x4883bc, then EDG vector at
0x4883f5. 0x484ae0 copies each object's type byte to the leaf record. All
types count toward 48-record splits and keep their insertion order during
redistribution. Mixed records can change support node/cache selection even
when the type-1 query ignores EDG entries. The live track loader now inserts
constructed file EDG into the same immutable tree used by all four wheels.
Absent EDG is explicitly diagnosed; no invented boundary generator is used.

## Complete type-2 query and first body contact

0x4740d0 first requires owner+0x28 nonnull. It passes the first segment
endpoint and float(abs(dx)+abs(dz)) to 0x484630. That traversal visits leaf
nodes in order 2,0,3,1, with strict negative and inclusive positive midpoint
tests. It is not a tight segment AABB. Candidate type must be 2 and original
segment intersection true. Strict least absolute midpoint-Y difference wins;
ties preserve the first record. The best distance is stored to f32 on each
replacement. Endpoints remain ordered and object word is returned unchanged.
The portable API reports a null leaf vector as outside its valid contract
instead of dereferencing invalid original memory.

Three complete mixed trees (leaf, forward split, reverse split) and 27 edge
queries match unchanged x86, including owner gate, ties, reversed edges,
constructor adjustment, endpoints and raw words. Old polygon-only insertion
and cached query fixtures still pass. The public polygon-only insert rejects
a mixed arena unless both immutable geometry arenas are supplied.

First-contact API covers 0x495020 through the first call at 0x4954ff:
eight source candidate points; candidate support and +/-4 gate; center query;
center-minus-velocity/32 fallback; selected EDG; signed XZ normal; infinite
line projection; correction times original 1.01. Eight real original calls
match first-contact and no-hit paths, including the fallback segment start.
The source default containment method at 0x508000 is `xor al,al; ret 4`,
verified by a bounded raw decode because it has no indexed function entry;
the EDG vtable slot +0x0c points there. It runs unchanged in the replay.
This API stops before response: it does not claim repeated-contact/effect
callbacks or the complete 0x495020 function.

## Complete scene-dependent response

0x494000 takes a private copy of car+8, selects support at point+displacement
with reuse flag zero, and leaves the persistent owner unchanged. On a miss
it scales the incoming normal by zero; on a hit it copies displacement.
It then multiplies that correction by original 1.05, before the existing
restored response kernel. A miss removes correction but still changes velocity
on the closing branch. 0x532b20 returns length and never normalizes its input.
45 complete unchanged x86 calls match support, correction, position, velocity,
speed, projections, angular callback, four point groups, reset fields and return.
This closes the preparation gap in the pure original-state API; it does not
manufacture a binding to the existing gameplay rigid body.

## Wheel and car state boundaries

0x494480 returns 1 for a zero material nibble; otherwise the plane difference
against car+0x334 selects 0 or 2 at inclusive +/-4. Five x86 cases match.
0x499730 preserves material displacement state at +0x82c/+0x830/+0x834 and
the explicit process RNG state; 29 x86 state transitions match. Equality at
the period does not reset state; the unrounded x87 phase is compared before
its stored f32 is consumed. Even zero amplitude updates RNG seed and full
product +0x655a0c. The initial narrow seven-case fixture did not expose these
two distinctions; all 16 material nibbles and gate/period boundaries now do.
Both have
pure Rust APIs, and are not plugged into the existing force adapter.

Producer trace: 0x49b510 stores extent arguments at +0x3a8/+0x3ac/+0x3b0,
but callers 0x4107e2/0x410832 pass the car's already-existing extent fields.
This is initialization/reset, not proof that visible mesh min/max is their
source. 0x49ba30 produces +0x490/+0x4a8 conditionally from body basis and
an input normal using normalized cross products; they cannot always be
replaced by the current rigid body's right/forward vectors. Original +0x38c
uses turns/64 per orientation callback (existing angular-field trace), not
a proven conversion from current radians/second. Offset-writer navigation
was performed in `local/experiments/019-contact-writers.py`; same offsets on
unrelated base pointers were excluded, not promoted to semantic proof.

Remaining: special box/cylinder scene transforms and record semantics;
missing-EDG generated boundary path; physical extent/wheel point producers;
full 0x499a70 alternate-height/front-wheel offset and force updates; repeated
body contacts, 0x494df0 impact/effect path, car-car original contacts and cadence.
The extent reset's caller 0x4110a0 invokes 0x410730 at 0x4110d7/0x41110b;
follow pre-reset construction and indirect block writes there instead of
equating extent arguments with visible mesh size.
Next exact wheel trace is 0x499bc4..0x499d15 (fallback normal/base and front
offset 0x493bc0), then +0x64/+0x6c state at 0x499d15..0x499eec and its later
force consumers. Current spring/body response remains the existing adapter.
Iteration 012 also requires the existing T01/T02 UI/mission/original comparison.
