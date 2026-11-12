# Run570: startup service bindings

Shared [Run571](../571-startup-service-integration/README.md) intake passes,
retaining one partial original despite its two closed ABI names.

Frozen native001 and shared read-only audit pass **360 scenes, 720 adapter
comparisons and four mutations**. Original `00536080` is 27 bytes; both actual
unresolved names are supplied by the same partial implementation. The body
zeros receiver+8/+12, calls the accepted Run543 `00555330` provider, then clears
one newly owned loader-zero byte at `0069dd1e`. Original module SHA256 is
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`; body SHA256
is `42b0ba96bdb248dc0e467b70c0ac9447cab2f79286826d5eecdade18bda21837`.

Index/raw caller witnesses pin `004b67b8` and `004dd653`: both load ECX from the
DWORD at `[0069ed0c]+4`, call `00536080`, and do not pass a stack argument. The
existing startup fastcall name transports that receiver in ECX; the existing
game-setup cdecl name accepts the same receiver explicitly and forwards it.
The two real names and the byte have unique candidate COFF owners at `/Od` and
`/O2`; `00555330` remains the sole external dependency. Existing Run469 REA
dossier `local/experiments/v2-frontier-469-rea/001/function-00536080.json`
matches its exit-zero receipt hash
`73072bb68cfc03325e4f80149828324e02047c926d974938e78630a1119cdd1e`
and reports the same body and child. Raw body and caller windows are in
`scope-evidence.json`.

The accepted Run543 child executes on both sides. Its controlled render callback
records receiver and state, and can change the receiver fields and the new byte
after the two original writes, exposing the final late byte clear. Tests compare
the full slot/node/global scene and ordered callbacks, four receiver alignments,
both ABI transports, stack/nonvolatile registers and one seeded x87 state.
Four controls detect missing/short field writes, early flag clear and a missing
child call. The callback and slot views are fixture transport, not live driver
proof; arbitrary receiver/global aliases, faults, incidental EAX, full FPU tag/
MXCSR and concurrency remain open. Entry status remains PARTIAL.

Run567's 778-pin/316-root/575-file closure has no original-body owner collision.
The byte is in the PE `.data` virtual zero tail; adjacent `0069dd18` pointer and
`0069dd1d` byte keep their existing owners. The fixture checks the new production
byte is zero before scene resets. `ready.json` and `coff.json` own audit details.

`00534540` is deliberately deferred: it passes descriptor `005de680` to
`00534480`, which can read/copy all 48 bytes through `005de6af`. The final DWORD
`005de6ac` already has a canonical owner; Run521's canonical split view is for
the different `005de650` descriptor. No 48-byte clone or guessed alias was made.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/570-startup-service-bindings/native-config.json --attempt 001
py -3 iterations/v2/001-original-recovery/runs/570-startup-service-bindings/finalize.py
```

Commands identify frozen proof origin, not a request to overwrite attempt001.
No shared CMake/registry/root docs or original game files were changed here.
