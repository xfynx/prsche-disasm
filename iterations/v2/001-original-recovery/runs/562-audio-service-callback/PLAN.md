# Run562 handoff

Goal: trace callback `004ad9c0` and prove an independent coherent child without
duplicating Run561. `004ad950` is bounded-native-verified; no shared game or
registry integration has been performed. `004ad8b0` and the callback remain
unrecovered. This run is not a completed callback packet.

Confirmed: callback 1114B has 21 calls, 14 distinct direct children plus the
GetTickCount IAT; Run556 supplements the missing indexed entry. Run560 full
closure and registry have no body owner for `004ad950` or `004ad8b0`. The latter
uses canonical root `00656ab4`, and calls `005666f0` and `00567720`; its stack
local at `[esp+4]` is initially unwritten but, on normally returning original
child paths without arbitrary callback effects, `005665b0` writes it on both
success and failure. See `output-trace-evidence.json`. `00567740` belongs to the
parallel Run561 draft; never duplicate it here.

Both indexed and REA-observed calls to `004ad950` immediately overwrite EAX:
`004adbf9` loads the root, and `004adedc` loads `[esp+1c]`. The current void
signature is safe for these observed callers; see `caller-return-evidence.json`.
No claim is made for unidentified indirect callers.

Next: batch original `005665b0`/`005666f0` with `004ad8b0` in a shared native
fixture. Cover both indexed resource encodings, missing entries, diagnostic
callback effects, actual `0056e290` and signed channel branches; control the
remaining stream endpoint with exact argument and reload checks. First establish
resource validity domains and canonical state ownership for every child; retain
faults, arbitrary callback effects and malformed resources as explicit limits.
Preserve the bounded split proof unchanged; game integration remains separate.
