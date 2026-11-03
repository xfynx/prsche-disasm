# Run523: buffer construction and ordered renderer states

Frozen native001 PASS at/Od and/O2:152,064 cases/964,416 endpoint events each;
304,128 comparisons/1,928,832 events total.15 mutations detected;272 input and
341 output pins rechecked. Four originals317B,0 new state:
537700/86B,537760/197B,540480/17B,5404e0/17B. No source replacement required.

537700 writes only the measured56B buffer fields, preserving opaque surrounding
bytes, calls actual537760 then the explicit535b00 frontier, and returns its
captured receiver.537760 reloads every field after callbacks and uses canonical
slot27 versus alias2 independently. Final FLD32/FST32 spill/MOV/FSTP32 self+34
is a bounded primitive, preserving NaN quieting, exception/round/stack effects
and stores before final state43. It is not replaced by a semantic no-op.
Both17B cdecl2 wrappers retain the full opaque SDK return and correct cleanup.

Raw5377dc..e6 loads self+30 intoEAX, movesEAX toECX and compares those identical
registers. JE5377fe is unconditional for all values, with no intervening child.
The original whole197B runs in proof, with dead5404a0 and5dedf4 relocated to a
fail-closed fixture endpoint/opaque cell. No production provider/state is added
for this unreachable path. All11 live ordered state calls remain explicit.

Shared fixture/config reuse frozen518's actual alternate/main starts,515/503
constructors,511 getter,359 settings and SDK RegFlushKey guard/detour. Fresh raw
buffer bodies compose; direct tests cover unaligned objects, callback field and
slot mutations, AL gates, used returns, all PC0/2/3 and4RC, depths0/3/6/7/8,
initial x87 status0/3f, signed zero, normal/subnormal/extreme/Inf/qNaN/sNaN bits.
Full x87 CW/status/tags/active80-bit values are compared at endpoints/finally;
empty register residue and instruction/data pointers are excluded. All13 actual
503 cache cells are observed. RegFlushKey is redirected, never called live.

535b00 remains a real typed cdecl0 strong child:14 ordered cdecl2 calls through
7 callbacks5de72c and two7-record blocks5de6bc/5de6f4 (112B). Its algorithm,
records and table are not guessed or added. State-ownership/COFF files establish
no new writable object data in either compiled variant.

Resource535b50/535ba0/table5bb6c8/byte69dd1c remain deferred until actual factory
consumers establish inputs/ABI; RET16/RET12 alone is insufficient. Table5bb6c8
has3 slots/12B; adjacent5bb6d4 is a separate table, not a fourth slot. Trace-only
tables/movie-resource-consumer evidence is not an accepted resource provider.
Calibration536870 remains deferred and must reuse root525's69de44 owner.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/523-render-resource-buffer/native-config.json --attempt 001
py -3 local/finish-render-buffer-523.py 523 1
py -3 local/handoff-render-buffer-523.py
```

Passed inputs immutable. No edits to521/524/525, registry/build/common docs or
other agents' work. Resource/calibration/flush algorithms, unmasked exceptions,
unmapped/fault/concurrency/live DLL/device/registry/full startup/gameplay domains
remain explicit. This is bounded native recovery, not a linked game EXE.
