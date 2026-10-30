# Run461: original filter object and x87 recurrence

Four original bodies /194B: constructor0059a170 (26B), setter0059a150 (25B),
callback0059a0f0 (93B), kernel0059c170 (50B). No new global storage. The setter
reuses the actual Run221 readonly005b24a8=1.0 owner. Ownership/navigation checks
cover the complete456 source/header closure (425 files); registry636 has no
overlapping accepted entry. Root459 owns shared REA; later shared integration
owns game registration/build. This worker did not launch either.

Frozen native003 PASS:294 cases /94 events per/Od and/O2 variant (588 cases /
188 events total),13 detected mutations. Real raw constructor→setter→callback→
kernel composition is compared with the recovered providers. Constructor callback
addresses are asserted before pointer normalization; the raw object points to
the actual raw child bodies, while the C++ object points to canonical C++ children.
The optional upstream callback is controlled and records its exact five arguments.

The upstream ABI is cdecl5(object,count,OUTPUT,INPUT,sign16mode). Original pushes
mode,input,output,count,object. Nonpositive upstream returns propagate immediately;
positive returns permit the original forward DWORD copy and kernel call, then
return the captured original count. Forward overlap and callback-modified state
are compared. Constructor/setter public interfaces match frozen458 typed names;
their incidental original EAX values are not caller-used returns.

Setter/kernel retain exact x87 instructions in small naked C++ functions. The
kernel holds ST0 across nonpopping FST output stores and stores/pops it only at
the end; no float recurrence approximation is used. Actual COFF confirms kernel
50B byte identity at/Od and/O2. Setter25B matches after its one canonical scalar
relocation. Native controls compare full object/sample memory, ESP/nonvolatile
ABI, all defined kernel/setter GPR values and arithmetic flags, x87 CW/SW/tag and
all eight80-bit register payloads. x87 instruction/data addresses are excluded
because the raw slab and recovered code occupy different addresses.

Cases cover signed zero, subnormals, normal extrema, infinities, qNaN/sNaN,
four rounding modes, precision24/53/64, seeded stack depths0/1/4/6 and the
kernel's count0/wrapped-count do-while behavior. The extended-accumulator mutation
is detected by a recurrence case; byte identity is an additional artifact check,
not the mutation failure oracle. The fixture compares masked exceptions; live
unmasked trap timing, arbitrary/faulting memory, concurrency and full458 parent
composition remain open.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/461-audio-filter-kernel/native-config.json --attempt 3
```

Receipt: `local/experiments/v2-audio-filter-kernel-461/003/receipt.json`.
001 caught a fixture enum colliding with the Windows CALLBACK macro.002 exposed
the upstream output/input order when buffers differed. Logs/generated fixtures
remain in their immutable attempts.003 uses final UTF-8 LF inputs; all source/
config/fixture hashes are frozen. No playable game, live audio or full startup
acceptance is claimed.
