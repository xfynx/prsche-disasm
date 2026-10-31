# Run475: original sample processor

Recovers complete Porsche.exe `00598760..00598937` (472 bytes), cdecl2
`void(count, buffers)`. Original SHA256:
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
Run473's two callers push buffers then count and ignore the return.

The original processes active voice records at stride0x50, clears each ramp flag
after the ramp child, handles signed negative/zero/positive process returns,
accumulates nonzero ordered FLOAT32 lanes, invokes optional voice/block hooks,
then runs each channel's optional filter and output processor before clearing
the channel accumulator through the real accepted434 `0058fef0`.
FLD/FST32/FCOMP/FNSTSW preserves NaN skipping, quieted FLOAT32 arguments and x87
status. Callback-visible captures and global/count/table reloads retain raw order.

Ownership check uses Run472's complete626-pin compiler closure through
`ManifestReader`, including run-owned sources and headers. Canonical458 owns
the physical mixer block: aligned[0]=006b1754, aligned[1]=006b1758,
channel_aligned=006b176c, channel_word=006b1780, filter=006b1790, table=006b17d0.
Canonical382 owns readonly zero005b23f8. The three new callback DWORDs
006b16b4/006b16b8/006b17d4 are unowned and loader-zero: `.data` file backing ends
005e7000, its virtual extent ends006c1538. Their production zero state and the
canonical scalar's raw bytes are asserted before fixture resets.

Native005 PASS:2,362 cases and35,055 callback events per `/Od` and `/O2`, with10
detected mutations. The pinned source/header/config/evidence/fixture inputs are
frozen. Receipt: `local/experiments/v2-audio-sample-processor-475/005/receipt.json`.
Shared integration belongs to the coordinator.

The fixture covers0..4 voices/lanes, active-byte dispatch, ramp consumed counts
(including zero/equal/underflow), signed process results, both filter paths,
ignored final-chain results, voice-hook clearing, mutable table/count/source/
destination cells and record identity captures. All256 callback mutation flag
combinations run with one/four lanes and three filter masks. FLOAT32 tests include
signed zero, subnormals, infinities and quiet/signaling NaNs across x87 precision
24/53/64, all rounding modes and stack depths0/1/6. Intermediate callback snapshots
and final memory/state/x87 values are compared, with ESP/EBP/EBX/ESI/EDI checks.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/475-audio-sample-processor/native-config.json --attempt 5
```

Failed attempts remain under `local/experiments/v2-audio-sample-processor-475`:
001 missing include search path;002 dead-owner binding link failures;
003 incorrect absolute relocation count;004 caught a symbolic458 field-offset
error in the first active voice accumulation. Each retains the then-current
input copies. No accepted proof was altered.

The native oracle relocates only pinned original body operands/calls; synthetic
cdecl carriers and controlled callback/child endpoints are fixture code.
Ramp005980c0 and stop00598670 retain proved typed contracts and remain real
unrecovered production dependencies. Original code has no new bounds guard.
Fixtures use mapped initialized records, at most4 voices/lanes, controlled chain
endpoints, masked floating faults and deterministic callbacks. Actual PCM kernels,
ramps/stop graph, initially absent block-hook branch, full parent composition, live audio/platforms, arbitrary faults,
concurrency and game acceptance remain open.
