# Run525: driver destruction

Frozen native002 PASS:5 originals274B/4B calibration pointer;19,968 comparisons,
109,440 events,15 detected mutations at/Od+/O2. Original515 context/vtables and521
mode are reused. All baseline001 inputs remain unchanged;002 adds controls only.

Bodies:538ab0/55B,556ab0/84B,557120/84B,538ce0/34B,536950/17B. Tests cover flags/
used returns, exact cleanup order and live helper reload, null/aliased fields,
unaligned objects, callback edits, virtual flags1/RET4, constructor composition,
nonvolatile registers/stack and x87 state through depth0..8. The canonical69de44
pointer remains unchanged unless a callback changes it; no invented clearing.

The original index/raw scope and full524 compiler closure establish ownership.
REA002 audits5 dossiers;001 sandbox spawn EPERM is retained. REA's575930 prototype
misses a real argument; caller/callee raw assembly confirms cdecl1. The calibration
virtual method is independently checked against raw table5bb708 and536840 flags/
RET4 body, without counting that controlled child as recovered.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/525-render-driver-destruction/native-config-mutations.json --attempt 002
py -3 scripts/research/audit-v2-rea-session.py --config iterations/v2/001-original-recovery/runs/525-render-driver-destruction/queries.json --attempt 002
```

Two real shutdown/library children remain unresolved. Native deallocator/window/
library/virtual endpoints are controlled; actual heap/device cleanup, arbitrary
external stack aliases, faults/lifetimes/concurrency and gameplay remain open.
Coordinator owns later shared intake; no fixture provider belongs in game sources.
