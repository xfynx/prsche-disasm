# Run728: audio decode/copy dispatch

Original `0058e310..0058e49e`,399B, cdecl7/RET0, always returns0.
Main index Porsche.exe row5040 and fresh REA dossier
`local/experiments/v2-audio-scene-724-rea/001/function-0058e310.json`
match the complete raw body. Its actual reachable parent is Run7220058e500.
`scope-evidence.json` pins raw bytes, assembly, SHA and canonical ownership;
registry1175 entry/body-range checks found no overlap.

The function allocates count*4+20000 zero-committed bytes with0x3000/4,
selects actual canonical493PCM or504coded constructors and calls the installed
cdecl5 process pointer. Formats0/8 use PCM16;2/9 PCM8;3/10 nibble with8-byte
output prefix;4 ADPCM. Other formats keep zero allocation data. Only bits8
writes signed16 output, using exact original x87 comparison status, clipping
above32767/below-32768 and truncating via actual522FTOL. Unordered input clips
to0x8000. Positive end selects inclusive[start,end]; the original passes that
shifted pointer to VirtualFree after undoing only the nibble prefix.

New readonly data is4B005c1694(-32768). Upper limit005c1698 reuses actual553;
flags006b49a3 reuse application_audio_device_state+0xe3. Descriptor fields1/2/5
and unwritten object bytes remain opaque; production does not clear them.
Canonical constructors consume only fields initialized by the original caller.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/728-audio-resource-copy/native-config.json --attempt 003
```

Native proof pending. Attempt001 compiled both modes but link exposed dead
522/553 dependencies;002 stopped before compile on missing include search.
003 reuses complete canonical522 owner closure and adds10 material controls.
The fixture uses actual493/492 PCM constructors/process/decode, actual504coded
constructors, actual522FTOL and actual data owner TUs. Coded-process callbacks
are explicit controlled transport endpoints, never game providers. VirtualAlloc
and VirtualFree use controlled stdcall endpoints with recorded arguments.

Bounds: valid disjoint source/output and sufficient committed allocation;
positive small decode counts; seeded canonical PCM LUT/function pointer state;
controlled coded process effects and allocation success. Real coded-child
composition, invalid pointers, allocation failure/faults, concurrency, live
platform/device/audio and full startup remain open. Shared graph/registry
integration belongs to the coordinator; no such acceptance is claimed here.
