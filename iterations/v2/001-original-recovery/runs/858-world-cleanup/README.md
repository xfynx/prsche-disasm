# Run858 BWorld cleanup

This packet recovers `00471c40..00471c80` (`application_sim_boundary_00471c40`,
`BWorld_DeInit`) and uses the existing Run831 owner for its writable root at
`00628960`; it does not define that storage again. The original Porsche.exe SHA-256 is
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`; the
65-byte body hash is
`54bb7f14bd46218a9022036cf631a844c4294749ab25f628842fbf10781e8702`.

The exact sequence is: log `"BWorld_DeInit..."`; load the root; when non-null,
call `00487590` with the root in ECX and then `0059f050(root)`; clear
`00628960`; log `"done.\n"`. The root is four loader-zero bytes in the writable
`.data` virtual tail, with no file-backed initial bytes. Run296 established the
same storage location, parent allocation path, and cleanup call edges.

## Native proof

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/858-world-cleanup/native-config.json --attempt 009
```

Receipt: `local/experiments/v2-world-cleanup-858/013/receipt.json`.
Both `/Od` and `/O2` pass four root values (`0`, `1`, `0x81234567`, and
`UINT32_MAX`) against the relocated original body. The fixture captures both
destructive callbacks, their root argument, ordered log strings, and final root
state. Wrong root clearing and wrong destructor argument both fail closed with
exit 10.

## Deferred child

The parent now calls the canonical compiled providers
`formatter_stdio_printf_005a177b(const char*, ...)` (true varargs, return value
ignored) and `application_release_0059f050(void*)` (cdecl, uint32 return ignored),
matching Run855's compiled source roots and headers. `00487590..004876db` is
confirmed as a 332-byte `thiscall`-style destructor:
the caller loads ECX from `00628960`; its body immediately reads `[ECX+8]`,
`[ECX+0xc]`, `[ECX+0x10]`, `[ECX+0x2c]`, `[ECX+0x30]`, `[ECX+0x34]`, and
`[ECX+0x14]`, then reaches 15 child calls including `004878e0`, `0044a690`,
`0059f8a0`, `0047ba50`, and `004890b0`. Those providers and the pointee layout
are not yet canonical, so no production destructor substitute is added.
`00471b70` remains deferred because its unbounded copy into `00628940` can
overwrite the root at lengths >=32; Run296's producer/consumer bound is still
unresolved.
