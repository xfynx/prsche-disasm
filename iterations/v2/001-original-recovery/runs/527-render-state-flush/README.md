# Run527: ordered state flush and option remap

Frozen native003 PASS at/Od and/O2:55,296 cases/737,280 events each;
110,592 comparisons/1,474,560 events total.13 mutations detected,214 input and
221 output pins rechecked. Two originals95B:535b00/51B and535a60/44B.
140B writable state:112B records5de6bc..72b and28B callbacks5de72c..747.
No readonly state, duplicate option byte or resource table is added.

535b00 executes seven iterations, calling each live callback twice with one
pair from each56B record block. Value/key reads and function-pointer loads retain
their original order; the second pair and callback are reloaded after the first
child. No record/table snapshot or cached two-call pointer enters production.
Each callback is cdecl2; original caller cleans16B per iteration. Actual523
consumer ignores535b00 EAX.535a60 reads existing canonical69dd1d and sends3 for
nonzero option/nonzero value, otherwise the original value, retaining full EAX.

Raw and C++535b00/535a60 plus actual523 buffer ctor/apply/wrappers compose.
The actual render_mode.cpp owner/setter supplies69dd1d; its uncalled services
are fixture-only fail-closed endpoints/views. Cases cover raw initial records,
distinct mutable data, callback replacement between paired calls and iterations,
late second/next-pair edits, option/API edits, U32/byte edges, unaligned buffers,
used535a60 result and x87 state through controlled callbacks. Separate negative
controls detect caching the callback and reading the second pair too early.

Initial PE bytes, section writability and full526 ownership closure (292 roots,
526 unique source/header files including524/523/525) are pinned. Four slots reuse
actual523540480, one uses new535a60, two point at the real535a90 frontier.
table-relocations.json independently verifies all7 COFF DIR32 target symbols per
variant, writable sections, raw112B record initializers, nonoverlap and no dynamic
initializers. Runtime VirtualQuery separately checks mutable table/record pages.
These symbol checks do not rely on runtime address inequality under ICF.

535a90 stays strongly unresolved: its104B body reads69dd1c and
5de6e8/5de6f0 +56*(signed key>>16), with no proved input bound. Existing112B
ownership covers stage0/1 physical words11/13 and25/27, not arbitrary signed
stages. Do not invent an index guard, expand ownership or duplicate69dd1c.
Resource535b50/table5bb6c8 remain deferred pending actual consumer ABI evidence.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/527-render-state-flush/native-config.json --attempt 003
py -3 local/finish-flush-527.py 527 3
py -3 local/audit-flush-527.py
```

001 preserved a missing namespace brace compile error;002 preserved uncalled
actual-mode-owner link dependencies;003 supplies only fixture fail-closed views
for those dependencies. Production/frozen inputs are immutable after003.
No shared build/registry/docs/other-run edits. Producer bounds,535a90 semantics,
fault/unmapped/unmasked/concurrency/live device/full startup/gameplay remain
unproved. Bounded native recovery does not establish a linked game EXE.
