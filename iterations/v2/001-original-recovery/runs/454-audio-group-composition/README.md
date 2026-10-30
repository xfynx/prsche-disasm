# Run454: bounded audio group/decoder/removal composition

Native006 PASS:33 cases/518 intermediate scenes each at `/Od` and `/O2`
(66 cases/1,036 scenes total), with11 detected mutations. Both main logs have
identical hashes. This includes three direct frozen-TU composition scenes.
`validation.json` records case subsets, source pins and proof boundaries.
This packet adds proof only: zero new original bodies, production changes or
storage. Frozen448/451/452 supply twelve existing bodies/2,262 original bytes.
The five448 bodies include the standalone validator; outer group release does
not call that validator, so each case records the actual original-body subset.

The shared native runner compiles the real451/452 decoder/remover, canonical
application device owner and443 DirectSound owner. A harness TU includes frozen
448 with only entry/core and two external callee symbol renames, allowing
decoder/process boundary snapshots. A second, direct frozen448 TU supplies
three direct composition scenes without decoder/process interposition.
No accepted source/header or previous run is edited. Existing exhaustive proof
448003,451004,452001 and REA447003/453001 are reused unchanged.

Instrumented cases call the full outer group function. The real2048B scratch
is checked in full, including every untouched odd word. The real184B resource
frame keeps its164B record and original relative argument/payload positions:
cursor is record+a8, scratch argument is record+ac, payload is record-20.
At each new resource, a synthetic fixture input seeds the164 record bytes;
continuations retain every byte and subscriber side effect. A reused synthetic
callsite seeds the decoder's opaque0x464 stack backing; no clear or count guard
is added to production. This is a bounded input domain, not arbitrary native
stack equivalence. Snapshots compare all164 record bytes, all6144 slot bytes,
all2048 scratch bytes, complete maps, headers, group tables and device backing,
with no pointer normalization. Raw original defaults and loader-zero globals
are checked against the PE before fixture resets or address transport.

Representative branch-driven cases cover relative selection, kind4/prefix8,
multiple FE continuations, token14 counts0..4, reverse subscriber payloads,
signed subscriber counts, map miss/null/zero handles, duplicate map keys,
COM erase-before-call/flag-clear-after-call, and observer changes to group
table/header/clear flag/subscriber count/function/payload/record count.
All streams are readable and finite; token14 never exceeds four entries in
448's actual record. Standalone451 malformed-count padding is not reused here.

Direct frozen-TU scenes compare deterministic maps, slots, group/header/device
state and defined subscriber payloads after real calls. Their opaque record and
scratch bytes are intentionally outside that direct scene's comparison;
instrumented cases compare them under the explicit seeded input above.
Controlled COM/subscriber functions are fixture endpoints. Actual subscriber
implementations,436 parent, malformed/faulting memory, concurrency, live APIs,
full startup and gameplay remain open. Root owns shared acceptance and reuse of
the unchanged453 game build; this worker does not rebuild the game.

Mutations detect cross-module decoder-record offset/remover wiring, default
data, relative payload offset, FE continuation, record+a0, retained opaque
decoder value, map erasure and slot/COM ordering/object writes. The opaque-zero
control is caught by a first-large-token multiFE scene (`00` vs retained `ef`).
Source/fixture/config inputs were UTF-8 LF before proof.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/454-audio-group-composition/native-config.json --attempt 006
```

Receipt:`local/experiments/v2-audio-group-composition-454/006/receipt.json`.
001..003 preserve fixture-domain guard corrections (alternate-table streams,
callback count changes, missing-key duplicate exclusion).004's main cases passed
but the wrong-layout mutant timed out on an invalid pointer.005's corrected
fail-fast exited1 but lost buffered stdout through `ExitProcess`; root approved
the known `fflush(stdout)` transport repair.006 changes only that flush from005.
Exact failed fixture/config/caller inputs are archived under001..005/inputs;
numbered attempts remain immutable. No production mismatch was found.
