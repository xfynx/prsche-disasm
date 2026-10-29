# Run446: original OS/CPU feature detection

Three original bodies/226B:00597070,0059a4d0 and0059a4ed. Native002 PASS:
28,570 cases across `/Od` and `/O2`,90,720 observed events,12 detected mutations.
922 cases use the real host CPU/helpers, including864 composed main calls;
27,648 controlled cases cover the complete bounded branch matrix.

The161B main body becomes C++ branch logic with a narrow original-stack adapter.
Its164B frame retains148B size-only OS backing and16B CPU output. Machine loads
transport opaque failed/partial GetVersionExA fields without indeterminate C++
scalar reads. The OS status stays ignored. PlatformID==1 AND minorVersion==0
suppresses bit1; unsigned basic maximum gates leaf1 then80000001, without an
extended-maximum query. There is no synthesized subleaf0 or default OS mask.

The29B ID-toggle and36B CPUID helpers retain their exact x86 ISA and extra ABI:
caller flags/ECX restored by the former; every GPR including EAX restored and
incoming ECX inherited by the latter. Actual helper COFF bytes equal the original
at both optimizations. Direct cases check status/ID flags, six real CPU leaves,
four inherited ECX values, stack/nonvolatile ABI and16B output canaries before
fixture-only detours. Controlled cases then record leaf order, output state and
ECX/output-pointer identity. Size-only OS input is asserted before fixture writes.

Full616 canonical Porsche entry/body ranges were checked against the candidates:
no overlaps. No original global storage is added. Internal C++ and Windows
adapters count zero additional original bodies. The actual platform object links
to SDK kernel32 in a nonexecuted NOENTRY DLL importing GetVersionExA, matching
the original IAT005b2150. Evidence, COFF, ownership and import receipts are local
JSON artifacts; Run447 owns REA, game integration and shared acceptance.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/446-cpu-features/native-config.json --attempt 002
```

Frozen receipt: `local/experiments/v2-cpu-features-446/002/receipt.json`.
Attempt001 retains a fixture inline-assembly syntax failure; production unchanged.
Live Windows API execution, other physical CPU models/pre-CPUID hardware,
442parent+realCPU composition, invalid memory, concurrency and full game startup
remain unverified. Opaque prior-stack bytes remain inputs, not deterministic
portable defaults. No game build or commit was performed in this run.
