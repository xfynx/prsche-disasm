# Run484: original display constructor and transform helpers

Native004 PASS at `/Od` and `/O2`: **2,912 cases /512,448 endpoint events per
variant**,5,824 comparisons /1,024,896 events total. All18 mutations detected.
Passed production, header, fixture, config and original evidence are frozen.
The306 input pins and305 output hashes were rechecked after proof.

Original Porsche.exe SHA256 is
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
The oracle executes the complete1761B constructor004677e0, through RET16 at
00467ebe, with the actual four original helpers:00539b30/68B,00539b80/69B,
00539f40/15B and00466e80/9B. Total1,922B, five original bodies; one caller is
repaired and four helpers are new. Cached469,482 evidence, Ghidra/raw instructions
and unchanged earlier prefix proof are reused. No new REA session is needed.

The replacement uses original signed FILD32/FSTP32 spills, including height
before width at surface init, captures actual dimensions before the config
callback, and computes Y=-2/height before X=2/width using the original x87
operation/spill order. The raw2/-2 words at005b2580/005b2628 are verified before
oracle relocation; literal values add no original state owner. Surface init's
last word is47800000. The no-argument getter supplies the receiver for the
three-word translation helper. The four diagonal words go to the stack matrix;
the second getter supplies the attach receiver and that matrix is the argument.
Surface roots reload at the original callsites, including local-transform+ b8.

Full argument/state capture also exposes and repairs earlier tag-only omissions
in this same caller: all32 vertex words, byte/DWORD/WORD pixel decoders for the
original format table, texture copy source `DWORD[texture+28]+10`, final driver
receiver `DWORD[DWORD[self+70]+4]`, and readback allocator text `PBUF`.
The new private header records corrected explicit-receiver cdecl adapters;
it does not disguise the old wrong child argument lists behind wrappers.

There are2,688 constructor scenes per variant:2,664 complete returns and24
controlled terminal exits. They cover all12 indexed format entries, seven
signed dimension pairs (zero, negative/high-bit, precision boundaries and normal
sizes), all32 callback modes, both driver choices, mode/reserve branches and
both original terminal failure routes. Callbacks alter texture dimensions,
actual dimensions, the surface root and the getter's matrix root. Every
controlled endpoint records arguments, receiver where used, pre-entry state,
strings and relevant matrix/vertex payloads. Stack pointers are compared by
their proved payload/relative layout, not by inventing identical host addresses.

Another224 direct helper cases exercise eight unaligned receivers and seven
raw-bit patterns, exact matrix contents, counter wrap, dirty-byte updates,
getter EAX and memory guards. cdecl adapter ESP/EBP/EBX/ESI/EDI and constructor
result are checked on returning paths. Incoming x87 PC0/2/3, all rounding modes
and depths0..4 compare control/status/tag plus all occupied80-bit registers.
The undefined contents of empty x87 registers are excluded using TOP/tag
mapping. Helpers preserve x87; masked zero division is included.

Other engine/Win32/THRASH calls are controlled boundaries, transported by small
synthetic ECX/stack/RET shims. The shims and original-PC jump-table relocations
are explicitly recorded. Actual stop/abort never returns: fixture longjmp
captures state at00557370/005a246e; no returned ABI is claimed for those paths.
Original callback identity literals004672c0/004672e0 are retained as stored
values only; the packet does not execute them. No fixture provider enters the
production source graph.

The source replacement is explicit:

- Replace old `source/recovered/Porsche.exe/render_display.cpp` with
  `render_display_484.cpp`; do not compile both owners.
- Add `render_transform_484.cpp` and this run's include directory.
- Keep old source/header/probe/proofs immutable. `replacement-scope.json` proves
  the unchanged prefix, read32 helper and all nine old global definitions/36B
  move unchanged into the replacement TU. No original storage is added.
- `coff.json` records actual strong provider/undefined symbol sets. Helper
  cores define the corrected names; their only non-algorithm undefined symbols
  at `/O2` are compiler security-cookie support. Three obsolete child names
  disappear with the old caller; no alias to an incorrect signature is added.

Ownership scans reuse the full480640-pin closure and inspect the two481 source
files separately. There is no scalar address owner collision. Existing
application-state/global/shared-runtime and render_objects TUs are linked into
the native proof. Coordinator owns registry/CMake/shared acceptance and the
reviewed replacement policy; this packet changes no global documentation.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/484-render-constructor-repair/native-config.json --attempt 4
```

Receipt: `local/experiments/v2-render-constructor-repair-484/004/receipt.json`.
Failed001 preserves the newly detected PBUF argument mismatch;002 preserves an
invalid returning-terminal fixture path.003 passes ordinary comparisons but its
height-capture mutation survives because callback changes coincided with early
terminal scenes.004 separates terminal conditions and sweeps every callback
mode; no mutation is removed. Old accepted inputs remain unchanged.

Actual graphics/COM/THRASH execution, other child compositions, original callback
execution, allocator failure/null or unmapped objects, unmasked FP faults,
concurrency, startup/display/gameplay remain open. The48B descriptor005de680
overlap with canonical005de6ac remains deferred;534540 is not implemented here.
