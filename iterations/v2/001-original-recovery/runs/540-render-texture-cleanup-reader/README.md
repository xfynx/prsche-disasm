# Run540: texture cleanup and scalar reader

Frozen native002 PASS:2 originals194B/4B writable count/78B readonly exactstrings.
440,376 comparisons/903,680 callback events/17 mutations;264 input and281 output
pins verified by the shared receipt auditor. No shared build acceptance yet.
Existing slot owner537 and heap free531f90 remain canonical; no new child function.

554cc0/170B unlinks head/interior textures from48B normal slot records, decrements
slot/total counts with unsigned wrap, then frees captured+14, freshly-read+1c and
self in order. Not-found reports diagnostics without decrement/free; callback
repairs do not cause retry. Full source/header closure from539 has no competing
owners. New006a3a40 is exactly4B loaderzero tail; strings are30B file/48B message.

56e290/24B always reads4B, BSWAPs, then shifts by masked CL derived from count.
Count0 is not a no-read case. Native cases sweep low-byte counts and values with
unaligned reads; guarded/null/high-count probes prove the specified read-AV
behavior. Actual537 format/destructor algorithms compose with both new bodies.

Free endpoints record intermediate arena/table/count/FPU state and may edit late
fields. Finite lists/slots0..31, null/nonnull payloads, head/interior/notfound,
wrapped counters, diagnostic state and readonly/loaderzero storage are bounded.
Live heap/device/diagnostic565340, arbitrary corrupt lists/indices/unmapped faults,
concurrency/full producer/startup/gameplay remain open.537005 is not retried.

001 preserved a fixture getter-name compile error; production is unchanged in002.
Passed source/header/config/original inputs are frozen. Coordinator owns542 intake.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/540-render-texture-cleanup-reader/native-config.json --attempt 002
```
