# Run736 scene blur program lifecycle

Native006 PASS for `00468240..00468307` (200B constructor) and
`004685e0..00468628` (73B setup). The production C++ uses the original
thiscall ABI through fastcall bridges, preserves unwritten receiver padding,
and keeps x86 allocation-size arithmetic explicitly modulo 32 bits. Shared
registry/build integration remains pending.

Provenance is Porsche.exe SHA-256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
REA dossiers are pinned in `scope-evidence.json`; raw body SHA-256 values are
`dc732d4efce9e922de566dd4fae040fb4875bd248bd0e6612a4f49b78ab373b9`
and `cef0694dda11c79da6caebc6fa6104028f97a8ec46884bd6b38971adcb3b906a`.
The binary index confirms the complete body ranges and direct child calls.

Verification:

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/736-scene-blur-program-lifecycle/native-config.json --attempt 006
```

Each `/Od` and `/O2` variant passes 76 original-x86 versus C++ cases: 36
constructor cases, 24 setup cases, and 16 composed
`00451490 -> 00468240 -> 004685e0` cases (152 comparisons total). Checks cover
RET14/RET18 stack balance, nonvolatile registers, constructor return EAX,
ordered child calls and arguments, the full 40B receiver, 12B node, allocation
buffer, 24B mode, and blur globals. Ten material mutations are detected.

Attempts 001 and 002 preserve two incorrect fixed relocation offsets. Attempt
003 passed both base variants and seven mutations, then Windows rejected the
next executable name with WinError740; attempt004 used neutral mutant names and
passed. Attempt005 repeats the full proof after replacing signed-overflow-prone
production C++ arithmetic with explicit x86 unsigned wrap. Attempt006 adds a
`c=0x40000000` case that materially exercises that wrap and passes the full set.

The proof permits a valid non-null 40B receiver and array buffer; the 12B node
allocation covers success and null return. Controlled endpoints prove transport,
not the downstream semantics of `0053f230`, `0053f160`, `0053f2a0`, or
`00468440`. Invalid pointers, allocation failure for the array, broad aliasing,
concurrency, lifetime, live renderer/device behavior, startup, and gameplay are
outside scope. Next recover those four children, then integrate this frozen
packet through the coordinator-owned registry/shared build and audit.
