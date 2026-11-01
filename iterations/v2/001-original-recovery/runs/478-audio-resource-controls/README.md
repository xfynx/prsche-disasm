# Run478: audio resource cleanup and progress controls

Three complete Porsche.exe bodies /293B: `004ad510`172B, `004ad670`78B,
`004ad6c0`43B. Original SHA is
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
Cached Run469001 REA, the matching Ghidra index and exact PE bytes establish the
body extents, instructions and four calls to accepted stop `00565d60`.
No new REA session or original child provider is needed.

Native001 PASS at `/Od` and `/O2`: **145,852 cases /122,028 child events per
variant**,291,704 comparisons /244,056 events total; all18 mutations detected.
The shared runner receipt is
`local/experiments/v2-audio-resource-controls-478/001/receipt.json`.
All206 input pins and245 output hashes were rechecked after proof. Production,
fixture, config and evidence are frozen. No failed native attempt exists.

Cleanup preserves the captured object, copies byte+2d2 to+2d3, handles+3c before
+38 using signed>=0, and resets each leading handle after its call. Each of32
records checks first+45c+12i and then second+5dc+12i using `!=-1` (other negative
values still call stop), reloads the second handle after the first callback,
then zeroes+44+4i and resets both handles after callbacks. The next root is read
after the previous object's callbacks. Every endpoint records the full object
and root state before applying adversarial writes. Distinct, identical and
overlapping roots, live root replacement/nulling and all relevant signed
boundaries are covered.

The progress getters preserve all32 output bits. Begin gates root,+88,+1c;
mode+14==2 bypasses+8c and signed+ a0 > +a4 checks. End gates root,+88,+8c and
returns+a4. Existing splash callers interpret both returns as signed; exact COFF
`/alternatename` directives bind their old `YAHXZ` names to canonical `YAIXZ`
providers. Native links call through those aliases. `coff.json` records both
actual object symbol sets/directives: three function definitions, two data
definitions, two aliases and only the accepted stop as an original dependency.

`original-evidence.json` scans Run472's complete manifest+delta626 pins and445
source/header files with zero drift. It finds the existing Run400 declaration
`extern void* audio_channel_banks_00656aa8[2]`, with no prior definition. This
packet owns that exact8B canonical array once; it defines a separate4B query
root00656ab4. Both spans are inside the original writable `.data` virtual tail
and have loader-zero initial state. The gap00656ab0 is unowned. Native proof
asserts production zeros before any fixture reset and proves the two bank cells
physically adjacent. Existing pointer-array consumers retain their exact name
and type. The array name is absent from the measured Run472 unresolved frontier;
the three requested function names are the expected closure.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/478-audio-resource-controls/native-config.json --attempt 1
```

The original cleanup return is unused; cdecl0 ESP/EBP/EBX/ESI/EDI and getter EAX
are checked. x87 control/status/tag and all80-bit registers remain identical
across varied precision/rounding/depth. Volatile GPRs and flags are not consumed
by these callers. Stop is a recording/mutation endpoint only in this fixture;
unchanged accepted Run435 native002 proves its real algorithm. Actual stop
composition, real resource producers, unallocated/unmapped pointers, faults,
concurrency, full startup/display and gameplay remain unproved. Coordinator
owns registry/CMake/shared integration; this packet adds no production stub.
