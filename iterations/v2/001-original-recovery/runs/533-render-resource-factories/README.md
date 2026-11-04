# Run533: resource constructor and factories

Frozen native003 PASS:737,280 comparisons/2,949,120 callback events at/Od,/O2,
22 detected mutations,257 input and341 output pins rechecked. COFF independently
pins all three readonly slots to canonical symbols and the separate1B zero flag.
Four complete originals253B:535b50/74B,535ba0/32B,536180/92B,5361e0/55B.
New storage is1B writable loader-zero flag69dd1c and12B readonly original table
5bb6c8. Actual529294-root closure plus pending528/530 production files/headers
totals535 physical files; only518 already declares/calls535b50. No competing
body/state owner is found. Adjacent69dd1d belongs to existing render_mode.cpp;
5bb6d4 is a separate node table and is excluded.

535b50 is ECX receiver/one consumed stack word/RET4, returning captured self.
It stores table,0 at+10,driver at+4,0 at+8/+c, then calls canonical setstate41,0;
only a nonzero result reaches42,0. Both nonzero produce flag0, otherwise1.
Raw second-call failure stores0 then1; preserve original store/control order.
535ba0 is ECX receiver/one consumed flags word/RET4, returning captured self.
It resets the same table and releases self through canonical59f050 when the
low flags byte has bit0. No additional node cleanup or invented destructor call.

The three original table words map to actual typed native transports:

- +0:535ba0, ECX self/stack flags, RET4.
- +4:5361e0, ECX self/stack descriptor0,descriptor1,flags,name, RET16.
  Complete body reads every input independently of the return cleanup, allocates
  0x54 with canonical59ef90, and on success calls535d80 with receiver allocation
  and those two descriptors,captured parent self,flags,name. Return is the child's
  actual EAX, including an opaque result different from allocation; failure0.
- +8:536180, ECX self/stack descriptor,flags,name, RET12. Complete body captures
  descriptor/self, branches on descriptor, allocates0x54, and on success calls
  535bc0(descriptor,parent,flags,name) or535ed0(parent,flags,name). Flags/name are
  read after allocation, and the actual child return is forwarded; failure0.

Three actual children remain strong typed frontiers, with raw input consumption
and complete RET evidence saved:535bc0 ECX self+4words/RET16 (365B),535ed0 ECX
self+3words/RET12 (224B),535d80 ECX self+5words/RET20 (336B). Their bodies are
not proposed for recovery here. In particular their node+1c flags do not gain a
legal stage domain. Run531/535a90 remains unresolved without a guessed guard.

Native proof compares the four bodies directly and through all three vtable
slots, actual540440 binding with flags1 old-resource destruction, and actual518
start→new constructor→523 buffer ctor/apply→527 flush/option compositions.
The source graph includes those actual algorithms and canonical359 export-call
binding; accepted496/515/loader/mode globals are explicit fixture transport views.
Cases cover allocation failure and opaque child returns, object fields/untouched
bytes, setstate short circuit/full DWORD returns, stack cleanup/nonvolatiles,
callback aliases, late resource/API edits, low-byte delete flags, independent
69dd1c/69dd1d changes, initial zero, raw table bytes and readonly/writable pages.
All descriptor/child-result/allocation-failure combinations are independent.
Controlled callbacks retain x87 PC/RC/status/active80-bit state and may edit control.
Raw/COFF checks do not depend on linked ICF address inequality. Mutations gate
branches, argument/slot order, full flag bits and forwarded child return values.

Original caller argument slots stay fixed during callbacks; ordinary object/global
aliases and late field/export reloads are exercised. The three constructors and
535a90 are controlled actual frontiers, not recovered implementations. Child input
producer/stage validity, arbitrary stack aliases, unmasked exceptions, faults,
lifetime/concurrency/live APIs/full startup/gameplay remain open.

```powershell
py -3 local/trace-render-resource-533.py
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/533-render-resource-factories/native-config.json --attempt 003
py -3 local/finish-resource-533.py 533 3
py -3 local/audit-resource-533.py 3
```

Only533/local owned. Root owns532/shared integration; frozen523/527/529 and
pending528/530 are unchanged.

001 retained a nonunique mutation anchor after direct comparisons passed;002
exposed correlated null/return cases through an undetected empty-return mutation.
003 uses the independent scene matrix and detects all22 controls. Passed proof
inputs are frozen; no shared build or registry acceptance is claimed here.
