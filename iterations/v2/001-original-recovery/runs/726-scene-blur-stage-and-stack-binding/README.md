# Run726 scene blur stage and reachable stack binding

Packet native/provenance/ownership audit PASS004. Recovers `00451490` (279B),
`005379f0` (34B), `00537a50` (10B), and a production binding for the unchanged
Run721 `004552b0` core (311B). Shared game integration remains pending.

The sole observed original caller `00468fb0` calls451490 at46906f then4552 at469074
without changing callerESP. The last451490 lookup `(0, BLUR)` enters raw44d320;
44d32a writes zero at the next4552 entryESP-0x24..-0x21. Raw44b830 makes no calls,
reads that key and writes a distinct output pointer. Both lookup exits and the
451490 epilog preserve the four bytes. Original4552 constructors read byte1/3.
This proves zero on this reachable path. Standalone4552 stack bytes remain
unspecified; Run721's explicit-input research interface retains that boundary.
The complete original executable direct-CALL scan finds only469074; no raw
absolute4552 pointer occurs. Ghidra incoming references independently agree.

The wrapper uses a small explicit ABI bridge: PUSH0, pass its address to721,
balanceESP, XOR ECX0, RET. It does not read a recovered compiler frame. Attempt003
passed comparisons but exposed a weak ECX mutation: MSVC restoredECX with POP
after the inline XOR because the local zero array occupied one stack slot.
The explicit bridge removes that compiler dependence; all seven controls now
fail materially. Attempts001/002 preserve the missing-header compile failure.

Verification commands:

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/726-scene-blur-stage-and-stack-binding/native-config.json --attempt 004
py -3 iterations/v2/001-original-recovery/runs/726-scene-blur-stage-and-stack-binding/audit.py
```

73 cases at each `/Od` and `/O2`, seven mutations. Original raw451490,5379f0,
537a50,44d320,44b830,4552 and both716 leaves execute in composition. Original
module/body bytes are SHA checked before relocations. Four poison stack images,
lookup hit/miss, allocation branches and free-list refill compare ordered calls,
all allocation bytes, both matrices, roots, used returns and ABI/ECX. The
synthetic four-CALL/RET sequence and poison-stack seeding are harness code.
Mode24B allocation must succeed because the original unconditionally calls its
setter; broad null/fault behavior remains outside this domain. Program allocation
failure still invokes setup with null, as in the original.

`evidence.json` pins the receipt, actual compiled source closure, original REA
dossiers and COFF disassembly. The audit verifies loader-zero48B blur state,
no body overlap including registry body_ranges, and no competing storage owner
(the only external address hits are Run179's generated extern declarations).
Run721's additional8200B state and existing716 state are reused with production
initial assertions before fixture resets. Neither earlier packet was edited.

`production-inputs.json` gives exact sources, entries, storage and true child
frontiers:468240,4685e0,455830,455570,4558b0,59f070. Do not add fixture/chain
providers to the game graph. No registry, shared manifest or root plan edits.
Live config/device, hostile aliases/faults, broad lifetime/concurrency and
startup/display/gameplay acceptance remain open.
