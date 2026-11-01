# Run479: mixer ramp and stop chain

Recovers five closed original Porsche.exe bodies,601 bytes:
005980a0(20),005980c0(361),00598670(23),00598690(108),00598700(89).
Original SHA256 is
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
The two real dependencies introduced by475 close without another helper frontier.

The ramp clamps a signed request above32, invokes the captured voice processor,
copies targets on nonpositive returns, and otherwise performs original x87
FLOAT32 divisor/delta stores and per-sample FADD/FST/FSTP updates. Lane/count/
source/hook reloads retain original call order; the last current lane advances
voice gain and emits the optional callback. Target setting captures lane count,
stores raw gain, multiplies each input factor and uses x87 C0 to zero products
below or unordered against the exact original floor. Stop captures its record,
sets four zero targets, ramps32 of requested256 samples, follows next pointers
captured before each actual438 pool release, clears the captured record, then
invokes the stopped callback unconditionally.

The full472626-pin compiler closure plus pending473/475 source/header check
establishes ownership. New storage is exactly callback006b16a8(4 loader-zero
bytes), readonly005b246c(4 bytes,raw0000c03f) and005b2738(4 bytes,raw0ad7a33b).
`.data` file backing ends005e7000; its virtual extent ends006c1538.
Config00598230 copies parameter[2] to006b16a8; no callback validity follows from
that producer. Canonical434/438/458/475 state and real helpers are reused.
Raw scalar equality and initial callback zero are checked before fixture reset.

Native002 PASS:7,218 cases/99,366 events total,10 detected mutations. The shared runner compiles `/Od` and `/O2` and
compares direct helpers and raw475+raw479 against actual475+479 composition with
the real438 pool release. Fixtures cover zero/negative/clamped counts, signed
processor returns, dynamic lane/table/source/current/target changes, optional
voice/block hooks, aliasing, floor neighbors, signed zeros, subnormals,
infinities and quiet/signaling NaNs across x87 precision24/53/64, all rounding
modes and stack depths0/1/6. Callback states, final pool/record/memory state,
x87 registers/status and ESP/EBP/EBX/ESI/EDI are compared.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/479-audio-mixer-ramp-stop/native-config.json --attempt 2
```

Attempt001 actual algorithms passed3,033 cases/49,683 events per compiler mode;
the attempted cap mutation was an identity change and correctly failed the
negative-control requirement. Its input copies remain in001. Attempt002 fixes
the mutation and adds a specific floor/alias concern; production code is unchanged.

Fixture endpoints control PCM processing/accumulation and external callbacks.
The stop chain requires a mapped non-null acyclic linked list; original code is a
do-loop without a null guard. Fixtures use initialized0..4 lanes/records and
masked floating faults. Real PCM kernels/subscribers, full init/parent graph,
arbitrary faults, concurrency, live audio/platforms and game acceptance stay open.
