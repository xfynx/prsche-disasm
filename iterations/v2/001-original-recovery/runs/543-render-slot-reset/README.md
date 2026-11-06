# Run543: texture-slot invalidation, reset and arena release

Frozen native002 PASS:3 originals245B and6 sparse loader-zero DWORDs24B.
Both/Od,/O2 total29,376 comparisons/119,328 events;20 mutations detected.
The actual555330/555390/555400 chain compares against original x86 with full
slot/node/global snapshots, callback arguments/order, stack/register ABI and x87.

scope-evidence.json owns the original ranges/bytes, caller/global references,
PE zero-tail/import evidence and542 effective740-pin/302-root/546-header closure.
No existing body/data owner overlaps. Production reuses537's1536B slots,540's
total006a3a40 and canonical loader/fill/heap/VirtualFree providers.

555330 preserves the dirty early exit, callback-late signed slot count, captured
normal count, slot flags and linked-node writes.555390 increments the late epoch,
reloads signed count after each48B fill, executes actual555400, then clears only
the original count/total/dirty fields.555400 tests initial arena, reloads it after
heap destruction, zeroes heap id before VirtualFree and zeroes arena even when
the API returns0. A callback's null arena still reaches the original API call.

Cases cover normal counts0..32, negative signed skips, finite external/shared
chains and specified slot-as-node aliases; dirty0 retains pending state. Controlled
callbacks edit count/epoch/arena/heap id and pending fields, vary API0/1, change x87
control and exercise bounded nested release. Existing heap/fill/OS algorithms and
live effects are not established by these controlled endpoints.

001 stopped before compilation on an omitted536 header include directory; its
inputs/generated fixture are preserved.002 changes include paths only and passes.
The shared read-only audit reverified all passed input/output/log/dependency pins.
ready.json/coff.json supply the integration handoff. Existing display cleanup name
render_display_thr_cleanup_00555390 requires the coordinator's typed final-link
alias to render_texture_reset_00555390; no duplicate implementation is added.

554bd0 insertion/554960 allocation remain deferred. Corrupt indices/cycles,
arbitrary external aliases/faults, live heap/device/concurrency/full producer/
startup/gameplay remain open. Antivirus-blocked537005 remains separate and
unaccepted; no retry, rename, exclusion or bypass was attempted.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/543-render-slot-reset/native-config.json --attempt 002
py -3 iterations/v2/001-original-recovery/runs/543-render-slot-reset/finalize.py
```

002 is an immutable completed attempt; the first command records its origin.
The coordinator owns544 shared integration and acceptance.
